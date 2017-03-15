/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Client.hpp"
#include "ServiceDraw.hpp"


Client::Client(int role, string name): _name(name), _role(role) {
}

int Client::role() {
    return this->_role;
}

void Client::role(int role) {
    this->_role = role;
}

string Client::name() {
    return this->_name;
}

void Client::name(string name) {
    this->_name = name;
}
