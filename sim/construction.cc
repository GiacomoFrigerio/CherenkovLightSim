#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
        //we define the material for the detector 
        G4NistManager *nist = G4NistManager::Instance();
        //we use the manager to use values of already known materials
        
        
        
        
        //Detector Structure
        
        //Silica
        G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3 , 2);
        SiO2->AddElement(nist->FindOrBuildElement("Si"), 1); 
        SiO2->AddElement(nist->FindOrBuildElement("O"), 2);
        //Silica -> Material takes Material, Density, Number of components (silicon dioxide) 
        
        //Sodium Oxide
        G4Material *Na2O = new G4Material("Na2O", 2.49*g/cm3, 2);
        Na2O->AddElement(nist->FindOrBuildElement("Na"), 2);
        Na2O->AddElement(nist->FindOrBuildElement("O"), 1);
        
        //Calcium Oxide
        G4Material *CaO = new G4Material("CaO", 3.34*g/cm3, 2);
        CaO->AddElement(nist->FindOrBuildElement("Ca"), 1);
        CaO->AddElement(nist->FindOrBuildElement("O"), 1);
        
        //Water
        G4Material *H2O = new G4Material("H20", 1.000*g/cm3 , 2);
        H2O->AddElement(nist->FindOrBuildElement("H"), 2); 
        H2O->AddElement(nist->FindOrBuildElement("O"), 1);
        
        //Carbonium
        G4Element *C = nist->FindOrBuildElement("C");
        
        
        //Aerogel
        G4Material *Aerogel = new G4Material("Aerogel", 0.200*g/cm3 , 3);
        Aerogel->AddMaterial(SiO2, 62.5*perCent);
        Aerogel->AddMaterial(H2O, 37.4*perCent);
        Aerogel->AddElement(C, 0.1*perCent);
        //we add material and percentage   
        
        //AerogelLD
        G4Material *AerogelLD = new G4Material("AerogelLD", 0.160*g/cm3 , 3);
        AerogelLD->AddMaterial(SiO2, 52.5*perCent);
        AerogelLD->AddMaterial(H2O, 47.4*perCent);
        AerogelLD->AddElement(C, 0.1*perCent);
        //we add material and percentage 
        
        //AerogelHD
        G4Material *AerogelHD = new G4Material("AerogelHD", 0.160*g/cm3 , 3);
        AerogelHD->AddMaterial(SiO2, 72.5*perCent);
        AerogelHD->AddMaterial(H2O, 27.4*perCent);
        AerogelHD->AddElement(C, 0.1*perCent);
        //we add material and percentage 
        
        //Water
        G4Material *Water = new G4Material("Water", 1*g/cm3, 1);
        Water->AddMaterial(H2O, 100*perCent);
        
        //Soda-Lime Glass
        G4Material *SLGlass = new G4Material("SLGlass", 2.52*g/cm3, 3);
        SLGlass->AddMaterial(SiO2, 74*perCent);
        SLGlass->AddMaterial(Na2O, 13*perCent);
        SLGlass->AddMaterial(CaO, 13*perCent);
        
        
        
        //we add momentum
        G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2  };
        //we are trying to find the mom (energy) of photon
        //we are dealing with blue and red light so we use 0.2 nm (lenght) and 0.9 nm (lenght) to convert 
        
        //we define reflective index of aerogel (choosing no dispersion)
        G4double rindexWorld[2] = {1.0, 1.0};
        G4double rindexAerogelLD[2] = {1.05, 1.05};
        G4double rindexAerogel[2] = {1.1, 1.1};  
        G4double rindexAerogelHD[2] = {1.2, 1.2};
        G4double rindexWater[2] = {1.3 , 1.3};
        G4double rindexSLGlass[2] = {1.4,1.4};
        
        
        
        G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable(); 
        mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2); 
        Aerogel->SetMaterialPropertiesTable(mptAerogel); 
        //we add material prop we defined
        
        G4MaterialPropertiesTable *mptAerogelLD = new G4MaterialPropertiesTable(); 
        mptAerogelLD->AddProperty("RINDEX", energy, rindexAerogelLD, 2); 
        AerogelLD->SetMaterialPropertiesTable(mptAerogelLD); 
        
        G4MaterialPropertiesTable *mptAerogelHD = new G4MaterialPropertiesTable(); 
        mptAerogelHD->AddProperty("RINDEX", energy, rindexAerogelHD, 2); 
        AerogelHD->SetMaterialPropertiesTable(mptAerogelHD); 

        G4MaterialPropertiesTable *mptWater = new G4MaterialPropertiesTable();
        mptWater->AddProperty("RINDEX", energy, rindexWater, 2);
        Water->SetMaterialPropertiesTable(mptWater);
        
        G4MaterialPropertiesTable *mptSLGlass = new G4MaterialPropertiesTable();
        mptSLGlass->AddProperty("RINDEX", energy, rindexSLGlass, 2);
        SLGlass->SetMaterialPropertiesTable(mptSLGlass);
        
        
        G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
        //searches the material for the world volume (worldmat) that contains air (it is our boundary and we must define it)
        
        G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
        mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2); 
        worldMat->SetMaterialPropertiesTable(mptWorld); 
        
        
        
        
        
        
        
        G4Box *solidWorld = new G4Box("solidWorld", 0.5*m , 0.5*m, 0.5*m);
        //remember these are half sizes (we obtain 1 meter) 
        
        G4LogicalVolume *logicWorld = new G4LogicalVolume (solidWorld, worldMat, "logicWorld");
        //first parameter is the solid volume, the next is world material and the last is the name
        
        G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0. , 0. , 0.), logicWorld, "physWorld", 0, false , 0, true);
        //1st is rotation, 2nd center of cood system,3rd is the logic volume, 4th the name, 5th if it must be set in another mother volume , 6th boolean op, 7th copy number and 8th is the question if should check for overlaps (which is bad) and gives you warning message
        
        G4Box *solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m);
        //it has to be smaller than world volume
        
        //we define logical volume
        G4LogicalVolume *logicRadiator = new G4LogicalVolume(solidRadiator, Water, "logicalRadiator"); //former Aerogel
        
        //we define physical volume
        G4VPhysicalVolume *physRadiator = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);  
        
        
        
        
        
        
        
        //we want to add photosensors (to detect pos of photons)
        G4Box *solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m, 0.01*m); 
        
        logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector"); 
        
        for(G4int i=0; i < 100; i++)
        {
          for(G4int j=0; j<100; j++) 
          {
              G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/100, -0.5*m+(j+0.5)*m/100, 0.49*m), logicDetector, "physDetector", logicWorld, false, j+i*100, true);
          }
        }
        
        
        
        
        
        
        return physWorld;
        
        
         
        
        
        
} 


void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector"); 
  
  logicDetector->SetSensitiveDetector(sensDet); 
  
  
  
}



