#include "GUI.h"
#include <QtWidgets/QApplication>
#include "test.h"
int main(int argc, char *argv[])
{   
    test_all();
    QApplication a(argc, argv);
    Repo r{ "elemente.txt" };
    Service s{ r };
    GUI w{s};
    w.show();
    return a.exec();
}
