//
// Created by Enzo Ramos on 08/03/2017.
//

#ifndef PETITPRINCE_Client_H
#define PETITPRINCE_Client_H

#include <iostream>

using namespace std;

class Client {
    private :
        int _role;
        string _name;

    public :
        Client(int role, string name): _name(name), _role(role) {};
        
        int getRole();

};

#endif //PETITPRINCE_Client_H
