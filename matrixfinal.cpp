#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double** m;
    Matrix(int rows, int cols) : rows(rows), cols(cols), m(new double* [rows]){
        for (int i = 0; i < rows; i++)
            m[i] = new double [cols];
    }

public:

    // constructor
    Matrix(int rows, int cols, double val) : Matrix(rows, cols) {
        for (int i = 0; i < rows; i++){
            double* temp = m[i] = new double [cols];
            for (int j = 0; j < cols; j++)
                temp[j] = val;
        }
    }

    // destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete [] m[i];
        delete [] m;
    }


    // copy constructor
    Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols), m(new double* [rows]) {
        for (int i = 0; i < rows; i++){
            double* temp = m[i] = new double [cols];
            for (int j = 0; j < cols; j++)
                temp[j] = orig.m[i][j];
        }
    }

    // operator =
    Matrix& operator = (const Matrix& orig) {
        Matrix copy(orig);
        rows = orig.rows;
        cols = orig.cols;
        swap(m, copy.m);
        return *this;
    }

    friend ostream& operator << (ostream& s, const Matrix& mat) {
        for (int i = 0; i < mat.rows; i++){
            for (int j = 0; j < mat.cols; j++)
                s << mat(i,j) << " ";
            s << '\n';
        }
        return s;
    
    }

};


int main(){
    Matrix a( 4, 3, 0.0);
    a(2,2) = 1.5;
    a[2][1] = 2.5;
    Matrix b( 4, 3, 0.0);
    b(1,2) = 1.2;
    b(0,0) = -1.1;
    Matrix c = a + b;
    cout << c << '\n';

    Matrix d( 3, 2, 1.0); // 4x3 x 3x2 = 4x2 matrix
    Matrix e = a * d;

    cout << e << '\n';

    b = d;
    cout << d << '\n';

}