#include <iostream>
#include <math.h>
#include <map>
#include <string>

class Operation {
public:

	virtual double perform(double leftOperand, double rightOperand) const { return INFINITY; };
	virtual double perform(double Operand) const { return INFINITY; };
};

class SinFunction : public Operation {
public:
	double perform(double Operand) const override {
		return sin(Operand);
	}
};

class Addition : public Operation {
public:
	double perform(double leftOperand, double rightOperand) const override {
		return leftOperand + rightOperand;
	}
};

class Subtraction : public Operation {
public:
	double perform(double leftOperand, double rightOperand) const override {
		return leftOperand - rightOperand;
	}
};
class Multiplication : public Operation {
public:
	double perform(double leftOperand, double rightOperand) const override {
		return leftOperand * rightOperand;
	}
};
class Division : public Operation {
public:
	double perform(double leftOperand, double rightOperand) const override {
		return leftOperand / rightOperand;
	}
};
int main() {
	
	Operation* plus = new Addition();
	Operation* minus = new Subtraction();
	Operation* sin = new SinFunction();
	Operation* division = new Division();

	std::map<std::string, Operation*> operations;
	operations["+"] = plus;
	operations["-"] = minus;
	operations["/"] = division;
	operations["sin"] = sin;

	std::cout << plus->perform(10, 3) << " " << minus->perform(10, 3) << std::endl;
	std::cout << operations["-"]->perform(10, 3) << std::endl;
	std::cout << operations["sin"]->perform(3.14) << std::endl;
	std::cout << operations["sin"]->perform(3.14,8) << std::endl;
	std::cout << operations["/"]->perform(-8, 0) << std::endl;

	return 0;
}
