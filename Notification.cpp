#include "Notification.h"



   void Notification::notiadminaction()

      {

          

      

            int a;

            npoint:

           

 	        cout<< " -------------------------------\n";

 	        cout<< " | (1) Display Notification    |\n | (2) Delete Notification     |\n | (3) Write Notification      |\n | (4) Exit                    |\n";

 	        cout<< " -------------------------------\n";

         

	        cout<< " Please Enter the corresponding number.\n";

      	        cin>>a;

                

                switch (a)

  	           {

         		case 1:

            		     {

           		        cout << " ---------------------------------- -\n";

		                cout << " |       Display Notification      |\n"; 

    		     	        cout << " -----------------------------------\n";

                	        

                	        displaynoti();

      		                goto npoint;

                 	     }

           		break;

           		

         		case 2: 

                	    { 

                  

       		               cout << " -----------------------------------\n";

          	               cout << " |       Delete Notification       |\n"; 

 	       		       cout << " -----------------------------------\n";                   

                   

                 		deletenoti();	 	

                		   goto npoint;

                 	    }

                         break;

                         

     			 case 3: 

                                {

                   

                                  cout << " --------------------------------------\n";

                                  cout << " |        Write Notification          |\n"; 

    		   		  cout << " --------------------------------------\n";                   

                                  

                                  writenoti();

                 		  goto npoint;

                		 }

             		  break;

             

           		  case 4:

                   		{

                               		cout << " Exiting \n\n";

                     			return;

                   		}

           

        		 default : 

                 		 { 

                   			cout << "#################################################\n";

                 		        cout << "| Invalid Input.:( . Please enter between (1-4) |\n"; 

          			        cout << "#################################################\n";

                   

                  			 goto npoint;

                 		}

      

       		  }

      

      }

  

  void Notification::displaynoti()//dsiplay not 

      {

         ifstream afile("notification.txt");

        

          if (!afile) 

           {

              cout << " Error opening file." << endl;

              return;

           }

           

          while (getline(afile, noti))

           { 

              

              	cout << noti << endl<<endl;

   

 	   }

             afile.close();

      

      }

      

      	void Notification::writenoti() //write noti

		{

			  ofstream afile("notification.txt", std::ios::app);		



   			 if (!afile) 

  				  {	

 				       cout << "Error opening file." << endl;

        				return;

    				  }

    				  

       			   // Maximum length of the input line

       			   const int a = 100;

    			  char* name;

    			  name=new char [a] ;



    		          char* note = new char[a]; // Dynamically allocate memory for the character array



    			  cout << " Enter the Notification: \n";

			   cin.getline(name, a); // Read input line

			   cin.getline(note, a);

  			  afile << "Notification : " << note << endl; // Write the notification to the file



  			  delete[] note; // Deallocate memory for the character array

	 		  afile.close(); // Close the file

		}

 	void Notification::deletenoti()

 	      {

 	                

  		  ofstream afile("notification.txt", std::ios::trunc); // Open file for writing (truncating)



  		  if (!afile) 

  			  {

     				   cout << "Error opening file." << endl;

         			   return;

    			  }



   			 afile.close(); // Close the file



   			 cout << "File contents deleted successfully." << endl;



 	     

 	      }



 	void Notification::admindeletenoti()

 	      {

 	                

  		  ofstream afile("adminnotification.txt", std::ios::trunc); // Open file for writing (truncating)



  		  if (!afile) 

  			  {

     				   cout << "Error opening file." << endl;

         			   return;

    			  }



   			 afile.close(); // Close the file

 	     

 	      }



void Notification::admindisplaynoti() 

{

    ifstream afile("adminmenu.txt");

    ofstream notificationFile("adminnotification.txt", std::ios::app);



    if (!afile || !notificationFile) 
    {

        cout << "Error opening file." << endl;

        return;

    }



    string iname, iprice, iquantity;

    bool lowQuantity = false;



    while (afile >> iname >> iprice >> iquantity)//read from file
     {

        int quantity = stoi(iquantity);//convert string to int

        if (quantity <= 0 || quantity < 10) 
        {

            notificationFile << "Item: " << iname << " has low quantity (" << quantity << "). Please reorder it.\n";//write to file

            lowQuantity = true;

        }

    }



    if (!lowQuantity)
     {

        notificationFile << "No items with low quantity found.\n";

    }



    afile.close();//close file

    notificationFile.close();//close file

    

        ifstream File("adminnotification.txt");



    if (!File) {

        cout << "Error opening file." << endl;

        return;

    }



    cout << "Notifications:\n";



    string notification;

    while (getline(File, notification))//read from file
    {

        cout << notification << endl;

    }



    notificationFile.close();

    admindeletenoti();

}






