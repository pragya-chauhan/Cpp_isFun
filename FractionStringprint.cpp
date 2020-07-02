#include<iostream>
#include<string>
using namespace std;

class Fraction{
  private:
  int num;
  int den;
  public:
  Fraction(int num, int den): num(num), den(den) {
      
  }
  Fraction(): num(0), den(1){
      
  }
  Fraction(int num): num(num), den(1){
      
  }
  Fraction add(const Fraction& a) const{
      return Fraction(num*a.den+den*a.num, den*a.den);
  }
  Fraction sub(const Fraction& a)const{
      return Fraction(num*a.den-den*a.num, den*a.den);
  }
  #if 0
  void print(const Fraction& a)const{
      cout<<num<<"/"<<den<<endl;                //will run without this use only when f1.print() without argument inside
  }
  #endif 0
  friend ostream& operator <<(ostream& s, const Fraction& a){
      return s<<a.num<<"/"<<a.den<<endl;
  }
  friend string print(const Fraction& a){
      return to_string(a.num)+"/" +to_string(a.den);
  }
};
int main() {
	// Main() Section 1
	Fraction f1;		// 1/1, Assume num and den are 1
	const Fraction f2(1,2); // 1/2
	Fraction f3(5);         // 5/1, Given number is num, assume den is 1
	Fraction f4(1,3);       // 1/3

	// Main() Section 2
	Fraction f5 = f2.add(f4); // 1/2 + 1/3 = 5/6
	Fraction f6 = f4.sub(f3); // 5/1 - 1/3 = 14/3


	// Main() Section 4
   cout << "f1: " << print(f1) << '\n'; // print format: (1/1)
	cout << "f2: " << print(f2) << '\n';
	cout << "f3: " << print(f3) << '\n';
	cout << "f4: " << print(f4) << '\n';
	cout << "f5: " << print(f5) << '\n';
	cout << "f6: " << print(f6) << '\n';


}
