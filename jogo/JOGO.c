#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define W 30
#define H 16
int x = 1, y = 1,tempo = 250,tempo1 = 250, pts = 0;
char map1[H][W] = 
{
    {7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8},
    {1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 5, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 1},
    {1, 0, 6, 6, 6, 2, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 6, 6, 6, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 6, 6, 6, 6, 6, 6, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 6, 6, 6, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 6, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 9, 6, 6, 6, 0, 1, 0, 0, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 6, 0, 1},
    {1, 6, 6, 6, 8, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 5, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 6, 6, 1, 6, 6, 6, 6, 2, 0, 0, 1, 6, 6, 6, 6, 2, 0, 1, 6, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 6, 6, 6, 6, 6, 6, 2, 0, 6, 6, 6, 6, 6, 2, 6, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 6, 6, 6, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 6, 6, 6, 6, 6, 6, 6, 6, 1},
    {1, 5, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 5, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1},
    {9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2}
};
char map2[H][W] = 
{
    {7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 8},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 3, 5, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 5, 1},
    {1, 0, 1, 0, 7, 6, 8, 0, 7, 6, 6, 2, 6, 6, 6, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 6, 6, 6, 6, 8, 0, 7, 6, 6, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 6, 6, 6, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 6, 2, 0, 1, 0, 1, 0, 6, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 9, 6, 6, 6, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 6, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 6, 6, 0, 1, 0, 1, 0, 0, 3, 6, 0, 0, 0, 0, 0, 0, 1},
    {1, 5, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 9, 6, 6, 6, 0, 0, 9, 6, 6, 6, 6, 1},
    {1, 0, 7, 6, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 5, 1, 6, 6, 6, 6, 6, 0, 9, 8, 0, 7, 6, 6, 0, 7, 6, 6, 6, 6, 0, 0, 7, 6, 6, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 6, 6, 6, 6, 6, 8, 0, 1, 0, 1, 0, 1, 0, 1, 0, 7, 6, 6, 0, 0, 1, 0, 6, 6, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 5, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 5, 1},
    {9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2}
};
void draw(int, int, char [H][W]);
void control(char map[H][W]);

int main(){
    int escolha, escolha1;
    FILE *file;
    char line[420];
    file = fopen("Entradajogo.txt", "r");
    fread(line,sizeof(line), 1, file);
    printf("%s", line);
    fclose(file);
    printf("\n\nIniciar [0->Nao|1->Sim]? ");
    scanf("%d", &escolha);
    fflush(stdin);
    if (escolha == 1){
        printf("\nNIVEL 1");
        Sleep(1000);
        while(pts != 30){
            draw(0,0, map1);
            control(map1);
            Sleep(100);
            printf("\nTempo = %d milisegundos", tempo);
            tempo--;
            if(tempo == 0){
                system("cls");
                FILE *fp;
                char lin[105];
                fp = fopen("tempo.txt", "r");
                fread(lin,sizeof(lin), 1, fp);
                printf("%s", lin);
                fclose(fp);
                Sleep(1000);
                break;
                }
        }
        if(pts == 30){
            printf("\nDeseja iniciar a fase 2 [0->Nao|1->Sim]? ");
            scanf("%d", &escolha1);
            fflush(stdin);
            if(escolha1 == 1){
            printf("NIVEL 2");
            Sleep(1000);
            while (pts != 60){
                draw(0,0, map2);
                control(map2);
                Sleep(100);
                printf("\nTempo = %d milisegundos", tempo1);
                tempo--;
                if(tempo == 0){
                    system("cls");
                    FILE *fl;
                    char li[105];
                    fl = fopen("tempo.txt", "r");
                    fread(li,sizeof(li), 1, fl);
                    printf("%s", li);
                    fclose(fl);
                    Sleep(1000);
                break;
                }
            }
            if (pts == 60){
                FILE *zerou;
                char tex[149];
                zerou = fopen("Zerou.txt", "r");
                fread(tex,sizeof(tex), 1, zerou);
                printf("%s", tex);
                fclose(zerou);
                }
            
            }
        }
    }
    return 0;
}

void draw(int py, int px, char map[H][W]){

    if (map[y + py][x + px] == 5)
    {
        pts += 5;
    }
    map[y][x] = 0;
    x += px;
    y += py;
    map[y][x] = 4;//personagem
    system("cls");//limpa tela
    for(char i = 0; i < H; i++)
    {
        for(char j = 0; j < W; j++)
        {
            switch (map[i][j])
            {
                case 0: printf(" ");       break;   //buraco
                case 1: printf("%c", 186); break;   //parede vert
                case 2: printf("%c", 188); break;   //canto pra direita baixo
                case 3: printf("%c", 16);  break;   //obstaculo
                case 4: printf("%c", 148); break;   //personagem
                case 5: printf("%c", 178); break;   //caixinha
                case 6: printf("%c", 205); break;   //parede horiz
                case 7: printf("%c", 201); break;   //canto pra esquerda cima
                case 8: printf("%c", 187); break;   //canto pra direita cima
                case 9: printf("%c", 200); break;   //canto pra esqueda baixo
         
            }        
        }
    printf("\n");
    }
}


void control(char map[H][W]){
    if(GetAsyncKeyState(VK_LEFT) && (map[y][x - 1] == 0 || map[y][x - 1] == 5))
    {
        draw(0, -1, map);
    }
    else if(GetAsyncKeyState(VK_RIGHT) && (map[y][x + 1] == 0 || map[y][x + 1] == 5))
    {
        draw(0, +1, map);
    }
    if(GetAsyncKeyState(VK_UP) && (map[y - 1][x] == 0 || map[y - 1][x] == 5))
    {
        draw(-1, 0, map);
    }
    if(GetAsyncKeyState(VK_DOWN) && (map[y + 1][x] == 0 || map[y + 1][x] == 5))
    {
        draw(1, 0, map);
    }
    if(GetAsyncKeyState(VK_ESCAPE))
    {
        exit(0);
    }
}