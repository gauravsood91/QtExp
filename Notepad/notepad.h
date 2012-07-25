#ifndef NOTEPAD_H
#define NOTEPAD_H

#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QToolBar>

class Notepad:public QMainWindow
{
    Q_OBJECT

public:
    Notepad();
private:
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QToolBar *toolBar;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QTextEdit *editArea;

    QString fileName;


    void createMenus();
    void createActions();
    void createToolBar();

    QAction *newAction;
    QAction *openAction;
    QAction *quitAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
private slots:
    void newFile();
    void quit();
    void save();
    void open();
    void saveAs();
    void copy();
    void cut();
    void paste();
};

#endif // NOTEPAD_H
