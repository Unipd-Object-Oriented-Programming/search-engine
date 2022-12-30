#include <QApplication>
#include <QFile>

#include "Service/Logger/Facade.h"
#include "Engine/Memory.h"
#include "View/MainWindow.h"

int main(int argc, char *argv[]) {
    Service::Logger::Facade logger_facade("./search-engine.log");

    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":assets/icon.svg"));

    QFile stylesheet(":/assets/stylesheet.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    Engine::Memory search_engine;
    View::MainWindow window(search_engine);
    window.resize(1024, 576);
    window.show();

    return app.exec();
}
