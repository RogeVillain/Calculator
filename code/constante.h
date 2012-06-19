/*!
 * \file constante.h
 * \brief classe constante et toutes les fonctions associées
 * \author Frederic Roge, Paul Villain
 */
#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

/*!
 * \enum Type
 * \brief Enumère les types de Constante
 */
enum Type {
       entier, /*!< Type entier */
       rationnel,/*!< Type rationnel */
       reel,/*!< Type reel */
       complexe,/*!< Type complexe */
       expression,/*!< Type expression */
       erreur/*!< Type erreur */
    };

/*!
 * \class Constante
 * \brief Défini le type de Constante
 */
class Constante
{
protected:
    Type genre;/*!< Type de la constante */
    virtual void buildConstant(const std::string&) = 0;/*!< Constructeur de constante empilable*/
public:
    /*!
    * \brief Accesseur
    * \return Le type de la Constante
    */
    const Type& getType() { return genre; }
    /*!
    * \brief Accesseur
    * \return La chaine correspondant à la Constante
    */
    virtual std::string getChain() const = 0;
};

#endif // CONSTANTE_H
