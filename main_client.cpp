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

#include "Server.h"
#include "Client.h"
#include "PetitPrinceServiceImpl.hpp"

#include <cstdlib>
#include <iostream>
#include <omniORB4/CORBA.h>

using namespace std;

/*
int test() {
    return 0;
}
*/

int main(int argc, char** argv) {
    /*
     * First main, as tester
     */
    //int _int = 1;
    //bool b = false;
    //cout << _int << endl;
    //int a = 0;
    //if(!test()) {
    //    cout << "ok" << endl;
    //}
    
    //PetitPrince::Server s(10001);
    //s.start();
    //s.stop();
    
    CORBA::ORB_var orb;
    try {
        orb = CORBA::ORB_init(argc, argv);
        CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
        CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());
        
        CosNaming::Name name;
        name.length(1);
        name[0].id = (const char *) "DrawingService";
        name[0].kind = (const char *) "";
        
        CORBA::Object_var managerObj = nc->resolve(name);
        PetitPrince::DrawingService_var manager = PetitPrince::DrawingService::_narrow(managerObj.in());
        
        // TODO:
        PetitPrince::Draw draw;
        PetitPrince::MarkedDraw mDraw;
        long res;
        char exit = 'n';
        try {
            do {
                cout << "\nDrawing service client" << endl;
                cout << "----------------------------" << endl;
                
                // Invoke first remote method
                res = manager->pushDraw(draw);
                cout << "Push result long is: " << res << endl;
                cout << "------------------------------------------" << endl;
                
                // Invoke second remote method
                res = manager->replyDraw(mDraw);
                cout << "Reply result long is: " << res << endl;
                cout << "-------------------------------------------" << endl;
                
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

