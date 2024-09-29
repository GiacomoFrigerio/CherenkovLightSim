#ifndef RUN_HH
#define RUN_HH


#include "G4UserRunAction.hh"
#include "G4Run.hh"

//#include "g4root.hh"
//this class includes the G4AnalysisManager but does not function

#include "G4AnalysisManager.hh" 

class MyRunAction : public G4UserRunAction
{
public: 
      MyRunAction();
      ~MyRunAction();
      
      virtual void BeginOfRunAction(const G4Run*);
      virtual void EndOfRunAction(const G4Run* );  
 
};















#endif
