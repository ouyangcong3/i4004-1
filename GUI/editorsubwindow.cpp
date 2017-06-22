#include "editorsubwindow.h"

/// TODO there is some commented code, investigate what I may use
EditorSubWindow::EditorSubWindow(QWidget *parent) : SubWindow(parent)
{
    editor = std::shared_ptr<Editor>(new Editor(parent));

    this->setWidget(editor.get());
    this->setWindowTitle("Editor");
    this->setWindowIcon(QIcon(":/Resources/icons/editor.png"));

    connect(editor.get(), &Editor::onTextChanged, [=](){
        emit onTextChanged();
    });
}



EditorSubWindow::~EditorSubWindow()
{
    // Delete here something or finalize
}

void EditorSubWindow::readFile()
{
    std::fstream file(filename.toStdString(), ios::in);
    //    file.open();

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
        std::shared_ptr<QTextEdit> text = this->editor->getText();
        text->setPlainText(doc);
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Can't open file ").append(filename));
    }
}

void EditorSubWindow::writeFile()
{
    std::fstream file(filename.toStdString(), ios::out | ios::trunc);

    if (file.is_open())
    {
        std::shared_ptr<QTextEdit> text = this->editor->getText();
        QStringList lines = text->toPlainText().split("\n");

        for (QString l : lines)
        {
            file << l.toStdString() << "\n";
        }

        file.close();
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Can't save to file ").append(filename));
    }
}

void EditorSubWindow::newFile()
{
    QMessageBox::StandardButton btn = QMessageBox::question(this, tr("New file"), tr("Do you want to start a new file?"));
    if (btn == QMessageBox::Yes)
    {
        std::shared_ptr<QTextEdit> text = this->editor->getText();
        text->clear();
        text->document()->setModified(false);

        this->filename.clear();

        //        setWindowTitleFilename();

        //        actCompile->setDisabled(true);
        //        actRun->setDisabled(true);
        //        actCompileRun->setDisabled(true);
    }
}

void EditorSubWindow::openFile()
{
    QFileDialog openDlg;
    openDlg.setAcceptMode(QFileDialog::AcceptOpen);

    filename = openDlg.getOpenFileName(this, tr("Open File"), "", "Intel4004 assembler (*.asm);;All files (*.*)");
    if (!filename.isEmpty())
    {
        this->filename = filename;
        //        createOutputFilename();
        readFile();

        //        QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
        //        textEditor->document()->setModified(false);
        //        setWindowTitleFilename();

        //        actCompile->setDisabled(false);
        //        actRun->setDisabled(false);
        //        actCompileRun->setDisabled(false);
    }
}

void EditorSubWindow::saveFile()
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

    //    setWindowTitleFilename();
}

void EditorSubWindow::saveAsFile()
{
    QFileDialog saveAsDlg;
    saveAsDlg.setAcceptMode(QFileDialog::AcceptSave);

    QString filename = saveAsDlg.getSaveFileName(this, tr("Save File As"), "", "Intel4004 assembler (*.asm);;All files (*.*)");
    if (!filename.isEmpty())
    {
        this->filename = filename;
        //        createOutputFilename();
        writeFile();

        //        QTextEdit* textEditor = this->editorSubWindow->getTextEditor();
        //        textEditor->document()->setModified(false);
        //        setWindowTitleFilename();

        //        actCompile->setDisabled(false);
        //        actRun->setDisabled(false);
        //        actCompileRun->setDisabled(false);
    }
}

void EditorSubWindow::undoEdit()
{
    std::shared_ptr<QTextEdit> textEditor = this->editor->getText();
    textEditor->undo();
}

void EditorSubWindow::redoEdit()
{
    std::shared_ptr<QTextEdit> textEditor = this->editor->getText();
    textEditor->redo();
}

void EditorSubWindow::cutEdit()
{
    std::shared_ptr<QTextEdit> textEditor = this->editor->getText();
    textEditor->cut();
}

void EditorSubWindow::copyEdit()
{
    std::shared_ptr<QTextEdit> textEditor = this->editor->getText();
    textEditor->copy();
}

void EditorSubWindow::pasteEdit()
{
    std::shared_ptr<QTextEdit> textEditor = this->editor->getText();
    textEditor->paste();
}

void EditorSubWindow::deleteEdit()
{
    std::shared_ptr<QTextEdit> textEditor = this->editor->getText();
    textEditor->textCursor().removeSelectedText();
}

void EditorSubWindow::selectAllEdit()
{
    std::shared_ptr<QTextEdit> textEditor = this->editor->getText();
    textEditor->selectAll();
}

QString EditorSubWindow::getFilename() const
{
    return filename;
}
