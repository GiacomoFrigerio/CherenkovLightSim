#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{

    fParticleGun = new G4ParticleGun(1);
    //we insert the number of particle for event
    //event -> 1 particle  ... several events form a run
    
    
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable(); 
    //the information of particles is stored in this table
    
    G4String particleName="proton"; //proton(proton) e-(electron)
    G4ParticleDefinition *particle = particleTable->FindParticle("proton"); //proton(proton) e-(electron)
    //finds particle prop
    
    G4ThreeVector pos(0.,0.,0.); 
    //Created in center of volume
    G4ThreeVector mom(0.,0.,1.); 
    //direction of momentum (we choose z dir)
    
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(100.*GeV); //standard 100 GeV
    fParticleGun->SetParticleDefinition(particle);
    
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;

}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent) 
{
//we inserted all info of particle in the method but we can put theme in the constructor (useful so do not overwrite after macro)
//    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable(); 
//    //the information of particles is stored in this table
//    
//    G4String particleName="proton";
//    G4ParticleDefinition *particle = particleTable->FindParticle("proton");
//    //finds particle prop
//    
//    G4ThreeVector pos(0.,0.,0.); 
//    //Created in center of volume
//    G4ThreeVector mom(0.,0.,1.); 
//    //direction of momentum (we choose z dir)
//    
//    fParticleGun->SetParticlePosition(pos);
//    fParticleGun->SetParticleMomentumDirection(mom);
//    fParticleGun->SetParticleMomentum(100.*GeV);
//    fParticleGun->SetParticleDefinition(particle);
//    
    fParticleGun->GeneratePrimaryVertex(anEvent);
}















