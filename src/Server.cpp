//
// Created by Enzo Ramos on 08/03/2017.
//

#include "Server.hpp"
#include "ServiceDraw.hpp"

Server::Server(int port): _port(port) {
    _clients = vector<Client>();
    _socket = socket(AF_INET, SOCK_STREAM, 0);

    if( socket < 0 ){
        cerr << "Error establishing socket..." << endl;
        exit(1);
    }

    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = htons(INADDR_ANY);
    _address.sin_port = htons(port);

    _running = false;
}

void Server::start() {
    cout << "Server starting"; cout.flush();
    for(int i=0; i<250000000; i++) if(i%49999999==0) { cout << "."; cout.flush(); }
    cout << endl << "Server started on port " << _port << endl;
    _running = true;
}

void Server::stop() {
    if(!_running)
        return;

    cout << "Server stopping"; cout.flush();
    for(int i=0; i<250000000; i++) if(i%49999999==0) { cout << "."; cout.flush(); }
    cout << endl << "Server stopped on port " << _port << endl;
    _running = false;
}

void Server::accept() {
    // TODO
}

::PetitPrince::Draw& Server::getDraw(int id) {
    // TODO
}

void Server::pushDraw(::PetitPrince::Draw& d) {
    // TODO
}

void Server::markDraw(::PetitPrince::Draw& d, double mark) {
    // TODO
}

Server::~Server() {
    stop();
}

