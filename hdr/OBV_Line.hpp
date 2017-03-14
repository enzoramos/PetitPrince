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


class ::OBV_PetitPrince::Line : public virtual ::PetitPrince::Line {
protected:
    Line(::CORBA::Long id, char* author, ::PetitPrince::DrawSeq* inner_draws, ::CORBA::Double mark,
        ::PetitPrince::Point _start, ::PetitPrince::Point _end)
            : ::PetitPrince::Line(id, author, inner_draws, mark),
              _start(start), _end(end) {
    }
    virtual ~Line();
    
public:
    // operations from Draw
    ::CORBA::Double area() override {
        throw(::PetitPrince::DrawService::non_applicable("A line does not have an area!"), ::CORBA::SystemException);
    }
    ::CORBA::Double perimeter() override {
        throw(::PetitPrince::DrawService::non_applicable("A line does not have a perimeter!"), ::CORBA::SystemException);
    }
    void homothetie(::CORBA::Double indice) override {
        double x = start().x, y = start().y;
        translation(-start().x, -start().y);
        end().x *= indice;
        end().y *= indice;
        translation(x, y);
    }
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        start().x += x;
        start().y += y;

        end().x += x;
        end().y += y;
    }
    void rotation(::CORBA::Double angle) override {
        double x = start().x;
        double y = start().y;
        double r = sqrt(x*x + y*y);
        start().x = r * cos(angle);
        start().y = r * sin(angle);

        x = end().x;
        y = end().y;
        r = sqrt(x*x + y*y);
        end().x = r * cos(angle);
        end().y = r * sin(angle);
    }
    void symCenter() override {
        rotation(180);
        // TODO
    }
    void symAxial() override {
        // TODO
    }

    char* toString() override {
        return "((" + start().x + "," + start().y + "),(" + end().x + "," + end().y + "))";
    }

    // attributes from Line
    ::PetitPrince::Point start() override {
        return this->_start;
    }
    void start(const ::PetitPrince::Point& _v) override {
        this->_start = _v;
    }
    ::PetitPrince::Point end() override {
        return this->_end;
    }
    void end(const ::PetitPrince::Point& _v) override {
        this->_end = _v;
    }

private:
    ::PetitPrince::Point _start;
    ::PetitPrince::Point _end;

};

#endif /* DRAWIMPL_HPP */

