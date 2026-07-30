#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>
# include <iterator>
# include <climits>

class Span {
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

    Span();

public:
    Span(unsigned int N);
    Span(const Span &src);
    Span &operator=(const Span &rhs);
    ~Span();

    void    addNumber(int number);

    template <typename Iterator>
    void    addNumbers(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize)
            throw std::out_of_range("Pas assez d'espace pour ajouter la plage");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int     shortestSpan() const;
    int     longestSpan() const;

    class FullContainerException : public std::exception {
        virtual const char* what() const throw() { return "Le Span est plein !"; }
    };

    class NoSpanException : public std::exception {
        virtual const char* what() const throw() { return "Pas assez d'éléments pour calculer un Span (minimum 2 requis)."; }
    };
};

#endif