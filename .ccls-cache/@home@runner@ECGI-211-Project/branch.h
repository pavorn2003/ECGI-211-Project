#include "ll.h"
#include <vector>
#include <iomanip>


string eNameCap(string x) {
  string Cap;
  Cap.push_back(toupper(x[0]));
  return Cap;
}

class branch {
  private:
    string location;
    int branchSize;
    float sales; 
    ll personnels;
  public:
    branch(string = "InputNewName",int = 3,float = 0);
    bool addEmployee(string);
    void removeEmployee(string);
    string getLo();
    employee getEmp(string);
    employee getEmp(int);
    employee getSortedEmp(int);
    void relocate(string); 
    void resize(int);
    void name(string);
    void sort(string);
    int size();
    int currentSize();
    float sale();
    bool checkEmployee(string);
    void rename(int,string);
    void resalary(int,float);
    void reYIS(int,int);
    void relevel(int,string);
    void print(int,string);
    void SumOption();
    void SumPerOption();
    void clearSort();
    void popLast();
};

branch::branch(string location, int branchSize, float sales) {
  this->location = location;
  this-> branchSize = branchSize;
  this-> sales = sales;
}

bool branch::addEmployee(string e) {
  if(personnels.getSize() == branchSize) {
    return false;
  }
  else {
    personnels.insert(e);
    return true;
  }
}

void branch::removeEmployee(string e) {personnels.remove(e);}

employee branch::getEmp(string n) { 
  for(int i =0;i<branchSize;i++) if(personnels.at(i).eName()==n) return personnels.at(i);
  return personnels.at(0); //we added to clear the error dk if it works
}

employee branch::getEmp(int n) {return personnels.at(n-1);}

bool branch::checkEmployee(string n) {
  if(personnels.getSize()==0) return false;
  return personnels.in(n);
}

void branch::relocate(string n) {location = n;}

void branch::resize(int n) {branchSize = n;}

void branch::name(string n) {location = n;}

int branch::size() { return branchSize;}

int branch::currentSize() { return personnels.getSize();}

float branch::sale() {return this->sales;}

string branch::getLo() {return location;}
  
void branch::sort(string valueSort){
  for(int i=0;i<personnels.getSize()-1;i++){
    for(int j=0; j<personnels.getSize()-i-1; j++) {
        if(valueSort=="salary") {if(personnels.at(j+1).eSalary()>personnels.at(j).eSalary()) personnels.swap(personnels.at(j).eName(),personnels.at(j+1).eName());} 
        else if(valueSort=="year") {if(personnels.at(j+1).eYear()>personnels.at(j).eYear()) personnels.swap(personnels.at(j).eName(),personnels.at(j+1).eName());  }
        else if(valueSort=="name") {if(personnels.at(j+1).eName()<personnels.at(j).eName()) personnels.swap(personnels.at(j).eName(),personnels.at(j+1).eName());}
    }
  }
}

void branch::rename(int emp,string n){personnels.rename(emp,n);}

void branch::resalary(int emp,float n){personnels.resalary(emp,n);}

void branch::reYIS(int emp, int n){personnels.reYIS(emp,n);}

void branch::relevel(int emp,string n){personnels.relevel(emp,n);}

void branch::popLast() {personnels.pop();}

void branch::SumPerOption() {
      
      cout<<"------------------------------------------------"<<endl;
      cout<<"|============== Summarize Branch ==============|"<<endl;
      cout<<"------------------------------------------------"<<endl;
      cout<<"|    Name    |    Position    | Years | Salary |"<<endl;
      cout<<"------------------------------------------------"<<endl;
  
      for(int i=0;i<personnels.getSize();i++){  
        if(personnels.getSize()==0)break; 
        cout<<"| "<< left << setw(10) << setfill(' ') <<  personnels.at(i).eName() << " | " << left<< setw(14) <<  personnels.at(i).ePosition() << " | " << left << setw(5) <<personnels.at(i).eYear() << " | " << left << setw(6) <<personnels.at(i).eSalary() << " |" <<endl;    
      }
      cout<<"------------------------------------------------"<<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 1. Sort by Name"<< " |"<<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 2. Sort by Year In Service"<< " |" <<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 3. Sort by Salary" << " |" <<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 0. Back" << " |" <<endl;
      cout<<"------------------------------------------------"<<endl;
    }
