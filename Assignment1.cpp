#include <iostream>
#include <string>
using namespace std;


inline int add(int a, int b) { return a + b; }
inline int subs(int a, int b) { return a - b; }
inline int multi(int a, int b) { return a * b; }
inline int divs(int a, int b) { return a / b; }


inline float add(float a, float b) { return a + b; }
inline float subs(float a, float b) { return a - b; }
inline float multi(float a, float b) { return a * b; }
inline float divs(float a, float b) { return a / b; }

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

 
    size_t op_pos = expr.find_first_of("+-*/");
    if (op_pos == string::npos) {
        cout << "Invalid expression no operator found.\n";
        return 1;
    }

    char op = expr[op_pos];
    string part1 = expr.substr(0, op_pos);
    string part2 = expr.substr(op_pos + 1);

    float a, b;

    
        a = stof(part1);
        b = stof(part2);
    
    
    float result;
    switch (op) {
        case '+': result = add(a, b); break;
        case '-': result = subs(a, b); break;
        case '*': result = multi(a, b); break;
        case '/':
            if (b == 0) {
                cout << "Error: Division by zero.\n";
                return 1;
            }
            result = divs(a, b);
            break;
        default:
            cout << "Unsupported operator.\n";
            return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}
