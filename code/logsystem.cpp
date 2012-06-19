#include "logsystem.h"

LogMessage::LogMessage(const std::string& s,unsigned int i){
    this->log = QString(s.c_str());
    this->degree = i;
}

void LogSystem::printLog(const LogMessage& l){

    cerr<<l.getLog().toStdString()<<endl;

    QFile file("LogFichier");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
         return;

    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    flux << l.getLog().toStdString().c_str() << endl;
}
