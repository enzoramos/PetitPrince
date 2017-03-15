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

#ifndef OBV_CIRCLE_HPP
#define OBV_CIRCLE_HPP

#include "OBV_Draw.hpp"
#include "ServiceDraw.hpp"

#include <cmath>
#include <math.h>

using namespace std;

class Circle : public virtual Draw, public virtual ::OBV_PetitPrince::Circle {

public:
    Circle(::CORBA::Long id, char* author, ::PetitPrince::DrawSeq& inner_draws, ::CORBA::Double mark,
        ::PetitPrince::Point center, ::CORBA::Double ray)
            : Draw(id, author, inner_draws, mark),
              _center(center), _ray(ray) {
    }
    virtual ~Circle();
    
public:
    // operations from Draw
    ::CORBA::Double area() override {
        return M_PI*_ray*_ray;
    }
    ::CORBA::Double perimeter() override {
        return 2*M_PI*_ray;
    }
    void homothetie(::CORBA::Double indice) override {
        _ray *= indice;
    }
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        _center = {center().x+x, center().y+y};
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
        stream << Draw::toString() << "(Circle(center: (" << _center.x << "," << _center.y << "), ray: " << _ray << "))";
        return const_cast<char*>(stream.str().c_str());
    }

    // attributes from Circle
    ::PetitPrince::Point center() override {
        return this->_center;
    }
    void center(const ::PetitPrince::Point& _v) override {
        this->_center = _v;
    }
    ::CORBA::Double ray() override {
        return this->_ray;
    }
    void ray(::CORBA::Double _v) override {
        this->_ray = _v;
    }


private:
    ::PetitPrince::Point _center;
    ::CORBA::Double _ray;

};


#endif /* OBV_CIRCLE_HPP */

