#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <stack>
#include <stdexcept>

using namespace std;

// Constants
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;

// Memory storage
double memory = 0.0;

// Function prototypes
void displayMenu();
void displayResult(double result, const string& operation = "");
double evaluateExpression(const string& expression);
double factorial(int n);
vector<string> tokenize(const string& expression);
bool isOperator(const string& token);
int precedence(const string& op);
double applyOperator(double a, double b, const string& op);
bool isNumber(const string& token);

int main() {
    double result = 0.0;
    string input;
    bool running = true;
    
    cout << "===== Scientific Calculator =====" << endl;
    cout << fixed << setprecision(6);
    
    while (running) {
        displayMenu();
        cout << "Current value: " << result << endl;
        cout << "Enter your choice or an expression: ";
        getline(cin, input);
        
        // Check if input is empty
        if (input.empty()) {
            continue;
        }
        
        // Check if input is a menu option
        if (input == "0" || input == "exit" || input == "quit") {
            running = false;
            cout << "Thank you for using the Scientific Calculator!" << endl;
            continue;
        }
        
        try {
            // Handle special functions
            if (input == "sin") {
                cout << "Enter value (in radians): ";
                getline(cin, input);
                result = sin(evaluateExpression(input));
                displayResult(result, "sin");
            }
            else if (input == "cos") {
                cout << "Enter value (in radians): ";
                getline(cin, input);
                result = cos(evaluateExpression(input));
                displayResult(result, "cos");
            }
            else if (input == "tan") {
                cout << "Enter value (in radians): ";
                getline(cin, input);
                result = tan(evaluateExpression(input));
                displayResult(result, "tan");
            }
            else if (input == "log" || input == "log10") {
                cout << "Enter value: ";
                getline(cin, input);
                double value = evaluateExpression(input);
                if (value <= 0) {
                    throw runtime_error("Cannot calculate log of non-positive number");
                }
                result = log10(value);
                displayResult(result, "log");
            }
            else if (input == "ln") {
                cout << "Enter value: ";
                getline(cin, input);
                double value = evaluateExpression(input);
                if (value <= 0) {
                    throw runtime_error("Cannot calculate ln of non-positive number");
                }
                result = log(value);
                displayResult(result, "ln");
            }
            else if (input == "sqrt") {
                cout << "Enter value: ";
                getline(cin, input);
                double value = evaluateExpression(input);
                if (value < 0) {
                    throw runtime_error("Cannot calculate square root of negative number");
                }
                result = sqrt(value);
                displayResult(result, "sqrt");
            }
            else if (input == "pow") {
                cout << "Enter base: ";
                string baseInput;
                getline(cin, baseInput);
                double base = evaluateExpression(baseInput);
                
                cout << "Enter exponent: ";
                string expInput;
                getline(cin, expInput);
                double exponent = evaluateExpression(expInput);
                
                result = pow(base, exponent);
                displayResult(result, "pow");
            }
            else if (input == "fact" || input == "!") {
                cout << "Enter value: ";
                getline(cin, input);
                int value = static_cast<int>(evaluateExpression(input));
                if (value < 0) {
                    throw runtime_error("Cannot calculate factorial of negative number");
                }
                result = factorial(value);
                displayResult(result, "factorial");
            }
            else if (input == "exp") {
                cout << "Enter exponent: ";
                getline(cin, input);
                result = exp(evaluateExpression(input));
                displayResult(result, "exp");
            }
            else if (input == "ans") {
                // Keep the current result
                displayResult(result, "ans");
            }
            else if (input == "ms") {
                memory = result;
                cout << "Value " << result << " stored in memory." << endl;
            }
            else if (input == "mr") {
                result = memory;
                displayResult(result, "memory recall");
            }
            else if (input == "m+") {
                memory += result;
                cout << "Added to memory. Memory is now: " << memory << endl;
            }
            else if (input == "mc") {
                memory = 0.0;
                cout << "Memory cleared." << endl;
            }
            else if (input == "pi") {
                result = PI;
                displayResult(result, "π");
            }
            else if (input == "e") {
                result = E;
                displayResult(result, "e");
            }
            else if (input == "clear" || input == "c") {
                result = 0.0;
                cout << "Calculator cleared." << endl;
            }
            else {
                // Evaluate the expression
                result = evaluateExpression(input);
                displayResult(result);
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    
    return 0;
}

// Display the menu options
void displayMenu() {
    cout << "\n===== Operations =====" << endl;
    cout << "sin, cos, tan - Trigonometric functions" << endl;
    cout << "log, ln - Logarithmic functions" << endl;
    cout << "sqrt - Square root" << endl;
    cout << "pow - Power function (x^y)" << endl;
    cout << "fact or ! - Factorial" << endl;
    cout << "exp - Exponential function (e^x)" << endl;
    cout << "pi - π constant" << endl;
    cout << "e - e constant" << endl;
    cout << "ans - Use previous result" << endl;
    cout << "ms - Memory store" << endl;
    cout << "mr - Memory recall" << endl;
    cout << "m+ - Memory add" << endl;
    cout << "mc - Memory clear" << endl;
    cout << "clear or c - Clear calculator" << endl;
    cout << "0, exit, quit - Exit calculator" << endl;
    cout << "Or enter a mathematical expression directly (e.g., 2+3*4)" << endl;
    cout << "======================" << endl;
}

// Display a result with optional operation label
void displayResult(double result, const string& operation) {
    if (!operation.empty()) {
        cout << operation << "(" << result << ") = " << result << endl;
    } else {
        cout << "Result: " << result << endl;
    }
}

// Calculate factorial of integer n
double factorial(int n) {
    if (n > 20) {
        throw runtime_error("Factorial too large to calculate accurately");
    }
    double fact = 1.0;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Helper function to check if a string is a number
bool isNumber(const string& token) {
    if (token.empty()) return false;
    
    bool hasDecimal = false;
    size_t start = (token[0] == '-' || token[0] == '+') ? 1 : 0;
    
    if (start == token.size()) return false;
    
    for (size_t i = start; i < token.size(); i++) {
        if (token[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

// Check if a token is an operator
bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

// Get the precedence of operators
int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

// Apply an operator to two operands
double applyOperator(double a, double b, const string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "^") return pow(a, b);
    
    if (op == "/") {
        if (b == 0) {
            throw runtime_error("Division by zero");
        }
        return a / b;
    }
    
    throw runtime_error("Unknown operator");
}

// Tokenize an expression into numbers and operators
vector<string> tokenize(const string& expression) {
    vector<string> tokens;
    string current;
    
    for (size_t i = 0; i < expression.size(); i++) {
        char c = expression[i];
        
        // Handle whitespace
        if (isspace(c)) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
            continue;
        }
        
        // Handle operators and parentheses
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')') {
            // Special case for negative numbers
            if (c == '-' && (i == 0 || expression[i-1] == '(' || 
                isOperator(string(1, expression[i-1])))) {
                current.push_back(c);
            } else {
                if (!current.empty()) {
                    tokens.push_back(current);
                    current.clear();
                }
                tokens.push_back(string(1, c));
            }
        } else {
            current.push_back(c);
        }
    }
    
    if (!current.empty()) {
        tokens.push_back(current);
    }
    
    return tokens;
}

// Evaluate a mathematical expression using Shunting Yard algorithm
double evaluateExpression(const string& expression) {
    // Replace special constants
    string expr = expression;
    size_t pos;
    
    // Replace PI constant
    while ((pos = expr.find("PI")) != string::npos) {
        expr.replace(pos, 2, to_string(PI));
    }
    
    // Replace pi constant
    while ((pos = expr.find("pi")) != string::npos) {
        expr.replace(pos, 2, to_string(PI));
    }
    
    // Replace E constant
    while ((pos = expr.find("E")) != string::npos) {
        expr.replace(pos, 1, to_string(E));
    }
    
    // Replace e constant (when it's not part of another word)
    pos = 0;
    while ((pos = expr.find("e", pos)) != string::npos) {
        if ((pos == 0 || !isalnum(expr[pos-1])) && 
            (pos == expr.length()-1 || !isalnum(expr[pos+1]))) {
            expr.replace(pos, 1, to_string(E));
            pos += to_string(E).length();
        } else {
            pos++;
        }
    }
    
    // Tokenize the expression
    vector<string> tokens = tokenize(expr);
    
    stack<string> operators;
    stack<double> values;
    
    for (const string& token : tokens) {
        // Handle left parenthesis
        if (token == "(") {
            operators.push(token);
        }
        // Handle right parenthesis
        else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                string op = operators.top();
                operators.pop();
                
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                
                values.push(applyOperator(a, b, op));
            }
            
            if (!operators.empty() && operators.top() == "(") {
                operators.pop();  // Discard the left parenthesis
            } else {
                throw runtime_error("Mismatched parentheses");
            }
        }
        // Handle operators
        else if (isOperator(token)) {
            while (!operators.empty() && operators.top() != "(" && 
                   precedence(operators.top()) >= precedence(token)) {
                string op = operators.top();
                operators.pop();
                
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                
                values.push(applyOperator(a, b, op));
            }
            
            operators.push(token);
        }
        // Handle numbers
        else if (isNumber(token)) {
            values.push(stod(token));
        }
        // Unknown token
        else {
            throw runtime_error("Unknown token: " + token);
        }
    }
    
    // Process any remaining operators
    while (!operators.empty()) {
        string op = operators.top();
        operators.pop();
        
        if (op == "(" || op == ")") {
            throw runtime_error("Mismatched parentheses");
        }
        
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        
        values.push(applyOperator(a, b, op));
    }
    
    // The final result should be the only value left
    if (values.size() != 1) {
        throw runtime_error("Invalid expression");
    }
    
    return values.top();
}