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

#ifndef OBV_LINE_HPP
#define OBV_LINE_HPP

#include "OBV_Draw.hpp"
#include "PetitPrince.hpp"

#include <cmath>

using namespace std;

class Line : public virtual Draw, public virtual ::OBV_PetitPrince::Line {

public:
    Line(::CORBA::Long id, char* author, ::PetitPrince::Point start, ::PetitPrince::Point end)
            : Draw(id, author, -1), _start(start), _end(end) {
    }
    virtual ~Line() {
    }
    /*
    char* author() override {}
    ::CORBA::Long id() override {}
    void inner_draws(const ::PetitPrince::DrawSeq& _v) override {}
    ::PetitPrince::DrawSeq* inner_draws() override {}
    ::CORBA::Double mark() override {}
    void mark(::CORBA::Double _v) override {}
    */    
    
public:
    // operations from Draw
    ::CORBA::Double area() override {
        throw(::PetitPrince::DrawService::NonApplicable("A line does not have an area!"));
    }
    ::CORBA::Double perimeter() override {
        throw(::PetitPrince::DrawService::NonApplicable("A line does not have a perimeter!"));
    }
    void homothetie(::CORBA::Double indice) override {
        double x = _start.x, y = _start.y;
        translation(-_start.x, -_start.y);
        _end.x *= indice;
        _end.y *= indice;
        translation(x, y);
    }
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        _start.x += x;
        _start.y += y;

        _end.x += x;
        _end.y += y;
    }
    void rotation(::CORBA::Double angle) override {
        double x = _start.x;
        double y = _start.y;
        double r = sqrt(x*x + y*y);
        _start.x = r * cos(angle);
        _start.y = r * sin(angle);

        x = _end.x;
        y = _end.y;
        r = sqrt(x*x + y*y);
        _end.x = r * cos(angle);
        _end.y = r * sin(angle);
    }
    void symCenter() override {
        rotation(180);
        // TODO
    }
    void symAxial() override {
        // TODO
    }

    char* toString() override {
        stringstream stream;
        stream << Draw::toString() << "(Line((" << _start.x << "," << _start.y << "),(" << _end.x << "," << _end.y << ")))";
        return const_cast<char*>(stream.str().c_str());
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

#endif /* OBV_LINE_HPP */

