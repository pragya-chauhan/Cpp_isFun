#include <iostream>

using namespace std;

double fact(int n)
{   double fact1 = 1;
    for(int i=n; i>=1; i--)
    {
        fact1 = fact1*i;
    }
    return fact1;
}

double fact2(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return (n*fact2(n-1));
    }
}

int fibo(int n)

{   int old =0, fibo = 0;
    int newNum = 1;
    for(int i=1; i<=n; i++)
    {   if(i==2)
    {
        fibo = old + newNum;
    }
    else{
        fibo = old + newNum;
        old = newNum;
        newNum = fibo;

    }
    }   return fibo;

}

int fibo2(int n)
{
    if(n<=1)
    {
        return n;
    }
    else{
        return fibo2(n-1) + fibo2(n-2);
    }
}

double choose(int n, int r)
{
    if (r == 0) return 1;
if (r > n / 2) return choose(n, n - r);
double res = 1;

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;

}


int main() {
       cout << "5!: " << fact(5) << ", " << fact2(5) << '\n';
       cout << "15!: " << fact(15) << ", " << fact2(15) << '\n';
       cout << "5th: " << fibo(5) << ", " << fibo2(5) << '\n';
       cout << "13th: " << fibo(13) << ", " << fibo2(13) << '\n';
       cout << "Lottery: " << choose(52,6) << '\n';
     }

