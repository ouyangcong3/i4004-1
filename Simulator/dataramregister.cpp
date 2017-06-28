#include "dataramregister.h"

int DataRAMRegister::getCharactersLength() const
{
    return charactersLength;
}

int DataRAMRegister::getStatusLength() const
{
    return statusLength;
}

DataRAMRegister::DataRAMRegister(unsigned int bank, unsigned int chip, unsigned int reg) : QObject()
{
    this->bank = bank;
    this->chip = chip;
    this->reg = reg;

    for (int i = 0; i < charactersLength; i++) {
        characters.push_back(0);
    }

    for (int i = 0; i < statusLength; i++) {
        status.push_back(0);
    }
}

DataRAMRegister::~DataRAMRegister()
{
    // delete or finalize here something
}

void DataRAMRegister::setCharacter(int index, int value)
{
    if (index < 0 || index > charactersLength) {
        std::cerr << "A DataRAM Chip has got " << charactersLength << " registers. "
                  << index << " is bad index of a register." << std::endl;
        return;
    }

    if (value < 0 || value > 0xF) {
        std::cerr << "A DataRAM Register has got 4 bit characters, which can save [0x0 - 0xF] values. "
                  << value << " is bad value. It will reduce with a mask 0xF." << std::endl;
        value = value & 0xF;
    }

    characters[index] = value;

    emit onDramRegCharChanged(bank, chip, reg, index, value);
}

int DataRAMRegister::getCharacter(int index) const
{
    if (index < 0 || index > charactersLength)
    {
        std::cerr << "A DataRAM Chip has got " << charactersLength << " registers. "
                  << index << " is bad index of a register." << std::endl;
        throw "DataRAM chip access error, because of wrong index"; /// FIXME Exception
    }

    return characters[index];
}

void DataRAMRegister::setStatus(int index, int value)
{
    if (index < 0 || index > statusLength)
    {
        std::cerr << "A DataRAM Chip has got " << statusLength << " status registers. "
                  << index << " is bad index of a status register." << std::endl;
        return;
    }

    if (value < 0 || value > 0xF)
    {
        std::cerr << "A DataRAM Register has got 4 bit characters, wgich can save [0x0 - 0xF] values. "
                  << value << " is bad value. It will reduce with a mask 0xF." << std::endl;
        value = value & 0xF;
    }

    status[index] = value;

    emit onDramRegStatChanged(bank, chip, reg, index, value);
}

int DataRAMRegister::getStatus(int index) const
{
    if (index < 0 || index > statusLength)
    {
        std::cerr << "A DataRAM Chip has got " << statusLength << " status registers. "
                  << index << " is bad index of a register." << std::endl;
        throw "DataRAM chip access error, because of wrong index"; /// FIXME Exception
    }

    return status[index];
}
