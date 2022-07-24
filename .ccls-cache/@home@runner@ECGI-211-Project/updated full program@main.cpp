#include "company.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {
  bool run = true;
  string comName, name, cont;
  float temp;
  char c;
  int numBranch, choice, count = 0, t;
  cout << "\033[2J\033[0;0H";
  cout << "Enter company name (with no space): ";
  cin >> comName;
  cout << "Enter number of branches within the company: ";
  cin >> numBranch;

  company *comp = new company(comName); // ask company name
  comp->makeBranch(numBranch);          // ask company size
  while (run) {
    choice = 0;
    // display
    while (true) {
      cout << "\033[2J\033[0;0H";
      comp->option();
      cout << "Input Option: ";
      cin >> choice;
      if (choice >= 0 && choice <= numBranch)
        break;
      else
        cout << "Invalid Input" << endl;
    } // manage branch option selection
    if (choice == 0) {
      cout << "\033[2J\033[0;0H"
           << "Program Ended." << endl;
      return 0;
    } // end program if input at start screnn = 0
    comp->branchOption(choice);
    int num = choice;
    while (true) {
      cout << "\033[2J\033[0;0H";
      comp->branchOption(choice);
      cout << "Input Option: ";
      cin >> choice;
      if (choice >= 0 && choice <= 6)
        break;
      else
        cout << "Invalid Input" << endl;
    } // branch management options (1-6)
    if (choice == 0)
      continue;
    switch (choice) {
    case 1: {
      cout << "\033[2J\033[0;0H";
      cout << "Enter Employee Name: ";
      cin >> name;
      if (comp->addEmployee(num, name))
        cout << "Employee " << name << " is added to branch "
             << comp->getBranch(num).getLo() << ".";
      else
        cout << "Branch is full. Unable to add more Employee.";
      cout << " Press any key then enter to exit." << endl;
      cin >> cont;
      break;
    } // add employee
    case 2: { // have to fix deleting first and last employee
      count = 0;
      while (true) {
        cout << "\033[2J\033[0;0H";
        if (count == 0)
          cout << "Enter Employee Name (enter 0 to go back): ";
        else
          cout << "Employee not found.\nEnter Employee Name (enter 0 to go "
                  "back): ";
        cin >> name;
        if (name == "0" || comp->getBranch(num).checkEmployee(name))
          break;
        count++;
      }
      if (name != "0") {
        comp->removeEmployee(num, name);
        cout << "Employee " << name
             << " is removed. Press any key then Enter to exit." << endl;
      }
      cin >> cont;
      break;
    } // remove employee
    case 3: {
      while (true) {

        while (true) {
          cout << "\033[2J\033[0;0H";
          comp->employeeOption(num);
          cout << "Input Option: ";
          cin >> choice;
          if (choice >= 0 && choice <= comp->getBranch(num).size())
            break;
          else
            cout << "Invalid Input" << endl;
        }
        if (choice == 0)
          break;
        while (true) {
          cout << "\033[2J\033[0;0H";
          comp->employeeAttribute(num, choice);
          cout << "Input Option: ";
          cin >> t;
          if (t >= 0 && t <= 4)
            break;
          else
            cout << "Invalid Input" << endl;
        }
        if (t == 0)
          continue;
        switch (t) {
        case 1: {
          cout << "Enter Employee's new name[string]: ";
          cin >> name;
          comp->rename(num, choice, name);
          cout << "Employee's name has been changed to " << name
               << ". Press any key then Enter to exit" << endl;
          cin >> cont;
          break;
        }
        case 2: {
          cout << "Enter Employee's new Position[string]: ";
          cin >> name;
          comp->relevel(num, choice, name);
          cout << "Employee's position has been changed to " << name
               << ". Press any key then enter to exit." << endl;
          cin >> cont;
          break;
        }
        case 3: {
          cout << "Enter Employee's new Salary[float]: ";
          cin >> temp;
          comp->resalary(num, choice, temp);
          cout << "Employee's Salary has been changed to " << temp
               << ". Press any key then enter to exit." << endl;
          cin >> cont;
          break;
        }
        case 4: {
          cout << "Enter Employee's new Year in Service[int]: ";
          cin >> t;
          comp->reYIS(num, choice, t);
          cout << "Employee's Year in Service has been changed to " << t
               << ". Press any key then enter to exit." << endl;
          cin >> cont;
          break;
        }
        }
      }
      break;
    } // manage employee
    case 4: {
      while (true) {
        cout << "\033[2J\033[0;0H";
        // initial print table
        comp->getBranch(num).SumPerOption(); // pls check
        cout << "Input Option: ";
        cin >> choice;
        if (choice < 0 || choice > 3)
          continue;
        if (choice == 0)
          break;

        switch (choice) {
        case 1: {
          comp->sort(num, "name");
          cout << "\033[2J\033[0;0H"; // clear
          comp->getBranch(num).SumPerOption();
          cout << "Press any key then enter to continue." << endl;
          cin >> cont;
          break;
        }
        case 2: {
          comp->sort(num, "year");
          cout << "\033[2J\033[0;0H";
          comp->getBranch(num).SumPerOption();
          cout << "Press any key then enter to continue." << endl;
          cin >> cont;
          break;
        }
        case 3: {
          comp->sort(num, "salary");
          cout << "\033[2J\033[0;0H";
          comp->getBranch(num).SumPerOption();
          cout << "Press any key then enter to continue." << endl;
          cin >> cont;
          break;
        }
        }
      }
      break;
    } // summarize branch
    case 5: {
      cout << "Input new Branch Size: ";
      cin >> choice;
      if (choice == 0)
        break;
      comp->resize(num, choice);
      cout << "Branch Size has been updated to " << choice
           << ". Press any key then enter to exit." << endl;
      cin >> cont;
      break;
    } // change branch size
    case 6: {
      cout << "Input new Branch Name: ";
      cin >> name;
      if (choice == 0)
        break;
      comp->branchName(num, name);
      cout << "Branch Name has been updated to " << name
           << ". Press any key then enter to exit." << endl;
      cin >> cont;
      break;
    }
    } // loop the entire program.
  }
}