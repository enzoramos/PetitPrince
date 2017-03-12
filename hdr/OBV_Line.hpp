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


class OBV_Line : public virtual ::PetitPrince::Line {
public:
    OBV_Line();
    OBV_Line(const OBV_Line& orig);
    virtual ~OBV_Line();

    OBV_Line(::CORBA::Long _id, char* _author, ::PetitPrince::DrawSeq* _inner_draws, ::CORBA::Double _mark,
                ::PetitPrince::Point _start, ::PetitPrince::Point _end)
            : id(_id), author(_author), inner_draws(_inner_draws), mark(_mark),
            start(_start), end(_end) {
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
        return start;
    }
    void start(const ::PetitPrince::Point& _v) override {
        start = _v;
    }
    ::PetitPrince::Point end() override {
        return end;
    }
    void end(const ::PetitPrince::Point& _v) override {
        end = _v;
    }

private:

};

#endif /* DRAWIMPL_HPP */

