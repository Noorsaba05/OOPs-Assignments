#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;

public:
    
    User(string u, string p) {
        username = u;
        password = p;
    }

    
    string getUsername() { return username; }
    string getPassword() { return password; }
};


class UserManager {
private:
    const string filename = "users.txt"; 

public:
 
    void registerUser() {
        string u, p;
        cout << "\n--- Registration ---" << endl;
        cout << "Enter Username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;

        User newUser(u, p); 


        ofstream file(filename, ios::app); 
        
        if (file.is_open()) {
            
            file << newUser.getUsername() << " " << newUser.getPassword() << endl;
            file.close();
            cout << "Registration Successful! You can now login." << endl;
        } else {
            cout << " Error: Could not open file." << endl;
        }
    }

    
    bool loginUser() {
        string u, p, fileUser, filePass;
        cout << "\n--- Login ---" << endl;
        cout << "Enter Username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;

        ifstream file(filename); 
        bool loginSuccess = false;

        if (file.is_open()) {
        
            while (file >> fileUser >> filePass) {
               
                if (fileUser == u && filePass == p) {
                    loginSuccess = true;
                    break; 
                }
            }
            file.close();
        }

        if (loginSuccess) {
            cout << "Login Successful! Welcome, " << u << "." << endl;
            return true;
        } else {
            cout << " Invalid Username or Password." << endl;
            return false;
        }
    }
};


int main() {
    UserManager authSystem; 
    int choice;

    while (true) {
     
        cout << "----Authentication System----\n";
        
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                authSystem.registerUser();
                break;
            case 2:
                authSystem.loginUser();
                break;
            case 3:
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}










