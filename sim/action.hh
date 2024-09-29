#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"

#include "generator.hh"
#include "run.hh" 

class MyActionInitialization : public G4VUserActionInitialization
{
public:
     MyActionInitialization();
     ~MyActionInitialization();
     
     virtual void Build() const;
     //this is the main function of the program that runs particles
};






#endif
