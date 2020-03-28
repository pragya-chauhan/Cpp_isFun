#include <iostream>
using namespace std;

int main() {
	for (float i = 0; i <= 10; i++)
		cout << i << ' ';       //only increments in integers
	cout << '\n';
	// type promotion 0 --> 0.0f
	for (float i = 0; i <= 10; i += 0.1)        
		cout << i << ' ';                   
	cout << '\n';

//	for (float i = 0; i <= 1000; i += 0.1)
//		cout << i << ' ';
//	cout << '\n';

}
