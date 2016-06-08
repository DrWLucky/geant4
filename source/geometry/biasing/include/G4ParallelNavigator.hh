//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4ParallelNavigator.hh,v 1.3 2002/04/10 13:13:06 dressel Exp $
// GEANT4 tag $Name: geant4-04-01 $
//
// ----------------------------------------------------------------------
// Class G4ParallelNavigator
//
// Class description:
//
// Used internaly for importance sampling and scoring in a "parallel"
// geometry. 
// It implements the interface G4VPGeoDriver (see G4VPGeoDriver.hh).
// It uses a G4Navigator.

// Author: Michael Dressel (Michael.Dressel@cern.ch)
// ----------------------------------------------------------------------
#ifndef G4ParallelNavigator_hh
#define G4ParallelNavigator_hh G4ParallelNavigator_hh

#include "G4VPGeoDriver.hh"
#include "geomdefs.hh"

class G4VTouchable;
class G4Navigator;
class G4PTouchableKey ;
class G4VPhysicalVolume;

class G4ParallelNavigator : public G4VPGeoDriver
{

public:  // with description

  G4ParallelNavigator(G4VPhysicalVolume &aWorldVolume);
    // initialise and create G4Navigator and a TouchableHistory

  ~G4ParallelNavigator();
    // delete Touchable and Navigator

  G4PTouchableKey LocateOnBoundary(const G4ThreeVector &aPosition, 
		                   const G4ThreeVector &aDirection);
    // The location of a track according to it's position
    // and direction in case the track crosses a boundary
    // of a "parallel" geometry.
    // Must be called in the PostDOIT of the ParallelTransportation.
    // (The track crosses the boundary if PostDOIT gets called.)
  

  G4PTouchableKey GetCurrentTouchableKey() const;
    // get the current G4PTouchableKey of the "parallel" geometry

  G4double ComputeStepLengthInit(const G4ThreeVector &aPosition, 
				 const G4ThreeVector &aDirection);
    // compute step length for a starting track. 
  
  G4double ComputeStepLengthCrossBoundary(const G4ThreeVector &aPosition, 
					  const G4ThreeVector &aDirection);
    // compute the step length after a track crossed a boundary
    // in a "parallel" geometry
  
  G4double ComputeStepLengthInVolume(const G4ThreeVector &aPosition, 
				     const G4ThreeVector &aDirection);
    // compute step length when track moves inside a volume.  
  
private:

  G4ParallelNavigator(const G4ParallelNavigator &);
  G4ParallelNavigator &operator=(const G4ParallelNavigator &);

  G4double ComputeStepLengthShifted(const G4String &m,
				    const G4ThreeVector &aPosition, 
				    const G4ThreeVector &aDirection);

  void Locate(const G4ThreeVector &aPosition, 
	      const G4ThreeVector &aDirection,
	      G4bool histsearch); 
			
  void Error(const G4String &m,
             const G4ThreeVector &pos,
             const G4ThreeVector &dir);

  G4double Shift(G4double d);

private:
  
  G4Navigator &fNavigator;
  G4VTouchable *fCurrentTouchable;
  G4int fNlocated;
};

#endif












