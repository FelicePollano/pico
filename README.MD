# PICO
Pico is a toy chess engine I decided to write to learn C++ again. I was pretty good (at least IMO) at that language in the 90, but now I want to approach it in a new manner, especially by the added value of having had a wide experience in other frameworks and tools.
As well as having experience in th elanguage, I had experience in chess engines as well, but using C#. At the very end I did not obtain a real engine, but just some tool able to comppute valid move in a certain position.
I think that could be useful to someone, and to this project as well, so I share a [link to it](https://github.com/FelicePollano/Felpo-II).

## Applying lessons from previous mistakes
Study all the theory before is absolutely an advantage. In previous engine I started without knowing what [FEN](https://www.chessprogramming.org/Forsyth-Edwards_Notation) was, and the difference between [Long Algebraic Notation \(LAN\)](https://www.chessprogramming.org/Algebraic_Chess_Notation#Long_Algebraic_Notation_.28LAN.29) and [standard one](https://www.chessprogramming.org/Algebraic_Chess_Notation#Standard_Algebraic_Notation_.28SAN.29).
Knowledge of these tools helps in producing good code, doing the right research, and implementing the function you need in the **order** you need.
With the right toolset, you can easily create an engine that is automatically testable from day 0.

## Unit testing
If you have some doubt on unit testing usefulness, writing a chess engine will show you why they are necessary. I think in chess engine programming unit testing was invented ages before normal people start to talk about these in that term, surely before Martin Fowler starts to write software, since first computer chess engine were created in the 70, and you cant just deal with a manual test in crafting a computer chess software.
I decided to write PICO in C++, when I started using C++ there was not handy tool for that, but now we have ( actually many ), and I decided to go with [gtest](https://github.com/google/googletest).
Very easy to install and get it up and running ( and that's good because one reason I hate C++ in the past was the pain of integrating someonelse code).
Just for share, starting with gtest is quite easy.
Just clone the repository, and then, in that folder, run:
```bash
cmake CMakeLists.txt
sudo make install
```
After that you have done. I embedded the test inside the code of the engine itself ( maybe in the future will skip these inreleases build) so I just had to link with additional
```
/usr/local/lib/libgtest.a
/usr/local/lib/libgtest_main.a
```
and adding the flag ```-pthread``` to the linker options.
After that, we can write such unit test (example):
```
TEST (MoveTest,e2e4_properly_done)
{
    OX88Board board;
    board.Init();

    MOVE m = OX88Board::FromAlgebraic("e2e4");
    board.Move(m);
    EXPECT_EQ(board.Fen(),"rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
    EXPECT_TRUE(board.SanityCheck());
}
TEST (MoveTest,e2e4_properly_undone)
{
    OX88Board board;
    board.Init();

    MOVE m = OX88Board::FromAlgebraic("e2e4");
    board.Move(m);
    board.UnMove(m);
    EXPECT_EQ(board.Fen(),"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    EXPECT_TRUE(board.SanityCheck());
}
```
Handy, isn't?
Now challenging part is to create a sensible amount of such test, before starting to write the *perft(n)* test, otherwise debugging it will be a pain. Solution for this is create automatically such tests with games found from the net.
