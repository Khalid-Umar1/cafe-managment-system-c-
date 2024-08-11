#include <iostream>

#include <cstring> // for strlen

#include "User.h" // Base class header file

#include "Admin.h" // Derived class header files

#include "employee.h"

#include "student.h"



using namespace std;



int main() {

    int num;

    char username[20], password[20];        // Username and password

    int ulength, plength;



    cout << "\n ####################################";

    cout << "\n |  Welcome to Cafe Digital System  |";

    cout << "\n ####################################";

mainpoint:

    do {

        cout << "\n ------------------------------------";

        cout << "\n |   1) Admin                       |";

        cout << "\n |   2) Employee                    |";

        cout << "\n |   3) Student                     |";

        cout << "\n |   4) Exit                        |";

        cout << "\n ------------------------------------\n";



        cout << " Select your sign in option\n";

        cin >> num;



        if (num != 4)       // If user does not want to exit, ask for username and password
        {

            cout << " Enter Username: ";

            cin >> username;

            cout << " Enter Password: ";

            cin >> password;



            ulength = strlen(username);

            plength = strlen(password);



            // Input validation to prevent buffer overflow

            if (ulength >= 20 || plength >= 20) 
            {

                cout << "Username or password is too long. Please try again.\n";

                continue;

            }

        }



        // Create user object based on user input

        User* user = nullptr;

        bool loggedIn = false;



        switch (num)        // Switch case to create object based on user input
         {

            case 1:     // Admin
            {

                user = new Admin(username, password, ulength, plength); // Create Admin object

                loggedIn = user->login("AdminLogin.txt", "Admin");

                break;

            }

            case 2:     // Employee
            {

                user = new Employee(username, password, ulength, plength);  // Create Employee object

                loggedIn = user->login("EmployeeLogin.txt", "Employee");

                break;

            }

            case 3: 
            {

                user = new Student(username, password, ulength, plength);   // Create Student object

                loggedIn = user->login("StudentLogin.txt", "Student");

                break;

            }

            case 4:
             {

                return 0;

            }

            default: 
            {

                cout << "#################################################\n";

                cout << "| Invalid Input.:( . Please enter between (1-4) |\n";

                cout << "#################################################\n";

                continue;

            }

        }



        // Check if user is not null and logged in

        if (user && loggedIn)     // If user is not null and logged in, perform action
        {

            cout << " -------------------------------\n";

            cout << " | Login successful           |\n";

            cout << " -------------------------------\n";

            user->action();    // Perform action

            delete user;

        }
         else 
        {

            cout << " ###############################\n";

            cout << " | Credentials do not match.  |\n";

            cout << " ###############################\n";

            if (user)    // If user is not null, delete user object
            {

                delete user;

            }

        }

     goto mainpoint;

    } while (!(num >= 1 && num <= 4));



    return 0;

}






