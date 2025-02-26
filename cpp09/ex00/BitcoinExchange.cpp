#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dataBase(other.dataBase) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if( this != &other)
        dataBase = other.dataBase;
    return *this;
}

void BitcoinExchange::checkSyntax(std::string str)
{
    if (str.empty())
        return ;
    size_t sepPos = str.find(",");
    std::string date = str.substr(0, sepPos);
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    std::regex regex(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    if (!std::regex_match(date, regex))
        return ;
    std::string value;
    value = str.substr(sepPos + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);
    float val;
    try
    {
        val = std::stof(value);
    }
    catch(const std::exception& e)
    {
        return;
    }
    dataBase[date] = val;
}

void BitcoinExchange::setDataBase(std::string input) 
{
    std::string str;
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: the program does not have Database.");
    std::ifstream dataB(input);
    if (!dataB.is_open())
        throw std::runtime_error("Error: could not open file.");
    while(std::getline(file, str))
        checkSyntax(str);
}

bool BitcoinExchange::inputSyntaxCheck(std::string str)
{
    if (str.empty() || str == "Date | Value")
        return true;

    size_t sepPos = str.find("|");
    if (sepPos == std::string::npos)
        return false;

    std::string date = str.substr(0, sepPos);
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);

    std::regex regexDate(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    if (!std::regex_match(date, regexDate))
        return false;

    std::string value = str.substr(sepPos + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);

    std::regex regexFloat(R"(^[+-]?\d+(\.\d+)?$)");
    if (!std::regex_match(value, regexFloat))
        return false;
    if (!value.find("-"))
        throw std::runtime_error("Error: not a positive number.");
    float val;
    try
    {
        val = std::stof(value);
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error("Error: too large a number.");
    }
    if (val > 1000)
        throw std::runtime_error("Error: too large a number.");

    return true;
}

void BitcoinExchange::handleImput(std::string input)
{
    std::string str;
    std::ifstream file(input);

    while(std::getline(file, str))
    {
        if (str == "Date | Value" || str.empty())
            continue;
        try
        {
      
            if (inputSyntaxCheck(str))
            {
                size_t end = str.find("|");

                std::string date = str.substr(0, end);
                date.erase(0, date.find_first_not_of(" \t")); 
                date.erase(date.find_last_not_of(" \t") + 1);

                std::string value = str.substr(end + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);

                float valuef;
                float result;
                if (dataBase.find(date) != dataBase.end())
                { 
                    valuef = std::stof(value);  
                    result = dataBase.find(date)->second * valuef;
                }
                else
                {  
                    valuef = std::stof(value);
                    result =  getClosestValue(date) * valuef;
                }
                std::cout << date << " => " << std::stof(value) << " = " << result <<"\n";
            }
            else
            {
                std::cout << "Error: bad input => " << str << "\n";
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
float BitcoinExchange::getClosestValue(const std::string &date)
{
    auto it = dataBase.lower_bound(date);

    if (it != dataBase.end() && it->first == date)
        return it->second;

    if (it == dataBase.begin())
        return -1;

    --it;
    return it->second;
}
