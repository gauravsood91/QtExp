#ifndef NOTEPAD_H
#define NOTEPAD_H

#include<QMainWindow>
#include<QMenu>
#include<QMenuBar>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QTextEdit>

class Notepad:public QMainWindow
{
    Q_OBJECT

public:
    Notepad();
private:
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QMenu *fileMenu;
    QMenu *editMenu;
    QTextEdit *editArea;
    void createMenus();
    void createActions();

    QAction *newAction;
    QAction *quitAction;
    QAction *saveAction;
private slots:
    void newFile();
    void quit();
    void save();
    void open();
};

#endif // NOTEPAD_H
