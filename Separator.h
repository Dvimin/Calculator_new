#pragma once

#include <string>
#include "API.h"

class Token {
public:
    enum class Type {
        DELIMETR_ARGS,
        LITERAL,
        FUNCTION,
        OPERATOR,
        BRACKET,
        VARIABLE
    };

    Token(Type type, std::string token) : type(type), token(token) {}

    Token(const Token&) = default;

    Token(Token&&) = default;

    Token& operator= (const Token&) = default;

    Token& operator= (Token&&) = default;

    ~Token() = default;

    Type GetType() const {
        return type;
    }

    std::string GetName() const {
        return token;
    }

private:
    const Type type;
    const std::string token;
};

std::vector<Token> Separate(const std::string& expression);
