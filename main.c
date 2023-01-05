#include <stdio.h>
#include "string.h"

// Variable qui donne le nombre de critere
#define T_CRITERE 3



// Création d'une structure Critere 
struct Critere {
  char nameCritere[100];
  int coef;
  double note;
};


// Stockage de critere dans une list
struct Critere critere[T_CRITERE] = {
  {"Premier critère", 1, 0},
  {"2 critere", 2, 0},
  {"3 critere", 3, 0}
};


// function principal d'un programme C
int main(){
  // Initialisation des variables
  char prenom[20];
  char nom[20];
  double total_note = 0.0;
  double total_coef_note = 0.0;
  double note_final = 0.0;
  double cache_note = 0.0;

  printf("<-- Bienvenue dans le gestionnaire de notes --> \n");

  // Lancement de la boucle tant que 'FIN' n'est pas écrit."
  do {
    // Demande le prenom
    printf("Donne moi le prenom de l'élève : ");
    scanf("%s", prenom);

    // Demande le nom
    printf("\nDonne moi le nom de l'élève : ");
    scanf("%s", nom);
    
    // Lancement de la boucle qui demande la notation des critères
    
    for (int i = 0; i < T_CRITERE; i++) {
        
      printf("\nDonne une note pour le critère : \n %s \n Avec un coefficient de : %d\n", critere[i].nameCritere, critere[i].coef);
      
      // Lancement de la boucle tant que la note saisie n'est pas correcte
      while (1) {
        printf("Donner une note entre 0 et 1 par tranches de 0.25 : \n");
        
        if(scanf("%lf", &cache_note) != 1){
            printf("Vous vous êtes trompé dans la notation, utilisez bien un nombre !\n");
            
            // Ces deux lignes permettent de vider le tampon d'entrée
            char buffer[100];
            fgets(buffer, 100, stdin);
        
            continue;
        }

        // Si la note saisie est valide
        if (((cache_note < 1) && (((int) (cache_note * 100) % 25) == 0))) {
          break;
        }

        // sinon, message d'erreur
        printf("Vous avez le choix entre 0, 0.25, 0.5, 0.75 et 1\n");
      }

      // Enregistre la note valide dans la structure Critère
      critere[i].note = cache_note;
    }


   
   // Calcule de la note final 
   for (int i = 0; i < T_CRITERE; i++) {
      total_note += critere[i].note * critere[i].coef;
      total_coef_note += critere[i].coef;
   }
  // Calcule de la note final
  note_final = (total_note / total_coef_note) * 20;
    
  printf("\n<---   Fin de la notation   --->\n\n");
  printf("\tPrénom : %s\n", prenom);
  printf("\tNom : %s\n", nom);
  printf("\tnote final : %.2lf/20\n", note_final);
  printf("\t(La note à été formaté à .00 !)\n");
  printf("\n<---           ()           --->\n");
  }while (strcmp(prenom, "FIN") == 1);

}

