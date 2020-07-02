#include<iostream>
using namespace std;

void print(const int x[], int size){
    for(int i = 0; i<size; i++)
    cout<<""<<x[i];
}

void fill(int x[], int size){
    for(int i=0; i<size; i++){
    int *p = x;
    *p++ = 0;
    }
}

void increment(int x[], int size){
    for(int i =0; i<size; i++)
    x[i] = x[i] +1;
}

void doubleMe(int x[], int size) {
    for(int i = 0; i<size; i++)
    x[i] = x[i]*2;
}



int main() {
	int x[10] = {1};
	const int size = sizeof(x)/sizeof(int);
	print(x, size);
	fill(x, size);
	print(x, size);
	increment(x, size);
	print(x, size);
	doubleMe(x, size);
	print(x, size);
	
}