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


class ::OBV_PetitPrince::Polygon : public virtual ::PetitPrince::Polygon {
protected:
    Polygon(::CORBA::Long id, char* author, ::PetitPrince::DrawSeq* inner_draws, ::CORBA::Double mark,
        ::PetitPrince::PointSeq& points_list)
            : ::PetitPrince::Line(id, author, inner_draws, mark),
              _points_list(points_list) {
    }
    virtual ~Polygon();
    
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

    // attributes from Polygon
    ::PetitPrince::PointSeq* points_list() override {
        return this->_points_list;
    }
    void points_list(const ::PetitPrince::PointSeq& _v) override {
        this->_points_list = &_v;
    }
    
private:
    ::PetitPrince::PointSeq* _points_list;

};


#endif /* DRAWIMPL_HPP */

