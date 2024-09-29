#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh" 

#include "construction.hh" 
#include "physics.hh"
#include "action.hh"



int main(int argc, char** argv)
{ 
   G4RunManager *runManager = new G4RunManager();
   
   //we don't want to build everytime the geometry graphics to save memory (expecially when we modify macrofile)
   
   
   runManager->SetUserInitialization(new MyDetectorConstruction()); 
   runManager->SetUserInitialization(new MyPhysicsList());
   runManager->SetUserInitialization(new MyActionInitialization());
   
   runManager->Initialize();
   
//   G4UIExecutive *ui = new G4UIExecutive(argc, argv);
   G4UIExecutive *ui = 0;
   
   if(argc == 1) //we use the run manager only if argc = 1
   {
      ui = new G4UIExecutive(argc, argv);
   }
   
   G4VisManager *visManager = new G4VisExecutive();
   visManager->Initialize();
   
   G4UImanager *UImanager = G4UImanager::GetUIpointer();
   
   if(ui)
   {
   
   //Now this command will be implemented in the Macro, so there is no need to keep them
   //UImanager->ApplyCommand("/vis/open OGL");
   //this is needed to visualize it
   //UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
   //changes initial position (where it is looked)
   //UImanager->ApplyCommand("/vis/drawVolume");
   //UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
   //UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
   //to visualize beam
   //UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");
   
   //Macro input -> we need to say it has to load info above and execute them
   
      UImanager->ApplyCommand("/control/execute vis.mac");
      ui->SessionStart();
   }
   else
   {
      G4String command= "/control/execute"; 
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);  
   }

   return 0;
} 
 
