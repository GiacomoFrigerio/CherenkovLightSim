# CherenkovLightSim
Cherenkov Light simulation in Geant4 with different materials and particles. 



Cherenkov Light simulation in Geant4 with different architectures of the solid Radiator (wall which interact with charged particle to produce photons).

Geant4 Version = 11.1

Materials used: Water (n=1.3), Aerogel(n=1.1), Low Density Aerogel(n=1.05), High Density Aerogel(n=1.2), Soda Lime Glass(n=1.4).

Particles used: proton (proton), electron (e-) 

Output is saved on a Root file with Event, fX, fY, fZ and fX:fY to reconstruct the radius of the Cherenkov cone. 

The results expected are that if the material (![Materials](https://github.com/user-attachments/assets/94079443-61f1-4775-9215-812e75701d31)
) has an increasing refractive index, the Cherenkov cone should increase its radius (![Results(visual)](https://github.com/user-attachments/assets/eb2a760b-62e5-45d9-b50a-5c35ddfbe55b) ![Results(plot)](https://github.com/user-attachments/assets/d5df0cf0-875e-4c07-932d-630497b9a92f)).

To start the code, download the files and create a build folder.
Then, inside the folder, do "cmake .." , then "make" and then "./NAME" where NAME is the folder of the code (in this case, sim).

The output is saved on a ROOT file. 


Project bibliography: https://www.youtube.com/playlist?list=PLLybgCU6QCGWgzNYOV0SKen9vqg4KXeVL . 
