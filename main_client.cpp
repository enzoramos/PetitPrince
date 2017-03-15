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

#include "Server.hpp"
#include "Client.hpp"
#include "PetitPrinceServiceImpl.hpp"
#include "OBV_Draw.hpp"
#include "OBV_Circle.hpp"
#include "OBV_Ellipse.hpp"
#include "OBV_Line.hpp"
#include "OBV_Polygon.hpp"

#include <cstdlib>
#include <iostream>
#include <omniORB4/CORBA.h>

using namespace std;

/*
int test() {
    return 0;
}
*/

//int main(int argc, char** argv) {
//    /*
//     * First main, as tester
//     */
//    //int _int = 1;
//    //bool b = false;
//    //cout << _int << endl;
//    //int a = 0;
//    //if(!test()) {
//    //    cout << "ok" << endl;
//    //}
//    
//    //PetitPrince::Server s(10001);
//    //s.start();
//    //s.stop();
//    
//    CORBA::ORB_var orb;
//    try {
//        orb = CORBA::ORB_init(argc, argv);
//        CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
//        CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());
//        
//        CosNaming::Name name;
//        name.length(1);
//        name[0].id = (const char *) "PetitPrinceService";
//        name[0].kind = (const char *) "";
//        
//        CORBA::Object_var managerObj = nc->resolve(name);
//        PetitPrince::PetitPrinceService_var manager = PetitPrince::PetitPrinceService::_narrow(managerObj.in());
//        
//        // TODO:
//        ::PetitPrince::DrawSeq ds;
//        Draw* line1 = new Line(0L, (char*)"author", ds, 2.5, {1.2, 3.3}, {2, 5});
//        Draw* line2 = new Line(1L, (char*)"author", ds, 2.5, {1.2, 3.3}, {2, 5});
//        Draw* line3 = new Line(2L, (char*)"author", ds, 2.5, {1.2, 3.3}, {2, 5});
//        Draw* line4 = new Line(3L, (char*)"author", ds, 2.5, {1.2, 3.3}, {2, 5});
//        
//        char exit = 'n';
//        try {
//            do {
//                cout << "\nDrawing service client" << endl;
//                cout << "----------------------------" << endl;
//                try {
//                    // Invoke first remote method
//                    manager->pushDraw(line1);
//                    manager->pushDraw(line2);
//                    manager->pushDraw(line3);
//                    manager->pushDraw(line4);
//
//                    ::PetitPrince::DrawSeq* draws_list = manager->draw_list();
//                    ::PetitPrince::Draw* draw_1 = manager->getDraw(0);
//                    ::PetitPrince::Draw* draw_2 = manager->getDraw(1);
//                    
//                    cout << "Draw 1: " << draw_1 << endl;
//                    cout << "Draw 2: " << draw_2 << endl;
//
//                    manager->markDraw(1.5, 0);
//                    ::PetitPrince::Draw* draw_1_2 = manager->getDraw(0);
//                    cout << "Draw 1.2: " << draw_1_2 << endl;
//                } catch(const ::PetitPrince::DrawService::non_applicable& e) {
//                    cerr << e.msg << endl;
//                } catch(const ::PetitPrince::DrawService::unexpected_draw& e) {
//                    cerr << e.msg << endl;
//                }
//                cout << "Exit? (y/n): ";
//                cin >> exit;
//            } while(exit!='y');
//            
//            //TODO: Shutdown server message
//            
//        } catch(const std::exception& std_e) {
//            cerr << std_e.what() << endl;
//        }
//    } catch(const CORBA::Exception& e) {
//        // Handles CORBA exceptions
//        //cerr << e << endl;
//    }
//    
//    // End CORBA
//    if (!CORBA::is_nil(orb)) {
//        try {
//            orb->destroy();
//            cout << "Ending CORBA..." << endl;
//        } catch(const CORBA::Exception& e) {
//            //cerr << "orb->destroy failed:" << e << endl;
//            return 1;
//        }
//    }
//    
//    return 0;
//}

