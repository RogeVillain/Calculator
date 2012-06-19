/*!
 * \file complexe.h
 * \brief classe complexe et toutes les fonctions associées
 * \author Frederic Roge, Paul Villain
 */
#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "constante.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"

/*!
   * \class Complexe
   * \brief classe definissant le type Complexe herite de la classe Constante
   */
class Complexe : public Constante
{
    Constante* _reel;   /*!< Partie reelle*/
    Constante* _img;    /*!< Partie imaginaire*/
    Type complexe_type_contenu;/*!< Type de contenu du complexe*/
    virtual void buildConstant(const std::string&);/*!< Constructeur de Constante empilable*/
public:
   /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe Complexe initialisant le buildConstante et le type du complexe
    *  \param string : buildConstante
    *	\param Type : Type
    */
    Complexe(const std::string&, const Type&);

    /*!
     *  \brief Constructeur
     *
     *  \param val : Texte récupéré
     *	\param T : Type de val
     *	\param Tvoulu : Type du complexe que l'on souhaite obtenir
     *	\param Torigine : Type du complexe transmis
     */
    Complexe(const std::string& val, const Type& T, const Type& Tvoulu, const Type& Torigine = entier);
    /*!
     *  \brief Constructeur de recopie
     *
     *  \param Complexe : Complexe à copier dans le Complexe présent
     */
    Complexe(const Complexe &);
    /*!
     *  \brief Destructeur
     *
     */
    ~Complexe();
    /*!
     *  \brief Accesseur
     *  \return Partie réelle
     */
    Constante* getReel() const {return _reel;}
    /*!
     *  \brief Accesseur
     *  \return Partie imaginaire
     */
    Constante* getIm() const {return _img;}
    /*!
     *  \brief Accesseur
     *  \return Modifie la partie réelle
     */
    void setReel(Constante* a) {delete _reel; _reel = a;}
    /*!
     *  \brief Accesseur
     *  \return Modifie la partie imaginaire
     */
    void setIm(Constante* a) {delete _img; _img = a;}
    /*!
     *  \brief Accesseur
     *  \return Type du contenu du complexe
     */
    Type get_complexe_type_contenu() const {return complexe_type_contenu;}
    /*!
     *  \brief Accesseur
     *  \return La chaine correspondant au Complexe
     */
    virtual std::string getChain() const;
    /*!
     *  \brief Surcharge de +=
     */
    Complexe& operator+=(Complexe const& e);
    /*!
     *  \brief Surcharge de -=
     */
    Complexe& operator-=(Complexe const& e);
    /*!
     *  \brief Surcharge de *=
     */
    Complexe& operator*=(Complexe const& e);
    /*!
     *  \brief Surcharge de /=
     */
    Complexe& operator/=(Complexe const& e);
};

/*!
 *  \brief Surcharge de +
 */
Complexe operator+(Complexe const& a, Complexe const& b);
/*!
 *  \brief Surcharge de -
 */
Complexe operator-(Complexe const& a, Complexe const& b);
/*!
 *  \brief Surcharge de *
 */
Complexe operator*(Complexe const& a, Complexe const& b);
/*!
 *  \brief Surcharge de /
 */
Complexe operator/(Complexe const& a, Complexe const& b);

#endif // COMPLEXE_H
