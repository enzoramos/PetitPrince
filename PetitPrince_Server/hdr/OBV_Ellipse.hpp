/*!
 * \file OBV_Ellipse.hpp
 * \author Jerome Ramsamy
 * \version 1.0
 *
 * \brief Define Ellipse class implementation.
 * 
 */

#ifndef OBV_ELLIPSE_HPP
#define OBV_ELLIPSE_HPP

#include "OBV_Draw.hpp"
#include "PetitPrince.hpp"

#include <cmath>

using namespace std;

/*!
 * \class Line OBV_Ellipse.hpp
 * \brief This class is the class that define the implementation of a ellipse.
 */
class Ellipse : public virtual Draw, public virtual ::OBV_PetitPrince::Ellipse {
public:
    /*!
     * \fn Ellipse(::CORBA::Long id, char* author, ::PetitPrince::Point center, ::CORBA::Double long_ray, ::CORBA::Double short_ray)
     * \brief The public constructor of the class Ellipse.
     * 
     * \param id the id of the draw (auto-generated)
     * \param author the author of the draw
     * \param center the center point for this ellipse
     * \param long_ray the long ray for this ellipse
     * \param short_ray the short ray for this ellipse
     */
    Ellipse(::CORBA::Long id, char* author, ::PetitPrince::Point center, ::CORBA::Double long_ray, ::CORBA::Double short_ray)
            : Draw(id, author, -1), _center(center), _long_ray(long_ray), _short_ray(short_ray) {
    }
    virtual ~Ellipse() {
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
        return M_PI*_long_ray*_short_ray;
    }
    
    /*!
     * \fn ::CORBA::Double petimeter()
     * \brief This method calculate the perimeter of the draw, if applicable.
     * 
     * \return the perimeter of this draw
     */
    ::CORBA::Double perimeter() override {
        return M_PI*sqrt(2*(_long_ray*_long_ray+_short_ray*_short_ray));
    }
    
    /*!
     * \fn void homothetie(::CORBA::Double indice)
     * \brief This method apply an homothetie to the draw.
     * 
     * \param indice the scalar factor defining the homothetie.
     */
    void homothetie(::CORBA::Double indice) override {
        _short_ray *= indice;
        _long_ray  *= indice;
    }
    
    /*!
     * \fn void translation(::CORBA::Double x, ::CORBA::Double y)
     * \brief This method apply a translation to the draw.
     * 
     * \param x the x-axis translation
     * \param y the y-axis translation
     */
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        _center.x += x;
        _center.y += y;
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
        stream << Draw::toString() << "Ellipse(center: (" << _center.x << "," << _center.y << "), long_ray: " << _long_ray << ", short_ray: " << _short_ray << ")";
        if(Draw::inner_draws()->length() > 0) {
            stream << "\n" << Draw::innerDrawsToString();
        }
        return strcpy(new char[stream.str().size()+1], stream.str().c_str());
    }

    // attributes from Ellipse
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
     * \fn ::CORBA::Double long_ray()
     * \brief The getter for the long ray field
     * 
     * \return the long ray of this draw
     */
    ::CORBA::Double long_ray() override {
        return this->_long_ray;
    }
    
    /*!
     * \fn void long_ray(::CORBA::Double _v)
     * \brief The setter for the long ray field
     * 
     * \param _v the long ray to set (replace current long ray)
     */
    void long_ray(::CORBA::Double _v) override {
        this->_long_ray = _v;
    }
    
    /*!
     * \fn ::CORBA::Double short_ray()
     * \brief The getter for the short ray field
     * 
     * \return the short ray of this draw
     */
    ::CORBA::Double short_ray() override {
        return this->_short_ray;
    }
    
    /*!
     * \fn void short_ray(::CORBA::Double _v)
     * \brief The setter for the short ray field
     * 
     * \param _v the short ray to set (replace current short ray)
     */
    void short_ray(::CORBA::Double _v) override {
        this->_short_ray = _v;
    }
    
private:
    ::PetitPrince::Point _center;
    ::CORBA::Double _long_ray;
    ::CORBA::Double _short_ray;

};


#endif /* OBV_ELLIPSE_HPP */

