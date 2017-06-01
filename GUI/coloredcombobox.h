#ifndef COLOREDCOMBOBOX_H
#define COLOREDCOMBOBOX_H

#include <QComboBox>
#include <QObject>
#include <QStringList>

#include <memory>

class ColoredComboBox : public QComboBox
{
public:
    explicit ColoredComboBox();
    virtual ~ColoredComboBox();

};

#endif // COLOREDCOMBOBOX_H
