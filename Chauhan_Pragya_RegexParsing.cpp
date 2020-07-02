#include <iostream>
#include <fstream>
#include<regex>
using namespace std;

#define NUM_READ_LINES 25

int main() {
	char s[NUM_READ_LINES][50];
	int counter = 0;

	
	ifstream inFile("hwregexcpp.txt",ifstream::in);

	
	if (inFile.good()) {

		
		while (!inFile.eof() && (counter < NUM_READ_LINES)) {
			inFile.getline(s[counter],50);
			counter++;
		}

		
		for (int i = 0; i < counter; i++) {
			cout << s[i] << endl;
		}
	}

	inFile.close();	
    
    regex r( R"(class([\s]+[\w_]+)[\s]*[:}]*[(public)(private)\s]*([\w_]*))");
	
	
    cmatch m;
 char (*p)[50] = s;
    char n;
//	cout << "Target sequence: " << *p << endl;
	//	cout << "Regular expression: " << r << endl;
	cout << "The following matches and submatches were found:" << endl;
for(int i=0; i<counter; i++){
   regex_search (s[i],m,r); 
		  for (auto x : m)
		//cout << m[0] << "\t" << '\n';
		//p = p + m.position() + m.length();
		cout << x << "\n\n";        //submatches and length
}

    
	return 0;
}