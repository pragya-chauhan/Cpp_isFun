#include<iostream>
#include<fstream>
using namespace std;

class Fraction{
  private:
  int num;
  int den;
  public:
  Fraction(int num, int den): num(num), den(den) {
     
  }
  Fraction(int num): num(num), den(1) {
      
  }
  Fraction(){
      
  }
  void print() const{
      cout<<num<<"\\"<<den<<endl;
  }
  void print(ostream& a) const{
       a <<num<<""<<"\\"<<den<<endl;
      }
      friend ostream& operator <<(ostream& s, const Fraction& a) {
          s<< a.num << "\\"  <<a.den <<endl;
          return s;
      }
      Fraction add (const Fraction& b) const{
          return Fraction (num*b.den + den*b.num, den*b.den);
      }
      
      friend Fraction operator +(const Fraction& a, const Fraction& b){
          return Fraction(a.num*b.den + a.den*b.num, a.den*b.den);
          
      }
      
};
int main() {
  const	Fraction a(1, 2); // 1/2 // a is an object, an instance of Fraction
	Fraction b(1, 3);
	Fraction c(-6, 5); // -6/5
	Fraction d(7, -5);
	Fraction e(1,0);
	Fraction f(3);
	Fraction g;
	a.print();
	b.print();
	Fraction h = a.add(b);
	Fraction h2 = a + b;
	int x = 2 + 3;
	ofstream s("test.dat");
	a.print(s);
	cout << a;
	cout<<h;
	cout<<c;
	//	cout << 6 << "hello" << a << 
}