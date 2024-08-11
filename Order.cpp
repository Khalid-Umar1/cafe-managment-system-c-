#include "Order.h"

#include <iostream>

#include <fstream>

#include <string>

#include <cstdlib> // for atoi



using namespace std;



void Order::adminorder() 

{

    ifstream file("adminmenu.txt");//open the file



    	if (!file) 

    	  {

        	cout << "Error opening file." << endl;

        	return;

    	  }


     // Declare and initialize variables
    const int mitem = 100;

    string itemname[mitem];

    string price[mitem];

    string quantity[mitem];



    int icount = 0;



    // Read data from the file

   	 while (icount < mitem && file >> itemname[icount] >> price[icount] >> quantity[icount]) //read the data from the file

    		{

        		++icount;

    		}



    file.close();





    cout << "Enter the name of the product to order: ";//ask the user to enter the name of the product

    string orderName;

    cin >> orderName;



    // Search for the item

    int orderIndex = -1;

    

   	 for (int i = 0; i < icount; ++i)//search for the item

 	     {

    		  

        		if (itemname[i] == orderName) 

        		    {

            			orderIndex = i;

            			break;

        		    }

    	     }





    	if (orderIndex == -1) //if the item is not found

    	   {

        	cout << "###################" << endl;

        	cout << "Product not found." << endl;

        	cout << "###################" << endl;

        	return;

     	   }



  

    	cout << "Enter the quantity to order: ";

   	int quant;

  	cin >> quant;

    	quant=quant+stoi(quantity[orderIndex]);//convert from string to integer and add it with the new quantity

	quantity[orderIndex]=to_string(quant);//convert the new quantity into the string 



               ofstream outFile("adminmenu.txt");//open the file for writing

                  if (!outFile)

                  	 {

                  	    cout << "Error opening file for writing." << endl;

                     	    return;

                   	 }



               for (int i = 0; i < icount; ++i)//write the data into the file

               	    {

                   	 outFile << itemname[i] << " " << price[i] << " " << quantity[i] << endl;

                    }

                 outFile.close();

                 

    // Further processing...

}



void Order::studentorder()//function to order for the student
 {

    totalcost = 0;

    const int mitem = 100;

    string itemname[mitem];

    string price[mitem];

    string quantity[mitem];



    int icount = 0;



    // Read menu items from adminmenu.txt

    ifstream file("adminmenu.txt");//open the file

    if (!file) 
    {

        cout << "Error opening adminmenu.txt." << endl;

        return;

    }



    while (icount < mitem && file >> itemname[icount] >> price[icount] >> quantity[icount])//read the data from the file
     {

        ++icount;

    }

    file.close();



    int orderIndex;

    int quant;

    bool orderPlaced = false;



    while (!orderPlaced)//loop to place the order
     {

        cout << "Enter the name of the product to order (or type 'end' to finish): ";

        cin >> orderName;



        if (orderName == "end")
         {

            orderPlaced = true;

            continue;

        }



        orderIndex = -1;

        for (int i = 0; i < icount; ++i)    //search for the items
        {

            if (itemname[i] == orderName) 
            {

                orderIndex = i;

                break;

            }

        }



        if (orderIndex == -1) 
        {

            cout << "Product not found." << endl;

            continue;

        }



        cout << "Enter the quantity: ";

        cin >> quant;



        // Ensure the quantity is valid and subtract it from available quantity

        int availableQuant = stoi(quantity[orderIndex]);//convert the string to integer

        if (quant <= availableQuant)      //check if the quantity is available
        {

            quantity[orderIndex] = to_string(availableQuant - quant);

            totalcost += stoi(price[orderIndex]) * quant;

            cout << "Order placed successfully!" << endl;



            // Update adminmenu.txt after placing an order

            ofstream adminMenuFile("adminmenu.txt");

            if (adminMenuFile.is_open())//open the file for writing
            {

                for (int i = 0; i < icount; ++i)
                 {

                    adminMenuFile << itemname[i] << " " << price[i] << " " << quantity[i] << endl;

                }

                adminMenuFile.close();

            }
             else
              {

                cout << "Error updating adminmenu.txt." << endl;

            }



            // Save the order details to scheduledorder.txt

            ofstream scheduledOrderFile("scheduledorder.txt", ios::app);   //open the file for writing

            if (scheduledOrderFile.is_open())     //check if the file is open
            {

                scheduledOrderFile << "Product: " << itemname[orderIndex] << " Quantity: " << quant << endl;

                scheduledOrderFile.close();

            }
             else
              {

                cout << "Error opening scheduledorder.txt for writing." << endl;

            }

        } else
         {

            cout << "Not enough quantity available!" << endl;

            continue;

        }

    }



    cout << "Total cost of the order: $" << totalcost << endl;



    // Display the orders from scheduledorder.txt

    cout << "Your Order is: " << endl;

    ifstream scheduledOrderFile("scheduledorder.txt");//open the file for reading

    if (scheduledOrderFile.is_open())   //check if the file is open
     {

        string order;

        while (getline(scheduledOrderFile, order))//read the data from the file
         {

            cout << order << endl;

        }

        scheduledOrderFile.close();

    } else {

        cout << "Error opening scheduledorder.txt for reading." << endl;

    }

}



void Order::employeeorder()         //function to order for the employee
{

    totalcost = 0;

            const int mitem = 100;

    string itemname[mitem];

    string price[mitem];

    string quantity[mitem];



    int icount = 0;



    // Read menu items from adminmenu.txt

    ifstream file("adminmenu.txt"); // Open the file for reading

    if (!file) {

        cout << "Error opening adminmenu.txt." << endl;

        return;

    }



    while (icount < mitem && file >> itemname[icount] >> price[icount] >> quantity[icount])     // Read data from the file
     {

        ++icount;

    }

    file.close();



    int orderIndex;

    int quant;

    bool orderPlaced = false;



    string orderName;

    string employeeName;



    cout << "Enter your name: ";

    cin >> employeeName;



    // Open the receipt file for appending

    ofstream receiptFile("reciept.txt", ios::app);      // Open the file for writing (appending)

    if (!receiptFile)       // Check if the file is open
    {

        cout << "Error opening receipt.txt for writing." << endl;

        return;

    }



    while (!orderPlaced)    // Loop to place the order
    {

        cout << "Enter the name of the product to order (or type 'end' to finish): ";

        cin >> orderName;



        if (orderName == "end")     // Check if the user wants to finish the order
        {

            orderPlaced = true;

            continue;

        }



        orderIndex = -1;

        for (int i = 0; i < icount; ++i)        // Search for the item
        {

            if (itemname[i] == orderName) 
            {

                orderIndex = i;

                break;

            }

        }



        if (orderIndex == -1) 
        {

            cout << "Product not found." << endl;

            continue;

        }



        cout << "Enter the quantity: ";

        cin >> quant;



        int availableQuant = stoi(quantity[orderIndex]);// Convert the quantity to integer

        if (quant <= availableQuant) {

            quantity[orderIndex] = to_string(availableQuant - quant);// Subtract the quantity from the available quantity



            // Calculate total cost of the order

            int totalCost = stoi(price[orderIndex]) * quant;// Calculate the total cost

            totalcost += totalCost;// Add the total cost to the totalcost variable



            // Write the order details to the receipt file

            receiptFile << "Employee: " << employeeName << ", Product: " << orderName << ", Quantity: " << quant << ", Total Cost: $" << totalCost << endl;// Write the order details to the file



            cout << "Order placed successfully!" << endl;// Display a success message

        }
         else
          {

            cout << "Not enough quantity available!" << endl;

            continue;

        }

    }

ofstream adminMenuFile("adminmenu.txt");// Open the file for writing

if (adminMenuFile.is_open())// Check if the file is open
 {

    for (int i = 0; i < icount; ++i) {

        adminMenuFile << itemname[i] << " " << price[i] << " " << quantity[i] << endl;

    }

    adminMenuFile.close();

} else {

    cout << "Error updating adminmenu.txt." << endl;

}

    receiptFile.close();

    cout << "Order is complete. Total cost: $" << totalcost << endl;

        string line;

    ifstream areceiptFile("reciept.txt");



    if (!areceiptFile) {

        cout << "Error opening receipt.txt." << endl;

        return;

    }



    cout << "Receipt:\n";

    while (getline(areceiptFile, line)) {

        cout << line << endl;

    }



    areceiptFile.close();

    // opening file to delete

      		  ofstream afile("reciept.txt", std::ios::trunc); // Open file for writing (truncating)



  		  if (!afile) 

  			  {

     				   cout << "Error opening file." << endl;

         			   return;

    			  }



   			 afile.close(); // Close the file



   			 cout << "File contents deleted successfully." << endl;

    }

void Order::onlineorder()      //function to order online

{

       ifstream scheduledOrderFile("scheduledorder.txt");

    if (scheduledOrderFile.is_open()) 

    {

        string order;

        while (getline(scheduledOrderFile, order)) 

        {

            cout << order << endl;

        }

        scheduledOrderFile.close();

    }

    else 

    {

        cout << "Error opening scheduledorder.txt for reading." << endl;

    }

}












