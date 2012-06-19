#include "complexe.h"

using namespace std;

Complexe::Complexe(const std::string& val, const Type& T) : _reel(), _img()
{
    genre = complexe;
    complexe_type_contenu = T;
    buildConstant(val);
}

Complexe::Complexe(const Complexe & a)
{
    complexe_type_contenu = a.complexe_type_contenu;
    genre = a.genre;

    switch(a.complexe_type_contenu)
    {
        case entier:{
            _reel = new Entier(a.getReel()->getChain());
            _img = new Entier(a.getIm()->getChain());
            break;
        }
        case rationnel:{
            _reel = new Rationnel(dynamic_cast<Rationnel*>(a.getReel())->getChain());
            _img = new Rationnel(dynamic_cast<Rationnel*>(a.getIm())->getChain());
            break;
        }
        case reel:{
            _reel = new Reel(a.getReel()->getChain());
            _img = new Reel(a.getIm()->getChain());
            break;
        }
    default:
        break;
    }
}

std::string Complexe::getChain() const
{
    stringstream ss;

    switch(complexe_type_contenu)
    {
        case entier:{
            Entier* temp1 = dynamic_cast<Entier*>(_reel);
            Entier* temp2 = dynamic_cast<Entier*>(_img);
            ss << temp1->getChain() << "$" << temp2->getChain();
            break;}

        case reel:{
            Reel* temp1 = dynamic_cast<Reel*>(_reel);
            Reel* temp2 = dynamic_cast<Reel*>(_img);
            ss << temp1->getChain() << "$" << temp2->getChain();
            break;}

        case rationnel:{
            Rationnel* temp1 = dynamic_cast<Rationnel*>(_reel);
            Rationnel* temp2 = dynamic_cast<Rationnel*>(_img);
            ss << temp1->getChain() << "$" << temp2->getChain();
            break;}
    default:
        break;
    }

    return ss.str();
}

Complexe::~Complexe()
{
    delete _reel;
    delete _img;
}

void Complexe::buildConstant(const std::string& val)
{
    int i = val.find_first_of('$');
    string temp1 = val.substr(0, i);
    string temp2 = val.substr(i+1);

    if(complexe_type_contenu == entier)
    {
        _reel = new Entier(temp1);
        _img = new Entier(temp2);
    }
    else if(complexe_type_contenu == rationnel)
    {
        Rationnel* n = new Rationnel(temp1);
                n->simplifier();
                _reel = n;

                Rationnel* n2 = new Rationnel(temp2);
                n2->simplifier();
                _img = n2;
    }
    else if(complexe_type_contenu == reel)
    {
        _reel = new Reel(temp1);
        _img = new Reel(temp2);
    }
}

Complexe::Complexe(const std::string& val, const Type& T, const Type& Tvoulu, const Type& Torigine) : _reel(), _img()
{
    if(Torigine == complexe) exit(12);

    if(T == rationnel)
    {
        switch(Tvoulu)
        {
            case entier:{
                complexe_type_contenu = entier;
                Entier* temp1 = new Entier(val, rationnel);
                Entier* temp2= new Entier("0");
                _reel = temp1;
                _img = temp2;
                break;}

            case reel:{
                complexe_type_contenu = reel;
                Reel* temp1 = new Reel(val, rationnel);
                Reel* temp2 = new Reel("0");
                _reel = temp1;
                _img = temp2;
                break;}

            case rationnel:{
                complexe_type_contenu = rationnel;
                Rationnel* temp3= new Rationnel(val);
                Rationnel* temp4 = new Rationnel("0");
                temp3->simplifier();
                temp4->simplifier();
                _reel = temp3;
                _img = temp4;
                break;}
        default:
            break;
        }

        genre = complexe;
    }
    else if(T == entier)
    {
        switch(Tvoulu)
        {
            case entier:{
                complexe_type_contenu = entier;
                Entier* temp1 = new Entier(val);
                Entier* temp2= new Entier("0");
                _reel = temp1;
                _img = temp2;
                break;}

            case reel:{
                complexe_type_contenu = reel;
                Reel* temp3 = new Reel(val, entier);
                Reel* temp4 = new Reel("0");
                _reel = temp3;
                _img = temp4;
                break;}

            case rationnel:{
                complexe_type_contenu = rationnel;
                Rationnel* temp3= new Rationnel(val, entier);
                Rationnel* temp4 = new Rationnel("0");
                temp3->simplifier();
                temp4->simplifier();
                _reel = temp3;
                _img = temp4;
                break;}
        default:
            break;
        }

        genre = complexe;
    }
    else if(T == reel)
    {
        switch(Tvoulu)
        {
            case entier:{
                complexe_type_contenu = entier;
                Entier* temp1 = new Entier(val, reel);
                Entier* temp2= new Entier("0");
                _reel = temp1;
                _img = temp2;
                break;}

            case reel:{
                complexe_type_contenu = reel;
                Reel* temp3 = new Reel(val);
                Reel* temp4 = new Reel("0");
                _reel = temp3;
                _img = temp4;
                break;}

            case rationnel:{
                complexe_type_contenu = rationnel;
                Rationnel* temp3= new Rationnel(val, reel);
                Rationnel* temp4 = new Rationnel("0");
                temp3->simplifier();
                temp4->simplifier();
                _reel = temp3;
                _img = temp4;
                break;}
        default:
            break;
        }

        genre = complexe;
    }
    else if(T == complexe)
    {
        int i = val.find_first_of('$');
        string temp1 = val.substr(0, i);
        string temp2 = val.substr(i+1);

        switch(Tvoulu)
        {
            case entier:{
                complexe_type_contenu = entier;
                Entier* temp3 = new Entier(temp1, Torigine);
                Entier* temp4 = new Entier(temp2, Torigine);
                _reel = temp3;
                _img = temp4;
                break;}

            case reel:{
                complexe_type_contenu = reel;
                Reel* temp3 = new Reel(temp1, Torigine);
                Reel* temp4 = new Reel(temp2, Torigine);
                _reel = temp3;
                _img = temp4;
                break;}

            case rationnel:{
                complexe_type_contenu = rationnel;
                Rationnel* temp3 = new Rationnel(temp1, Torigine);
                Rationnel* temp4 = new Rationnel(temp2, Torigine);
                temp3->simplifier();
                temp4->simplifier();
                _reel = temp3;
                _img = temp4;
                break;}
        default:
            break;
        }

        genre = complexe;
    }
}
Complexe& Complexe::operator+=(Complexe const& e)
{
    if(complexe_type_contenu == entier)
    {
        Entier* temp1 = dynamic_cast<Entier*>(_reel);
        Entier* temp2 = dynamic_cast<Entier*>(_img);
        Entier* temp3 = dynamic_cast<Entier*>(e.getReel());
        Entier* temp4 = dynamic_cast<Entier*>(e.getIm());

        temp1->setVal(temp1->getVal() + temp3->getVal());
        temp2->setVal(temp2->getVal() + temp4->getVal());
    }
    else if(complexe_type_contenu == rationnel)
    {
        Rationnel* temp1 = dynamic_cast<Rationnel*>(_reel);
        Rationnel* temp2 = dynamic_cast<Rationnel*>(_img);
        Rationnel* temp3 = dynamic_cast<Rationnel*>(e.getReel());
        Rationnel* temp4 = dynamic_cast<Rationnel*>(e.getIm());

        temp1->getNum()->setVal(temp1->getNum()->getVal()*temp3->getDen()->getVal() + temp3->getNum()->getVal()*temp1->getDen()->getVal());
        temp1->getDen()->setVal(temp1->getDen()->getVal() * temp3->getDen()->getVal());

        temp2->getNum()->setVal(temp2->getNum()->getVal()*temp4->getDen()->getVal() + temp4->getNum()->getVal()*temp2->getDen()->getVal());
        temp2->getDen()->setVal(temp2->getDen()->getVal() * temp4->getDen()->getVal());

        temp1->simplifier();
        temp2->simplifier();
    }
    else if(complexe_type_contenu == reel)
    {
        Reel* temp1 = dynamic_cast<Reel*>(_reel);
        Reel* temp2 = dynamic_cast<Reel*>(_img);
        Reel* temp3 = dynamic_cast<Reel*>(e.getReel());
        Reel* temp4 = dynamic_cast<Reel*>(e.getIm());

        temp1->setVal(temp1->getVal() + temp3->getVal());
        temp2->setVal(temp2->getVal() + temp4->getVal());
    }

    return *this;
}
Complexe& Complexe::operator-=(Complexe const& e)
{
    if(complexe_type_contenu == entier)
    {
        Entier* temp1 = dynamic_cast<Entier*>(_reel);
        Entier* temp2 = dynamic_cast<Entier*>(_img);
        Entier* temp3 = dynamic_cast<Entier*>(e.getReel());
        Entier* temp4 = dynamic_cast<Entier*>(e.getIm());

        temp1->setVal(temp3->getVal() - temp1->getVal());
        temp2->setVal(temp4->getVal() - temp2->getVal());
    }
    else if(complexe_type_contenu == rationnel)
    {
        Rationnel* temp1 = dynamic_cast<Rationnel*>(_reel);
        Rationnel* temp2 = dynamic_cast<Rationnel*>(_img);
        Rationnel* temp3 = dynamic_cast<Rationnel*>(e.getReel());
        Rationnel* temp4 = dynamic_cast<Rationnel*>(e.getIm());

        temp1->getNum()->setVal(temp3->getNum()->getVal()*temp1->getDen()->getVal() - temp1->getNum()->getVal()*temp3->getDen()->getVal());
        temp1->getDen()->setVal(temp1->getDen()->getVal() * temp3->getDen()->getVal());

        temp2->getNum()->setVal(temp4->getNum()->getVal()*temp2->getDen()->getVal() - temp2->getNum()->getVal()*temp4->getDen()->getVal());
        temp2->getDen()->setVal(temp2->getDen()->getVal() * temp4->getDen()->getVal());

        temp1->simplifier();
        temp2->simplifier();
    }
    else if(complexe_type_contenu == reel)
    {
        Reel* temp1 = dynamic_cast<Reel*>(_reel);
        Reel* temp2 = dynamic_cast<Reel*>(_img);
        Reel* temp3 = dynamic_cast<Reel*>(e.getReel());
        Reel* temp4 = dynamic_cast<Reel*>(e.getIm());

        temp1->setVal(temp3->getVal() - temp1->getVal());
        temp2->setVal(temp4->getVal() - temp2->getVal());
    }

    return *this;
}
Complexe& Complexe::operator*=(Complexe const& e)
{
    if(complexe_type_contenu == entier)
    {
        Entier* temp1 = dynamic_cast<Entier*>(_reel);
        Entier* temp2 = dynamic_cast<Entier*>(_img);
        Entier* temp3 = dynamic_cast<Entier*>(e.getReel());
        Entier* temp4 = dynamic_cast<Entier*>(e.getIm());
        int i = temp1->getVal();
        temp1->setVal((i * temp3->getVal()) - (temp2->getVal() * temp4->getVal()));
        temp2->setVal((i * temp4->getVal()) + (temp3->getVal() * temp2->getVal()));
    }
    else if(complexe_type_contenu == rationnel)
    {
        Rationnel* temp1 = dynamic_cast<Rationnel*>(_reel);
        Rationnel* temp2 = dynamic_cast<Rationnel*>(_img);
        Rationnel* temp3 = dynamic_cast<Rationnel*>(e.getReel());
        Rationnel* temp4 = dynamic_cast<Rationnel*>(e.getIm());

        int i = temp1->getNum()->getVal();
        int j = temp1->getNum()->getVal();

        temp1->getNum()->setVal(((temp1->getNum()->getVal()*temp3->getNum()->getVal()*temp2->getDen()->getVal()*temp4->getDen()->getVal() - temp2->getNum()->getVal()*temp4->getNum()->getVal()*temp1->getDen()->getVal()*temp3->getDen()->getVal())));
        temp1->getDen()->setVal((temp1->getDen()->getVal()*temp3->getDen()->getVal()*temp2->getDen()->getVal()*temp4->getDen()->getVal()));

        temp2->getNum()->setVal(((i*temp2->getNum()->getVal()*temp2->getDen()->getVal()*temp3->getDen()->getVal() + temp2->getNum()->getVal()*temp3->getNum()->getVal()*j*temp4->getDen()->getVal())));
        temp2->getDen()->setVal((temp1->getDen()->getVal()*temp3->getDen()->getVal()*temp2->getDen()->getVal()*temp4->getDen()->getVal()));

        temp1->simplifier();
        temp2->simplifier();
    }
    else if(complexe_type_contenu == reel)
    {
        Reel* temp1 = dynamic_cast<Reel*>(_reel);
        Reel* temp2 = dynamic_cast<Reel*>(_img);
        Reel* temp3 = dynamic_cast<Reel*>(e.getReel());
        Reel* temp4 = dynamic_cast<Reel*>(e.getIm());
        float i = temp1->getVal();
        temp1->setVal((i * temp3->getVal()) - (temp2->getVal() * temp4->getVal()));
        temp2->setVal((i * temp4->getVal()) + (temp3->getVal() * temp2->getVal()));
    }

    return *this;
}

Complexe& Complexe::operator/=(Complexe const& e)
{
    if(complexe_type_contenu == entier)
    {
        Entier* temp1 = dynamic_cast<Entier*>(_reel);
        Entier* temp2 = dynamic_cast<Entier*>(_img);
        Entier* temp3 = dynamic_cast<Entier*>(e.getReel());
        Entier* temp4 = dynamic_cast<Entier*>(e.getIm());
        int i = temp1->getVal();
        temp1->setVal(((i * temp3->getVal()) + (temp2->getVal() * temp4->getVal()))/(temp3->getVal()*temp3->getVal()+temp4->getVal()*temp4->getVal()));
        temp2->setVal(((i * temp4->getVal()) - (temp3->getVal() * temp2->getVal()))/(temp3->getVal()*temp3->getVal()+temp4->getVal()*temp4->getVal()));
    }
    else if(complexe_type_contenu == rationnel)
    {
        Rationnel* temp1 = dynamic_cast<Rationnel*>(_reel);
        Rationnel* temp2 = dynamic_cast<Rationnel*>(_img);
        Rationnel* temp3 = dynamic_cast<Rationnel*>(e.getReel());
        Rationnel* temp4 = dynamic_cast<Rationnel*>(e.getIm());

        int a = temp1->getNum()->getVal();
        int b = temp1->getDen()->getVal();
        int c = temp2->getNum()->getVal();
        int d = temp2->getDen()->getVal();
        int e = temp3->getNum()->getVal();
        int f = temp3->getDen()->getVal();
        int g = temp4->getNum()->getVal();
        int h = temp4->getDen()->getVal();

        int A=a*d*f*h;
        int B=c*b*f*h;
        int C=e*h*b*d;
        int D=g*f*b*d;
        temp1->getNum()->setVal(A*C+B*D);
        temp1->getDen()->setVal(C*C+D*D);
        temp2->getNum()->setVal(C*B-D*A);
        temp2->getDen()->setVal(C*C+D*D);
        /*temp1->getNum()->setVal(((i*temp3->getNum()->getVal()*temp2->getDen()->getVal()*temp4->getDen()->getVal() + temp2->getNum()->getVal()*temp4->getNum()->getVal()*temp1->getDen()->getVal()*temp3->getDen()->getVal())));
        temp1->getDen()->setVal((j*temp3->getDen()->getVal()*temp2->getDen()->getVal()*temp4->getDen()->getVal()));

        temp2->getNum()->setVal(((i*temp2->getNum()->getVal()*temp2->getDen()->getVal()*temp3->getDen()->getVal() - temp2->getNum()->getVal()*temp3->getNum()->getVal()*j*temp4->getDen()->getVal())));
        temp2->getDen()->setVal((j*temp3->getDen()->getVal()*temp2->getDen()->getVal()*temp4->getDen()->getVal()));
        */
        temp1->simplifier();
        temp2->simplifier();
    }
    else if(complexe_type_contenu == reel)
    {
        Reel* temp1 = dynamic_cast<Reel*>(_reel);
        Reel* temp2 = dynamic_cast<Reel*>(_img);
        Reel* temp3 = dynamic_cast<Reel*>(e.getReel());
        Reel* temp4 = dynamic_cast<Reel*>(e.getIm());
        float i = temp1->getVal();

        temp1->setVal(((i * temp3->getVal()) + (temp2->getVal() * temp4->getVal()))/(temp3->getVal()*temp3->getVal()+temp4->getVal()*temp4->getVal()));
        temp2->setVal(((i * temp4->getVal()) - (temp3->getVal() * temp2->getVal()))/(temp3->getVal()*temp3->getVal()+temp4->getVal()*temp4->getVal()));

    }

    return *this;
}



Complexe operator+(Complexe const& a, Complexe const& b)
{
        Complexe temp(a);
        temp += b;
        return temp;
}
Complexe operator-(Complexe const& a, Complexe const& b)
{
        Complexe temp(a);
        temp -= b;
        return temp;
}
Complexe operator*(Complexe const& a, Complexe const& b)
{
        Complexe temp(a);
        temp *= b;
        return temp;
}

Complexe operator/(Complexe const& a, Complexe const& b)
{
        Complexe temp(a);
        temp /= b;
        return temp;
}
