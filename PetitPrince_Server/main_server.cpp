/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jerem
 *
 * Created on 6 mars 2017, 20:06
 */

#include "PetitPrinceServiceImpl.hpp"
#include "DrawServiceImpl.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <omniORB4/CORBA.h>

using namespace std;


map<::CORBA::Long, ::PetitPrince::Draw*> PetitPrinceServiceImpl::_draw_list;

string longSeqToString(::PetitPrince::LongSeq* s) {
    stringstream ss;
    if(s->length() <= 0) {
        return "empty";
    }
    ss << (*s)[0];
    long l = s->length();
    for(int i = 1; i<l; i++) {
        ss << ", " << (*s)[i];
    }
    return ss.str();
}

int main(int argc, char** argv) {
    
    CORBA::ORB_var orb;
    PetitPrinceServiceImpl* ppsImpl;
    DrawServiceImpl* dsImpl;
    
    try {
        orb = CORBA::ORB_init(argc, argv);        
        
        CORBA::Object_var rootPOAObj = orb->resolve_initial_references("RootPOA");
        PortableServer::POA_var rootPOA = PortableServer::POA::_narrow(rootPOAObj.in());
        
        CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
        
        CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());

        ppsImpl = new PetitPrinceServiceImpl(orb);
        dsImpl = new DrawServiceImpl(orb);
        
        PortableServer::ObjectId_var o_ppsImpl = rootPOA->activate_object(ppsImpl);
        PortableServer::ObjectId_var o_dsImpl = rootPOA->activate_object(dsImpl);
        
        CORBA::Object_var o_pps = rootPOA->servant_to_reference(ppsImpl);
        CORBA::Object_var o_ds = rootPOA->servant_to_reference(dsImpl);
        
        CORBA::String_var s;
        s = orb->object_to_string(o_pps);
        cout << endl << "The IOR of the PPS object is: " << s.in() << endl << endl;
        s = orb->object_to_string(o_ds);
        cout << endl << "The IOR of the DS object is: " << s.in() << endl << endl;
        
        CosNaming::Name petit_prince_service;
        petit_prince_service.length(1);
        petit_prince_service[0].id = (const char *) "PetitPrinceService";
        petit_prince_service[0].kind = (const char *) "";
        nc->rebind(petit_prince_service, o_pps);
        
        CosNaming::Name draw_service;
        draw_service.length(1);
        draw_service[0].id = (const char *) "DrawService";
        draw_service[0].kind = (const char *) "";
        nc->rebind(draw_service, o_ds);
        
        PortableServer::POAManager_var poamanager = rootPOA->the_POAManager();
        poamanager->activate();
        cout << "The server is ready. Awaiting for incoming requests..." << endl;
        /*
        ppsImpl->createLine("Batard1", {0, 0}, {7, 1});
        ppsImpl->createLine("Batard2", {0, 0}, {7, 2});
        ppsImpl->createLine("Batard3", {0, 0}, {7, 3});
        ppsImpl->createLine("Batard1", {0, 1}, {7, 4});
        ::PetitPrince::LongSeq* __s = ppsImpl->getDraws("Batard1");
        cout << longSeqToString(__s) << endl;
        cout << dsImpl->toString(0) << endl;
        long l = __s->length();
        for(int i=0; i<l; i++) {
            cout << dsImpl->toString((*__s)[i]) << endl;
        }*/
        
        orb->run();
        
    } catch(const CORBA::Exception& e) {
        cerr << e._name() << endl;
    }
    
    if(ppsImpl)
        ppsImpl->_remove_ref();
    
    if (!CORBA::is_nil(orb)) {
        try {
            orb->destroy();
            cout << "Ending CORBA..." << endl;
        } catch (const CORBA::Exception& e) {
//            cout << "orb->destroy() failed:" << e << endl;
            return 1;
        }
    }
    
    return 0;
}
