#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <sys/stat.h>
#include <direct.h>

#include "Colors/colors.h"


#define WIDTH 13
#define HEIGHT 13
#define BORDER 35
#define TARGET 88
#define PLAYER 208
#define OBSTACLES 254

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ENTER 13

typedef struct{
    int x;
    int y;
} tTarget;

typedef struct{
    char name[8];
    int points;
} tPlayer;

void moveCursor(int x, int y)
{
    COORD destination = {x, y};
    HANDLE cursor = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition (cursor, destination);
}

void showRanking()
{
    system("cls");
    printf("Ranking:\n\n");
    printf("\tNickname:\tScore:\n\n");
    FILE *rf;
    rf = fopen("Ranking/ranking.pzl", "r+b");
    tPlayer player;

    if(rf==NULL)
        printf("\nfalha ao abrir ranking!\n");
    else{
        for(int i=0; i<10; i++){
            fread(&player, sizeof(tPlayer), 1, rf);
            printf("\t%s\t\t- %i\n", player.name, player.points);
        }
        fclose(rf);
    }
    printf("\n\n");
    system("pause");
}

void menuTutorial()
{
        system("cls");
        printf("Tutorial:\n\n");
        printf("Utilize as setas direcionais para movimentar o jogador\n");
        printf("Seu objetivo e chutar as caixas coloridas nos alvos marcados com X\n\n");
        FORERED; printf("CUIDADO"); RESETALL; printf(", se a caixa for chutada na parede nao sera possivel descola-la\n\n");
        printf("Nesse caso,\npressione a tecla \"r\" para reiniciar o mapa ou\nprecione a tecla \"m\" para retornar ao menu\n\n\n");
        system("pause");
}

void menuCreditos()
{
    system("cls");
    printf("Creditos:\n\n");
    printf("\tDesenvolvedores:\n\n");
    printf("\t\tGabriel Nalin Gibin\n");
    printf("\t\tVinicius Guimaraes\n\n\n");
    system("pause");
}

void menuDesign()
{
     system("CLS");


    FORERED; printf("\n\n\t %c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("%c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("%c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("        %c%c%c%c   ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("       %c%c%c%c    ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("      %c%c%c%c     ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE;printf("     %c%c%c%c      ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE;printf("    %c%c%c%c       ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c            ",254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("   %c%c%c%c        ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c            ",254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("  %c%c%c%c         ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c            ",254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c      %c%c%c   ", 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf(" %c%c%c%c          ",254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c            \n", 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c            ",254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("%c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c%c%c%c%c%c%c%c%c%c   \n", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;
    FORERED; printf("\t %c%c%c            ",254, 254, 254);RESETALL; FOREYELLOW; printf("%c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;FOREBLUE; printf("%c%c%c%c%c%c%c%c%c%c%c%c   ", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;FOREGREEN; printf("%c%c%c%c%c%c%c%c%c%c%c%c   \n", 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254);RESETALL;




    printf("\n\tJogar \n");
    printf("\tRanking \n");
    printf("\tTutorial \n");
    printf("\tCreditos \n");
    printf("\tSair \n");
}

int menuMoveIcon(int x)
{
    char key;
    key = getch();

    switch(key){
        case ARROW_UP:
            if(x == 0) return 4;
            else return -1;
            break;
        case ARROW_DOWN:
            if(x == 4) return -4;
            else return 1;
            break;
        case ENTER:
            return 5;
            break;
        default:
            return 0;
        }

}

void menu()
{
    for(;;){
        int x = 1;
        int icon = 0;

        while(x){
            moveCursor(0,0);
            menuDesign();
            moveCursor(5,15+ icon);
            printf("->");
            Beep(493, 100);

            if(menuMoveIcon(icon)== 5){
                x=0;
                }else{
                    icon += menuMoveIcon(icon);
                }
        }

        switch(icon){
            case 0: return;
            case 1: showRanking();
                    break;
            case 2: menuTutorial();
                    break;
            case 3: menuCreditos();
                    break;
            case 4:
                printf("\n\n");
                exit(0);


        }
    }
}

void musica()
{
    Beep(493,150);
    Beep(261,150);
    Beep(392,100);
}

void clearMap(int map[WIDTH][HEIGHT])
{
    for (int y = 0;y<HEIGHT; y++){
        for (int x = 0; x<WIDTH; x++){
            map[x][y] = '\0';
        }
    }
}

int isTarget(int x, int y, tTarget target[4])
{
    if(x == target[0].x && y == target[0].y) return 1;
    else if(x == target[1].x && y == target[1].y) return 1;
    else if(x == target[2].x && y == target[2].y) return 1;
    else if(x == target[3].x && y == target[3].y) return 1;
    else return 0;
}

void loadMap(int level, int map[WIDTH][HEIGHT], tTarget target[4])
{
    char pathFile[20];
    snprintf(pathFile, 20, "Maps/map-%i.txt", level);
    int countTarget = 0;

    FILE *mapFile;
    mapFile = fopen(pathFile, "r");

    if (mapFile == NULL){
        printf("Erro ao abrir o arquivo \n");
        exit(1);
    }else{
        char character;
        character = fgetc(mapFile);
        for(int x=0, y=0;!feof(mapFile); x++){
            switch(character){
                case '-':
                    map[x][y] = 0;
                    break;
                case 'o':
                    map[x][y] = OBSTACLES;
                    break;
                case '#':
                    map[x][y] = BORDER;
                    break;
                case 'x':
                    map[x][y]=0;
                    target[countTarget].x = x;
                    target[countTarget].y = y;
                    countTarget++;
                    break;
                case 'p':
                    map[x][y] = PLAYER;
                    break;
                case '1':
                    map[x][y] = 1;
                    break;
                case '2':
                    map[x][y] = 2;
                    break;
                case '3':
                    map[x][y] = 3;
                    break;
                case '4':
                    map[x][y] = 4;
                    break;
                default:
                    y++;
                    x=-1;
            }
            character = fgetc(mapFile);
        }
        fclose(mapFile);
    }
}

void printMap(int map[WIDTH][HEIGHT], tTarget target[4])
{
    moveCursor(0,0);
    for(int y=0;y<HEIGHT; y++){
        for (int x=0; x<WIDTH; x++){
            switch (map[x][y]){
                case 1:
                    FOREBLUE;
                    printf("%c ", 254);
                    style(RESETALL);
                    break;
                case 2:
                    FORERED;
                    printf("%c ", 254);
                    style(RESETALL);
                    break;
                case 3:
                    FOREGREEN;
                    printf("%c ", 254);
                    style(RESETALL);
                    break;
                case 4:
                    FOREYELLOW;
                    printf("%c ", 254);
                    style(RESETALL);
                    break;
                case PLAYER:
                    printf("%c ", PLAYER);
                    break;
                case BORDER:
                    if(x==0 && y==0) printf("%c%c", 201, 205);
                    else if(x==WIDTH-1 && y==0) printf("%c", 187);
                    else if(x==0 && y==HEIGHT-1) printf("%c%c", 200, 205);
                    else if(x==WIDTH-1 && y==HEIGHT-1) printf("%c", 188);
                    else if(x==0) printf("%c ", 186);
                    else if(x==WIDTH-1) printf("%c", 186);
                    else if(y==0 || y==HEIGHT-1) printf("%c%c", 205, 205);
                    break;
                default:
                    if(isTarget(x, y, target)) printf("%c ", TARGET);
                    else printf("%c ", map[x][y]);
            }
        }
        printf("\n");
    }
}

int moveBlock(int map[WIDTH][HEIGHT], tTarget target[4], int block, int direction)
{
    int moviment = 0, observer = 0;

    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            if(map[x][y]==block){
                switch(direction){
                    case 0:
                        if(map[x][y-1]==0 && isTarget(x, y, target) && moviment == 0){
                            Beep(100,100);
                            observer = 1;
                        }
                        if(map[x][y-1]==0){
                            map[x][y-1]=block;
                            map[x][y]=0;
                            Sleep(200);
                            printMap(map, target);
                            x=0;
                            y=0;
                            moviment++;
                        }
                        else if(isTarget(x, y, target) && moviment >= 1 ){
                            musica();
                            if(observer==0)return 1;
                            else return 0;
                        }
                        else if(isTarget(x, y, target) && moviment == 0){
                            return 0;
                        }
                        else if(observer == 1){
                            return -1;

                        }else{
                            return 0;

                        }
                        break;
                    case 1:
                        if(map[x+1][y]==0 && isTarget(x, y, target) && moviment == 0){
                            Beep(100,100);
                            observer = 1;
                        }
                        if(map[x+1][y]==0){
                            map[x+1][y]=block;
                            map[x][y]=0;
                            Sleep(200);
                            printMap(map, target);
                            x=0;
                            y=0;
                            moviment++;
                        }
                        else if(isTarget(x, y, target) && moviment >= 1){
                            musica();
                            if(observer==0)return 1;
                            else return 0;
                        }
                        else if(isTarget(x, y, target) && moviment == 0){
                            return 0;

                        }
                        else if(observer == 1){
                            return -1;

                        }else{
                            return 0;
                        }
                        break;
                    case 2:
                        if(map[x][y+1]==0 && isTarget(x, y, target) && moviment == 0){
                            Beep(100,100);
                            observer++;
                        }
                        if(map[x][y+1]==0){
                            map[x][y+1]=block;
                            map[x][y]=0;
                            Sleep(200);
                            printMap(map, target);
                            x=0;
                            y=0;
                            moviment++;
                        }
                        else if(isTarget(x, y, target) && moviment > 0){
                            musica();
                            if(observer==0)return 1;
                            else return 0;
                        }
                        else if(isTarget(x, y, target) && moviment == 0){
                            return 0;

                        }
                        else if(observer == 1){
                            return -1;

                        }else{
                            return 0;
                        }
                        break;

                    case 3:
                        if(map[x-1][y]==0 &&isTarget(x, y, target) && moviment == 0){
                            Beep(100,100);
                            observer++;
                        }
                        if(map[x-1][y]==0){
                            map[x-1][y]=block;
                            map[x][y]=0;
                            Sleep(200);
                            printMap(map, target);
                            x=0;
                            y=0;
                            moviment++;
                        }
                        else if(isTarget(x, y, target) && moviment > 0){
                            musica();
                            if(observer==0){return 1;}
                            else {return 0;}
                        }
                        else if(isTarget(x, y, target) && moviment == 0){
                            return 0;

                        }
                        else if(observer == 1){
                            return -1;

                        }else{
                            return 0;
                        }
                        break;
                }
            }
        }
    }
    return -1;
}

int getComand()
{
    char key;
    key = getch();
        if(key == -32){
            key = getch();
        }
    switch(key){
        case ARROW_UP:    return 0;
        case ARROW_RIGHT: return 1;
        case ARROW_DOWN:  return 2;
        case ARROW_LEFT:  return 3;
        case 'r':         return 4;
        case 'm':         return 5;
        case '6':         return 6;
    }
    return -1;
}

int movePlayer(int map[WIDTH][HEIGHT], int direction)
{
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            if(map[x][y]==PLAYER){
                switch(direction){
                    case 0:
                        if(map[x][y-1]==0){
                            map[x][y-1]=PLAYER;
                            map[x][y]=0;
                            return 0;
                        }else if(map[x][y-1]>=1 && map[x][y-1]<=4){
                            return map[x][y-1];
                        }else{
                            return 0;
                        }
                    case 1:
                        if(map[x+1][y]==0){
                            map[x+1][y]=PLAYER;
                            map[x][y]=0;
                            return 0;
                        }else if(map[x+1][y]>=1 && map[x+1][y]<=4){
                            return map[x+1][y];
                        }else{
                            return 0;
                        }
                    case 2:
                        if(map[x][y+1]==0){
                            map[x][y+1]=PLAYER;
                            map[x][y]=0;
                            return 0;
                        }else if(map[x][y+1]>=1 && map[x][y+1]<=4){
                            return map[x][y+1];
                        }else{
                            return 0;
                        }
                    case 3:
                        if(map[x-1][y]==0){
                            map[x-1][y]=PLAYER;
                            map[x][y]=0;
                            return 0;
                        }else if(map[x-1][y]>=1 && map[x-1][y]<=4){
                            return map[x-1][y];
                        }else{
                            return 0;
                        }
                }
            }
        }
    }
    return -1;
}

int rankingExists()
{
    FILE *test;
    test = fopen("Ranking/ranking.pzl", "r");
    if(test){
        fclose(test);
        return 1;
    }
    else return 0;
}

void createRanking()
{
    FILE *rf;
    tPlayer genericPlayer;
    strcpy(genericPlayer.name, "HotDog\0");
    genericPlayer.points = 600;
    mkdir("Ranking");

    rf = fopen("Ranking/ranking.pzl", "w");
    if(rf == NULL)
        printf("Falha ao criar ranking!");
    else{
        for(int i=0; i<10; i++){
            fwrite(&genericPlayer, sizeof(tPlayer), 1, rf);
            genericPlayer.points -= 50;
        }
        fclose(rf);
    }
}

void updateRanking(tPlayer player)
{
    tPlayer rankingPlayer;
    int count = 0;

    FILE *oldRanking;
    FILE *newRanking;

    oldRanking = fopen("Ranking/ranking.pzl", "rb");
    if(oldRanking == NULL){
        printf("\nFalha ao atualizar ranking!\n");
        return;
    }else{
        newRanking = fopen("Ranking/tempRanking.pzl", "w+b");
        if(newRanking == NULL){
            printf("\nFalha ao atualizar ranking!\n");
            return;
        }else{
            for(int i=0; i<10; i++){
                fread(&rankingPlayer, sizeof(tPlayer), 1, oldRanking);
                if(player.points > rankingPlayer.points && count == 0){
                    fwrite(&player, sizeof(tPlayer), 1, newRanking);
                    count++;
                }
                fwrite(&rankingPlayer, sizeof(tPlayer), 1, newRanking);
            }
            fclose(oldRanking);
            fclose(newRanking);
        }
    }
    remove("Ranking/ranking.pzl");
    rename("Ranking/tempRanking.pzl", "Ranking/ranking.pzl");
}

int main(void)
{
    if(!rankingExists()){
        createRanking();
    }

    int map[WIDTH][HEIGHT];
    tTarget target[4];

    while(1){
        menu();

        int points = 1200;
        int level = 1;
        int playing = 1;
        int collision = 0;
        int completeLevel=0;

        clearMap(map);
        loadMap(level, map, target);
        system("cls");

        while(playing){
            printMap(map, target);
            printf("\n\"r\" para reiniciar a fase\n\"m\" para retornar ao menu\n");
            int comand = getComand();
            if(comand == 6) level = 6;

            if(comand == -1){
                printf("comando invalido!");
            }else if(comand>=0 && comand<=3){
                printf("                  ");
                points -= 2;
                collision = movePlayer(map, comand);
                if(collision>=1 && collision<=4){
                    completeLevel += moveBlock(map, target, collision, comand);
                    if(completeLevel == 4){
                        level ++;
                        if (level!=7){
                                loadMap(level, map, target);
                        }else{
                            tPlayer player;
                            for(int i=0;i<11;i++){
                                player.name[i] = '\0';
                            }
                            printf("\nVoce completou todos os niveis!    \n");
                            if (points < 0) points =0;
                            points+=50;
                            printf("Sua pontuacao final foi de: %i       \n", points);
                            printf("Insira seu nome: ");
                            fflush(stdin);
                            fgets(player.name, 8, stdin);
                            player.name[strlen(player.name)-1] = '\0';
                            player.points = points;
                            updateRanking(player);
                            playing = 0;
                        }
                        completeLevel = 0;
                    }
                }
            }else if(comand == 4){
                clearMap(map);
                loadMap(level, map, target);
                completeLevel = 0;
            }else if(comand == 5){
                playing = 0;
            }
        }
    }


    return 0;
}

