#include <iostream>
using namespace std;

template<typename T>
class Vec3d {
private:
    T x,y,z;
public:
    Vec3d (T x, T y, T z) : x(x), y(y), z(z){}
    Vec3d (T x, T y) : x(x), y(y), z(0) {}
    Vec3d (T x) : x(x), y(0), z(0) {}
    Vec3d () :x(0), y(0) , z(0) {}

    Vec3d friend operator + (const Vec3d& a, const Vec3d& b) {
        return Vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    Vec3d friend operator - (const Vec3d& a, const Vec3d& b) {
        return Vec3d(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    friend ostream& operator << (ostream& s, const Vec3d& a) {
        s << a.x << " " << a.y << " " << a.z;
        return s;
    }
};





int main() {
	// use friend operators
	const Vec3d<float> a(1.0,2.5,3.5); // double precision!
	const Vec3d<float> b(2.0);         //(2,0,0)
	const Vec3d<float> c(2.0,3.5);     //(2,3.5,0)
	const Vec3d<float> d;              //(0,0,0)

	const Vec3d<float> f = a + c;
	const Vec3d<float> g = b - d; // d is not an object, pick a different one

    cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	cout << f << '\n';
	cout << g << '\n';
}