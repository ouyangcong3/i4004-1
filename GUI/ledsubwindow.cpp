#include "ledsubwindow.h"

LEDSubWindow::LEDSubWindow(Simulator *simulator) : SubWindow()
{
    this->simulator = simulator;

    this->setWindowTitle("LED panel");
    this->setWindowIcon(QIcon(":/Resources/icons/led.png"));

    centralWidget = std::shared_ptr<QWidget>(new QWidget);
    layout = std::shared_ptr<QGridLayout>(new QGridLayout(centralWidget.get()));
    layout->setMargin(10);
    layout->setHorizontalSpacing(10);
    layout->setVerticalSpacing(0);

    this->setWidget(centralWidget.get());

    for (unsigned i = 0; i < ledNumber; i++)
    {
        Led* led = new Led(simulator);
        led->setConnection(ChooseIOWidget::IOType::ROM_IO, i / 4, 3 - i % 4);

        unsigned ledRow = i / ledColumns;

        layout->addWidget(led, ledRow, i % ledColumns);
        leds.push_back(led);
    }

//    QSizePolicy sp = this->sizePolicy();
//    sp.setHorizontalPolicy(QSizePolicy::Maximum);
//    sp.setVerticalPolicy(QSizePolicy::Maximum);
//    this->setSizePolicy(sp);

//    this->move(25, 25);

//    QString os = QSysInfo::kernelType();
//    if (os == "darwin")
//    {
//        this->move(1040, 5);
//    }
//    else
//    {
//        this->move(1200, 5);
//    }
}

LEDSubWindow::~LEDSubWindow()
{
    for (Led* led : leds)
    {
        delete (led);
    }
}

void LEDSubWindow::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        QWindowStateChangeEvent* ev = static_cast<QWindowStateChangeEvent*>(event);
        if (!(ev->oldState() & Qt::WindowMaximized) && windowState() & Qt::WindowMaximized)
        {
            this->setWindowState(Qt::WindowNoState);
        }
        else
        {
            QMdiSubWindow::changeEvent(event);
        }
    }
}
