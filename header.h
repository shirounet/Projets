    struct Personne {
           char nom[16];
           char prenom[16];
           char tel[11];
           int cat;
           };

    void inscription(struct Personne*, int*, int*, int*);
    void supprimer(struct Personne*, int*, int*, int*);
    void modification(struct Personne*, int *, int*, int*);
    void affichage(struct Personne*, int);
    void affichagepro(struct Personne *, int, int*, int);
    int recherche(struct Personne *, int);
    int tri(struct Personne *, int, int *, int);
