#include<iostream>
#include<string>
using namespace std;

class Employee{
protected:
	string name, dept;
	float salary;
	
public:
		virtual void getDetails(){
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Department: ";
			cin>>dept;
			cout<<"Enter base salary: ";
			cin>>salary;
		}

		virtual void displayDetails(){
			cout<<"Name: "<<name<<endl;
			cout<<"Department: "<<dept<<endl;
			cout<<"Salary: "<<salary<<endl;
		
		}
		
		virtual int computeSalary(){
			cout<<"Salary for employee:"<<salary<<endl ;
			return 0;
		}

};
class Manager:public Employee{
protected:
	int bonous;
	
	public: 
		void getDetails() override {
		Employee::getDetails();
		cout<<"Enter bonous for Manager: ";
		cin>>bonous;
		}
		
		 void displayDetails() override {
		 	cout<<"Name: "<<name<<endl;
			cout<<"Department: "<<dept<<endl;
			cout<<"Salary: "<<salary<<endl;
			cout<<"Bonous: "<<bonous;
		 }
		 
		 int computeSalary() override {
		 	cout<<"Salary for manager:"<<salary+bonous<<endl;
		 	return 0;
		 }
		 

};

class Director:public Manager{
protected:
	float perks;
	
	public: 
		void getDetails() override {
		Employee::getDetails();
		cout<<"Enter Perks for director: ";
		cin>>perks;
		}
		
		 void displayDetails() override {
		 	cout<<"Name: "<<name<<endl;
			cout<<"Department: "<<dept<<endl;
			cout<<"Salary: "<<salary<<endl;
			cout<<"Bonous: "<<bonous;
			cout<<"Perks: "<<perks;
		 }
		 
		 int computeSalary() override {
		  	cout<<"Salary for Director"<<salary+bonous<<endl;;
		  	return 0;
		 }
		 

};

int main(){

int ch;
Employee *ptr = nullptr;

		do{
			
			cout<<"-----Menu-----"<<endl;
			cout<<"1. Create Employee"<<endl;
			cout<<"2. Create Manager"<<endl;
			cout<<"3. Create Director"<<endl;
			cout<<"4. Display details"<<endl;
			cout<<"5. Compute Salary"<<endl;
			cout<<"6. Exit "<<endl;
			
			cout<<"Enter your choice: ";
			cin>>ch;

				switch(ch){
					case 1:
						 ptr = new Employee();
						 ptr->getDetails();
						 cout << "Employee Created!\n";
						 break;
					case 2:
						ptr = new Manager();
						ptr->getDetails();
						cout<<"Manager Created!\n";
						break;
					case 3:
						ptr = new Director();
						ptr->getDetails();
						cout<<"Director Created!\n";
						break;
					case 4:
						ptr->displayDetails();
						break;
					case 5:
	                                        ptr->computeSalary();
						break;
	                                    				
					case 6:
						cout<<"Exiting..."<<endl;
					break;
			}




	      }while(ch!=6);
}
