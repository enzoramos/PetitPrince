/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DrawServiceImpl.hpp
 * Author: Enzo Ramos
 *
 * Created on 12 mars 2017, 16:51
 */

#ifndef DRAWSERVICEIMPL_HPP
#define DRAWSERVICEIMPL_HPP

#include "PetitPrince.hpp"


class DrawServiceImpl : virtual public POA_PetitPrince::DrawService,
                        virtual public PortableServer::RefCountServantBase{
public:
    DrawServiceImpl();
    DrawServiceImpl(const DrawServiceImpl& orig);
    virtual ~DrawServiceImpl();
    
    ::CORBA::Double area(::CORBA::Long id) override;
    ::CORBA::Double perimeter(::CORBA::Long id) override;
    void homothetie(::CORBA::Long id, ::CORBA::Double index) override;
    void translation(::CORBA::Long id, ::CORBA::Double x, ::CORBA::Double y) override;
    void rotation(::CORBA::Long id, ::CORBA::Double angle) override;
    void symCenter(::CORBA::Long id) override;
    void symAxial(::CORBA::Long id) override;
    
    void addDraw(::CORBA::Long pid, ::CORBA::Long cid) override;
    
    char* toString(::CORBA::Long id) override;
    
private:
    CORBA::ORB_var _orb;
    
};

#endif /* DRAWSERVICEIMPL_HPP */

