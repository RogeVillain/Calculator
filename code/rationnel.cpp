#include "rationnel.h"
#include "math.h"

using namespace std;

Rationnel::Rationnel(const std::string& val) : numerateur(new Entier("0")), denominateur( new Entier("0"))
{
    buildConstant(val);
    genre = rationnel;
}

Rationnel::Rationnel (const Rationnel & a)
{
    genre = a.genre;
    numerateur = new Entier(a.getNum()->getChain());
    denominateur = new Entier(a.getDen()->getChain());
}

std::string Rationnel::getChain() const
{
    stringstream ss;
    ss << numerateur->getChain() << "/" << denominateur->getChain();

    return ss.str();
}

void Rationnel::buildConstant(const std::string& val)
{
    int i = val.find_first_of('/');
   numerateur->setVal(atoi(val.substr(0, i).c_str()));
   denominateur->setVal(atoi(val.substr(i+1).c_str()));
}

Rationnel::Rationnel(const std::string& val, const Type& T1, const Type& T2) : numerateur(new Entier("0")), denominateur(new Entier("0"))
{
    if(T1 == rationnel)
    {
        buildConstant(val);
        genre = rationnel;
    }
    else if(T1 == entier)
    {
        numerateur->setVal(atoi(val.c_str()));
        denominateur->setVal(1);
        genre = rationnel;
    }
    else if(T1 == reel)
    {
        int j;
        float i = atof(val.c_str());
        int temp1;
        float temp2;

        for(j = 0; j <= 5; j++)
        {
            temp1 = floor(i);
            temp2 = i - temp1;
            if(temp2 > 0)
                   i *= 10;
            else
                break;
        }

        temp2 = 1;

        for(int k = j; k > 0; k--)
            temp2 *= 10;

        temp1 = floor(i);
        numerateur->setVal(temp1);
        denominateur->setVal(temp2);
        genre = rationnel;

    }
    else if(T1 == complexe)
    {
        int i = val.find_first_of('$');
        string re = val.substr(0, i);

        Rationnel temp(re, T2);
        numerateur->setVal(temp.getNum_int());
        denominateur->setVal(temp.getDen_int());
        genre = entier;
    }
}
Rationnel& Rationnel::operator+=(Rationnel const& e)
{
   numerateur->setVal(numerateur->getVal()*e.denominateur->getVal() + e.numerateur->getVal()*denominateur->getVal());
   denominateur->setVal(denominateur->getVal()*e.denominateur->getVal());
   return *this;
}
Rationnel& Rationnel::operator-=(Rationnel const& e)
{
   numerateur->setVal(numerateur->getVal()*e.denominateur->getVal() - e.numerateur->getVal()*denominateur->getVal());
   denominateur->setVal(denominateur->getVal()*e.denominateur->getVal());
   return *this;
}
Rationnel& Rationnel::operator*=(Rationnel const& e)
{
   numerateur->setVal(numerateur->getVal() * e.numerateur->getVal());
   denominateur->setVal(denominateur->getVal()*e.denominateur->getVal());
   return *this;
}
Rationnel& Rationnel::operator/=(Rationnel const& e)
{
   numerateur->setVal(numerateur->getVal() * e.denominateur->getVal());
   denominateur->setVal(denominateur->getVal()*e.numerateur->getVal());
   return *this;
}
Rationnel operator+(Rationnel const& a, Rationnel const& b)
{
    Rationnel temp(a);
    temp += b;
    return temp;
}
Rationnel operator-(Rationnel const& a, Rationnel const& b)
{
    Rationnel temp(a);
    temp -= b;
    return temp;
}
Rationnel operator*(Rationnel const& a, Rationnel const& b)
{
    Rationnel temp(a);
    temp *= b;
    return temp;
}
Rationnel operator/(Rationnel const& a, Rationnel const& b)
{
    Rationnel temp(a);
    temp /= b;
    return temp;
}
int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}


void Rationnel::simplifier()
{

        int tmp2 = numerateur->getVal();
        int tmp3 = denominateur->getVal();
    if (tmp2 < 0) tmp2*=-1;
        if (tmp3 < 0) tmp3*=-1;

        int tmp = pgcd(tmp2, tmp3);

        if (tmp != 1)
        {
                numerateur->setVal(numerateur->getVal() / tmp);
                denominateur->setVal(denominateur->getVal() / tmp);
        }

        if (denominateur->getVal() < 0)
        {
        denominateur->setVal(denominateur->getVal() * -1);
        numerateur->setVal(numerateur->getVal() * -1);
        }

}
