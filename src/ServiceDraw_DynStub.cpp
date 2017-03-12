// This file is generated by omniidl (C++ backend) - omniORB_4_1. Do not edit.

#include "ServiceDraw.hpp"

OMNI_USING_NAMESPACE(omni)

static const char* _0RL_dyn_library_version = omniORB_4_1_dyn;

static ::CORBA::TypeCode::_Tracker _0RL_tcTrack(__FILE__);

static CORBA::PR_structMember _0RL_structmember_PetitPrince_mPoint[] = {
  {"x", CORBA::TypeCode::PR_long_tc()},
  {"y", CORBA::TypeCode::PR_long_tc()}
};

#ifdef _0RL_tc_PetitPrince_mPoint
#  undef _0RL_tc_PetitPrince_mPoint
#endif
static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mPoint = CORBA::TypeCode::PR_struct_tc("IDL:PetitPrince/Point:1.0", "Point", _0RL_structmember_PetitPrince_mPoint, 2, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_Point = _0RL_tc_PetitPrince_mPoint;
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_Point = _0RL_tc_PetitPrince_mPoint;
#endif


static CORBA::TypeCode_ptr _0RL_ft_PetitPrince_mDraw = CORBA::TypeCode::PR_forward_tc("IDL:PetitPrince/Draw:1.0", &_0RL_tcTrack);
#define _0RL_tc_PetitPrince_mDraw _0RL_ft_PetitPrince_mDraw

static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mDrawSeq = CORBA::TypeCode::PR_alias_tc("IDL:PetitPrince/DrawSeq:1.0", "DrawSeq", CORBA::TypeCode::PR_sequence_tc(0, _0RL_tc_PetitPrince_mDraw, &_0RL_tcTrack), &_0RL_tcTrack);


#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_DrawSeq = _0RL_tc_PetitPrince_mDrawSeq;
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_DrawSeq = _0RL_tc_PetitPrince_mDrawSeq;
#endif

static CORBA::PR_valueMember _0RL_valuemember_PetitPrince_mDraw[] = {
  
};

#ifdef _0RL_tc_PetitPrince_mDraw
#  undef _0RL_tc_PetitPrince_mDraw
#endif
static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mDraw = CORBA::TypeCode::PR_value_tc("IDL:PetitPrince/Draw:1.0", "Draw", CORBA::VM_NONE, CORBA::TypeCode::PR_null_tc(), _0RL_valuemember_PetitPrince_mDraw, 0, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_Draw = _0RL_tc_PetitPrince_mDraw;
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_Draw = _0RL_tc_PetitPrince_mDraw;
#endif


static CORBA::TypeCode_ptr _0RL_ft_PetitPrince_mLine = CORBA::TypeCode::PR_forward_tc("IDL:PetitPrince/Line:1.0", &_0RL_tcTrack);
#define _0RL_tc_PetitPrince_mLine _0RL_ft_PetitPrince_mLine

static CORBA::PR_valueMember _0RL_valuemember_PetitPrince_mLine[] = {
  
};

#ifdef _0RL_tc_PetitPrince_mLine
#  undef _0RL_tc_PetitPrince_mLine
#endif
static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mLine = CORBA::TypeCode::PR_value_tc("IDL:PetitPrince/Line:1.0", "Line", CORBA::VM_NONE, _0RL_tc_PetitPrince_mDraw, _0RL_valuemember_PetitPrince_mLine, 0, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_Line = _0RL_tc_PetitPrince_mLine;
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_Line = _0RL_tc_PetitPrince_mLine;
#endif


static CORBA::TypeCode_ptr _0RL_ft_PetitPrince_mCercle = CORBA::TypeCode::PR_forward_tc("IDL:PetitPrince/Cercle:1.0", &_0RL_tcTrack);
#define _0RL_tc_PetitPrince_mCercle _0RL_ft_PetitPrince_mCercle

static CORBA::PR_valueMember _0RL_valuemember_PetitPrince_mCercle[] = {
  
};

#ifdef _0RL_tc_PetitPrince_mCercle
#  undef _0RL_tc_PetitPrince_mCercle
#endif
static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mCercle = CORBA::TypeCode::PR_value_tc("IDL:PetitPrince/Cercle:1.0", "Cercle", CORBA::VM_NONE, _0RL_tc_PetitPrince_mDraw, _0RL_valuemember_PetitPrince_mCercle, 0, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_Cercle = _0RL_tc_PetitPrince_mCercle;
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_Cercle = _0RL_tc_PetitPrince_mCercle;
#endif


static CORBA::TypeCode_ptr _0RL_ft_PetitPrince_mEllipses = CORBA::TypeCode::PR_forward_tc("IDL:PetitPrince/Ellipses:1.0", &_0RL_tcTrack);
#define _0RL_tc_PetitPrince_mEllipses _0RL_ft_PetitPrince_mEllipses

static CORBA::PR_valueMember _0RL_valuemember_PetitPrince_mEllipses[] = {
  
};

#ifdef _0RL_tc_PetitPrince_mEllipses
#  undef _0RL_tc_PetitPrince_mEllipses
#endif
static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mEllipses = CORBA::TypeCode::PR_value_tc("IDL:PetitPrince/Ellipses:1.0", "Ellipses", CORBA::VM_NONE, _0RL_tc_PetitPrince_mDraw, _0RL_valuemember_PetitPrince_mEllipses, 0, &_0RL_tcTrack);

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_Ellipses = _0RL_tc_PetitPrince_mEllipses;
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_Ellipses = _0RL_tc_PetitPrince_mEllipses;
#endif


static CORBA::PR_structMember _0RL_structmember_PetitPrince_mDrawService_mnon__applicable[] = {
  {"msg", CORBA::TypeCode::PR_string_tc(0, &_0RL_tcTrack)}
};

static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mDrawService_mnon__applicable = CORBA::TypeCode::PR_exception_tc("IDL:PetitPrince/DrawService/non_applicable:1.0", "non_applicable", _0RL_structmember_PetitPrince_mDrawService_mnon__applicable, 1, &_0RL_tcTrack);
const CORBA::TypeCode_ptr PetitPrince::DrawService::_tc_non_applicable = _0RL_tc_PetitPrince_mDrawService_mnon__applicable;


static CORBA::PR_structMember _0RL_structmember_PetitPrince_mDrawService_munexpected__draw[] = {
  {"msg", CORBA::TypeCode::PR_string_tc(0, &_0RL_tcTrack)}
};

static CORBA::TypeCode_ptr _0RL_tc_PetitPrince_mDrawService_munexpected__draw = CORBA::TypeCode::PR_exception_tc("IDL:PetitPrince/DrawService/unexpected_draw:1.0", "unexpected_draw", _0RL_structmember_PetitPrince_mDrawService_munexpected__draw, 1, &_0RL_tcTrack);
const CORBA::TypeCode_ptr PetitPrince::DrawService::_tc_unexpected_draw = _0RL_tc_PetitPrince_mDrawService_munexpected__draw;


#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_DrawService = CORBA::TypeCode::PR_interface_tc("IDL:PetitPrince/DrawService:1.0", "DrawService", &_0RL_tcTrack);
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_DrawService = CORBA::TypeCode::PR_interface_tc("IDL:PetitPrince/DrawService:1.0", "DrawService", &_0RL_tcTrack);
#endif

#if defined(HAS_Cplusplus_Namespace) && defined(_MSC_VER)
// MSVC++ does not give the constant external linkage otherwise.
namespace PetitPrince { 
  const ::CORBA::TypeCode_ptr _tc_PetitPrinceService = CORBA::TypeCode::PR_interface_tc("IDL:PetitPrince/PetitPrinceService:1.0", "PetitPrinceService", &_0RL_tcTrack);
} 
#else
const ::CORBA::TypeCode_ptr PetitPrince::_tc_PetitPrinceService = CORBA::TypeCode::PR_interface_tc("IDL:PetitPrince/PetitPrinceService:1.0", "PetitPrinceService", &_0RL_tcTrack);
#endif

static void _0RL_PetitPrince_mPoint_marshal_fn(cdrStream& _s, void* _v)
{
  PetitPrince::Point* _p = (PetitPrince::Point*)_v;
  *_p >>= _s;
}
static void _0RL_PetitPrince_mPoint_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::Point* _p = new PetitPrince::Point;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_PetitPrince_mPoint_destructor_fn(void* _v)
{
  PetitPrince::Point* _p = (PetitPrince::Point*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const PetitPrince::Point& _s)
{
  PetitPrince::Point* _p = new PetitPrince::Point(_s);
  _a.PR_insert(_0RL_tc_PetitPrince_mPoint,
               _0RL_PetitPrince_mPoint_marshal_fn,
               _0RL_PetitPrince_mPoint_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, PetitPrince::Point* _sp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mPoint,
               _0RL_PetitPrince_mPoint_marshal_fn,
               _0RL_PetitPrince_mPoint_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Point*& _sp)
{
  return _a >>= (const PetitPrince::Point*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::Point*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mPoint,
                    _0RL_PetitPrince_mPoint_unmarshal_fn,
                    _0RL_PetitPrince_mPoint_marshal_fn,
                    _0RL_PetitPrince_mPoint_destructor_fn,
                    _v)) {
    _sp = (const PetitPrince::Point*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_PetitPrince_mDrawSeq_marshal_fn(cdrStream& _s, void* _v)
{
  PetitPrince::DrawSeq* _p = (PetitPrince::DrawSeq*)_v;
  *_p >>= _s;
}
static void _0RL_PetitPrince_mDrawSeq_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::DrawSeq* _p = new PetitPrince::DrawSeq;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_PetitPrince_mDrawSeq_destructor_fn(void* _v)
{
  PetitPrince::DrawSeq* _p = (PetitPrince::DrawSeq*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawSeq& _s)
{
  PetitPrince::DrawSeq* _p = new PetitPrince::DrawSeq(_s);
  _a.PR_insert(_0RL_tc_PetitPrince_mDrawSeq,
               _0RL_PetitPrince_mDrawSeq_marshal_fn,
               _0RL_PetitPrince_mDrawSeq_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, PetitPrince::DrawSeq* _sp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mDrawSeq,
               _0RL_PetitPrince_mDrawSeq_marshal_fn,
               _0RL_PetitPrince_mDrawSeq_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::DrawSeq*& _sp)
{
  return _a >>= (const PetitPrince::DrawSeq*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::DrawSeq*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mDrawSeq,
                    _0RL_PetitPrince_mDrawSeq_unmarshal_fn,
                    _0RL_PetitPrince_mDrawSeq_marshal_fn,
                    _0RL_PetitPrince_mDrawSeq_destructor_fn,
                    _v)) {
    _sp = (const PetitPrince::DrawSeq*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_PetitPrince_mDraw_marshal_fn(cdrStream& _s, void* _v)
{
  PetitPrince::Draw* _p = (PetitPrince::Draw*)_v;
  PetitPrince::Draw::_NP_marshal(_p, _s);
}
static void _0RL_PetitPrince_mDraw_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::Draw* _p = PetitPrince::Draw::_NP_unmarshal(_s);
  _v = _p;
}
static void _0RL_PetitPrince_mDraw_destructor_fn(void* _v)
{
  PetitPrince::Draw* _p = (PetitPrince::Draw*)_v;
  ::CORBA::remove_ref(_p);
}

void operator<<=(::CORBA::Any& _a, PetitPrince::Draw* _v)
{
  ::CORBA::add_ref(_v);
  _a.PR_insert(_0RL_tc_PetitPrince_mDraw,
               _0RL_PetitPrince_mDraw_marshal_fn,
               _0RL_PetitPrince_mDraw_destructor_fn,
               _v);
}
void operator<<=(::CORBA::Any& _a, PetitPrince::Draw** _vp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mDraw,
               _0RL_PetitPrince_mDraw_marshal_fn,
               _0RL_PetitPrince_mDraw_destructor_fn,
               *_vp);
  *_vp = 0;
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Draw*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mDraw,
                    _0RL_PetitPrince_mDraw_unmarshal_fn,
                    _0RL_PetitPrince_mDraw_marshal_fn,
                    _0RL_PetitPrince_mDraw_destructor_fn,
                    _v)) {
    _sp = (PetitPrince::Draw*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_PetitPrince_mLine_marshal_fn(cdrStream& _s, void* _v)
{
  PetitPrince::Line* _p = (PetitPrince::Line*)_v;
  PetitPrince::Line::_NP_marshal(_p, _s);
}
static void _0RL_PetitPrince_mLine_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::Line* _p = PetitPrince::Line::_NP_unmarshal(_s);
  _v = _p;
}
static void _0RL_PetitPrince_mLine_destructor_fn(void* _v)
{
  PetitPrince::Line* _p = (PetitPrince::Line*)_v;
  ::CORBA::remove_ref(_p);
}

void operator<<=(::CORBA::Any& _a, PetitPrince::Line* _v)
{
  ::CORBA::add_ref(_v);
  _a.PR_insert(_0RL_tc_PetitPrince_mLine,
               _0RL_PetitPrince_mLine_marshal_fn,
               _0RL_PetitPrince_mLine_destructor_fn,
               _v);
}
void operator<<=(::CORBA::Any& _a, PetitPrince::Line** _vp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mLine,
               _0RL_PetitPrince_mLine_marshal_fn,
               _0RL_PetitPrince_mLine_destructor_fn,
               *_vp);
  *_vp = 0;
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Line*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mLine,
                    _0RL_PetitPrince_mLine_unmarshal_fn,
                    _0RL_PetitPrince_mLine_marshal_fn,
                    _0RL_PetitPrince_mLine_destructor_fn,
                    _v)) {
    _sp = (PetitPrince::Line*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_PetitPrince_mCercle_marshal_fn(cdrStream& _s, void* _v)
{
  PetitPrince::Cercle* _p = (PetitPrince::Cercle*)_v;
  PetitPrince::Cercle::_NP_marshal(_p, _s);
}
static void _0RL_PetitPrince_mCercle_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::Cercle* _p = PetitPrince::Cercle::_NP_unmarshal(_s);
  _v = _p;
}
static void _0RL_PetitPrince_mCercle_destructor_fn(void* _v)
{
  PetitPrince::Cercle* _p = (PetitPrince::Cercle*)_v;
  ::CORBA::remove_ref(_p);
}

void operator<<=(::CORBA::Any& _a, PetitPrince::Cercle* _v)
{
  ::CORBA::add_ref(_v);
  _a.PR_insert(_0RL_tc_PetitPrince_mCercle,
               _0RL_PetitPrince_mCercle_marshal_fn,
               _0RL_PetitPrince_mCercle_destructor_fn,
               _v);
}
void operator<<=(::CORBA::Any& _a, PetitPrince::Cercle** _vp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mCercle,
               _0RL_PetitPrince_mCercle_marshal_fn,
               _0RL_PetitPrince_mCercle_destructor_fn,
               *_vp);
  *_vp = 0;
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Cercle*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mCercle,
                    _0RL_PetitPrince_mCercle_unmarshal_fn,
                    _0RL_PetitPrince_mCercle_marshal_fn,
                    _0RL_PetitPrince_mCercle_destructor_fn,
                    _v)) {
    _sp = (PetitPrince::Cercle*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_PetitPrince_mEllipses_marshal_fn(cdrStream& _s, void* _v)
{
  PetitPrince::Ellipses* _p = (PetitPrince::Ellipses*)_v;
  PetitPrince::Ellipses::_NP_marshal(_p, _s);
}
static void _0RL_PetitPrince_mEllipses_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::Ellipses* _p = PetitPrince::Ellipses::_NP_unmarshal(_s);
  _v = _p;
}
static void _0RL_PetitPrince_mEllipses_destructor_fn(void* _v)
{
  PetitPrince::Ellipses* _p = (PetitPrince::Ellipses*)_v;
  ::CORBA::remove_ref(_p);
}

void operator<<=(::CORBA::Any& _a, PetitPrince::Ellipses* _v)
{
  ::CORBA::add_ref(_v);
  _a.PR_insert(_0RL_tc_PetitPrince_mEllipses,
               _0RL_PetitPrince_mEllipses_marshal_fn,
               _0RL_PetitPrince_mEllipses_destructor_fn,
               _v);
}
void operator<<=(::CORBA::Any& _a, PetitPrince::Ellipses** _vp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mEllipses,
               _0RL_PetitPrince_mEllipses_marshal_fn,
               _0RL_PetitPrince_mEllipses_destructor_fn,
               *_vp);
  *_vp = 0;
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::Ellipses*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mEllipses,
                    _0RL_PetitPrince_mEllipses_unmarshal_fn,
                    _0RL_PetitPrince_mEllipses_marshal_fn,
                    _0RL_PetitPrince_mEllipses_destructor_fn,
                    _v)) {
    _sp = (PetitPrince::Ellipses*)_v;
    return 1;
  }
  return 0;
}


static void _0RL_PetitPrince_mDrawService_mnon__applicable_marshal_fn(cdrStream& _s, void* _v)
{
  const PetitPrince::DrawService::non_applicable* _p = (const PetitPrince::DrawService::non_applicable*)_v;
  *_p >>= _s;
}
static void _0RL_PetitPrince_mDrawService_mnon__applicable_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::DrawService::non_applicable* _p = new PetitPrince::DrawService::non_applicable;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_PetitPrince_mDrawService_mnon__applicable_destructor_fn(void* _v)
{
  PetitPrince::DrawService::non_applicable* _p = (PetitPrince::DrawService::non_applicable*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::non_applicable& _s)
{
  PetitPrince::DrawService::non_applicable* _p = new PetitPrince::DrawService::non_applicable(_s);
  _a.PR_insert(_0RL_tc_PetitPrince_mDrawService_mnon__applicable,
               _0RL_PetitPrince_mDrawService_mnon__applicable_marshal_fn,
               _0RL_PetitPrince_mDrawService_mnon__applicable_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::non_applicable* _sp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mDrawService_mnon__applicable,
               _0RL_PetitPrince_mDrawService_mnon__applicable_marshal_fn,
               _0RL_PetitPrince_mDrawService_mnon__applicable_destructor_fn,
               (PetitPrince::DrawService::non_applicable*)_sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::DrawService::non_applicable*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mDrawService_mnon__applicable,
                    _0RL_PetitPrince_mDrawService_mnon__applicable_unmarshal_fn,
                    _0RL_PetitPrince_mDrawService_mnon__applicable_marshal_fn,
                    _0RL_PetitPrince_mDrawService_mnon__applicable_destructor_fn,
                    _v)) {
    _sp = (const PetitPrince::DrawService::non_applicable*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_insertToAny__cPetitPrince_mDrawService_mnon__applicable(::CORBA::Any& _a, const ::CORBA::Exception& _e) {
  const PetitPrince::DrawService::non_applicable & _ex = (const PetitPrince::DrawService::non_applicable &) _e;
  operator<<=(_a,_ex);
}

static void _0RL_insertToAnyNCP__cPetitPrince_mDrawService_mnon__applicable (::CORBA::Any& _a, const ::CORBA::Exception* _e) {
  const PetitPrince::DrawService::non_applicable* _ex = (const PetitPrince::DrawService::non_applicable*) _e;
  operator<<=(_a,_ex);
}

class _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_mnon__applicable {
public:
  _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_mnon__applicable() {
    PetitPrince::DrawService::non_applicable::insertToAnyFn = _0RL_insertToAny__cPetitPrince_mDrawService_mnon__applicable;
    PetitPrince::DrawService::non_applicable::insertToAnyFnNCP = _0RL_insertToAnyNCP__cPetitPrince_mDrawService_mnon__applicable;
  }
};
static _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_mnon__applicable _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_mnon__applicable_;


static void _0RL_PetitPrince_mDrawService_munexpected__draw_marshal_fn(cdrStream& _s, void* _v)
{
  const PetitPrince::DrawService::unexpected_draw* _p = (const PetitPrince::DrawService::unexpected_draw*)_v;
  *_p >>= _s;
}
static void _0RL_PetitPrince_mDrawService_munexpected__draw_unmarshal_fn(cdrStream& _s, void*& _v)
{
  PetitPrince::DrawService::unexpected_draw* _p = new PetitPrince::DrawService::unexpected_draw;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_PetitPrince_mDrawService_munexpected__draw_destructor_fn(void* _v)
{
  PetitPrince::DrawService::unexpected_draw* _p = (PetitPrince::DrawService::unexpected_draw*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::unexpected_draw& _s)
{
  PetitPrince::DrawService::unexpected_draw* _p = new PetitPrince::DrawService::unexpected_draw(_s);
  _a.PR_insert(_0RL_tc_PetitPrince_mDrawService_munexpected__draw,
               _0RL_PetitPrince_mDrawService_munexpected__draw_marshal_fn,
               _0RL_PetitPrince_mDrawService_munexpected__draw_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, const PetitPrince::DrawService::unexpected_draw* _sp)
{
  _a.PR_insert(_0RL_tc_PetitPrince_mDrawService_munexpected__draw,
               _0RL_PetitPrince_mDrawService_munexpected__draw_marshal_fn,
               _0RL_PetitPrince_mDrawService_munexpected__draw_destructor_fn,
               (PetitPrince::DrawService::unexpected_draw*)_sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const PetitPrince::DrawService::unexpected_draw*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_PetitPrince_mDrawService_munexpected__draw,
                    _0RL_PetitPrince_mDrawService_munexpected__draw_unmarshal_fn,
                    _0RL_PetitPrince_mDrawService_munexpected__draw_marshal_fn,
                    _0RL_PetitPrince_mDrawService_munexpected__draw_destructor_fn,
                    _v)) {
    _sp = (const PetitPrince::DrawService::unexpected_draw*)_v;
    return 1;
  }
  return 0;
}

static void _0RL_insertToAny__cPetitPrince_mDrawService_munexpected__draw(::CORBA::Any& _a, const ::CORBA::Exception& _e) {
  const PetitPrince::DrawService::unexpected_draw & _ex = (const PetitPrince::DrawService::unexpected_draw &) _e;
  operator<<=(_a,_ex);
}

static void _0RL_insertToAnyNCP__cPetitPrince_mDrawService_munexpected__draw (::CORBA::Any& _a, const ::CORBA::Exception* _e) {
  const PetitPrince::DrawService::unexpected_draw* _ex = (const PetitPrince::DrawService::unexpected_draw*) _e;
  operator<<=(_a,_ex);
}

class _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_munexpected__draw {
public:
  _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_munexpected__draw() {
    PetitPrince::DrawService::unexpected_draw::insertToAnyFn = _0RL_insertToAny__cPetitPrince_mDrawService_munexpected__draw;
    PetitPrince::DrawService::unexpected_draw::insertToAnyFnNCP = _0RL_insertToAnyNCP__cPetitPrince_mDrawService_munexpected__draw;
  }
};
static _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_munexpected__draw _0RL_insertToAny_Singleton__cPetitPrince_mDrawService_munexpected__draw_;

static void _0RL_PetitPrince_mDrawService_marshal_fn(cdrStream& _s, void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  omniObjRef::_marshal(_o, _s);
}
static void _0RL_PetitPrince_mDrawService_unmarshal_fn(cdrStream& _s, void*& _v)
{
  omniObjRef* _o = omniObjRef::_unMarshal(PetitPrince::DrawService::_PD_repoId, _s);
  _v = _o;
}
static void _0RL_PetitPrince_mDrawService_destructor_fn(void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  if (_o)
    omni::releaseObjRef(_o);
}

void operator<<=(::CORBA::Any& _a, PetitPrince::DrawService_ptr _o)
{
  PetitPrince::DrawService_ptr _no = PetitPrince::DrawService::_duplicate(_o);
  _a.PR_insert(PetitPrince::_tc_DrawService,
               _0RL_PetitPrince_mDrawService_marshal_fn,
               _0RL_PetitPrince_mDrawService_destructor_fn,
               _no->_PR_getobj());
}
void operator<<=(::CORBA::Any& _a, PetitPrince::DrawService_ptr* _op)
{
  _a.PR_insert(PetitPrince::_tc_DrawService,
               _0RL_PetitPrince_mDrawService_marshal_fn,
               _0RL_PetitPrince_mDrawService_destructor_fn,
               (*_op)->_PR_getobj());
  *_op = PetitPrince::DrawService::_nil();
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::DrawService_ptr& _o)
{
  void* _v;
  if (_a.PR_extract(PetitPrince::_tc_DrawService,
                    _0RL_PetitPrince_mDrawService_unmarshal_fn,
                    _0RL_PetitPrince_mDrawService_marshal_fn,
                    _0RL_PetitPrince_mDrawService_destructor_fn,
                    _v)) {
    omniObjRef* _r = (omniObjRef*)_v;
    if (_r)
      _o = (PetitPrince::DrawService_ptr)_r->_ptrToObjRef(PetitPrince::DrawService::_PD_repoId);
    else
      _o = PetitPrince::DrawService::_nil();
    return 1;
  }
  return 0;
}

static void _0RL_PetitPrince_mPetitPrinceService_marshal_fn(cdrStream& _s, void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  omniObjRef::_marshal(_o, _s);
}
static void _0RL_PetitPrince_mPetitPrinceService_unmarshal_fn(cdrStream& _s, void*& _v)
{
  omniObjRef* _o = omniObjRef::_unMarshal(PetitPrince::PetitPrinceService::_PD_repoId, _s);
  _v = _o;
}
static void _0RL_PetitPrince_mPetitPrinceService_destructor_fn(void* _v)
{
  omniObjRef* _o = (omniObjRef*)_v;
  if (_o)
    omni::releaseObjRef(_o);
}

void operator<<=(::CORBA::Any& _a, PetitPrince::PetitPrinceService_ptr _o)
{
  PetitPrince::PetitPrinceService_ptr _no = PetitPrince::PetitPrinceService::_duplicate(_o);
  _a.PR_insert(PetitPrince::_tc_PetitPrinceService,
               _0RL_PetitPrince_mPetitPrinceService_marshal_fn,
               _0RL_PetitPrince_mPetitPrinceService_destructor_fn,
               _no->_PR_getobj());
}
void operator<<=(::CORBA::Any& _a, PetitPrince::PetitPrinceService_ptr* _op)
{
  _a.PR_insert(PetitPrince::_tc_PetitPrinceService,
               _0RL_PetitPrince_mPetitPrinceService_marshal_fn,
               _0RL_PetitPrince_mPetitPrinceService_destructor_fn,
               (*_op)->_PR_getobj());
  *_op = PetitPrince::PetitPrinceService::_nil();
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, PetitPrince::PetitPrinceService_ptr& _o)
{
  void* _v;
  if (_a.PR_extract(PetitPrince::_tc_PetitPrinceService,
                    _0RL_PetitPrince_mPetitPrinceService_unmarshal_fn,
                    _0RL_PetitPrince_mPetitPrinceService_marshal_fn,
                    _0RL_PetitPrince_mPetitPrinceService_destructor_fn,
                    _v)) {
    omniObjRef* _r = (omniObjRef*)_v;
    if (_r)
      _o = (PetitPrince::PetitPrinceService_ptr)_r->_ptrToObjRef(PetitPrince::PetitPrinceService::_PD_repoId);
    else
      _o = PetitPrince::PetitPrinceService::_nil();
    return 1;
  }
  return 0;
}

