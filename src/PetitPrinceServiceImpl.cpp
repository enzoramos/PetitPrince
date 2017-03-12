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

virtual PetitPrinceServiceImpl::~PetitPrinceServiceImpl() {
    _orb->shutdown(false);
}


void PetitPrinceServiceImpl::pushDraw(::PetitPrince::Draw* d) override {
    
}

void PetitPrinceServiceImpl::markDraw(::CORBA::Long mark, ::CORBA::Long id) override {
    
}

::PetitPrince::Draw* PetitPrinceServiceImpl::getDraw(::CORBA::Long id) override {
    
}

::PetitPrince::DrawSeq* PetitPrinceServiceImpl::draw_list() override {
    
}

void PetitPrinceServiceImpl::draw_list(const ::PetitPrince::DrawSeq& _v) override {
    
}

