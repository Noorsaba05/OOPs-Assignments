#include <iostream>
using namespace std;

int main() {
    int ch, n = 0;
    int a[10]; 
    int tot = 0;
    float per;
    char grade;

    do {
        cout << "\nStudent Grading System\n";
        cout << "1. Input Marks\n";
        cout << "2. Calculate Total and Display Grade and Percentage\n";
        cout << "3. Display Highest and Lowest Marks\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "Enter number of subjects: ";
                cin >> n;
                for(int i = 0; i < n; i++) {
                    cout << "Enter Marks for subject " << i+1 << ": ";
                    cin >> a[i];
                }
                break;

            case 2:
                tot = 0;
                for(int i = 0; i < n; i++) {
                    tot += a[i];
                }
                per = (float)tot / (n * 100) * 100;

              
                if(per >= 90) grade = 'A';
                else if(per >= 70) grade = 'B';
                else if(per >= 60) grade = 'C';
                else if(per >= 50) grade = 'D';
                else grade = 'F';

                cout << "Total Marks are: " << tot << endl;
                cout << "Percentage is: " << per << "%" << endl;
                cout << "Grade: " << grade << endl;
                break;

            case 3:
                if(n == 0) {
                    cout << "No marks entered yet.\n";
                    break;
                }

                int high, low;
                high = low = a[0];

                for(int i = 1; i < n; i++) {
                    if(a[i] > high) high = a[i];
                    if(a[i] < low)  low = a[i];
                }

                cout << "Highest Marks: " << high << endl;
                cout << "Lowest Marks: " << low << endl;
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while(ch != 4);

    return 0;
}

