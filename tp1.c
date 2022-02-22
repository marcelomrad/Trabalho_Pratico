#include <stdio.h>
#define TMAX 16

int main()
{
    int tamanho_tab;
    char entrada[TMAX];
    fgets(entrada, TMAX, stdin);
    sscanf(entrada, "%d" , &tamanho_tab);
    char tabuleiro[TMAX][TMAX];

    for (int i = 0; i < tamanho_tab; i++)
    {
        fgets(tabuleiro[i], TMAX, stdin);
    }   
    //transformar dama Branca antes do jogo começar
    for (int j = 0; j < tamanho_tab; j++)
    {
        if(tabuleiro[0][j] == 'b')
            tabuleiro[0][j] = 'B';
    }
    //transformar dama Preta antes do jogo começar
    for (int j = 0; j < tamanho_tab; j++)
    {
        if(tabuleiro[tamanho_tab-1][j] == 'p')
            tabuleiro[tamanho_tab-1][j] = 'P';
    }
    
    int x1, y1, x2, y2;  //coordenadas (x1,y1) (x2,y2)
    int Rp=0, Rb=0;      // pontuação
        
    do
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 

        //Peça Preta(p)
        if(tabuleiro[x1][y1] == 'p')
        {
            //movimentação das peças pretas
            if((x2 == x1+1 && y2 == y1+1) &&  tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'p';
                tabuleiro[x1][y1] = 'o';
            }
            if((x2 == x1+1 && y2 == y1-1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'p';
                tabuleiro[x1][y1] = 'o';
            }             
            //movimento de captura que a peça preta faz (diagonal direita)
            if((x2 == x1+2 && y2 == y1+2) && (tabuleiro[x1+1][y1+1] == 'b' || 
               tabuleiro[x1+1][y1+1] == 'B' ) && tabuleiro[x1+2][y1+2] == 'o')
            {
                Rp++;
                tabuleiro[x2][y2] = 'p';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1+1][y1+1] = 'o';
            }

            //movimento de captura que a peça preta faz (diagonal esquerda)
            if((x2 == x1+2 && y2 == y1-2) && (tabuleiro[x1+1][y1-1] == 'b' ||
               tabuleiro[x1+1][y1-1] == 'B')  && tabuleiro[x1+2][y1-2] == 'o')
            {
                Rp++;
                tabuleiro[x2][y2] = 'p';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1+1][y1-1] = 'o';
            } 
            //transformação peça preta em dama
            if(x2 == tamanho_tab-1)
            {
                Rp++;
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o'; 
            }
        }

        //Dama Preta (P)
        if(tabuleiro[x1][y1] == 'P')
        {    
            //movimentação Dama Preta
             if((x2 == x1+1 && y2 == y1+1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';
            }
            if((x2 == x1+1 && y2 == y1-1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';
            } 
            if((x2 == x1-1 && y2 == y1+1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';
            }
            if((x2 == x1-1 && y2 == y1-1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';  
            }                          
            //movimento de captura que a dama Preta faz (diagonal esquerda superior)
            if((x2 == x1-2 && y2 == y1-2) && (tabuleiro[x1-1][y1-1] == 'b' || 
                tabuleiro[x1-1][y1-1] == 'B') && tabuleiro[x1-2][y1-2] == 'o')
            {
                Rp++;
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1-1][y1-1] = 'o';
            }
            //movimento de captura que a dama preta faz (diagonal direita superior)
            if((x2 == x1-2 && y2 == y1+2) && (tabuleiro[x1-1][y1+1] == 'b' ||
                tabuleiro[x1-1][y1+1] == 'B') && tabuleiro[x1-2][y1+2] == 'o')
            {
                Rp++;
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1-1][y1+1] = 'o';
            }
            //movimento de captura que a dama preta faz (diagonal direita inferior)
            if((x2 == x1+2 && y2 == y1+2)  && (tabuleiro[x1+1][y1+1] == 'b' || 
                tabuleiro[x1+1][y1+1] == 'B')  && tabuleiro[x1+2][y1+2] == 'o')
            {
                Rp++;
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1+1][y1+1] = 'o';
            } 
            //movimento de captura que a Dama preta faz (diagonal esquerda inferior)
            if((x2 == x1+2 && y2 == y1-2) && (tabuleiro[x1+1][y1-1] == 'b' ||
                tabuleiro[x1+1][y1-1] == 'B')  && tabuleiro[x1+2][y1-2] == 'o')
            {
                Rp++;
                tabuleiro[x2][y2] = 'P';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1+1][y1-1] = 'o';
            }
        }
        //Peça Branca(b) 
        if(tabuleiro[x1][y1] == 'b')
        {   
            //movimentação peças Brancas
             if((x2 == x1-1 && y2 == y1+1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'b';
                tabuleiro[x1][y1] = 'o';
            }
            if((x2 == x1-1 && y2 == y1-1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'b';
                tabuleiro[x1][y1] = 'o';  
            }            
            //movimento de captura que a peça branca faz (diagonal esquerda)
            if((x2 == x1-2 && y2 == y1-2)  && (tabuleiro[x1-1][y1-1] == 'p' ||
                tabuleiro[x1-1][y1-1] == 'P')  && tabuleiro[x1-2][y1-2] == 'o')
            {
                Rb++;
                tabuleiro[x2][y2] = 'b';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1-1][y1-1] = 'o';
            }
            //movimento de captura que a peça branca faz (diagonal direita)
            if((x2 == x1-2 && y2 == y1+2) && (tabuleiro[x1-1][y1+1] == 'p' ||
                tabuleiro[x1-1][y1+1] == 'P')  && tabuleiro[x1-2][y1+2] == 'o')
            {
                Rb++;
                tabuleiro[x2][y2] = 'b';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1-1][y1+1] = 'o';
            }    
            //transformação de peça em dama branca (diagonal esquerda)
            if(x2 == 0)
            {
                Rb++;
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
            }
        }   
        //Dama Branca(B)
        if(tabuleiro[x1][y1] == 'B')
        {   
            //Movimentos Dama Branca
             if((x2 == x1+1 && y2 == y1+1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
            }
            if((x2 == x1+1 && y2 == y1-1)  && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
            } 
            if((x2 == x1-1 && y2 == y1+1) && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
            }
            if((x2 == x1-1 && y2 == y1-1)  && tabuleiro[x2][y2] == 'o')
            {
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o'; 
            } 
            //movimento de captura que a dama branca faz (diagonal direita)
            if((x2 == x1+2 && y2 == y1+2) && (tabuleiro[x1+1][y1+1] == 'p' ||
                tabuleiro[x1+1][y1+1] == 'P') && tabuleiro[x1+2][y1+2] == 'o' )
            {
                Rb++;
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1+1][y1+1] = 'o';
            }
            //movimento de captura que a dama branca faz (diagonal esquerda)
            if((x2 == x1+2 && y2 == y1-2) && (tabuleiro[x1+1][y1-1] == 'p' ||
                tabuleiro[x1+1][y1-1] == 'P') && tabuleiro[x1+2][y1-2] == 'o')
            {
                Rb++;
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1+1][y1-1] = 'o';
            }
            //movimento de capatura que a Dama Branca faz (diagonal esquerda)
            if((x2 == x1-2 && y2 == y1-2) && (tabuleiro[x1-1][y1-1] == 'p' ||
                tabuleiro[x1-1][y1-1] == 'P')  && tabuleiro[x1-2][y1-2] == 'o' )
            {
                Rb++;
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1-1][y1-1] = 'o';
            }
            //movimento de captura que a Dama branca faz (diagonal direita)
            if((x2 == x1-2 && y2 == y1+2) && (tabuleiro[x1-1][y1+1] == 'p' ||
                tabuleiro[x1-1][y1+1] == 'P')  && tabuleiro[x1-2][y1+2] == 'o')
            {
                Rb++;
                tabuleiro[x2][y2] = 'B';
                tabuleiro[x1][y1] = 'o';
                tabuleiro[x1-1][y1+1] = 'o';
            }    
        }

    } while (x1!=0 || y1!=0 || x2!=0 || y2!=0);

     if(Rp > Rb)
       printf("PRETAS %d\nBRANCAS %d\nPRETAS VENCERAM ", Rp, Rb);
    else if(Rb > Rp)
       printf("PRETAS %d\nBRANCAS %d\nBRANCAS VENCERAM ", Rp, Rb);
    else
        printf("PRETAS %d\nBRANCAS %d\nEMPATE ", Rp, Rb);

    return 0;
}
