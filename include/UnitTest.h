#ifndef UNITTEST_H
#define UNITTEST_H


class UnitTest
{
    public:
        UnitTest();
        virtual ~UnitTest();
        void Run();
    protected:

    private:
        void fen_load_1();
        void fen_load_2();
        void fen_load_3();
        void fen_load_4();
        void fen_load_5();
        void fen_output_1();
        void fen_output_2();
        void fen_output_3();
        void fen_output_4();
        void check_empty();
};

#endif // UNITTEST_H
