#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
using namespace std;
class Node{
public:
    Node();
    Node(int);
    Node(Node&);
    ~Node();
    int getInfo() const;
    void setInfo(int);
    Node* getDreapta() const;
    Node* getStanga() const;
    void setStanga(Node&);
    void setDreapta(Node&);
    friend class Arbore;
private:
    int info;
    Node *st,*dr;
};


#endif // NODE_H_INCLUDED
