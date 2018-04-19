#ifndef ARBORE_H_INCLUDED
#define ARBORE_H_INCLUDED
#include <iostream>
#include "Node.h"
using namespace std;
class Arbore{
public:
    Arbore();
    Arbore(int);
    Arbore(Arbore&);
    ~Arbore();
    void insertArbore(int);
    Node*& getNode();
    void StergeNodDinArbore(int);
    void SRD(Node*&, ostream& cout);
    void Stergere();
    int InaltimeArbore(Node*);
    int FrunzeArbore(Node*, int);
    void Parcurgere(Arbore&,Node*);//Folosit doar pentru operatorul+
    void Parcurgere1(Arbore&,Node*,Node*);//Folosit doar pentru operatorul*
    void Parcurgere2(Arbore&,Node*,Node*);//Folosit doar pentru operatorul-
    void Parcurgere3(Node*); //Folosit doar pentru destructor(functia Stergere)
    Arbore operator-(Arbore&);
    Arbore operator*(Arbore&);
    Arbore operator+(Arbore&);
    int operator==(Arbore&);
    int operator!=(Arbore&);
    int operator<(Arbore&);
    friend ostream& operator<<(ostream&,Arbore&);
    friend istream& operator>>(istream&,Arbore&);
private:
    Node *nod;
};


#endif // ARBORE_H_INCLUDED
