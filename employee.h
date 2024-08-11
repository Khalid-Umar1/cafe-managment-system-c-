#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h" // Include User class header file
#include "Stock.h" // Include Stock class header file// Include CompSugg class header file
#include "Notification.h" // Include Notification class header file
#include "Order.h"
using namespace std;
class Employee : public User {
private:
    Stock s1;
    Notification n1;
    Order o1;
public:
    Employee(char* n = nullptr, char* p = nullptr, int a = 0, int b = 0) : User(n, p, a, b) {}

    void action() override;

};

#endif // ADMIN_H
