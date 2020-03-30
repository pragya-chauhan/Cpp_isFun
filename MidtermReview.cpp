#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class A {
public:
	A()  { cout << 'A'; }
	~A() { cout << "~A"; } 
};

class B : public A {
private:
	int x;
public:
	B(int x) : x(x) { cout << "B" << x; }
	~B()            { cout << "~B"; }
};

class Vehicle {
private:
	int speed;
public:
	Vehicle(int s) : speed(s) { cout << "V " << speed; }
	~Vehicle() { cout << "~V"; }
};
class Wheel {
public:
	Wheel(int p) { cout << "Wheel p=" << p; }
};

class Car : public Vehicle {
private:
	Wheel w1, w2, w3, w4;
public:
	Car(int s, int p) : Vehicle(s), w1(p), w2(p), w3(p), w4(p) {
		cout << "Car";
	}
	~Car() { cout << "~Car"; }
};

double rec(int n) {
	if (n < 3)
		return 4;
	return 1.5 * rec(n-2);
}

#define print(a)  cout << #a << ": " << a << '\n'
/*
	The macro print will print for a parameter p
   p: value
	 Type in the exact value
 */
int main() {
	int a1 = 17 / 4; print(a1); //4
	int a2 = 3 % 7;  print(a2); //3 
	int a3 = 7 % 3;  print(a3); //1
	int a4 = 3;      print(a4); //3 
	int a5 = a4++;   print(a5);//4  WRONG ANS 3 
	int a6 = ++a4;   print(a6); //4 WRONG ANS 5 
	int a7 = sizeof(uint32_t); print(a7); //4
	int a8 = sizeof(float);    print(a8); //4 
	int a9 = sizeof(double);   print(a9); //8 
	double b1 = 3 / 2;        print(b1); //1
	double b2 = (int)3.5 * 3; print(b2); //9.0   WRONG Ans 9 
	double b3 = int(3.5) * 3; print(b3);//9 
	double b4 = int(3.5 * 3); print(b4);//10
	double Z = 0.0; //0.0
	double b5 = 1.0 / Z;      print(b5);//inf                                       Read notes
	double b6 = -1.0 / Z;     print(b6);//-inf 
	double b7 = 5.0 / b5;     print(b7);//???? inf but wrong ans is 0
	double b8 = b5 + b6;      print(b8); //-nan ??????????????? Read notes
	double b9 = sin(b5);      print(b9);// ???????????? -nan
	double b10 = sqrt(b5);    print(b10); // ????/inf
	double b11 = rec(9);      print(b11);// rec???????????
	
	for (int i = 0; i < 100; i = i * 3 + 1)
		cout << i; //0141340                only one statement will run after for
	cout << '\n';

	for (int i = 3; i < 47; i = i * 2 - 2)
		cout << i;  //346101834
	cout << '\n';

	for (int i = 3; i < 47; i += 4)
		if (i % 3 == 0) //3152739
			cout << i;
	cout << '\n';
	
	
	double sum = 0;
	for (int i = 0; i < 100; i++)
		sum += 0.1; 
	bool c1 = sum == 10;      print(c1);    //0
	bool c2 = b9 == b9;       print(c2);    //??????????? -nan =! -nan
	bool c3 = b9 != b9;       print(c3);    //?????????
	int a = 2, b = 3;
	if (a < 3 && b > 2)       // what does the if statement print?
		cout << "yes\n";        //yes
	else
		cout << "no\n";
  B binst(3);               // what is the output of the class?
	cout << '\n';           //AB3
	vector<int> list;
	for (int i = 0; i < 10; i++)
		list.push_back(i);
	list.erase(list.begin() + 5);
	list.erase(list.begin() + 5);
	for (vector<int>::iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << ' ';
	cout << '\n'; // output?
	map<string,int> lookupId;
	lookupId["hello"] = 1;
	lookupId["apple"] = 2;	
	lookupId["good"] = 3;
	for (map<string,int>::const_iterator i = lookupId.begin(); i != lookupId.end(); ++i)
		cout << i->second << ' ';
	cout << '\n';
	
	
	
	int x[10] = {5, 1, 7, 9};
	int*p = &x[3];
	cout << *p << '\n';     //9
	p--;        
	cout << p[0] << '\n';   //??????????????//
	*(p-2) = 3;             //
	*p = 6;                 //
	for (p = x; p < x+5; p++)
		cout << *p << ' ';
	cout << '\n';
}

//destructor running in the end???????????????????????



/*
	legal or illegal
	be prepared for each statement in this section to state whether it is legal or illegal and if illegal, why. An answer of illegal is wrong unless it is properly explained.
*/

class X {
private:
	int x;
public:
	virtual void f() = 0;                       //abstract class
};

void legalOrillegal() {
	int a;
	//const int b; //illegal uninitialized const ‘b’ [-fpermissive]
	const int* c = &a;
	//c = &b;     //illegal
	//int* const d = &b;      //illegal invalid conversion from ‘const int*’ to ‘int*’
	//X x1;           //illegal  error: cannot declare variable ‘x1’ to be of abstract type ‘X’
	
	X *px1;     //legal
		delete px1;     
		
		
	//X createObject();   //illegal  invalid abstract return type ‘X’
	//createObject.f();       //illegal request for member ‘f’ in ‘createObject’, which is of non-class type ‘X()’

	int* e = new int[100];
	delete e;
	
	//int* f = malloc(1024* sizeof(int));     //?????????
//	delete [] f;

	int* g = new int;
	delete g;
	delete g;
	int* h;
}
