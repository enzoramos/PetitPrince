/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OBV_Draw.hpp
 * Author: jeremy
 *
 * Created on 14 mars 2017, 19:56
 */

#ifndef OBV_DRAW_HPP
#define OBV_DRAW_HPP

#include "ServiceDraw.hpp"

#include <omniORB4/CORBA.h>
#include <sstream>

using namespace std;

class Draw : public virtual ::OBV_PetitPrince::Draw {

protected:
    Draw(::CORBA::Long id, char* author, ::PetitPrince::DrawSeq& inner_draws, ::CORBA::Double mark)
            : _id(id), _author(author), _inner_draws(inner_draws), _mark(mark) {
    }

public:
    ::CORBA::Long id() override {
        return this->_id;
    }
    char* author() override {
        return this->_author;
    }
    ::PetitPrince::DrawSeq* inner_draws() override {
        return &this->_inner_draws;
    }
    void inner_draws(const ::PetitPrince::DrawSeq& _v) override {
        this->_inner_draws = _v;
    }
    ::CORBA::Double mark() override {
        return this->_mark;
    }
    void mark(::CORBA::Double _v) override {
        this->_mark = _v;
    }

    char* toString() override {
        stringstream stream;
        stream << "Draw(id: " << _id  <<  ", author: "  <<  _author  <<  ", mark: "  <<  _mark  <<  ")";
        return const_cast<char*>(stream.str().c_str());
    }
    
    void _add_ref() override {}
    ::CORBA::ULong _refcount_value() override {}
    void _remove_ref() override {}

private:
    ::CORBA::Long _id;
    char* _author;
    ::PetitPrince::DrawSeq _inner_draws;
    ::CORBA::Double _mark;

};


#endif /* OBV_DRAW_HPP */
