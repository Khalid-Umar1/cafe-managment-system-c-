#include "Admin.h"

#include <iostream>

#include <fstream>

#include <cstring> // for strcmp

using namespace std;

void Admin::action() 

{

    int a;

    apoint:

    cout << " ---------------------------------\n";

    cout << " | (1) Employees Staff            |\n | (2) Menu control               |\n | (3) Complaints and suggestions |\n | (4) Notification               |\n | (5) Scheduled orders           |\n | (6) Log Out                    |\n";

    cout << " ---------------------------------\n";

    cout << " Please Enter the corresponding number.\n";

    cin >> a;

    switch (a)      // Switch case for the admin to choose the function
    {

        case 1:
         {

            employeeStaff();    // Employee Staff

            goto apoint;

        }

        break;

        case 2: 
        {

            s1.stockaction();

            goto apoint;

        }

        break;

        case 3:
         {

            c1.comsuggadminaction();

            goto apoint;

        }

        break;

        case 4: 
        {

            n1.notiadminaction();

            goto apoint;

        }

        break;

        case 5:
         {

            o1.onlineorder();
            
            goto apoint;

        }

        break;

        case 6:
         {

            cout << " Logging out of the account.....\n";

            return;

        }

        break;

        default: {

            cout << "#################################################\n";

            cout << "| Invalid Input.:( . Please enter between (1-4) |\n";

            cout << "#################################################\n";

            goto apoint;

        }

    }

}



void Admin::employeedisplay() 

{

         ifstream efile("adminemployee.txt");//file to read employee details

          if (!efile) 

           {

              cout << " Error opening file." << endl;

              return;

           }

         string name, sal, ag, jb;

         int i=1;

         while (efile >> name >> sal >> ag >> jb) //read employee details from file

          {

           

                cout <<" No: "<< i<< " Name: "<< name << " Salary: " << sal << " Age: " << ag << " Job: " << jb << endl;  //display employee details

               i++;

          }

        

          efile.close();

}



void Admin::employeeStaff() 
{

    int a;

    cout << " -------------------------------\n";

    cout << " |   Employee Staff Function   |\n";

    cout << " -------------------------------\n";

    epoint:

    cout << " -------------------------------\n";

    cout << " | (1) Employee Search          |\n | (2) Add Employee             |\n | (3) Remove employee          |\n | (4) Display All Employee     | \n | (5) Exit                     |\n";

    cout << " -------------------------------\n";

    cout << " Please Enter the corresponding number.\n";

    cin >> a;

    switch (a)// Switch case for the admin to choose the function 
    {

        case 1: {

            string searchname;

            cout << " -------------------------------\n";

            cout << " |       Employee Search       |\n";

            cout << " -------------------------------\n";

            cout << " Enter the name of the employee: ";

            cin >> searchname;

            employeesearch(searchname);

            goto epoint;

        }

        break;

        case 2:         // Add Employee
        {

            char addname[10], salary[10], age[10], job[10];

            cout << " -------------------------------\n";

            cout << " |        Add Employee         |\n";

            cout << " -------------------------------\n";

            cout << " Enter the name of the employee: ";

            cin >> addname;

            cout << " Enter the age of the employee: ";

            cin >> age;

            cout << " Enter the salary of the employee: ";

            cin >> salary;

            cout << " Enter the job of the employee: ";

            cin >> job;

            cout << endl;

            employeeadd(addname, salary, age, job);

            goto epoint;

        }

        break;

        case 3:
         {

            char removename[10];

            cout << " -------------------------------\n";

            cout << " |       Remove Employee       |\n";

            cout << " -------------------------------\n";

            cout << " Enter the name of the employee: ";

            cin >> removename;

            employeeremove(removename);

            goto epoint;

        }

        break;

        case 4: 
        {

            employeedisplay();

            goto epoint;

        }

        break;

        case 5: 
        {

            cout << " Exiting from employee: \n";

            action();

            return;

        }

        default: {

            cout << "#################################################\n";

            cout << "| Invalid Input.:( . Please enter between (1-4) |\n";

            cout << "#################################################\n";

            goto epoint;

        }

    }

}



void Admin::employeesearch(const string& searchname) 

{

          const int maxEmployees = 20;

        string name[maxEmployees], salary[maxEmployees], age[maxEmployees], job[maxEmployees];



        int count = 0;



        ifstream file("adminemployee.txt");

        if (!file) 

        {

            cout << "Error opening file." << endl;

            return;

        }



        // This while loop read employee details from file and store them in arrays

        while (file >> name[count] >> salary[count] >> age[count] >> job[count]) //read employee details from file

        {

            ++count;

            if (count >= maxEmployees) 

            {

                cout << "Maximum employee limit reached." << endl;

                return;

            }

        }

        file.close();



        // This for loop searches for the employee to be removed

        int searchIndex = -1;

        for (int i = 0; i < count; ++i) 

        {

            if (name[i] == searchname) 

            {

                searchIndex = i;

                break;

            }

        }



        // If employee found, remove their details from arrays

        if (searchIndex != -1) 

        {

            int i = searchIndex;

            

                cout<<"\n Name: "<<name[i]<<" Salary: "<<salary[i]<<" Age: "<<age[i]<<" Job Type: "<<job[i]<<endl;

            

            

            cout << "\n Employee searched successfully." << endl;

        } 

        else 

        {

            cout << " Employee not found." << endl;

            return;

        }

}



void Admin::employeeadd(char* addname, char* salary, char* age, char* job) //function to add employee

{

         ifstream file("adminemployee.txt");//file to read employee details

        if (!file) 

         {

            cout << "Error opening file." << endl;//if file not opened

            return;

         }



        string name, sal, ag, jb;//

        int count = 0;



        // Read existing data from the file

        while (file >> name >> sal >> ag >> jb) //read employee details from file

        {

            ++count;

            if (count >= 10)

             {

                cout << " Maximum employee limit reached." << endl;

                return;

            }

        }

        file.close();



        ofstream outFile("adminemployee.txt", ios::app);

        if (!outFile) 

        {

            cout << " Error opening file for writing." << endl;

            return;

        }



        // Write the new employee to the file

        outFile << addname << " " << salary << " " << age << " " << job << endl;

        outFile.close();

        

        cout << " Employee added successfully." << endl;

        cout<<" -----------------------\n";

        cout << " Name: "<< addname << " Salary: " << salary << " Age: " << age << " Job: " << job << endl;

        cout<<" -----------------------\n";

        

            const int maxEmployees = 20;

    string username[maxEmployees], password[maxEmployees];//arrays to store employee credentials



   count = 0;



    ifstream inFile("EmployeeLogin.txt");

    if (!inFile) {

        cout << "Error opening file." << endl;

        return;

    }



    // Read existing employee credentials from file and store them in arrays

    while (inFile >> username[count] >> password[count]) //read employee credentials from file
    {

        ++count;

        if (count >= maxEmployees) {

            cout << "Maximum employee limit reached." << endl;

            inFile.close();

            return;

        }

    }

    inFile.close();

    

        string Username , Password;

        cout<<" Enter the username for the new user: ";

        cin>>Username;

        cout<<" Enter the password for the new user: ";

        cin>>Password;

        

        username[count]=Username;

        password[count]=Password;

        ++count;

            // Write the updated employee credentials back to the file

    ofstream aoutFile("EmployeeLogin.txt");

    if (!aoutFile)   
    {

        cout << "Error opening file for writing." << endl;

        return;

    }



    for (int i = 0; i < count; ++i) //write employee credentials to file
    {

        aoutFile << username[i] << " " << password[i] << endl;

    }

    aoutFile.close();



    cout << " New employee credentials added successfully." << endl;

    

        employeedisplay();

}



void Admin::employeeremove(const string& removeName) //function to remove employee

{

        const int maxEmployees = 20;

        string name[maxEmployees], salary[maxEmployees], age[maxEmployees], job[maxEmployees];



        int count = 0;



        ifstream file("adminemployee.txt");

        if (!file) 

        {

            cout << "Error opening file." << endl;

            return;

        }



        // This while loop read employee details from file and store them in arrays

        while (file >> name[count] >> salary[count] >> age[count] >> job[count]) //read employee details from file

        {

            ++count;

            if (count >= maxEmployees) 

            {

                cout << "Maximum employee limit reached." << endl;

                return;

            }

        }

        file.close();



        // This for loop searches for the employee to be removed

        int removeIndex = -1;

        for (int i = 0; i < count; ++i) //search for the employee to be removed

        {

            if (name[i] == removeName) 

            {

                removeIndex = i;

                break;

            }

        }



        // If employee found, remove their details from arrays

        if (removeIndex != -1) 

        {

            for (int i = removeIndex; i < count - 1; ++i) 

            {

                name[i] = name[i + 1];

                salary[i] = salary[i + 1];

                age[i] = age[i + 1];

                job[i] = job[i + 1];

            }

            --count;

            cout << "Employee removed successfully." << endl;

        } 

        else 

        {

            cout << "Employee not found." << endl;

            return;

        }



        // Write the updated employee details back to the file

        ofstream outFile("adminemployee.txt");

        if (!outFile) 

        {

            cout << "Error opening file for writing." << endl;

            return;

        }



        for (int i = 0; i < count; ++i) 

        {

            outFile << name[i] << " " << salary[i] << " " << age[i] << " " << job[i] << endl;

        }

        outFile.close();

          

          //to remove credetnial from the file also 

          



    string username[maxEmployees], password[maxEmployees];



    count = 0;



    ifstream inFile("EmployeeLogin.txt");

    if (!inFile) {

        cout << "Error opening file." << endl;

        return;

    }



    // Read employee credentials from file and store them in arrays

    while (inFile >> username[count] >> password[count]) {

        ++count;

        if (count >= maxEmployees) {

            cout << "Maximum employee limit reached." << endl;

            return;

        }

    }

    inFile.close();



    // Search for the employee to be removed

    removeIndex = -1;

    for (int i = 0; i < count; ++i) {

        if (username[i] == removeName) {

            removeIndex = i;

            break;

        }

    }



    // If employee found, remove their credentials from arrays

    if (removeIndex != -1) {

        for (int i = removeIndex; i < count - 1; ++i) {

            username[i] = username[i + 1];

            password[i] = password[i + 1];

        }

        --count;

        cout << "Employee credential removed successfully." << endl;

    } else {

        cout << "Employee not found." << endl;

        return;

    }



    // Write the updated employee credentials back to the file

    ofstream aoutFile("EmployeeLogin.txt");

    if (!aoutFile) {

        cout << "Error opening file for writing.!!" << endl;

        return;

    }



    for (int i = 0; i < count; ++i) {

        aoutFile << username[i] << " " << password[i] << endl;

    }

    outFile.close();

    employeedisplay();

}




