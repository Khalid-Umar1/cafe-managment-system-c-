#ifndef COMPSUGG_H
#define COMPSUGG_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CompSugg {
private:
    string suggestion;
    string complain;

public:
    void comsuggadminaction();
    void comsuggstudentaction();
    void displaysugg();
    void displaycomp();
    void givecomp();
    void givesugg();
};

#endif // COMPSUGG_H

