#ifndef node_h
#define node_h
#include "employee.h"

class node {
  private:
    node* next;
    employee* emp;
  public:
    node(string e) {emp = new employee(e,""); next = NULL;}
    ~node() {}
    void setNext(node* n) {next = n;}
    node* getNext() {return next;}
    employee getVal() {return *emp;}
    void rename(string s) {emp->rename(s);}
    void resalary(float f) {emp->resalary(f);}
    void reYIS(int n) {emp->reYIS(n);}
    void relevel(string s) {emp->relevel(s);}
};
typedef node* nodePtr;

#endif