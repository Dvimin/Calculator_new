#pragma once

#include "ExpressionElements.h"
#include <algorithm>

class OperationsDescription {
public:
    OperationsDescription(const OperationsDescription&) = delete;
    OperationsDescription(OperationsDescription&&) = delete;
    OperationsDescription& operator=(const OperationsDescription&) = delete;
    OperationsDescription& operator=(OperationsDescription&&) = delete;

    static bool IsValidFunctionName(const std::string& name);
    static bool IsValidOperatorName(const std::string& name);
    static bool IsValidBracketName(const std::string& name);

    static OperationsDescription& GetInstance(void);

    bool CheckOperation(const std::string& name) const;
    bool CheckFunction(const std::string& operation) const;
    bool CheckOperator(const std::string& operation) const;
    bool CheckBracket(const std::string& operation) const;

    std::shared_ptr<Operation> GetFunction(const std::string& operation) const;
    std::shared_ptr<Operation> GetBracket(const std::string& operation) const;
    std::shared_ptr<Operation> GetOperator(const std::string& operation, ElementType type) const;

    void LoadOperation(std::shared_ptr<Operation> operation);
    void Clear(void);

private:
    OperationsDescription() = default;
    static bool IsBeginigFunctionName(const char symbol);
    static bool IsBeginingOperatorName(const char symbol);
    static bool IsBeginingBracketName(const char symbol);

    void AddFunction(std::shared_ptr<Operation> operation);
    void AddOperator(std::shared_ptr<Operation> operation);
    void AddBracket(std::shared_ptr<Operation> operation);

    std::map<std::string, std::shared_ptr<Operation>> functions;
    std::multimap<std::string, std::shared_ptr<Operation>> operators;
    std::map<std::string, std::shared_ptr<Operation>> brackets;
};

class BinaryOperator : public Operation {
public:
    enum class Associative {
        LEFT,
        RIGHT,
    };

    using DoBinaryOperation = std::shared_ptr<Literal>(*)(std::shared_ptr<Operand> a, std::shared_ptr<Operand> b);

    BinaryOperator() = delete;
    BinaryOperator(const std::string& name, int prioryty, DoBinaryOperation operation, Associative associative = Associative::LEFT) :
        name(name), prioryty(prioryty), doOperation(operation), assotiative(associative) {};

    int GetPriority(void) const {
        return prioryty;
    };

    Associative GetAssociative(void) const;
    ElementType GetType(void) const override final;
    std::string GetTokenName(void) const override final;
    void DoOperation(DataStack& dataStack) const override final;

private:
    DoBinaryOperation doOperation;
    const std::string name;
    const int prioryty;
    const Associative assotiative;
};

class PreficsOperator : public Operation {
public:
    using DoPreficsOperation = std::shared_ptr<Literal>(*)(std::shared_ptr<Operand> a);

    PreficsOperator() = delete;
    PreficsOperator(const std::string& name, int prioryty, DoPreficsOperation operation) :
        name(name), prioryty(prioryty), doOperation(operation) {};

    int GetPriority(void) const;
    ElementType GetType(void) const override final;
    std::string GetTokenName(void) const override final;
    void DoOperation(DataStack& dataStack) const override final;

private:
    DoPreficsOperation doOperation;
    const std::string name;
    const int prioryty;
};

class PostficsOperator : public Operation {
public:
    using DoPostficsOperation = std::shared_ptr<Literal>(*)(std::shared_ptr<Operand> a);

    PostficsOperator() = delete;
    PostficsOperator(const std::string& name, DoPostficsOperation operation) :
        name(name), doOperation(operation) {};


    ElementType GetType(void) const override final;
    std::string GetTokenName(void) const override final;
    void DoOperation(DataStack& dataStack) const override final;

private:
    DoPostficsOperation doOperation;
    const std::string name;
};

class OpenBracket : public Operation {
public:
    using DoFunc = std::shared_ptr<Literal>(*)(std::shared_ptr<Operand> a);

    OpenBracket() = delete;
    OpenBracket(const std::string& name, DoFunc operation) :
        name(name), doOperation(operation) {};

    ElementType GetType(void) const override final;
    std::string GetTokenName(void) const override final;
    void DoOperation(DataStack& dataStack) const override final;

private:
    DoFunc doOperation;
    const std::string name;
};

class CloseBracket : public Operation {
public:
    CloseBracket() = delete;
    CloseBracket(std::string name, std::string pare) :
        name(name), pare(pare) {};

    std::string GetPare(void) const;
    std::string GetTokenName(void) const override final;
    ElementType GetType(void) const override final;
    void DoOperation(DataStack& dataStack) const override final;

private:
    const std::string name;
    const std::string pare;
};

class Function : public Operation {
public:
    using DoFunc = std::shared_ptr<Literal>(*)(std::vector<std::shared_ptr<Operand>> args);

    Function() = delete;
    Function(std::string name, int argsNum, DoFunc operation) :
        name(name), argsNum(argsNum), doOperation(operation) {};

    std::string GetTokenName(void) const override final;
    ElementType GetType(void) const override final;
    void DoOperation(DataStack& dataStack) const override final;

private:
    DoFunc doOperation;
    const std::string name;
    const int argsNum;
};
