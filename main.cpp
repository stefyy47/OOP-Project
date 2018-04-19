#include <iostream>
#include "Arbore.h"

using namespace std;

int main()
{
    Arbore *a;
    Arbore b;
    Arbore c;
    Arbore d;
    Arbore e;
    Arbore k;
    a = new Arbore();
    a->insertArbore(2);
    a->insertArbore(3);
    a->insertArbore(4);
    a->insertArbore(5);
    a->insertArbore(6);
    a->insertArbore(1);
    b.insertArbore(10);
    b.insertArbore(20);
    Arbore f(*a);
    Arbore g(b);
    c = *a + b;
    d = *a * b;
    *a = *a + b;
    cout<<c<<endl;
    cout<<*a<<endl;



    return 0;
}
