#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "User.h" // Include User class header file
#include "CompSugg.h" // Include CompSugg class header file
#include "Notification.h" // Include Notification class header file
#include "Order.h"
#include "Stock.h"

using namespace std;

class Student : public User 
{
private:
    Stock s1;
    CompSugg c1;
    Notification n1;
    Order o1;
    
public:
    Student(char* n = nullptr, char* p = nullptr, int a = 0, int b = 0) : User(n, p, a, b) {}

    void action() override;
};

#endif // ADMIN_H	
