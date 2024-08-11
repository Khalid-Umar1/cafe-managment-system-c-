#include "CompSugg.h"



   void CompSugg::comsuggadminaction()

      {

            int a;

            spoint:

           

 	        cout<< " -------------------------------\n";

 	        cout<< " | (1) Display Complains       |\n | (2) Display Suggestion      |\n | (3) Reply to Complains      |\n | (4) Exit                    |\n";

 	        cout<< " -------------------------------\n";

         

	         cout<< " Please Enter the corresponding number.\n";

      	   cin>>a;

	       switch (a)

  	           {

         		case 1:

            		     {

           		        cout << " --------------------------------\n";

		                cout << " |       Complains Display      |\n"; 

    		     	        cout << " --------------------------------\n";

                	        displaycomp();

      		                goto spoint;

                 	     }

           		break;

           		

         		case 2: 

                	    { 

                  

       		               cout << " ----------------------------------\n";

          	               cout << " |       Suggestion Display       |\n"; 

 	       		       cout << " ----------------------------------\n";                   

                   

                 	 	 displaysugg();

                		   goto spoint;

                 	    }

                         break;

                         

     			 case 3: 

                                {

                   

                                  cout << " --------------------------------------\n";

                                  cout << " |        Reply to complains          |\n"; 

    		   		  cout << " --------------------------------------\n";                   

                                   givecomp();

                 		  goto spoint;

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

                   

                  			 goto spoint;

                 		}

      

       		  }

     }

   void CompSugg::comsuggstudentaction()

      {

            int a;

            spoint:

           

 	        cout<< " -------------------------------\n";

 	        cout<< " | (1) Write Complains         |\n | (2) Write Suggestion      |\n | (3) Exit                    |\n";

 	        cout<< " -------------------------------\n";

         

	         cout<< " Please Enter the corresponding number.\n";

      	   cin>>a;

	       switch (a)

  	           {

         		case 1:

            		     {

           		        cout << " ------------------------------\n";

		                cout << " |       Write Complains      |\n"; 

    		     	        cout << " ------------------------------\n";

                	        givecomp();

      		                goto spoint;

                 	     }

           		break;

           		

         		case 2: 

                	    { 

                  

       		               cout << " --------------------------------\n";

          	               cout << " |       Write Suggestion       |\n"; 

 	       		       cout << " ---------------------------- ---\n";                   

                   

                 	 	 givesugg();

                		   goto spoint;

                 	    }

                         break;

             

           		  case 3:

                   		{

                               		cout << " Exiting \n\n";

                     			return;

                   		}

           

        		 default : 

                 		 { 

                   			cout << "#################################################\n";

                 		        cout << "| Invalid Input.:( . Please enter between (1-4) |\n"; 

          			        cout << "#################################################\n";

                   

                  			 goto spoint;

                 		}

      

       		  }

     }

     

   void CompSugg::displaysugg()

     {

        ifstream efile("sugg.txt");

          if (!efile) 

           {

              cout << " Error opening file." << endl;

              return;

           }

        // string isugg;

           getline(efile,suggestion);

                cout << " Suggestion: \n "<< suggestion << endl;  

        

          efile.close();

     

     }

 void CompSugg::displaycomp()     

     {

        ifstream afile("comp.txt");

        

          if (!afile) 

           {

              cout << " Error opening file." << endl;

              return;

           }

           int i=0;

         //string icomp;

          while (getline(afile, complain))

           { 

              

              	cout << "Complain "<<i+1<<" : "<< endl << complain << endl<<endl;

              i++;

 	   }

             afile.close();

          

     }

	void CompSugg::givecomp() 

		{

			ofstream afile("comp.txt", std::ios::app);



   			 if (!afile)

     				{

        				cout << "Error opening file." << endl;

        				return ;

    				}

    			const int s = 20; // Maximum length of the input line

    			char name[s];

    

    			const int size = 100; // Maximum length of the input line

    			char comp[size];

    			

    			cin.getline(name, s); // Read input line

    

   			cout << "Enter your name: ";

          		cin.getline(name, s);

   			cout << "Enter your complaint: ";

    			cin.getline(comp, size); // Read input line

			

			cout<<name<<" : "<< comp << endl;

 			afile <<name<<" : "<< comp << endl; // Write the complaint to the file



    			afile.close();

		}

		

	void CompSugg::givesugg() 

		{

			ofstream afile("sugg.txt", std::ios::app);



   			 if (!afile)

     				{

        				cout << "Error opening file." << endl;

        				return ;

    				}

    			const int s = 20; // Maximum length of the input line

    			char name[s];

    

    			const int size = 100; // Maximum length of the input line

    			char sugg[size];

    			

    			cin.getline(name, s); // Read input line

    

   			cout << "Enter your name: ";

          		cin.getline(name, s);

   			cout << "Enter your Suggestion: ";

    			cin.getline(sugg, size); // Read input line

			

			cout<<name<<" : "<< sugg << endl;

			

 			afile <<name<<" : "<< sugg << endl; // Write the complaint to the file



    			afile.close();

		}


