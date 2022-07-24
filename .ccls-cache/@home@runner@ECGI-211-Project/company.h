#include "branch.h"
#include <iomanip>

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

    branch getBranch(int n) { return *(branches+n-1); }

    void defBranch(int n, string newName, int branchSize) {
      (*(branches+n-1)).relocate(newName);
      (*(branches+n-1)).resize(branchSize);
    }

    bool addEmployee(int n, string e) { return (*(branches+n-1)).addEmployee(e); }

    void popLast(int n){ (*(branches+n-1)).popLast(); }

    void removeEmployee(int n, string e) { (*(branches+n-1)).removeEmployee(e); }

    void option() {
      cout<<"-----------------------------------"<<endl;
      cout<<"|======== Manage Branches ========|"<<endl;
      cout<<"-----------------------------------"<<endl;
      for(int i=1;i<=noOfBranch;i++) cout<<"| "<<i<<". "<<left<<setw(29)<<setfill(' ')<<(branches+i-1)->getLo()<<"|"<<endl;
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
      cout<<"| 6. Change Name"<<right<<setw((branches+n-1)->getLo().length()+4)<<"|"<<endl;
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
    
    void branchName(int branch,string n) {(branches+branch-1)->name(n);}

    void rename(int branch,int emp,string name){(branches+branch-1)->rename(emp,name);}

    void resalary(int branch,int emp,float s){(branches+branch-1)->resalary(emp,s);}

    void relevel(int branch,int emp,string lvl){(branches+branch-1)->relevel(emp,lvl);}

    void reYIS(int branch,int emp,int yis){(branches+branch-1)->reYIS(emp,yis);}
};