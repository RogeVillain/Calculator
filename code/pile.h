/*!
 * \file pile.h
 * \brief classe pile et toutes les fonctions associ�es
 * \author Frederic Roge, Paul Villain
 */
#ifndef PILE_H
#define PILE_H

#include <iostream>
#include <stack>
#include <vector>
#include "complexe.h"
/*!
   * \class Pile
   * \brief classe definissant la Pile de la calculatrice
   */
class Pile
{
public:
    /*!
      * \brief Singleton
      * Donne l'instance du Singleton
    */
    static Pile& donneInstance();
    /*!
      *\brief Singleton
      * Lib�re l'instance du Singleton
    */
    static void libereInstance();

    /*!
    * \brief Sommet de la Pile
    * \return Sommet de la pile (Constante)
    */
    Constante* sommetPile();
    /*!
    *   \brief Empiler
    *   Ajoute une nouvelle constante � la pile
    */
    void pushPile(Constante* ptr);
    /*!
    *   \brief D�piler
    *   \return Sommet de la pile (Constante)
    */
    Constante* popPile();
    /*!
      * \brief Test si la pile est vide
      * \return booleen
      */
    bool isEmpty() const {return p.empty();}
    /*!
      * \brief Taille de la pile
      * \return  Nombre d'�l�ments de la pile (int)
      */
    int getSize() const {return p.size();}
    /*!
      * \brief Vider la pile
      * Vide la pile
      */
    void dropPile();
    /*!
      * \brief Dupliquer le premier element de la Pile
      * \return Le premier �l�ment de la Pile
      */
    Constante* duplicate();
    /*!
      * \brief Echange deux valeurs de la pile
      * Echange la place de deux valeurs sur la Pile
      * \param i : Place du premier �l�ment (int)
      * \param j : Place du deuxi�me �l�ment � �changer avec le premier (int)
      */
    void swap(int i, int j);

protected:
    /*!
      * \brief Constructeur
      */
    Pile();
    /*!
      * \brief Constructeur de recopie
      * \param Pile : La pile � recopier
      */
    Pile(const Pile&);
    /*!
      * \brief Destructeur
      */
    ~Pile();
    /*!
      * \brief Surcharge de l'op�rateur d'affectation =
      *
      */
    void operator=(const Pile&);

private:

    static Pile* instanceUnique; /*!< Singleton */
    std::stack<Constante*> p; /*!< Pile de Constante */

};

#endif // PILE_H
