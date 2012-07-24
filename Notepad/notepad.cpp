#include "notepad.h"
#include<QDebug>
Notepad::Notepad()
{
    hLayout=new QHBoxLayout;
    vLayout=new QVBoxLayout;

    createActions();
    createMenus();
    editArea=new QTextEdit;

    setCentralWidget(editArea);

    show();
}
void Notepad::createActions()
{
    newAction=new QAction("New",this);
    newAction->setShortcut(QKeySequence::New);
    connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));

    saveAction=new QAction("Save",this);
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction,SIGNAL(triggered()),this,SLOT(save()));

    quitAction=new QAction("Quit",this);
    quitAction->setShortcut(QKeySequence::Quit);
    connect(quitAction,SIGNAL(triggered()),this,SLOT(quit()));



}

void Notepad::createMenus()
{
    fileMenu=menuBar()->addMenu(tr("File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);

    editMenu=menuBar()->addMenu(tr("Edit"));

}
void Notepad::newFile()
{

}
void Notepad::open()
{

}
void Notepad::save()
{

}
void Notepad::quit()
{
    this->close();
}
