#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) {
        
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex operator-(const Complex& c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    Complex operator*(const Complex& c) {
        Complex temp;
        temp.real = (real * c.real) - (imag * c.imag);
        temp.imag = (real * c.imag) + (imag * c.real);
        return temp;
    }

    Complex operator/(const Complex& c) {
        // Check for division by zero
        if (c.real == 0.0 && c.imag == 0.0) {
            cerr << "Error: Division by zero!" << endl;
            exit(1); // You can handle this error in a way that suits your needs
        }

        Complex temp;
        temp.real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
        temp.imag = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Enter real part: ";
        is >> c.real;
        cout << "Enter imaginary part: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    Complex num1, num2, result;
    char operation;

    cout << "Enter the first complex number:\n";
    cin >> num1;

    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    cout << "Enter the second complex number:\n";
    cin >> num2;

    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            result = num1 / num2;
            cout << "Result: " << result << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }

    return 0;
}
