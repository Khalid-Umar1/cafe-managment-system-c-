#include "employee.h"



void Employee::action() 

    {

    

    int a;

    apoint:

    cout << " ---------------------------------\n";

    cout << " | (1) Display Menu              |\n | (2) Order                     |\n | (3) Online Orders             |\n | (4) Search item              |\n | (5) Exit                      |\n";

    cout << " ---------------------------------\n";

    cout << " Please Enter the corresponding number.\n";

    cin >> a;

    switch (a) 

    {

        case 1: 

        {

            s1.itemdisplay();

            goto apoint;

        }

        break;

        case 2: 

        {

            s1.itemdisplay();

            o1.employeeorder();

            goto apoint;

        }

        break;

        case 3: 

        { 

            

            o1.onlineorder();

            goto apoint;

        }

        break;



        case 4: {

            string searchname;

                   cout << " ---------------------------\n";

                   cout << " |       Item Search       |\n"; 

    		   cout << " ---------------------------\n";                   

                   

                   cout<<" Enter the name of the item: ";

                   cin>>searchname;

                                         

            s1.itemsearch(searchname);

            goto apoint;

        }

        break;

        case 5: {

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
