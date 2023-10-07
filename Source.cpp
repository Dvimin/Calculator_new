#include <iostream>
#include <math.h>

class Operation {
public:
	virtual double perform(double leftOperand, double rightOperand) const = 0;
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

class Function {
public:
	virtual double fun(double argument) const = 0;
};

class SinFunction : public Function {
public:
	double fun(double argument) const override {
		return sin(argument);
	}
};

class CosFunction : public Function {
public:
	double fun(double argument) const override {
		return cos(argument);
	}
};

int main() {

	return 0;
}
