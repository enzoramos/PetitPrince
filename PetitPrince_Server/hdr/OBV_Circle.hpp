/*!
 * \file OBV_Circle.hpp
 * \author Jerome Ramsamy
 * \version 1.0
 *
 * \brief Define Circle class implementation.
 * 
 */

#ifndef OBV_CIRCLE_HPP
#define OBV_CIRCLE_HPP

#include "OBV_Draw.hpp"
#include "PetitPrince.hpp"

#include <cmath>
#include <math.h>

using namespace std;

/*!
 * \class Line OBV_Circle.hpp
 * \brief This class is the class that define the implementation of a circle.
 */
class Circle : public virtual Draw, public virtual ::OBV_PetitPrince::Circle {

public:
    /*!
     * \fn Circle(::CORBA::Long id, char* author, ::PetitPrince::Point center, ::CORBA::Double ray)
     * \brief The public constructor of the class Circle.
     * 
     * \param id the id of the draw (auto-generated)
     * \param author the author of the draw
     * \param center the center point for this circle
     * \param ray the ray for this circle
     */
    Circle(::CORBA::Long id, char* author, ::PetitPrince::Point center, ::CORBA::Double ray)
            : Draw(id, author, -1), _center(center), _ray(ray) {
    }
    virtual ~Circle() {
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
        return M_PI*_ray*_ray;
    }
    
    /*!
     * \fn ::CORBA::Double petimeter()
     * \brief This method calculate the perimeter of the draw, if applicable.
     * 
     * \return the perimeter of this draw
     */
    ::CORBA::Double perimeter() override {
        return 2*M_PI*_ray;
    }
    
    /*!
     * \fn void homothetie(::CORBA::Double indice)
     * \brief This method apply an homothetie to the draw.
     * 
     * \param indice the scalar factor defining the homothetie.
     */
    void homothetie(::CORBA::Double indice) override {
        _ray *= indice;
    }
    
    /*!
     * \fn void translation(::CORBA::Double x, ::CORBA::Double y)
     * \brief This method apply a translation to the draw.
     * 
     * \param x the x-axis translation
     * \param y the y-axis translation
     */
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        _center = {center().x+x, center().y+y};
    }
    
    /*!
     * \fn void rotation(::CORBA::Double angle)
     * \brief This method apply a rotation to the draw.
     * 
     * \param angle the angle defining the rotation.
     */
    void rotation(::CORBA::Double angle) override {
    }
    
    /*!
     * \fn void symCenter()
     * \brief This method apply a central symetry to the draw.
     */
    void symCenter() override {
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
        stream << Draw::toString() << "Circle(center: (" << _center.x << "," << _center.y << "), ray: " << _ray << ")";
        if(Draw::inner_draws()->length() > 0) {
            stream << "\n" << Draw::innerDrawsToString();
        }
        return strcpy(new char[stream.str().size()+1], stream.str().c_str());
    }

    // attributes from Circle
    /*!
     * \fn ::PetitPrince::Point center()
     * \brief The getter for the center field
     * 
     * \return the center of this draw
     */
    ::PetitPrince::Point center() override {
        return this->_center;
    }
    
    /*!
     * \fn void center(::PetitPrince::Point& _v)
     * \brief The setter for the center field
     * 
     * \param _v the center to set (replace current center)
     */
    void center(const ::PetitPrince::Point& _v) override {
        this->_center = _v;
    }
    
    /*!
     * \fn ::CORBA::Double ray()
     * \brief The getter for the ray field
     * 
     * \return the ray of this draw
     */
    ::CORBA::Double ray() override {
        return this->_ray;
    }
    
    /*!
     * \fn void ray(::CORBA::Double _v)
     * \brief The setter for the ray field
     * 
     * \param _v the ray to set (replace current ray)
     */
    void ray(::CORBA::Double _v) override {
        this->_ray = _v;
    }


private:
    ::PetitPrince::Point _center;
    ::CORBA::Double _ray;

};


#endif /* OBV_CIRCLE_HPP */

