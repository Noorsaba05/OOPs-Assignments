#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string name;
    int rollno;

    virtual void insert() {
        cin.ignore();
        cout<<"Enter Name: ";
        getline(cin, name);
        cout<<"Enter Roll No: ";
        cin >> rollno;
    }

    virtual void display() {
        cout<<"Name: " << name << endl;
        cout<<"Roll No: " << rollno << endl;
    }
};

class Academic : public virtual student {
public:
    int marks;

    void insert() override {
        student::insert();
        cout<<"Enter Academic Marks: ";
        cin >> marks;
    }

    void display() override {
        student::display();
        cout<<"Marks: " << marks << endl;
    }
};

class extra_Curr : public virtual student {
public:
    string activity;

    void insert() override {
        student::insert();
        cin.ignore();
        cout<<"Enter Extra Curricular Activity: ";
        getline(cin, activity);
    }

    void display() override {
        student::display();
        cout<<"Activity: " << activity << endl;
    }
};

class report : public Academic, public extra_Curr {
public:
    void insert() {
        Academic::insert();       
        extra_Curr::insert();   
    }

    void display() {
        Academic::display();
        cout<<"Activity: " << activity << endl;
    }
};

int main() {
    report r;
    r.insert();
    cout<<"\n----- Student Report -----\n";
    r.display();

    return 0;
}

