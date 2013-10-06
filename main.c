#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main() {

    struct Personne repertoire[100];
    int pro[100];

    int nbrperso=0;             // Le nombre de personne(s) existante(s)
    int nbrpro=0;               // Le nombre de personne(s) professionelle(s)
    char code;             // Code de transation

    printf("[~] Hi, please enter code:\n"); // Bonjour
    code=getchar();
    while(code!='Q' && code!='q') {
                    switch(code) {
                                 case 'I':
                                     inscription(repertoire, &nbrperso, pro, &nbrpro);
                                      break;
                                 case 'S':
                                     supprimer(repertoire, &nbrperso);
                                        break;
                                 case 'M':
                                     modification(repertoire, &nbrperso);
                                      break;
                                 case 'T':
                                     affichage(repertoire, nbrperso);
                                        break;
                                 case 'A':
                                     affichagepro(repertoire, nbrperso, pro, nbrpro);
                                      break;
                                 case 'P':
                                        break;
                                 case 'R':
                                      break;
                                 case 'N':
                                        break;
                                 case 'B':
                                      break;
                                 case 'L':
                                        break;
                                 case 'C':
                                     system("cls");
                                        break;
                                 default:
                                 printf("[#] Error : Code Unknow\n"); // Code inconnu
                                 }
    printf("[#]Le repertoire contient %d personnes dont %d pro\n[~] Please enter code:\n", nbrperso, nbrpro); // Bonjour
    fflush(stdin);
    code=getchar();
    }
    printf("[0] Bye Bye :)\n");
    return 0;
}

void inscription(struct Personne *repertoire, int *nbrperso, int *pro, int *nbrpro) {
    printf("[~] Enter <last name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].nom);

    printf("[~] Enter <first name> :\n");
    fflush(stdin);
    gets(repertoire[*nbrperso].prenom);

    int rech=recherche(repertoire, *nbrperso);
    printf("RECH %d NBRPERSO %d\n\n", rech, *nbrperso);
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

        if(*nbrperso) {
            tri(repertoire, *nbrperso, pro, *nbrpro);
        }

        *nbrperso=*nbrperso+1; // Incrementation number of contacts
    }
    else
    {
        printf("[#] Error : sorry this guy already exist\n");
        printf("Last Name : %s\nFirst Name : %s\nTelephone Number : %s\n----------\n", repertoire[rech].nom,repertoire[rech].prenom,repertoire[rech].tel);
    }
}

void supprimer(struct Personne* repertoire, int *nbrperso) {
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
                    for(rech;rech<*nbrperso;rech++) {
                        repertoire[rech]=repertoire[rech+1];
                        }
                        *nbrperso=*nbrperso-1;
            }
    }
    else
    {
        printf("[#] Error : Contact Unknow\n");
    }
}

void modification(struct Personne* repertoire, int *nbrperso) {
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

                            repertoire[imod]=repertoire[*nbrperso];
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

int tri(struct Personne *repertoire, int nbrperso, int *pro, int nbrpro)
{
    int i, ii;
    struct Personne temp;
        for(i=0;i<nbrperso && (strcmp(repertoire[nbrperso].nom, repertoire[i].nom)!=-1);i++);
    ii=i;
        for(i;i<nbrperso;i++) {
        temp=repertoire[i];
        repertoire[i]=repertoire[nbrperso];
        repertoire[nbrperso]=temp;
        }
    return ii;
}

void affichage(struct Personne *repertoire, int nbrperso)
{
    int i;
    for(i=0;i<nbrperso;i++) {
        printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
    }
}

void affichagepro(struct Personne *repertoire,int nbrperso, int *pro, int nbrpro) {
    int i;
    for(i=0;i<nbrperso;i++) {
        if(repertoire[i].cat) {
            printf("Last Name :%s\nFirst Name :%s\nTelephone Number :%s\nCat : %d\n----------\n", repertoire[i].nom,repertoire[i].prenom,repertoire[i].tel,repertoire[i].cat);
        }
    }
}
