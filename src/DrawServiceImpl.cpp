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


DrawServiceImpl::DrawServiceImpl(){

}

DrawServiceImpl::DrawServiceImpl(const DrawServiceImpl& orig){

}

virtual DrawServiceImpl::~DrawServiceImpl(){

}

void DrawServiceImpl::addDraw(::PetitPrince::Draw* parent, ::PetitPrince::Draw* child) {
    if(parent->area() < child->area()){
       throw ::PetitPrince::DrawService::unexpected_draw("L'aire du dessin est plus grande que celle du parent");
    }
    parent->inner_draws() = child;
}

void DrawServiceImpl::homothetie(::PetitPrince::Draw* d, ::CORBA::Long indice) {
    d->homothetie(indice);

}

void DrawServiceImpl::rotation(::PetitPrince::Draw* d, ::CORBA::Long angle) {
    d->rotation(angle);
}

::CORBA::Long DrawServiceImpl::area(::PetitPrince::Draw* d) {
    try{
        return d->area();
    } catch(::PetitPrince::DrawService::non_applicable e) {
        std::cout << e << std::endl;
    }
}

::CORBA::Long DrawServiceImpl::perimeter(::PetitPrince::Draw* d) {
    try{
        return d->perimeter();
    } catch(::PetitPrince::DrawService::non_applicable e) {
        std::cout << e << std::endl;
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

void DrawServiceImpl::translation(::PetitPrince::Draw* d, ::CORBA::Long x, ::CORBA::Long y) {
    d->translation(x,y);
}

