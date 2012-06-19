/*!
 * \file factoryconst.h
 * \brief classe FactoryConst et toutes les fonctions associées
 * \author Frederic Roge, Paul Villain
 */
#ifndef FACTORYCONST_H
#define FACTORYCONST_H

#include "complexe.h"
#include "expression.h"
#include "factoryconst.h"

/*!
* \class FactoryConst
*   Créé des constante depuis les types strings retourné par les différentes constantes
*/
class FactoryConst
{
public:
    /*!
    * \brief Créé une constante
    * \param val : la valeur précédement convertie en string
    * \param T : Type de val
    * \return Constante de type T
    */
    static Constante* createConstant(const std::string& val, const Type& T);
    /*!
    * \brief Créé une constante
    * \param val : la valeur précédement convertie en string
    * \param T : Type de val
    * \param Tdonne : Type voulu en retour
    * \return Constante de type Tdonne
    */
    static Constante* createConstant(const std::string& val, const Type& T, const Type& Tdonne);
    /*!
    * \brief Créé une constante
    * \param val : la valeur précédement convertie en string
    * \param T : Type de val
    * \param Tdonne : Type voulu en retour
    * \param Tcomplexe : Type des parties réelles et imaginaires du complexe
    * \return Constante de type Tdonne
    */
    static Constante* createConstant(const std::string& val, const Type& T, const Type& Tdonne, const Type& Tcomplexe);
    /*!
    * \brief Créé une constante
    * \param val : la valeur précédement convertie en string
    * \param T : Type de val
    * \param Tdonne : Type voulu en retour
    * \param Tvoulu : Type voulu pour le complexe
    * \param Torigine : Type d'origine du complexe
    * \return Constante de type Tdonne
    */
    static Constante* createConstant(const std::string& val, const Type& T, const Type& Tdonne, const Type& Tvoulu, const Type& Torigine);
private:
    /*!
    * \brief Constructeur
    * Empeche toute instanciation de FactoryConst
    */
    FactoryConst() {}
};

#endif // FACTORYCONST_H
