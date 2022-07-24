#include <iostream>
#include "company.h"
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv) {
  ll arr;
  employee emp("steve",""),emp2("john",""),emp3("henry",""),emp4("jonathan","");
  employee *a=&emp,*b=&emp2,*c=&emp3;
  arr.insert("steve");
    cout<<arr.getSize()<<a->eName()<<endl;
  arr.insert("john");
    cout<<arr.getSize()<<b->eName()<<endl;
  arr.insert("henry");
    cout<<arr.getSize()<<c->eName()<<endl;
  arr.insert("alice");
  arr.insert("jonathan");
  arr.rename(2,"wfdaf");
  arr.swap("steve","jonathan"); 
  // always use swap in chrono order
  arr.printAll();

  cout<<arr.at(2).eName()<<" "<<arr.in("jonathan")<<endl;
  //cout<<arr.in()<<endl;
  return 0;
}
