#include <iostream>

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
        else
        {
            std:cout<<"unknown command:"<<arg<<"\n";
        }

    }while(1);
    return 0;
}
