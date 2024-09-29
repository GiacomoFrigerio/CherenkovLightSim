#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh" 
//this is useful to implement dimension

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"

#include "detector.hh"


class MyDetectorConstruction : public G4VUserDetectorConstruction 
{
public: 
        MyDetectorConstruction(); 
        //Constructor
        ~MyDetectorConstruction(); 
        //Destructor
        
        virtual G4VPhysicalVolume *Construct();
        //main function that construct the geometry of the detector. 
        
private:
     G4LogicalVolume *logicDetector; 
     virtual void ConstructSDandField(); 
                 
};

#endif



