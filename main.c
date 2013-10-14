#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {			// DEBUT main()

	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	//																			//
	//					DEBUT	-	DECLARATION DES VARIABLES					//
	//																			//
	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	
    Personne repertoire[100] = { 0 };	// repertoire de 100 personnes
    int pro[100] = { 0 };						// tableau de 100 professionels
    int nbrperso = 0;							// Le nombre de personne(s) existante(s)
    int nbrpro = 0;								// Le nombre de personne(s) professionelle(s)
    char code;								 // code de transaction
	
	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	//																			//
	//					FIN		-	DECLARATION DES VARIABLES					//
	//																			//
	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	
	
	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	//																			//
	//					DEBUT	-		CODE DE TRANSACTION						//
	//																			//
	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	
    printf(WELCOME);
    
    code=getchar();		// STDIN <code>
    while(code!='Q' && code!='q') {				// Option 'Q' ou 'q' pour quitter le programme
                    switch(code) {
                                 case 'I':		// Option 'I' ou 'i' pour inscription()
								 case 'i':
                                     inscription(repertoire, &nbrperso, pro, &nbrpro);
                                      break;
                                 case 'S':		// Option 'S' ou 's' pour supprimer()
								 case 's':
                                     supprimer(repertoire, &nbrperso, pro, &nbrpro);
                                        break;
                                 case 'M':		// Option 'M' ou 'm' pour modifier()
								 case 'm':
                                     modification(repertoire, &nbrperso, pro, &nbrpro);
                                      break;
                                 case 'T':		// Option 'T' ou 't' pour afficher tous le repertoire
								 case 't':
                                     affichage(repertoire, nbrperso);
                                        break;
                                 case 'A':		// Option 'A' ou 'a' pour afficher uniquement les personnels
								 case 'a':
                                     affichageperso(repertoire, nbrperso, pro, nbrpro);
                                      break;
                                 case 'P':     // Option 'A' ou 'a' pour afficher uniquement les professionels
                                 case 'p':
                                      affichagepro(repertoire, nbrperso, pro, nbrpro);
                                        break;
                                 case 'R':
                                 case 'r':
                                      rech_num(repertoire, nbrperso, pro, nbrpro); // Option 'R' recherche numero par (nom) ou (nom et prenom)
                                      break;
                                 case 'N':
                                 case 'n':
                                      rech_num_by_name(repertoire, nbrperso, pro, nbrpro); // Option 'N' recherche numero par nom
                                        break;
                                 case 'B':
                                 case 'b':
                                      rech_name(repertoire, nbrperso, pro, nbrpro); // Option 'B' recherche par numero de telephone
                                      break;
                                 case 'L':
                                 case 'l':
                                      rech_char(repertoire, nbrperso, pro, nbrpro);
                                        break;
                                 case 'C':
                                     system("cls");
                                        break;
                                 default:
                                 printf("[#] Error : Code Unknow\n"); // Si le code de transaction est inconnu
                                 }
								 
    printf("[#] Le repertoire contient %d personnes dont %d pro\n[~] Please enter code:\n\n", nbrperso, nbrpro);
    fflush(stdin);
    code=getchar();		// STDIN <code>
    }
	
    printf("Bye Bye :)\n");
	system("pause");
    return 0;
}						// Fin main()

void inscription(struct Personne *repertoire, int *nbrperso, int *pro, int *nbrpro) {
    printf("[~] Enter <last name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].nom);

    printf("[~] Enter <first name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].prenom);

    int rech=recherche(repertoire, *nbrperso);

    if(rech<0) {
        printf("[~] Enter <telephone number> :\n");
        fflush(stdin);
        gets(repertoire[*nbrperso].tel);

        printf("[~] Enter <categorie> :\n(0) for personal contact\n(1) for professional contact\n");
        fflush(stdin);
        scanf("%d",&(repertoire[*nbrperso].cat));

        while(((repertoire[*nbrperso].cat)!=0) && ((repertoire[*nbrperso].cat)!=1)) {
            printf("[#] Error : bad categorie, please select again :\n(0) for personnel contact\n(1) for professional contact\n");
            fflush(stdin);
            scanf("%d",&(repertoire[*nbrperso].cat));
        }

        int i;
        struct Personne temp;
        for(i=0;i<*nbrperso && ((strcmp(repertoire[*nbrperso].nom, repertoire[i].nom)!=-1));i++) {
        for(i;i<*nbrperso && ((strcmp(repertoire[*nbrperso].prenom, repertoire[i].prenom)!=-1));i++); //A VERIFIER TRI PRENOM
        }
        for(i;i<*nbrperso;i++) {
        temp=repertoire[i];
        repertoire[i]=repertoire[*nbrperso];
        repertoire[*nbrperso]=temp;
        }

        *nbrperso=*nbrperso+1; // Incrementation number of contacts

                               *nbrpro=0; // ON CREE LE TAB PRO
                               for(i=0; i<*nbrperso; i++) {
                               if(repertoire[i].cat) {
                                                           pro[*nbrpro]=i;
                                                           *nbrpro=(*nbrpro)+1;
                                                           }
                                     }
    }
    else
    {
        printf("[#] Error : sorry this guy already exist\n");
        printf("Last Name : %s\nFirst Name : %s\nTelephone Number : %s\n----------\n", repertoire[rech].nom,repertoire[rech].prenom,repertoire[rech].tel);
    }
}

void supprimer(struct Personne* repertoire, int *nbrperso, int *pro, int *nbrpro) {
    printf("[~] Enter <last name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].nom);

    printf("[~] Enter <first name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].prenom);

    char r;
    int rech=recherche(repertoire, *nbrperso);

    if(rech>-1) {
            do {
            printf("[#] Are you sure to remove this contact ?\nLast Name : %s\nFirst Name : %s\nTelephone Number : %s\n[#] [Y/N]\n", repertoire[rech].nom, repertoire[rech].prenom, repertoire[rech].tel);
            fflush(stdin);
            r=getchar();
            } while(((r)!='Y') && ((r)!='N'));

            if(r=='Y') {

                       int i;
                       for(rech;rech<*nbrperso;rech++) { // ON TRI LE repertoire
                       repertoire[rech]=repertoire[rech+1];
                       }

                       *nbrperso=*nbrperso-1; // ON DECREMENTE LE NBR DE PERSO

                        *nbrpro=0;                          // CREATION TAB PRO
                        for(i=0; i<*nbrperso; i++) {
                                 if(repertoire[i].cat) {
                                 pro[*nbrpro]=i;
                                 *nbrpro=(*nbrpro)+1;
                                 }
                        }
            }
    }
    else
    {
        printf("[#] Error : Contact Unknow\n");
    }
}

void modification(struct Personne* repertoire, int *nbrperso, int *pro, int *nbrpro) {
    printf("[~] Enter <last name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].nom);

    printf("[~] Enter <first name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].prenom);
    
    int rech=recherche(repertoire, *nbrperso);

    if(rech>-1) {

            int imod=rech;

            do {
                    printf("[~] Enter NEW <last name> :\n");
                    fflush(stdin);
                    gets(repertoire[*nbrperso].nom);
    
                    printf("[~] Enter NEW <first name> :\n");
                    fflush(stdin);
                    gets(repertoire[*nbrperso].prenom);

                    rech=recherche(repertoire, *nbrperso);

                        if(rech<0) {
                            printf("[~] Enter NEW <telephone number> :\n");
                            fflush(stdin);
                            gets(repertoire[*nbrperso].tel);

                            printf("[~] Enter NEW <categorie> :\n(0) for personal contact\n(1) for professional contact\n");
                            fflush(stdin);
                            scanf("%d",&(repertoire[*nbrperso].cat));

                                while(((repertoire[*nbrperso].cat)!=0) && ((repertoire[*nbrperso].cat)!=1)) {
                                printf("[#] Error : bad categorie, please select again :\n(0) for personnel contact\n(1) for professional contact\n");
                                fflush(stdin);
                                scanf("%d",&(repertoire[*nbrperso].cat));
                                }

                            repertoire[imod]=repertoire[*nbrperso]; // ON EFFECTUE LA MODIF DE NOM PRENOM

                            int i; // ON TRI LE TAB
                            struct Personne temp;
                            for(i=0;i<*nbrperso && (strcmp(repertoire[imod].nom, repertoire[i].nom)!=-1);i++);
                            for(i;i<imod;i++) {
                            temp=repertoire[i];
                            repertoire[i]=repertoire[imod];
                            repertoire[imod]=temp;
                            }

                            *nbrpro=0;                 // ON CREE LE TAB PRO
                            for(i=0; i<*nbrperso; i++) {
                                     if(repertoire[i].cat) {
                                                           pro[*nbrpro]=i;
                                                           *nbrpro=(*nbrpro)+1;
                                                           }
                                     }

                        }
                        else
                        {
                            printf("[#] DOUBLON DOUBLON DOUBLON [#]\n");
                        }
            } while (rech>-1);
    }
    else
    {
        printf("[#] Error : Contact Unknow\n");
    }
}

int recherche(struct Personne *repertoire, int nbrperso) {
    int i;
    for(i=0;i<nbrperso;i++) { //&& nbrperso!=0
                        if(strcmp(repertoire[nbrperso].nom,repertoire[i].nom)==0) {
                            if(strcmp(repertoire[nbrperso].prenom,repertoire[i].prenom)==0) {
                                return i; // Return indice contact
                             }
                        }
    }

    return -1; // Return -1 if Contact Unknow
}

void affichage(struct Personne *repertoire, int nbrperso)
{
    int i, pause=0;
    for(i=0;i<nbrperso;i++) {
                            if((++pause)%6==0)
                            {
                                       system("pause");
                            }
        printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
    }
}

void affichageperso(struct Personne *repertoire, int nbrperso, int *pro, int nbrpro) {
    int i, pause=0;
    for(i=0;i<nbrperso;i++) {
    if(!(repertoire[i].cat)) {
                            if((++pause)%6==0)
                            {
                                       system("pause");
                            }
            printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
            }
    }
}

void affichagepro(struct Personne *repertoire, int nbrperso, int *pro, int nbrpro) {
    int i, pause=0;
    for(i=0;i<nbrpro;i++) {
                           if((++pause)%6==0)
                            {
                                       system("pause");
                            }
            printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[pro[i]].nom,repertoire[pro[i]].prenom,repertoire[pro[i]].tel,repertoire[pro[i]].cat);
    }
}

void rech_num(struct Personne *repertoire, int nbrperso, int *pro, int nbrpro) {
     int r, i, pause=0;
     struct Personne temp;
     
     do{
     printf("Effectuer la recherche uniquement sur les pro ?\n(1) Oui\n(0) Non, sur tout le repertoire\n");
     fflush(stdin);
     scanf("%d",&r);
     }while((r!=0) && (r!=1));
     
                   printf("[~] Enter <last name> :\n");
                   fflush(stdin);
                   gets(temp.nom);
                   
                   printf("[~] Enter <first name> :\n");
                   fflush(stdin);
                   gets(temp.prenom);
                   
     if(r)
     {
          for(i=0; i<nbrpro && (strcmp(temp.nom,repertoire[pro[i]].nom)!=1);i++) {
                  if(strcmp(temp.nom,repertoire[pro[i]].nom)==0) {
                  if(strcmp(temp.prenom,repertoire[pro[i]].prenom)==0 || !strlen(temp.prenom)) {
                                                                      if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[pro[i]].nom,repertoire[pro[i]].prenom,repertoire[pro[i]].tel,repertoire[pro[i]].cat);
                  }
                  }
          }
     }
     else
     {
         for(i=0; i<nbrperso && (strcmp(temp.nom,repertoire[i].nom)!=1);i++) {
                  if(strcmp(temp.nom,repertoire[i].nom)==0) {
                  if(strcmp(temp.prenom,repertoire[i].prenom)==0 || !strlen(temp.prenom)) {
                                                                                             if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
                  }
                  }
         }
     }
}

void rech_num_by_name(struct Personne *repertoire, int nbrperso, int *pro, int nbrpro) {
     int r, i, pause=0;
     struct Personne temp;
     
     do{
     printf("Effectuer la recherche uniquement sur les pro ?\n(1) Oui\n(0) Non, sur tout le repertoire\n");
     fflush(stdin);
     scanf("%d",&r);
     }while((r!=0) && (r!=1));
     
                   printf("[~] Enter <last name> :\n");
                   fflush(stdin);
                   gets(temp.nom);
                   
                   printf("[~] Enter <first name> :\n");
                   fflush(stdin);
                   gets(temp.prenom);
                   
     if(r)
     {
          for(i=0; i<nbrpro && (strcmp(temp.nom,repertoire[pro[i]].nom)!=1);i++) {
                  if(strcmp(temp.nom,repertoire[pro[i]].nom)==0) {
                                                                                             if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[pro[i]].nom,repertoire[pro[i]].prenom,repertoire[pro[i]].tel,repertoire[pro[i]].cat);
                  }
          }
     }
     else
     {
         for(i=0; i<nbrperso && (strcmp(temp.nom,repertoire[i].nom)!=1);i++) {
                  if(strcmp(temp.nom,repertoire[i].nom)==0) {
                                                                                        if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
                  }
         }
     }
}

void rech_name(struct Personne *repertoire, int nbrperso, int *pro, int nbrpro) {
     int r, i, pause=0;
     struct Personne temp;
     
     do{
     printf("Effectuer la recherche uniquement sur les pro ?\n(1) Oui\n(0) Non, sur tout le repertoire\n");
     fflush(stdin);
     scanf("%d",&r);
     }while((r!=0) && (r!=1));
     
                   printf("[~] Enter <telephone number> :\n");
                   fflush(stdin);
                   gets(temp.tel);
                   
     if(r)
     {
          for(i=0; i<nbrpro && (strcmp(temp.tel,repertoire[pro[i]].tel)!=0);i++);
                  if(i!=nbrpro) {
                                                            if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[pro[i]].nom,repertoire[pro[i]].prenom,repertoire[pro[i]].tel,repertoire[pro[i]].cat);
                  }
     }
     else
     {
         for(i=0; i<nbrperso && (strcmp(temp.tel,repertoire[i].tel)!=0);i++);
                  if(i!=nbrperso) {
                                                              if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
                  }
     }
}

void rech_char(struct Personne *repertoire, int nbrperso, int *pro, int nbrpro) {
     int r, i, pause=0;
     char u;
     
     do{
     printf("Effectuer la recherche uniquement sur les pro ?\n(1) Oui\n(0) Non, sur tout le repertoire\n");
     fflush(stdin);
     scanf("%d",&r);
     }while((r!=0) && (r!=1));
     
                   printf("[~] Enter <Lettre> :\n");
                   fflush(stdin);
                   u=getchar();
                   
     if(r)
     {
          for(i=0; i<nbrpro && (u <= repertoire[pro[i]].nom[0]) ;i++) {
                  if(u == repertoire[pro[i]].nom[0]) {
                                                   if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[pro[i]].nom,repertoire[pro[i]].prenom,repertoire[pro[i]].tel,repertoire[pro[i]].cat);
                  }
                  }
     }
     else
     {
         for(i=0; i<nbrperso && (u <= repertoire[i].nom[0]) ;i++) {
                  if(u == repertoire[i].nom[0]) {
                                                              if((++pause)%6==0)
                            {
                                       system("pause");
                            }
                  printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
                  }
                  }
     }
}
