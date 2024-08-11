#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>

class User
{
	private:
 	char* name;
    	char* password;
    	int size1, size2;

	public:
    	User(char* n = nullptr, char* p = nullptr, int a = 0, int b = 0);
    	bool compareCredentials(const char* storedName, const char* storedPassword);
    	bool login(const char* filename, const char* userType);
    	virtual void action() =0;
    	~User();
};

#endif 

