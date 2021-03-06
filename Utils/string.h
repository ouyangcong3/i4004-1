#ifndef STRING_H
#define STRING_H

#include <sstream>
#include <string>
#include <regex>
#include <vector>

#include "Utils/searchresult.h"

class String
{
public:
    static std::string trimStrong(const std::string& str); // Delete all whitespaces from string
    static std::string trim(const std::string& str); // It will left only 1 whitespace

    // divide string by divider to vector of strings
    static std::vector<std::string> divideBy(const std::string& str, const std::string& divider);

    /*
     * Find a first matching of a substring in a string "where" by a pattern.
     * Returns search_result, which consider "prefix", "find" and "suffix".
     *
     * So f.e. we have got a string "I love bananas".
     * And we find by a pattern "na".
     * In this case the prefix is "I love ba",
     * the find is "na",
     * and the suffix is "nas".
     */
    static SearchResult search(const std::string& where, std::regex pattern);

    static std::string replace(const std::string& where, std::regex what, const std::string& with);

    static std::string trimBeginEnd(const std::string& str);

    static std::string int2hex_string(int dec);
};


#endif // STRING_H
