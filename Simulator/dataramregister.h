#ifndef DATARAMREGISTER_H
#define DATARAMREGISTER_H

#include <QObject>

#include <vector>
#include <iostream>

class DataRAMRegister : public QObject
{
    Q_OBJECT
private:
    std::vector<int> characters;
    std::vector<int> status;

    const int charactersLength = 16;
    const int statusLength = 4;

public:
    DataRAMRegister();
    virtual ~DataRAMRegister();

    void setCharacter(int index, int value);
    int getCharacter(int index) const;

    void setStatus(int index, int value);
    int getStatus(int index) const;

signals:
    void onDramRegisterChanged();

};

#endif // DATARAMREGISTER_H
