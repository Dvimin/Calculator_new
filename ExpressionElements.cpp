#include "ExpressionElements.h"

double Literal::GetValue(void) const {
    return value;
}
ElementType Literal::GetType(void) const {
    return ElementType::LITERAL;
}

double Variable::GetValue(void) const {
    if (isInit != true)
        throw std::exception(("Variable " + name + " not init").c_str());
    return value;
}

ElementType Variable::GetType(void) const {
    return ElementType::VARIABLE;
}

std::string Variable::GetName(void) const {
    return name;
}

bool Variable::IsInit(void) const {
    return isInit;
};

void Variable::SetValue(const double value) {
    this->value = value;
    isInit = true;
};