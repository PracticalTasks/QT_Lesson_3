#include "Lesson_3.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lesson_3 w;
    w.setWindowTitle("SimplePad ver. 0.01");

    w.show();
    return a.exec();
}
