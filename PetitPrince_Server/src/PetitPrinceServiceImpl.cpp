/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServiceDrawImpl.cpp
 * Author: jeremy
 * 
 * Created on 10 mars 2017, 16:00
 */

#include "PetitPrinceServiceImpl.hpp"
#include "OBV_Line.hpp"
#include "OBV_Circle.hpp"
#include "OBV_Ellipse.hpp"
#include "OBV_Polygon.hpp"


using namespace std;


PetitPrinceServiceImpl::PetitPrinceServiceImpl() {
}

PetitPrinceServiceImpl::PetitPrinceServiceImpl(const PetitPrinceServiceImpl& orig) {
}

PetitPrinceServiceImpl::PetitPrinceServiceImpl(CORBA::ORB_var orb): _orb(orb) {
}

PetitPrinceServiceImpl::~PetitPrinceServiceImpl() {
    _orb->shutdown(false);
}


::CORBA::Long PetitPrinceServiceImpl::createLine(const char* author, const ::PetitPrince::Point& a, const ::PetitPrince::Point& b) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Line(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), a, b))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

::CORBA::Long PetitPrinceServiceImpl::createCircle(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double ray) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Circle(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), center, ray))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

::CORBA::Long PetitPrinceServiceImpl::createEllipse(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double long_ray, ::CORBA::Double short_ray) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Ellipse(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), center, long_ray, short_ray))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

::CORBA::Long PetitPrinceServiceImpl::createPolygon(const char* author, const ::PetitPrince::PointSeq& pts) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Polygon(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), const_cast<::PetitPrince::PointSeq&>(pts)))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

::PetitPrince::LongSeq* PetitPrinceServiceImpl::getDraws(const char* author) {
    ::PetitPrince::LongSeq* ls = new ::PetitPrince::LongSeq();
    for(auto elem : _draw_list) {
        if(strcmp(elem.second->author(), author) == 0) {
            int l = ls->length();
            ls->length(l+1);
            (*ls)[l] = elem.first;
        }
    }
    return ls;
}

void PetitPrinceServiceImpl::markDraw(::CORBA::Double mark, ::CORBA::Long id) {
    _draw_list.at(id)->mark(mark);
}

