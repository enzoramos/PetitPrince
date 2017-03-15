//
// Created by Enzo Ramos on 08/03/2017.
//

#ifndef PETITPRINCE_CLIENT_H
#define PETITPRINCE_CLIENT_H

#include <iostream>

using namespace std;

class Client {

public :
    Client(int role, string name);

    int role();
    void role(int role);
    string name();
    void name(string name);
    
private :
    int _role;
    string _name;

};


#endif //PETITPRINCE_CLIENT_H
