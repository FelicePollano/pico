#include <iostream>
#include "OX88Board.h"
#include <gtest/gtest.h>
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
            ::testing::InitGoogleTest();
            return RUN_ALL_TESTS();
        }
        else
        {
            std::cout<<"unknown command:"<<arg<<"\n";
        }

    }while(1);
    return 0;
}
