#ifndef stack_h
#define  stack_h
#include "node.h"

class Stack{
private:
	 nodePtr top;
	int size;
public:
    Stack(nodePtr = NULL);
    ~Stack();
    void pop();
    void push(employee);
};

Stack::Stack(nodePtr n){
  if(n) {
    top=n;
    size=1;
  }
 else{
   top=NULL;
	 size=0;
   }
}
void Stack::push(employee e){
  nodePtr new_node=new node(e);
  if(new_node){
	 	  new_node->setNext(top);
      top=new_node;
     size++; 
   }
 else cout<<"No memory left for new nodes"<<endl;
}
void Stack::pop(){
 	  nodePtr n=top;
		employee* value;		//
	 if(n)	{
    top=top->getNext();
     value=n->getVal();
     delete n;
     size--;
     //return value;
     }
  cout<<"popping "<<value<<endl;
		//cout<<"Empty stack"<<endl;
	}
Stack::~Stack(){
   cout<<"Clearing all stacks"<<endl;
  	int i;
  nodePtr n=top;
  for(i=0;i<size;i++){
      n=top;
      top=top->getNext();
      delete n;
  }


}

#endif