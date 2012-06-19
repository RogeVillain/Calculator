#include "calculateur.h"
#include "mainwindow.h"

using namespace std;

Entier* toEntier(Constante* a)
{
    if(a->getType() == entier)
    {
        return dynamic_cast<Entier*>(a);
    }
    else if(a->getType() == rationnel)
    {
        return new Entier(a->getChain(), rationnel);
    }
    else if(a->getType() == reel)
    {
        return new Entier(a->getChain(), reel);
    }
    else if(a->getType() == complexe)
    {
        return new Entier(a->getChain(), complexe, dynamic_cast<Complexe*>(a)->get_complexe_type_contenu());
    }
    else
        return NULL;
}

Rationnel* toRationnel(Constante* a)
{
    if(a->getType() == entier)
    {
        return new Rationnel(a->getChain(), entier);
    }
    else if(a->getType() == rationnel)
    {
        return dynamic_cast<Rationnel*>(a);
    }
    else if(a->getType() == reel)
    {
        return new Rationnel(a->getChain(), reel);
    }
    else if(a->getType() == complexe)
    {
        return new Rationnel(a->getChain(), complexe, dynamic_cast<Complexe*>(a)->get_complexe_type_contenu());
    }
    else
        return NULL;
}

Reel* toReel(Constante* a)
{
    if(a->getType() == entier)
    {
        return new Reel(a->getChain(), entier);
    }
    else if(a->getType() == rationnel)
    {
        return new Reel(a->getChain(), rationnel);
    }
    else if(a->getType() == reel)
    {
        return new Reel(a->getChain(), reel);
    }
    else if(a->getType() == complexe)
    {
        return new Reel(a->getChain(), complexe, dynamic_cast<Complexe*>(a)->get_complexe_type_contenu());
    }
    else
        return NULL;
}

Complexe* toComplexe(Constante* a, const Type& T)
{
    if(a->getType() == entier)
    {
        return new Complexe(a->getChain(), entier, T);
    }
    else if(a->getType() == rationnel)
    {
        return new Complexe(a->getChain(), rationnel, T);
    }
    else if(a->getType() == reel)
    {
        return new Complexe(a->getChain(), reel, T);
    }
    else if(a->getType() == complexe)
    {
        return new Complexe(a->getChain(), complexe, T, dynamic_cast<Complexe*>(a)->get_complexe_type_contenu());
    }
    else
        return NULL;
}


Constante* addition(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b)
{
    if ((!isExpression(a->getChain())) && (!isExpression(b->getChain())))
    {
        switch(Mode)
        {
            case entier:
                return new Entier((*toEntier(a) + *toEntier(b)).getChain());
                break;
            case rationnel:
            {
                Rationnel* n= new Rationnel((*toRationnel(a) + *toRationnel(b)).getChain());
                n->simplifier();
                return n;
                break;
            }
            case reel:
                return new Reel((*toReel(a) + *toReel(b)).getChain());
                break;
            case complexe:
                return new Complexe((*toComplexe(a, Tcomplexe) + *toComplexe(b, Tcomplexe)).getChain(), Tcomplexe);
                break;
            default:
                return NULL;
                break;
        }
    }
    else if (!isExpression(a->getChain()))
    {
        /*Si seulement b est une expression*/
        string s = b->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + a->getChain() + " " + s + " +'");
    }
    else if (!isExpression(b->getChain()))
    {
        /* Seulement a est une expression */
        string s = a->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + s + " " + b->getChain() + " +'");
    }
    else
    {
        /*Les deux sont des expressions*/
        string sa = a->getChain();
        string sb = b->getChain();
        sa.erase(sa.length()-1,1);
        sb.erase(0,1);
        sb.erase(sb.length()-1,1);
        return new Expression(sa + " " + sb + " +'");
    }
}


Constante* soustraction(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b)
{
    if ((!isExpression(a->getChain())) && (!isExpression(b->getChain())))
    {
        switch(Mode)
        {
            case entier:
                return new Entier((*toEntier(b) - *toEntier(a)).getChain());
                break;
            case rationnel:
                {
                Rationnel* n= new Rationnel((*toRationnel(a) - *toRationnel(b)).getChain());
                n->simplifier();
                return n;
                break;
            }
            case reel:
                return new Reel((*toReel(b) - *toReel(a)).getChain());
                break;
            case complexe:
                return new Complexe((*toComplexe(b, Tcomplexe) - *toComplexe(a, Tcomplexe)).getChain(), Tcomplexe);
                break;
            default:
                return NULL;
                break;
        }
    }
    else if (!isExpression(a->getChain()))
    {
        /*Si seulement b est une expression*/
        string s = b->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + a->getChain() + " " + s + " -'");
    }
    else if (!isExpression(b->getChain()))
    {
        /* Seulement a est une expression */
        string s = a->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + s + " " + b->getChain() + " -'");
    }
    else
    {
        /*Les deux sont des expressions*/
        string sa = a->getChain();
        string sb = b->getChain();
        sa.erase(sa.length()-1,1);
        sb.erase(0,1);
        sb.erase(sb.length()-1,1);
        return new Expression(sa + " " + sb + " -'");
    }
}

Constante* multiplication(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b)
{
    if ((!isExpression(a->getChain())) && (!isExpression(b->getChain())))
    {
        switch(Mode)
        {
            case entier:
                return new Entier((*toEntier(a) * *toEntier(b)).getChain());
                break;
            case rationnel:
                {
                Rationnel* n= new Rationnel((*toRationnel(a) * *toRationnel(b)).getChain());
                n->simplifier();
                return n;
                break;
            }
            case reel:
                return new Reel((*toReel(a) * *toReel(b)).getChain());
                break;
            case complexe:
                return new Complexe((*toComplexe(a, Tcomplexe) * *toComplexe(b, Tcomplexe)).getChain(), Tcomplexe);
                break;
            default:
                return NULL;
                break;
        }
    }
    else if (!isExpression(a->getChain()))
    {
        /*Si seulement b est une expression*/
        string s = b->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + a->getChain() + " " + s + " *'");
    }
    else if (!isExpression(b->getChain()))
    {
        /* Seulement a est une expression */
        string s = a->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + s + " " + b->getChain() + " *'");
    }
    else
    {
        /*Les deux sont des expressions*/
        string sa = a->getChain();
        string sb = b->getChain();
        sa.erase(sa.length()-1,1);
        sb.erase(0,1);
        sb.erase(sb.length()-1,1);
        return new Expression(sa + " " + sb + " *'");
    }
}

Constante* div(const Type& Mode, const Type& Tcomplexe, Constante* a, Constante* b)
{
    if ((!isExpression(a->getChain())) && (!isExpression(b->getChain())))
    {
        switch(Mode)
        {
            case entier:
                return new Entier((*toEntier(a) / *toEntier(b)).getChain());
                break;
            case rationnel:
                {
                Rationnel* n= new Rationnel((*toRationnel(a) / *toRationnel(b)).getChain());
                n->simplifier();
                return n;
                break;
            }
            case reel:
                return new Reel((*toReel(a) / *toReel(b)).getChain());
                break;
            case complexe:
                return new Complexe((*toComplexe(a, Tcomplexe) / *toComplexe(b, Tcomplexe)).getChain(), Tcomplexe);
                break;
            default:
                return NULL;
                break;
        }
    }
    else if (!isExpression(a->getChain()))
    {
        /*Si seulement b est une expression*/
        string s = b->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + a->getChain() + " " + s + " /'");
    }
    else if (!isExpression(b->getChain()))
    {
        /* Seulement a est une expression */
        string s = a->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + s + " " + b->getChain() + " /'");
    }
    else
    {
        /*Les deux sont des expressions*/
        string sa = a->getChain();
        string sb = b->getChain();
        sa.erase(sa.length()-1,1);
        sb.erase(0,1);
        sb.erase(sb.length()-1,1);
        return new Expression(sa + " " + sb + " /'");
    }
}



Constante* pow(Constante* a, Constante* b, const Type& T)
{
    if ((!isExpression(a->getChain())) && (!isExpression(b->getChain())))
    {
        Reel* temp1 = toReel(a);
        Reel* temp2 = toReel(b);

        temp1->setVal(pow(temp1->getVal(), temp2->getVal()));

        if(T == entier)
            return toEntier(temp1);
        else if(T == rationnel)
        {
            Rationnel* n = toRationnel(temp1);
            n->simplifier();
            return n;
        }

        else
            return temp1;
    }
    else if (!isExpression(a->getChain()))
    {
        /*Si seulement b est une expression*/
        string s = b->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + a->getChain() + " " + s + " pow'");
    }
    else if (!isExpression(b->getChain()))
    {
        /* Seulement a est une expression */
        string s = a->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + s + " " + b->getChain() + " pow'");
    }
    else
    {
        /*Les deux sont des expressions*/
        string sa = a->getChain();
        string sb = b->getChain();
        sa.erase(sa.length()-1,1);
        sb.erase(0,1);
        sb.erase(sb.length()-1,1);
        return new Expression(sa + " " + sb + " pow'");
    }
}



Constante* mod(Constante* a, Constante* b)
{
    if ((!isExpression(a->getChain())) && (!isExpression(b->getChain())))
    {
        Entier* temp1 = toEntier(a);
        Entier* temp2 = toEntier(b);

        temp1->setVal(temp1->getVal() % temp2->getVal());
        return temp1;
    }
    else if (!isExpression(a->getChain()))
    {
        /*Si seulement b est une expression*/
        string s = b->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + a->getChain() + " " + s + " mod'");
    }
    else if (!isExpression(b->getChain()))
    {
        /* Seulement a est une expression */
        string s = a->getChain();
        s.erase(0,1);
        s.erase(s.length()-1,1);
        return new Expression("'" + s + " " + b->getChain() + " mod'");
    }
    else
    {
        /*Les deux sont des expressions*/
        string sa = a->getChain();
        string sb = b->getChain();
        sa.erase(sa.length()-1,1);
        sb.erase(0,1);
        sb.erase(sb.length()-1,1);
        return new Expression(sa + " " + sb + " mod'");
    }
}

Constante* cos(Constante* a, bool degre)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp = toReel(a);
        if(degre == false)
            temp->setVal(cos(temp->getVal()));
        else
            temp->setVal(cos(temp->getVal()*3.14159265/180));
        return temp;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " cos'");
    }
}

Constante* cosh(Constante* a)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp = toReel(a);
            temp->setVal(cosh(temp->getVal()));
        return temp;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " cosh'");
    }
}


Constante* sin(Constante* a, bool degre)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp = toReel(a);
        if(degre == false)
            temp->setVal(sin(temp->getVal()));
        else
            temp->setVal(sin(temp->getVal()*3.14159265/180));
        return temp;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " sin'");
    }
}


Constante* sinh(Constante* a)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp = toReel(a);
            temp->setVal(sinh(temp->getVal()));
        return temp;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " sinh'");
    }
}



Constante* tan(Constante* a, bool degre)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp = toReel(a);
        if(degre == false)
            temp->setVal(tan(temp->getVal()));
        else
            temp->setVal(tan(temp->getVal()*3.14159265/180));
        return temp;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " tan'");
    }
}


Constante* tanh(Constante* a)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp = toReel(a);
            temp->setVal(tanh(temp->getVal()));
        return temp;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " tanh'");
    }
}


Constante* fact(Constante* a)
{
    if (!isExpression(a->getChain()))
    {
        Entier* temp = toEntier(a);

        int n = temp->getVal();
        if(n < 0) return temp;
        int accu = 1;

        while(n != 0)
        {
            accu *= n;
            n -= 1;
        }

        temp->setVal(accu);
        return temp;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " fact'");
    }
}


Constante* log(Constante* a, const Type& T)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp1 = toReel(a);

        temp1->setVal(log10(temp1->getVal()));

        if(T == entier)
            return toEntier(temp1);
        else if(T == rationnel)
            return toRationnel(temp1);
        else
            return temp1;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " log'");
    }
}


Constante* ln(Constante*a, const Type& T)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp1 = toReel(a);

        temp1->setVal(log(temp1->getVal()));

        if(T == entier)
            return toEntier(temp1);
        else if(T == rationnel)
            {
            Rationnel* n = toRationnel(temp1);
            n->simplifier();
            return n;
            }
        else
            return temp1;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " ln'");
    }
}


Constante* sqrt(Constante*a, const Type& T)
{
    if (!isExpression(a->getChain()))
    {
        Reel* temp1 = toReel(a);

        temp1->setVal(sqrt(temp1->getVal()));

        if(T == entier)
            return toEntier(temp1);
        else if(T == rationnel)
            {
            Rationnel* n = toRationnel(temp1);
            n->simplifier();
            return n;
            }
        else
            return temp1;
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " sqrt'");
    }
}


Constante* sqr(Constante*a, const Type& T, const Type& Tcomplexe)
{
    if (!isExpression(a->getChain()))
    {
        return multiplication(T, Tcomplexe, a, a);
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " sqr'");
    }
}


Constante* cube(Constante*a, const Type& T, const Type& Tcomplexe)
{
    if (!isExpression(a->getChain()))
    {
        return multiplication(T, Tcomplexe, a, sqr(a, T, Tcomplexe));
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " cube'");
    }
}


Constante* inv(Constante* a, const Type& T)
{
   if (!isExpression(a->getChain()))
    {
        if(T == entier)
        {
            Reel* temp = toReel(a);
            temp->setVal(1 / temp->getVal());
            return toEntier(temp);
        }
        else if(T == rationnel)
        {
            Rationnel* temp = toRationnel(a);
            int i = temp->getNum()->getVal();
            temp->getNum()->setVal(temp->getDen()->getVal());
            temp->getDen()->setVal(i);
            temp->simplifier();
            return temp;
        }
        else{
            Reel* temp = toReel(a);
            temp->setVal(1/temp->getVal());
            return temp;
        }
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " inv'");
    }
}



Constante* sign(Constante*a, const Type& T, const Type& Tcomplexe)
{
    if (!isExpression(a->getChain()))
    {
        if(T == entier)
        {
            Entier* temp = toEntier(a);
            temp->setVal(-1 * temp->getVal());
            return temp;
        }
        else if(T == rationnel)
        {
            Rationnel* temp = toRationnel(a);
            temp->getNum()->setVal(-1 * temp->getNum()->getVal());
            return temp;
        }
        else if(T == reel)
        {
            Reel* temp = toReel(a);
            temp->setVal(-1 * temp->getVal());
            return temp;
        }
        else
        {
            Complexe* temp = toComplexe(a, Tcomplexe);
            temp->setReel(sign(temp->getReel(), Tcomplexe, Tcomplexe));
            temp->setIm(sign(temp->getIm(), Tcomplexe, Tcomplexe));
            return temp;
        }
    }
    else
    {
        string s1 = a->getChain();
        s1.erase(s1.length()-1,1);

       return new Expression(s1 + " sign'");
    }
}
