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

#ifndef OBV_ELLIPSE_HPP
#define OBV_ELLIPSE_HPP

#include "OBV_Draw.hpp"
#include "ServiceDraw.hpp"

#include <cmath>

using namespace std;

class Ellipse : public virtual Draw, public virtual ::OBV_PetitPrince::Ellipse {
public:
    Ellipse(::CORBA::Long id, char* author, ::PetitPrince::DrawSeq& inner_draws, ::CORBA::Double mark,
        ::PetitPrince::Point center, ::CORBA::Double long_ray, ::CORBA::Double short_ray)
            : Draw(id, author, inner_draws, mark),
              _center(center), _long_ray(long_ray), _short_ray(short_ray) {
    }
    virtual ~Ellipse();
    
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
        stream << Draw::toString() << "(Ellipse(center: (" << _center.x << "," << _center.y << "), long_ray: " << _long_ray << ", short_ray: " << _short_ray << "))";
        return const_cast<char*>(stream.str().c_str());
    }

    // attributes from Ellipse
    ::PetitPrince::Point center() override {
        return this->_center;
    }
    void center(const ::PetitPrince::Point& _v) override {
        this->_center = _v;
    }
    ::CORBA::Double long_ray() override {
        return this->_long_ray;
    }
    void long_ray(::CORBA::Double _v) override {
        this->_long_ray = _v;
    }
    ::CORBA::Double short_ray() override {
        return this->_short_ray;
    }
    void short_ray(::CORBA::Double _v) override {
        this->_short_ray = _v;
    }
    
private:
    ::PetitPrince::Point _center;
    ::CORBA::Double _long_ray;
    ::CORBA::Double _short_ray;

};


#endif /* OBV_ELLIPSE_HPP */

