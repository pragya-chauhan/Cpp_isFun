#include <iostream>
using namespace std;

class C {
	int x;
public:
	C(int x) : x(x) {}
	virtual void f() = 0;		//abstract class =0
};

class D : public C {             //class D inheriting class C publically
	int y;
public:
	D(int x, int y) : C(x), y(y) {}
};

class F : public D {                  //class F inheriting class D publically
public:
	F(int x, int y) : D(x,y) {}
	void f() { cout << "F"; }
};

int main() {
	//C c1;     // error:no matching function for call to ‘C::C()’ object declared should look excatly as the function
	//C c2(3);    //error: cannot declare variable ‘c2’ to be of abstract type ‘C’
	//C c3(int x);    //error: invalid abstract return type ‘C’
	C* cp; // It is ALWAYS legal to declare a pointer
	//D d1;     error: no matching function for call to ‘D::D()’
	//D d2(1,2);  error: cannot declare variable ‘d2’ to be of abstract type ‘D’
  //d1.f();
	F f1(1,2);  //Why?????????????
	f1.f();
}
