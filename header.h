	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	//																			//
	//					DEBUT	-	CONSTANTE D'AFFICHAGE                       //
	//																			//
	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	
#define WELCOME "[~] Welcome , select option :\n" \
"[~] Des mises a jours :\n(I)\tInscrire\n(S)\tSupprimer\n(M)\tModifier\n(Q)\tQuitter\n\n[~] "

	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
	//																			//
	//					FIN    	-	CONSTANTE D'AFFICHAGE                       //
	//																			//
	/*					~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~					*/
    struct Personne {
           char nom[16];
           char prenom[16];
           char tel[11];
           int cat;
           };
           
    typedef struct Personne Personne;

    void inscription(Personne*, int*, int*, int*);
    void supprimer(Personne*, int*, int*, int*);
    void modification(Personne*, int *, int*, int*);
    void affichage(Personne*, int);
    void affichageperso(Personne *, int , int *, int);
    void affichagepro(Personne *, int, int*, int);
    int recherche(Personne *, int);

    void rech_num(Personne *, int, int *, int);
    void rech_num_by_name(Personne *, int , int *, int );
    void rech_name(Personne *, int , int *, int );
    void rech_char(Personne *repertoire, int nbrperso, int *pro, int nbrpro);
