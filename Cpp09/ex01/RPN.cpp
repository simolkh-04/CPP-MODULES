#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::_isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::_executeOp(char op) {
    if (_stack.size() < 2) {
        throw std::runtime_error("Error");
    }

    long b = _stack.top(); _stack.pop();
    long a = _stack.top(); _stack.pop();

    if (op == '+') _stack.push(a + b);
    else if (op == '-') _stack.push(a - b);
    else if (op == '*') _stack.push(a * b);
    else if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Error");
        _stack.push(a / b);
    }
}

void RPN::evaluate(const std::string& expression) {
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (std::isspace(c))
            continue;

        if (std::isdigit(c)) {
            _stack.push(c - '0');
        } else if (_isOperator(c)) {
            try {
                _executeOp(c);
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                return;
            }
        } else {
            std::cout << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << _stack.top() << std::endl;
    }
}