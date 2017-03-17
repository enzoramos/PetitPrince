/*!
 * \file DrawServiceImpl.cpp
 * \author Enzo Ramos
 * \version 1.0
 *
 * \brief Define DrawServiceImpl methods implementation.
 * 
 */

#include "DrawServiceImpl.hpp"
#include "PetitPrinceServiceImpl.hpp"

using namespace std;


DrawServiceImpl::DrawServiceImpl(){
}

DrawServiceImpl::DrawServiceImpl(const DrawServiceImpl& orig){
}

DrawServiceImpl::DrawServiceImpl(CORBA::ORB_var orb): _orb(orb) {
}

DrawServiceImpl::~DrawServiceImpl(){
}

/*!
 * \fn ::CORBA::Double area(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * 
 * \return the calculated area of the draw.
 */
::CORBA::Double DrawServiceImpl::area(::CORBA::Long id) {
    ::PetitPrince::Draw* d = ::PetitPrinceServiceImpl::_draw_list.at(id);
    try{
        return d->area();
    } catch(::PetitPrince::DrawService::NonApplicable e) {
        cout << e.msg << endl;
    }
}

/*!
 * \fn ::CORBA::Double perimeter(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * 
 * \return the calculated perimeter of the draw.
 */
::CORBA::Double DrawServiceImpl::perimeter(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    try{
        return d->perimeter();
    } catch(::PetitPrince::DrawService::NonApplicable e) {
        cout << e.msg << endl;
    }
}

/*!
 * \fn void homothetie(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * \param index the scalar factor to apply to the draw
 * 
 */
void DrawServiceImpl::homothetie(::CORBA::Long id, ::CORBA::Double index) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->homothetie(index);
}

/*!
 * \fn void translation(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * \param x the x translation to apply to the draw
 * \param y the y translation to apply to the draw
 * 
 */
void DrawServiceImpl::translation(::CORBA::Long id, ::CORBA::Double x, ::CORBA::Double y) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->translation(x,y);
}

/*!
 * \fn void rotation(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * \param angle the angle to rotate the draw
 * 
 */
void DrawServiceImpl::rotation(::CORBA::Long id, ::CORBA::Double angle) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->rotation(angle);
}

/*!
 * \fn void symCenter(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * 
 */
void DrawServiceImpl::symCenter(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->symCenter();
}

/*!
 * \fn void symAxial(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * 
 */
void DrawServiceImpl::symAxial(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    d->symAxial();
}

/*!
 * \fn void addDraw(::CORBA::Long id)
 * \brief This method add an inner draw into a parent draw.
 * 
 * \param pid the draw parent id. This draw is the one who will own the inner draw.
 * \param cid the draw child id. This draw is the one who will belong to the parent draw.
 * 
 * \throw UnexpectedDraw when the inner draw has a greater area than the parent draw.
 * 
 */
void DrawServiceImpl::addDraw(::CORBA::Long pid, ::CORBA::Long cid) {
    ::PetitPrince::Draw* parent = PetitPrinceServiceImpl::_draw_list.at(pid);
    ::PetitPrince::Draw* child = PetitPrinceServiceImpl::_draw_list.at(cid);
    if(parent->area() < parent->area()){
       throw ::PetitPrince::DrawService::UnexpectedDraw("L'aire du dessin est plus grande que celle du parent");
    }
    ::CORBA::ULong l = parent->inner_draws()->length();
    parent->inner_draws()->length(l+1);
    (*parent->inner_draws())[l] = child;
}

/*!
 * \fn char* toString(::CORBA::Long id)
 * \brief This method is a local call to the Draw class method.
 * 
 * \param id the id of the draw
 * 
 * \return the user-friendly formatted string that represent the draw.
 * 
 */
char* DrawServiceImpl::toString(::CORBA::Long id) {
    ::PetitPrince::Draw* d = PetitPrinceServiceImpl::_draw_list.at(id);
    return d->toString();
}

