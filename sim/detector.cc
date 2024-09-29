#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist) 
{
      G4Track *track  = aStep->GetTrack();
      
      track->SetTrackStatus(fStopAndKill); 
      //as soon as photon enters detector it is killed and does not go any further
      
      
      G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
      G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
      //in the case of the photon, this gives info on the photon when it leaves the sensitive detector (for charged particles is more complicated) 
      
      G4ThreeVector posPhoton = preStepPoint->GetPosition();
      
      //G4cout << "Photon position:" << posPhoton << G4endl;
      //this finds photon position but in the lab we do not have it, we have access to detector position
      
      const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
      
      G4int copyNo = touchable->GetCopyNumber();
      
      G4cout << "Copy number: " << copyNo << G4endl;
      
      G4VPhysicalVolume *physVol = touchable->GetVolume();
      G4ThreeVector posDetector = physVol->GetTranslation(); 
      
      G4cout << "Detector position: " << posDetector << G4endl;
      
      G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID(); 
      
      //we store photon information
      G4AnalysisManager *man = G4AnalysisManager::Instance();
      man->FillNtupleIColumn(0, evt); //event number
      man->FillNtupleDColumn(1, posDetector[0]);
      man->FillNtupleDColumn(2, posDetector[1]);
      man->FillNtupleDColumn(3, posDetector[2]);
      man->AddNtupleRow(0); 
      //D is for double  
      
      return true;
      
} 









