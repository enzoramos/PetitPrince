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

namespace PetitPrince {

    DrawingServiceImpl::DrawingServiceImpl(CORBA::ORB_var orb): _orb(orb) {
    }
    
    DrawingServiceImpl::DrawingServiceImpl() {
    }

    DrawingServiceImpl::DrawingServiceImpl(const DrawingServiceImpl& orig) {
    }

    DrawingServiceImpl::~DrawingServiceImpl() {
        _orb->shutdown(false);
    }
    
    ::CORBA::Long DrawingServiceImpl::pushDraw(const ::PetitPrince::Draw& d) {
        // TODO: code
    }
    
    ::CORBA::Long DrawingServiceImpl::replyDraw(const ::PetitPrince::MarkedDraw& marked_draw) {
        // TODO: code
    }

}
