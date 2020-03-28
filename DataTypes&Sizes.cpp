#include <iostream>
using namespace std;

/*
  421
	000 = 0
	001 = 1
	010 = 2
	011 = 3
	100 = 4
	101 = 5
	110 = 6
	111 = 7
    1
=====
 1000
  -21
	000 = 0
	001 = 1
	010 = 2
	011 = 3
	100 = -4
	101 = -3
	110 = -2
	111 = -1
 */

int main() {
    unsigned short a = 65000;
    unsigned short b =   540;
    unsigned short c =     0;
	cout << 7 * 24 * 60 * 60 << '\n';
	cout << 365 * 24 * 60 * 60 << '\n';
	cout << 69 * 365 * 24 * 60 * 60 << '\n';
	int age = 138;
	cout << age * 365 * 24 * 60 * 60 << '\n';
	//type promotion: when two types are different, promote the smaller
	// 3 + 2L
	cout << sizeof(365LL) << '\n';
  uint64_t secondsInAge = age * 365LL * 24 * 60 * 60;
	cout << secondsInAge << '\n';
     c = a + b;
    cout<<c<<endl;
    cout<<"Sizes of different datatypes\n";
    cout<<sizeof(int)<<endl;                //4bytes    
    cout<<sizeof(signed int)<<endl;         //4bytes
    cout<<sizeof(short)<<endl;              //  2
    cout<<sizeof(long)<<endl;       //8
    cout<<sizeof(long long)<<endl;      //8
    cout<<sizeof(double)<<endl;     //8
    cout<<sizeof(float)<<endl;      //4
    cout<<sizeof(char32_t)<<endl;       //4
    cout<<sizeof(char)<<endl;       //1
    cout<<sizeof(string)<<endl;     //8
    cout<<sizeof(uint64_t)<<endl;       //8
    cout<<sizeof(uint32_t)<<endl;       //4
    
    
    
    
    
    
    
    
    
    
    
    
}
