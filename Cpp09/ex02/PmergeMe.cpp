#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
        this->_timeVec = other._timeVec;
        this->_timeDeq = other._timeDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) return false;

        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j]))
                return false;
        }

        long val = std::atol(arg.c_str());
        if (val < 0 || val > INT_MAX)
            return false;

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }
    return !_vec.empty();
}

std::vector<int> PmergeMe::_generateJacobsthal(size_t n) const {
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < static_cast<int>(n)) {
        int next = jacob.back() + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return jacob;
}

// Implémentation de Ford-Johnson sur std::vector
void PmergeMe::_sortVector(std::vector<int>& arr) {
    if (arr.size() <= 1)
        return;

    // 1. Former les paires et trouver min/max
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);

    for (size_t i = 0; i < arr.size() - (hasStraggler ? 1 : 0); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    if (hasStraggler)
        straggler = arr.back();

    // 2. Trier récursivement les grands éléments (Main Chain)
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    _sortVector(mainChain);

    // 3. Reconstruire la Pend Chain selon le tri de la Main Chain
    std::vector<int> pendChain;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pendChain.push_back(pairs[j].second);
                break;
            }
        }
    }

    // Le premier élément de pendChain va toujours au tout début
    if (!pendChain.empty())
        mainChain.insert(mainChain.begin(), pendChain[0]);

    // 4. Insertion dichotomique selon la séquence de Jacobsthal
    std::vector<int> jacob = _generateJacobsthal(pendChain.size());
    std::vector<bool> inserted(pendChain.size(), false);
    inserted[0] = true;

    for (size_t k = 2; k < jacob.size(); ++k) {
        int targetIndex = jacob[k];
        if (targetIndex >= static_cast<int>(pendChain.size()))
            targetIndex = pendChain.size() - 1;

        for (int j = targetIndex; j > jacob[k - 1]; --j) {
            if (j < static_cast<int>(pendChain.size()) && !inserted[j]) {
                int val = pendChain[j];
                std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
                mainChain.insert(it, val);
                inserted[j] = true;
            }
        }
    }

    // Insérer le straggler s'il existe
    if (hasStraggler) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

// Implémentation identique sur std::deque
void PmergeMe::_sortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = (arr.size() % 2 != 0);

    for (size_t i = 0; i < arr.size() - (hasStraggler ? 1 : 0); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    if (hasStraggler)
        straggler = arr.back();

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    _sortDeque(mainChain);

    std::deque<int> pendChain;
    for (size_t i = 0; i < mainChain.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pendChain.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pendChain.empty())
        mainChain.push_front(pendChain[0]);

    std::vector<int> jacob = _generateJacobsthal(pendChain.size());
    std::vector<bool> inserted(pendChain.size(), false);
    inserted[0] = true;

    for (size_t k = 2; k < jacob.size(); ++k) {
        int targetIndex = jacob[k];
        if (targetIndex >= static_cast<int>(pendChain.size()))
            targetIndex = pendChain.size() - 1;

        for (int j = targetIndex; j > jacob[k - 1]; --j) {
            if (j < static_cast<int>(pendChain.size()) && !inserted[j]) {
                int val = pendChain[j];
                std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
                mainChain.insert(it, val);
                inserted[j] = true;
            }
        }
    }

    if (hasStraggler) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);
    }

    arr = mainChain;
}

void PmergeMe::execute() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size() && i < 5; ++i)
        std::cout << _vec[i] << " ";
    if (_vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;

    // Benchmark Vector
    clock_t start = clock();
    _sortVector(_vec);
    clock_t end = clock();
    _timeVec = static_cast<double>(end - start) / CLOCKSPERSEC * 1000000.0;

    // Benchmark Deque
    start = clock();
    _sortDeque(_deq);
    end = clock();
    _timeDeq = static_cast<double>(end - start) / CLOCKSPERSEC * 1000000.0;

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size() && i < 5; ++i)
        std::cout << _vec[i] << " ";
    if (_vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << _timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(5)
              << _timeDeq << " us" << std::endl;
}