#include <iostream>
#include "OX88Board.h"
#include "UnitTest.h"
using namespace std;

int main()
{
    string arg;
    do
    {
        std::cin>>arg;
        if(arg=="quit")
        {
            break;
        }
        else if(arg=="test")
        {
            UnitTest ut;
            ut.Run();
        }
        else
        {
            std::cout<<"unknown command:"<<arg<<"\n";
        }

    }while(1);
    return 0;
}
