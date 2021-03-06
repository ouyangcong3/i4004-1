#include "mainwindow.h"

void MainWindow::createActions()
{
    // Actions File
    actNew = std::shared_ptr<QAction>(new QAction(tr("&New"), this));
    actNew->setIcon(QIcon(":/Resources/icons/new.png"));
    actNew->setShortcut(QKeySequence::New);
    connect(actNew.get(), &QAction::triggered, [=](){
        this->editorSubWindow->newFile();
    });

    actOpen = std::shared_ptr<QAction>(new QAction(tr("&Open"), this));
    actOpen->setIcon(QIcon(":/Resources/icons/open.png"));
    actOpen->setShortcut(QKeySequence::Open);
    connect(actOpen.get(), &QAction::triggered, this, [=](){
        this->editorSubWindow->openFile();
    });

    actSave = std::shared_ptr<QAction>(new QAction(tr("&Save"), this));
    actSave->setIcon(QIcon(":/Resources/icons/save.png"));
    actSave->setShortcut(QKeySequence::Save);
    connect(actSave.get(), &QAction::triggered, [=](){
        this->editorSubWindow->saveFile();
    });

    actSaveAs = std::shared_ptr<QAction>(new QAction(tr("Save As..."), this));
    actSaveAs->setIcon(QIcon(":/Resources/icons/saveas.png"));
    actSaveAs->setShortcut(QKeySequence::SaveAs);
    connect(actSaveAs.get(), &QAction::triggered, [=](){
        this->editorSubWindow->saveAsFile();
    });

    actExit = std::shared_ptr<QAction>(new QAction(tr("E&xit"), this));
    actExit->setIcon(QIcon(":/Resources/icons/exit.png"));
    actExit->setShortcut(tr("Ctrl+Q"));
    connect(actExit.get(), &QAction::triggered, [=](){
        QMainWindow::close();
    });

    // Actions Edit
    actUndo = std::shared_ptr<QAction>(new QAction(tr("Undo"), this));
    actUndo->setIcon(QIcon(":/Resources/icons/undo.png"));
    actUndo->setShortcut(QKeySequence::Undo);
    connect(actUndo.get(), &QAction::triggered, [=](){
        this->editorSubWindow->undoEdit();
    });

    actRedo = std::shared_ptr<QAction>(new QAction(tr("Redo"), this));
    actRedo->setIcon(QIcon(":/Resources/icons/redo.png"));
    actRedo->setShortcut(QKeySequence::Redo);
    connect(actRedo.get(), &QAction::triggered, [=](){
        this->editorSubWindow->redoEdit();
    });

    actCut = std::shared_ptr<QAction>(new QAction(tr("Cut"), this));
    actCut->setIcon(QIcon(":/Resources/icons/cut.png"));
    actCut->setShortcut(QKeySequence::Cut);
    connect(actCut.get(), &QAction::triggered, [=](){
        this->editorSubWindow->cutEdit();
    });

    actCopy = std::shared_ptr<QAction>(new QAction(tr("Copy"), this));
    actCopy->setIcon(QIcon(":/Resources/icons/copy.png"));
    actCopy->setShortcut(QKeySequence::Copy);
    connect(actCopy.get(), &QAction::triggered, [=](){
        this->editorSubWindow->copyEdit();
    });

    actPaste = std::shared_ptr<QAction>(new QAction(tr("Paste"), this));
    actPaste->setIcon(QIcon(":/Resources/icons/paste.png"));
    actPaste->setShortcut(QKeySequence::Paste);
    connect(actPaste.get(), &QAction::triggered, [=](){
        this->editorSubWindow->pasteEdit();
    });

    actDelete = std::shared_ptr<QAction>(new QAction(tr("Delete"), this));
    actDelete->setIcon(QIcon(":/Resources/icons/delete.png"));
    actDelete->setShortcut(QKeySequence::Delete);
    connect(actDelete.get(), &QAction::triggered, [=](){
        this->editorSubWindow->deleteEdit();
    });

    actSelectAll = std::shared_ptr<QAction>(new QAction(tr("Select All"), this));
    actSelectAll->setIcon(QIcon(":/Resources/icons/selectall.png"));
    actSelectAll->setShortcut(QKeySequence::SelectAll);
    connect(actSelectAll.get(), &QAction::triggered, [=](){
        this->editorSubWindow->selectAllEdit();
    });

    // Actions Build
    actCompile = std::shared_ptr<QAction>(new QAction(tr("Compile"), this));
    actCompile->setIcon(QIcon(":/Resources/icons/compile.png"));
    actCompile->setShortcut(tr("Ctrl+B"));

    connect(actCompile.get(), &QAction::triggered, [=](){
        buildCode();
    });

    // Actions Debug

    actionGroup = std::make_shared<QActionGroup>(this);

    actVerySlow = std::shared_ptr<QAction>(new QAction(tr("Very Slow"), this));
    actVerySlow->setCheckable(true);
    actionGroup->addAction(actVerySlow.get());
    connect(actVerySlow.get(), &QAction::triggered, [=](){
        simulator->setDelay(2000);
    });

    actSlow = std::shared_ptr<QAction>(new QAction(tr("Slow"), this));
    actSlow->setCheckable(true);
    actionGroup->addAction(actSlow.get());
    connect(actSlow.get(), &QAction::triggered, [=](){
        simulator->setDelay(1000);
    });

    actNormal = std::shared_ptr<QAction>(new QAction(tr("Normal"), this));
    actNormal->setCheckable(true);
    actNormal->setChecked(true);
    actionGroup->addAction(actNormal.get());
    connect(actNormal.get(), &QAction::triggered, [=](){
        simulator->setDelay(50);
    });

    actFast = std::shared_ptr<QAction>(new QAction(tr("Fast"), this));
    actFast->setCheckable(true);
    actionGroup->addAction(actFast.get());
    connect(actFast.get(), &QAction::triggered, [=](){
        simulator->setDelay(25);
    });

    actVeryFast = std::shared_ptr<QAction>(new QAction(tr("Very Fast"), this));
    actVeryFast->setCheckable(true);
    actionGroup->addAction(actVeryFast.get());
    connect(actVeryFast.get(), &QAction::triggered, [=](){
        simulator->setDelay(10);
    });

    actPlay = std::shared_ptr<QAction>(new QAction(tr("Play"), this));
    actPlay->setIcon(QIcon(":/Resources/icons/debug_resume.png"));
    actPlay->setShortcut(tr("F5"));
    connect(actPlay.get(), &QAction::triggered, [=](){
        simulator->play();
    });

    actStep = std::shared_ptr<QAction>(new QAction(tr("Step"), this));
    actStep->setIcon(QIcon(":/Resources/icons/debug_step_over.png"));
    actStep->setShortcut(tr("F10"));
    connect(actStep.get(), &QAction::triggered, [=](){
        simulator->step();
    });

    actStop = std::shared_ptr<QAction>(new QAction(tr("Stop"), this));
    actStop->setIcon(QIcon(":/Resources/icons/debug_stop.png"));
    actStop->setShortcut(tr("Escape"));
    connect(actStop.get(), &QAction::triggered, [=](){
        simulator->stop();
    });

    actReset = std::shared_ptr<QAction>(new QAction(tr("Reset"), this));
    actReset->setIcon(QIcon(":/Resources/icons/debug_restart.png"));
    actReset->setShortcut(tr("Ctrl+Backspace"));
    connect(actReset.get(), &QAction::triggered, [=](){
        simulator->reset();
    });
}

void MainWindow::createMenu()
{
    // Create main menu
    mainMenu = std::shared_ptr<QMenuBar>(new QMenuBar);
    this->setMenuBar(mainMenu.get());

    // Create menu File
    menuFile = std::shared_ptr<QMenu>(mainMenu->addMenu("File"));
    menuFile->addAction(actNew.get());
    menuFile->addAction(actOpen.get());
    menuFile->addSeparator();
    menuFile->addAction(actSave.get());
    menuFile->addAction(actSaveAs.get());
    menuFile->addSeparator();
    menuFile->addAction(actExit.get());

    // Create menu Edit
    menuEdit = std::shared_ptr<QMenu>(mainMenu->addMenu("Edit"));
    menuEdit->addAction(actUndo.get());
    menuEdit->addAction(actRedo.get());
    menuEdit->addSeparator();
    menuEdit->addAction(actCut.get());
    menuEdit->addAction(actCopy.get());
    menuEdit->addAction(actPaste.get());
    menuEdit->addAction(actDelete.get());
    menuEdit->addSeparator();
    menuEdit->addAction(actSelectAll.get());

    // Create menu Build
    menuBuild = std::shared_ptr<QMenu>(mainMenu->addMenu("Build"));
    menuBuild->addAction(actCompile.get());
    menuBuild->addSeparator();
    speedMenu = std::make_shared<QMenu>("Play speed");
    menuBuild->addMenu(speedMenu.get());

    speedMenu->addAction(actVerySlow.get());
    speedMenu->addAction(actSlow.get());
    speedMenu->addAction(actNormal.get());
    speedMenu->addAction(actFast.get());
    speedMenu->addAction(actVeryFast.get());

    menuBuild->addAction(actPlay.get());
    menuBuild->addAction(actStop.get());
    menuBuild->addAction(actStep.get());
    menuBuild->addAction(actReset.get());

    // Create menu Windows
    menuWindows = std::shared_ptr<QMenu>(mainMenu->addMenu("Windows"));
    nextWindow = std::shared_ptr<QAction>(new QAction("Next window", this));
    nextWindow->setShortcut(tr("Ctrl+]"));
    connect(nextWindow.get(), SIGNAL(triggered(bool)), mdi.get(), SLOT(activateNextSubWindow()));
    menuWindows->addAction(nextWindow.get());

    prevWindow = std::shared_ptr<QAction>(new QAction("Previous window", this));
    prevWindow->setShortcut(tr("Ctrl+["));
    connect(prevWindow.get(), SIGNAL(triggered(bool)), mdi.get(), SLOT(activatePreviousSubWindow()));
    menuWindows->addAction(prevWindow.get());

    menuWindows->addSeparator();

    for(int i = 0; i < mdi->subWindowList().length(); i++)
    {
        QMdiSubWindow* w = mdi->subWindowList().at(i);

        QAction* act = new QAction(w->windowTitle(), this);

        QIcon ico = w->windowIcon();
        act->setIcon(ico);
        if (i < 9)
        {
            std::string shortcut = QString("Ctrl+"+ QString::number(i+1)).toStdString();
            act->setShortcut(tr(shortcut.c_str()));
        }

        listWindowsMenuBtn.push_back(act);
        connect(act, SIGNAL(triggered(bool)), w, SLOT(show()));
        connect(act, SIGNAL(triggered(bool)), w, SLOT(setFocus()));
        menuWindows->addAction(act);
    }

    menuWindows->addSeparator();

    minimizeAll = std::shared_ptr<QAction>(new QAction("Minimize all", this));
    minimizeAll->setShortcut(tr("Ctrl+M"));
    for(QMdiSubWindow* w : mdi->subWindowList())
    {
        connect(minimizeAll.get(), SIGNAL(triggered(bool)), w, SLOT(showMinimized()));
    }
    menuWindows->addAction(minimizeAll.get());

    showWindows = std::shared_ptr<QAction>(new QAction("Show windows", this));
    showWindows->setShortcut(tr("Ctrl+Shift+M"));
    for(QMdiSubWindow* w : mdi->subWindowList())
    {
        connect(showWindows.get(), SIGNAL(triggered(bool)), w, SLOT(showNormal()));
    }
    menuWindows->addAction(showWindows.get());
}

void MainWindow::createToolbars()
{
    toolBarMinimize = std::shared_ptr<QToolBar>(new QToolBar("Minimize"));
    for(QMdiSubWindow* w : mdi->subWindowList())
    {
        QIcon ico = w->windowIcon();
        QString title = w->windowTitle();

        QAction* act = new QAction(ico, title, this);
        listWindowsToolbarBtn.push_back(act);
        act->setToolTip("Show " + title);

        connect(act, SIGNAL(triggered(bool)), w, SLOT(show()));
        connect(act, SIGNAL(triggered(bool)), w, SLOT(setFocus()));

        toolBarMinimize->addAction(act);
    }

    toolBarMinimize->setFloatable(false);
    toolBarMinimize->setMovable(false);

    toolBarFile = std::shared_ptr<QToolBar>(new QToolBar("File"));
    toolBarFile->addAction(actNew.get());
    toolBarFile->addAction(actOpen.get());
    toolBarFile->addAction(actSave.get());

    toolBarEdit = std::shared_ptr<QToolBar>(new QToolBar("Edit"));
    toolBarEdit->addAction(actUndo.get());
    toolBarEdit->addAction(actRedo.get());
    toolBarEdit->addSeparator();
    toolBarEdit->addAction(actCut.get());
    toolBarEdit->addAction(actCopy.get());
    toolBarEdit->addAction(actPaste.get());
    toolBarEdit->addAction(actDelete.get());
    toolBarEdit->addSeparator();
    toolBarEdit->addAction(actSelectAll.get());

    toolBarBuild = std::shared_ptr<QToolBar>(new QToolBar("Build"));
    toolBarBuild->addAction(actCompile.get());
    toolBarBuild->addSeparator();
    toolBarBuild->addAction(actPlay.get());
    toolBarBuild->addAction(actStop.get());
    toolBarBuild->addAction(actStep.get());
    toolBarBuild->addAction(actReset.get());

    this->addToolBar(toolBarFile.get());
    this->addToolBar(toolBarEdit.get());
    this->addToolBar(toolBarBuild.get());
    this->addToolBar(Qt::LeftToolBarArea, toolBarMinimize.get());
}

void MainWindow::createSubWindows()
{
    editorSubWindow = std::shared_ptr<EditorSubWindow>(new EditorSubWindow(mdi.get()));
    mdi->addSubWindow(editorSubWindow.get(), Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    debuggerSubWindow = std::shared_ptr<DebuggerSubWindow>(new DebuggerSubWindow(mdi.get(), compiler, simulator));
    mdi->addSubWindow(debuggerSubWindow.get(), Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    ledSubWindow = std::shared_ptr<LEDSubWindow>(new LEDSubWindow(mdi.get(), simulator));
    mdi->addSubWindow(ledSubWindow.get(), Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    buttonSubWindow = std::shared_ptr<ButtonSubWindow>(new ButtonSubWindow(mdi.get(), simulator));
    mdi->addSubWindow(buttonSubWindow.get(), Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    mdi->setActiveSubWindow(editorSubWindow.get()); // Editor window is activated (focused) by default

    debuggerSubWindow->setWindowState(Qt::WindowMinimized);
    ledSubWindow->setWindowState(Qt::WindowMinimized);
    buttonSubWindow->setWindowState(Qt::WindowMinimized);
}

void MainWindow::createDocks()
{
    this->setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    this->setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);

    this->setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    this->setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    dockResult = std::shared_ptr<QDockWidget>(new QDockWidget("Output"));
    dockResult->setFeatures(QDockWidget::NoDockWidgetFeatures);
    lstResult = std::shared_ptr<QListWidget>(new QListWidget);
    dockResult->setWidget(lstResult.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockResult.get());
    dockResult->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    dockDRam = std::shared_ptr<QDockWidget>(new QDockWidget("Data RAM"));
    dockDRam->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dramWidget = std::shared_ptr<DataRamWidget>(new DataRamWidget(simulator));
    dockDRam->setWidget(dramWidget.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockDRam.get());
    dockDRam->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    dockRom = std::shared_ptr<QDockWidget>(new QDockWidget("ROM"));
    dockRom->setFeatures(QDockWidget::NoDockWidgetFeatures);
    romWidget = std::shared_ptr<RomWidget>(new RomWidget(simulator));
    dockRom->setWidget(romWidget.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockRom.get());
    dockRom->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    this->tabifyDockWidget(dockResult.get(), dockRom.get());
    this->tabifyDockWidget(dockRom.get(), dockDRam.get());
    this->dockResult->raise();


    dockCpuWidget = std::shared_ptr<QDockWidget>(new QDockWidget("CPU"));
    dockCpuWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    cpuWidget = std::shared_ptr<CpuWidget>(new CpuWidget(simulator));
    dockCpuWidget->setWidget(cpuWidget.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockCpuWidget.get());

    connect(compiler, SIGNAL(onCompiled()), this, SLOT(handleCompiled()));
}

MainWindow::MainWindow(Compiler& compiler, Simulator &simulator, QWidget *parent)
    : QMainWindow(parent)
{
    this->compiler = &compiler;
    this->simulator = &simulator;

    this->setWindowState(Qt::WindowMaximized);

    // create components
    mdi = std::shared_ptr<QMdiArea>(new QMdiArea);
//    mdi->tileSubWindows();
//    mdi->cascadeSubWindows();

    mdi->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdi->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    createActions();
    createDocks();
    createSubWindows();
    createToolbars();
    createMenu();

    statusLabel = std::shared_ptr<QLabel>(new QLabel("Line: 1\t"));
    statusBar = std::shared_ptr<QStatusBar>(new QStatusBar);
    statusBar->setStyleSheet("background-color: lightgray");
    statusBar->addPermanentWidget(statusLabel.get());


    // set widgets
    this->setCentralWidget(mdi.get());
    this->setStatusBar(statusBar.get());

    connect(this->compiler, SIGNAL(onCompiled()), this, SLOT(handleBuildCode()));

    connect(this->compiler, SIGNAL(onCompiledError()), this, SLOT(handleCompiledError()));

    connect(this->simulator, SIGNAL(onEvalCommand(QString)), this, SLOT(handleEvalCommand(const QString&)));

    connect(editorSubWindow.get(), SIGNAL(onCursorPosChanged(unsigned)), this, SLOT(handleCursorPosChanged(unsigned)));
}

MainWindow::~MainWindow()
{
    for (QAction* a : listWindowsMenuBtn)
    {
        delete(a);
    }

    for (QAction* a : listWindowsToolbarBtn)
    {
        delete(a);
    }
}

void MainWindow::createOutputFilename()
{
    outputname = filename;
    outputname = outputname.split(".").first();
    outputname.append(".bin");
}

void MainWindow::buildCode()
{
    this->editorSubWindow->saveFile();

    this->actCompile->setDisabled(true);
    simulator->stop();
    simulator->reset();

    lstResult->clear();

    filename = this->editorSubWindow->getFilename();

    QtConcurrent::run([=](){
       compiler->compile(filename.toStdString());
    });
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    bool isPlaying = this->simulator->getIsPlaying();
    this->simulator->stop();

    QString msg = tr("Please, don't forget to save your changes.\n\nDo you want to exit?");
    QMessageBox::StandardButton btn = QMessageBox::question(this, tr("Exit"), msg);
    if (btn == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
        if (isPlaying)
        {
            this->simulator->play();
        }
    }
}

void MainWindow::handleCompiledError()
{
    this->actCompile->setDisabled(false);
}

void MainWindow::handleBuildCode()
{
    std::vector<std::shared_ptr<CompilerError>> errors = this->compiler->getErrors();

    if (errors.empty())
    {
        lstResult->addItem(QString(tr("Compiled successfully")));
    }
    else
    {
        for (const std::shared_ptr<CompilerError> e : errors)
        {
            QString msg;
            msg.append("Line ").append(QString::number(e->row));
            msg.append(": ")
                    .append(QString(e->message.c_str()));
            lstResult->addItem(msg);
        }
    }

    this->actCompile->setDisabled(false);

    return;
}

void MainWindow::handleCompiled()
{
    dockResult->raise();

    if (compiler->getErrors().empty())
    {
        this->actPlay->setEnabled(true);
        this->actStep->setEnabled(true);
    }
    else
    {
        this->actPlay->setEnabled(false);
        this->actStep->setEnabled(false);
    }
}

void MainWindow::handleCursorPosChanged(unsigned line)
{
    statusLabel->setText("Line: " + QString::number(line) + "\t");
}

void MainWindow::handleEvalCommand(const QString &msg)
{
    this->lstResult->addItem(msg);
}
