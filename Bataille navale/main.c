#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


    int Choix,colonne,ligne,ligneTir,colonneTir,u=2,pointRestant=1,viePetit=2,vieGrand=4,vieMoyen=3,choixTableau,choixReponse,SigneLigne =1,SigneColonne=1,compteur,ConditionImpossible=0,tempActuel,tempBase,reset=0,scores=10;
    char prenom[50],reponse[3];

    //M = Moyen
    //G = Grand
    //S = Small
    //P = Petit
    char grille[8][8];
    char grilleDeJeu[8][8];
    char grilleModel1[8][8] ={
        '-','-','-','-','-','-','-','-',
        '-','-','G','G','G','G','-','-',
        '-','-','-','-','-','-','-','-',
        '-','-','-','-','M','M','M','-',
        '-','-','-','-','-','-','-','-',
        '-','-','P','-','-','-','-','-',
        '-','-','P','-','-','-','-','-',
        '-','-','-','-','-','-','S','-',
    };
    char grilleModel2[8][8] ={
        'M','M','M','-','-','-','-','G',
        '-','-','-','-','-','-','-','G',
        '-','-','-','-','P','P','-','G',
        '-','-','-','-','-','-','-','G',
        '-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-',
        '-','-','S','-','-','-','-','-',
    };
    char grilleModel3[8][8] ={
        '-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','P','P',
        '-','M','M','M','-','-','-','-',
        '-','-','-','-','-','-','-','-',
        '-','-','G','-','-','-','-','-',
        '-','-','G','-','-','-','-','-',
        '-','-','G','-','-','-','-','-',
        '-','-','G','S','-','-','-','-',
    };
    char grilleModel4[8][8] ={
        'G','G','G','G','-','-','-','-',
        '-','-','-','-','-','-','-','P',
        '-','-','-','-','-','-','-','P',
        '-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-',
        '-','-','-','-','M','M','M','-',
        '-','-','-','-','-','-','-','-',
        'S','-','-','-','-','-','-','-',
    };
    char grilleModel5[8][8] ={
        '-','S','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-',
        '-','-','-','-','-','-','-','-',
        '-','G','G','G','G','-','-','-',
        '-','-','-','-','-','P','P','-',
        '-','-','M','-','-','-','-','-',
        '-','-','M','-','-','-','-','-',
        '-','-','M','-','-','-','-','-',
    };
    void sous_marin()
{
    printf("                                                     o o\n");
    printf("                                                     o ooo\n");
    printf("                                                       o oo\n");
    printf("                                                          o o      |   #)\n");
    printf("                                                           oo     _|_|_#_\n");
    printf("                                                             o   | U505  |\n");
    printf("                       __                    ___________________|       |_________________\n");
    printf("                       |   -_______-----------                                              \\ \n");
    printf("                     >|    _____                                                   --->     )\n");
    printf("                       |__ -     ---------_________________________________________________ /\n\n\n");
}

void menu()
{
    printf("1. Jouer \n\n2. Aide\n\n3. Score\n\n4. Quitter\n");
    scanf("%d", &Choix);
    system("cls");
    switch(Choix)
    {
    case 1:
        Jeu();
        break;
    case 2:
        Aide();
        break;
    case 3:
        Score();
        break;
    case 4:
        Quitter();
        break;
    }
}
void Quitter()
{
    printf("J espere que tu reviendras vite ;)");
    system("cls");
    return 0;
}
void Aide()
{
    system("cls");
    printf("Voici l aide :) :) :) :) :) :) :) :) :) :)");
    system("pause");
    system("pause");
    menu();
}

    void introduction()
{
    printf("Bienvenue dans la bataille navale\n\n\n");
    system("pause");
    system("cls");
    printf("Comment vous appelez-vous captain ? (sans espace)\n\n");
    scanf("%s", &prenom);
    system("cls");
}

    void Jeu()
{
    FILE *fichier = fopen("resultat.txt","a+");
    for(ligne = 0; ligne <8;ligne++)
    {
        for(colonne =0;colonne <8;colonne++)
        {
            grille[ligne][colonne]='-';
        }
    }
    for(ligne = 0; ligne <8;ligne++)
    {
        for(colonne =0;colonne <8;colonne++)
        {
            grilleDeJeu[ligne][colonne]='-';
        }
    }
    printf("Voulez vous que le choix de la carte soit aleatoire ? (1.oui    2.non)\n");
    scanf("%d",&choixReponse);
    switch(choixReponse)
    {
    case 1:
        choixTableau=rand()%5;
        break;
    case 2:
        printf("Choississez une grille entre 1 et 5\n\n");
        scanf("%d", &choixTableau);
        switch(choixTableau)
        {
            case 1:
                for(ligne = 0; ligne <8;ligne++)
                {
                    for(colonne =0;colonne <8;colonne++)
                    {
                        grilleDeJeu[ligne][colonne]=grilleModel1[ligne][colonne];
                    }
                }
            break;
            case 2:
                for(ligne = 0; ligne <8;ligne++)
                {
                    for(colonne =0;colonne <8;colonne++)
                    {
                        grilleDeJeu[ligne][colonne]=grilleModel2[ligne][colonne];
                    }
                }
            break;
            case 3:
                for(ligne = 0; ligne <8;ligne++)
                {
                    for(colonne =0;colonne <8;colonne++)
                    {
                        grilleDeJeu[ligne][colonne]=grilleModel3[ligne][colonne];
                    }
                }
            break;
            case 4:
                for(ligne = 0; ligne <8;ligne++)
                {
                    for(colonne =0;colonne <8;colonne++)
                    {
                        grilleDeJeu[ligne][colonne]=grilleModel4[ligne][colonne];
                    }
                }
            break;
            case 5:
                for(ligne = 0; ligne <8;ligne++)
                {
                    for(colonne =0;colonne <8;colonne++)
                    {
                        grilleDeJeu[ligne][colonne]=grilleModel5[ligne][colonne];
                    }
                }
            break;
        }
    break;
    }
    system("cls");
    while (pointRestant > 0)
    {
        SigneColonne=1;
        SigneLigne=1;
        printf(" ");
    for(compteur=0; compteur<8;compteur++)
    {
        printf("%5d", SigneLigne);
        SigneLigne++;
    }
    printf("\n");
    printf("%d", SigneColonne);
        for(ligne = 0; ligne <8;ligne++)
        {
            for(colonne =0;colonne <8;colonne++)
            {
                printf("%5c", grille[ligne][colonne]);
            }
            printf("\n");
            if(SigneColonne<8)
            {
                SigneColonne++;
                printf("%d", SigneColonne);
            }
        }
        printf("Choisissez une ligne: ");
        scanf("%d", &ligneTir);

        if(ligneTir>=8||ligneTir<=0)
        {
            printf("Choisit un chiffre entre 1 et 8 !!!!!\n");
            scanf("%d", &ligneTir);
        }
        ligneTir=ligneTir-1;
        printf("\nChoisissez une colonne: ");
        scanf("%d", &colonneTir);
        if(colonneTir>=8||colonneTir<=0)
        {
            printf("\nChoisissez une colonne: ");
            scanf("%d", &colonneTir);
        }
        colonneTir=colonneTir-1;

        if(grilleDeJeu[ligneTir][colonneTir]=='-')
        {
            if(grille[ligneTir][colonneTir]=='R')
            {
                printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
            }
            else
            {
                grille[ligneTir][colonneTir]='R';
                printf("\n\nTon tir a fait mouche !!!\n\n");
            }
        }
        else
        {
            if(grilleDeJeu[ligneTir][colonneTir]=='G')
            {
                if(grille[ligneTir][colonneTir]=='T')
                {
                    printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                }
                else
                {
                    grille[ligneTir][colonneTir]='T';
                    vieGrand--;
                    pointRestant--;
                    printf("\n\nBravo !! Tu as toucher un bateau.\n\n");
                }
            }
            else
            {
                if(grilleDeJeu[ligneTir][colonneTir]=='M')
                {
                    if(grille[ligneTir][colonneTir]=='T')
                    {
                        printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                    }
                    else
                    {
                        grille[ligneTir][colonneTir]='T';
                        vieMoyen--;
                        pointRestant--;
                        printf("\n\nBravo !! Tu as toucher un bateau.\n\n");
                    }
                }
                else
                {
                    if(grilleDeJeu[ligneTir][colonneTir]=='P')
                    {
                        if(grille[ligneTir][colonneTir]=='T')
                        {
                            printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                        }
                        else
                        {
                            grille[ligneTir][colonneTir]='T';
                            viePetit--;
                            pointRestant--;
                            printf("\n\nBravo !! Tu as toucher un bateau. \n\n");
                        }
                    }
                    else
                    {
                        if(grilleDeJeu[ligneTir][colonneTir]=='S')
                        {
                            if(grille[ligneTir][colonneTir]=='T')
                            {
                                printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                            }
                            else
                            {
                                if(grille[ligneTir][colonneTir]=='T')
                                {
                                    printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                                }
                                else
                                {
                                    grille[ligneTir][colonneTir]='C';
                                    pointRestant--;
                                    printf("\n\nTu as couler un bateau\n\n");
                                }
                            }
                        }
                    }
                }
            }
        }
        if(vieGrand==0)
        {
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    if(grilleDeJeu[ligne][colonne]=='G')
                    {
                        grille[ligne][colonne]='C';
                    }
                }
            }
            vieGrand=1;
            printf("\n\nTu as couler un bateau\n\n");
        }
        if(viePetit==0)
        {
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    if(grilleDeJeu[ligne][colonne]=='P')
                    {
                        grille[ligne][colonne]='C';
                    }
                }
            }
            printf("\n\nTu as couler un bateau\n\n");
            viePetit=1;
        }
        if(vieMoyen==0)
        {
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    if(grilleDeJeu[ligne][colonne]=='M')
                    {
                        grille[ligne][colonne]='C';
                    }
                }
            }
            printf("\n\nTu as couler un bateau\n\n");
            vieMoyen=1;
        }
        system("pause");
        system("cls");
    }
    fprintf(fichier,"%s", prenom);
    fprintf(fichier,"%s", "\n");
    fprintf(fichier,"%d", scores);
    fprintf(fichier,"%s", "\n");
    printf("\n\nBravo tu as gagner\n\n\n1.Pour revenir au menu\n\n2.Pour quitter\n\n");
    pointRestant=10;
    fclose(fichier);
    scanf("%d", &reset);
    while(reset<1||reset>2)
    {
        system("cls");
        printf("Choissiser le chiffre 1 ou 2 !!\n\n1.Pour revenir au menu\n\n2.Pour quitter\n");
        scanf("%d", &reset);
    }
    switch(reset)
    {
    case 1:
        system("cls");
        menu();
        break;
    case 2:
        system("cls");
        Quitter();
        break;
    }
    system("cls");
    menu();
}
void Score()
{

}
int main()
{
        sous_marin();
        introduction();
        menu();
    return 0;
}
