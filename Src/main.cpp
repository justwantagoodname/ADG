#include "main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWindow &win = *(new QWindow());
    win.setTitle("ADG");
    win.show();
    return QApplication::exec();
}
