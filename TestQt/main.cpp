#include<QApplication>
#include "test1.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    test1 *t1=new test1;
    return app.exec();
}
