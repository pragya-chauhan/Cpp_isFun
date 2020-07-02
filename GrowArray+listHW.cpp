//Pragya Chauhan	pchauhan@stevens.edu CPE553


#include <iostream>
#include<memory.h>

using namespace std;



template<typename P>
class GrowArray {
private:
    int capacity;//length
    int size;
    P* data;
    void checkGrow() {
		if (size >= capacity){
		P* old = data;
		data = new P[size+size];
		for (int i = 0; i < size; i++)
			    data[i] = old[i];
		delete [] old;
		capacity = size+size;
		}
	}
public:
    // constructor
    GrowArray(int capacity) : capacity(capacity), size(0), data(new P[capacity]) {}   //reinterpret_cast<P*>(new char[sizeof(P)*capacity]
    
    ~GrowArray() { delete [] data; }
    
    void add(int v) {		
        checkGrow();
		data[size++] = v; }
    
    
    
    // removeEnd
    void removeEnd(){
        size--;
        }

    GrowArray(const GrowArray& orig) : capacity(orig.capacity), size(orig.size), data(new P[orig.capacity]) {
	 memcpy(data, orig.data, orig.size*sizeof(P)); 
	 }

    GrowArray& operator =(GrowArray copy) {
		capacity = copy.capacity;
		size = copy.size;
		swap(data, copy.data);
		return *this;
        
    }
    
     GrowArray(GrowArray&& orig) : capacity(orig.capacity), size(orig.size), data(orig.data) {
		orig.data = nullptr;
	}


  

    friend ostream& operator <<(ostream& s, const GrowArray& list){
        for (int i = 0; i < list.size; i++)
            s << list.data[i] << '\t';
        return s;
    }


};

template<typename T>
class List {
private:
  int capacity;
	T* data;
public:
  List() : capacity(0), data(nullptr) {}
	~List() {
		delete [] data;
	}

	List(const List& orig) : capacity(orig.capacity), data(new T[orig.capacity]) {
		memcpy(data, orig.data, capacity*sizeof(T));
	}

	//old way of disabling operator =: 	List& operator =(List copy);
	//new way of disabling operator =: 	List& operator =(List copy) = delete;
	List& operator =(List copy) {
		capacity = copy.capacity;
		swap(data, copy.data);
		return *this;
	}
	
	void add(const T& v) {
		T* old = data;
		data = new T[capacity+1]; // your object must contain constructor T()
    for (int i = 0; i < capacity; i++)
			data[i] = old[i];
		data[capacity++] = v; 
    delete [] old;
	}
	friend ostream& operator <<(ostream& s, const List& list) {
		for (int i = 0; i < list.capacity; i++) {
			s << list.data[i] << ' ';
		}
		return s;
	}
};

int main() {
GrowArray<int> a(100);
	for (int i = 0; i < 1000000; i++)
		a.add(i);
	for (int i = 0; i < 999990; i++)
		a.removeEnd();
	// should have 0 1 2 3 4 5 6 7 8 9		 
	cout << a << '\n';
	
	List<string> b;
	b.add("hello");
	string s[] = { "test", "this", "now" };
	
	for (int i = 0; i < sizeof(s)/sizeof(string); i++)
		b.add(s[i]);
	cout << b << '\n';
}
