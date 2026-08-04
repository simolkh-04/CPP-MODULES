#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _db;

    bool    _isValidDate(const std::string& date) const;
    bool    _isValidValue(const std::string& valStr, float& value) const;
    void    _trim(std::string& str) const;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbPath);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void    loadDatabase(const std::string& dbPath);
    void    processInput(const std::string& inputPath) const;
};

#endif