#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept> // For standard exceptions

using namespace std;



// --- Custom Exception ---
class InvalidInputException : public exception {
    string message;
public:
    InvalidInputException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// --- Abstract Base Class ---
class Employee {
protected:
    int empId;
    string name;
    string dept;

public:
    Employee(int id, string n, string d) : empId(id), name(n), dept(d) {}

    // Virtual Destructor
    virtual ~Employee() {
        // cout << "Destructor called for ID: " << empId << endl; 
    }

    // Pure Virtual Functions (Abstract)
    virtual double calculateSalary() const = 0; 
    virtual void displayDetails() const = 0;

    // Inline Function
    inline int getEmpId() const { return empId; }
    inline string getName() const { return name; }

    // Operator Overloading (==) for ID Search
    bool operator==(int searchId) const {
        return this->empId == searchId;
    }

    // File Handling: Save basic details
    void saveToFile() const {
        ofstream file("employees.txt", ios::app);
        if (!file) {
            throw runtime_error("File Error: Unable to open employees.txt");
        }
        file << empId << " | " << name << " | " << dept << endl;
        file.close();
    }
};

// --- Derived Class: Hourly Employee ---
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(int id, string n, string d, double rate, int hours)
        : Employee(id, n, d) {
        if (rate < 0 || hours < 0) throw InvalidInputException("Rate or Hours cannot be negative.");
        hourlyRate = rate;
        hoursWorked = hours;
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayDetails() const override {
        cout << left << setw(10) << empId 
             << setw(20) << name 
             << setw(15) << dept 
             << setw(15) << "Hourly" 
             << "Salary: " << calculateSalary() << endl;
    }
};

// --- Derived Class: Salaried Employee ---
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(int id, string n, string d, double salary)
        : Employee(id, n, d) {
        if (salary < 0) throw InvalidInputException("Salary cannot be negative.");
        monthlySalary = salary;
    }

    double calculateSalary() const override {
        return monthlySalary; // Fixed salary
    }

    void displayDetails() const override {
        cout << left << setw(10) << empId 
             << setw(20) << name 
             << setw(15) << dept 
             << setw(15) << "Salaried" 
             << "Salary: " << calculateSalary() << endl;
    }
};

// --- Derived Class: Contractual Employee ---
class ContractualEmployee : public Employee {
private:
    double contractAmount;

public:
    ContractualEmployee(int id, string n, string d, double amount)
        : Employee(id, n, d) {
        if (amount < 0) throw InvalidInputException("Contract amount cannot be negative.");
        contractAmount = amount;
    }

    double calculateSalary() const override {
        return contractAmount;
    }

    void displayDetails() const override {
        cout << left << setw(10) << empId 
             << setw(20) << name 
             << setw(15) << dept 
             << setw(15) << "Contract" 
             << "Salary: " << calculateSalary() << endl;
    }
};

// --- Helper Functions (Function Overloading) ---
void logAction(string action) {
    cout << "\n[LOG]: " << action << endl;
}

void logAction(string action, int id) {
    cout << "\n[LOG]: " << action << " (ID: " << id << ")" << endl;
}

// --- Main Menu Logic ---
int main() {
    // Dynamic Storage: Vector of pointers to Employee
    vector<Employee*> staff;
    int choice;

    while (true) {
        cout << "\n=== EMPLOYEE PAYROLL SYSTEM ===\n";
        cout << "1. Add Employee\n";
        cout << "2. Calculate & Display All Salaries\n";
        cout << "3. Search Employee by ID (Operator Overloading)\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 4) break;

        try {
            switch (choice) {
                case 1: {
                    int type, id;
                    string name, dept;
                    cout << "Select Type: 1.Hourly  2.Salaried  3.Contractual: ";
                    cin >> type;

                    cout << "Enter ID: "; cin >> id;
                    
                    // Check if ID already exists
                    bool exists = false;
                    for (auto e : staff) {
                        if (*e == id) { // Using operator==
                            exists = true; 
                            break;
                        }
                    }
                    if (exists) throw InvalidInputException("Employee ID already exists!");

                    cout << "Enter Name: "; cin >> name;
                    cout << "Enter Dept: "; cin >> dept;

                    Employee* newEmp = nullptr; // Pointer for dynamic allocation

                    switch (type) {
                        case 1: {
                            double rate; int hours;
                            cout << "Enter Hourly Rate: "; cin >> rate;
                            cout << "Enter Hours Worked: "; cin >> hours;
                            newEmp = new HourlyEmployee(id, name, dept, rate, hours);
                            break;
                        }
                        case 2: {
                            double sal;
                            cout << "Enter Monthly Salary: "; cin >> sal;
                            newEmp = new SalariedEmployee(id, name, dept, sal);
                            break;
                        }
                        case 3: {
                            double amt;
                            cout << "Enter Contract Amount: "; cin >> amt;
                            newEmp = new ContractualEmployee(id, name, dept, amt);
                            break;
                        }
                        default:
                            throw InvalidInputException("Invalid Employee Type Selected.");
                    }

                    
                    staff.push_back(newEmp);
                    
                    
                    newEmp->saveToFile();
                    
                    logAction("Employee added successfully", id);
                    break;
                }
                case 2: {
                    if (staff.empty()) {
                        cout << "No employees found.\n";
                    } else {
                        cout << "\n--- PAYROLL DETAILS ---\n";
                        cout << left << setw(10) << "ID" << setw(20) << "NAME" << setw(15) << "DEPT" << setw(15) << "TYPE" << "DETAILS\n";
                        cout << "----------------------------------------------------------------------\n";
                        for (Employee* e : staff) {
                           
                            e->displayDetails(); 
                        }
                    }
                    break;
                }
                case 3: {
                    int searchId;
                    cout << "Enter ID to Search: "; cin >> searchId;
                    bool found = false;
                    for (Employee* e : staff) {
                        // Using Operator Overloading: *e == searchId
                        if (*e == searchId) {
                            cout << "\n--- Employee Found ---\n";
                            e->displayDetails();
                            found = true;
                            break;
                        }
                    }
                    if (!found) cout << "Employee with ID " << searchId << " not found.\n";
                    break;
                }
                default:
                    cout << "Invalid menu choice.\n";
            }
        }
        catch (const InvalidInputException& e) {
            cerr << "\n[Input Error]: " << e.what() << endl;
        }
        catch (const exception& e) {
            cerr << "\n[System Error]: " << e.what() << endl;
        }
    }

    // Cleanup: Delete dynamically allocated memory
    for (Employee* e : staff) {
        delete e;
    }
    staff.clear();
    return 0;
}