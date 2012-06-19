#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "constante.h"
#include "entier.h"

class Rationnel : public Constante
{
    Entier* numerateur;/*!< numérateur*/
    Entier* denominateur;/*!< dénominateur*/
    virtual void buildConstant(const std::string&);/*!< Construit la Constante empilable*/
public:
    /*!
    *  \brief Constructeur
    *  Constructeur de la classe Rationnel initialisant le buildConstante et le genre du rationnel
    *  \param string : buildConstante
    */
    Rationnel(const std::string& );
    /*!
    *  \brief Constructeur
    *  Constructeur de la classe Rationnel
    *  \param val : string
    *  \param T1 : Type de la constante contenue dans val
    *  \param T2 : Type du contenu du complexe que l'on peut transmettre si on le souhaite
    */
    Rationnel(const std::string& val, const Type& T1, const Type& T2 = entier);
    /*!
      * \brief Constructeur de recopie
      *
      */
    Rationnel (const Rationnel &);

    /*!
      * \brief Accesseur
      * \return Le numérateur entant qu' int
      */
    int getNum_int() const {return numerateur->getVal();}
    /*!
      * \brief Accesseur
      * \return Le dénominateur entant qu' int
      */
    int getDen_int() const {return denominateur->getVal();}

    /*!
      * \brief Accesseur
      * \return Change la valeur du numérateur
      */

    void setNum(Entier* a) {delete numerateur; numerateur = a;}
    /*!
      * \brief Accesseur
      * \return Change la valeur du dénominateur
      */
    void setDen(Entier* a) {delete denominateur; denominateur = a;}
    /*!
      * \brief Accesseur
      * \return Le numérateur entant qu'Entier
      */
    Entier* getNum() const {return numerateur;}
    /*!
      * \brief Accesseur
      * \return Le dénominateur entant qu'Entier
      */
    Entier* getDen() const {return denominateur;}
    /*!
      * \brief Destructeur
      * Libï¿½re les pointeurs d'Entier
      */
    ~Rationnel() {delete numerateur; delete denominateur;}
    /*!
      * \brief Convertit en chaine le Rationnel
      * \return La chaine correspondante au Rationnel
      */
    virtual std::string getChain() const;
    /*!
      * \brief Surcharge de l'opérateur +=
      */
    Rationnel& operator+=(Rationnel const& e);
    /*!
      * \brief Surcharge de l'opérateur -=
      */
    Rationnel& operator-=(Rationnel const& e);
    /*!
      * \brief Surcharge de l'opérateur *=
      */
    Rationnel& operator*=(Rationnel const& e);
    /*!
      * \brief Surcharge de l'opérateur /=
      */
    Rationnel& operator/=(Rationnel const& e);
    /*!
      * \brief Simplifie le Rationnel
      */
    void simplifier();
};
/*!
  * \brief Surcharge de l'opérateur +
  */
Rationnel operator+(Rationnel const& a, Rationnel const& b);
/*!
  * \brief Surcharge de l'opérateur -
  */
Rationnel operator-(Rationnel const& a, Rationnel const& b);
/*!
  * \brief Surcharge de l'opérateur *
  */
Rationnel operator*(Rationnel const& a, Rationnel const& b);
/*!
  * \brief Surcharge de l'opérateur /
  */
Rationnel operator/(Rationnel const& a, Rationnel const& b);
/*!
  * \brief PGCD de deux nombres
  * \param a: int
  * \param b : int
  * \return PGCD (a,b)
  */
int pgcd(int a, int b);

#endif // RATIONNEL_H
