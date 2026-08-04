#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
    loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::_trim(std::string& str) const {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) {
        str.clear();
        return;
    }
    size_t last = str.find_last_not_of(" \t");
    str = str.substr(first, (last - first + 1));
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2000 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2 && isLeap)
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

void BitcoinExchange::loadDatabase(const std::string& dbPath) {
    std::ifstream file(dbPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t delim = line.find(',');
        if (delim != std::string::npos) {
            std::string date = line.substr(0, delim);
            float rate = std::atof(line.substr(delim + 1).c_str());
            _db[date] = rate;
        }
    }
    file.close();
}

bool BitcoinExchange::_isValidValue(const std::string& valStr, float& value) const {
    char* endptr;
    value = std::strtof(valStr.c_str(), &endptr);
    
    if (*endptr != '\0' && !std::isspace(*endptr)) {
        std::cout << "Error: bad input => " << valStr << std::endl;
        return false;
    }
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::processInput(const std::string& inputPath) const {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, delim);
        std::string valStr = line.substr(delim + 1);

        _trim(date);
        _trim(valStr);

        if (!_isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        float value;
        if (!_isValidValue(valStr, value))
            continue;

        std::map<std::string, float>::const_iterator it = _db.upper_bound(date);

        if (it != _db.begin()) {
            --it;
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        } else {
            std::cout << "Error: date too early => " << date << std::endl;
        }
    }
    file.close();
}