// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.
#ifndef __ServiceDraw_hh__
#define __ServiceDraw_hh__

#ifndef __CORBA_H_EXTERNAL_GUARD__
#include <omniORB4/CORBA.h>
#endif

#ifndef  USE_stub_in_nt_dll
# define USE_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
#endif
#ifndef  USE_core_stub_in_nt_dll
# define USE_core_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
#endif
#ifndef  USE_dyn_stub_in_nt_dll
# define USE_dyn_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
#endif






#ifdef USE_stub_in_nt_dll
# ifndef USE_core_stub_in_nt_dll
#  define USE_core_stub_in_nt_dll
# endif
# ifndef USE_dyn_stub_in_nt_dll
#  define USE_dyn_stub_in_nt_dll
# endif
#endif

#ifdef _core_attr
# error "A local CPP macro _core_attr has already been defined."
#else
# ifdef  USE_core_stub_in_nt_dll
#  define _core_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _core_attr
# endif
#endif

#ifdef _dyn_attr
# error "A local CPP macro _dyn_attr has already been defined."
#else
# ifdef  USE_dyn_stub_in_nt_dll
#  define _dyn_attr _OMNIORB_NTDLL_IMPORT
# else
#  define _dyn_attr
# endif
#endif





_CORBA_MODULE PetitPrince

_CORBA_MODULE_BEG

  struct Point {
    typedef _CORBA_ConstrType_Fix_Var<Point> _var_type;

    
    ::CORBA::Double x;

    ::CORBA::Double y;

  

    void operator>>= (cdrStream &) const;
    void operator<<= (cdrStream &);
  };

  typedef Point::_var_type Point_var;

  typedef Point& Point_out;

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_Point;

#ifndef __PetitPrince_mDraw__
#define __PetitPrince_mDraw__

  class Draw;

  class Draw_Helper {
  public:
    static void add_ref(Draw*);
    static void remove_ref(Draw*);
    static void marshal(Draw*, cdrStream&);
    static Draw* unmarshal(cdrStream&);
  };

  typedef _CORBA_Value_Var    <Draw,Draw_Helper> Draw_var;
  typedef _CORBA_Value_Member <Draw,Draw_Helper> Draw_member;
  typedef _CORBA_Value_OUT_arg<Draw,Draw_Helper> Draw_out;

#endif // __PetitPrince_mDraw__

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_DrawSeq;

  class DrawSeq_var;

  class DrawSeq : public _CORBA_Unbounded_Sequence_Value< Draw, _CORBA_Value_Element< Draw, Draw_Helper > , Draw_Helper >  {
  public:
    typedef DrawSeq_var _var_type;
    inline DrawSeq() {}
    inline DrawSeq(const DrawSeq& _s)
      : _CORBA_Unbounded_Sequence_Value< Draw, _CORBA_Value_Element< Draw, Draw_Helper > , Draw_Helper > (_s) {}

    inline DrawSeq(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence_Value< Draw, _CORBA_Value_Element< Draw, Draw_Helper > , Draw_Helper > (_max) {}
    inline DrawSeq(_CORBA_ULong _max, _CORBA_ULong _len, Draw** _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence_Value< Draw, _CORBA_Value_Element< Draw, Draw_Helper > , Draw_Helper > (_max, _len, _val, _rel) {}

  

    inline DrawSeq& operator = (const DrawSeq& _s) {
      _CORBA_Unbounded_Sequence_Value< Draw, _CORBA_Value_Element< Draw, Draw_Helper > , Draw_Helper > ::operator=(_s);
      return *this;
    }
  };

  class DrawSeq_out;

  class DrawSeq_var {
  public:
    inline DrawSeq_var() : _pd_seq(0) {}
    inline DrawSeq_var(DrawSeq* _s) : _pd_seq(_s) {}
    inline DrawSeq_var(const DrawSeq_var& _s) {
      if( _s._pd_seq )  _pd_seq = new DrawSeq(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~DrawSeq_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline DrawSeq_var& operator = (DrawSeq* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline DrawSeq_var& operator = (const DrawSeq_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new DrawSeq;
        *_pd_seq = *_s._pd_seq;
      } else if( _pd_seq ) {
        delete _pd_seq;
        _pd_seq = 0;
      }
      return *this;
    }
    inline _CORBA_Value_Element< Draw, Draw_Helper >  operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline DrawSeq* operator -> () { return _pd_seq; }
    inline const DrawSeq* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator DrawSeq& () const { return *_pd_seq; }
#else
    inline operator const DrawSeq& () const { return *_pd_seq; }
    inline operator DrawSeq& () { return *_pd_seq; }
#endif
      
    inline const DrawSeq& in() const { return *_pd_seq; }
    inline DrawSeq&       inout()    { return *_pd_seq; }
    inline DrawSeq*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline DrawSeq* _retn() { DrawSeq* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class DrawSeq_out;
    
  private:
    DrawSeq* _pd_seq;
  };

  class DrawSeq_out {
  public:
    inline DrawSeq_out(DrawSeq*& _s) : _data(_s) { _data = 0; }
    inline DrawSeq_out(DrawSeq_var& _s)
      : _data(_s._pd_seq) { _s = (DrawSeq*) 0; }
    inline DrawSeq_out(const DrawSeq_out& _s) : _data(_s._data) {}
    inline DrawSeq_out& operator = (const DrawSeq_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline DrawSeq_out& operator = (DrawSeq* _s) {
      _data = _s;
      return *this;
    }
    inline operator DrawSeq*&()  { return _data; }
    inline DrawSeq*& ptr()       { return _data; }
    inline DrawSeq* operator->() { return _data; }

    inline _CORBA_Value_Element< Draw, Draw_Helper >  operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    DrawSeq*& _data;

  private:
    DrawSeq_out();
    DrawSeq_out& operator=(const DrawSeq_var&);
  };

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_PointSeq;

  class PointSeq_var;

  class PointSeq : public _CORBA_Unbounded_Sequence< Point >  {
  public:
    typedef PointSeq_var _var_type;
    inline PointSeq() {}
    inline PointSeq(const PointSeq& _s)
      : _CORBA_Unbounded_Sequence< Point > (_s) {}

    inline PointSeq(_CORBA_ULong _max)
      : _CORBA_Unbounded_Sequence< Point > (_max) {}
    inline PointSeq(_CORBA_ULong _max, _CORBA_ULong _len, Point* _val, _CORBA_Boolean _rel=0)
      : _CORBA_Unbounded_Sequence< Point > (_max, _len, _val, _rel) {}

  

    inline PointSeq& operator = (const PointSeq& _s) {
      _CORBA_Unbounded_Sequence< Point > ::operator=(_s);
      return *this;
    }
  };

  class PointSeq_out;

  class PointSeq_var {
  public:
    inline PointSeq_var() : _pd_seq(0) {}
    inline PointSeq_var(PointSeq* _s) : _pd_seq(_s) {}
    inline PointSeq_var(const PointSeq_var& _s) {
      if( _s._pd_seq )  _pd_seq = new PointSeq(*_s._pd_seq);
      else              _pd_seq = 0;
    }
    inline ~PointSeq_var() { if( _pd_seq )  delete _pd_seq; }
      
    inline PointSeq_var& operator = (PointSeq* _s) {
      if( _pd_seq )  delete _pd_seq;
      _pd_seq = _s;
      return *this;
    }
    inline PointSeq_var& operator = (const PointSeq_var& _s) {
      if( _s._pd_seq ) {
        if( !_pd_seq )  _pd_seq = new PointSeq;
        *_pd_seq = *_s._pd_seq;
      } else if( _pd_seq ) {
        delete _pd_seq;
        _pd_seq = 0;
      }
      return *this;
    }
    inline Point& operator [] (_CORBA_ULong _s) {
      return (*_pd_seq)[_s];
    }

  

    inline PointSeq* operator -> () { return _pd_seq; }
    inline const PointSeq* operator -> () const { return _pd_seq; }
#if defined(__GNUG__)
    inline operator PointSeq& () const { return *_pd_seq; }
#else
    inline operator const PointSeq& () const { return *_pd_seq; }
    inline operator PointSeq& () { return *_pd_seq; }
#endif
      
    inline const PointSeq& in() const { return *_pd_seq; }
    inline PointSeq&       inout()    { return *_pd_seq; }
    inline PointSeq*&      out() {
      if( _pd_seq ) { delete _pd_seq; _pd_seq = 0; }
      return _pd_seq;
    }
    inline PointSeq* _retn() { PointSeq* tmp = _pd_seq; _pd_seq = 0; return tmp; }
      
    friend class PointSeq_out;
    
  private:
    PointSeq* _pd_seq;
  };

  class PointSeq_out {
  public:
    inline PointSeq_out(PointSeq*& _s) : _data(_s) { _data = 0; }
    inline PointSeq_out(PointSeq_var& _s)
      : _data(_s._pd_seq) { _s = (PointSeq*) 0; }
    inline PointSeq_out(const PointSeq_out& _s) : _data(_s._data) {}
    inline PointSeq_out& operator = (const PointSeq_out& _s) {
      _data = _s._data;
      return *this;
    }
    inline PointSeq_out& operator = (PointSeq* _s) {
      _data = _s;
      return *this;
    }
    inline operator PointSeq*&()  { return _data; }
    inline PointSeq*& ptr()       { return _data; }
    inline PointSeq* operator->() { return _data; }

    inline Point& operator [] (_CORBA_ULong _i) {
      return (*_data)[_i];
    }

  

    PointSeq*& _data;

  private:
    PointSeq_out();
    PointSeq_out& operator=(const PointSeq_var&);
  };

#ifndef __PetitPrince_mDraw__
#define __PetitPrince_mDraw__

  class Draw;

  class Draw_Helper {
  public:
    static void add_ref(Draw*);
    static void remove_ref(Draw*);
    static void marshal(Draw*, cdrStream&);
    static Draw* unmarshal(cdrStream&);
  };

  typedef _CORBA_Value_Var    <Draw,Draw_Helper> Draw_var;
  typedef _CORBA_Value_Member <Draw,Draw_Helper> Draw_member;
  typedef _CORBA_Value_OUT_arg<Draw,Draw_Helper> Draw_out;

#endif // __PetitPrince_mDraw__

  class Draw : 
    public virtual ::CORBA::ValueBase
  {
  public:  
    // Standard mapping
    typedef Draw*    _ptr_type;
    typedef Draw_var _var_type;

    static _ptr_type _downcast(::CORBA::ValueBase*);
    

#ifdef OMNI_HAVE_COVARIANT_RETURNS
    virtual Draw* _copy_value();
#else
    virtual ::CORBA::ValueBase* _copy_value();
#endif

    // Definitions in this scope
    

    // Operations and attributes
    virtual ::CORBA::Long id() = 0;
    virtual char* author() = 0;
    virtual DrawSeq* inner_draws() = 0;
    virtual void inner_draws(const ::PetitPrince::DrawSeq& _v) = 0;
    virtual ::CORBA::Double mark() = 0;
    virtual void mark(::CORBA::Double _v) = 0;
    virtual ::CORBA::Double area() = 0;
    virtual ::CORBA::Double perimeter() = 0;
    virtual void homothetie(::CORBA::Double indice) = 0;
    virtual void translation(::CORBA::Double x, ::CORBA::Double y) = 0;
    virtual void rotation(::CORBA::Double angle) = 0;
    virtual void symCenter() = 0;
    virtual void symAxial() = 0;
    virtual char* toString() = 0;

    // Accessors for public members
    

  protected:
    // Accessors for private members
    

  public:
    // omniORB internal
    virtual const char* _NP_repositoryId() const;
    virtual const char* _NP_repositoryId(::CORBA::ULong& _hashval) const;

    virtual const _omni_ValueIds* _NP_truncatableIds() const;

    virtual ::CORBA::Boolean _NP_custom() const;

    virtual void* _ptrToValue(const char* id);

    static void _NP_marshal(Draw*, cdrStream&);
    static Draw* _NP_unmarshal(cdrStream&);
    

    virtual void _PR_marshal_state(cdrStream&) const;
    virtual void _PR_unmarshal_state(cdrStream&);
    virtual void _PR_copy_state(Draw*);

    static _core_attr const char* _PD_repoId;

  protected:
    Draw();
    virtual ~Draw();

  private:
    // Not implemented
    Draw(const Draw &);
    void operator=(const Draw &);
  };

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_Draw;

#ifndef __PetitPrince_mLine__
#define __PetitPrince_mLine__

  class Line;

  class Line_Helper {
  public:
    static void add_ref(Line*);
    static void remove_ref(Line*);
    static void marshal(Line*, cdrStream&);
    static Line* unmarshal(cdrStream&);
  };

  typedef _CORBA_Value_Var    <Line,Line_Helper> Line_var;
  typedef _CORBA_Value_Member <Line,Line_Helper> Line_member;
  typedef _CORBA_Value_OUT_arg<Line,Line_Helper> Line_out;

#endif // __PetitPrince_mLine__

  class Line : 
    public virtual Draw
  {
  public:  
    // Standard mapping
    typedef Line*    _ptr_type;
    typedef Line_var _var_type;

    static _ptr_type _downcast(::CORBA::ValueBase*);
    

#ifdef OMNI_HAVE_COVARIANT_RETURNS
    virtual Line* _copy_value();
#else
    virtual ::CORBA::ValueBase* _copy_value();
#endif

    // Definitions in this scope
    

    // Operations and attributes
    virtual Point start() = 0;
    virtual void start(const ::PetitPrince::Point& _v) = 0;
    virtual Point end() = 0;
    virtual void end(const ::PetitPrince::Point& _v) = 0;

    // Accessors for public members
    

  protected:
    // Accessors for private members
    

  public:
    // omniORB internal
    virtual const char* _NP_repositoryId() const;
    virtual const char* _NP_repositoryId(::CORBA::ULong& _hashval) const;

    virtual const _omni_ValueIds* _NP_truncatableIds() const;

    virtual ::CORBA::Boolean _NP_custom() const;

    virtual void* _ptrToValue(const char* id);

    static void _NP_marshal(Line*, cdrStream&);
    static Line* _NP_unmarshal(cdrStream&);
    

    virtual void _PR_marshal_state(cdrStream&) const;
    virtual void _PR_unmarshal_state(cdrStream&);
    virtual void _PR_copy_state(Line*);

    static _core_attr const char* _PD_repoId;

  protected:
    Line();
    virtual ~Line();

  private:
    // Not implemented
    Line(const Line &);
    void operator=(const Line &);
  };

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_Line;

#ifndef __PetitPrince_mCircle__
#define __PetitPrince_mCircle__

  class Circle;

  class Circle_Helper {
  public:
    static void add_ref(Circle*);
    static void remove_ref(Circle*);
    static void marshal(Circle*, cdrStream&);
    static Circle* unmarshal(cdrStream&);
  };

  typedef _CORBA_Value_Var    <Circle,Circle_Helper> Circle_var;
  typedef _CORBA_Value_Member <Circle,Circle_Helper> Circle_member;
  typedef _CORBA_Value_OUT_arg<Circle,Circle_Helper> Circle_out;

#endif // __PetitPrince_mCircle__

  class Circle : 
    public virtual Draw
  {
  public:  
    // Standard mapping
    typedef Circle*    _ptr_type;
    typedef Circle_var _var_type;

    static _ptr_type _downcast(::CORBA::ValueBase*);
    

#ifdef OMNI_HAVE_COVARIANT_RETURNS
    virtual Circle* _copy_value();
#else
    virtual ::CORBA::ValueBase* _copy_value();
#endif

    // Definitions in this scope
    

    // Operations and attributes
    virtual Point center() = 0;
    virtual void center(const ::PetitPrince::Point& _v) = 0;
    virtual ::CORBA::Double ray() = 0;
    virtual void ray(::CORBA::Double _v) = 0;

    // Accessors for public members
    

  protected:
    // Accessors for private members
    

  public:
    // omniORB internal
    virtual const char* _NP_repositoryId() const;
    virtual const char* _NP_repositoryId(::CORBA::ULong& _hashval) const;

    virtual const _omni_ValueIds* _NP_truncatableIds() const;

    virtual ::CORBA::Boolean _NP_custom() const;

    virtual void* _ptrToValue(const char* id);

    static void _NP_marshal(Circle*, cdrStream&);
    static Circle* _NP_unmarshal(cdrStream&);
    

    virtual void _PR_marshal_state(cdrStream&) const;
    virtual void _PR_unmarshal_state(cdrStream&);
    virtual void _PR_copy_state(Circle*);

    static _core_attr const char* _PD_repoId;

  protected:
    Circle();
    virtual ~Circle();

  private:
    // Not implemented
    Circle(const Circle &);
    void operator=(const Circle &);
  };

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_Circle;

#ifndef __PetitPrince_mEllipse__
#define __PetitPrince_mEllipse__

  class Ellipse;

  class Ellipse_Helper {
  public:
    static void add_ref(Ellipse*);
    static void remove_ref(Ellipse*);
    static void marshal(Ellipse*, cdrStream&);
    static Ellipse* unmarshal(cdrStream&);
  };

  typedef _CORBA_Value_Var    <Ellipse,Ellipse_Helper> Ellipse_var;
  typedef _CORBA_Value_Member <Ellipse,Ellipse_Helper> Ellipse_member;
  typedef _CORBA_Value_OUT_arg<Ellipse,Ellipse_Helper> Ellipse_out;

#endif // __PetitPrince_mEllipse__

  class Ellipse : 
    public virtual Draw
  {
  public:  
    // Standard mapping
    typedef Ellipse*    _ptr_type;
    typedef Ellipse_var _var_type;

    static _ptr_type _downcast(::CORBA::ValueBase*);
    

#ifdef OMNI_HAVE_COVARIANT_RETURNS
    virtual Ellipse* _copy_value();
#else
    virtual ::CORBA::ValueBase* _copy_value();
#endif

    // Definitions in this scope
    

    // Operations and attributes
    virtual Point center() = 0;
    virtual void center(const ::PetitPrince::Point& _v) = 0;
    virtual ::CORBA::Double long_ray() = 0;
    virtual void long_ray(::CORBA::Double _v) = 0;
    virtual ::CORBA::Double short_ray() = 0;
    virtual void short_ray(::CORBA::Double _v) = 0;

    // Accessors for public members
    

  protected:
    // Accessors for private members
    

  public:
    // omniORB internal
    virtual const char* _NP_repositoryId() const;
    virtual const char* _NP_repositoryId(::CORBA::ULong& _hashval) const;

    virtual const _omni_ValueIds* _NP_truncatableIds() const;

    virtual ::CORBA::Boolean _NP_custom() const;

    virtual void* _ptrToValue(const char* id);

    static void _NP_marshal(Ellipse*, cdrStream&);
    static Ellipse* _NP_unmarshal(cdrStream&);
    

    virtual void _PR_marshal_state(cdrStream&) const;
    virtual void _PR_unmarshal_state(cdrStream&);
    virtual void _PR_copy_state(Ellipse*);

    static _core_attr const char* _PD_repoId;

  protected:
    Ellipse();
    virtual ~Ellipse();

  private:
    // Not implemented
    Ellipse(const Ellipse &);
    void operator=(const Ellipse &);
  };

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_Ellipse;

#ifndef __PetitPrince_mPolygon__
#define __PetitPrince_mPolygon__

  class Polygon;

  class Polygon_Helper {
  public:
    static void add_ref(Polygon*);
    static void remove_ref(Polygon*);
    static void marshal(Polygon*, cdrStream&);
    static Polygon* unmarshal(cdrStream&);
  };

  typedef _CORBA_Value_Var    <Polygon,Polygon_Helper> Polygon_var;
  typedef _CORBA_Value_Member <Polygon,Polygon_Helper> Polygon_member;
  typedef _CORBA_Value_OUT_arg<Polygon,Polygon_Helper> Polygon_out;

#endif // __PetitPrince_mPolygon__

  class Polygon : 
    public virtual Draw
  {
  public:  
    // Standard mapping
    typedef Polygon*    _ptr_type;
    typedef Polygon_var _var_type;

    static _ptr_type _downcast(::CORBA::ValueBase*);
    

#ifdef OMNI_HAVE_COVARIANT_RETURNS
    virtual Polygon* _copy_value();
#else
    virtual ::CORBA::ValueBase* _copy_value();
#endif

    // Definitions in this scope
    

    // Operations and attributes
    virtual PointSeq* points_list() = 0;
    virtual void points_list(const ::PetitPrince::PointSeq& _v) = 0;

    // Accessors for public members
    

  protected:
    // Accessors for private members
    

  public:
    // omniORB internal
    virtual const char* _NP_repositoryId() const;
    virtual const char* _NP_repositoryId(::CORBA::ULong& _hashval) const;

    virtual const _omni_ValueIds* _NP_truncatableIds() const;

    virtual ::CORBA::Boolean _NP_custom() const;

    virtual void* _ptrToValue(const char* id);

    static void _NP_marshal(Polygon*, cdrStream&);
    static Polygon* _NP_unmarshal(cdrStream&);
    

    virtual void _PR_marshal_state(cdrStream&) const;
    virtual void _PR_unmarshal_state(cdrStream&);
    virtual void _PR_copy_state(Polygon*);

    static _core_attr const char* _PD_repoId;

  protected:
    Polygon();
    virtual ~Polygon();

  private:
    // Not implemented
    Polygon(const Polygon &);
    void operator=(const Polygon &);
  };

  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_Polygon;

#ifndef __PetitPrince_mDrawService__
#define __PetitPrince_mDrawService__

  class DrawService;
  class _objref_DrawService;
  class _impl_DrawService;
  
  typedef _objref_DrawService* DrawService_ptr;
  typedef DrawService_ptr DrawServiceRef;

  class DrawService_Helper {
  public:
    typedef DrawService_ptr _ptr_type;

    static _ptr_type _nil();
    static _CORBA_Boolean is_nil(_ptr_type);
    static void release(_ptr_type);
    static void duplicate(_ptr_type);
    static void marshalObjRef(_ptr_type, cdrStream&);
    static _ptr_type unmarshalObjRef(cdrStream&);
  };

  typedef _CORBA_ObjRef_Var<_objref_DrawService, DrawService_Helper> DrawService_var;
  typedef _CORBA_ObjRef_OUT_arg<_objref_DrawService,DrawService_Helper > DrawService_out;

#endif

  // interface DrawService
  class DrawService {
  public:
    // Declarations for this interface type.
    typedef DrawService_ptr _ptr_type;
    typedef DrawService_var _var_type;

    static _ptr_type _duplicate(_ptr_type);
    static _ptr_type _narrow(::CORBA::Object_ptr);
    static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
    
    static _ptr_type _nil();

    static inline void _marshalObjRef(_ptr_type, cdrStream&);

    static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
      omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static _core_attr const char* _PD_repoId;

    // Other IDL defined within this scope.
    class non_applicable : public ::CORBA::UserException {
    public:
      
      ::CORBA::String_member msg;

    

      inline non_applicable() {
        pd_insertToAnyFn    = insertToAnyFn;
        pd_insertToAnyFnNCP = insertToAnyFnNCP;
      }
      non_applicable(const non_applicable&);
      non_applicable(const char* i_msg);
      non_applicable& operator=(const non_applicable&);
      virtual ~non_applicable();
      virtual void _raise() const;
      static non_applicable* _downcast(::CORBA::Exception*);
      static const non_applicable* _downcast(const ::CORBA::Exception*);
      static inline non_applicable* _narrow(::CORBA::Exception* _e) {
        return _downcast(_e);
      }
      
      void operator>>=(cdrStream&) const ;
      void operator<<=(cdrStream&) ;

      static _core_attr insertExceptionToAny    insertToAnyFn;
      static _core_attr insertExceptionToAnyNCP insertToAnyFnNCP;

      virtual ::CORBA::Exception* _NP_duplicate() const;

      static _core_attr const char* _PD_repoId;
      static _core_attr const char* _PD_typeId;

    private:
      virtual const char* _NP_typeId() const;
      virtual const char* _NP_repoId(int*) const;
      virtual void _NP_marshal(cdrStream&) const;
    };

    static _dyn_attr const ::CORBA::TypeCode_ptr _tc_non_applicable;

    class unexpected_draw : public ::CORBA::UserException {
    public:
      
      ::CORBA::String_member msg;

    

      inline unexpected_draw() {
        pd_insertToAnyFn    = insertToAnyFn;
        pd_insertToAnyFnNCP = insertToAnyFnNCP;
      }
      unexpected_draw(const unexpected_draw&);
      unexpected_draw(const char* i_msg);
      unexpected_draw& operator=(const unexpected_draw&);
      virtual ~unexpected_draw();
      virtual void _raise() const;
      static unexpected_draw* _downcast(::CORBA::Exception*);
      static const unexpected_draw* _downcast(const ::CORBA::Exception*);
      static inline unexpected_draw* _narrow(::CORBA::Exception* _e) {
        return _downcast(_e);
      }
      
      void operator>>=(cdrStream&) const ;
      void operator<<=(cdrStream&) ;

      static _core_attr insertExceptionToAny    insertToAnyFn;
      static _core_attr insertExceptionToAnyNCP insertToAnyFnNCP;

      virtual ::CORBA::Exception* _NP_duplicate() const;

      static _core_attr const char* _PD_repoId;
      static _core_attr const char* _PD_typeId;

    private:
      virtual const char* _NP_typeId() const;
      virtual const char* _NP_repoId(int*) const;
      virtual void _NP_marshal(cdrStream&) const;
    };

    static _dyn_attr const ::CORBA::TypeCode_ptr _tc_unexpected_draw;

  
  };

  class _objref_DrawService :
    public virtual ::CORBA::Object,
    public virtual omniObjRef
  {
  public:
    ::CORBA::Double area(::PetitPrince::Draw* d);
    ::CORBA::Double perimeter(::PetitPrince::Draw* d);
    void homothetie(::PetitPrince::Draw* d, ::CORBA::Double indice);
    void translation(::PetitPrince::Draw* d, ::CORBA::Double x, ::CORBA::Double y);
    void rotation(::PetitPrince::Draw* d, ::CORBA::Double angle);
    void symCenter(::PetitPrince::Draw* d);
    void symAxial(::PetitPrince::Draw* d);
    void addDraw(::PetitPrince::Draw* parent, ::PetitPrince::Draw* child);
    char* toString(::PetitPrince::Draw* d);

    inline _objref_DrawService()  { _PR_setobj(0); }  // nil
    _objref_DrawService(omniIOR*, omniIdentity*);

  protected:
    virtual ~_objref_DrawService();

    
  private:
    virtual void* _ptrToObjRef(const char*);

    _objref_DrawService(const _objref_DrawService&);
    _objref_DrawService& operator = (const _objref_DrawService&);
    // not implemented

    friend class DrawService;
  };

  class _pof_DrawService : public _OMNI_NS(proxyObjectFactory) {
  public:
    inline _pof_DrawService() : _OMNI_NS(proxyObjectFactory)(DrawService::_PD_repoId) {}
    virtual ~_pof_DrawService();

    virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
    virtual _CORBA_Boolean is_a(const char*) const;
  };

  class _impl_DrawService :
    public virtual omniServant
  {
  public:
    virtual ~_impl_DrawService();

    virtual ::CORBA::Double area(::PetitPrince::Draw* d) = 0;
    virtual ::CORBA::Double perimeter(::PetitPrince::Draw* d) = 0;
    virtual void homothetie(::PetitPrince::Draw* d, ::CORBA::Double indice) = 0;
    virtual void translation(::PetitPrince::Draw* d, ::CORBA::Double x, ::CORBA::Double y) = 0;
    virtual void rotation(::PetitPrince::Draw* d, ::CORBA::Double angle) = 0;
    virtual void symCenter(::PetitPrince::Draw* d) = 0;
    virtual void symAxial(::PetitPrince::Draw* d) = 0;
    virtual void addDraw(::PetitPrince::Draw* parent, ::PetitPrince::Draw* child) = 0;
    virtual char* toString(::PetitPrince::Draw* d) = 0;
    
  public:  // Really protected, workaround for xlC
    virtual _CORBA_Boolean _dispatch(omniCallHandle&);

  private:
    virtual void* _ptrToInterface(const char*);
    virtual const char* _mostDerivedRepoId();
    
  };


  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_DrawService;

#ifndef __PetitPrince_mPetitPrinceService__
#define __PetitPrince_mPetitPrinceService__

  class PetitPrinceService;
  class _objref_PetitPrinceService;
  class _impl_PetitPrinceService;
  
  typedef _objref_PetitPrinceService* PetitPrinceService_ptr;
  typedef PetitPrinceService_ptr PetitPrinceServiceRef;

  class PetitPrinceService_Helper {
  public:
    typedef PetitPrinceService_ptr _ptr_type;

    static _ptr_type _nil();
    static _CORBA_Boolean is_nil(_ptr_type);
    static void release(_ptr_type);
    static void duplicate(_ptr_type);
    static void marshalObjRef(_ptr_type, cdrStream&);
    static _ptr_type unmarshalObjRef(cdrStream&);
  };

  typedef _CORBA_ObjRef_Var<_objref_PetitPrinceService, PetitPrinceService_Helper> PetitPrinceService_var;
  typedef _CORBA_ObjRef_OUT_arg<_objref_PetitPrinceService,PetitPrinceService_Helper > PetitPrinceService_out;

#endif

  // interface PetitPrinceService
  class PetitPrinceService {
  public:
    // Declarations for this interface type.
    typedef PetitPrinceService_ptr _ptr_type;
    typedef PetitPrinceService_var _var_type;

    static _ptr_type _duplicate(_ptr_type);
    static _ptr_type _narrow(::CORBA::Object_ptr);
    static _ptr_type _unchecked_narrow(::CORBA::Object_ptr);
    
    static _ptr_type _nil();

    static inline void _marshalObjRef(_ptr_type, cdrStream&);

    static inline _ptr_type _unmarshalObjRef(cdrStream& s) {
      omniObjRef* o = omniObjRef::_unMarshal(_PD_repoId,s);
      if (o)
        return (_ptr_type) o->_ptrToObjRef(_PD_repoId);
      else
        return _nil();
    }

    static _core_attr const char* _PD_repoId;

    // Other IDL defined within this scope.
    
  };

  class _objref_PetitPrinceService :
    public virtual ::CORBA::Object,
    public virtual omniObjRef
  {
  public:
    void pushDraw(::PetitPrince::Draw* d);
    Draw* getDraw(::CORBA::Long id);
    void markDraw(::CORBA::Double mark, ::CORBA::Long id);
    DrawSeq* draw_list();
    void draw_list(const ::PetitPrince::DrawSeq& _v);

    inline _objref_PetitPrinceService()  { _PR_setobj(0); }  // nil
    _objref_PetitPrinceService(omniIOR*, omniIdentity*);

  protected:
    virtual ~_objref_PetitPrinceService();

    
  private:
    virtual void* _ptrToObjRef(const char*);

    _objref_PetitPrinceService(const _objref_PetitPrinceService&);
    _objref_PetitPrinceService& operator = (const _objref_PetitPrinceService&);
    // not implemented

    friend class PetitPrinceService;
  };

  class _pof_PetitPrinceService : public _OMNI_NS(proxyObjectFactory) {
  public:
    inline _pof_PetitPrinceService() : _OMNI_NS(proxyObjectFactory)(PetitPrinceService::_PD_repoId) {}
    virtual ~_pof_PetitPrinceService();

    virtual omniObjRef* newObjRef(omniIOR*,omniIdentity*);
    virtual _CORBA_Boolean is_a(const char*) const;
  };

  class _impl_PetitPrinceService :
    public virtual omniServant
  {
  public:
    virtual ~_impl_PetitPrinceService();

    virtual void pushDraw(::PetitPrince::Draw* d) = 0;
    virtual Draw* getDraw(::CORBA::Long id) = 0;
    virtual void markDraw(::CORBA::Double mark, ::CORBA::Long id) = 0;
    virtual DrawSeq* draw_list() = 0;
    virtual void draw_list(const ::PetitPrince::DrawSeq& _v) = 0;
    
  public:  // Really protected, workaround for xlC
    virtual _CORBA_Boolean _dispatch(omniCallHandle&);

  private:
    virtual void* _ptrToInterface(const char*);
    virtual const char* _mostDerivedRepoId();
    
  };


  _CORBA_MODULE_VAR _dyn_attr const ::CORBA::TypeCode_ptr _tc_PetitPrinceService;

_CORBA_MODULE_END



_CORBA_MODULE POA_PetitPrince
_CORBA_MODULE_BEG

  class DrawService :
    public virtual PetitPrince::_impl_DrawService,
    public virtual ::PortableServer::ServantBase
  {
  public:
    virtual ~DrawService();

    inline ::PetitPrince::DrawService_ptr _this() {
      return (::PetitPrince::DrawService_ptr) _do_this(::PetitPrince::DrawService::_PD_repoId);
    }
  };

  class PetitPrinceService :
    public virtual PetitPrince::_impl_PetitPrinceService,
    public virtual ::PortableServer::ServantBase
  {
  public:
    virtual ~PetitPrinceService();

    inline ::PetitPrince::PetitPrinceService_ptr _this() {
      return (::PetitPrince::PetitPrinceService_ptr) _do_this(::PetitPrince::PetitPrinceService::_PD_repoId);
    }
  };

_CORBA_MODULE_END



_CORBA_MODULE OBV_PetitPrince
_CORBA_MODULE_BEG

  class Draw :
    public virtual PetitPrince::Draw
  {
  protected:
    Draw();
    
    virtual ~Draw();

  public:
    

  protected:
    

  private:
    
  };

  class Line :
    public virtual PetitPrince::Line,
    public virtual Draw
  {
  protected:
    Line();
    
    virtual ~Line();

  public:
    

  protected:
    

  private:
    
  };

  class Circle :
    public virtual PetitPrince::Circle,
    public virtual Draw
  {
  protected:
    Circle();
    
    virtual ~Circle();

  public:
    

  protected:
    

  private:
    
  };

  class Ellipse :
    public virtual PetitPrince::Ellipse,
    public virtual Draw
  {
  protected:
    Ellipse();
    
    virtual ~Ellipse();

  public:
    

  protected:
    

  private:
    
  };

  class Polygon :
    public virtual PetitPrince::Polygon,
    public virtual Draw
  {
  protected:
    Polygon();
    
    virtual ~Polygon();

  public:
    

  protected:
    

  private:
    
  };

_CORBA_MODULE_END





#undef _core_attr
#undef _dyn_attr

extern void operator<<=(::CORBA::Any& _a, const PetitPrince::Point& _s);
extern void operator<<=(::CORBA::Any& _a, PetitPrince::Point* _sp);
extern _CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Point*& _sp);
extern _CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::Point*& _sp);

void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawSeq& _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::DrawSeq* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::DrawSeq*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::DrawSeq*& _sp);

void operator<<=(::CORBA::Any& _a, const PetitPrince::PointSeq& _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::PointSeq* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::PointSeq*& _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::PointSeq*& _sp);

void operator<<=(::CORBA::Any& _a, PetitPrince::Draw* _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::Draw** _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Draw*& _s);

void operator<<=(::CORBA::Any& _a, PetitPrince::Line* _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::Line** _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Line*& _s);

void operator<<=(::CORBA::Any& _a, PetitPrince::Circle* _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::Circle** _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Circle*& _s);

void operator<<=(::CORBA::Any& _a, PetitPrince::Ellipse* _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::Ellipse** _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Ellipse*& _s);

void operator<<=(::CORBA::Any& _a, PetitPrince::Polygon* _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::Polygon** _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Polygon*& _s);

void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::non_applicable& _s);
void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::non_applicable* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::DrawService::non_applicable*& _sp);

void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::unexpected_draw& _s);
void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::unexpected_draw* _sp);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::DrawService::unexpected_draw*& _sp);

void operator<<=(::CORBA::Any& _a, PetitPrince::DrawService_ptr _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::DrawService_ptr* _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::DrawService_ptr& _s);

void operator<<=(::CORBA::Any& _a, PetitPrince::PetitPrinceService_ptr _s);
void operator<<=(::CORBA::Any& _a, PetitPrince::PetitPrinceService_ptr* _s);
_CORBA_Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::PetitPrinceService_ptr& _s);



inline void
PetitPrince::DrawService::_marshalObjRef(::PetitPrince::DrawService_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}


inline void
PetitPrince::PetitPrinceService::_marshalObjRef(::PetitPrince::PetitPrinceService_ptr obj, cdrStream& s) {
  omniObjRef::_marshal(obj->_PR_getobj(),s);
}




#ifdef   USE_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
# undef  USE_stub_in_nt_dll
# undef  USE_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
#endif
#ifdef   USE_core_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
# undef  USE_core_stub_in_nt_dll
# undef  USE_core_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
#endif
#ifdef   USE_dyn_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
# undef  USE_dyn_stub_in_nt_dll
# undef  USE_dyn_stub_in_nt_dll_NOT_DEFINED_ServiceDraw
#endif

#endif  // __ServiceDraw_hh__

