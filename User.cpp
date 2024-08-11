#include "User.h"

using namespace std;

User::User(char* n, char* p, int a, int b) : size1(a), size2(b) //constructor

{

    name = new char[size1 + 1];

    password = new char[size2 + 1];



    for (int i = 0; i < size1; i++) 

    {

        name[i] = n[i];

    }

    name[size1] = '\0';



    for (int i = 0; i < size2; i++) 

    {

        password[i] = p[i];

    }

    password[size2] = '\0';

}



bool User::compareCredentials(const char* storedName, const char* storedPassword)   //compare the credentials

{

    int i = 0;

    while (name[i] != '\0' && storedName[i] != '\0')    //compare the name

    {

        if (name[i] != storedName[i])       //if the name is not equal to the stored name

        {

            return false;

        }

        ++i;

    }

    if (name[i] == '\0' && storedName[i] == '\0')   //compare the password

    {

        i = 0;

        while (password[i] != '\0' && storedPassword[i] != '\0')    //if the password is not equal to the stored password

        {

            if (password[i] != storedPassword[i])   //if the password is not equal to the stored password

            {

                return false;

            }

            ++i;

        }

        return (password[i] == '\0' && storedPassword[i] == '\0');

    }

    return false;

}



bool User::login(const char* filename, const char* userType)    //login function

{

    char storedName[20], storedPassword[20];

    ifstream afile(filename);



    if (!afile) 

    {

        std::cout << "Error opening file: " << filename << std::endl;

        return false;

    }



    while (afile >> storedName >> storedPassword)   //read the file 

    {

        if (compareCredentials(storedName, storedPassword))     //compare the credentials

        {

            std::cout << "Login successful as " << userType << ": " << storedName << std::endl;

            afile.close();

            return true;

        }

    }



    std::cout << " ###################################################\n";

    std::cout << " |Invalid credentials for " << userType << ". Please try again. |\n";

    std::cout << " ###################################################\n";



    afile.close();

    return false;

}



User::~User() 

{

    delete[] name;

    delete[] password;

}


