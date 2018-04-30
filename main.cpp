#include <QApplication>

#include "GlobalDatabase.hpp"
#include "MainWindow.hpp" // NOTE THAT MAINWINDOW.H IS A Q_OBJECT (SUBCLASS OF QMAINWINDOW) FOR WHICH MOC HAS BEEN PRESET

int main(int argc, char *argv[])
{
    QApplication mainApplication(argc, argv);
    
    GlobalDataBase *database = new GlobalDataBase();
    MainWindow w(nullptr, database);
    w.show();
    //kMainWindow w(nullptr);
    //w.show();
    
    // CLEANUP RESPONSIBILITY PASSED TO MAIN WINDOW
    QObject::connect(&mainApplication, &QApplication::aboutToQuit, &w, &MainWindow::cleanUpOnQuit);

    
    return mainApplication.exec();
}



