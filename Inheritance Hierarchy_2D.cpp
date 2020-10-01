#include <iostream>
using namespace std;

class C {                          //declaration of base class
	int x;
public:
	C(int x) : x(x) {}
	virtual void f() {}
};

class D : public C {                    //class D inheriting class C publically
	int y;
public:
	D(int x, int y) : C(x), y(y) {}
	virtual void g() = 0;
};

class F : public D {                   //class F inheriting class D publically
public:
	F(int x, int y) : D(x,y) {}
	void f() { cout << "F"; }
};

class G : public F {                     //class G inheriting class F publically
public:
	G(int x, int y) : F(x,y) {}
	void g() { cout << "G"; }
};

int main() {
//	C c1(1,2);// illegal, no matching constructo
	C c2 (2); // legal
//	D d1(1,2); // illegal, abstract class //error: cannot declare variable ‘d1’ to be of abstract type ‘D’
//	F f1(1,2); // illegal, inherits g() from D                          WHY?????????????
	G g1(1,2); // LEGAL!
//	G g2;   error: no matching function for call to ‘G::G()’
	G* gp = &g1;
	C* cp = &g1;
	g1.g();
//	cp->g();  error: ‘class C’ has no member named ‘g’
}
