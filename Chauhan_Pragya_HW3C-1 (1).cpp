#include<iostream>

using namespace std;

class Body {
    private:
    string name;
    double mass;
    double radius;
    double x;
    double y;
    double z;
    
    public:
    Body(string name, double mass, double x, double y, double z, double radius ): name(name), mass(mass), radius(radius), x(x), y(y), z(z){}
    
    friend ostream& operator <<(ostream& s, const Body& v){
        return s<< v.name<<", "<<v.mass<<", "<<v.x<<", "<<v.y<<", "<<v.z<<", "<<v.radius;
    }
};

int main() {
	//         name      mass(kg) x y z  radius (m)
	Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
	Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
	cout << earth << '\n';
	cout << moon << '\n';
}
