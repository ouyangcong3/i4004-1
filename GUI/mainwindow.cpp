#include "mainwindow.h"

void MainWindow::createActions()
{
    // Actions File
    actNew = std::shared_ptr<QAction>(new QAction(tr("&New"), this));
    actNew->setIcon(QIcon(":/Resources/icons/new.png"));
    actNew->setShortcut(QKeySequence::New);
    connect(actNew.get(), SIGNAL(triggered(bool)), this, SLOT(newFile()));

    actOpen = std::shared_ptr<QAction>(new QAction(tr("&Open"), this));
    actOpen->setIcon(QIcon(":/Resources/icons/open.png"));
    actOpen->setShortcut(QKeySequence::Open);
    connect(actOpen.get(), SIGNAL(triggered(bool)), this, SLOT(openFile()));

    actSave = std::shared_ptr<QAction>(new QAction(tr("&Save"), this));
    actSave->setIcon(QIcon(":/Resources/icons/save.png"));
    actSave->setShortcut(QKeySequence::Save);
    connect(actSave.get(), SIGNAL(triggered(bool)), this, SLOT(saveFile()));

    actSaveAs = std::shared_ptr<QAction>(new QAction(tr("Save As..."), this));
    actSaveAs->setIcon(QIcon(":/Resources/icons/saveas.png"));
    actSaveAs->setShortcut(QKeySequence::SaveAs);
    connect(actSaveAs.get(), SIGNAL(triggered(bool)), this, SLOT(saveAsFile()));

    actExit = std::shared_ptr<QAction>(new QAction(tr("E&xit"), this));
    actExit->setIcon(QIcon(":/Resources/icons/exit.png"));
    actExit->setShortcut(tr("Ctrl+Q"));
    connect(actExit.get(), SIGNAL(triggered(bool)), this, SLOT(exitFile()));

    // Actions Edit
    actUndo = std::shared_ptr<QAction>(new QAction(tr("Undo"), this));
    actUndo->setIcon(QIcon(":/Resources/icons/undo.png"));
    actUndo->setShortcut(QKeySequence::Undo);
    connect(actUndo.get(), SIGNAL(triggered(bool)), this, SLOT(undoEdit()));

    actRedo = std::shared_ptr<QAction>(new QAction(tr("Redo"), this));
    actRedo->setIcon(QIcon(":/Resources/icons/redo.png"));
    actRedo->setShortcut(QKeySequence::Redo);
    connect(actRedo.get(), SIGNAL(triggered(bool)), this, SLOT(redoEdit()));

    actCut = std::shared_ptr<QAction>(new QAction(tr("Cut"), this));
    actCut->setIcon(QIcon(":/Resources/icons/cut.png"));
    actCut->setShortcut(QKeySequence::Cut);
    connect(actCut.get(), SIGNAL(triggered(bool)), this, SLOT(cutEdit()));

    actCopy = std::shared_ptr<QAction>(new QAction(tr("Copy"), this));
    actCopy->setIcon(QIcon(":/Resources/icons/copy.png"));
    actCopy->setShortcut(QKeySequence::Copy);
    connect(actCopy.get(), SIGNAL(triggered(bool)), this, SLOT(copyEdit()));

    actPaste = std::shared_ptr<QAction>(new QAction(tr("Paste"), this));
    actPaste->setIcon(QIcon(":/Resources/icons/paste.png"));
    actPaste->setShortcut(QKeySequence::Paste);
    connect(actPaste.get(), SIGNAL(triggered(bool)), this, SLOT(pasteEdit()));

    actDelete = std::shared_ptr<QAction>(new QAction(tr("Delete"), this));
    actDelete->setIcon(QIcon(":/Resources/icons/delete.png"));
    actDelete->setShortcut(QKeySequence::Delete);
    connect(actDelete.get(), SIGNAL(triggered(bool)), this, SLOT(deleteEdit()));

    actSelectAll = std::shared_ptr<QAction>(new QAction(tr("Select All"), this));
    actSelectAll->setIcon(QIcon(":/Resources/icons/selectall.png"));
    actSelectAll->setShortcut(QKeySequence::SelectAll);
    connect(actSelectAll.get(), SIGNAL(triggered(bool)), this, SLOT(selectAllEdit()));

    // Actions Build
    actCompile = std::shared_ptr<QAction>(new QAction(tr("Compile"), this));
    actCompile->setIcon(QIcon(":/Resources/icons/compile.png"));
    actCompile->setShortcut(tr("Ctrl+B"));
    actCompile->setDisabled(true);
    connect(actCompile.get(), SIGNAL(triggered(bool)), this, SLOT(compileBuild()));

    actRun = std::shared_ptr<QAction>(new QAction(tr("Run"), this));
    actRun->setIcon(QIcon(":/Resources/icons/run.png"));
    actRun->setShortcut(tr("F5"));
    actRun->setDisabled(true);
    connect(actRun.get(), SIGNAL(triggered(bool)), this, SLOT(runBuild()));

    actCompileRun = std::shared_ptr<QAction>(new QAction(tr("Compile and Run"), this));
    actCompileRun->setIcon(QIcon(":/Resources/icons/compile_run.png"));
    actCompileRun->setShortcut(tr("Ctrl+R"));
    actCompileRun->setDisabled(true);
    connect(actCompileRun.get(), SIGNAL(triggered(bool)), this, SLOT(compileRunBuild()));

    // Actions Debug
    actResume = std::shared_ptr<QAction>(new QAction(tr("Resume"), this));
    actResume->setIcon(QIcon(":/Resources/icons/debug_resume.png"));
    actResume->setShortcut(tr("F8"));
    connect(actResume.get(), SIGNAL(triggered(bool)), this, SLOT(debugResume()));

    actStep = std::shared_ptr<QAction>(new QAction(tr("Step"), this));
    actStep->setIcon(QIcon(":/Resources/icons/debug_step_over.png"));
    actStep->setShortcut(tr("F10"));
    connect(actStep.get(), SIGNAL(triggered(bool)), this, SLOT(debugStep()));

    actStop = std::shared_ptr<QAction>(new QAction(tr("Stop"), this));
    actStop->setIcon(QIcon(":/Resources/icons/debug_stop.png"));
    connect(actStop.get(), SIGNAL(triggered(bool)), this, SLOT(debugStop()));

    actReset = std::shared_ptr<QAction>(new QAction(tr("Reset"), this));
    actReset->setIcon(QIcon(":/Resources/icons/debug_restart.png"));
    connect(actReset.get(), SIGNAL(triggered(bool)), this, SLOT(debugReset()));
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
    menuBuild->addAction(actRun.get());
    menuBuild->addSeparator();
    menuBuild->addAction(actCompileRun.get());

    // Create menu Preferences
    mainMenu->addMenu("Preferences");

    // Create menu Windows
    menuWindows = std::shared_ptr<QMenu>(mainMenu->addMenu("Windows"));
    nextWindow = std::shared_ptr<QAction>(new QAction("Next window", this));
    connect(nextWindow.get(), SIGNAL(triggered(bool)), mdi.get(), SLOT(activateNextSubWindow()));
    menuWindows->addAction(nextWindow.get());

    prevWindow = std::shared_ptr<QAction>(new QAction("Previous window", this));
    connect(prevWindow.get(), SIGNAL(triggered(bool)), mdi.get(), SLOT(activatePreviousSubWindow()));
    menuWindows->addAction(prevWindow.get());

    menuWindows->addSeparator();

    for(QMdiSubWindow* w : mdi->subWindowList())
    {
        QAction* act = new QAction(w->windowTitle(), this);
        listWindowsMenuBtn.push_back(act);
        connect(act, SIGNAL(triggered(bool)), w, SLOT(show()));
        connect(act, SIGNAL(triggered(bool)), w, SLOT(setFocus()));
        menuWindows->addAction(act);
    }

    menuWindows->addSeparator();

    minimizeAll = std::shared_ptr<QAction>(new QAction("Minimize all", this));
    for(QMdiSubWindow* w : mdi->subWindowList())
    {
        connect(minimizeAll.get(), SIGNAL(triggered(bool)), w, SLOT(showMinimized()));
    }
    menuWindows->addAction(minimizeAll.get());

    showWindows = std::shared_ptr<QAction>(new QAction("Show windows", this));
    for(QMdiSubWindow* w : mdi->subWindowList())
    {
        connect(showWindows.get(), SIGNAL(triggered(bool)), w, SLOT(showNormal()));
    }
    connect(showWindows.get(), SIGNAL(triggered(bool)), mdi.get(), SLOT(tileSubWindows()));

    menuWindows->addAction(showWindows.get());

    // Create menu Help
    mainMenu->addMenu("Help");
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
    toolBarBuild->addAction(actRun.get());
    toolBarBuild->addAction(actCompileRun.get());

    toolBarDebug = std::shared_ptr<QToolBar>(new QToolBar("Debug"));
    toolBarDebug->addAction(actResume.get());
    toolBarDebug->addAction(actStop.get());
    toolBarDebug->addAction(actStep.get());
    toolBarDebug->addAction(actReset.get());

    this->addToolBar(toolBarFile.get());
    this->addToolBar(toolBarEdit.get());
    this->addToolBar(toolBarBuild.get());
    this->addToolBar(toolBarDebug.get());
    this->addToolBar(Qt::LeftToolBarArea, toolBarMinimize.get());
}

void MainWindow::createSubWindows()
{
//    editor = new AsmEditor; /// TODO Provide safe delete of this pointer and AsmEditor class at all

    editorSubWindow = std::shared_ptr<EditorSubWindow>(new EditorSubWindow);
    ledSubWindow = std::shared_ptr<LEDSubWindow>(new LEDSubWindow);
//    sevenSegmentSubWindow = std::shared_ptr<SevenSegmentSubWindow>(new SevenSegmentSubWindow);
    buttonSubWindow = std::shared_ptr<ButtonSubWindow>(new ButtonSubWindow);

    mdi->addSubWindow(editorSubWindow.get());
    mdi->addSubWindow(ledSubWindow.get());
//    mdi->addSubWindow(sevenSegmentSubWindow.get());
    mdi->addSubWindow(buttonSubWindow.get());
}

void MainWindow::createDocks()
{
    this->setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    this->setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);

    this->setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    this->setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    dockResult = std::shared_ptr<QDockWidget>(new QDockWidget("Compile Output"));
    lstResult = std::shared_ptr<QListWidget>(new QListWidget);
    dockResult->setWidget(lstResult.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockResult.get());

    dockDRam = std::shared_ptr<QDockWidget>(new QDockWidget("Data RAM"));
    dramWidget = std::shared_ptr<DataRamWidget>(new DataRamWidget);
    dockDRam->setWidget(dramWidget.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockDRam.get());

    dockRom = std::shared_ptr<QDockWidget>(new QDockWidget("ROM"));
    romWidget = std::shared_ptr<RomWidget>(new RomWidget);
    dockRom->setWidget(romWidget.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockRom.get());

    dockPRam = std::shared_ptr<QDockWidget>(new QDockWidget("Program RAM"));
    pramWidget = std::shared_ptr<ProgramRamWidget>(new ProgramRamWidget);
    dockPRam->setWidget(pramWidget.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockPRam.get());

    this->tabifyDockWidget(dockResult.get(), dockDRam.get());
    this->tabifyDockWidget(dockDRam.get(), dockRom.get());
    this->tabifyDockWidget(dockRom.get(), dockPRam.get());

    dockCpuWidget = std::shared_ptr<QDockWidget>(new QDockWidget("CPU"));
    cpuWidget = std::shared_ptr<CpuWidget>(new CpuWidget);
    dockCpuWidget->setWidget(cpuWidget.get());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockCpuWidget.get());

    QSizePolicy sizePolicy = dockCpuWidget->sizePolicy();
    sizePolicy.setHorizontalPolicy(QSizePolicy::Maximum);
    dockCpuWidget->setSizePolicy(sizePolicy);

    sizePolicy = dockResult->sizePolicy();
    sizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    dockResult->setSizePolicy(sizePolicy);

    sizePolicy = dockDRam->sizePolicy();
    sizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    dockDRam->setSizePolicy(sizePolicy);

    sizePolicy = dockRom->sizePolicy();
    sizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    dockRom->setSizePolicy(sizePolicy);

    sizePolicy = dockPRam->sizePolicy();
    sizePolicy.setHorizontalPolicy(QSizePolicy::Minimum);
    dockPRam->setSizePolicy(sizePolicy);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);

    // create components
    mdi = std::shared_ptr<QMdiArea>(new QMdiArea);
//    mdi->tileSubWindows();
    mdi->cascadeSubWindows();

    mdi->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdi->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    createActions();
    createDocks();
    createSubWindows();
    createToolbars();
    createMenu();

    statusBar = std::shared_ptr<QStatusBar>(new QStatusBar);

    // set widgets
    this->setCentralWidget(mdi.get());
    this->setStatusBar(statusBar.get());

    // form settings
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->setFocus();
//    setWindowTitleFilename();
//    this->resize(960, 640);

//    // connects
//    connect(textEditor, SIGNAL(textChanged()), this, SLOT(setWindowTitleFilename()));
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
    //    outputname = filename.split("/").last();
    outputname = filename;
    outputname = outputname.split(".").first();
    outputname.append(".bin");
}

void MainWindow::setWindowTitleFilename()
{
    QString title = "Intel4004";
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();

//    if (textEditor->document()->isModified())
//    {
//        title = "*Intel4004";
//    }
//    else
//    {
//        title = "Intel4004";
//    }
//    if (!filename.isEmpty())
//    {
//        title.append(" - [").append(filename).append("]");
//    }
    this->setWindowTitle(title);
}


void MainWindow::readFile()
{
    file.open(filename.toStdString(), ios::in);

    if(file.is_open())
    {
        string line;
        QString doc;

        bool firstLine = true;

        while(getline(file, line))
        {
            if(firstLine)
            {
                firstLine = false;
            }
            else
            {
                doc.append("\n");
            }
            doc.append(line.c_str());
        }

        file.close();
//        QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//        textEditor->setPlainText(doc);
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Can't open file ").append(filename));
    }
}

void MainWindow::writeFile()
{
    file.open(filename.toStdString(), ios::out | ios::trunc);

    if (file.is_open())
    {
//        QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//        QStringList lines = textEditor->toPlainText().split("\n");

//        for (QString l : lines)
//        {
//            file << l.toStdString() << "\n";
//        }

        file.close();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Can't save to file ").append(filename));
    }
}


void MainWindow::newFile()
{
    QMessageBox::StandardButton btn = QMessageBox::question(this, tr("New file"), tr("Do you want to start a new file?"));
    if (btn == QMessageBox::Yes)
    {
        this->editorSubWindow->clearEditor();
        this->filename.clear();

        setWindowTitleFilename();

//        actCompile->setDisabled(true);
//        actRun->setDisabled(true);
//        actCompileRun->setDisabled(true);
    }
}

void MainWindow::openFile()
{
    QFileDialog openDlg;
    openDlg.setAcceptMode(QFileDialog::AcceptOpen);

    QString filename = openDlg.getOpenFileName(this, tr("Open File"), "", "Intel4004 assembler (*.asm);;All files (*.*)");
    if (!filename.isEmpty())
    {
        this->filename = filename;
        createOutputFilename();
        readFile();

//        QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//        textEditor->document()->setModified(false);
        setWindowTitleFilename();

        actCompile->setDisabled(false);
        actRun->setDisabled(false);
        actCompileRun->setDisabled(false);
    }
}

void MainWindow::saveFile()
{
    if (filename.isEmpty())
    {
        saveAsFile();
    }
    else
    {
//        QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//        textEditor->document()->setModified(false);
        writeFile();
    }

    setWindowTitleFilename();
}

void MainWindow::saveAsFile()
{
    QFileDialog saveAsDlg;
    saveAsDlg.setAcceptMode(QFileDialog::AcceptSave);

    QString filename = saveAsDlg.getSaveFileName(this, tr("Save File As"), "", "Intel4004 assembler (*.asm);;All files (*.*)");
    if (!filename.isEmpty())
    {
        this->filename = filename;
        createOutputFilename();
        writeFile();

//        QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//        textEditor->document()->setModified(false);
        setWindowTitleFilename();

        actCompile->setDisabled(false);
        actRun->setDisabled(false);
        actCompileRun->setDisabled(false);
    }
}

void MainWindow::exitFile()
{
    QMainWindow::close();
}

void MainWindow::undoEdit()
{
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->undo();
}

void MainWindow::redoEdit()
{
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->redo();
}

void MainWindow::cutEdit()
{
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->cut();
}

void MainWindow::copyEdit()
{
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->copy();
}

void MainWindow::pasteEdit()
{
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->paste();
}

void MainWindow::deleteEdit()
{
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->textCursor().removeSelectedText();
}

void MainWindow::selectAllEdit()
{
//    QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
//    textEditor->selectAll();
}

void MainWindow::buildCode()
{
    saveFile();
    lstResult->clear();
//    compiler.reset(new Compiler(/*filename.toStdString(), outputname.toStdString()*/));
//    compiler->compile(filename.toStdString());

//    for (const Error& i : compiler->getErrors())
//    {
//        QString e;
//        if (i.line != -1)
//        {
//            e.append("Line ").append(QString::number(i.line));
//        }
//        e.append("\tCommand: ")
//                .append(QString::fromStdString(i.command))
//                .append("\t")
//                .append(QString::fromStdString(i.text))
//                .append("\n");
//        lstResult->addItem(e);

//    }

//    if(compiler->getErrors().empty())
//    {
//        lstResult->addItem("Project was compiled successfully.\n");

//        romWidget->clear();
////        romWidget->write(compiler->getCompiledCode());
//    }
}

void MainWindow::compileBuild()
{
    buildCode();
}

void MainWindow::runBuild()
{

}

void MainWindow::compileRunBuild()
{
    buildCode();
//    simulator.reset(new Simulator());
//    simulator->setCode(compiler->getCompiledCode());
}

void MainWindow::debugResume()
{

}

void MainWindow::debugStep()
{
//    if (simulator)
//    {
//        simulator->step();
//    }
//    else
//    {
//        // TODO Exception
//        std::cerr << "Can't make a step, because simulator was not created."  << std::endl;
//    }
}

void MainWindow::debugStop()
{

}

void MainWindow::debugReset()
{

}

void MainWindow::closeEvent(QCloseEvent* event)
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, tr("Exit"), tr("Do you want to exit?"));
    if (btn == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}






