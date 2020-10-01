// https://www.youtube.com/watch?v=qsMahidcehY

// #include <bits/stdc++.h> 

// using namespace std; 

// class Test{
// private:
// 	Test(){
// 	}
// public:
// 	~Test(){}
// 	int val = 0;
// 	Test(int v){
// 		val = v;
// 	} 
// 	int operator + (Test &b){
// 		return b.val - val;
// 	}
// 	int operator++ (int){
// 		return ++val;
// 	}
// };

// int main(){

// 	Test a(10);// = new Test(10);
// 	Test b(2);// = new Test(2);
// 	Test *c = new Test(2);
// 	cout<<a + b<<"\n";
// 	cout<<a++<<"\n";
// 	delete c;
// 	return 0;
// }

// class test1{
// public: 
// 	virtual int add(int a) { return a + 1;} //virtual function
// 	virtual int add(int a) = 0; //pure virtual function
// };

// class test2 : public test1{
// public: 
// 	int add(int a){ return a + 10;}
// };

// int main(){
	
// 	test1 *t1 = new test2;
// 	test2 *t2 = new test2;
// 	test2 a;
	
// 	cout<<a.add(5)<<"\n";
// 	cout<<t1->add(5)<<"\n";
// 	cout<<t2->add(5)<<"\n";

// 	return 0;
// }

// class Test{

// public: 

// 	static int cnt;
// 	int g = 0;

// 	void* operator new(size_t sz){
// 		cnt++;
// 		return (void*)malloc(sizeof(sz));
// 	}

// 	void operator delete(void* t){
// 		cnt--;
// 		free(t);
// 	}

// 	int get_instances(){
// 		return cnt;
// 	}
// };

// int Test::cnt = 0;

//Global operator overloading for integer data type
// void* operator new(size_t size, int val = 0){
// 	void* p = (void*)malloc(sizeof(size));
// 	if(p) *static_cast<int*>(p) = val;
// 	return p;
// }

// void operator delete(void* t){
// 	free(t);
// }

// int main(){

	// Test a,b,c;
	// cout<<c.get_instances()<<"\n";

	// Test *t = (Test *)malloc(sizeof(Test)); //malloc does not call constructor, just creates memory
	// cout<<t->get_instances()<<"\n";

// 	Test *t = new Test;
// 	cout<<Test::cnt<<"\n";
	
// 	t->g = 0;
// 	Test *f = t;

// 	cout<<&(*t)<<" "<<&(*f)<<"\n";

// 	delete t;

// 	cout<<&(*t)<<" "<<&(*f)<<"\n";
// 	cout<<t->g<<"\n";

// 	f->g = 0;

// 	cout<<Test::cnt<<"\n";
// 	return 0; 
// } 














// CPP program without virtual destructor 
// causing undefined behavior 
// #include<iostream> 

// using namespace std; 

// class base { 
// public: 
// 	base()	 
// 	{ cout<<"Constructing base \n"; } 
// 	virtual ~base() 
// 	{ cout<<"Destructing base \n"; }	 
// }; 

// class derived: public base { 
// public: 
// 	derived()	 
// 	{ cout<<"Constructing derived \n"; } 
// 	~derived() 
// 	{ cout<<"Destructing derived \n"; } 
// }; 

// int main(void) 
// { 
// //derived *d = new derived(); 
// base *b = new derived(); 
// delete b; 
// // getchar(); 
// return 0; 
// } 





#include <iostream> 

using namespace std;
  

// class Test1; 
  
// class Test2 { 
// public: 
//     void showTest1(Test1&); 
// }; 
  
// class Test1 { 
// private: 
//     int b; 
  
// public: 
//     Test1() { b = 0; } 
//     friend void Test2::showTest1(Test1& x); // Friend function 
// }; 
  
// void Test2::showTest1(Test1& x) 
// { 
//     std::cout << "B::b = " << x.b<<"\n"; 
// } 
  
// int main() 
// { 
//     Test2 a; 
//     Test1 x; 
//     a.showTest1(x); 
//     return 0; 
// }

class B;

class A{
public: 
	void getval(B& b);
protected:
	int k = 100;
};

class C : public A{
public:
	C(){
		cout<<A::k<<"\n";
	}
};

class B{
private: 
	int val = 10;
public:
	friend void A::getval(B& b);
	friend void new_fun(B& b);
};

void A::getval(B& b){
	cout<<b.val<<"\n";
}

void new_fun(B& b){
	cout<<b.val<<"\n";
}

int main(){

	C c;
	A a;
	B b;
	a.getval(b);
	new_fun(b);
	return 0;
}


























