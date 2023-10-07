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

int main() {

	return 0;
}
