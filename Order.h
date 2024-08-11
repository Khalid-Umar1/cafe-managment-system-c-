#ifndef ORDER_H
#define ORDER_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // for atoi
#include <cstring>
using namespace std;

class Order 
{
private:
    string orderName;
    int quant;
    int totalcost;
public:
    void adminorder();
    void studentorder ();
    void employeeorder ();
    void onlineorder();
};

#endif // ORDER_H

