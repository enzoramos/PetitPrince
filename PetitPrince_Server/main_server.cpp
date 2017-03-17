/*!
 * \file main_client.cpp
 * \author Jeremy Bidet
 * \version 1.0
 *
 * \brief Define the server main.
 * 
 */

#include "PetitPrinceServiceImpl.hpp"
#include "DrawServiceImpl.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <omniORB4/CORBA.h>

using namespace std;

/*!
 * \def _draw_list constant map used to save every draws submitted
 */
map<::CORBA::Long, ::PetitPrince::Draw*> PetitPrinceServiceImpl::_draw_list;

/*!
 * \fn string longSeqToString(::PetitPrince::LongSeq* s)
 * \brief This method is used locally to ease the print of a Long sequence.
 * \param s a pointer to the Long sequence.
 * \return a user-friendly representation of the Long sequence.
 */
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
    
    // Define the main vars
    CORBA::ORB_var orb;
    PetitPrinceServiceImpl* ppsImpl;
    DrawServiceImpl* dsImpl;
    
    // Used to handle exception
    try {
        // Initialize the ORB
        orb = CORBA::ORB_init(argc, argv);        
        
        // Get the root POA var
        CORBA::Object_var rootPOAObj = orb->resolve_initial_references("RootPOA");
        PortableServer::POA_var rootPOA = PortableServer::POA::_narrow(rootPOAObj.in());
        
        // Get the Name Service context
        CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
        CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());

        // Initialize the services
        ppsImpl = new PetitPrinceServiceImpl(orb);
        dsImpl = new DrawServiceImpl(orb);
        
        // Activate the services in the root POA
        PortableServer::ObjectId_var o_ppsImpl = rootPOA->activate_object(ppsImpl);
        PortableServer::ObjectId_var o_dsImpl = rootPOA->activate_object(dsImpl);
        
        // Create the servant references
        CORBA::Object_var o_pps = rootPOA->servant_to_reference(ppsImpl);
        CORBA::Object_var o_ds = rootPOA->servant_to_reference(dsImpl);
        
        // Print some logs in server
        CORBA::String_var s;
        s = orb->object_to_string(o_pps);
        cout << endl << "The IOR of the PPS object is: " << s.in() << endl << endl;
        s = orb->object_to_string(o_ds);
        cout << endl << "The IOR of the DS object is: " << s.in() << endl << endl;
        
        // Create and bind the naming service for PetitPrince service
        CosNaming::Name petit_prince_service;
        petit_prince_service.length(1);
        petit_prince_service[0].id = (const char *) "PetitPrinceService";
        petit_prince_service[0].kind = (const char *) "";
        nc->rebind(petit_prince_service, o_pps);
        
        // Create and bind the naming service for Draw service
        CosNaming::Name draw_service;
        draw_service.length(1);
        draw_service[0].id = (const char *) "DrawService";
        draw_service[0].kind = (const char *) "";
        nc->rebind(draw_service, o_ds);
        
        // Get and activate the POA Manager
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
        
        // Run the ORB
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
            cout << "orb->destroy() failed:" << e._name() << endl;
            return 1;
        }
    }
    
    return 0;
}
