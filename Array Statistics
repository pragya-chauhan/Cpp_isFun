#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{   double mean = 0.0;
    double Max = 0.0;
    double Min = 0.0;
    ifstream in("3B.dat");
    double readNumber;
    vector<double> vectorNumber ;
    while(in>> readNumber)
    {
        vectorNumber.push_back(readNumber);
    }

        cout<<"Elements = "<<vectorNumber.size() << endl;


            Max = *max_element(vectorNumber.begin(), vectorNumber.end());
            cout<<"Max = "<<Max;
            Min = *min_element(vectorNumber.begin(), vectorNumber.end());
            cout<<"\nMin = "<<Min;
            mean = (accumulate(vectorNumber.begin(), vectorNumber.end(),0.0f))/vectorNumber.size();
            cout<<"\nMean = "<<mean;
                float sum = accumulate(vectorNumber.begin(), vectorNumber.end(),0.0f, [&mean](float x, float y){return x + (y - mean) * (y - mean);
});
            float var = sum / vectorNumber.size();

              cout<<"\nVar = "<<var;
    return 0;
}
