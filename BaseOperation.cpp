#include "BaseOperation.h"


std::shared_ptr<Literal> Add(std::shared_ptr<Operand> a, std::shared_ptr<Operand> b) {
    return std::make_shared<Literal>(a->GetValue() + b->GetValue());
}

std::shared_ptr<Literal> Sub(std::shared_ptr<Operand> a, std::shared_ptr<Operand> b) {
    return std::make_shared<Literal>(a->GetValue() - b->GetValue());
}

std::shared_ptr<Literal> Mul(std::shared_ptr<Operand> a, std::shared_ptr<Operand> b) {
    return std::make_shared<Literal>(a->GetValue() * b->GetValue());
}

std::shared_ptr<Literal> Div(std::shared_ptr<Operand> a, std::shared_ptr<Operand> b) {
    return std::make_shared<Literal>(a->GetValue() / b->GetValue());
}

std::shared_ptr<Literal> Assign(std::shared_ptr<Operand> a, std::shared_ptr<Operand> b) {
    if (a->GetType() != ElementType::VARIABLE)
        throw std::exception("Impossible to assign a value to a non-variable");
    std::shared_ptr<Variable> var = std::dynamic_pointer_cast<Variable>(a);
    var->SetValue(b->GetValue());
    return std::make_shared<Literal>(var->GetValue());
}

std::shared_ptr<Literal> UnaryMinus(std::shared_ptr<Operand> a) {
    return std::make_shared<Literal>(-(a->GetValue()));
}

std::shared_ptr<Literal> PrefixIncrement(std::shared_ptr<Operand> a) {
    if (a->GetType() != ElementType::VARIABLE)
        throw std::exception("Cannot apply increment to constant");
    std::shared_ptr<Variable> var = std::dynamic_pointer_cast<Variable>(a);
    var->SetValue(a->GetValue() + 1);
    return std::make_shared<Literal>(var->GetValue());
}

std::shared_ptr<Literal> PrefixDecrement(std::shared_ptr<Operand> a) {
    if (a->GetType() != ElementType::VARIABLE)
        throw std::exception("Cannot apply increment to constant");
    std::shared_ptr<Variable> var = std::dynamic_pointer_cast<Variable>(a);
    var->SetValue(a->GetValue() - 1);
    return std::make_shared<Literal>(var->GetValue());
}

std::shared_ptr<Literal> PostfixIncrement(std::shared_ptr<Operand> a) {
    if (a->GetType() != ElementType::VARIABLE)
        throw std::exception("Cannot apply increment to constant");
    double result = a->GetValue();
    std::shared_ptr<Variable> var = std::dynamic_pointer_cast<Variable>(a);
    var->SetValue(a->GetValue() + 1);
    return std::make_shared<Literal>(result);
}

std::shared_ptr<Literal> PostfixDecrement(std::shared_ptr<Operand> a) {
    if (a->GetType() != ElementType::VARIABLE)
        throw std::exception("Cannot apply increment to constant");
    double result = a->GetValue();
    std::shared_ptr<Variable> var = std::dynamic_pointer_cast<Variable>(a);
    var->SetValue(a->GetValue() - 1);
    return std::make_shared<Literal>(result);
}

std::shared_ptr<Literal> Max(std::vector<std::shared_ptr<Operand>> args) {
    return std::make_shared<Literal>(args[0]->GetValue() > args[1]->GetValue() ? args[0]->GetValue() : args[1]->GetValue());
}

void LoadBase(OperationsDescription& dstr) {
    const BinaryOperator add = { "+", 1, Add };
    const BinaryOperator sub = { "-", 1, Sub };
    const BinaryOperator mul = { "*", 2, Mul };
    const BinaryOperator div = { "/", 2, Div };
    const BinaryOperator assign = { "=", 0, Assign, BinaryOperator::Associative::RIGHT };
    const PreficsOperator unaryMinus = { "-", 3, UnaryMinus };
    const PreficsOperator prefixIncrement = { "++", 5, PrefixIncrement };
    const PreficsOperator prefixDecrement = { "--", 5, PrefixDecrement };
    const PostficsOperator postfixIncrement = { "++", PostfixIncrement };
    const PostficsOperator postfixDecrement = { "--", PostfixDecrement };
    const OpenBracket openBracket = { "(", nullptr };
    const CloseBracket closeBracket = { ")", "(" };
    const Function max = { "max", 2, Max };

    dstr.LoadOperation(std::make_shared<BinaryOperator>(add));
    dstr.LoadOperation(std::make_shared<BinaryOperator>(sub));
    dstr.LoadOperation(std::make_shared<BinaryOperator>(mul));
    dstr.LoadOperation(std::make_shared<BinaryOperator>(div));
    dstr.LoadOperation(std::make_shared<BinaryOperator>(assign));
    dstr.LoadOperation(std::make_shared<PreficsOperator>(unaryMinus));
    dstr.LoadOperation(std::make_shared<PreficsOperator>(prefixIncrement));
    dstr.LoadOperation(std::make_shared<PreficsOperator>(prefixDecrement));
    dstr.LoadOperation(std::make_shared<PostficsOperator>(postfixIncrement));
    dstr.LoadOperation(std::make_shared<PostficsOperator>(postfixDecrement));
    dstr.LoadOperation(std::make_shared<OpenBracket>(openBracket));
    dstr.LoadOperation(std::make_shared<CloseBracket>(closeBracket));
    dstr.LoadOperation(std::make_shared<Function>(max));
}
