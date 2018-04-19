#include "Arbore.h"
Arbore::Arbore() {
    nod = NULL;
}
Arbore::Arbore(int x) {
    nod = new Node(x);
}
Arbore::Arbore(Arbore& copiere){
    nod = NULL;
    Parcurgere(*this,copiere.nod);
}
Arbore::~Arbore() {
    Stergere();
    nod = NULL;
}
void Arbore::insertArbore(int x) {
    Node *nod1=nod;
    if(nod==NULL)
        nod=new Node(x);
    else while(1) {
            if(nod1->info>=x) {
                if(nod1->st!=NULL)
                    nod1=nod1->st;
                else if(nod1->st==NULL) {
                    nod1->st=new Node(x);
                    break;
                }
            } else if(nod1->info<x) {
                if(nod1->dr!=NULL)
                    nod1=nod1->dr;
                else if(nod1->dr==NULL) {
                    nod1->dr=new Node(x);
                    break;
                }
            }
        }
}
void Arbore::StergeNodDinArbore(int x) {
    int OK1,OK2;
    Node *q=nod,*q1,*q2;
    if(nod->info==x) {
        nod=nod->dr;
        q1=nod;
        while(q1->st!=NULL)
            q1=q1->st;
        q1->st=q->st;
        delete q;
    } else {
        while(q!=NULL) {
            q1=q;
            if(q->info>x && q->st!=NULL) {
                q=q->st;
                OK1=1;
                OK2=0;
            } else if(q->info<x && q->dr!=NULL) {
                q=q->dr;
                OK1=0;
                OK2=1;
            }
            if(q->info==x)
                break;
        }
        if(q->dr==NULL && q->st==NULL && OK1==1) {
            q1->st=NULL;
            delete q;
        } else if(q->dr==NULL && q->st==NULL && OK2==1) {
            q1->dr=NULL;
            delete q;
        } else if(q->dr==NULL && q->st!=NULL && OK1==1) {
            q1->st=q->st;
            delete q;
        } else if(q->dr==NULL && q->st!=NULL && OK2==1) {
            q1->dr=q->st;
            delete q;
        } else if(q->dr!=NULL && q->st==NULL && OK1==1) {
            q1->st=q->dr;
            delete q;
        } else if(q->dr!=NULL && q->st==NULL && OK2==1) {
            q1->dr=q->dr;
            delete q;
        } else {
            q2=q->dr;
            while(q2!=NULL && q2->st!=NULL)
                q2=q2->st;
            q1->dr=q->dr;
            if(q2!=NULL)
                q2->st=q->st;
            delete q;
        }
    }
}
void Arbore::Stergere() {
    Parcurgere3(this->nod);
}
void Arbore::SRD(Node*& nod, ostream& cout) {
 if(nod!=NULL){
    SRD(nod->st,cout);
    cout<<nod->info<<' ';
    SRD(nod->dr,cout);
 }
}
void Arbore::Parcurgere(Arbore& a,Node* nod) { //Folosit doar pentru operatorul+
    if(nod!=NULL){
        a.insertArbore(nod->info);
        if(nod->st!=NULL)
            Parcurgere(a,nod->st);
        if(nod->dr!=NULL)
            Parcurgere(a,nod->dr);
    }
}
void Arbore::Parcurgere1(Arbore& a,Node* nod,Node* nod1){ //Folosit doar pentru operatorul*
    static Node *q=nod1;
    if(nod!=NULL && nod1!=NULL)
    {while(nod1!=NULL && nod->info!=nod1->info)
    {
        if(nod1->dr!=NULL && nod->info>nod1->info)
        nod1=nod1->dr;
        else if(nod1->st!=NULL && nod->info<nod1->info)
        nod1=nod1->st;
        else break;
    }
    if(nod->info==nod1->info)
    a.insertArbore(nod->info);
    nod1=q;
    if(nod->st!=NULL)
    Parcurgere1(a,nod->st,nod1);
    if(nod->dr!=NULL)
    Parcurgere1(a,nod->dr,nod1);
    }
}
void Arbore::Parcurgere2(Arbore& a,Node* nod,Node* nod1){ //Folosit doar pentru operatorul-
    static Node *q=nod1;
    if(nod!=NULL && nod1!=NULL)
    {while(nod1!=NULL && nod->info!=nod1->info)
    {
        if(nod1->dr!=NULL && nod->info>nod1->info)
            nod1=nod1->dr;
        else if(nod1->st!=NULL && nod->info<nod1->info)
            nod1=nod1->st;
        else break;
    }
    if(nod->info!=nod1->info)
        a.insertArbore(nod->info);
    nod1=q;
    if(nod->st!=NULL)
        Parcurgere2(a,nod->st,nod1);
    if(nod->dr!=NULL)
        Parcurgere2(a,nod->dr,nod1);
    }
}
void Arbore::Parcurgere3(Node* nod) { //Folosit doar pentru destructor
     if(nod!=NULL){
        if(nod->st!=NULL){
             Parcurgere3(nod->st);
             delete nod;
        }
        if(nod->dr!=NULL){
            Parcurgere3(nod->dr);
            delete nod;
        }
    }
}
int Arbore::InaltimeArbore(Node* nod) {
    if (nod==NULL)
        return 0;
    else {
        int lDepth = InaltimeArbore(nod->st);
        int rDepth = InaltimeArbore(nod->dr);
        if (lDepth > rDepth)
            return(lDepth+1);
        else return(rDepth+1);
    }
}
int Arbore::FrunzeArbore(Node* nod,int k = 0) {
    if (nod) {
        if(nod->st==NULL && nod->dr==NULL)
            k++;
        FrunzeArbore(nod->st,k);
        FrunzeArbore(nod->dr,k);
    }
    return k;
}
Node*& Arbore::getNode() {
    return nod;
}

Arbore Arbore::operator+(Arbore& a) {
    Arbore b;
    Node* q=this->nod,*q1=a.nod;
    Parcurgere(b,q);
    Parcurgere(b,q1);
    return b;
}
Arbore Arbore::operator*(Arbore& a) {
    Arbore b;
    Node* q=this->nod,*q1=a.nod;
    Parcurgere1(b,q,q1);
    return b;
}
Arbore Arbore::operator-(Arbore& a) {
    Arbore b;
    Node* q=this->nod,*q1=a.nod;
    Parcurgere2(b,q,q1);
    return b;
}
int Arbore::operator==(Arbore& a) {
    int inaltime1 = InaltimeArbore(this->nod);
    int inaltime2 = InaltimeArbore(a.nod);
    if(inaltime1 == inaltime2)
    return 1;
    else return 0;
}
int Arbore::operator!=(Arbore& a) {
    int inaltime1 = InaltimeArbore(this->nod);
    int inaltime2 = InaltimeArbore(a.nod);
    if(inaltime1 != inaltime2)
    return 1;
    else return 0;
}
int Arbore::operator<(Arbore& a) {
    int inaltime1 = InaltimeArbore(this->nod);
    int inaltime2 = InaltimeArbore(a.nod);
    if(inaltime1 < inaltime2)
    return 1;
    else return 0;
}
ostream& operator<<(ostream& stream, Arbore& a){
   a.SRD(a.getNode(), stream);
   return stream;
}
istream& operator>>(istream& stream,Arbore& a)
{
    int x=0;
    stream>>x;
    a.insertArbore(x);
    return stream;
}
