#include<iostream>
using namespace std;

class MyNumber{

private:
	int *value;
public:
	MyNumber(int v=0){
	 value = new int;
	 *value = v;
	 cout<<"Constructor created with value:"<<*value<<endl;
	}	
	
	MyNumber(const MyNumber &other){
	value = new int;
	*value = *(other.value);
	cout<<"Copy-constructed with value = "<<*value<<endl;
	}
	
	MyNumber& set(int v){
	*value = v;
	return *this;
	}
	
	MyNumber& increment(){
	(*value)++;
	return *this;
	}
	
	void display() const
	{
	cout<<"Current value ="<<*value<<endl;

	}
	
	~MyNumber()
	{
	cout<<"Destroying object with value = "<<*value<<endl;
	delete value;
	}

};

int main(){
MyNumber *obj = new MyNumber(10);
obj->display();


	obj->set(20).increment().display();
	
	MyNumber copy = *obj; 
	copy.display();
	
	delete obj;

	copy.increment().display();

return 0;
}
