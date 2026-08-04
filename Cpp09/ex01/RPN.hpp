#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN {
private:
    std::stack<long> _stack;

    bool _isOperator(char c) const;
    void _executeOp(char op);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void evaluate(const std::string& expression);
};

#endif