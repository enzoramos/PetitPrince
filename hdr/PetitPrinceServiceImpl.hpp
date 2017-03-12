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

namespace PetitPrince {
    
    class DrawingServiceImpl:
            virtual public POA_PetitPrince::PetitPrinceService,
            virtual public PortableServer::RefCountServantBase {
        
    public:
        DrawingServiceImpl();
        DrawingServiceImpl(const DrawingServiceImpl& orig);
        DrawingServiceImpl(CORBA::ORB_var orb);
        virtual ~DrawingServiceImpl();
        
        virtual ::CORBA::Long pushDraw(const ::PetitPrince::Draw& d) override;
        virtual ::CORBA::Long replyDraw(const ::PetitPrince::MarkedDraw& marked_draw) override;
        
    private:
        CORBA::ORB_var _orb;
        
    };

}
#endif /* SERVICEDRAWIMPL_HPP */

