
#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWindow window;
    MyPushButton *button = new MyPushButton(QString("Res/c21aca3d70cf3bc72959fef08c00baa1cd112a60.jpg"));
    button->resize(50000, 50000);
    button->show();
    return QApplication::exec();
}
