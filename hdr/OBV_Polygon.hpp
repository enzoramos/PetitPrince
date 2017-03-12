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


class OBV_Polygon : public virtual ::PetitPrince::Polygon {
public:
    OBV_Polygon();
    OBV_Polygon(const OBV_Polygon& orig);
    virtual ~OBV_Polygon();

    CircleImpl(::CORBA::Long _id, char* _author, ::PetitPrince::DrawSeq* _inner_draws, ::CORBA::Double _mark,
                ::PetitPrince::PointSeq _points_list)
            : id(_id), author(_author), inner_draws(_inner_draws), mark(_mark),
            points_list(_points_list) {
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

