#pragma once

#include <string>
#include <vector>
#include <stack>
#include <map>
#include <memory>
#include <exception>

constexpr char DELIMETR_ARGS = ',';
constexpr char SIMBOL_BEFORE_ARGS = '(';
constexpr char SIMBOL_AFTER_ARGS = ')';

enum class ElementType {
	PREFICS, POSTFICS, BINARY, FUNCTION, OPEN_BRACKET, CLOSE_BRACKET, LITERAL, VARIABLE, DELIMETR_ARGS, SIMBOL_BEFORE_ARGS, SIMBOL_AFTER_ARGS,
};

class Operand {
public:
	virtual ~Operand() = default;
	virtual double GetValue(void) const = 0;
	virtual ElementType GetType(void) const = 0;
};

class Literal : public Operand {
public:
	Literal(double value) : value(value) {};
	Literal(Literal const& it) = default;
	Literal(Literal&& it) = default;
	Literal& operator=(const Literal& other) = default;
	Literal& operator=(Literal&&) = default;
	~Literal() = default;
	double GetValue(void) const;
	ElementType GetType(void) const;
private:
	const double value;
};

class Variable : public Operand {
public:
	Variable(const std::string& name) : isInit(false), name(name) {};
	Variable(Variable const& it) = default;
	Variable(Variable&& it) = default;
	Variable& operator=(const Variable& other) = default;
	Variable& operator=(Variable&&) = default;
	~Variable() = default;
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
	using DataStack = std::stack<std::shared_ptr<Operand>>;
	virtual std::string GetTokenName(void) const = 0;
	virtual ElementType GetType(void) const = 0;
	virtual ~Operation() = default;
	virtual void DoOperation(DataStack& dataStack) const = 0;
};
