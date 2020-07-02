#include <iostream>
#include <memory.h>
using namespace std;

class BadSize {
private:
    const char* filename;
    int lineNum;
public:
    BadSize(const char filename[], int lineNum) :
            filename(filename), lineNum(lineNum) {}
    friend ostream& operator <<(ostream& s, const BadSize& b) {
        return s << b.filename << ": " << b.lineNum << " size mismatch";
    }
};

class Matrix {
private:
    int rows, cols;
    double* m;
    static int count;
public:
    Matrix(int rows, int cols, double val = 0) : rows(rows), cols(cols),m(new double[rows*cols]) {
        for (int i = 0; i < rows*cols; i++)
            m[i] = val;
    }
    Matrix(int rows, int cols):rows(rows),cols(cols),m(new double[rows*cols]){
        for (int i=0;i<rows*cols;i++)
        m[i]=0;
    }
    ~Matrix() {delete [] m;}
    friend ostream& operator<<(ostream& s, const Matrix& a){for(int i=0,j=0;i<a.rows*a.cols;i++)
        {
        s<<a.m[i]<<" ";j++;if(j>=a.cols){s<<"\n";j=0;}
        }
        return s;
    }

        friend istream& operator>>(istream& s, Matrix& a)
        {for(int i=0;i<a.rows*a.cols;i++)
            {s>>a.m[i];} return s;
        }

    Matrix(const Matrix& orig):rows(orig.rows),cols(orig.cols){for(int i=0;i<orig.rows*orig.cols;i++){m[i]=orig.m[i];}}
    Matrix& operator=(const Matrix& orig){Matrix copy(orig);
        this->rows = copy.rows;
        this->cols = copy.cols;
        swap(this->m, copy.m);
        return *this;}

    static Matrix identity(int i){return Matrix(i,i,0);}
    static int getCount() {
        return count;
    }
    static Matrix scale(int n, double v) {
        Matrix a(n,n,0);
        for (int i = 0; i < a.rows*a.cols; i += a.rows+1)
            a.m[i] = v;
        return a;
    }
    //https://stackoverflow.com/questions/77005/how-to-automatically-generate-a-stacktrace-when-my-program-crashes
    friend  Matrix operator +(const Matrix& left, const Matrix& right) {
        if (left.rows != right.rows || left.cols != right.cols)
            throw BadSize(__FILE__, __LINE__);
            Matrix copy(left);for(int i=0;i<left.rows*left.cols;i++){copy.m[i]=left.m[i]+right.m[i];}
            return copy;
    }

    friend  Matrix operator *(const Matrix& left, double right) {
        Matrix copy(left);for(int i=0;i<left.rows*left.cols;i++){copy.m[i]=left.m[i]*right;}
        return copy;
    }

    friend Matrix operator *(const Matrix& left, const Matrix& right){
        if (left.rows != right.cols || left.cols != right.rows)
            throw BadSize(__FILE__, __LINE__);
        Matrix A(left.rows,right.cols,0);
        for(int i=0;i<left.rows*right.cols;i++){
            for(int j=0;j<left.cols;j++)
            {A.m[i]+=left.m[i/right.cols*left.cols+j]*right.m[i%right.cols+j*right.cols];}
        }
        return A;
    }


    Matrix& operator =(double b){for(int i=0;i<rows*cols;i++){m[i]=b;}}
    double& operator ()(int i, int j)  {
        return m[(i-1)*cols +j-1];
    }
};

//globally defines the static variable
int Matrix::count = 0;

int main() {
    Matrix m1 = Matrix::identity(4);
    m1(1,3) = 5.5;
    Matrix m2 = m1 * 2.5; // scalar multiplication
    Matrix m3 = m1 + m2;
    cout << m3 << '\n';
    Matrix m4 = m3; // copy constructor
    cout << m4 << '\n';
    cin >> m4;
    // optional: matrix mult 50%
    Matrix m5(2,3, 1.0);
    m5(1,2) = 2.0;
    Matrix m6(3, 4, 2.0);
    m6(2,1) = -1;
    m6(2,3) = -2;
    Matrix m7 = m5 * m6;
    cout << m7 << '\n';
}
