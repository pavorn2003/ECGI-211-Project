#include <iostream>
using namespace std;

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
    employee() {name="NA";}
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

