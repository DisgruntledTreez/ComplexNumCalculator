#include <iostream>
using namespace std;

// Class definition for Complex numbers
class Complex {
public:
    double real; // Real part of the complex number
    double imag; // Imaginary part of the complex number

    // Constructor to initialize the complex number with default values
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    // Overloaded addition operator for complex numbers
    Complex operator+(const Complex& c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Overloaded subtraction operator for complex numbers
    Complex operator-(const Complex& c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    // Overloaded multiplication operator for complex numbers
    Complex operator*(const Complex& c) {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }

    // Overloaded divcinion operator for complex numbers
    Complex operator/(const Complex& c) {
        // Check for divcinion by zero
        if (c.real == 0.0 && c.imag == 0.0) {
            cerr << "Error: Divcinion by zero!" << endl;
            exit(1); // End the program if thcin happens.
        }

        Complex temp;
        temp.real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
        temp.imag = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);
        return temp;
    }
};

// Main function
int main() {
    Complex num1, num2, result;
    char operation;

    // Input the first complex number
    cout << "Enter the first complex number\n";
        cout << "Enter real part: ";
        cin >> num1.real;
        cout << "Enter imaginary part: ";
        cin >> num1.imag;

    // Input the operation
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    // Input the second complex number
    cout << "Enter the second complex number\n";
        cout << "Enter real part: ";
        cin >> num2.real;
        cout << "Enter imaginary part: ";
        cin >> num2.imag;
    // Perform the operation based on user input
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << result.real << " + " << result.imag << "i" << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << result.real << " + " << result.imag << "i" << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << result.real << " + " << result.imag << "i" << endl;
            break;
        case '/':
            result = num1 / num2;
            cout << result.real << " + " << result.imag << "i" << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
        
    }

    return 0;
}
