// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4GaussHermiteQ.hh,v 2.0 1998/07/02 17:31:47 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
// Roots of ortogonal polynoms and corresponding weights are calculated based on
// iteration method (by bisection Newton algorithm). Constant values for initial
// approximations were derived from the book: M. Abramowitz, I. Stegun, Handbook
// of mathematical functions, DOVER Publications INC, New York 1965 ; chapters 9,
// 10, and 22 .
//
// --------------------------------------------------------------------------
//
// Constructor for Gauss-Hermite quadrature method . The function GaussHermite
// should be called then
//
// G4GaussHermiteQ( function pFunction, G4int nHermite  ) 
//
// ----------------------------------------------------------------------------
//
// Gauss-Hermite method for integration of exp(-x*x)*nFunction(x) from minus infinity
// to plus infinity .
//
// G4double Integral() const 
//
//
// ------------------------------- HISTORY -------------------------------------
//
// 13.05.97 V.Grichine (Vladimir.Grichine@cern.chz0

#ifndef G4GAUSSHERMITEQ_HH
#define G4GAUSSHERMITEQ_HH

#include "G4VGaussianQuadrature.hh"

class G4GaussHermiteQ : public G4VGaussianQuadrature
{
public:
        // Constructor

        G4GaussHermiteQ( function pFunction, G4int nHermite  ) ;
			       
        // Methods
			     
        G4double Integral() const ;


protected:

private:

} ;


#endif