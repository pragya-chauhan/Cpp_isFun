//DynamicArray when we want to reserve a chink of memory like vector we need three pointers
// check in main DynamicArray b2(1000) and DynamicArray  a1;

#include<iostream>

using namespace std;

class DynamicArray{
  private:
  
             
  int capacity;     //memory reserved
  int size;             //no of elements
  int *p;
  void checkgrow(){
      if(size>=capacity){
          int *old = p;     //remember the old memmory
          p= new int[size+size];
          for(int i= 0; i<size ; i++) //copy the new
          p[i] = old[i];
          delete [] old;
          capacity = size + size;
      }
  }
  
  public:
  DynamicArray():  capacity(1),size(0),p(new int[1])    {
      
  }
  DynamicArray(int initialcapacity):  capacity(initialcapacity), size(0), p(new int[initialcapacity]){
      
  }
  ~DynamicArray(){
      delete [] p;
  }
  void add(int v){
      checkgrow();
      p[size] = v;           //size 0 adding there first
      size++;   }
      //cbheckgrow()
    friend ostream& operator <<(ostream& s, const DynamicArray& d){
        for(int i=0; i<d.size; i++){
            s<<d.p[i]<<'\n';
            return s;
        }
    }    
 
};

int main(){
DynamicArray a1;
for(int i=0; i<100; i++){
    a1.add(i);
    cout<<a1;
}    
DynamicArray b1(1000);
for(int i=0; i<1000; i++){
    b1.add(i);
    cout<<b1;
    
}

}