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


class OBV_Ellipse : public virtual ::PetitPrince::Ellipse {
public:
    PolygonImpl();
    OBV_Ellipse(const OBV_Ellipse& orig);
    virtual ~OBV_Ellipse();

    PolygonImpl(::CORBA::Long _id, char* _author, ::PetitPrince::DrawSeq* _inner_draws, ::CORBA::Double _mark,
                ::PetitPrince::Point _center1, ::PetitPrince::Point _center2, ::CORBA::Double _ray)
            : id(_id), author(_author), inner_draws(_inner_draws), mark(_mark),
            center1(_center1), center2(_center2), ray(_ray) {
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
    }
    ::CORBA::Double perimeter() override {
    }
    void homothetie(::CORBA::Double indice) override {
    }
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
    }
    void rotation(::CORBA::Double angle) override {
    }
    void symCenter() override {
    }
    void symAxial() override {
    }

    char* toString() override {
    }

    // attributes from Line

private:

};


#endif /* DRAWIMPL_HPP */

