#include <iostream>

using namespace std;

int main()
{
int a;
    cout<<"Please enter a positive integer: ";  //1
    cin>>a;                                     //2
    
    while( a != 1 ) {
      if(a%2==0)             //3
    a =a/2;
    else
    a = a*3 + 1;
    cout <<"\n"<<a;
   }
    return 0;
}