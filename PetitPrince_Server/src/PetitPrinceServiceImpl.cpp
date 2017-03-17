/*!
 * \file PetitPrinceServiceImpl.cpp
 * \author Jeremy Bidet
 * \version 1.0
 *
 * \brief Define PetitPrinceServiceImpl methods implementation.
 * 
 */

#include "PetitPrinceServiceImpl.hpp"
#include "OBV_Line.hpp"
#include "OBV_Circle.hpp"
#include "OBV_Ellipse.hpp"
#include "OBV_Polygon.hpp"


using namespace std;


PetitPrinceServiceImpl::PetitPrinceServiceImpl() {
}

PetitPrinceServiceImpl::PetitPrinceServiceImpl(const PetitPrinceServiceImpl& orig) {
}

PetitPrinceServiceImpl::PetitPrinceServiceImpl(CORBA::ORB_var orb): _orb(orb) {
}

PetitPrinceServiceImpl::~PetitPrinceServiceImpl() {
    _orb->shutdown(false);
}

/*!
 * \fn ::CORBA::Long createLine(const char* author, const ::PetitPrince::Point& a, const ::PetitPrince::Point& b)
 * \brief This method create a line with an author and two points as start and end coordinates
 * 
 * \param author the author of the draw
 * \param a a reference to the start point of the line
 * \param b a reference to the end point of the line
 * 
 * \throw InvalidDrawParams when creation fails
 * 
 * \return the id of the created draw
 * 
 */
::CORBA::Long PetitPrinceServiceImpl::createLine(const char* author, const ::PetitPrince::Point& a, const ::PetitPrince::Point& b) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Line(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), a, b))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

/*!
 * \fn ::CORBA::Long createCircle(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double ray)
 * \brief This method create a circle with an author a center and a ray
 * 
 * \param author the author of the draw
 * \param center a reference to the center point of the circle
 * \param ray the ray of the circle
 * 
 * \throw InvalidDrawParams when creation fails
 * 
 * \return the id of the created draw
 * 
 */
::CORBA::Long PetitPrinceServiceImpl::createCircle(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double ray) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Circle(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), center, ray))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

/*!
 * \fn ::CORBA::Long createEllipse(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double long_ray, ::CORBA::Double short_ray)
 * \brief This method create a circle with an author a center and a ray
 * 
 * \param author the author of the draw
 * \param center a reference to the center point of the circle
 * \param ray the ray of the circle
 * 
 * \throw InvalidDrawParams when creation fails
 * 
 * \return the id of the created draw
 * 
 */
::CORBA::Long PetitPrinceServiceImpl::createEllipse(const char* author, const ::PetitPrince::Point& center, ::CORBA::Double long_ray, ::CORBA::Double short_ray) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Ellipse(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), center, long_ray, short_ray))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

/*!
 * \fn ::CORBA::Long createPolygon(const char* author, const ::PetitPrince::PointSeq& pts)
 * \brief This method create a polygon with an author and a serie of points
 * 
 * \param author the author of the draw
 * \param pts a sequence of points
 * 
 * \throw InvalidDrawParams when creation fails
 * 
 * \return the id of the created draw
 * 
 */
::CORBA::Long PetitPrinceServiceImpl::createPolygon(const char* author, const ::PetitPrince::PointSeq& pts) {
    if(_draw_list.insert(make_pair(PetitPrinceServiceImpl::cpt, new Polygon(PetitPrinceServiceImpl::cpt, strcpy(new char[strlen(author)+1], author), const_cast<::PetitPrince::PointSeq&>(pts)))).second) {
        return PetitPrinceServiceImpl::cpt++;
    }
    throw(PetitPrince::PetitPrinceService::InvalidDrawParams("Parameters invalid!"));
}

/*!
 * \fn ::PetitPrince::LongSeq* getDraws(const char* author)
 * \brief This method return a sequence of id for the draws craeated by an author
 * 
 * \param author the author of the draws
 * 
 * \return the ids of the draws created by this author
 * 
 */
::PetitPrince::LongSeq* PetitPrinceServiceImpl::getDraws(const char* author) {
    ::PetitPrince::LongSeq* ls = new ::PetitPrince::LongSeq();
    for(auto elem : _draw_list) {
        if(strcmp(elem.second->author(), author) == 0) {
            int l = ls->length();
            ls->length(l+1);
            (*ls)[l] = elem.first;
        }
    }
    return ls;
}

/*!
 * \fn void markDraw(::CORBA::Double mark, ::CORBA::Long id)
 * \brief This method give a mark for a draw
 * 
 * \param mark the given mark
 * \param id the id of the draw to apply the mark
 * 
 */
void PetitPrinceServiceImpl::markDraw(::CORBA::Double mark, ::CORBA::Long id) {
    _draw_list.at(id)->mark(mark);
}

