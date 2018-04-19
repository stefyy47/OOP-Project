#include "Node.h"
Node::Node() {
    info=0;
    st=dr=NULL;
}
Node::Node(int newInfo) {
    info=newInfo;
    st=dr=NULL;
}
Node::Node(Node& copiere) {
    this->info = copiere.info;
    if(copiere.st != NULL)
        this->st = new Node(copiere.st->info);
    if(copiere.dr != NULL)
        this->dr = new Node(copiere.dr->info);
}
Node::~Node() {
    delete st;
    delete dr;
}
void Node::setInfo(int newInfo) {
    info=newInfo;
}
void Node::setStanga(Node& newNode) {
    st=&newNode;
}
void Node::setDreapta(Node& newNode) {
    dr=&newNode;
}
int Node::getInfo() const {
    return info;
}
Node* Node::getStanga() const {
    return st;
}
Node* Node::getDreapta() const {
    return dr;
}
