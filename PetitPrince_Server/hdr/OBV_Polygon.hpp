/*!
 * \file OBV_Polygon.hpp
 * \author Jerome Ramsamy
 * \version 1.0
 *
 * \brief Define Polygon class implementation.
 * 
 */

#ifndef OBV_POLYGON_HPP
#define OBV_POLYGON_HPP

#include "OBV_Draw.hpp"
#include "PetitPrince.hpp"

#include <cmath>
#include <cstring>
#include <string>

using namespace std;

/*!
 * \class Line OBV_Polygon.hpp
 * \brief This class is the class that define the implementation of a polygon.
 */
class Polygon : public virtual Draw, public virtual ::OBV_PetitPrince::Polygon {
public:
    /*!
     * \fn Polygon(::CORBA::Long id, char* author, ::PetitPrince::PointSeq& points_list)
     * \brief The public constructor of the class Polygon.
     * 
     * \param id the id of the draw (auto-generated)
     * \param author the author of the draw
     * \param points_list the list of points that define the polygon
     */
    Polygon(::CORBA::Long id, char* author, ::PetitPrince::PointSeq& points_list)
            : Draw(id, author, -1), _points_list(points_list) {
    }
    virtual ~Polygon() {
    }
    
public:
    // operations from Draw
    /*!
     * \fn ::CORBA::Double area()
     * \brief This method calculate the area of the draw, if applicable.
     * 
     * \return the area of this draw
     */
    ::CORBA::Double area() override {
        double area = 0;
        for(int i = 1; i < _points_list.length();i++){
            area += (_points_list[i-1].x *_points_list[i].y)-(_points_list[i].x *_points_list[i-1].y);
        }
        return 0.5*fabs(area);
    }
    
    /*!
     * \fn ::CORBA::Double petimeter()
     * \brief This method calculate the perimeter of the draw, if applicable.
     * 
     * \return the perimeter of this draw
     */
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
    
    /*!
     * \fn void homothetie(::CORBA::Double indice)
     * \brief This method apply an homothetie to the draw.
     * 
     * \param indice the scalar factor defining the homothetie.
     */
    void homothetie(::CORBA::Double indice) override {
        ::PetitPrince::Point tmp = _points_list[0];
        translation(-tmp.x,-tmp.y);
        for(int i = 0; i < _points_list.length(); i++){
            _points_list[i].x *= indice;
            _points_list[i].y *= indice;
        }
        translation(tmp.x,tmp.y);
    }
    
    /*!
     * \fn void translation(::CORBA::Double x, ::CORBA::Double y)
     * \brief This method apply a translation to the draw.
     * 
     * \param x the x-axis translation
     * \param y the y-axis translation
     */
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        for(int i = 0; i < _points_list.length(); i++){
            _points_list[i].x += x;
            _points_list[i].y += y;
        }
    }
    
    /*!
     * \fn void rotation(::CORBA::Double angle)
     * \brief This method apply a rotation to the draw.
     * 
     * \param angle the angle defining the rotation.
     */
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
    
    /*!
     * \fn void symCenter()
     * \brief This method apply a central symetry to the draw.
     */
    void symCenter() override {
        rotation(180);
    }
    
    /*!
     * \fn void symAxial()
     * \brief This method apply a axial symetry to the draw.
     */
    void symAxial() override {
    }
    
    /*!
     * \fn char* toString()
     * \brief Generate a user-friendly representation of this draw
     * 
     * \return The user-friendly representation of this draw
     */
    char* toString() override {
        stringstream stream;
        long l = points_list()->length();
        stream << "(" << (*points_list())[0].x << "," << (*points_list())[0].y << ")";
        for(int i=1; i<l; i++) {
            stream << ",(" << (*points_list())[i].x << "," << (*points_list())[i].y << ")";
        }
        stringstream tmp;
        tmp << Draw::toString() << "Polygon(" << stream.str() << ")";
        if(Draw::inner_draws()->length() > 0) {
            stream << "\n" << Draw::innerDrawsToString();
        }
        return strcpy(new char[tmp.str().size()+1], tmp.str().c_str());
    }

    // attributes from Polygon
    /*!
     * \fn ::PetitPrince::PointSeq* points_list()
     * \brief The getter for the points list field
     * 
     * \return the points list of this draw
     */
    ::PetitPrince::PointSeq* points_list() override {
        return &this->_points_list;
    }
    
    /*!
     * \fn void points_list(::PetitPrince::PointSeq& _v)
     * \brief The setter for the points list field
     * 
     * \param _v the points list to set (replace current points list)
     */
    void points_list(const ::PetitPrince::PointSeq& _v) override {
        this->_points_list = _v;
    }
    
private:
    /*!
     * \fn double dist(::PetitPrince::Point start, ::PetitPrince::Point end)
     * \brief This private method is used to calculate the euclidian distance
     * between two points
     * 
     * \return the distance between both points
     */
    double dist(::PetitPrince::Point start, ::PetitPrince::Point end){
        return sqrt(pow((end.x-start.x),2)+pow((end.y-start.y),2));
    }
    
private:
    ::PetitPrince::PointSeq _points_list;

};


#endif /* OBV_POLYGON_HPP */

