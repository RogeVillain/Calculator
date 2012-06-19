/*!
 * \file logsystem.h
 * \brief Class LogSystem ET Class LogMessage
 * \author Frederic Roge, Paul Villain
 */
#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QString>
#include <sstream>
#include <QFile>
#include <QTextStream>
#include <iostream>

using namespace std;

/*!
* \class LogMessage
* \brief Classe pour les messages log
*/
class LogMessage
{
    QString log; /*!< contenu du message log*/
    unsigned int degree;  /*!< degre d'importance du message log */
public:
    /*!
    * \brief Constructeur
    *
    * \param Contenu du message
    * \param Degre d'importance du message
    */
    LogMessage(const std::string&,unsigned int);
    /*!
    * \brief Partie du message précisant le degré d'importance du message
    */
    QString getLog()const{
        std::stringstream ss;
        ss<<"[";
        ss<<degree;
        ss<<"]";
        return QString(ss.str().c_str()+log);
        }
};

/*!
* \class LogSystem
* \brief Classe pour la gestion des messages log
*/
class LogSystem
{
public:
    /*!
    * \brief Affiche un message log dans la console
    * \param log message à ajouter
    */
    static void printLog(const LogMessage & l);
};
#endif // LOGSYSTEM_H
