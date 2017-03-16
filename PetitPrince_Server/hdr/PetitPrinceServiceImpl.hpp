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

#include "PetitPrince.hpp"

#include <map>

using namespace std;

class PetitPrinceServiceImpl:
        virtual public POA_PetitPrince::PetitPrinceService,
        virtual public PortableServer::RefCountServantBase {

public:
    PetitPrinceServiceImpl();
    PetitPrinceServiceImpl(const PetitPrinceServiceImpl& orig);
    PetitPrinceServiceImpl(CORBA::ORB_var orb);
    virtual ~PetitPrinceServiceImpl();
    
    ::CORBA::Long createLine(const char* author, const ::PetitPrince::Point& a, const ::PetitPrince::Point& b) override;
    ::CORBA::Long createCircle(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double ray) override;
    ::CORBA::Long createEllipse(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double long_ray, ::CORBA::Double short_ray) override;
    ::CORBA::Long createPolygon(const char* author, const ::PetitPrince::PointSeq& pts) override;
    
    ::PetitPrince::LongSeq* getDraws(const char* author) override;
    void markDraw(::CORBA::Double mark, ::CORBA::Long id) override;
    

private:
    CORBA::ORB_var _orb;
    long cpt = 0;
    
public:
    static map<::CORBA::Long, ::PetitPrince::Draw*> _draw_list;
};


#endif /* SERVICEDRAWIMPL_HPP */

