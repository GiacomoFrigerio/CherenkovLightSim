# CherenkovLightSim
Cherenkov Light simulation in Geant4 with different materials and particles. 



Cherenkov Light simulation in Geant4 with different architectures of the solid Radiator (wall which interact with charged particle to produce photons).

Geant4 Version = 11.1

Materials used: Water (n=1.3), Aerogel(n=1.1), Low Density Aerogel(n=1.05), High Density Aerogel(n=1.2), Soda Lime Glass(n=1.4).

Particles used: proton (proton), electron (e-) 

Output is saved on a Root file with Event, fX, fY, fZ and fX:fY to reconstruct the radius of the Cherenkov cone. 

The results expected are that if the material has an increasing refractive index, the Cherenkov cone should increase its radius.

To start the code, download the files and create a build folder.
Then, inside the folder, do "cmake .." , then "make" and then "./NAME" where NAME is the folder of the code (in this case, sim).

The output is saved on a ROOT file. 


Project bibliography: https://www.youtube.com/playlist?list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL . 
