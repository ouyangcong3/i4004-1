#ifndef DEBUGGERLIST_H
#define DEBUGGERLIST_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QPainter>

#include <memory>
#include <vector>

#include "Simulator/debugger.h"
#include "Compiler/compiler.h"
#include "Simulator/simulator.h"

class DebuggerList : public QTableWidget
{
    Q_OBJECT
public:
    explicit DebuggerList(Compiler *compiler, Simulator* simulator);
    virtual ~DebuggerList();

    void selectAddress(unsigned addr);
    void deselectAll();

private:
    const unsigned columnNumbers = 4;

    std::vector<QTableWidgetItem*> items;
    Compiler* compiler;
    Simulator* simulator;

    void setCode(std::vector<unsigned> code);

signals:

public slots:

};

#endif // DEBUGGERLIST_H
