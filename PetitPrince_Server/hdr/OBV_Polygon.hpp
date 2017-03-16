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

#ifndef OBV_POLYGON_HPP
#define OBV_POLYGON_HPP

#include "OBV_Draw.hpp"
#include "PetitPrince.hpp"

#include <cmath>
#include <cstring>
#include <string>

using namespace std;

class Polygon : public virtual Draw, public virtual ::OBV_PetitPrince::Polygon {
public:
    Polygon(::CORBA::Long id, char* author, ::PetitPrince::PointSeq& points_list)
            : Draw(id, author, -1), _points_list(points_list) {
    }
    virtual ~Polygon() {
    }
    
public:
    // operations from Draw
    ::CORBA::Double area() override {
        double area = 0;
        for(int i = 1; i < _points_list.length();i++){
            area += (_points_list[i-1].x *_points_list[i].y)-(_points_list[i].x *_points_list[i-1].y);
        }
        return 0.5*fabs(area);
    }
    ::CORBA::Double perimeter() override {
        double perim = 0;
        if(_points_list.length() > 2){
            for(int i = 1; i < _points_list.length();i++){
                perim += dist(_points_list[i-1],_points_list[i]);
            }
            perim+=dist(_points_list[_points_list.length()-1],_points_list[0]);
        }
        return perim;
    }
    void homothetie(::CORBA::Double indice) override {
        ::PetitPrince::Point tmp = _points_list[0];
        translation(-tmp.x,-tmp.y);
        for(int i = 0; i < _points_list.length(); i++){
            _points_list[i].x *= indice;
            _points_list[i].y *= indice;
        }
        translation(tmp.x,tmp.y);
    }
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        for(int i = 0; i < _points_list.length(); i++){
            _points_list[i].x += x;
            _points_list[i].y += y;
        }
    }
    void rotation(::CORBA::Double angle) override {
        ::PetitPrince::Point tmp = _points_list[0];
        translation(-_points_list[0].x,-_points_list[0].y);
        
        for(int i = 1 ; i < _points_list.length(); i++){
            double x = _points_list[i].x;
            double y = _points_list[i].y;
            double r = sqrt(x*x + y*y);
            _points_list[i].x = r * cos(angle);
            _points_list[i].y = r * sin(angle);
        }
        translation(tmp.x,tmp.y);
    }
    void symCenter() override {
        rotation(180);
    }
    void symAxial() override {
    }

    char* toString() override {
        stringstream stream;
        long l = points_list()->length();
        stream << "(" << (*points_list())[0].x << "," << (*points_list())[0].y << ")";
        for(int i=1; i<l; i++) {
            stream << ",(" << (*points_list())[i].x << "," << (*points_list())[i].y << ")";
        }
        stringstream tmp;
        tmp << Draw::toString() << "(Polygon(" << stream.str() << "))";
        return strcpy(new char[tmp.str().size()+1], tmp.str().c_str());
    }

    // attributes from Polygon
    ::PetitPrince::PointSeq* points_list() override {
        return &this->_points_list;
    }
    void points_list(const ::PetitPrince::PointSeq& _v) override {
        this->_points_list = _v;
    }
    
private:
    double dist(::PetitPrince::Point start, ::PetitPrince::Point end){
        return sqrt(pow((end.x-start.x),2)+pow((end.y-start.y),2));
    }
    
private:
    ::PetitPrince::PointSeq _points_list;

};


#endif /* OBV_POLYGON_HPP */

