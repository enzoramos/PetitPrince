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
#include "DrawServiceImpl.hpp"

#include <cmath>
#include <math.h>



class ::OBV_PetitPrince::Circle : public virtual ::PetitPrince::Circle {
protected:
    Circle(::CORBA::Long id, char* author, ::PetitPrince::DrawSeq* inner_draws, ::CORBA::Double mark,
        ::PetitPrince::Point center, ::CORBA::Double ray)
            : ::PetitPrince::Line(id, author, inner_draws, mark),
              _center(center), _ray(ray) {
    }
    virtual ~Circle();
    
public:
    // operations from Draw
    ::CORBA::Double area() override {
        return M_PI*ray()*ray();
    }
    ::CORBA::Double perimeter() override {
        return 2*M_PI*ray();
    }
    void homothetie(::CORBA::Double indice) override {
        double tmp = ray();
        ray(tmp*indice);
    }
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        ::PetitPrince::Point tmp = ::PetitPrince::Point(center().x+x,center().y+y)
        center(tmp);
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
        return "rayon : " + ray() + "Centre : "center();
    }

    // attributes from Circle
    ::PetitPrince::Point center() override {
        return this->_center;
    }
    void center(const ::PetitPrince::Point& _v) override {
        this->_center = _v;
    }
    ::PetitPrince::Point ray() override {
        return this->_ray;
    }
    void ray(const ::PetitPrince::Point& _v) override {
        this->_ray = _v;
    }

private:
    ::PetitPrince::Point _center;
    ::CORBA::Double _ray;

};


#endif /* DRAWIMPL_HPP */

