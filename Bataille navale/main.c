#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>       //toutes les librairies utilisé

#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center
#pragma execution_character_set( "utf-8" )


    int Choix,colonne,ligne,ligneTir,colonneTir,u=2,pointRestant=10,viePetit=2,vieGrand=4,vieMoyen=3,choixTableau,choixReponse,SigneLigne =1,SigneColonne=1,compteur,ConditionImpossible=0,tempActuel,tempBase,reset=0,scores,coupRestant=35;
    char prenom[50],reponse[3],pseudo[50];  //Création des variables

    //M = Moyen
    //G = Grand
    //S = Small
    //P = Petit
    char grille[8][8];                          //Création de la grille visible
    char grilleDeJeu[8][8];                     //Création de la grille vierge
    char grilleModel1[8][8] ={                  //Création des tableau models
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
    /*printf("1. Jouer \n\n2. Aide\n\n3. Score\n\n4. Quitter\n");     //Le menu oú l'utilisateur choisit ce qu'il veut faire*/
    do                                       //Boucle de sécurité pour que l'utilisateur rentre un chiffre de 1 à 4
    {
    printf("\n\n\n\n");
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("                                   %c               Choississez une des 4 options           %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                         1.Jouer                       %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                          2.Aide                       %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                         3.Score                       %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                        4.Quitter                      %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n\n\n",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);
    printf("                                                               ");
    scanf("%d", &Choix);
    system("cls");
    }
    while(Choix>=5||Choix<=0);
    switch(Choix)
    {
    case 1:
        Jeu();                                                      //Fonction Jeu qui fait démarrer une partie
        break;
    case 2:
        Aide();                                                     //Fonction Aide qui affiche les personne qui m'ont aidé
        break;
    case 3:
        Score();                                                    //Affiche tous les scores
        break;
    case 4:
        Quitter();                                                  //Fait quitter le programme
        break;
    }
}
void Quitter()                                                      //Fait quitter le programme
{
    system("cls");
    printf("\n\n\n\n");
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("                                   %c       Revien vite sinon tes bateau vont couler        %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                  Merci d'avoir jouer                  %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                    Bataille navale                    %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n\n\n\n\n",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);
    system("pause");

    system("taskkill /IM cb_console_runner.exe");
}
void Aide()                                                         //Fonction Aide qui affiche les personne qui m'ont aidé
{
    system("cls");
    printf("\n\n\n\n");
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("                                   %c                          Aide:                        %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                         Merci :                       %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c              Au capitaine MICHAEL PERDOLETTI          %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                  Au pirate AKMIR RAZIC                %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                 Au jeune VALENTIN ZINGG               %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c                   SINON YA PAS D'AIDE                 %c\n",DVSB,DVSB);
    printf("                                   %c                                                       %c\n",DVSB,DVSB);
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n\n\n\n\n",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);

    system("pause");
    system("cls");
    menu();
}

    void introduction()                                                 //Demande le nom du joueur
{
    SetConsoleOutputCP(437);
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("                                   %c         Bienvenue dans la bataille navale             %c\n",DVSB,DVSB);
    printf("                                   %c                      Version 1.0                      %c\n",DVSB,DVSB);
    printf("                                   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n\n\n\n\n",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);
    system("pause");
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("                                %c  Comment vous appelez-vous captain ? (sans espace)    %c\n",DVSB,DVSB);
    printf("                                %c                                                       %c\n",DVSB,DVSB);
    printf("                                %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n                                                           ",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);
    scanf("%s", &prenom);
    system("cls");
}

    void Jeu()
{
    FILE *fichier = fopen("resultat.txt","a+");                          //Ouvre le fichier des scores
    for(ligne = 0; ligne <8;ligne++)
    {
        for(colonne =0;colonne <8;colonne++)
        {
            grille[ligne][colonne]='-';                                 //Remplit la grille visible de -
        }
    }
    for(ligne = 0; ligne <8;ligne++)
    {
        for(colonne =0;colonne <8;colonne++)
        {
            grilleDeJeu[ligne][colonne]='-';                            //Remplit la grille invisible de -
        }
    }
    do
    {
    printf("\n\n\n\n");
    printf("                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("                        %c       Voulez vous une carte aleatoire(1.oui 2.non)      %c\n",DVSB,DVSB);
    printf("                        %c                                                         %c\n",DVSB,DVSB);
    printf("                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);
    printf("                                                   ");
    scanf("%d",&choixReponse);                                                              //demande si l'utilisateur si il veut une grille aléatoire ou pas
    }
    while(choixReponse>=3||choixReponse<=0);
    switch(choixReponse)
    {
    case 1:
        choixTableau=rand()%5;                                         //Choisit un chiffre aléatoire de 1 à 5
        break;
    case 2:
    printf("\n\n\n");
    printf("                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
    printf("                        %c          Choississez un chiffre de 1 a 5                %c\n",DVSB,DVSB);
    printf("                        %c                                                         %c\n",DVSB,DVSB);
    printf("                        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);
    printf("                                                   ");
    scanf("%d", &choixTableau);                                    //L'utilisateur choisit un chiffre de 1 à 5
        break;
    }
    switch(choixTableau)
    {
        case 1:
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    grilleDeJeu[ligne][colonne]=grilleModel1[ligne][colonne];   //Transfert la première grille model dans la  grille vierge
                }
            }
            break;
        case 2:
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    grilleDeJeu[ligne][colonne]=grilleModel2[ligne][colonne];   //Transfert la deuxième grille model dans la  grille vierge
                }
            }
           break;
        case 3:
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    grilleDeJeu[ligne][colonne]=grilleModel3[ligne][colonne];   //Transfert la troisième grille model dans la  grille vierge
                }
            }
        break;
        case 4:
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    grilleDeJeu[ligne][colonne]=grilleModel4[ligne][colonne];   //Transfert la quatrième grille model dans la  grille vierge
                }
            }
            break;
        case 5:
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    grilleDeJeu[ligne][colonne]=grilleModel5[ligne][colonne];   //Transfert la cinquième grille model dans la  grille vierge
                }
            }
        break;
    }
    system("cls");
    do
    {
        printf("\n\n\n");
        printf("                         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",DTLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DTRC);
        printf("                         %c              Nombre de coup restant:%d                  %c\n",DVSB,coupRestant,DVSB);    //Affiche le nombre de coup restant
        printf("                         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",DBLC,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DHSB,DBRC);
        printf("                                                   \n");

        SigneColonne=1;
        SigneLigne=1;
        printf("                                     ");
    for(compteur=0; compteur<8;compteur++)
    {
        printf("%5d", SigneLigne);                                              //Affiche les chiffre à coté de la grille
        SigneLigne++;
    }
    printf("\n");
    printf("                                    ");
    printf("%d", SigneColonne);                                                 //Affiche les chiffre à coté de la grille
        for(ligne = 0; ligne <8;ligne++)
        {
            for(colonne =0;colonne <8;colonne++)
            {
                printf("%5c", grille[ligne][colonne]);                          //Affiche la grille
            }
            printf("\n");
            printf("                                    ");
            if(SigneColonne<8)
            {
                SigneColonne++;
                printf("%d", SigneColonne);                                     //Affiche les chiffre à coté de la grille
            }
        }
        printf("Choisissez une ligne: ");
        scanf("%d", &ligneTir);                                                 //L'utilisateur choisit la ligne pour tiré
        while(ligneTir>=9||ligneTir<=0)                                         //Condition pour que l'utilisateur chosit un chiffre de 1 à 8
        {
            printf("                                    ");
            printf("Choisit un chiffre entre 1 et 8 !!!!!\n");
            printf("                                    ");
            scanf("%d", &ligneTir);
        }
        ligneTir=ligneTir-1;
        printf("\n                                    ");
        printf("Choisissez une colonne: ");
        scanf("%d", &colonneTir);                                               //L'utilisateur choisit la colonne pour tiré
        while(colonneTir>=9||colonneTir<=0)                                     //Condition pour que l'utilisateur chosit un chiffre de 1 à 8
        {
            printf("                                    ");
            printf("Choisit un chiffre entre 1 et 8 !!!!!\n");
            printf("                                    ");
            printf("Choisissez une ligne: ");
            scanf("%d", &colonneTir);
        }
        colonneTir=colonneTir-1;                                                //Fait moin un pour que les tir coresponde à la grille
        if(grilleDeJeu[ligneTir][colonneTir]=='-')
        {
            if(grille[ligneTir][colonneTir]=='R'||grille[ligneTir][colonneTir]=='C')                //Condition pour qu'il ne tire pas deux fois au même endroit
            {
                printf("\n\n                                    ");
                printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
            }
            else
            {
                printf("\n\n                                    ");
                grille[ligneTir][colonneTir]='R';                                                   //Affiche un R à l'endroit indiquer par l'utilisateur ne touche pas de bateau
                printf("Ton tir est tomber dans la flotte !!\n\n");
                coupRestant--;
                scores--;
            }
        }
        else
        {
            if(grilleDeJeu[ligneTir][colonneTir]=='G')
            {
                if(grille[ligneTir][colonneTir]=='T'||grille[ligneTir][colonneTir]=='C')                //Condition pour qu'il ne tire pas deux fois au même endroit
                {
                    printf("\n\n                                    ");
                    printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                }
                else
                {
                    grille[ligneTir][colonneTir]='T';                                                       //Affiche un T à l'endroit indiquer par l'utilisateur touche un bateau
                    vieGrand--;
                    pointRestant--;
                    printf("\n\n                                    ");
                    printf("Bravo !! Tu as toucher un bateau.\n\n");
                    coupRestant--;
                    scores= scores+3;
                }
            }
            else
            {
                if(grilleDeJeu[ligneTir][colonneTir]=='M')
                {
                    if(grille[ligneTir][colonneTir]=='T'||grille[ligneTir][colonneTir]=='C')                //Condition pour qu'il ne tire pas deux fois au même endroit
                    {
                        printf("\n\n                                    ");
                        printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                    }
                    else
                    {
                        grille[ligneTir][colonneTir]='T';                                                   //Affiche un T à l'endroit indiquer par l'utilisateur touche un bateau
                        vieMoyen--;
                        pointRestant--;
                        printf("\n\n                                    ");
                        printf("Bravo !! Tu as toucher un bateau.\n\n");
                        coupRestant--;
                        scores= scores+3;
                    }
                }
                else
                {
                    if(grilleDeJeu[ligneTir][colonneTir]=='P')
                    {
                        if(grille[ligneTir][colonneTir]=='T'||grille[ligneTir][colonneTir]=='C')                //Condition pour qu'il ne tire pas deux fois au même endroit
                        {
                            printf("\n\n                                    ");
                            printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                        }
                        else
                        {
                            grille[ligneTir][colonneTir]='T';                                                   //Affiche un T à l'endroit indiquer par l'utilisateur touche un bateau
                            viePetit--;
                            pointRestant--;
                            printf("\n\n                                    ");
                            printf("Bravo !! Tu as toucher un bateau. \n\n");
                            coupRestant--;
                            scores= scores+3;
                        }
                    }
                    else
                    {
                        if(grilleDeJeu[ligneTir][colonneTir]=='S')
                        {
                            if(grille[ligneTir][colonneTir]=='C')                                                       //Condition pour qu'il ne tire pas deux fois au même endroit
                            {
                                printf("\n\n                                    ");
                                printf("Tu as deja tirer a cette position !! Je te laisse ressayer :) \n\n\n\n");
                            }
                            else
                            {
                                grille[ligneTir][colonneTir]='C';                                                       //Affiche un C puisque le bateau est directement coulé
                                pointRestant--;
                                printf("\n\nTu as couler un bateau\n\n");
                                coupRestant--;
                                scores= scores+5;
                            }
                        }
                    }
                }
            }
        }
        scores=scores+coupRestant;
        if(vieGrand==0)                                                                                                 //Regarde si la vie des grands bateau est à 0
        {
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    if(grilleDeJeu[ligne][colonne]=='G')                                                                //Cherche toutes les lettres G du tableau visible
                    {
                        grille[ligne][colonne]='C';                                                                     //Affiche un C oú se trouvait les G pour afficher que le bateau est coulé
                    }
                }
            }
            vieGrand=1;
            printf("\n\n                                    ");
            printf("Tu as couler un bateau\n\n");
            scores= scores+5;
        }
        if(viePetit==0)
        {
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    if(grilleDeJeu[ligne][colonne]=='P')                                                                //Cherche toutes les lettres P du tableau visible
                    {
                        grille[ligne][colonne]='C';                                                                     //Affiche un C oú se trouvait les P pour afficher que le bateau est coulé
                    }
                }
            }
            printf("\n\n                                    ");
            printf("Tu as couler un bateau\n\n");
            scores= scores+5;
            viePetit=1;
        }
        if(vieMoyen==0)
        {
            for(ligne = 0; ligne <8;ligne++)
            {
                for(colonne =0;colonne <8;colonne++)
                {
                    if(grilleDeJeu[ligne][colonne]=='M')                                                                //Cherche toutes les lettres M du tableau visible
                    {
                        grille[ligne][colonne]='C';                                                                     //Affiche un C oú se trouvait les M pour afficher que le bateau est coulé
                    }
                }
            }
            printf("\n\n                                    ");
            printf("Tu as couler un bateau\n\n");
            scores= scores+5;
            vieMoyen=1;
        }
        printf("\n\n                                    ");
        system("pause");
        system("cls");
    }
    while(pointRestant >0 && coupRestant>0);                                                                            //Enregistre les infos dans le tableau

    fprintf(fichier,"%s", prenom);
    fprintf(fichier,"%s", "\n");
    fprintf(fichier,"%d", scores);
    fprintf(fichier,"%s", "\n");
    fprintf(fichier,"%d", coupRestant);
    fprintf(fichier,"%s", "\n");
    fprintf(fichier,"%s", "\n");

    if(pointRestant==0)                                                                                                 //Condition pour gagner la partie
    {
        printf("\nBravo tu as gagner\n\n");
    }
    else
    {
        printf("Tu as perdu, tu fera mieux la prochaine fois :)\n\n");
    }
    printf("1.Pour revenir au menu\n\n2.Pour quitter\n\n");
    pointRestant=10;
    fclose(fichier);
    scanf("%d", &reset);                                                                                                //Demande s'il veut quitter la partie ou revenir au menu
    while(reset<1||reset>2)                                                                                             //Sécurité pour que l'utilisateur ne puisse pas choisir un autre chiffre que 1 et 2
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
    FILE *fichier = fopen("resultat.txt","a+");                                                                                 //Ouvre le fichier text
    do
    {
        fscanf(fichier,"%s",&prenom);                                                                                           //Affiche les scores
        fscanf(fichier,"%d",&scores);
        fscanf(fichier,"%d",&coupRestant);
        printf("\n\n %s a reussi a faire %d point avec %d coup restants\n\n",prenom,scores,coupRestant);
    }
    while(!feof(fichier));
    fclose(fichier);
    system("pause");
    menu();
}
int main()
{
    sous_marin();
    introduction();
    menu();
    return 0;
}
