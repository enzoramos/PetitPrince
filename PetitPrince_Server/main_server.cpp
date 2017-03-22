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
#include <map>
#include <functional>
#include <thread>
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

void teacherRunnable(::PetitPrinceServiceImpl& ppsImpl, ::DrawServiceImpl& dsImpl) {
    bool exit = false;
    map<char, string> services_commands_name = {
        pair<char, string>('?', "Help"),
        pair<char, string>('_', "---------------------"),
        pair<char, string>('a', "Get draws by author"),
        pair<char, string>('b', "Mark a draw"),
        pair<char, string>('c', "---------------------"),
        pair<char, string>('x', "Exit (also !)")
    };
    map<char, function<void()>> services_commands = {
        //getDraws
        pair<char, function<void()>>('a', [&ppsImpl, &dsImpl] () {
            string author;
            cout << "Author: "; cout.flush(); cin >> author; cout << endl;
            ::PetitPrince::LongSeq* s = ppsImpl.getDraws(author.c_str());
            for(int i=0; i<s->length(); i++) { cout << dsImpl.toString((*s)[i]) << endl; }}),
        //area
        pair<char, function<void()>>('b', [&ppsImpl, &dsImpl] () {
            long id; double mark;
            cout << "Id: "; cout.flush(); cin >> id;
            cout << "Mark: "; cout.flush(); cin >> mark;
            ppsImpl.markDraw(mark, id);
            cout << endl << "Mark " << mark << " successfully given to draw (" << id << ")!" << endl; }),
        //help
        pair<char, function<void()>>('?', [] () {
            cout << "--------------------------------------------" << endl
                 << "------------------- HELP -------------------" << endl
                 << "--------------------------------------------" << endl
                 << "When you select an action, the command" << endl
                 << "prompt will ask you to give the needed" << endl
                 << "parameters for each functions." << endl
                 << "Then, it will execute the function and" << endl
                 << "print to you the result." << endl
                 << "--------------------------------------------" << endl
                 << "Parameters types and examples:" << endl
                 << endl
                 << "Author    -> string  (James Cameron)" << endl
                 << "ID        -> long    (1)" << endl
                 << "Mark     -> double" << endl
                 << "--------------------------------------------" << endl;
                cout << "Press a key then enter..." << endl; char _; cin >> _;cin.get(); }),
        //exit
        pair<char, function<void()>>('x', [&exit] () mutable -> void { exit = true; }),
        pair<char, function<void()>>('!', [&exit] () mutable -> void { exit = true; }),
        //empty
        pair<char, function<void()>>('_', [] () {}),
        pair<char, function<void()>>('c', [] () {})
    };
    // Loop to make a user command prompt
    try {
        cout << "PetitPrince service server (as teacher) started!" << endl;
        cout << "-----------------------------------" << endl;
        do {
            try {
                cout << endl << "Please select an operation and give needed parameters:" << endl;
                for(auto e : services_commands_name) {
                    cout << "(" << e.first << ") " << e.second << endl;
                }
                char c = '*';
                cout << ": "; cout.flush(); cin >> c;
                services_commands.at(c)();
            } catch(const ::PetitPrince::DrawService::NonApplicable& e) {
                cerr << e.msg << endl;
            } catch(const ::PetitPrince::DrawService::UnexpectedDraw& e) {
                cerr << e.msg << endl;
            }
        } while(!exit);
    } catch(const std::exception& std_e) {
        cerr << std_e.what() << endl;
    }
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
        
        // start new thread routine for teacher
        auto routine = [&ppsImpl, &dsImpl] () {
            bool exit = false;
            map<char, string> services_commands_name = {
                pair<char, string>('?', "Help"),
                pair<char, string>('_', "---------------------"),
                pair<char, string>('a', "Get draws by author"),
                pair<char, string>('b', "Mark a draw"),
                pair<char, string>('c', "---------------------"),
                pair<char, string>('x', "Exit (also !)")
            };
            map<char, function<void()>> services_commands = {
                //getDraws
                pair<char, function<void()>>('a', [&ppsImpl, &dsImpl] () {
                    string author;
                    cout << "Author: "; cout.flush(); cin >> author; cout << endl;
                    ::PetitPrince::LongSeq* s = ppsImpl->getDraws(author.c_str());
                    for(int i=0; i<s->length(); i++) { cout << dsImpl->toString((*s)[i]) << endl; }}),
                //area
                pair<char, function<void()>>('b', [&ppsImpl, &dsImpl] () {
                    long id; double mark;
                    cout << "Id: "; cout.flush(); cin >> id;
                    cout << "Mark: "; cout.flush(); cin >> mark;
                    ppsImpl->markDraw(mark, id);
                    cout << endl << "Mark " << mark << " successfully given to draw (" << id << ")!" << endl; }),
                //help
                pair<char, function<void()>>('?', [] () {
                    cout << "--------------------------------------------" << endl
                         << "------------------- HELP -------------------" << endl
                         << "--------------------------------------------" << endl
                         << "When you select an action, the command" << endl
                         << "prompt will ask you to give the needed" << endl
                         << "parameters for each functions." << endl
                         << "Then, it will execute the function and" << endl
                         << "print to you the result." << endl
                         << "--------------------------------------------" << endl
                         << "Parameters types and examples:" << endl
                         << endl
                         << "Author    -> string  (James Cameron)" << endl
                         << "ID        -> long    (1)" << endl
                         << "Mark     -> double" << endl
                         << "--------------------------------------------" << endl;
                        cout << "Press a key then enter..." << endl; char _; cin >> _;cin.get(); }),
                //exit
                pair<char, function<void()>>('x', [&exit] () mutable -> void { exit = true; }),
                pair<char, function<void()>>('!', [&exit] () mutable -> void { exit = true; }),
                //empty
                pair<char, function<void()>>('_', [] () {}),
                pair<char, function<void()>>('c', [] () {})
            };
            // Loop to make a user command prompt
            try {
                cout << endl << endl;
                cout << "----------------------------------------" << endl;
                cout << "PetitPrince server (as teacher) started!" << endl;
                cout << "----------------------------------------" << endl;
                do {
                    try {
                        cout << endl << "Please select an operation and give needed parameters:" << endl;
                        for(auto e : services_commands_name) {
                            cout << "(" << e.first << ") " << e.second << endl;
                        }
                        char c = '*';
                        cout << ": "; cout.flush(); cin >> c;
                        services_commands.at(c)();
                    } catch(const ::PetitPrince::DrawService::NonApplicable& e) {
                        cerr << e.msg << endl;
                    } catch(const ::PetitPrince::DrawService::UnexpectedDraw& e) {
                        cerr << e.msg << endl;
                    }
                } while(!exit);
                cout << endl << endl;
                cout << "--------------------------------------" << endl;
                cout << "PetitPrince server (as teacher) ended!" << endl;
                cout << "--------------------------------------" << endl;
            } catch(const std::exception& std_e) {
                cerr << std_e.what() << endl;
            }
        };
        thread teacher(routine);
        
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
