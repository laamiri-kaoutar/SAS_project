#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct Etudiant {
    int id;
    char nom[50];
    char prenom[50];
    char date_naissance[15];  
    char departement[50];
    float note_generale;
} Etudiant;
void menu_departement(char departement[]) {
    int choix;
    int count=0;
    printf("Veuillez choisir un département :\n");
    printf("1. Informatique\n");
    printf("2. Mathématiques\n");
    printf("3. Physique\n");
    printf("4. Chimie\n");
    printf("5. Biologie\n");
    printf("Entrez votre choix (1-5) : ");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            strcpy(departement, "Informatique");
            break;
        case 2:
            strcpy(departement, "Mathematiques");
            break;
        case 3:
            strcpy(departement, "Physique");
            break;
        case 4:
            strcpy(departement, "Chimie");
            break;
        case 5:
            strcpy(departement, "Biologie");
            break;
        default:
            if(count<=3){
            printf("\n le Choix invalide.\n");
            menu_departement(departement);
            count++;
            } else break;
    }
}
void ajouter(Etudiant etudiants[], int *cmp){
       int n;
       printf("vous voulez ajouter : \n 1-un element \n 2-plusieurs elements\n");
       scanf("%d",&n);
       if(n==1){
        etudiants[*cmp].id = (*cmp)+1;
        printf("entrer le nom d'etudiant : ");
        scanf("%s",etudiants[*cmp].nom);
       printf("entrer le prenom d'etudiant : ");
        scanf("%s",etudiants[*cmp].prenom);
       printf("entrer la date de naissance d'etudiant : format JJ/MM/AAAA ");
        scanf("%s",etudiants[*cmp].date_naissance);
       printf("entrer la note generale d'etudiant : ");
        scanf("%f",&etudiants[*cmp].note_generale);
        menu_departement(etudiants[*cmp].departement);
        printf("\n");
          (*cmp)++;
       } else {
         int nmbEtud;
        printf("combiet d'etudiants vous voulez ajouter :");
        scanf("%d",&nmbEtud);
        for(int i=0; i< nmbEtud ; i++){
        etudiants[*cmp].id = (*cmp)+1;
        printf("entrer le nom d'etudiant : ");
        scanf("%s",etudiants[*cmp].nom);
       printf("entrer le prenom d'etudiant : ");
        scanf("%s",etudiants[*cmp].prenom);
       printf("entrer la date de naissance d'etudiant : format JJ/MM/AAAA ");
        scanf("%s",etudiants[*cmp].date_naissance);
       printf("entrer la note generale d'etudiant : ");
        scanf("%f",&etudiants[*cmp].note_generale);
        menu_departement(etudiants[*cmp].departement);
        printf("\n");
          (*cmp)++;
        }
        }
}
 void afficher(Etudiant etudiants[], int cmp){
    printf("\n%-20s | %-20s | %-20s | %-20s | %-20s | ","Nom", "Prenom", "Date de naissance", "Departement","Note generale");
    for(int i=0 ; i<cmp ; i++){
        printf("\n%-20s | %-20s | %-20f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);

    } 
 }
 int index_rechercher(Etudiant etudaint[],int id, int cmp){
    int found=-1;
    for(int i=0 ; i< cmp ; i++){
        if(etudaint[i].id== id){
        found=i;
        break;
        }
    }
   return found;
}
 void modifier(Etudiant etudiants[], int cmp){
    int id;
    printf("entrer id d'etudiant que vous voulez modifier : ");
    scanf("%d",&id);
    int found = index_rechercher(etudiants , id , cmp);
    if(found>=0){
        int choix;
        printf("\nque voulez-vous modifier ?\n");
        printf("1 - Nom              2 - Prenom\n");
        printf("3 - Date de naissance 4 - note generale\n");
        printf("5 - departement       6 - Tous les champs\n");
        printf("0 - Quitter\n");
        scanf("%d", &choix);
    switch (choix) {
        case 1:
            printf("entrer le nouveau nom: ");
            scanf("%s", etudiants[found].nom);
            break;
        case 2:
            printf("entrer le nouveau prenom : ");
            scanf("%s",etudiants[found].prenom);
            break;
        case 3:
            printf("entrer la nouvelle date de naissance : ");
            scanf("%s", etudiants[found].date_naissance);
            break;
        case 4:
            printf("entrer la nouvelle note generale: ");
            scanf("%f",&etudiants[found].note_generale);
            break;
        case 5:
            menu_departement(etudiants[found].departement);
            break;
        case 6:
            printf("Entrer le nouveau nom : ");
            scanf("%s", etudiants[found].nom);
            printf("Entrer le nouveau prenom : ");
            scanf("%s",etudiants[found].prenom);
            printf("Entrer la nouvelle date de naisance (: ");
            scanf("%s", etudiants[found].date_naissance);
            printf("Entrer la nouvelle note générale : ");
            scanf("%f", &etudiants[found].note_generale);
            menu_departement(etudiants[found].departement);
            break;
        case 0:
           printf("quitter \n");
            break;
        default:
            break;
      }
    } else printf("cet etudiant n'est existe pas .");
}
 void supprimer(Etudiant etudiants[], int *cmp){
    int id;
    printf("entrer id d'etudiant que vous voulez supprimer : ");
    scanf("%d",&id);
    int found = index_rechercher(etudiants , id , *cmp);
    if(found>=0){
        for (int i = found; i < *cmp; i++)
        {
            strcpy(etudiants[i].nom,etudiants[i+1].nom);
            strcpy(etudiants[i].prenom,etudiants[i+1].prenom);
            strcpy(etudiants[i].date_naissance,etudiants[i+1].date_naissance);
            strcpy(etudiants[i].note_generale,etudiants[i+1].note_generale);
            strcpy(etudiants[i].departement,etudiants[i+1].departement);
        }
        (*cmp)--,
    } else printf("cet etudiant n'est existe pas .");
}
void rechercher(Etudiant etudiants[], int cmp){
       char nom[50];
    int found=-1;
    printf("quel est le nom de l'etudiant que vous voulez rechercher ? ");
    scanf("%s",nom);
    for(int i=0 ; i< cmp ; i++){
        if(strcmp(etudiants[i].nom, nom) == 0){
        printf("\n%-20s | %-20s | %-20f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);
        found=i;
        break;
        }
    }
    if (found<0) printf("cet etudiant n'est existe pas :");
}

void rechercher_Departement(Etudiant etudiants[], int cmp){
    int choix;
    int count=0;
    printf("Veuillez choisir un département :\n");
    printf("1. Informatique\n");
    printf("2. Mathématiques\n");
    printf("3. Physique\n");
    printf("4. Chimie\n");
    printf("5. Biologie\n");
    printf("Entrez votre choix (1-5) : ");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            for(int i=0 ; i< cmp ; i++){
            if(strcmp(etudiants[i].departement, "Informatique") == 0){
            printf("\n%-20s | %-20s | %-20f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);
            }
            }
            break;
        case 2:
            for(int i=0 ; i< cmp ; i++){
            if(strcmp(etudiants[i].departement, "Mathematiques") == 0){
            printf("\n%-20s | %-20s | %-20f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);
            }
            }
            break;
        case 3:
            for(int i=0 ; i< cmp ; i++){
            if(strcmp(etudiants[i].departement, "Physique") == 0){
            printf("\n%-20s | %-20s | %-20f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);
            }
            }
            break;
        case 4:
            for(int i=0 ; i< cmp ; i++){
            if(strcmp(etudiants[i].departement, "Chimie") == 0){
            printf("\n%-20s | %-20s | %-20f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);
            }
            }
            break;
        case 5:
            for(int i=0 ; i< cmp ; i++){
            if(strcmp(etudiants[i].departement, "Biologie") == 0){
            printf("\n%-20s | %-20s | %-20f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);
            }
            }
            break;
        default:
            if(count<=3){
            printf("\n le Choix invalide.\n");
            menu_departement(departement);
            count++;
            } else break;
    }

}

/*les statistiques*/
void etudiantsDepart(Etudiant etudiants[],int cmp){
    int inf=0,bio=0,chim=0,math=0,phy=0;
    for(int i=0 ; i< cmp ; i++){
            if(strcmp(etudiants[i].departement, "Biologie") == 0){
                bio++;
            }
            if(strcmp(etudiants[i].departement, "Chimie") == 0){
                chim++;
            }
            if(strcmp(etudiants[i].departement, "Physique") == 0){
                phy++;
            }
            if(strcmp(etudiants[i].departement, "Informatique") == 0){
                inf++;
            }
            if(strcmp(etudiants[i].departement, "Mathematiques") == 0){
                math++;
            }
            }
        printf("Nombre d'etudiants dans chaque departement :\n");
        printf("%-20s : %d étudiants\n","Informatique", inf);
        printf("%-20s : %d étudiants\n","Mathematiques", math);
        printf("%-20s : %d étudiants\n","Biologie", bio);
        printf("%-20s : %d étudiants\n","Chimie", chim);
        printf("%-20s : %d étudiants\n","Physique", phy);
}
void totalEtudiants(int cmp){
     printf("nombre total des etudiants : %d\n", cmp);
}
void filtrerSeuil(Etudiant etudiants[], int cmp){
    int seuil;
    int n= 0;
    printf("Entrez le seuil de moyenne : ");
    scanf("%d",&seuil);
    for (int i = 0; i < cmp; i++)
    {
        if (etudiants[i].note_generale> seuil)
        {
            printf("\n%-20s | %-20s | %-20.2f | %-20d | %-20s | ",etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_naissance,etudiants[i].departement,etudiants[i].note_generale);
            n++;
        }
        
    }
    if(n== 0) printf("\nAucun etudiant n'a une moyenne superieure au seuil.\n");

    

}
int main(){
    Etudiant etudiants[200];
    int cmp;
    ajouter(etudiants, &cmp);
    return 0;
}