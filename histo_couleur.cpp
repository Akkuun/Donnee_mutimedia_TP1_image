#include <stdio.h>
#include "image_ppm.h"
#include<iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{

  char cNomImgLue[250]; // input du fichier .ppm
  int nH, nW, nTaille,valeur_actuelle_gris, nR,nG,nB;

//int iteration[255]; // tableau qui va contenir tout les itération des valeurs de gris
std::vector<int> iterationRed;
std::vector<int> iterationGreen;
std::vector<int> iterationBlue;


FILE *histoR;
histoR =  fopen("histoR.dat","wb");
FILE *histoG;
histoG =  fopen("histoG.dat","wb");
FILE *histoB;
histoB =  fopen("histoB.dat","wb");

//on rempli notre tableau de 0
for (int i = 0; i < 256; i++){
       
        iterationRed.push_back(0);
         iterationGreen.push_back(0);
 iterationBlue.push_back(0);   
    
}

  if (argc != 2) 
     {
       printf("Usage: ImageIn.pgm \n"); 
       exit (1) ;
     }
     
   sscanf (argv[1],"%s",cNomImgLue) ; //  association avec varaibles

   OCTET *ImgIn, *ImgOut; // tableau d'octet contenant les couleurs de chaque pixel
   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
    nTaille = nH * nW;

  
  
   allocation_tableau(ImgIn, OCTET, nTaille *3 );// calcul qui permet de représenter les différents pixel de l'imag dans un tableau 1D  de taille *3 pour chacune des composantes



     // ex  0 1 2
       //     3 4 5  ==> 1 2 3 4 5 6 7 8 
       //     6 7 8 


   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
  


 //fprintf(histo,"%d,\n", ImgIn[i*nW+j]);

    for (int i=0; i < nTaille*3; i+=3){ // on parcours tout les pixel

        nR = ImgIn[i]; //valeur de rouge
        nG = ImgIn[i+1]; // vlaeur de vert
        nB = ImgIn[i+2]; // valeur de bleu
        iterationRed.at(nR) =  iterationRed.at(nR) +1 ;
        iterationGreen.at(nG) =  iterationGreen.at(nG) +1 ;
        iterationBlue.at(nB) =  iterationBlue.at(nB) +1 ;


    }





for (int i=0; i < 256; i+=1) // parcours de chaque vecteur iteration
     {
       nR = ImgIn[i];
       nG = ImgIn[i+1];
       nB = ImgIn[i+2];
       fprintf(histoR,"%d,\n",iterationRed.at(i)); 
       fprintf(histoG,"%d,\n",iterationGreen.at(i)); 
       fprintf(histoB,"%d,\n",iterationBlue.at(i)); 
 
     }



   free(ImgIn); free(ImgOut);
   return 1;
}
