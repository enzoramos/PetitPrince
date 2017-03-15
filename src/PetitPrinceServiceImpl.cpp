/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServiceDrawImpl.cpp
 * Author: jeremy
 * 
 * Created on 10 mars 2017, 16:00
 */

#include "PetitPrinceServiceImpl.hpp"


PetitPrinceServiceImpl::PetitPrinceServiceImpl() {
    
}

PetitPrinceServiceImpl::PetitPrinceServiceImpl(const PetitPrinceServiceImpl& orig) {
    
}

PetitPrinceServiceImpl::PetitPrinceServiceImpl(CORBA::ORB_var orb) {
    
}

PetitPrinceServiceImpl::~PetitPrinceServiceImpl() {
    _orb->shutdown(false);
}


void PetitPrinceServiceImpl::pushDraw(::PetitPrince::Draw* d) {
    
}

void PetitPrinceServiceImpl::markDraw(::CORBA::Double mark, ::CORBA::Long id) {
    
}

::PetitPrince::Draw* PetitPrinceServiceImpl::getDraw(::CORBA::Long id) {
    
}

::PetitPrince::DrawSeq* PetitPrinceServiceImpl::draw_list() {
    
}

void PetitPrinceServiceImpl::draw_list(const ::PetitPrince::DrawSeq& _v) {
    
}

