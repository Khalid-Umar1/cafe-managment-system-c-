#ifndef ADMIN_H
#define ADMIN_H

#include "User.h" 
#include "Order.h"// Include User class header file
#include "Stock.h" // Include Stock class header file
#include "CompSugg.h" // Include CompSugg class header file
#include "Notification.h" // Include Notification class header file
using namespace std;
class Admin : public User
 {
private:
    Stock s1;
    CompSugg c1;
    Notification n1;
    Order o1;
public:
    Admin(char* n = nullptr, char* p = nullptr, int a = 0, int b = 0) : User(n, p, a, b) {}

    void action() override;
    void employeeStaff();
    void employeesearch(const string& searchname);
    void employeeadd(char* addname, char* salary, char* age, char* job);
    void employeeremove(const string& removeName);
    void employeedisplay();
};

#endif // ADMIN_H

