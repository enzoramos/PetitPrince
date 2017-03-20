/*!
 * \file main_client.cpp
 * \author Enzo Ramos
 * \version 1.0
 *
 * \brief Define the client main.
 * 
 */

#include "PetitPrince.hpp"

#include <omniORB4/CORBA.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <map>
#include <functional>

using namespace std;



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
    
    // Used to handle exception
    try {
        // Initialize the ORB
        orb = CORBA::ORB_init(argc, argv);
        
        // Get the Naming Service context
        CORBA::Object_var rootContextObj = orb->resolve_initial_references("NameService");
        CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow(rootContextObj.in());
        
        // Create the naming service for PetitPrince service
        CosNaming::Name pps;
        pps.length(1);
        pps[0].id = (const char *) "PetitPrinceService";
        pps[0].kind = (const char *) "";
        // Get the reference for the PetitPrince service in naming service
        ::CORBA::Object_var managerObj = nc->resolve(pps);
        ::PetitPrince::PetitPrinceService_var pps_manager = ::PetitPrince::PetitPrinceService::_narrow(managerObj.in());
        
        // Create the naming service for Draw service
        CosNaming::Name ds;
        ds.length(1);
        ds[0].id = (const char *) "DrawService";
        ds[0].kind = (const char *) "";
        // Get the reference for the Draw service in naming service
        managerObj = nc->resolve(ds);
        ::PetitPrince::DrawService_var ds_manager = ::PetitPrince::DrawService::_narrow(managerObj.in());
        
        bool exit = false;
        map<char, string> services_commands_name = {
            pair<char, string>('?', "Help"),
            pair<char, string>('_', "---------------------"),
            pair<char, string>('a', "Create a line"),
            pair<char, string>('b', "Create a circle"),
            pair<char, string>('c', "Create an ellipse"),
            pair<char, string>('d', "Create a polygon"),
            pair<char, string>('e', "---------------------"),
            pair<char, string>('f', "Get draws by author"),
            pair<char, string>('g', "---------------------"),
            pair<char, string>('h', "Get area"),
            pair<char, string>('i', "Get perimeter"),
            pair<char, string>('j', "---------------------"),
            pair<char, string>('k', "Apply homothetie"),
            pair<char, string>('l', "Apply translation"),
            pair<char, string>('m', "Apply rotation"),
            pair<char, string>('n', "Apply central symetry"),
            pair<char, string>('o', "Apply axial symetry"),
            pair<char, string>('p', "---------------------"),
            pair<char, string>('q', "Add an inner draw"),
            pair<char, string>('r', "---------------------"),
            pair<char, string>('x', "Exit (also !)")
        };
        map<char, function<void()>> services_commands = {
            //createLine
            pair<char, function<void()>>('a', [&ds_manager, &pps_manager] () {
                string author; double x, y; PetitPrince::Point a, b;
                cout << "Author: "; cout.flush(); cin >> author;
                cout << "Start: "; cout.flush(); cin >> x >> y; a = {x, y};
                cout << "End: "; cout.flush(); cin >> x >> y; b = {x, y};
                cout << endl << "Line (" << pps_manager->createLine(author.c_str(), a, b) << ") successfully created!" << endl; }),
            //createCircle
            pair<char, function<void()>>('b', [&ds_manager, &pps_manager] () {
                string author; double x, y; PetitPrince::Point center; double ray;
                cout << "Author: "; cout.flush(); cin >> author;
                cout << "Center: "; cout.flush(); cin >> x >> y; center = {x, y};
                cout << "Ray: "; cout.flush(); cin >> ray;
                cout << endl << "Circle (" << pps_manager->createCircle(author.c_str(), center, ray) << ") successfully created!" << endl; }),
            //createEllipse
            pair<char, function<void()>>('c', [&ds_manager, &pps_manager] () {
                string author; double x, y; PetitPrince::Point center; double long_ray, short_ray;
                cout << "Author: "; cout.flush(); cin >> author;
                cout << "Center: "; cout.flush(); cin >> x >> y; center = {x, y};
                cout << "Rays: "; cout.flush(); cin >> long_ray >> short_ray;
                cout << endl << "Ellipse (" << pps_manager->createEllipse(author.c_str(), center, long_ray, short_ray) << ") successfully created!" << endl; }),
            //createPolygon
            pair<char, function<void()>>('d', [&ds_manager, &pps_manager] () {
                string author; int l; double x, y; PetitPrince::PointSeq pts;
                cout << "Author: "; cout.flush(); cin >> author;
                cout << "Points quantity? "; cout.flush(); cin >> l; pts.length(l);
                cout << "Points: "; cout.flush(); for(int i=0; i<l; i++) { cin >> x >> y; pts[i] = {x, y}; }
                cout << endl << "Polygon (" << pps_manager->createPolygon(author.c_str(), pts) << ") successfully created!" << endl; }),
            //getDraws
            pair<char, function<void()>>('f', [&ds_manager, &pps_manager] () {
                string author;
                cout << "Author: "; cout.flush(); cin >> author; cout << endl;
                ::PetitPrince::LongSeq* s = pps_manager->getDraws(author.c_str());
                for(int i=0; i<s->length(); i++) { cout << ds_manager->toString((*s)[i]) << endl; }}),
            //area
            pair<char, function<void()>>('h', [&ds_manager, &pps_manager] () {
                long id;
                cout << "Id: "; cout.flush(); cin >> id;
                cout << endl << "Area: " << ds_manager->area(id) << endl; }),
            //perimeter
            pair<char, function<void()>>('i', [&ds_manager, &pps_manager] () {
                long id;
                cout << "Id: "; cout.flush(); cin >> id;
                cout << endl << "Perimeter: " << ds_manager->perimeter(id) << endl; }),
            //homothetie
            pair<char, function<void()>>('k', [&ds_manager, &pps_manager] () {
                long id; double index;
                cout << "Id: "; cout.flush(); cin >> id;
                cout << "Index: "; cout.flush(); cin >> index;
                ds_manager->homothetie(id, index);
                cout << endl << "Homothetie successfully updated!" << endl; }),
            //translation
            pair<char, function<void()>>('l', [&ds_manager, &pps_manager] () {
                long id; double x, y;
                cout << "Id: "; cout.flush(); cin >> id;
                cout << "X Y: "; cout.flush(); cin >> x >> y;
                ds_manager->translation(id, x, y);
                cout << endl << "Translation successfully updated!" << endl; }),
            //rotation
            pair<char, function<void()>>('m', [&ds_manager, &pps_manager] () {
                long id; double angle;
                cout << "Id: "; cout.flush(); cin >> id;
                cout << "Angle: "; cout.flush(); cin >> angle;
                ds_manager->rotation(id, angle);
                cout << endl << "Rotation successfully updated!" << endl; }),
            //symCenter
            pair<char, function<void()>>('n', [&ds_manager, &pps_manager] () {
                long id;
                cout << "Id: "; cout.flush(); cin >> id;
                ds_manager->symCenter(id);
                cout << endl << "Central symetry successfully updated!" << endl; }),
            //symAxial
            pair<char, function<void()>>('o', [&ds_manager, &pps_manager] () {
                long id;
                cout << "Id: "; cout.flush(); cin >> id;
                ds_manager->symAxial(id);
                cout << endl << "Axial symetry successfully updated!" << endl; }),
            //addDraw
            pair<char, function<void()>>('q', [&ds_manager, &pps_manager] () {
                long pid, cid;
                cout << "ParentID ChildID: "; cout.flush(); cin >> pid >> cid;
                ds_manager->addDraw(pid, cid);
                cout << endl << "Successfully added inner draw (" << cid << ") to parent draw (" << pid << ") !" << endl; }),
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
                     << "Start     -> point   (0.5 2)" << endl
                     << "End       -> point" << endl
                     << "Center    -> point" << endl
                     << "Ray       -> double  (2.5456)" << endl
                     << "Rays      -> doubles (2.5456 0.419)" << endl
                     << "Points    -> points  (0.5 2 1.2 6 8 0...)" << endl
                     << "ID        -> long    (1)" << endl
                     << "Index     -> double" << endl
                     << "Angle     -> double" << endl
                     << "X Y       -> doubles" << endl
                     << "--------------------------------------------" << endl;
                    cout << "Press a key then enter..." << endl; char _; cin >> _;cin.get(); }),
            //exit
            pair<char, function<void()>>('x', [&exit] () mutable -> void { exit = true; }),
            pair<char, function<void()>>('!', [&exit] () mutable -> void { exit = true; }),
            //empty
            pair<char, function<void()>>('_', [] () {}),
            pair<char, function<void()>>('e', [] () {}),
            pair<char, function<void()>>('j', [] () {}),
            pair<char, function<void()>>('p', [] () {}),
            pair<char, function<void()>>('r', [] () {})
        };
        
        // Loop to make a user command prompt
        try {
            cout << "PetitPrince service client started!" << endl;
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
    } catch(const CORBA::Exception& e) {
        // Handles CORBA exceptions
        cerr << e._name() << endl;
    }
    
    // End CORBA
    if (!CORBA::is_nil(orb)) {
        try {
            orb->destroy();
            cout << "Ending CORBA..." << endl;
        } catch(const CORBA::Exception& e) {
            cerr << "orb->destroy failed:" << e._name() << endl;
            return 1;
        }
    }
    return 0;
}


// This is the old body test of the try catch loop for the client main.
void old_body(::PetitPrince::PetitPrinceService_var& pps_manager, ::PetitPrince::DrawService_var& ds_manager) {
    // Invoke first remote method
    long b1 = pps_manager->createLine((char*)"Batard1", {0, 0}, {7, 1});
    long b2 = pps_manager->createLine((char*)"Batard2", {0, 0}, {7, 2});
    long b3 = pps_manager->createLine((char*)"Batard3", {0, 0}, {7, 3});
    long b4 = pps_manager->createLine((char*)"Batard1", {0, 0}, {7, 4});

    ::PetitPrince::LongSeq* s = pps_manager->getDraws("Batard1");
    cout << "longSeq: " << longSeqToString(s) << endl;
    long l = s->length();
    for(int i=0; i<l; i++) {
        cout << ds_manager->toString((*s)[i]) << endl;
    }
    pps_manager->markDraw(2.5, b1);

    s = pps_manager->getDraws("Batard1");
    cout << "longSeq: " << longSeqToString(s) << endl;
    l = s->length();
    for(int i=0; i<l; i++) {
        cout << ds_manager->toString((*s)[i]) << endl;
    }
}
