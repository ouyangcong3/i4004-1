#include "number.h"

std::regex Number::binPrefix = std::regex("(0b[01]+)|(0B[01]+)");
std::regex Number::binPostfix = std::regex("([01]+b)|([01]+B)");

std::regex Number::dec = std::regex("[0-9]+");

std::regex Number::hexPrefix = std::regex("(0x[0-f]+)|(0X[0-f]+)|(0x[0-F]+)|(0X[0-F]+)");
std::regex Number::hexPostfix = std::regex("([0-F]+H)|([0-f]+H)|([0-F]+h)|([0-f]+h)");

bool Number::isBin(const std::string& str)
{
    return regex_match(str, binPrefix) || regex_match(str, binPostfix);
}

bool Number::isDec(const std::string& str)
{
    return regex_match(str, dec);
}

bool Number::isHex(const std::string& str)
{
    return regex_match(str, hexPrefix) || regex_match(str, hexPostfix);
}

bool Number::isNumber(const std::string& str)
{
    return isBin(str) || isDec(str) || isHex(str);
}

unsigned int Number::getUInt(const std::string& str)
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
        std::string msg = "Unknown type of a number " + str;
        throw CompilerException("Number", msg);
    }
}

std::string Number::replaceNumbersWithDec(const std::string& str)
{
    std::string result = str;

    SearchResult s = String::search(result, binPrefix);
    while(!s.find.empty())
    {
        result = String::replace(result, binPrefix, std::to_string(getUInt(s.find)));
        s = String::search(result, binPrefix);
    }

    s = String::search(result, binPostfix);
    while(!s.find.empty())
    {
        result = String::replace(result, binPostfix, std::to_string(getUInt(s.find)));
        s = String::search(result, binPostfix);
    }

    s = String::search(result, hexPrefix);
    while(!s.find.empty())
    {
        result = String::replace(result, hexPrefix, std::to_string(getUInt(s.find)));
        s = String::search(result, hexPrefix);
    }

    s = String::search(result, hexPostfix);
    while(!s.find.empty())
    {
        result = String::replace(result, hexPostfix, std::to_string(getUInt(s.find)));
        s = String::search(result, hexPostfix);
    }

    return result;
}
