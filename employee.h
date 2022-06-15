#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;

string eNameCap(string x) {
  string Cap;
  Cap.push_back(toupper(x[0]));
  return Cap;
}

class employee {
  private:
    string name;
    string level;
    int yearInService;
    float salary;
    bool senior = false;
  public:
    employee(string="NA",int=0,string="intern",float=0);
    employee(string="NA",string="intern");
    string eName();
    string ePosition();
    float eSalary();
    int eYear();
    void rename(string);
    void resalary(float);
    void reYIS(int);
    void relevel(string);
};

employee::employee(string n, int y, string l, float s) {
  name = n;
  level = l;
  yearInService = y;
  salary = s;

  if(yearInService >= 3) senior = true;
}

employee::employee(string n, string l) {
  name = n;
  level = l;

  if(level == "intern") {
    salary = 0;
    yearInService =0;
  }
  if(yearInService >= 3) senior = true;
  
}

string employee::eName() {return name;}
string employee::ePosition() {return level;}
float employee::eSalary() {return salary;}
int employee::eYear() {return yearInService;}

void employee::rename(string n){name =n;}
void employee::resalary(float n){salary =n;}
void employee::reYIS(int n){yearInService = n;}
void employee::relevel(string n){level = n;}


class branch {
  private:
    string location;
    int branchSize;
    float sales; 
    vector<employee> personnel;
    vector<employee> sortedPersonnel;
  public:
    branch(string = "BKK",int = 3,float = 0);
    bool addEmployee(employee);
    void removeEmployee(employee);
    string getLo();
    employee getEmp(string);
    employee getEmp(int);
    employee getSortedEmp(int);
    void relocate(string); 
    void resize(int);
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
};
// every branch should have at least 1 person with at least 3 years of service.
// if branch does not make  $3000/month then personnel size decrease.
branch::branch(string location, int branchSize, float sales) {
  this->location = location;
  this-> branchSize = branchSize;
  this-> sales = sales;
}

bool branch::addEmployee(employee e) {
  if(personnel.size() == branchSize) {
    return false;
  }
  else {
    personnel.push_back(e);
    return true;
  }
}

void branch::removeEmployee(employee e) {
  int i; 
  if(personnel.size()==0) cout<<"No employee to remove."<<endl;
  else {
    for(i =0;i<personnel.size();i++)     if(personnel.at(i).eName()==e.eName()) break;
    personnel.erase(personnel.begin() + i);
  }
}

employee branch::getEmp(string n) {
  for(int i =0;i<branchSize;i++) {
    if(personnel.at(i).eName()==n) return personnel.at(i);
  }
}

employee branch::getEmp(int n) {return personnel.at(n-1);}

employee branch::getSortedEmp(int n) {return sortedPersonnel.at(n-1);}

bool branch::checkEmployee(string n) {
  if(personnel.size()==0) return false;
  for(int i = 0;i<personnel.size();i++) {
    if(n==personnel.at(i).eName()) return true;
  }
  return false;
}

void branch::relocate(string n) {
  location = n;
}

void branch::resize(int n) {branchSize = n;}

int branch::size() { return branchSize;}

int branch::currentSize() { return personnel.size();}

float branch::sale() {return this->sales;}

string branch::getLo() {return location;}
  
void branch::sort(string valueSort){
  int i,j,k,n,min;
  string temp;
  bool pass=0;
  if(valueSort == "salary"){
    sortedPersonnel.clear();
    for(i=0;i<personnel.size();i++){
      min = 100000000;
      for(j=0,n=0; j<personnel.size(); j++) {
        for(k=0;k<sortedPersonnel.size();k++) {
          pass =0;
          if(personnel.at(j).eSalary() == sortedPersonnel.at(k).eSalary()) {
            pass=1;
            break;
          }
        }
        if (pass==1) continue;
        else{
          if(personnel.at(j).eSalary()<min){
            min=personnel.at(j).eSalary();
            n=j;
          }
        }
      }
      sortedPersonnel.push_back(personnel.at(n));
    }
  }
  //----------------------------------
  if(valueSort == "year"){
    sortedPersonnel.clear();
    for(i=0;i<personnel.size();i++){
      min = 100000000;
      for(j=0,n=0; j<personnel.size(); j++) {
        for(k=0;k<sortedPersonnel.size();k++) {
          pass =0;
          if(personnel.at(j).eYear() == sortedPersonnel.at(k).eYear()) {
            pass=1;
            break;
          }
        }
        if (pass==1) continue;
        else{
          if(personnel.at(j).eYear()<min){
            min=personnel.at(j).eYear();
            n=j;
          }
        }
      }
      sortedPersonnel.push_back(personnel.at(n));
    }
  }
  //------------------------------------
  if(valueSort == "name"){
    sortedPersonnel.clear();
    for(i=0;i<personnel.size();i++){
      temp = "zzzzzzzzzzzz";
      for(j=0,n=0; j<personnel.size(); j++) {
        for(k=0;k<sortedPersonnel.size();k++) {
          pass =0;
          if(personnel.at(j).eName().compare(sortedPersonnel.at(k).eName())==0) {
            pass=1;
            break;
          }
        }
        if (pass==1) continue;
        else{
          if(eNameCap(personnel.at(j).eName()).compare(eNameCap(temp))<0){
            temp=personnel.at(j).eName();
            n=j;
          }
        }
      }
      sortedPersonnel.push_back(personnel.at(n));
    }
  }


  for(int i = 0;i<sortedPersonnel.size();i++) {
    cout<<sortedPersonnel.at(i).eName();
    //cout<<" Salary:"<<sortedPersonnel.at(i).eSalary();
    if(i!=sortedPersonnel.size()-1){
      cout<<", ";
    }
    }
  cout<<endl;
  }

void branch::rename(int emp,string n){personnel.at(emp-1).rename(n);}

void branch::resalary(int emp,float n){personnel.at(emp-1).resalary(n);}

void branch::reYIS(int emp, int n){personnel.at(emp-1).reYIS( n);}

void branch::relevel(int emp,string n){personnel.at(emp-1).relevel(n);}

void branch::SumOption() {
      cout<<"------------------------------------------------"<<endl;
      cout<<"|============== Summarize Branch ==============|"<<endl;
      cout<<"------------------------------------------------"<<endl;
      cout<<"|    Name    |    Position    | Years | Salary |"<<endl;
      cout<<"------------------------------------------------"<<endl;
      for(int i=0;i<personnel.size();i++){  
        cout<<"| "<< left << setw(10) << setfill(' ') <<  personnel.at(i).eName() << " | " << left<< setw(14) <<  personnel.at(i).ePosition() << " | " << left << setw(5) <<personnel.at(i).eYear() << " | " << left << setw(6) <<personnel.at(i).eSalary() << " |" <<endl;    
      }
      cout<<"------------------------------------------------"<<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 1. Sort by Name"<< " |"<<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 2. Sort by Year In Service"<< " |" <<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 3. Sort by Salary" << " |" <<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 0. Back" << " |" <<endl;
      cout<<"------------------------------------------------"<<endl;
    }

void branch::SumPerOption() {
      
      cout<<"------------------------------------------------"<<endl;
      cout<<"|============== Summarize Branch ==============|"<<endl;
      cout<<"------------------------------------------------"<<endl;
      cout<<"|    Name    |    Position    | Years | Salary |"<<endl;
      cout<<"------------------------------------------------"<<endl;
  
      for(int i=0;i<personnel.size();i++){  
        if(personnel.size()==0)break; 
        cout<<"| "<< left << setw(10) << setfill(' ') <<  sortedPersonnel.at(i).eName() << " | " << left<< setw(14) <<  sortedPersonnel.at(i).ePosition() << " | " << left << setw(5) <<sortedPersonnel.at(i).eYear() << " | " << left << setw(6) <<sortedPersonnel.at(i).eSalary() << " |" <<endl;    
      }
      cout<<"------------------------------------------------"<<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 1. Sort by Name"<< " |"<<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 2. Sort by Year In Service"<< " |" <<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 3. Sort by Salary" << " |" <<endl;
      cout<< left << setw(46) << setfill(' ') <<"| 0. Back" << " |" <<endl;
      cout<<"------------------------------------------------"<<endl;
    }

class company {
  private:
    string name;
    branch* branches;
    int noOfBranch;
  public:
    company(string n) {name = n;}
    ~company() {delete[]branches;}
    void rename(string n) {name = n;}
    void makeBranch(int b) {
      branches = new branch[b];
      noOfBranch = b;
    }

    void listBranch() {
      cout<<"There are "<<noOfBranch<<" branches total"<<endl<<"Branches locations consist of ";
      for(int i=0;i<noOfBranch;i++) {
        cout<<(*(branches+i)).getLo();
        if(i!=noOfBranch-1) cout<<", ";
        else cout<<endl;
      }
    }

    branch getBranch(int n) { return *(branches+n-1); }

    void defBranch(int n, string newName, int branchSize) {
      (*(branches+n-1)).relocate(newName);
      (*(branches+n-1)).resize(branchSize);
    }

    bool addEmployee(int n, employee e) { return (*(branches+n-1)).addEmployee(e); }

    void removeEmployee(int n, employee e) { (*(branches+n-1)).removeEmployee(e); }

    void option() {
      cout<<"-----------------------------------"<<endl;
      cout<<"|======== Manage Branches ========|"<<endl;
      cout<<"-----------------------------------"<<endl;
      for(int i=1;i<=noOfBranch;i++){
      cout<<"| "<<i<<". "<<left<<setw(29)<<setfill(' ')<<(branches+i-1)->getLo()<<"|"<<endl;
      }
      cout<<"-----------------------------------"<<endl;
    }

    void branchOption(int n) {
      cout<<setfill('-')<<setw(20+(branches+n-1)->getLo().length())<<"-"<<endl;
      cout<<"|======== "<<(branches+n-1)->getLo()<<" ========|"<<endl;
      cout<<setfill('-')<<setw(20+(branches+n-1)->getLo().length())<<"-"<<endl;    
      cout<<"| 1. Add Employee"<<right<<setfill(' ')<<setw(3+((branches+n-1)->getLo().length()))<<"|"<<endl;
      cout<<"| 2. Remove Employee"<<right<<setw((branches+n-1)->getLo().length())<<"|"<<endl;
      cout<<"| 3. Manage Employee"<<right<<setw((branches+n-1)->getLo().length())<<"|"<<endl;
      cout<<"| 4. Summarize Branch"<<right<<setw((branches+n-1)->getLo().length()-1)<<"|"<<endl;
      cout<<"| 5. Change Size"<<right<<setw((branches+n-1)->getLo().length()+4)<<"|"<<endl;
      cout<<"| 0. Back"<<right<<setw((branches+n-1)->getLo().length()+11)<<"|"<<endl;
      cout<<setfill('-')<<setw(20+(branches+n-1)->getLo().length())<<"-"<<endl;
    }

    void employeeOption(int n) {
      cout<<"------------------------------------"<<endl;
      cout<<"|======== Manage Employees ========|"<<endl;
      cout<<"------------------------------------"<<endl;
      for(int i=1;i<=(branches+n-1)->size();i++){
      cout<<"| "<<i<<". "<<left<<setw(30)<<setfill(' ');    
      if(i<=(branches+n-1)->currentSize()) 
        cout<<(branches+n-1)->getEmp(i).eName()<<"|"<<endl;
      else cout<<""<<"|"<<endl;
      }
      cout<<"| 0. Back"<<setw(26)<<""<<"|"<<endl;
      cout<<"------------------------------------"<<endl;
    }

    void employeeAttribute(int branch, int emp) {
      cout<<setfill('-')<<setw(20+(branches+branch-1)->getEmp(emp).eName().length())<<"-"<<endl;
      cout<<"|======== "<<(branches+branch-1)->getEmp(emp).eName()<<" ========|"<<endl;
      cout<<setfill('-')<<setw(20+(branches+branch-1)->getEmp(emp).eName().length())<<"-"<<endl;    
      cout<<"| 1. Name"<<right<<setfill(' ')<<setw(11+((branches+branch-1)->getEmp(emp).eName().length()))<<"|"<<endl;
      cout<<"| 2. Position"<<right<<setw(7+(branches+branch-1)->getEmp(emp).eName().length())<<"|"<<endl;
      cout<<"| 3. Salary"<<right<<setw(9+(branches+branch-1)->getEmp(emp).eName().length())<<"|"<<endl;
      cout<<"| 4. Year Of Service"<<right<<setw((branches+branch-1)->getEmp(emp).eName().length())<<"|"<<endl;
      cout<<"| 0. Back"<<right<<setw(11+(branches+branch-1)->getEmp(emp).eName().length())<<"|"<<endl;
      cout<<setfill('-')<<setw(20+(branches+branch-1)->getEmp(emp).eName().length())<<"-"<<endl;
    }

    void sort(int n, string s) {(branches+n-1)->sort(s);}

    void resize(int branch,int n) {(branches+branch-1)->resize(n);}

    void rename(int branch,int emp,string name){(branches+branch-1)->rename(emp,name);}

    void resalary(int branch,int emp,float s){(branches+branch-1)->resalary(emp,s);}

    void relevel(int branch,int emp,string lvl){(branches+branch-1)->relevel(emp,lvl);}

    void reYIS(int branch,int emp,int yis){(branches+branch-1)->reYIS(emp,yis);}

};
