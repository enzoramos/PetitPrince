//
// Created by Enzo Ramos on 08/03/2017.
//

#ifndef PETITPRINCE_Client_H
#define PETITPRINCE_Client_H

#include <iostream>

using namespace std;

class Client {
    private :
        int role;
        string name;

    public :
        Client(int role, string name): name(name),role(role){};

        ~Client();
        int getRole();

};

#endif //PETITPRINCE_Client_H
