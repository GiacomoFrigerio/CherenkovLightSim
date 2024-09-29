//we have to say to Geant4 the physics of the system (create particle and tell how they interact) 

#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh" 

class MyPhysicsList : public G4VModularPhysicsList
{
public:
    MyPhysicsList();
    ~MyPhysicsList();
};





#endif
