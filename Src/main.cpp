#include "main.h"
#include "Config.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWindow &win = *(new QWindow());

    auto config = ConfigFile("../config.json");

    auto root = config.getConfigRoot();
    auto val = root.value("title");
    win.setTitle(val.toString());
    win.show();

    return QApplication::exec();
}
