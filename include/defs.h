// -*- C++ -*-
// $Id: defs.h,v 1.4 2002-11-04 04:34:02 edwards Exp $

/*! \file
 * \brief Type definitions
 */

QDP_BEGIN_NAMESPACE(QDP);

/*! \addtogroup defs Type definitions
 *
 * User constructed types made from QDP type compositional nesting.
 * The layout is suitable for a scalar-like implementation. Namely,
 * sites are the slowest varying index.
 *
 * @{
 */

// These are fixed precision versions
#define INTEGER32 int
#define REAL32    float
#define REAL64    double
#define LOGICAL   bool

// These are floating precision versions
#define REAL      REAL32
#define DOUBLE    REAL64

//! Gamma matrices are conveniently defined for this Ns
typedef GammaType<Ns> Gamma;

// Aliases for a scalar architecture
typedef OLattice< PScalar< PColorMatrix< RComplex<REAL>, Nc> > > LatticeGauge;
typedef OLattice< PSpinVector< PColorVector< RComplex<REAL>, Nc>, Ns> > LatticeFermion;
typedef OLattice< PSpinVector< PColorVector< RComplex<REAL>, Nc>, Ns>>1 > > LatticeHalfFermion;
typedef OLattice< PSpinMatrix< PColorMatrix< RComplex<REAL>, Nc>, Ns> > LatticePropagator;
typedef OLattice< PScalar< PColorMatrix< RComplex<REAL>, Nc> > > LatticeColorMatrix;
typedef OLattice< PSpinMatrix< PScalar< RComplex<REAL> >, Ns> > LatticeSpinMatrix;
typedef OLattice< PScalar< PScalar< RComplex<REAL> > > > LatticeComplex;

typedef OLattice< PScalar< PSeed < RScalar<INTEGER32> > > > LatticeSeed;
typedef OLattice< PScalar< PScalar< RScalar<INTEGER32> > > > LatticeInteger;
typedef OLattice< PScalar< PScalar< RScalar<REAL> > > > LatticeReal;
typedef OLattice< PScalar< PScalar< RScalar<DOUBLE> > > > LatticeDouble;
typedef OLattice< PScalar< PScalar< RScalar<LOGICAL> > > > LatticeBoolean;

typedef OScalar< PScalar< PColorMatrix< RComplex<REAL>, Nc> > > Gauge;
typedef OScalar< PSpinVector< PColorVector< RComplex<REAL>, Nc>, Ns> > Fermion;
typedef OScalar< PSpinMatrix< PColorMatrix< RComplex<REAL>, Nc>, Ns> > Propagator;
typedef OScalar< PScalar< PScalar< RComplex<REAL> > > > Complex;

typedef OScalar< PScalar< PSeed< RScalar<INTEGER32> > > > Seed;
typedef OScalar< PScalar< PScalar< RScalar<INTEGER32> > > > Integer;
typedef OScalar< PScalar< PScalar< RScalar<REAL> > > > Real;
typedef OScalar< PScalar< PScalar< RScalar<DOUBLE> > > > Double;
typedef OScalar< PScalar< PScalar< RScalar<LOGICAL> > > > Boolean;

typedef OScalar< PScalar< PScalar< RComplex<DOUBLE> > > > DComplex;


// Duplicate names
typedef OScalar< PScalar< PColorMatrix< RComplex<REAL>, Nc> > > ColorMatrix;
typedef OScalar< PScalar< PColorVector< RComplex<REAL>, Nc> > > ColorVector;
typedef OScalar< PSpinMatrix< PScalar< RComplex<REAL> >, Ns> > SpinMatrix;
typedef OScalar< PSpinVector< PScalar< RComplex<REAL> >, Ns> > SpinVector;
typedef OScalar< PSpinVector< PColorVector< RComplex<REAL>, Nc>, Ns> > ColorVectorSpinVector;
typedef OScalar< PSpinMatrix< PColorMatrix< RComplex<REAL>, Nc>, Ns> > ColorMatrixSpinMatrix;

// Level below outer for internal convenience
typedef PScalar< PScalar< RScalar<REAL> > > IntReal;
typedef PScalar< PScalar< RScalar<INTEGER32> > > IntInteger;
typedef PScalar< PScalar< RScalar<DOUBLE> > > IntDouble;
typedef PScalar< PScalar< RScalar<LOGICAL> > > IntBoolean;

// Fixed precision
typedef OLattice< PScalar< PColorMatrix< RComplex<REAL32>, Nc> > > LatticeColorMatrix32;
typedef OScalar< PScalar< PScalar< RScalar<REAL32> > > > Real32;

/*! @} */   // end of group defs

QDP_END_NAMESPACE();

