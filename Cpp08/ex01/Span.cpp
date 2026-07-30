#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N); 
}

Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers) {}

Span &Span::operator=(const Span &rhs) {
    if (this != &rhs) {
        this->_maxSize = rhs._maxSize;
        this->_numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw FullContainerException();
    _numbers.push_back(number);
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return (maxVal - minVal);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minDiff = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }

    return minDiff;
}