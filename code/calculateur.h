/*!
 * \file calculatrice.h
 * \brief Header calculatrice permettant les opérations sur les constantes
 * \author Frederic Roge, Paul Villain
 */
#ifndef CALCULATEUR_H
#define CALCULATEUR_H

#include <iostream>
#include "complexe.h"
#include "expression.h"
#include <cmath>

/*!
     *  \brief Convertisseur en Entier
     *
     *  Convertit un type Constante en Entier
     *
     *  \param a : Constante
     *	\return La Constante convertit en Entier
     */
Entier* toEntier(Constante* a);
/*!
     *  \brief Convertisseur en Rationnel
     *
     *  Convertit un type Constante en Rationnel
     *
     *  \param a : Constante
     *	\return La Constante convertit en Rationnel
     */
Rationnel* toRationnel(Constante* a);
/*!
     *  \brief Convertisseur en Reel
     *
     *  Convertit un type Constante en Reel
     *
     *  \param a : Constante
     *	\return La Constante convertit en Reel
     */
Reel* toReel(Constante* a);
/*!
     *  \brief Convertisseur en Complexe
     *
     *  Convertit un type Constante en Complexe en mettant la partie imaginaire et réelle dans la type voulu
     *
     *  \param a : Constante
     *  \param T : Type
     *	\return La Constante convertit en Complexe
     */
Complexe* toComplexe(Constante* a, const Type& T);
/*!
     *  \brief Additionneur de Constantes
     *
     *  Additionne deux Constantes suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *  \param Tcomplexe : Type (définissant le mode de possible conversion pour l'addition de complexes)
     *	\return La somme des constantes
     */
Constante* addition(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b);
/*!
     *  \brief Soustracteur de Constantes
     *
     *  Soustrait deux Constantes suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *  \param Tcomplexe : Type (définissant le mode de possible conversion pour la soustraction de complexes)
     *	\return La différence des constantes
     */
Constante* soustraction(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b);
/*!
     *  \brief Multiplicateur de Constantes
     *
     *  Multiplie deux Constantes suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *  \param Tcomplexe : Type (définissant le mode de possible conversion pour la multiplication de complexes)
     *	\return Le produit des constantes
     */
Constante* multiplication(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b);
/*!
     *  \brief Diviseur de Constantes
     *
     *  Divise deux Constantes suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *  \param Tcomplexe : Type (définissant le mode de possible conversion pour la division de complexes)
     *	\return Le rapport des constantes
     */
Constante* div(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b);
/*!
     *  \brief Calcul du cosinus d'une constante
     *
     *  Permet de calculer le cosinus d'une constante suivant l'unité d'angle choisit
     *
     *  \param a : Constante
     *  \param degree : bool (type d'angle : degré ou radian)
     *	\return Le cosinus de la Constante
     */
Constante* cos(Constante* a, bool degre);
/*!
     *  \brief Calcul du cosinus hyperbolique d'une constante
     *
     *  Permet de calculer le cosinus hyperbolique d'une constante
     *
     *  \param a : Constante
     *	\return Le cosinus hyperbolique de la Constante
     */
Constante* cosh(Constante* a);
/*!
     *  \brief Calcul du sinus d'une constante
     *
     *  Permet de calculer le sinus d'une constante suivant l'unité d'angle choisit
     *
     *  \param a : Constante
     *  \param degree : bool (type d'angle : degré ou radian)
     *	\return Le sinus de la Constante
     */
Constante* sin(Constante* a, bool degre);
/*!
     *  \brief Calcul du sinus hyperbolique d'une constante
     *
     *  Permet de calculer le sinus hyperbolique d'une constante
     *
     *  \param a : Constante
     *	\return Le sinus hyperbolique de la Constante
     */
Constante* sinh(Constante* a);
/*!
     *  \brief Calcul de la tangente d'une constante
     *
     *  Permet de calculer la tangente d'une constante suivant l'unité d'angle choisit
     *
     *  \param a : Constante
     *  \param degree : bool (type d'angle : degré ou radian)
     *	\return La tangente de la Constante
     */
Constante* tan(Constante* a, bool degre);
/*!
     *  \brief Calcul de la tangente hyperbolique d'une constante
     *
     *  Permet de calculer la tangente hyperbolique d'une constante
     *
     *  \param a : Constante
     *	\return La tangente hyperbolique de la Constante
     */
Constante* tanh(Constante* a);
/*!
     *  \brief Calcul du modulo d'une constante
     *
     *  Permet de calculer une constante modulo une autre constante
     *
     *  \param a : Constante
     *  \param b : Constante
     *	\return Le modulo de la Constante
     */
Constante* mod(Constante* a, Constante* b);
/*!
     *  \brief Calcul du factoriel d'une constante
     *
     *  Permet de calculer le factoriel d'une constante (d'un Entier uniquement)
     *
     *  \param a : Constante
     *	\return Le factoriel de la Constante
     */
Constante* fact(Constante* a);
/*!
     *  \brief Calcul d'une constante à une certaine puissance
     *
     *  Permet de calculer une constante puissance une autre constante en fonction du type des Constantes
     *
     *  \param a : Constante
     *  \param b : Constante
     *  \param T : Type
     *	\return La Constante puissance l'autre Constante
     */
Constante* pow(Constante* a, Constante* b, const Type& T);
/*!
     *  \brief Calcul le logarithme décimal d'une constante
     *
     *  Permet de calculer le logarithme décimal d'une constante en fonction du type de la Constantes
     *
     *  \param a : Constante
     *  \param T : Type
     *	\return Le logarithme décimal de la Constante
     */
Constante* log(Constante* a, const Type& T);
/*!
     *  \brief Calcul le logarithme néperien d'une constante
     *
     *  Permet de calculer le logarithme néperien d'une constante en fonction du type de la Constantes
     *
     *  \param a : Constante
     *  \param T : Type
     *	\return Le logarithme néperien de la Constante
     */
Constante* ln(Constante*a, const Type& T);
/*!
     *  \brief Calcul la racine carrée d'une constante
     *
     *  Permet de calculer la racine carrée d'une constante en fonction du type de la Constantes
     *
     *  \param a : Constante
     *  \param T : Type
     *	\return La racine carrée de la Constante
     */
Constante* sqrt(Constante*a, const Type& T);
/*!
     *  \brief Calcul le carré d'une constante
     *
     *  Permet de calculer le carré d'une Constantes suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *  \param Tcomplexe : Type (définissant le mode de possible conversion pour la division de complexes)
     *	\return Le carré de la Constante
     */
Constante* sqr(Constante*a, const Type& T, const Type& Tcomplexe);
/*!
     *  \brief Calcul le cube d'une constante
     *
     *  Permet de calculer le cube d'une Constante suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *  \param Tcomplexe : Type (définissant le mode de possible conversion pour la division de complexes)
     *	\return Le cube de la Constante
     */
Constante* cube(Constante*a, const Type& T, const Type& Tcomplexe);
/*!
     *  \brief Calcul l'inverse d'une constante
     *
     *  Permet de calculer l'inverse d'une Constante suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *	\return L'inverse de la Constante
     */
Constante* inv(Constante* a, const Type& T);
/*!
     *  \brief Calcul l'opposé d'une constante
     *
     *  Permet de calculer l'opposé d'une Constante suivant le Mode choisis
     *
     *  \param a : Constante
     *  \param Mode : Type (définissant le mode de la calculatrice)
     *  \param Tcomplexe : Type (définissant le mode de possible conversion pour la division de complexes)
     *	\return L'opposé de la Constante
     */
Constante* sign(Constante*a, const Type& T, const Type& Tcomplexe);

#endif // CALCULATEUR_H
