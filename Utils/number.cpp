#include "number.h"

std::regex Utils::Number::binPrefix = std::regex("(0b[01]+)|(0B[01]+)");
std::regex Utils::Number::binPostfix = std::regex("([01]+b)|([01]+B)");

std::regex Utils::Number::dec = std::regex("[0-9]+");

std::regex Utils::Number::hexPrefix = std::regex("(0x[0-f]+)|(0X[0-f]+)|(0x[0-F]+)|(0X[0-F]+)");
std::regex Utils::Number::hexPostfix = std::regex("([0-F]+H)|([0-f]+H)|([0-F]+h)|([0-f]+h)");

bool Utils::Number::isBin(const std::string& str)
{
    return regex_match(str, binPrefix) || regex_match(str, binPostfix);
}

bool Utils::Number::isDec(const std::string& str)
{
    return regex_match(str, dec);
}

bool Utils::Number::isHex(const std::string& str)
{
    return regex_match(str, hexPrefix) || regex_match(str, hexPostfix);
}

bool Utils::Number::isNumber(const std::string& str)
{
    return isBin(str) || isDec(str) || isHex(str);
}

unsigned int Utils::Number::getUInt(const std::string& str)
{
    if(regex_match(str, binPrefix))
    {
        std::string result = str.substr(2, str.size() - 2);
        return std::stoi(result, nullptr, 2);
    }
    else if (regex_match(str, binPostfix))
    {
        std::string result = str.substr(0, str.size() - 1);
        return std::stoi(result, nullptr, 2);
    }
    else if (regex_match(str, dec))
    {
        return std::stoi(str, nullptr, 10);
    }
    else if (regex_match(str, hexPrefix))
    {
        std::string result = str.substr(2, str.size()-2);
        return std::stoi(result, nullptr, 16);
    }
    else if (regex_match(str, hexPostfix))
    {
        std::string result = str.substr(0, str.size() - 1);
        return std::stoi(result, nullptr, 16);
    }
    else
    {
        std::string msg = "Number::Unknown type of a number " + str;
        throw msg;
    }

}
