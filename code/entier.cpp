#include "entier.h"

using namespace std;

Entier::Entier(const std::string& val)
{
    buildConstant(val);
    genre = entier;
}
std::string Entier::getChain() const
{
    stringstream ss;
    ss << valeur;

    return ss.str();
}

void Entier::buildConstant(const std::string& val)
{
    valeur = atoi(val.c_str());
}

Entier::Entier(const std::string& val, const Type& T1, const Type& T2)
{
    if(T1 == rationnel)
    {
        int num, denom, i;
        i = val.find_first_of('/');
        num = atoi(val.substr(0, i).c_str());
        denom = atoi(val.substr(i+1).c_str());

        i = num / denom;

        valeur = i;
        genre = entier;
    }
    else if(T1 == reel || T1 == entier)
    {
        buildConstant(val);
        genre = entier;
    }
    else if(T1 == complexe)
    {
        int i = val.find_first_of('$');
        string re = val.substr(0, i);

        Entier temp(re, T2);
        valeur = temp.getVal();
        genre = entier;
    }
}

Entier& Entier::operator+=(Entier const& e)
{
    valeur += e.valeur;
    return *this;
}
Entier& Entier::operator-=(Entier const& e)
{
    valeur -= e.valeur;
    return *this;
}
Entier& Entier::operator*=(Entier const& e)
{
    valeur *= e.valeur;
    return *this;
}
Entier& Entier::operator/=(Entier const& e)
{
    valeur /= e.valeur;
    return *this;
}

Entier operator+(Entier const& a, Entier const& b)
{
    Entier temp(a);
    temp += b;
    return temp;
}
Entier operator-(Entier const& a, Entier const& b)
{
    Entier temp(a);
    temp -= b;
    return temp;
}
Entier operator*(Entier const& a, Entier const& b)
{
    Entier temp(a);
    temp *= b;
    return temp;
}
Entier operator/(Entier const& a, Entier const& b)
{
    Entier temp(a);
    temp /= b;
    return temp;
}

