#include <QtGui/QApplication>
#include <iostream>
#include "mainwindow.h"
#include "logsystem.h"
#include "factoryconst.h"
#include "pile.h"

using namespace std;

int main(int argc, char *argv[])
{
    QFile file("LogFichier");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.close();

    LogSystem::printLog(LogMessage("Lancement de l'application", 1));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();

    LogSystem::printLog(LogMessage("Arret de l'application", 1));

    return 0;
}
