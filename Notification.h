#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Notification {
private:
    std::string noti;

public:
    void notiadminaction();
    void displaynoti();
    void writenoti();
    void deletenoti();
    void admindisplaynoti();
    void admindeletenoti();
};

#endif // NOTIFICATION_H

