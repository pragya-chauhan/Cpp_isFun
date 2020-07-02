#include<iostream>
using namespace std;

class Complex{
  private:
  double real;
  double imag;
  
  public:
  Complex(double real, double imag): real(real), imag(imag){
      
  }
  friend Complex operator +(const Complex& a , const Complex& b) {
      return Complex(a.real+b.real, a.imag+b.imag);
  }
  void print() const{
      cout<<real<<","<<imag<<endl;
  }
  Complex add(const Complex& b)const{
      return Complex(real+b.real, imag +b.imag);
  }
  Complex operator -() const{
      return Complex(-real, -imag);
  }
  friend ostream& operator <<(ostream& s, const Complex& a){
      s<<a.real<<","<<a.imag<<endl;
      return s;
  }
};
int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using a friend function
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
	e.print();
}