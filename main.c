#include <stdio.h>
#include "string.h"

struct Critere {
  char nameCritere[100];
  int coef;
  double note;
};

struct Critere critere[3] = {
  {"Premier critère", 1, 0},
  {"2 critere", 2, 0},
  {"3 critere", 3, 0}
};

int total_critere = 3;

int main(){
  char prenom[20];
  char nom[20];
  double total_note = 0.0;
  double total_coef_note = 0.0;
  double moyenne = 0.0;
  double cache_note = 0.0;

  printf("Bienvenue dans le gestionnaire de note : \n");

  do {
    // Demande le prenom
    printf("Donne moi le prenom : \n");
    scanf("%s", prenom);

    // Demande le nom
    printf("Donne moi le nom : \n");
    scanf("%s", nom);

    
    
    /*
    for (int i = 0; i < total_critere; i++) {
      printf("%s avec un coef de %d\n", critere[i].nameCritere, critere[i].coef);
      printf("Donne moi une note : \n");
      scanf("%lf", &cache_note);
      if((cache_note < 1) && (((int) (cache_note * 100) % 25) != 0)){
        printf("Vous avez le choix entre 0, 0.25, 0.5, 0.75 et 1");
        critere[i].note = cache_note;
        continue;
      }
      i--;
      continue;
    }
    */
    
    for (int i = 0; i < total_critere; i++) {
      printf("%s avec un coef de %d\n", critere[i].nameCritere, critere[i].coef);
      while (1) {
        printf("Donne moi une note : \n");
        scanf("%lf", &cache_note);

        // Si note saisie est valide
        if (((cache_note < 1) && (((int) (cache_note * 100) % 25) != 0))) {
          break;
        }

        // Si la note saisie par l'utilisateur n'est pas valide, affiche un message d'erreur
        printf("Vous avez le choix entre 0, 0.25, 0.5, 0.75 et 1");
      }

      // Enregistre la note valide dans la structure Critere
      critere[i].note = cache_note;
    }


   

   for (int i = 0; i < total_critere; i++) {
      total_note += critere[i].note * critere[i].coef;
      total_coef_note += critere[i].coef;
   }
  
  moyenne = (total_note / total_coef_note) * 20;

  printf("La note est de %lf", moyenne);

  }while (strcmp(prenom, "FIN") == 1);

}


