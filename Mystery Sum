#include<iostream>
#include <cmath>
using namespace std;
int main()
{
    int  n,i,j,m,k;
    float  sum1 =0, sum2 =0, sum3=0;
    float result1, result2,result3;
    cout<<"Enter a positive integer:";    //1
    cin>>n;

    for( i = 1; i<=n; i++ )
    {                                                       //2
        sum1 = sum1 + 1/((float)i*(float)i);
    }
    result1 = sqrt(6 * sum1);
    cout<<"result1 = "<<result1;            //3

    cout<<"\nEnter a large positive number=";
    cin>>m;

    for( j = 1; j<=m; j++ )
    {                                                       //large value of n
        sum2 = sum2 + 1/((float)j*(float)j);
    }
    result2 = sqrt(6 * sum2);
    cout<<"result2 = "<<result2;

    for( k = m; k>=1; k-- )
    {                                                       //large value of n in reverse
        sum3 = sum3 + 1/((float)k*(float)k);
    }
    result3 = sqrt(6 * sum3);
    cout<<"\nresult3 = "<<result3;

}
