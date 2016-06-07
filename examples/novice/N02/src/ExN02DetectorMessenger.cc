// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ExN02DetectorMessenger.cc,v 1.4 1998/10/09 14:35:32 japost Exp $
// GEANT4 tag $Name: geant4-00 $
//
// 

#include "ExN02DetectorMessenger.hh"

#include "ExN02DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "globals.hh"

ExN02DetectorMessenger::ExN02DetectorMessenger(ExN02DetectorConstruction * myDet)
:myDetector(myDet)
{ 

  mydetDir = new G4UIdirectory("/mydet/");
  mydetDir->SetGuidance("ExN02 detector control.");
  
  MatCmd = new G4UIcmdWithAString("/mydet/setMaterial",this);
  MatCmd->SetGuidance("Select Material of the SimpleBox.");
  MatCmd->SetGuidance("  Choice : Air, Al(default), Pb, Vacuum");
  MatCmd->SetParameterName("choice",true);
  MatCmd->SetDefaultValue("Al");
  MatCmd->SetCandidates("Air Al Pb Vacuum");
  MatCmd->AvailableForStates(PreInit,Idle);
  
  SizeCmd = new G4UIcmdWithADoubleAndUnit("/mydet/setSize",this);
  SizeCmd->SetGuidance("Set full Size of the Box");
  SizeCmd->SetParameterName("Size",false,false);
  SizeCmd->SetDefaultUnit("cm");
  SizeCmd->SetUnitCategory("Length");
  SizeCmd->AvailableForStates(PreInit,Idle);
  
  FieldCmd = new G4UIcmdWithADoubleAndUnit("/mydet/setField",this);  
  FieldCmd->SetGuidance("Define magnetic field.");
  FieldCmd->SetGuidance("Magnetic field will be in Z direction.");
  FieldCmd->SetParameterName("Bz",false,false);
  FieldCmd->SetDefaultUnit("tesla");
  FieldCmd->SetUnitCategory("Magnetic flux density");
  FieldCmd->AvailableForStates(PreInit,Idle);  
}

ExN02DetectorMessenger::~ExN02DetectorMessenger()
{
  delete MatCmd;
  delete SizeCmd;
  delete FieldCmd;
  delete mydetDir;
}

void ExN02DetectorMessenger::SetNewValue(G4UIcommand * command,G4String newValues)
{ 
  // if( command == MatCmd )
  //   { myDetector->setMaterial(newValues);}
  
  if( command == SizeCmd )
   { myDetector->SetDetectorLength(SizeCmd->GetNewDoubleValue(newValues));}
  
  if( command == FieldCmd )
   { myDetector->SetMagField(FieldCmd->GetNewDoubleValue(newValues));}
}
