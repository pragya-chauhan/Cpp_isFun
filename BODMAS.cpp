#include <iostream>
using namespace std;

int main() {
	cout << 2 + 3 * 4 << '\n';  //14
	cout << 2 * 3 / 2 << '\n';  //3
	cout << 2 / 3 * 3 << '\n';  //0
	cout << 2.0/ 3 *3 << '\n';//Why????????????
	cout << 2 / 3 * 2.0 << '\n';//0
	
	uint32_t w = 2 + 2;
	int x = 2 - 5;
	uint32_t x2 = 2 - 5;
	int y = 3 * 4;
	int z = 2 / 3;
	int a = 2 % 3; // 2 MOD 3
	cout << w << ' ' << x << ' ' << x2 << ' ' << y << ' ' << z << ' ' << a << '\n';  //4 3 4------- 12 0 2 
	cout << 5 % 3 << 6 % 3 << 7 % 3 << 8 % 3 << '\n';  // % n  --> 0 to n-1
	
}
