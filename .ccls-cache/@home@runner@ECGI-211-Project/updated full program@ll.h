#ifndef LL_h
#define LL_h
#include "node.h"

class ll {
  private:
    nodePtr hol;
    int size = 0;
  public:
    ll() {
      size=0;
      hol=NULL;
    }

    void insert(string emp) {
      nodePtr currentPtr=hol,newPtr = new node(emp);
      if(newPtr == NULL) cout<<"FAIL"<<endl;
        if(hol==NULL) {
          hol = newPtr;
          cout<<emp<<" added"<<endl;
        }
        else {
          while(currentPtr->getNext()!=NULL)  currentPtr=currentPtr->getNext();
          
          currentPtr->setNext(newPtr);
          cout<<emp<<" added"<<endl;
        }
      size++;
    }
    int remove(string empName)  {
      nodePtr current=hol,prev,temp;
      for(int i=0;i<size;i++) {
        if(current->getVal().eName()==empName) {
          if(i==0) {
            temp=hol;
            hol=hol->getNext();
            delete temp;
          } else if(i==size-1) {
            temp=current;
            prev->setNext(NULL);
            delete temp;
          } else {
          temp = current;
          prev->setNext(current->getNext());
          delete temp;
          }
          size--;
          return 1;
        }
        prev=current;
        current=current->getNext();    
      }
      return 0;
    }
    bool in(string n) {
      nodePtr currentPtr=hol;
      while(currentPtr!=NULL) {
        if(currentPtr->getVal().eName()==n) return true;
        currentPtr=currentPtr->getNext();
      }
      return false;
    }
    void swap(string name1,string name2) {
      int check=0;
      nodePtr currentPtr=hol,prevPtr,prevTemp1,currentTemp1,prevTemp2,currentTemp2,prevT,t;
      while(currentPtr!=NULL) {
        if(currentPtr->getVal().eName() == name1) {
          currentTemp1=currentPtr;
          prevTemp1=prevPtr;
          check++;
        }
        else if(currentPtr->getVal().eName() == name2) {
          currentTemp2=currentPtr; 
          prevTemp2=prevPtr;
          check++;
        }
        prevPtr = currentPtr;
        currentPtr=currentPtr->getNext();
      }
      if(check!=2) cout<<"INVALID INPUT"<<endl;
      else {
        t=currentTemp2->getNext();
        if(hol==currentTemp1) hol=currentTemp2;
        else prevTemp1->setNext(currentTemp2);
    
        currentTemp2->setNext(currentTemp1->getNext());
        prevTemp2->setNext(currentTemp1);
        currentTemp1->setNext(t);
      }
      
    }
    int getSize() {return size;}

    void printAll() {
      nodePtr current=hol;
      while(hol!=NULL) {
        cout<<"hi"<<endl;
        cout<<hol->getVal().eName()<<endl;
        hol=hol->getNext();
      }
      hol=current;
    }
    employee emp(string empName) {
      nodePtr currentPtr=hol;
      while(currentPtr->getNext()) {
        if(empName==currentPtr->getVal().eName()) return currentPtr->getVal();
        currentPtr=currentPtr->getNext();
      }
    }

    employee at(int n) {
      nodePtr currentPtr = hol;
      for(int i=0;i<n;i++) currentPtr=currentPtr->getNext();
      return currentPtr->getVal();
    }

    void rename(int emp,string n) {
      nodePtr current=hol;
      for(int i=0;i<emp;i++) current=current->getNext();
      current->getVal().rename(n);
    }
    
};


#endif
