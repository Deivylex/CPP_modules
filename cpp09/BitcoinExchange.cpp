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
    size_t end = str.find(",");
    std::string date = str.substr(str.find_first_not_of(" \t"), end);
    std::regex regex("\\d{4}-\\d{2}-\\d{2}");
    if (!std::regex_match(date, regex))
        return ;
    std::string value;
    value = str.substr(end + 1, str.find_last_not_of(" \t") + 1);
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

void BitcoinExchange::setDataBase() 
{
    std::string str;
    std::ifstream file("data.csv");

    while(std::getline(file, str))
        checkSyntax(str);
}

bool BitcoinExchange::inputSyntaxCheck(std::string str)
{
    if (str.empty() || str == "Date | Value")
        return true;

    size_t sepPos = str.find("|");
    if (sepPos == std::string::npos)
        return false; // No hay separador "|"

    // 🔹 Extraer y limpiar la fecha
    std::string date = str.substr(0, sepPos);
    date.erase(0, date.find_first_not_of(" \t")); // Eliminar espacios iniciales
    date.erase(date.find_last_not_of(" \t") + 1); // Eliminar espacios finales

    // 🔹 Validar fecha con regex
    std::regex regexDate(R"(^\d{4}-\d{2}-\d{2}$)");
    if (!std::regex_match(date, regexDate))
        return false;

    // 🔹 Extraer y limpiar el valor
    std::string value = str.substr(sepPos + 1);
    value.erase(0, value.find_first_not_of(" \t")); // Eliminar espacios iniciales
    value.erase(value.find_last_not_of(" \t") + 1); // Eliminar espacios finales

    // 🔹 Validar número con regex
    std::regex regexFloat(R"(^[+-]?\d+(\.\d+)?$)");
    if (!std::regex_match(value, regexFloat))
        return false;

    // 🔹 Convertir a número y validar rango

        float val = std::stof(value);
        if (val < 0)
            throw std::runtime_error("Error: not a positive number.");
        if (val > 1000)
            throw std::runtime_error("Error: too large a number.");

    return true;
}

void BitcoinExchange::handleImput(std::string input) //arreglar eliminar espacion del comienzo y final
{
    std::string str;
    std::ifstream file(input);

    while(std::getline(file, str))
    {
        try
        {
      
            if (inputSyntaxCheck(str))
            {
                size_t end = str.find("|");
                // Extraer y limpiar la fecha
                std::string date = str.substr(0, end);
                date.erase(0, date.find_first_not_of(" \t")); // Eliminar espacios iniciales
                date.erase(date.find_last_not_of(" \t") + 1); // Eliminar espacios finales

                // Extraer y limpiar el valor
                std::string value = str.substr(end + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);
                if (dataBase.find(date) != dataBase.end())
                { 
                    float valuef = std::stof(value);  
                    float result = dataBase.find(date)->second * valuef;
                    std::cout << date << " => " << valuef << " = " << result <<"\n";
                }
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

void BitcoinExchange::printMap(){

    for (const auto& pair : dataBase)
    {
        std::cout << "date : " << pair.first << " valor: " << pair.second << "\n";
    }

}