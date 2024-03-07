#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Tests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestAll();
    MainWindow w;
    w.show();
    return a.exec();
    
}
