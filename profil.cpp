#include <stdio.h>
#include "image_ppm.h"
#include<iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{

  char cNomImgLue[250]; // input du fichier .pgm
  int nH, nW, nTaille,valeur_actuelle_gris,LigneOuColonne,indice;
  
  FILE *histo;
  histo = fopen("profil.dat","wb");


  if (argc != 4) 
     {
       printf("Usage: ImageIn.pgm  LigneOuColonne(0 ligne ; 1 colonne) indice\n"); 
       exit (1) ;
     }
     
    sscanf (argv[1],"%s",cNomImgLue) ; //  association avec varaibles
    sscanf (argv[2],"%d",&LigneOuColonne) ; //  association avec varaibles
    sscanf (argv[3],"%d",&indice) ; //  association avec varaibles

   OCTET *ImgIn, *ImgOut; // tableau d'octet contenant les couleurs de chaque pixel
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
    nTaille = nH * nW;

  
  
   allocation_tableau(ImgIn, OCTET, nTaille);// calcul qui permet de représenter les différents pixel de l'imag dans un tableau 1D 


     // ex  0 1 2
       //     3 4 5  ==> 1 2 3 4 5 6 7 8 
       //     6 7 8 


   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);
  


  for (int i=0; i < nH; i++)
  {
   for (int j=0; j < nW; j++)
     {
       


      if(LigneOuColonne ==0 && i==indice){
        fprintf(histo,"%d,\n", ImgIn[i*nW+j]);
        ImgOut[i*nW+j] = 0;
      }

      else if(LigneOuColonne == 1 && j == indice){
        fprintf(histo,"%d,\n", ImgIn[i*nW+j]);
        ImgOut[i*nW+j] = 0;
      }
      
      else  {
            ImgOut[i*nW+j] = ImgIn[i*nW+j]; // image creer 
            }


    

     
     }
    }

       
 ecrire_image_pgm("toto", ImgOut,  nH, nW);
   free(ImgIn); free(ImgOut);
   return 1;
}
