/*!
 * \file DrawServiceImpl.hpp
 * \author Enzo Ramos
 * \version 1.0
 *
 * \brief Define DrawService interface implementation.
 * 
 */

#ifndef DRAWSERVICEIMPL_HPP
#define DRAWSERVICEIMPL_HPP

#include "PetitPrince.hpp"

/*!
 * \class DrawServiceImpl DrawServiceImpl.hpp
 * \brief This class implements the DrawService interface generated by the idl
 * after compilation. The DrawService class inherited is the POA version. The
 * POA classes inherit the _impl_ classes which inherit the interfaces.
 * This class will define the implementation of each methods contained in the
 * interface (see cpp source file).
 */
class DrawServiceImpl : virtual public POA_PetitPrince::DrawService,
                        virtual public PortableServer::RefCountServantBase{
public:
    DrawServiceImpl();
    DrawServiceImpl(const DrawServiceImpl& orig);
    DrawServiceImpl(CORBA::ORB_var orb);
    virtual ~DrawServiceImpl();
    
    /*!
     * \fn ::CORBA::Double area(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * 
     * \return the calculated area of the draw.
     */
    ::CORBA::Double area(::CORBA::Long id) override;
    
    /*!
     * \fn ::CORBA::Double perimeter(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * 
     * \return the calculated perimeter of the draw.
     */
    ::CORBA::Double perimeter(::CORBA::Long id) override;
    
    /*!
     * \fn void homothetie(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * \param index the scalar factor to apply to the draw
     * 
     */
    void homothetie(::CORBA::Long id, ::CORBA::Double index) override;
    
    /*!
     * \fn void translation(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * \param x the x translation to apply to the draw
     * \param y the y translation to apply to the draw
     * 
     */
    void translation(::CORBA::Long id, ::CORBA::Double x, ::CORBA::Double y) override;
    
    /*!
     * \fn void rotation(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * \param angle the angle to rotate the draw
     * 
     */
    void rotation(::CORBA::Long id, ::CORBA::Double angle) override;
    
    /*!
     * \fn void symCenter(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * 
     */
    void symCenter(::CORBA::Long id) override;
    
    /*!
     * \fn void symAxial(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * 
     */
    void symAxial(::CORBA::Long id) override;
    
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
    void addDraw(::CORBA::Long pid, ::CORBA::Long cid) override;
    
    /*!
     * \fn char* toString(::CORBA::Long id)
     * \brief This method is a local call to the Draw class method.
     * 
     * \param id the id of the draw
     * 
     * \return the user-friendly formatted string that represent the draw.
     * 
     */
    char* toString(::CORBA::Long id) override;
    
private:
    CORBA::ORB_var _orb;
    
};

#endif /* DRAWSERVICEIMPL_HPP */

