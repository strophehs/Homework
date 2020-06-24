#include<iostream>
using namespace std;
class MyClass
{
    char  ch;
public:
    MyClass( )
    {
        cout<<"This is a constructor! "<<endl;
        ch='a';
    }
    MyClass(char character )
    {
        cout<<"This is a constructor! "<<endl;
        ch=character;
    }
    void Print( )
    {
        cout<<"The value of ch is "<<ch<<endl;
    }
    ~ MyClass( )
    {
        cout<<"This is a destructor of "<<ch<<endl;
    }
};
int  main( )
{
    MyClass first, second('b');
    first.Print( );
    second.Print( );
    return 0;
}

