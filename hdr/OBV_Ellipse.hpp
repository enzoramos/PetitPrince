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

#ifndef DRAWIMPL_HPP
#define DRAWIMPL_HPP

#include "ServiceDraw.hpp"

#include <cmath>


class ::OBV_PetitPrince::Ellipse : public virtual ::PetitPrince::Ellipse {
protected:
    Ellipse(::CORBA::Long id, char* author, ::PetitPrince::DrawSeq* inner_draws, ::CORBA::Double mark,
        ::PetitPrince::Point center, ::CORBA::Double long_ray, ::CORBA::Double short_ray)
            : ::PetitPrince::Line(id, author, inner_draws, mark),
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
        // TODO
    }

    // attributes from Ellipse
    ::PetitPrince::Point center() override {
        return this->_center;
    }
    void center(const ::PetitPrince::Point& _v) override {
        this->_center = _v;
    }
    ::PetitPrince::Point long_ray() override {
        return this->_long_ray;
    }
    void long_ray(const ::PetitPrince::Point& _v) override {
        this->_long_ray = _v;
    }
    ::PetitPrince::Point short_ray() override {
        return this->_short_ray;
    }
    void short_ray(const ::PetitPrince::Point& _v) override {
        this->_short_ray = _v;
    }

private:
    ::PetitPrince::Point _center;
    ::CORBA::Double _long_ray;
    ::CORBA::Double _short_ray;

};


#endif /* DRAWIMPL_HPP */

