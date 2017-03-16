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
#include "PetitPrinceServiceImpl.hpp"

using namespace std;


DrawServiceImpl::DrawServiceImpl(){
}

DrawServiceImpl::DrawServiceImpl(const DrawServiceImpl& orig){
}

DrawServiceImpl::DrawServiceImpl(CORBA::ORB_var orb): _orb(orb) {
}

DrawServiceImpl::~DrawServiceImpl(){
}

::CORBA::Double DrawServiceImpl::area(::CORBA::Long id) {
    ::PetitPrince::Draw* d = ::PetitPrinceServiceImpl::_draw_list.at(id);
    try{
        return d->area();
    } catch(::PetitPrince::DrawService::NonApplicable e) {
        cout << e.msg << endl;
    }
}

::CORBA::Double DrawServiceImpl::perimeter(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    try{
        return d->perimeter();
    } catch(::PetitPrince::DrawService::NonApplicable e) {
        cout << e.msg << endl;
    }
}

void DrawServiceImpl::homothetie(::CORBA::Long id, ::CORBA::Double index) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->homothetie(index);
}
void DrawServiceImpl::translation(::CORBA::Long id, ::CORBA::Double x, ::CORBA::Double y) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->translation(x,y);
}
void DrawServiceImpl::rotation(::CORBA::Long id, ::CORBA::Double angle) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->rotation(angle);
}
void DrawServiceImpl::symCenter(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->symCenter();
}
void DrawServiceImpl::symAxial(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->symAxial();
}

void DrawServiceImpl::addDraw(::CORBA::Long pid, ::CORBA::Long cid) {
    ::PetitPrince::Draw* parent = PetitPrinceServiceImpl::_draw_list.at(pid);
    ::PetitPrince::Draw* child = PetitPrinceServiceImpl::_draw_list.at(cid);
    if(parent->area() < parent->area()){
       throw ::PetitPrince::DrawService::UnexpectedDraw("L'aire du dessin est plus grande que celle du parent");
    }
    ::CORBA::ULong l = parent->inner_draws()->length();
    parent->inner_draws()->length(l+1);
    (*parent->inner_draws())[l] = child;
}

char* DrawServiceImpl::toString(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    return d->toString();
}

