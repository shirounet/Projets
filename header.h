    struct Personne {
           char nom[15];
           char prenom[15];
           char tel[10];
           int cat;
           };

    void inscription(struct Personne*, int*, int*, int*);
    void supprimer(struct Personne*, int*);
    void modification(struct Personne*, int *);
    void affichage(struct Personne*, int);
    void affichagepro(struct Personne *, int, int*, int);
    int recherche(struct Personne *, int);
    int tri(struct Personne *, int, int *, int);
