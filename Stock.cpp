#include "Stock.h"

#include "Notification.h"

#include <iomanip>

using namespace std ;



void Stock::stockaction() 

{

    n1.admindisplaynoti();//display notification

    int a;

       mpoint:  

      cout<< " -------------------------------\n";

      cout<< " | (1) Display Item            |\n | (2) Search Item             |\n | (3) Add Item                |\n | (4) Remove Item             |\n | (5) Order Item              |\n | (6) Exit                    |\n";

      cout<< " -------------------------------\n";

      cout<< " Please Enter the corresponding number.\n";

      cin>>a;

       switch (a)

       {

         case 1:

                 {//display item

                   cout << " ---------------------------\n";

                   cout << " |       Item Display      |\n"; 

    		   cout << " ---------------------------\n";

                    itemdisplay();

                    goto mpoint;

                 }

           break;

         case 2: 

                 { //search item

                   char* searchname;

                   cout << " ---------------------------\n";

                   cout << " |       Item Search       |\n"; 

    		   cout << " ---------------------------\n";                   

                   

                   cout<<" Enter the name of the item: ";

                   cin>>searchname;

                                         

                   itemsearch(searchname);

                 

                

                   goto mpoint;

                 }

             break;

         case 3: 

                 {//add item

                   char addname[10],iprice[10],iquantity[10];

                   cout << " ---------------------------\n";

                   cout << " |        Add Item         |\n"; 

    		   cout << " ---------------------------\n";                   

                   

                   cout<<" Enter the name of the Item: ";

                   cin>>addname;

                   cout<<" Enter the price of the Item: ";

                   cin>>iprice;

                   cout<<" Enter the quantity of the Item: ";

                   cin>>iquantity;

               

                   cout<<endl;

                                         

                   itemadd(addname,iprice, iquantity );

                   goto mpoint;

                 }

             break;

         case 4: 

                 { 

                   char* searchname;

                   cout << " ---------------------------\n";

                   cout << " |       Item Remove       |\n"; 

    		   cout << " ---------------------------\n";                   

                   

                   cout<<" Enter the name of the item: ";

                   cin>>searchname;

                                         

                   itemremove(searchname);

                 

                

                   goto mpoint;

                 }

             break;

       

         case 5: 

                 { 

                   

                   cout << " --------------------------\n";

                   cout << " |       Item Order       |\n"; 

    		   cout << " --------------------------\n";                   

                   

                   o1.adminorder();

                

                   goto mpoint;

                 }

             break;

          case 6:

                  {

                    cout<<" Exiting \n";

                    return ;

                    

                  }

           default:

                  {

                   cout << "#################################################\n";

                   cout << "| Invalid Input.:( . Please enter between (1-4) |\n"; 

                   cout << "#################################################\n";

                   goto mpoint;

                  }

       }  

          

    }



void Stock::bubblesort(string name[],string price[],string quantity [],int itemcount)//sort items

{

    for (int i = 0; i < itemcount - 1; ++i)//sort items

    {

        for (int j = 0; j < itemcount - i - 1; ++j)

        {

            // Convert quantity strings to integers for comparison

            int quantity1 = stoi(quantity[j]);  //stoi is used to convert string to integer

            int quantity2 = stoi(quantity[j + 1]);//stoi is used to convert string to integer

            if (quantity1 > quantity2)

            {

                // Swap menu items

                swap(name[j], name[j + 1]);

                swap(price[j], price[j + 1]);

                swap(quantity[j], quantity[j + 1]);

            }

        }

    }

}



void Stock::itemdisplay() 

{

    ifstream efile("adminmenu.txt");//open file

    if (!efile) 

    {

        cout << " Error opening file." << endl;

        return;

    }



    const int maxitem = 20;

    string iname[maxitem], iprice[maxitem], iquantity[maxitem];//array for item name,price and quantity

    int count = 0;



    // Read items from file and store them in arrays

    while (efile >> iname[count] >> iprice[count] >> iquantity[count]) //read items from file

    {

        ++count;

        if (count >= maxitem) //check if item limit is reached

        {

            cout << "Maximum Item limit reached." << endl;

            return;

        }

    }

    efile.close();



    // Sort items for display

    bubblesort(iname, iprice, iquantity, count);//sort items



    // Display sorted items

    cout << "---------------------------------------------------------------" << endl;

    cout << left << setw(5) << "No." << setw(20) << "Name" << setw(15) << "Price" << setw(10) << "Quantity" <<endl;

    cout << "---------------------------------------------------------------" << endl; 

    for (int i = 0; i < count; ++i) {

       

        int quantity = stoi(iquantity[i]);//stoi is used to convert string to integer

         if (quantity == 0)

                   {

                        // Change text color to yellow for items with quantity less than 10

                       cout << "\x1b[31m"; // ANSI escape code for red text

                   }

                   

                   else if (quantity < 10) 

                   {

                     // Change text color to yellow for items with quantity less than 10

                       cout << "\x1b[33m"; // ANSI escape code for yellow text

                   }

                  

                     cout << left << setw(5) << (i + 1) << setw(20) << iname[i] << setw(20) << iprice[i] << setw(14) << iquantity[i]<< endl;



                 if (quantity < 10) 

                    {

                       // Reset text color to default after printing the line

                       cout << "\x1b[0m"; // ANSI escape code for resetting text color

                     }

    }

}



void Stock::itemsearch(const std::string& searchname) //search item

{

    const int maxitem = 20;

        string iname[maxitem], iprice[maxitem], iquantity[maxitem];



        int count = 0;



        ifstream file("adminmenu.txt");

        if (!file) 

        {

            cout << "Error opening file." << endl;

            return;

        }



        // This while loop read employee details from file and store them in arrays

        while (file >> iname[count] >> iprice[count] >> iquantity[count]) 

        {

            ++count;

            if (count >= maxitem) 

            {

                cout << "Maximum Item limit reached." << endl;

                return;

            }

        }

        file.close();//close file



        // This for loop searches for the employee to be removed

        int searchIndex = -1;

        for (int i = 0; i < count; ++i) 

        {

            if (iname[i] == searchname) 

            {

                searchIndex = i;

                break;

            }

        }



        // If item found, remove their details from arrays

        if (searchIndex != -1) 

        {

            int i = searchIndex;

            

                cout <<" No: "<< i+1<< " Name: "<< iname[i] << " Price: " << iprice[i] << " Quantity: " << iquantity[i] << endl;  

            

            

            cout << "\n Item searched successfully." << endl;

        } 

        else 

        {

            cout << " Item not found." << endl;

            return;

        }

       

}



void Stock::itemadd(char* addname, char* iprice, char* iquantity)//add item

 {

    ifstream file("adminmenu.txt");//open file

        if (!file) 

         {

            cout << "Error opening file." << endl;

            return;

         }



        string iname,ip,iq;//

        int count = 0;



        // Read existing data from the file

        while (file >> iname >> ip >> iq) //read items from file

        {

            ++count;

            if (count >= 20)

             {

                cout << " Maximum item limit reached." << endl;

                return;

            }

        }

        file.close();



        ofstream outFile("adminmenu.txt", ios::app);//open file for writing

        if (!outFile) 

        {

            cout << " Error opening file for writing." << endl;

            return;

        }



        // Write the new employee to the file

        outFile << addname << " " << iprice << " " << iquantity << endl;//write items to file

        outFile.close();

        

        cout << " Item added successfully." << endl;

        

        cout<<" -----------------------\n";

        cout << " Name: "<< iname << " Price: " << ip << " quantity: " << iq << endl;

        cout<<" -----------------------\n";

        

        itemdisplay();

}



void Stock::itemremove(const string& removeName) //remove item

{

    const int maxitem = 20;

        string iname[maxitem], iprice[maxitem], iquantity[maxitem];//array for item name,price and quantity



        int count = 0;



        ifstream file("adminmenu.txt");

        if (!file) 

        {

            cout << "Error opening file." << endl;

            return;

        }



        // This while loop read employee details from file and store them in arrays

        while (file >> iname[count] >> iprice[count] >> iquantity[count]) //read items from file

        {

            ++count;

            if (count >= maxitem) 

            {

                cout << "Maximum Item limit reached." << endl;

                return;

            }

        }

        file.close();



        // This for loop searches for the employee to be removed

        int removeIndex = -1;

        for (int i = 0; i < count; ++i) 

        {

            if (iname[i] == removeName) 

            {

               removeIndex = i;

                break;

            }

        }



        // If employee found, remove their details from arrays

        if (removeIndex != -1) 

        {

            for (int i = removeIndex; i < count - 2; ++i) 

            {

                iname[i] = iname[i + 1];

                iprice[i] = iprice[i + 1];

                iquantity[i] = iquantity[i + 1];

               

            }

            --count;

            cout << "Item removed successfully." << endl;

        } 

        else 

        {

            cout << "Item not found." << endl;

            return;

        }

                  // Write the updated menu back to the file

        ofstream outfile("adminmenu.txt");

        if (!outfile) {

            cout << "Error opening file for writing." << endl;

            return;

        }

        for (int i = 0; i < count; ++i) //write items to file

        {

            outfile << iname[i] << " " << iprice[i] << " " << iquantity[i] << endl;

        }

        outfile.close();

        // Write the updated employee details back to the file

        

        itemdisplay();

}




