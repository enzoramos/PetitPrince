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
#include <omniORB4/CORBA.h>
#include <sstream>

using namespace std;


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
    try {
        orb = CORBA::ORB_init(argc, argv);
        CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
        CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());
        
        CosNaming::Name name;
        name.length(1);
        name[0].id = (const char *) "PetitPrinceService";
        name[0].kind = (const char *) "";
        
        ::CORBA::Object_var managerObj = nc->resolve(name);
        ::PetitPrince::PetitPrinceService_var pps_manager = ::PetitPrince::PetitPrinceService::_narrow(managerObj.in());
        
        name;
        name.length(1);
        name[0].id = (const char *) "DrawService";
        name[0].kind = (const char *) "";
        
        managerObj = nc->resolve(name);
        ::PetitPrince::DrawService_var ds_manager = ::PetitPrince::DrawService::_narrow(managerObj.in());
        
        // TODO:
        char exit = 'n';
        try {
            do {
                cout << "\nDrawing service client" << endl;
                cout << "----------------------------" << endl;
                try {
                    // Invoke first remote method
                    long b1 = pps_manager->createLine("Batard1", {0, 0}, {7, 1});
                    long b2 = pps_manager->createLine("Batard2", {0, 0}, {7, 2});
                    long b3 = pps_manager->createLine("Batard3", {0, 0}, {7, 3});
                    long b4 = pps_manager->createLine("Batard4", {0, 0}, {7, 4});
                    
                    ::PetitPrince::LongSeq* s = pps_manager->getDraws("Batard1");
                    cout << longSeqToString(s) << endl;
                    long l = s->length();
                    for(int i=0; i<l; i++) {
                        cout << ds_manager->toString((*s)[i]) << endl;
                    }
                    pps_manager->markDraw(2.5, b1);
                    
                    s = pps_manager->getDraws("Batard1");
                    cout << longSeqToString(s) << endl;
                    l = s->length();
                    for(int i=0; i<l; i++) {
                        cout << ds_manager->toString((*s)[i]) << endl;
                    }
                    
                } catch(const ::PetitPrince::DrawService::NonApplicable& e) {
                    cerr << e.msg << endl;
                } catch(const ::PetitPrince::DrawService::UnexpectedDraw& e) {
                    cerr << e.msg << endl;
                }
                cout << "Exit? (y/n): ";
                cin >> exit;
            } while(exit!='y');
            
            //TODO: Shutdown server message
            
        } catch(const std::exception& std_e) {
            cerr << std_e.what() << endl;
        }
    } catch(const CORBA::Exception& e) {
        // Handles CORBA exceptions
        //cerr << e << endl;
    }
    
    // End CORBA
    if (!CORBA::is_nil(orb)) {
        try {
            orb->destroy();
            cout << "Ending CORBA..." << endl;
        } catch(const CORBA::Exception& e) {
            //cerr << "orb->destroy failed:" << e << endl;
            return 1;
        }
    }
    return 0;
}


