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



class OBV_Circle : public virtual ::PetitPrince::Circle {
public:
    OBV_Circle();
    OBV_Circle(const OBV_Circle& orig);
    virtual ~OBV_Circle();

    OBV_Circle(::CORBA::Long _id, char* _author, ::PetitPrince::DrawSeq* _inner_draws, ::CORBA::Double _mark,
                ::PetitPrince::Point _center, ::CORBA::Double _ray)
            : id(_id), author(_author), inner_draws(_inner_draws), mark(_mark),
            center(_center), ray(_ray) {
    }

    // attributes from Draw
    ::CORBA::Long id() override {
    }
    char* author() override {
    }
    ::PetitPrince::DrawSeq* inner_draws() override {
    }
    void inner_draws(const ::PetitPrince::DrawSeq& _v) override {
    }
    ::CORBA::Double mark() override {
    }
    void mark(::CORBA::Double _v) override {
    }

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
    }
    void symCenter() override {
    }
    void symAxial() override {
    }

    char* toString() override {
        return "rayon : " + ray() + "Centre : "center();
    }

    // attributes from Line

private:

};


#endif /* DRAWIMPL_HPP */

