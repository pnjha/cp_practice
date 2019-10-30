#include <iostream> 

using namespace std; 

class Distance { 
public: 

	// Member Object 
	int feet, inch; 

	// No Parameter Constructor 
	Distance() 
	{ 
		this->feet = 0; 
		this->inch = 0; 
	} 

	// Constructor to initialize the object's value 
	// Parametrized Constructor 
	Distance(int f, int i) 
	{ 
		this->feet = f; 
		this->inch = i; 
	} 

	// Declaring friend function using friend keyword 
	// friend Distance operator+(Distance&, Distance&); 
	Distance operator+(auto d2) // Call by reference 
	{ 
		// Create an object to return 
		Distance d3; 

		// Perform addition of feet and inches 
		d3.feet = this->feet + d2.feet; 
		d3.inch = this->inch + d2.inch; 

		// Return the resulting object 
		return d3; 
	} 
}; 

// Implementing friend function with two parameters 

// Driver Code 
int main() 
{ 
	// Declaring and Initializing first object 
	Distance d1(8, 9); 

	// Declaring and Initializing second object 
	Distance d2(10, 2); 

	// Declaring third object 
	Distance d3; 

	// Use overloaded operator 
	d3 = d1 + d2; 
	int a = 10, b = 10, c = 10;
	a = b + c;
	cout<<a<<"\n";
	// Display the result 
	cout << "Total Feet & Inches: " << d3.feet << "'" << d3.inch<<"\n"; 
	return 0; 
} 