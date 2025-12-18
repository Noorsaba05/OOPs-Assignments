#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <ctime> 

using namespace std;



string getCurrentTimestamp() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string timestamp(dt);
    timestamp.pop_back(); 
    return timestamp;
}


void logError(const string& message) {
   
    ofstream logFile("error_log.txt", ios::app);

    if (!logFile) {
        cerr << "Error: Unable to open log file!" << endl;
        return;
    }


    logFile << "[" << getCurrentTimestamp() << "] " << message << endl;

    logFile.close();
    cout << ">> Error logged to 'error_log.txt'" << endl;
}


void riskyOperation(const string& filename) {
    cout << "Attempting to open file: " << filename << "..." << endl;
    
    ifstream file(filename);

    if (!file) {
        // If file doesn't exist, THROW an exception
        throw runtime_error("FileNotFoundError: Could not open '" + filename + "'");
    }

    cout << "Success: File opened." << endl;
    file.close();
}

int main() {
    cout << "=== Assignment 8: Error Logger ===" << endl;

    // Test Case 1: File that does not exist
    string badFilename = "non_existent_file.txt";

    try {
        riskyOperation(badFilename);
    } 
    catch (const runtime_error& e) {
        // Catch the specific runtime error
        cerr << "Exception Caught: " << e.what() << endl;
        logError(e.what()); // Log it to file
    }
    catch (const exception& e) {
        // Catch any other standard exceptions
        cerr << "Unknown Exception: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\n-----------------------------------\n";

    // Test Case 2: Manually throwing a different error (e.g., Access Denied simulation)
    try {
        // Simulating a logic error or access issue
        bool accessDenied = true;
        if (accessDenied) {
            throw runtime_error("AccessDeniedError: User does not have permission.");
        }
    }
    catch (const exception& e) {
        cerr << "Exception Caught: " << e.what() << endl;
        logError(e.what());
    }

    cout << "\nProgram finished safely. Check 'error_log.txt' for details." << endl;

    return 0;
}
