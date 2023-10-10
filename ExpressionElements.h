#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <memory>
#include <exception>

enum class ElementType {
	BINARY,
	FUNCTION,
	LITERAL,
	VARIABLE,
};

class Operand {
public:
	virtual double GetValue(void) const = 0;
	virtual ElementType GetType(void) const = 0;
};

class Literal : public Operand {
public:
	Literal(double value) : value(value) {};
	double GetValue(void) const;
	ElementType GetType(void) const;
private:
	const double value;
};

class Variable : public Operand {
public:
	Variable(const std::string& name) : isInit(false), name(name) {};
	static bool IsValidValueName(const std::string& name);
	double GetValue(void) const;
	ElementType GetType(void) const;
	std::string GetName(void) const;
	bool IsInit(void) const;
	void SetValue(const double value);
private:
	static bool IsBeginingValueName(const char symbol);
	double value;
	bool isInit;
	std::string name;
};

class Operation {
public:

};
