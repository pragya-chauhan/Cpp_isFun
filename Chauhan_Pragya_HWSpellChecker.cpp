//Pragya Chauhan 

#include <iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<fstream>
#include<sstream>


using namespace std;

int main(int argc, char* argv[])

{
    unordered_map<string, int> dict; 
    int i=1;
    ifstream f("dict.txt");
    string linebuf;
    while(!f.eof()){
        getline (f,linebuf);
        //cout<<linebuf<<endl;
        dict[linebuf] = i++;
    }
    
    for(int i=1; i < argc; i++){
       // string book = argv[i];
        //cout<<book;
               fstream file;
               file.open(argv[i]);
               while(!file.eof()){
                   string sent;
        getline (file,sent);
               
    
        //cout<<linebuf<<endl;
        for (unordered_map<string, int>::iterator i = dict.begin();
			 i != dict.end(); ++i) {
         if (dict.find(sent) == dict.end())
            continue;
            else            
            cout<<sent<<endl;
    }}
           file.close();
    }
    
    
    
    
    
   
    
    
    
    
    
}
