/*!
 * \file expression.h
 * \brief classe Expression et toutes les fonctions associées
 * \author Frederic Roge, Paul Villain
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H


#include "constante.h"
/*!
* \class Expression
* \brief classe definissant le type Expression, herite de la classe Constante
*/
class Expression : public Constante
{
    std::string expr;       /*!< L'expression*/
    void buildConstant(const std::string& val);     /*!< Constructeur de Constante empilable*/
public:
    /*!
    * \brief Constructeur
    * Expression initiallisée avec un string
    * \param val : La nouvelle Expression
    */
    Expression(std::string const& val);
    /*!
    * \brief Accesseur
    * \return L'Expression
    */
    std::string getExpr() const {return expr;}
    /*!
     * \brief Accesseur
     * Change la valeur de l'Expression
    */
    void setExpr(const std::string& s) {expr = s;}
    /*!
      * \brief Chaine de l'Expression
      * \return la chaine correspondant à l'Expression
      */
    virtual std::string getChain() const;
};

#endif // EXPRESSION_H
