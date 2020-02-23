#include <iostream>

using namespace std;

int main()
{   int i,sum, j, fsum=0;
    for(i=1; i<101; i++){               //A
        sum=i*(i+1)/2;
        
    }
    cout<<"Gauss Results: "<<sum;
    for(j=1; j<101; j++){
    fsum = fsum + j;                    //B
    }
    cout<<"\nLoop Reuslt: "<<fsum;
    if(sum = fsum)
    cout<<"\nBoth results are the same.";
	else
	cout<<"\nResult is not same.";
    
    return 0;
}
