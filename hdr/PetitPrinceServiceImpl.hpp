/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServiceDrawImpl.hpp
 * Author: jeremy
 *
 * Created on 10 mars 2017, 15:59
 */

#ifndef SERVICEDRAWIMPL_HPP
#define SERVICEDRAWIMPL_HPP

#include "ServiceDraw.hpp"

class PetitPrinceServiceImpl:
        virtual public POA_PetitPrince::PetitPrinceService,
        virtual public PortableServer::RefCountServantBase {

public:
    PetitPrinceServiceImpl();
    PetitPrinceServiceImpl(const PetitPrinceServiceImpl& orig);
    PetitPrinceServiceImpl(CORBA::ORB_var orb);
    virtual ~PetitPrinceServiceImpl();


    void pushDraw(::PetitPrince::Draw* d) override;
    void markDraw(::CORBA::Double mark, ::CORBA::Long id) override;
    ::PetitPrince::Draw* getDraw(::CORBA::Long id) override;
    ::PetitPrince::DrawSeq* draw_list() override;
    void draw_list(const ::PetitPrince::DrawSeq& _v) override;

private:
    CORBA::ORB_var _orb;

};


#endif /* SERVICEDRAWIMPL_HPP */

