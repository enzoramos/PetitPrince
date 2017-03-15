//
// Created by Enzo Ramos on 05/03/2017.
//

#ifndef PETITPRINCE_SERVEUR_H
#define PETITPRINCE_SERVEUR_H


#include "Client.hpp"
#include "ServiceDraw.hpp"

#include <vector>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <mutex>


using namespace std;

class Server {
public:
    Server(): Server(10000) {};
    Server(int port);
    ~Server();

    void start();
    void stop();
    void accept();
    ::PetitPrince::Draw& getDraw(int id);
    void pushDraw(::PetitPrince::Draw& d);
    void markDraw(::PetitPrince::Draw& d, double mark);

private:
    //server params
    int _socket;
    int _port;
    struct sockaddr_in _address;
    socklen_t _size;

    // clients list
    vector<Client> _clients;

    mutex _mutex;

    bool _running;
};


#endif //PETITPRINCE_SERVEUR_H
