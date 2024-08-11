#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Notification.h"
#include "Order.h"
using namespace std;

class Stock 
{
	protected:
	    string itemname;
	    int s1;
	    string  price;
	    int s2;
	    string  quantity;
	    Order o1;
	    Notification n1;

	public:
	    
	    void stockaction();
	    void itemdisplay();
	    void itemsearch(const std::string& searchname);
	    void itemadd(char* addname, char* iprice, char* iquantity);
	    void itemremove(const std::string& removeName);
	    void bubblesort(string [] ,string [] ,string [],int);
};

#endif // STOCK_H

