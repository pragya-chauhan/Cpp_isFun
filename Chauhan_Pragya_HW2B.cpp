#include <iostream> 

using namespace std; 
  
bool isPrime(int a) 
{ 
  for (int i = 2; i < a; i++) 
	if (a % i ==0) 
  return false; 
  return true; 
} 
  
int main() 

{ 
    int a;  
    cout<<"Please enter a positive integer:";
    cin>>a;
    isPrime(a);
    if (isPrime(a) == false)
    cout<<"The number  "<<a<<" is: NOT PRIME";
    else
    cout<<"The number  "<<a<<" is: PRIME";
    
    return 0; 
} 