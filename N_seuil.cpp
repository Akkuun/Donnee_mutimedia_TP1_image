// test_couleur.cpp : Seuille une image en niveau de gris

#include <stdio.h>
#include "image_ppm.h"
#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille, S,pas;
  
  if (argc != 4) 
     {
       printf("Usage: ImageIn.pgm ImageOut.pgm Seuil \n"); 
       exit (1) ;
     }
   
   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);
   sscanf (argv[3],"%d",&S);

   OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);
   
   pas = 255/S;	
 
 for (int i=0; i < nH; i++) {
   for (int j=0; j < nW; j++)
     {
     
     bool ok = false;
     
     for (int n_pas=0; n_pas<255 ; n_pas+=pas){

	     if ( ImgIn[i*nW+j] < n_pas && !ok) {
	     
			     ImgOut[i*nW+j]=n_pas;
			     ok = true;
	     
	     }
    
     }
     
     if (!ok) ImgOut[i*nW+j]=255;
     
    }
 }

   ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
}

