#include <iostream>
using namespace std;

class Complex {
public:
    int *r, *i;
    
    Complex(int real = 0, int imag = 0){
        r = new int(real);
        i = new int(imag);
    }
     Complex(const Complex& other) {
        r = new int(*other.r);
        i = new int(*other.i);
    }
    
    ~Complex(){
        delete r;
        delete i;
    }
    
  Complex& operator=(const Complex& other) {
    if (this != &other) {
        *r = *other.r;
        *i = *other.i;
    }
    return *this;
}
    
    void getdata() {
        int real, imag;
        cout << "Enter Real and Imaginary Part: ";
        cin >> real >> imag;
        *r = real;
        *i = imag;
    }

    void display() {
        if (*i > 0) {
            cout << *r << " + " << *i << "i" << endl;
        } else {
            cout << *r << *i << "i" << endl;
        }
    }
    
    Complex operator + (Complex c) {
        return Complex(*r + *c.r, *i + *c.i);
    }
       
    Complex operator - (Complex c){
        return Complex(*r - *c.r, *i - *c.i);
    }
   
    Complex operator * (Complex c) {
	int real = (*r) * (*c.r) - (*i) * (*c.i);
	int imag = (*r) * (*c.i) + (*i) * (*c.r);
	return Complex(real, imag);
    }
    
    
    
};

int main() {
    Complex a, b, sum, subs, multi, div;

    a.getdata();
    b.getdata();

    sum = a + b;
    subs = a - b;
    multi = a * b;
    
	
    cout << "First Complex Number: ";
    a.display();

    cout << "Second Complex Number: ";
    b.display();

    cout << "Addition of Complex Numbers: ";
    sum.display();
    
    cout << "Subtraction of Complex Numbers: ";
    subs.display();
    
     cout << "Multiplication of Complex Numbers: ";
     multi.display();
     
    
    return 0;
}
