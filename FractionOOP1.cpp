#include<iostream>
using namespace std;

class Fraction{
  private:
  int num;
  int den;
  public:
  Fraction(int num, int den): num(num), den(den){
      
  }
  Fraction(int num): num(num), den(1){
      
  }
  Fraction(): num(0), den(1){
      
  }
  Fraction operator +(Fraction b) const{
      return Fraction(num*b.den+b.num*den, den*b.den);
  }
  Fraction add( Fraction b) const{
       return Fraction(num*b.den+b.num*den, den*b.den);
  }
  friend ostream& operator <<(ostream& s, const Fraction& a) {
      return s<< a.num<<","<<a.den<<endl; 
  }
  
};





int main() {
	const Fraction f1(1,2);
	const Fraction f2(1,3);
	const Fraction f2b(3); // 3/1
	const Fraction f2c; // 0/1
	//THIS IS WRONG, but not an error:  Fraction f2d(); // THIS IS NOT AN OBJECT!!!
	//ERROR: f2d is not an object	cout << 	f2d;
	//ERROR: f2d is not an object f1 = f2d + f2;
	
	Fraction f3 = f1.add(f2);
	Fraction f4 = f1.operator +(f2);
	Fraction f5 = f1 + f2;
	//f5 = f1 - f2;
//	Fraction f6 = f1 + 3; // automatically calls Fraction(3)  ==> 3/1
//	Fraction f7 = 3 + f1;
    cout<< f3 <<endl;
    cout<< f4 <<endl;
    cout<< f5 <<endl;
  //  cout<<f6<< endl;
	
}