//
//  QDirSystem.cpp
//  projectKTFD
//
//  Created by Keitaro Takahashi on 2018/05/04.
//

#include "QDirSystem.hpp"

QDirSystem::QDirSystem()
{
    
}

QDirSystem::~QDirSystem()
{
    
}

QString QDirSystem::getSaveDirUrlByDialog()
{
    QString selFilter;
    QString filename = QFileDialog::getSaveFileName(0,
                                                    QObject::tr("Save as... "),
                                                    "IRiMaSProject",
                                                    QObject::tr(""));
    
    std::cout << filename.toStdString() << std::endl;
    
    return filename;
}

QString QDirSystem::getDirUrlByDialog()
{
    QString url = QFileDialog::getExistingDirectory();
    return url;
}

bool QDirSystem::createDirByDialog()
{
    QString url = getDirUrlByDialog();
    
    if(url.isEmpty()) {
        return false;
    }
    
    std::cout << url.toStdString() << std::endl;
    return true;
}

bool QDirSystem::createDir(QString url)
{
    QDir dir = QDir(url);

    if(!dir.mkdir(url)) {
        QMessageBox msg; msg.setText("Error : Could not create Directory. \n"); msg.exec(); return false;
    }
    return true;
}

bool QDirSystem::removeDir(QString url)
{
    
}

bool QDirSystem::moveDir(QString from, QString to)
{
    
}
