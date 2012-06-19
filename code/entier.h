/*!
 * \file entier.h
 * \brief classe entier et toutes les fonctions associ�es
 * \author Frederic Roge, Paul Villain
 */
#ifndef ENTIER_H
#define ENTIER_H

#include "constante.h"

/*!
 * \class Entier
 * \brief D�fini le type Entier h�ritant de Constante
 */
class Entier : public Constante
{
    int valeur;/*!< L'entier */
    virtual void buildConstant(const std::string&);/*!< Constructeur de constante empilable*/
public:
    /*!
    * \brief Constructeur d'Entier
    * \param val : Chaine de caract�re initialisant l'Entier
    */
    Entier(const std::string& val);
    /*!
     *  \brief Constructeur
     *
     *  \param val : Texte r�cup�r�
     *	\param T1 : Type de val
     *	\param T2 : Type du complexe que l'on souhaite obtenir
     */
    Entier(const std::string& val, const Type& T1, const Type& T2 = entier);
    /*!
     *  \brief Accesseur
     *  \return L'Entier
     */
    int getVal() const {return valeur;}
    /*!
     *  \brief Accesseur
     *  \brief modifie l'Entier
     */
    void setVal(const int& i) {valeur = i;}
    /*!
     *  \brief Accesseur
     *  \return Renvoi la chaine correspondant � l'Entier
     */
    virtual std::string getChain() const;
    /*!
    * \brief Surrcharge de +=
    */
    Entier& operator+=(Entier const& e);
    /*!
    * \brief Surrcharge de -=
    */
    Entier& operator-=(Entier const& e);
    /*!
    * \brief Surrcharge de *=
    */
    Entier& operator*=(Entier const& e);
    /*!
    * \brief Surrcharge de /=
    */
    Entier& operator/=(Entier const& e);

};

/*!
* \brief Surrcharge de +
*/
Entier operator+(Entier const& a, Entier const& b);
/*!
* \brief Surrcharge de -
*/
Entier operator-(Entier const& a, Entier const& b);
/*!
* \brief Surrcharge de *
*/
Entier operator*(Entier const& a, Entier const& b);
/*!
* \brief Surrcharge de /
*/
Entier operator/(Entier const& a, Entier const& b);


#endif // ENTIER_H
