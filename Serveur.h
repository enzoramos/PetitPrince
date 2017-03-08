//
// Created by Enzo Ramos on 05/03/2017.
//

#ifndef PETITPRINCE_SERVEUR_H
#define PETITPRINCE_SERVEUR_H


#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Client.h"
#include "ServiceDraw.hh"

using namespace std;


class Serveur {

    private:
        //param serveur
        int socket;
        int port;
        struct sockaddr_in adress;
        socklen_t size;

        // liste des clients
        vector<Client&> clients;

        mutex mutex;

    public:
        Serveur(int port):port(port){
            clients = vector<Client&>();
            socket = socket(AF_INET, SOCK_STREAM, 0);

            if( socket < 0 ){
                cerr << "Error establishing socket..." << endl;
                exit(1);
            }

            adress.sin_family = AF_INET;
            adress.sin_addr.s_addr = htons(INADDR_ANY);
            adress.sin_port = htons(port);
        }
        ~Serveur();

        void Start();
        void Stop();
        void accept();
        Draw getDraw(int id);
        void pushDraw(Draw d);
        void markDraw(MarkedDraw d);

};


#endif //PETITPRINCE_SERVEUR_H
