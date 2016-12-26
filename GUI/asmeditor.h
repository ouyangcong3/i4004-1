#ifndef ASMEDITOR_H
#define ASMEDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QPainter>
#include <QPaintEngine>
#include <QPlainTextEdit>
#include <QTextBlock>
#include <QList>
#include <QMouseEvent>
#include <QScrollBar>

#include <iostream>

using namespace std;

class AsmEditor : public QTextEdit
{
    Q_OBJECT
private:

public:
    explicit AsmEditor(QWidget *parent = 0);

signals:

public slots:


    // QWidget interface
protected:
    void paintEvent(QPaintEvent* e) Q_DECL_OVERRIDE;


};


#endif // ASMEDITOR_H