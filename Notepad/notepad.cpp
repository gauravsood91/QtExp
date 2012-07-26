#include "notepad.h"
#include<QDebug>

Notepad::Notepad()
{
    hLayout=new QHBoxLayout;
    vLayout=new QVBoxLayout;
    createActions();
    createMenus();
    createToolBar();
    editArea=new QTextEdit;

    showMaximized();
    setCentralWidget(editArea);
    setWindowTitle("Notepad");

    show();
}
void Notepad::createActions()
{
    newAction=new QAction("New",this);
    newAction->setShortcut(QKeySequence::New);
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));

    openAction=new QAction("Open",this);
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction,SIGNAL(triggered()),this,SLOT(open()));

    saveAction=new QAction("Save",this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    saveAsAction=new QAction("Save As",this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    connect(saveAsAction,SIGNAL(triggered()),this,SLOT(saveAs()));

    quitAction=new QAction("Quit",this);
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction,SIGNAL(triggered()),this,SLOT(quit()));

    copyAction=new QAction("Copy",this);
    copyAction->setShortcut(QKeySequence::Copy);
    connect(copyAction,SIGNAL(triggered()),this,SLOT(copy()));

    cutAction=new QAction("Cut",this);
    cutAction->setShortcut(QKeySequence::Cut);
    connect(cutAction,SIGNAL(triggered()),this,SLOT(cut()));

    pasteAction=new QAction("Paste",this);
    pasteAction->setShortcut(QKeySequence::Paste);
    connect(pasteAction,SIGNAL(triggered()),this,SLOT(paste()));
}
void Notepad::createToolBar()
{
    toolBar=addToolBar(tr("ToolBar"));
    toolBar->addAction(newAction);
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(saveAsAction);
    toolBar->addAction(quitAction);
    toolBar->addAction(cutAction);
    toolBar->addAction(copyAction);
    toolBar->addAction(pasteAction);

}

void Notepad::createMenus()
{
    fileMenu=menuBar()->addMenu(tr("File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addAction(quitAction);

    editMenu=menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
}
void Notepad::newFile()
{
    this->fileName="";
    editArea->setText("");
}
void Notepad::open()
{
    QString fileN=QFileDialog::getOpenFileName();
    this->fileName=fileN;
    QString text;
    QFile fileObj(fileN);
    qDebug()<<fileObj.fileName();
    fileObj.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream in(&fileObj);

    while(!in.atEnd())
    {
        text=in.readLine();
        editArea->append(text);
        qDebug()<<text;
    }
}
void Notepad::save()
{
    if(!this->fileName.isNull())
    {
        QFile fileObj(this->fileName);
        fileObj.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream out(&fileObj);
        QString text=editArea->toPlainText();
        out<<text;
    }
}
void Notepad::saveAs()
{
    QString fileN=QFileDialog::getSaveFileName();
    QFile fileObj(fileN);
    fileObj.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&fileObj);
    QString text=editArea->toPlainText();
    out<<text;
}

void Notepad::quit()
{
    this->close();
}
void Notepad::copy()
{
    editArea->copy();

}
void Notepad::paste()
{
    editArea->paste();
}
void Notepad::cut()
{
    editArea->cut();
}
