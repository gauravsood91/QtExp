#include<QApplication>
#include "notepad.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    Notepad notepad;
    return app.exec();
}
