#include "pile.h"

using namespace std;

Pile* Pile::instanceUnique = 0;

Pile& Pile::donneInstance()
{
    if(instanceUnique == 0)
        instanceUnique = new Pile;
    return *instanceUnique;
}

void Pile::libereInstance()
{
    if(instanceUnique != 0)
        delete instanceUnique;
    instanceUnique = 0;
}

Pile::Pile()
{
}

Pile::~Pile()
{
    if(instanceUnique != 0)
        delete instanceUnique;

    while(!p.empty())
    {
        delete p.top();
        p.pop();
    }
}

Constante* Pile::sommetPile()
{
    return p.top();
}

void Pile::pushPile(Constante* ptr)
{
    p.push(ptr);
}

Constante* Pile::popPile()
{
    if(!p.empty()){
    Constante* test = p.top();
    p.pop();
    return test;
    }
    else return NULL;
}
Constante* Pile::duplicate()
{
    Constante* temp = p.top();
    string s = temp->getChain();

    if(temp == NULL) return NULL;

    if(temp->getType() == entier)
    {
        Entier* Dup = new Entier(s);
        return Dup;
    }
    else if(temp->getType() == rationnel)
    {
        Rationnel* Dup = new Rationnel(s);
        return Dup;
    }
    else if(temp->getType() == reel)
    {
        Reel* Dup = new Reel(s);
        return Dup;
    }
    else
    {
        Complexe* temp2 = dynamic_cast<Complexe*>(temp);
        Complexe* Dup = new Complexe(s, temp2->get_complexe_type_contenu());
        return Dup;
    }
}
void Pile::dropPile()
{
    while(!p.empty())
    {
        p.pop();
    }
}

void Pile::swap(int i, int j)
{
    vector<Constante*> tab;

    for(int k = 0; k < j; k++)
    {
        tab.push_back(sommetPile());
        p.pop();
    }

    Constante* t = tab.at(i-1);
    tab[i-1] = tab[j-1];
    tab[j-1] = t;

    for(int k =0; k < j; k++)
    {
        p.push(tab[j - k - 1]);
        tab.pop_back();
    }
}
