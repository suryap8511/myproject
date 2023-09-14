#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    ComplexNumber operator*(const ComplexNumber& other) const {
        double resultReal = (real * other.real) - (imaginary * other.imaginary);
        double resultImaginary = (real * other.imaginary) + (imaginary * other.real);
        return ComplexNumber(resultReal, resultImaginary);
    }

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& complex) {
        if (complex.imaginary >= 0) {
            os << complex.real << " + " << complex.imaginary << "i";
        } else {
            os << complex.real << " - " << -complex.imaginary << "i";
        }
        return os;
    }
};

int main() {
  
    ComplexNumber complex1(2, 3);
    ComplexNumber complex2(1, -1);

    ComplexNumber addition_result = complex1 + complex2;
    std::cout << "Addition: " << complex1 << " + " << complex2 << " = " << addition_result << std::endl;

    ComplexNumber subtraction_result = complex1 - complex2;
    std::cout << "Subtraction: " << complex1 << " - " << complex2 << " = " << subtraction_result << std::endl;

    ComplexNumber multiplication_result = complex1 * complex2;
    std::cout << "Multiplication: " << complex1 << " * " << complex2 << " = " << multiplication_result << std::endl;

    return 0;
}

