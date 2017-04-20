#ifndef COMPILERN_H
#define COMPILERN_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <memory>

#include "Compiler/line.h"
#include "Exceptions/compilerexception.h"

class CompilerN
{
private:
    std::ifstream input;
    std::ofstream output;   /// TODO save a bin table somewhere or decide if I need this

    std::vector<std::string> lines;

public:
    CompilerN();

    void compile(const std::string& inputFilename);
    std::map<unsigned int, unsigned int> getObjectCode();
};

#endif // COMPILERN_H
