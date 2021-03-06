#include "dram.h"

int DRAM::getLength() const
{
    return length;
}

void DRAM::reset()
{
    for (int i = 0; i < length; i++)
    {
        std::shared_ptr<DataRAMBank> bank = getDataRAMBank(i);
        bank->reset();
    }
}

DRAM::DRAM(int bankNumber) : QObject(),
    length(bankNumber)
{
    for (int i = 0; i < length; i++)
    {
        std::shared_ptr<DataRAMBank> bank = std::shared_ptr<DataRAMBank>(new DataRAMBank(i));

        banks.push_back(bank);
    }
}

DRAM::~DRAM()
{
    // delete or finalize here something
}

std::shared_ptr<DataRAMBank> DRAM::getDataRAMBank(int index)
{
    if (index < 0 || index > length)
    {
        std::cerr << "Data RAM accessing error. " << index
                  << " is wrong index of a bank, because there are " << length << " banks." << std::endl;
        std::string msg = "Data RAM accessing error.";
        throw LogExceptions("DRam", msg);
    }

    return banks[index];
}
