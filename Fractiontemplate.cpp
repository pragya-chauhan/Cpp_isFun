#include <iostream>
using namespace std;

template <typename T>
class Fraction {
private:
    T num, den;
public:
    Fraction (T num, T den) : num(num), den(den) {}
    Fraction (T num) : num(num) , den(1) {}

    friend ostream& operator << (ostream& s, const Fraction& a) {
        s << a.num << "/" << a.den;
        return s;
    }

    Fraction friend operator + (const Fraction& a, const Fraction& b) {
        return Fraction(a.num * b.den + b.num * a.den, a.den * b.den);
    }
};


int main() {
	Fraction<int> f1(1,2);
	Fraction<int> f2(1,3);
	Fraction<int> f3 = f1 + f2;
	Fraction<int> f4 = f1 + 2; // f1 + Fraction(2) = f1 + 2/1
	Fraction<int> f5 = 2 + f1; // Fraction(2) + f1
    cout << f1 << '\n';
    cout << f2 << '\n';
    cout << f3 << '\n';
    cout << f4 << '\n';
    cout << f5 << '\n';

}