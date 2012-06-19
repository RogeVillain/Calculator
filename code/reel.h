/*!
 * \file reel.h
 * \brief classe reelle et toutes les fonctions associées
 * \author Frédéric Rogé, Paul Villain
 */

#ifndef REEL_H
#define REEL_H

#include "constante.h"

/*!
* \class Reel
* \brief classe definissant le type Reel herite de la classe Constante
*/

class Reel : public Constante
{
    float valeur;/*!< Valeur du reel */
    virtual void buildConstant(const std::string&);/*!< Constructeur de Constante empilable*/
public:
    /*!
    *  \brief Constructeur
    *  Constructeur de la classe Reel
    *  \param val : string
    */
    Reel(const std::string& val);
    /*!
    *  \brief Constructeur
    *  Constructeur de la classe Reel
    *  \param val : string
    *  \param T1 : Type de la constante contenue dans val
    *  \param T2 : Type du contenu du complexe que l'on peut transmettre si on le souhaite
    */
    Reel(const std::string& val, const Type& T1, const Type& T2 = entier);
    /*!
    *  \brief Accesseur
    *
    *  \return Valeur du reel
    */
    float getVal() const {return valeur;}
    /*!
    *  \brief Accesseur
    *
    *  \return Modifie la valeur du reel
    */
    void setVal(float f) {valeur = f;}
    /*!
    *  \brief Convertisseur
    *
    *  \return Une chaine correspondant à la valeur du reel
    */
    virtual std::string getChain() const;
    /*!
    *  \brief Surcharge de +=
    */
    Reel& operator+=(Reel const& e);
    /*!
     *  \brief Surcharge de -=
     */
    Reel& operator-=(Reel const& e);
    /*!
     *  \brief Surcharge de *=
     */
    Reel& operator*=(Reel const& e);
    /*!
     *  \brief Surcharge de /=
     */
    Reel& operator/=(Reel const& e);
};

/*!
 *  \brief Surcharge de +
 */
Reel operator+(Reel const& a, Reel const& b);
/*!
 *  \brief Surcharge de -
 */
Reel operator-(Reel const& a, Reel const& b);
/*!
 *  \brief Surcharge de *
 */
Reel operator/(Reel const& a, Reel const& b);
/*!
 *  \brief Surcharge de /
 */
Reel operator*(Reel const& a, Reel const& b);

#endif // REEL_H
