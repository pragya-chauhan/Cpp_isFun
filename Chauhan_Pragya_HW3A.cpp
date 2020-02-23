/*  Pragya Chauhan  pchauhan@stevens.edu
	Make the following main work by writing a class Complex.
	Notice that since objects are const, you will have to promise not to change them
 */
#include <iostream>
using namespace std;

class Complex
{   private: 
    double real;
    double imag;
   
    public:
     Complex(double real, double imag) : real(real), imag(imag){}        //constructor
     Complex add(Complex b) const {
         Complex ans(real+b.real , imag+ b.imag);
        return ans;
    }
     
     
     void print() const{
        cout<<"("<<real<<","<<imag<<")\n";     
     }
    
     friend Complex operator + (Complex a, Complex b){
         Complex c(a.real+b.real, a.imag+b.imag);
     
         return c;
     }  
    
    Complex operator -() const
    {
        return Complex (-real, -imag);
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