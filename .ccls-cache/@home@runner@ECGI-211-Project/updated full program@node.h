#ifndef node_h
#define node_h
class node {
  private:
    node* next;
    employee* emp;
  public:
    node(string e) {emp = new employee(e,""); next = NULL;}
    //~node() {cout<<"deleting "<<emp->eName()<<endl;}
    void setNext(node* n) {next = n;}
    node* getNext() {return next;}
    employee getVal() {return *emp;}
  
};
typedef node* nodePtr;

#endif