/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DrawImpl.hpp
 * Author: jeremy
 *
 * Created on 12 mars 2017, 17:08
 */

#ifndef OBV_POLYGON_HPP
#define OBV_POLYGON_HPP

#include "OBV_Draw.hpp"
#include "PetitPrince.hpp"

#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

class Polygon : public virtual Draw, public virtual ::OBV_PetitPrince::Polygon {
public:
    Polygon(::CORBA::Long id, char* author, ::PetitPrince::PointSeq& points_list)
            : Draw(id, author, -1), _points_list(points_list) {
    }
    virtual ~Polygon() {
    }
    
public:
    // operations from Draw
    ::CORBA::Double area() override {
        // TODO
    }
    ::CORBA::Double perimeter() override {
        // TODO
    }
    void homothetie(::CORBA::Double indice) override {
        // TODO
    }
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        // TODO
    }
    void rotation(::CORBA::Double angle) override {
        // TODO
    }
    void symCenter() override {
        // TODO
    }
    void symAxial() override {
        // TODO
    }

    char* toString() override {
        stringstream stream;
        long l = points_list()->length();
        stream << "(" << (*points_list())[0].x << "," << (*points_list())[0].y << ")";
        for(int i=1; i<l; i++) {
            stream << ",(" << (*points_list())[i].x << "," << (*points_list())[i].y << ")";
        }
        stringstream tmp;
        tmp << Draw::toString() << "(Polygon(" << stream.str() << "))";
        return const_cast<char*>(tmp.str().c_str());
    }

    // attributes from Polygon
    ::PetitPrince::PointSeq* points_list() override {
        return &this->_points_list;
    }
    void points_list(const ::PetitPrince::PointSeq& _v) override {
        this->_points_list = _v;
    }
    
private:
    ::PetitPrince::PointSeq _points_list;

};


#endif /* OBV_POLYGON_HPP */

