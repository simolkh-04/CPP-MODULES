#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <ctime>
# include <cstdlib>
# include <cctype>
# include <climits>
# include <algorithm>
# include <iomanip>

class PmergeMe {
private:
    std::vector<int>    _vec;
    std::deque<int>     _deq;
    double              _timeVec;
    double              _timeDeq;

    std::vector<int>    _generateJacobsthal(size_t n) const;

    void                _sortVector(std::vector<int>& arr);

    void                _sortDeque(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool    parseInput(int argc, char** argv);
    void    execute();
};

#endif