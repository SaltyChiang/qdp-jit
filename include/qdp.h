// -*- C++ -*-
// $Id: qdp.h,v 1.23 2003-08-05 21:14:34 edwards Exp $

/*! \file
 * \brief Primary include file for QDP
 *
 * No other file should be included by the user
 */

/*! \mainpage  QDP
 *
 * \section Description
 *
 * QDP is a C++ data-parallel interface for Lattice field theory.
 * The QDP interface provides an environment somewhat similar to 
 * Fortran 90 - namely data-parallel operations (operator/infix form)
 * which can be applied on lattice wide objects. The interface provides a
 * level of abstraction such that high-level user code written using the
 * API can be run unchanged on a single processor workstation or a
 * collection of multiprocessor nodes with parallel communications.
 * Architectural dependencies are hidden below the interface. A variety
 * of types for the site elements are provided. To achieve good
 * performance, overlapping communication and computation primitives are
 * provided.
 */

/*! \namespace QDP
 * \brief Primary namespace holding all QDP types, operations and objects
 */

#ifndef QDP_INCLUDE
#define QDP_INCLUDE

#if defined(__GNUC__)
// Under g++, enforce using V3 or greater
#if __GNUC__ < 3
#error "QDP++ requires g++ 3.0 or higher. This version of the g++ compiler is not supported"
#endif
#endif

// Under gcc, set some attributes
#if defined(__GNUC__)
#define QDP_ALIGN8   __attribute__ ((aligned (8)))
#define QDP_ALIGN16  __attribute__ ((aligned (16)))
#define QDP_INLINE   __attribute__ ((always_inline))
#define QDP_CONST    __attribute__ ((const))
#define QDP_CINLINE  __attribute__ ((always_inline,const))
#endif


#include <cstdio>
#include <cstdlib>
#include <ostream>
#include <iostream>

/* Get local configuration options (ARCH_SCALAR/PARSCALAR, Nd, Nc, Ns) */
#include <qdp_config.h>

using namespace std;   // I do not like this

using std::iostream;
using std::ostream;

// Move to another file eventually
#define FORWARD 1
#define BACKWARD -1


#undef QDP_NO_NAMESPACE

#if defined(QDP_NO_NAMESPACE)
#define QDP_BEGIN_NAMESPACE(a)
#define QDP_END_NAMESPACE()

#else // ! defined(QDP_NO_NAMESPACE)
#define QDP_BEGIN_NAMESPACE(a) namespace a {
#define QDP_END_NAMESPACE(a) };
#endif

// Basic includes
QDP_BEGIN_NAMESPACE(QDP);
#define PETE_USER_DEFINED_EXPRESSION
#include <PETE/PETE.h>
QDP_END_NAMESPACE();

#include "qdp_init.h"
#include "qdp_forward.h"
#include "qdp_multi.h"

#include "qdp_params.h"
#include "qdp_layout.h"
#include "qdp_filebuf.h"
#include "qdp_io.h"
#include "qdp_xmlio.h"
#include "qdp_qdpio.h"
#include "qdp_subset.h"
#include "qdp_map.h"

#include "qdp_traits.h"
#include "qdp_qdpexpr.h"
#include "qdp_qdptype.h"
#include "qdp_qdpsubtype.h"

QDP_BEGIN_NAMESPACE(QDP);
#include "QDPOperators.h"
QDP_END_NAMESPACE();

#include "qdp_newops.h"
//#include "qdp_word.h"
#include "qdp_simpleword.h"
#include "qdp_reality.h"
//#include "qdp_inner.h"
#include "qdp_primitive.h"
#include "qdp_outer.h"
#include "qdp_outersubtype.h"
#include "qdp_defs.h"
#include "qdp_globalfuncs.h"
#include "qdp_specializations.h"

//#include "qdp_special.h"
#include "qdp_random.h"

#if defined(ARCH_SCALAR)
// Architectural specific code to a single node/single proc box
#warning "Using scalar architecture"
#include "qdp_scalar_specific.h"

#elif defined(ARCH_PARSCALAR)
// Architectural specific code to a parallel/single proc box
#warning "Using parallel scalar architecture"
#include "qdp_parscalar_specific.h"

#else
#error "Unknown architecture ARCH"
#endif


#endif  // QDP_INCLUDE
