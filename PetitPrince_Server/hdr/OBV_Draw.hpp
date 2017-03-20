/*!
 * \file OBV_Draw.hpp
 * \author Jerome Ramsamy
 * \version 1.0
 *
 * \brief Define Draw class implementation.
 * 
 */

#ifndef OBV_DRAW_HPP
#define OBV_DRAW_HPP

#include "PetitPrince.hpp"

#include <omniORB4/CORBA.h>
#include <sstream>

using namespace std;


/*!
 * \class Draw OBV_Draw.hpp
 * \brief This class is a virtual class that define the first behavior of each
 * draws that will be implemented.
 */
class Draw : public virtual ::OBV_PetitPrince::Draw {

protected:
    /*!
     * \fn Draw(::CORBA::Long id, char* author, ::CORBA::Double mark)
     * \brief The protected constructor of the class Draw. Only called by sub classes.
     * 
     * \param id the id of the draw (auto-generated)
     * \param author the author of the draw
     * \param mark the mark for this draw
     */
    Draw(::CORBA::Long id, char* author, ::CORBA::Double mark)
            : _id(id), _author(author), _mark(mark) {
    }
    virtual ~Draw() {
    }

    
public:
    /*!
     * \fn ::CORBA::Long id()
     * \brief The getter for the id field
     * 
     * \return the id of this draw
     */
    ::CORBA::Long id() override {
        return this->_id;
    }
    
    /*!
     * \fn char* author()
     * \brief The getter for the author field
     * 
     * \return the author of this draw
     */
    char* author() override {
        return this->_author;
    }
    
    /*!
     * \fn ::PetitPrince::DrawSeq* inner_draws()
     * \brief The getter for the inner draws field
     * 
     * \return the inner draws of this draw
     */
    ::PetitPrince::DrawSeq* inner_draws() override {
        return &this->_inner_draws;
    }
    
    /*!
     * \fn void inner_draws(::PetitPrince::DrawSeq& _v)
     * \brief The setter for the inner draws field
     * 
     * \param _v the inner draws to add (replace current inner draws)
     */
    void inner_draws(const ::PetitPrince::DrawSeq& _v) override {
        this->_inner_draws = _v;
    }
    
    /*!
     * \fn ::CORBA::Long id()
     * \brief The getter for the id field
     * 
     * \return the id of this draw
     */
    ::CORBA::Double mark() override {
        return this->_mark;
    }
    
    /*!
     * \fn void mark(::CORBA::Double _v)
     * \brief The setter for the mark field
     * 
     * \param _v the mark to set (replace current mark)
     */
    void mark(::CORBA::Double _v) override {
        this->_mark = _v;
    }

    /*!
     * \fn char* toString()
     * \brief Generate a user-friendly representation of this draw
     * 
     * \return The user-friendly representation of this draw
     */
    char* toString() override {
        stringstream stream;
        stream << "Draw(id: " << _id  <<  ", author: "  <<  _author  <<  ", mark: "  <<  _mark << ")";
        return strcpy(new char[stream.str().size()+1], stream.str().c_str());
    }
    
    void _add_ref() override {}
    ::CORBA::ULong _refcount_value() override {}
    void _remove_ref() override {}
    
protected:
    string innerDrawsToString(int deep = 0) {
        stringstream stream;
        long l = _inner_draws.length();
        if(l > 0) {
            for(int i=0; i<deep+1; i++) {
                stream << "\t";
            }
            stream << "(" << _inner_draws[0]->toString() << ")";
            for(int i=1; i<l; i++) {
                stream << ",(" << _inner_draws[i]->toString() << ")";
            }
        }
        return stream.str();
    }

private:
    ::CORBA::Long _id;
    char* _author;
    ::PetitPrince::DrawSeq _inner_draws;
    ::CORBA::Double _mark;

};


#endif /* OBV_DRAW_HPP */

