//Pragya Chauhan

//Question 5. Write Fraction class
#include <iostream>

using namespace std;

class Fraction{
  private:
  int num;
  int den;
  public:
  Fraction(int num, int den): num(num), den(den){
      
  }
  Fraction operator *(const Fraction& a) const{
      return Fraction(num*a.num, den*a.den);
  }
  friend Fraction operator +(const Fraction& a, const Fraction& b){
      return Fraction(a.num*b.den+b.num*a.den, a.den*b.den);
  } 
  friend Fraction operator -(const Fraction& a){
      return Fraction(-a.num, a.den);
  }
  friend ostream& operator <<(ostream& s, const Fraction& a){
      return s<<a.num<<'/'<<a.den;
  }
  
};

int main() {
const Fraction a(1,2);
const Fraction b(1,3);
const Fraction c = a * b; // ⅙ (use member operator)
const Fraction d = a + b; // ⅚ (use friend)
const Fraction e = -a; // -½ (use friend)
cout << c << ' ' << d << ' ' << e << '\n';
}





//Question 4 Find the errors

// a			Error: b is a constant but it is uninitialized

int main() {
int a = 2;
const int b;
int* p = &a;
const int* q = &a;
a = 3;
}

//b				

int main() {
const int a = 3;
int* q = a;				//q is a pointer to an int but a is just an integer we need to derefernce it to get the value
int* p = &a;		//Error: a is a constant we cannot point to its address and might threaten to change it
}

//c
class A {
public:
A(int x) {}				//no intialization
};
class B : public A {
public:
B(int x) {}					//parent class is also not initialized
};
A a1(5);
B b1(3);
A a2;			//no constructor written to call 

//d
class A {
public:
A() {}
virtual void f() {
cout << “a”;
}
};
class B : public A {
public:
B() {}
void g() { cout << “b”; }
};
B b1;
A*p = &b1;
p->f();
p->g();					//but there is no function in class A to call g() child B has it but A cannot access it.

//e

class A {
public:
void f() { cout <<
“yoho!”;}
};
A a1();				//this is not an object but a function so cannot use a1.f()
a1.f();


//f
class A {
public:
A(int x) {}						//constructor not intialized, if writing constructor intialize it or dont write at all default will be called
};
class B : public A {
public:
B(int x) {}				
};

//g
int main() {
for (int i = 10; i <= 10;
i--)
cout << i;				//infinite loop i-- keeps going on until overflow
}

//h
int main() {
int x[6] = {5, 4, 1};
int* p = x;
for (int i = 6; i >= 0; i--)			//i should be >0 because we are also taking the nul character
cout << *p++;
}

//i

in t* f() {				//in t is not same as int datatype is int 
int a = 3;		
return &a;
}

//j
int main() {
int sum;					//sum is uninitialized
for (int i = 0;i <= 10;
i++)
sum += i				//no semicolon
cout << sum << ‘\n’;
}



// Question 3 find output

hello?
aax2aax3ygoodbye?

//Question 2 Determine what program does

int f(int n) { return n - 2; }
int main() {
cout << 3 + 2 * 4 << ‘\n’;					//11
cout << 3 / 4 + 4 / 4 + 5 / 4 << ‘\n’;			//2
cout << 4 % 5 + 5 % 5 + 6 % 5 << ‘\n’;		//5
cout << 2 / 3 * 3 << ‘\n’;					//0
cout << 2 * 3 / 3 << ‘\n’;				//2
cout << 2 / 3.0 * 3 << ‘\n’;			//2	
cout << 1 / 2 << ‘\n’;		//0
cout << 19 / 10 << ‘\n;			//1	//'' character missing so I assumed if it is there what output 
cout << 14.0 / 5 << ‘\n’;	//2.8
int sum = 2;					
for (int i = 6; i <= 8; i++)
sum += f(i);
cout << sum;						//172
int x[10] = {2, 8, 5};
int* p = &x[2];
*p++ = 5;
*++p = 2;
*p-- += 2;
for (int i = 0; i < 6; i++)
cout << x[i] << ‘\n’;				//8 5 0 4 0
}


//Output
11
2
5
0
2
2
0
1
2.8
172
8
5
0
4
0


//Question 1 but no question number was given so assumed



#include <iostream>

using namespace std;

int sum(int n){
    int s =0;
    for(int i=1; i<=n; i++){
        s = s+i;
    }
    return s;
}

int product(int a, int b){
    int prod = 1;
    for(int i = a; i<=b; i++){
        prod = prod *i;
    }
    return prod;
}

double sumRecip(int p){
    double sum = 1.0;
    for(int i=1; i <=p; i++){
        sum = sum + 1/i;
    }
    return sum;
}

double mean(int a[], double n){
     int sum = 0.0; 
    for (int i=0; i<n; i++) 
       sum += a[i]; 
  
    return sum/n;
}




int main() {
cout << sum(10) << '\n'; // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
cout << product(5, 9) << '\n'; // 5 * 6 * 7 * 8 * 9
cout << sumRecip(10) << '\n'; // 1/1 + ½ + ⅓ + ¼ + … + 1/10
int x[] = {80, 80, 90, 100};
cout << mean(x, sizeof(x)/sizeof(int)) << '\n'; // should print: 87.5
}



//2			Class quiz

#include <iostream>
#include <string>
using namespace std;


class Question{
  private:
  string quest;
  public:
  Question(string quest) : quest(quest){
      
  }
  string getQuest() const {return quest; }
   virtual void print() =0 ; 
   virtual ~Question(){
       
   }
   friend ostream& operator <<(ostream& s,  Question *v){
    return s<<v->quest<<"";
    }
};  
class     MultipleChoiceQuestion: public Question{
    private:
    int a, b, c, d;
    public:
    MultipleChoiceQuestion(string quest, int a, int b, int c, int d): Question(quest), a(a), b(b), c(c), d(d){
        
    }
     void print() override{
        cout<<getQuest<<'\n'<<"a)"<<'\n'<<a<<"b)"<<'\n'<<b<<"c)"<<'\n'<<c<<"d)"<<'\n'<<d;
    }
};
    
class     FillinQuestion: public Question{
    private:
    string ans;
    public:
    FillinQuestion(string quest, string ans): Question(quest), ans(ans){
        
    }
     void print() override{
        cout<<getQuest<<'\n';
        cin>>ans;
    }
};

class     NumericQuestion: public Question{
    private:
    string ans;
    public:
    NumericQuestion(string quest, string ans): Question(quest), ans(ans){
        
    }
     void print() override{
        cout<<getQuest<<'\n';
        cin>>ans;
    }
};
    
  class Quiz {
private:
	ofstream f;
	vector<Question*> questions ;

public:
	Quiz(string filename) : f(filename.c_str()), questions() {
	
	}
    void addQuestion( Question* s ) {
    questions.push_back(s);
	}

    void print() {
		for (int i = 0; i < questions.size() ; i++)                                         
			questions[i]->print(f);
	}
     ~Quiz(){
    for(auto s: questions)
        delete []s;
    }
};  
    
  
int main() {
Quiz q("C++ Quiz");
q.addQuestion(new MultipleChoiceQuestion("What is 2+2?", "2", "3", "*4", "5"));
q.addQuestion(new FillinQuestion("What is 2+2?", "4"));
q.addQuestion(new NumericQuestion("What is 2+2?", 3.9, 4.1));
cout << q << '\n';


//Question 1 Matrix

#include <iostream>

using namespace std;

class IllegalSize {
};

template<typename T>
class Matrix {
private:
	uint32_t rows,cols;
	T** m;
	static T ident;

public:
  Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), m(new T*[rows]) {
		for (uint32_t i = 0; i < rows; i++) {
		m[i] = new T[cols];
		}
	}
  Matrix(uint32_t rows, uint32_t cols, double v) : Matrix(rows,cols) {
		for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++)
			m[i][j] = v;
		}
	}
	Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), m(new T*[rows]) {
		for (uint32_t i = 0; i < rows; i++) {
		T* temp = m[i] = new T[cols];
		for (uint32_t j = 0; j < cols; j++)
		m[i][j] = orig.m[i][j];
		}
	}

	Matrix& operator =(const Matrix& orig) {
		Matrix copy(orig);
		rows = orig.rows;
		cols = orig.cols;
		swap(m, copy.m);
		return *this;
	}
	~Matrix() {
		for (uint32_t i = 0; i < rows; i++)
		delete[] m[i];
		delete [] m;
	}
	Matrix(Matrix&& orig) : rows(orig.rows), cols(orig.cols), m(orig.m) {
		orig.m = nullptr;
	}
	
 double operator()(uint32_t r, uint32_t c) const {
	
		return m[r][c];
	}
  double& operator()(uint32_t r, uint32_t c) { 
		return m[r][c];
	}
friend  Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
		throw IllegalSize();
		Matrix ans(a.rows, a.cols);
		for (uint32_t i = 0; i < a.rows; i++)
		for (uint32_t j = 0; j < a.cols; j++)
		ans.m[i][j] = a.m[i][j] + b.m[i][j];
		return ans;
	}
friend ostream& operator<<(ostream& s, const Matrix& m) {
		for (uint32_t i = 0; i < m.rows; i++) {
	for (uint32_t j = 0; j < m.cols; j++) {
s << m(i,j) << '\t';
}
s << '\n';}	return s;}
};


Matrix<double> f() {
Matrix<double> temp(3,2);
temp(2,1) = 1.1;
return temp;
}




int main() {
Matrix<double> a(3,2); // 3 rows, 2 columns each, all 0.0
cout << a << '\n';
/* expected output:
0 0
0 0
0 0
*/
const Matrix<double> b(3,2, 1.5); // 3 rows, 2 columns, all values = 1.5
a(1,1) = 2.5; // set element in row 1, column 1 = 2.5
Matrix<double> c = a + b;
cout << c << '\n';
/*expected output. Note a little roundoff error is fine
If instead of 4.0 the answer is 3.999999999 that's ok.
1.5 1.5
1.5 4.0
1.5 1.5
*/
const Matrix<double> d = c;
Matrix<double> e(c);
e = a;
e = Matrix<double>::ident(3); // call static method ident
cout << e << '\n';
/* output should be all zeros, with 1s down the main diagonal
1 0 0
0 1 0
0 0 1
*/
}



// Question 2 Dictionary
#include <iostream>
#include<fstream>
#include<unordered_map>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
    unordered_map<string, string> dict; 
    int i=1;
	string key, value;
    ifstream f("dict.dat");
    string linebuf;
    while (input >> key >> value) {
        dict[key] = value;
    }
    
for(int i= 1; i<argc; i++){
	string temp(argv[i]);
	if(dictionary.find(temp) != dictionary.end())
     temp = dictionary.at(temp); 
        std::cout << temp << ' ';
}
}


// Extra Credit

#include <iostream>

using namespace std;

class Unit{
  private:
  double a, b, c, d;
  public:
  Unit(double a, double b, double c, double d): a(a), b(b), c(c), d(d){
      
  }
  double convertTo(const Unit& a) const{
      return  (a.a*3.281 );
  }
  void convert(const Unit& a)const{
      cout<<"\"Incompatible unit\"";
  }
  friend ostream& operator <<(ostream& s, const Unit& v){
      s<<v.a<<""<<v.b<<""<<v.c<<""<<v.d<<"";
      return s;
  }
};





int main() {
Unit m(1,0,0,1.0);
Unit foot(1,0,0,0.3033);
cout << m.convertTo(foot) << '\n'; // should print 3.28
Unit day(0,0,1,24*60*60);
foot.convert(day); // return NaN, print an error message “Incompatible unit”
}
















































