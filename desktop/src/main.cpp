//===========================================
//  Lumina-DE source code
//  Copyright (c) 2012, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <QUrl>


#include "LSession.h"
#include "Globals.h"

#include <LuminaXDG.h> //from libLuminaUtils
#include <LuminaOS.h>
#include <LUtils.h>
#include <LDesktopUtils.h>

#define DEBUG 0

int main(int argc, char ** argv)
{
    if (argc > 1) {
        if (QString(argv[1]) == QString("--version")) {
            qDebug() << LDesktopUtils::LuminaDesktopVersion();
            return 0;
        }
    }
    if(!QFile::exists(LOS::LuminaShare())) {
        qDebug() << "Lumina does not appear to be installed correctly. Cannot find: " << LOS::LuminaShare();
        return 1;
    }
    //Setup any pre-QApplication initialization values
    LXDG::setEnvironmentVars();

    LSession a(argc, argv);
    if(!a.isPrimaryProcess()) {
        return 0;
    }
    //Setup the log file
    QElapsedTimer *timer=0;
    if(DEBUG) {
        timer = new QElapsedTimer();
        timer->start();
    }
    if(DEBUG) {
        qDebug() << "Session Setup:" << timer->elapsed();
    }
    a.setupSession();
    if(DEBUG) {
        qDebug() << "Exec Time:" << timer->elapsed();
        delete timer;
    }
    int retCode = a.exec();
    //qDebug() << "Stopping the window manager";
    qDebug() << "Finished Closing Down Lumina";
    return retCode;
}