//With help from StackOverflow :

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main()
{   int ROWS = 0;
    int COLS = 0;

    int numbers[12][12];


    ifstream inputFile;
    inputFile.open("3C.dat");

    inputFile >> ROWS;
    inputFile >> COLS;

    for(int countRows = 0; countRows < ROWS; countRows++)
    {
        for(int countColumns = 0; countColumns < COLS; countColumns++)
        {
            inputFile >> numbers[countRows][countColumns];
        }
    }

    inputFile.close();

    for(int i=0;i<COLS;i++)
    {
        numbers[ROWS][i] = 0;
        for(int j=0;j<ROWS;j++)
        {
            numbers[ROWS][i] +=numbers[j][i];
        }

    }

    for(int i=0;i<ROWS+1;i++)
    {
        numbers[i][COLS] = 0;
        for(int j=0;j<COLS;j++)
        {
            numbers[i][COLS] +=numbers[i][j];
        }
    }

    for(int i=0;i<ROWS+1;i++)
    {
        if(i==ROWS)
        {
            for(int j=0;j<(COLS+1)*10;j++)
                cout << "-";
            cout <<endl;
        }
        for(int j=0;j<COLS+1;j++)
        {
            if(j==COLS) cout << "| rowsum =";
            cout << setw(2) <<   numbers[i][j] << " ";

        }
        cout <<endl;
    }

    return 0;
}
