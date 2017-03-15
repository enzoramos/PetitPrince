/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DrawServiceImpl.cpp
 * Author: Enzo Ramos
 * 
 * Created on 12 mars 2017, 16:51
 */

#include "DrawServiceImpl.hpp"

#include <iostream>

using namespace std;


DrawServiceImpl::DrawServiceImpl(){

}

DrawServiceImpl::DrawServiceImpl(const DrawServiceImpl& orig){

}

DrawServiceImpl::~DrawServiceImpl(){

}

void DrawServiceImpl::addDraw(::PetitPrince::Draw* parent, ::PetitPrince::Draw* child) {
    if(parent->area() < child->area()){
       throw ::PetitPrince::DrawService::unexpected_draw("L'aire du dessin est plus grande que celle du parent");
    }
    ::CORBA::ULong l = parent->inner_draws()->length();
    parent->inner_draws()->length(l+1);
    (*parent->inner_draws())[l] = child;
}

void DrawServiceImpl::homothetie(::PetitPrince::Draw* d, ::CORBA::Double indice) {
    d->homothetie(indice);

}

void DrawServiceImpl::rotation(::PetitPrince::Draw* d, ::CORBA::Double angle) {
    d->rotation(angle);
}

::CORBA::Double DrawServiceImpl::area(::PetitPrince::Draw* d) {
    try{
        return d->area();
    } catch(::PetitPrince::DrawService::non_applicable e) {
        cout << e.msg << endl;
    }
}

::CORBA::Double DrawServiceImpl::perimeter(::PetitPrince::Draw* d) {
    try{
        return d->perimeter();
    } catch(::PetitPrince::DrawService::non_applicable e) {
        cout << e.msg << endl;
    }
}

void DrawServiceImpl::symAxial(::PetitPrince::Draw* d) {
    d->symAxial();  
}

void DrawServiceImpl::symCenter(::PetitPrince::Draw* d) {
    d->symCenter();
}

char* DrawServiceImpl::toString(::PetitPrince::Draw* d) {
    return d->toString();
}

void DrawServiceImpl::translation(::PetitPrince::Draw* d, ::CORBA::Double x, ::CORBA::Double y) {
    d->translation(x,y);
}

