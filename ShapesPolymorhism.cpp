#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Shape{
private:
    double x;
    double y;
public:
    Shape(double x, double y): x(x), y(y){}
    double getX() const {return x; }
    double getY() const {return y;}
    virtual void draw(ostream& s) = 0;          //abstract class used in all children
    virtual ~Shape() {}

    friend ostream& operator <<(ostream& s,  Shape *v){
    v->draw(s);
    return s;
    }
};

class FilledRect: public Shape{
private:
    double z;
    double h;
public:                                // d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
    FilledRect(double x, double y, double z, double h): Shape(x,y), z(z), h(h) {}
    void draw(ostream& s)  override{
        s<<getX()<<' '<< getY() <<" moveto \n";
		s<<getX()+z<<' '<<getY()<<" lineto \n";
		s<<getX()+z<<' '<<getY()+h<<" lineto \n";
		s<<getX()<<' '<<getY()+h<<" lineto \n";
		s<<"closepath \n";
		s<<"fill \n";
    }
    };

class Rect: public Shape{
private:
    double z;
    double h;
public:
    Rect(double x, double y, double z, double h): Shape(x,y),  z(z), h(h) {}
    void draw(ostream& s)  override{
    s<<getX()<<' '<< getY() <<" moveto \n";
		s<<getX()+z<<' '<<getY()<<" lineto \n";
		s<<getX()+z<<' '<<getY()+h<<" lineto \n";
		s<<getX()<<' '<<getY()+h<<" lineto \n";
		s<<"closepath \n";
		s<<"stroke \n";
    }
    };

class FilledCircle: public Shape{
private:
    double r;                                           // x y r 0 360 arc fill
public:
    FilledCircle(double x, double y, double r):Shape(x,y), r(r) {}
    void draw(ostream& s)  override{
        s<< getX()<<' ' << getY()<<' ' << r<<' '  <<"0 " <<"360 "<< "arc \n";
        s <<"fill \n";
    }
      };

class Circle: public Shape{
private:
    double r;
public:
    Circle(double x, double y, double r): Shape(x,y), r(r) {}
    void draw(ostream& s)  override{
    s<< getX()<<' ' << getY()<<' ' << r<<' '  <<"0 " <<"360 "<< "arc \n";
    s <<"stroke \n";
    }
    };

class Line: public Shape{
private:
    double z;
    double h;
public:
    Line(double x, double y, double z, double h): Shape(x,y), z(z), h(h) {}
    void draw(ostream& s)  override{
    s<< getX()<<' ' << getY()<<' ' <<"moveto \n";
    s<< z<<' ' << h<<' ' <<"lineto \n";
    s<<"stroke \n";
    }
     };

class Polygon: public Shape{
private:
    double l;
    int n;
public:
    Polygon(double x, double y, double l, int n): Shape(x,y), l(l), n(n) {}
    void draw(ostream& s)   override{
    double ang = 360/n;
    s<< "gsave \n";
		s<< getX() << ' ' << getY() << ' ' << "translate \n";
		s<< "0 0 moveto \n";
		s<< n << " {" << l << " 0 lineto currentpoint translate " << ang << " rotate} repeat \n";
		s<< "closepath \n";
		s<< "stroke \n";
		s<< "grestore \n"<<endl;
    }
    };




class Drawing {
private:
	ofstream f;
	vector<Shape*> shapes ;

public:
	Drawing(string filename) : f(filename.c_str()), shapes() {
	                                              //Drawing d("test2.ps");

	}
    void add( Shape* s ) {
    shapes.push_back(s);
	}

    void draw() {
		for (int i = 0; i < shapes.size() ; i++)                                          //shapes[i]->end()
			shapes[i]->draw(f);
	}
     void setrgb(int r, int g, int b)   {
	f<<r<<' '<<g<<' '<<b<<" setrgbcolor \n";                    //d.setrgb(1,0,0);
	}
    ~Drawing(){
    for(auto s: shapes)
        delete s;
    }
};


int main() {
	ofstream f;
	Drawing d("test2.ps");
	d.setrgb(1,0,0); // set drawing color to be bright red:  1 0 0 setrgbcolor
    d.add(new FilledRect(100.0, 150.0, 200.0, 50)); // x y moveto x y lineto ... fill
    d.add(new Rect(100.0, 150.0, 200.0, 50));       // x y moveto x y lineto ... stroke
	for (int x = 0; x < 600; x += 100)
		d.add(new FilledCircle(x,200,50.0)); // x y r 0 360 arc fill
	d.setrgb(0,1,0); // the rest are green

	d.add(new Circle(0,0, 100)); // 0 0 100 0 360 stroke
	d.add(new Line(400,500, 600,550));
	d.add(new Polygon(200,200, 50, 6));
	d.draw();
}
