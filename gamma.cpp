// test_couleur.cpp : Seuille une image couleur 

#include <stdio.h>
#include <math.h>
#include "image_ppm.h"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;
  float nR, nG, nB;
  float gamma;
  
  if (argc != 4) 
     {
       printf("Usage: ImageIn.ppm ImageOut.ppm gamma  \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   sscanf (argv[3],"%f",&gamma);

   OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_ppm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;


   int nTaille3 = nTaille * 3;
   
   allocation_tableau(ImgIn, OCTET, nTaille3);
   lire_image_ppm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille3);
	
   for (int i=0; i < nTaille3; i+=3)
     {
       nR = ImgIn[i];
       nG = ImgIn[i+1];
       nB = ImgIn[i+2];
       
      // ImgOut[i]= pow((nR/255),gamma) * 255*100; 
      // ImgOut[i+1]= pow((nG/255),gamma) * 255*100; 
       //ImgOut[i+2]= pow((nB/255),gamma) * 255*100; 
      // cout<<pow((nB/255),gamma)<<endl;
       
        ImgOut[i]= 255 * (pow((nR/255),gamma));
       ImgOut[i+1]=255 * (pow((nG/255),gamma));
       ImgOut[i+2]= 255 * (pow((nB/255),gamma));
     }
   cout << gamma;
   ecrire_image_ppm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn);
   return 1;
}

