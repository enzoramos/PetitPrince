/*!
 * \file OBV_Line.hpp
 * \author Jerome Ramsamy
 * \version 1.0
 *
 * \brief Define Line class implementation.
 * 
 */

#ifndef OBV_LINE_HPP
#define OBV_LINE_HPP

#include "OBV_Draw.hpp"
#include "PetitPrince.hpp"

#include <cmath>

using namespace std;

/*!
 * \class Line OBV_Line.hpp
 * \brief This class is the class that define the implementation of a line.
 */
class Line : public virtual Draw, public virtual ::OBV_PetitPrince::Line {

public:
    /*!
     * \fn Line(::CORBA::Long id, char* author, ::PetitPrince::Point start, ::PetitPrince::Point end)
     * \brief The public constructor of the class Line.
     * 
     * \param id the id of the draw (auto-generated)
     * \param author the author of the draw
     * \param start the start point for this line
     * \param end the end point for this line
     */
    Line(::CORBA::Long id, char* author, ::PetitPrince::Point start, ::PetitPrince::Point end)
            : Draw(id, author, -1), _start(start), _end(end) {
    }
    virtual ~Line() {
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
        throw(::PetitPrince::DrawService::NonApplicable("A line does not have an area!"));
    }
    
    /*!
     * \fn ::CORBA::Double petimeter()
     * \brief This method calculate the perimeter of the draw, if applicable.
     * 
     * \return the perimeter of this draw
     */
    ::CORBA::Double perimeter() override {
        throw(::PetitPrince::DrawService::NonApplicable("A line does not have a perimeter!"));
    }
    
    /*!
     * \fn void homothetie(::CORBA::Double indice)
     * \brief This method apply an homothetie to the draw.
     * 
     * \param indice the scalar factor defining the homothetie.
     */
    void homothetie(::CORBA::Double indice) override {
        double x = _start.x, y = _start.y;
        translation(-_start.x, -_start.y);
        _end.x *= indice;
        _end.y *= indice;
        translation(x, y);
    }
    
    /*!
     * \fn void translation(::CORBA::Double x, ::CORBA::Double y)
     * \brief This method apply a translation to the draw.
     * 
     * \param x the x-axis translation
     * \param y the y-axis translation
     */
    void translation(::CORBA::Double x, ::CORBA::Double y) override {
        _start.x += x;
        _start.y += y;

        _end.x += x;
        _end.y += y;
    }
    
    /*!
     * \fn void rotation(::CORBA::Double angle)
     * \brief This method apply a rotation to the draw.
     * 
     * \param angle the angle defining the rotation.
     */
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
        stream << Draw::toString() << "(Line((" << _start.x << "," << _start.y << "),(" << _end.x << "," << _end.y << ")))";
        return strcpy(new char[stream.str().size()+1], stream.str().c_str());
    }

    // attributes from Line
    /*!
     * \fn ::PetitPrince::Point start()
     * \brief The getter for the start field
     * 
     * \return the start of this draw
     */
    ::PetitPrince::Point start() override {
        return this->_start;
    }
    
    /*!
     * \fn void start(::PetitPrince::Point& _v)
     * \brief The setter for the start field
     * 
     * \param _v the start to set (replace current start)
     */
    void start(const ::PetitPrince::Point& _v) override {
        this->_start = _v;
    }
    
    /*!
     * \fn ::PetitPrince::Point end()
     * \brief The getter for the end field
     * 
     * \return the end of this draw
     */
    ::PetitPrince::Point end() override {
        return this->_end;
    }
    
    /*!
     * \fn void end(::PetitPrince::Point& _v)
     * \brief The setter for the end field
     * 
     * \param _v the end to set (replace current end)
     */
    void end(const ::PetitPrince::Point& _v) override {
        this->_end = _v;
    }

private:
    ::PetitPrince::Point _start;
    ::PetitPrince::Point _end;

};

#endif /* OBV_LINE_HPP */

