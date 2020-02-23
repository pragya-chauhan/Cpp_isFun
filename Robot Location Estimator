#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#define PI 3.14159265

using namespace std;

double polar2Rect(double r, double theta, double &dx, double &dy)
{
    if(r<0 || theta<0 ||r<0&& theta<0)
    {
        cout<<"\nRobot has reached final destination.";

    }
          else
          dx = dx + round((r*(sin(theta*PI/180))));
        dy = dy + round((r*(cos(theta*PI/180))));
      return dx;
        return dy;
}


int main()
{   double r, theta=0;
    double dx=0, dy=0;


    ifstream file("hw2e.dat");
  string str;
  while (!file.eof()) {
  double theta,r;
    file >> theta >>r;



    polar2Rect( r,  theta,  dx,  dy);
    if(r<0 || theta<0)
    {
        break;
    }
    else
    cout<<"\nNew robot position (X,Y):("<<dx;
    cout<<","<<dy<<").";



  }

}



