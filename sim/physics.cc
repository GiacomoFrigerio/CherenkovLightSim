#include "physics.hh" 

MyPhysicsList::MyPhysicsList()
{
  RegisterPhysics (new G4EmStandardPhysics());
  //we are now dealing with EM interaction (not hadrons for now)
  // it is better to avoid complicated physics if not necessary
  RegisterPhysics (new G4OpticalPhysics());
  //optical photons (if not, no light available)
  
  
  
}

MyPhysicsList::~MyPhysicsList()
{} 






