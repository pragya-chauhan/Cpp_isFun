#include <iostream>
using namespace std;
int main()

{   
    float i =0,j=0;
    float sum1F=0, sum2F = 0;
    
    double p=0, q=0;
    double sum1D = 0, sum2D = 0;
    
    for(i=1; i<101; i++)
    {
        sum1F = sum1F + 1/i;
    }
    cout<<"Sum1F = "<<sum1F;
    for(j=100; j>0; j--)
    {
        sum2F = sum2F + 1/j;
    }
    cout<<", Sum2F = "<<sum2F;
    
    for(p=1; p<101; p++)
    {
        sum1D = sum1D + 1/p;
    }
    cout<<"\nSum1D = "<<sum1D;
    for(q=100; q>0; q--)
    {
        sum2D = sum2D + 1/q;
    }
    cout<<", Sum2D = "<<sum2D;
 
    cout<<"\nSum1F - Sum2F = "<<sum1F-sum2F;   
    cout<<"\nSum1D - Sum2D = "<<sum1D-sum2D;   
}
