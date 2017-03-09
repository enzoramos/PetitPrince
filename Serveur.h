//
// Created by Enzo Ramos on 05/03/2017.
//

#ifndef PETITPRINCE_SERVEUR_H
#define PETITPRINCE_SERVEUR_H

#include <vector>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <mutex>

#include "Client.h"
//#include "ServiceDraw.hh"

using namespace std;


class Serveur {

    public:
        Serveur(int port): _port(port){
            _clients = vector<Client>();
            _socket = socket(AF_INET, SOCK_STREAM, 0);

            if( socket < 0 ){
                cerr << "Error establishing socket..." << endl;
                exit(1);
            }

            _address.sin_family = AF_INET;
            _address.sin_addr.s_addr = htons(INADDR_ANY);
            _address.sin_port = htons(port);
        }
        ~Serveur();

        void Start();
        void Stop();
        void accept();
        /*Draw getDraw(int id);
        void pushDraw(Draw d);
        void markDraw(MarkedDraw d);*/

    private:
        //param serveur
        int _socket;
        int _port;
        struct sockaddr_in _address;
        socklen_t _size;

        // liste des clients
        vector<Client> _clients;

        mutex _mutex;
};


#endif //PETITPRINCE_SERVEUR_H
