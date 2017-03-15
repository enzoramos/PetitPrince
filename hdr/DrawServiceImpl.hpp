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

#include "ServiceDraw.hpp"


class DrawServiceImpl : virtual public POA_PetitPrince::DrawService,
                        virtual public PortableServer::RefCountServantBase{
public:
    DrawServiceImpl();
    DrawServiceImpl(const DrawServiceImpl& orig);
    virtual ~DrawServiceImpl();
    
    void addDraw(::PetitPrince::Draw* parent, ::PetitPrince::Draw* child) override;
    void homothetie(::PetitPrince::Draw* d, ::CORBA::Double indice) override;
    void rotation(::PetitPrince::Draw* d, ::CORBA::Double angle) override;
    void translation(::PetitPrince::Draw* d, ::CORBA::Double x, ::CORBA::Double y) override;
    ::CORBA::Double area(::PetitPrince::Draw* d) override;
    ::CORBA::Double perimeter(::PetitPrince::Draw* d) override;
    void symAxial(::PetitPrince::Draw* d) override;
    void symCenter(::PetitPrince::Draw* d) override;
    char* toString(::PetitPrince::Draw* d) override;
    
private:
    CORBA::ORB_var _orb;
    
};

#endif /* DRAWSERVICEIMPL_HPP */

