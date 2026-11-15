#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    char **grid = malloc(4 * sizeof(char *));
    
    int i = 0;
    while(i < 3)
    {
        grid[i] = malloc(4 * sizeof(char));
        grid[i][0] = ' ';
        grid[i][1] = ' ';
        grid[i][2] = ' ';
        grid[i][3] = '\0';
        i = i+1;
    }
    grid[3] = NULL;

    printf("À vous de jouer ! :\n\n");
    i = 0;
    while(grid[i] != NULL)
    {
        printf("  %c  |  %c  |  %c  \n", grid[i][0], grid[i][1], grid[i][2]);
        if (i < 2) 
        {
            printf("-----------------\n");
        }
        i = i+1;
    }

    int choix;
    int ligne;
    int colonne;
    char gagnant = ' ';
    int tours = 0;

    while(gagnant == ' ' && tours < 9) 
    {
        int coup_valide = 0;
        while(coup_valide == 0) 
        {
            printf("\nChoisissez une position à jouer (0 a 8): ");
            scanf("%d", &choix);

            if(choix >= 0 && choix <= 8) 
            {
                if(choix == 0) { ligne = 0; colonne = 0; }
                else if(choix == 1) { ligne = 0; colonne = 1; }
                else if(choix == 2) { ligne = 0; colonne = 2; }
                else if(choix == 3) { ligne = 1; colonne = 0; }
                else if(choix == 4) { ligne = 1; colonne = 1; }
                else if(choix == 5) { ligne = 1; colonne = 2; }
                else if(choix == 6) { ligne = 2; colonne = 0; }
                else if(choix == 7) { ligne = 2; colonne = 1; }
                else if(choix == 8) { ligne = 2; colonne = 2; }

                if(grid[ligne][colonne] == ' ') 
                {
                    grid[ligne][colonne] = 'X';
                    coup_valide = 1;
                    tours = tours+1;
                } 
                else 
                {
                    printf("Veuillez choisir une case vide.\n");
                }
            }
            else
            {
                printf("Chiffre invalide (entre 0 et 8).\n");
            }
        }

        printf("\n");
        i = 0;
        while(grid[i] != NULL) 
        {
            printf("  %c  |  %c  |  %c  \n", grid[i][0], grid[i][1], grid[i][2]);
            if (i < 2) 
            {
                printf("-----------------\n");
            }
            i =i+1;
        }

        i = 0;
        while(i < 3) 
        {
            if(grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) 
            {
                gagnant = grid[i][0];
            }
            if(grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) 
            {
                gagnant = grid[0][i];
            }
            i = i+1;
        }
        if(grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) 
        {
            gagnant = grid[0][0];
        }
        if(grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) 
        {
            gagnant = grid[0][2];
        }

        if(gagnant == ' ' && tours < 9) 
        {
            printf("\nLe Robot joue...\n\n");
            int ordi_choix;
            int ordi_valide = 0;

            while(ordi_valide == 0)
            {
                ordi_choix = rand() % 9;

                if(ordi_choix == 0) { ligne = 0; colonne = 0; }
                else if(ordi_choix == 1) { ligne = 0; colonne = 1; }
                else if(ordi_choix == 2) { ligne = 0; colonne = 2; }
                else if(ordi_choix == 3) { ligne = 1; colonne = 0; }
                else if(ordi_choix == 4) { ligne = 1; colonne = 1; }
                else if(ordi_choix == 5) { ligne = 1; colonne = 2; }
                else if(ordi_choix == 6) { ligne = 2; colonne = 0; }
                else if(ordi_choix == 7) { ligne = 2; colonne = 1; }
                else if(ordi_choix == 8) { ligne = 2; colonne = 2; }

                if(grid[ligne][colonne] == ' ') 
                {
                    grid[ligne][colonne] = 'O';
                    ordi_valide = 1;
                    tours = tours+1;
                }
            }

            i = 0;
            while(grid[i] != NULL) 
            {
                printf("  %c  |  %c  |  %c  \n", grid[i][0], grid[i][1], grid[i][2]);
                if (i < 2) 
                {
                    printf("-----------------\n");
                }
                i =i+1;
            }

            i = 0;
            while(i < 3) 
            {
                if(grid[i][0] != ' ' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) 
                {
                    gagnant = grid[i][0];
                }
                if(grid[0][i] != ' ' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) 
                {
                    gagnant = grid[0][i];
                }
                i = i+1;
            }
            if(grid[0][0] != ' ' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) 
            {
                gagnant = grid[0][0];
            }
            if(grid[0][2] != ' ' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) 
            {
                gagnant = grid[0][2];
            }
        }
    }

    printf("\n");
    if(gagnant == 'X') 
    {
        printf("Bravo, vous avez gagné ! GG !\n");
    } 
    else if(gagnant == 'O') 
    {
        printf("Le Robot a gagné... Loser...\n");
    } 
    else 
    {
        printf("Et c'est un match nul... Peux mieux faire...\n");
    }
    i = 0;
    while(grid[i] != NULL)
    {
        free(grid[i]);
        i =i+1;
    }
    free(grid);
    
    return 0;
}