#include "label.h"

std::shared_ptr<Instruction> Label::getInstruction() const
{
    return instruction;
}

Label::Label(const std::string& name, unsigned int value)
{
    this->name = name;
    this->value = value;

    Constant::add(this->name, this->value);
}

Label::Label(const std::string& name, const std::string& param)
{
    this->name = name;

    if (param.empty())
    {
        this->value = ObjectCode::getProgramCounter();

        Constant::add(this->name, this->value);
        return;
    }

    SearchResult command = String::search(param, Compiler::commandRegex);
    if (!command.isEmpty() && CommandSet::isCommand(command.find))
    {
        Constant::add(this->name, ObjectCode::getProgramCounter());

        unsigned length = CommandSet::getLength(command.find);
        unsigned pc = ObjectCode::getProgramCounter();
        ObjectCode::setProgramCounter(pc + length);
    }
    else if (Number::isNumber(param))
    {
        this->value = Number::getUInt(param);
        Constant::add(this->name, this->value);
    }
    else if (Constant::isConstant(param))
    {
        this->value = Constant::getByName(param);
        Constant::add(this->name, this->value);
    }
    else if (MathExpr::isMathExpression(param))
    {
        this->value = MathExpr::evaluate(param);
        Constant::add(this->name, this->value);
    }
    else if (String::trimBeginEnd(param).compare("*") == 0)
    {
        this->value = ObjectCode::getProgramCounter();
        Constant::add(this->name, this->value);
    }
    else
    {
        std::string msg = "Wrong parameter " + param + " in label " + name;
        throw CompilerException("Label", msg);
    }
}

std::string Label::getName() const
{
    return name;
}

unsigned int Label::getValue() const
{
    return value;
}
