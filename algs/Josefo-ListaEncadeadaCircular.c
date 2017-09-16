/*Um pequeno ex�rcito se viu rodeado certa vez por um ex�rcito mais forte que ele.
A �nica chance para nao serem esmagados seria que alguem fosse buscar refor�o montado no �nico cavalo da tropa.
Para decidir quem seria o sortudo a ir buscar ajuda, decidiu-se colocar todos os soldados em um circulo,
sorteando-se entao um nome de um soldado e um numero M. A partir do soldado sorteado,
o  M-�simo soldado no sentido horario seria retirado da roda tendo que ficar no campo de batalha.
Procedendo-se desta forma, o �ltimo soldado que restasse no circulo seria aquele que iria buscar ajuda.
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    struct no {  //Cria��o da estrutura N� com o ponteiro PROX, para a cria��o da lista circular e a numera��o do soldado
        int idsoldado;
        struct no *prox;
    };
    struct no *p, *q; //Cria��o de ponteiros p e q para a lista circular
    int n, m; //Declara��o das vari�veis N e M. N=n�mero de soldados. M=Valor atribu�do ao M-�simo soldado retirado da roda

    int i, contagem;

    printf("Digite o numero de soldados: ");
    scanf("%d", &n); //Capta��o do n�mero de soldados
    printf("Digite M (M-esimo soldado): ");
    scanf("%d", &m); //Capta��o do M-�simo soldado retirado do circulo.

    p = q = malloc(sizeof(struct no)); // Cria��o da lista circular encadeada contendo todos os soldados - aloca��o na mem�ria
    p->idsoldado = 1; // O ponteiro P recebe o valor da variavel soldado = 1. Logo, este � o valor do mesmo.
    for (i = 2; i <= n; ++i) { // Incrimentar i enquanto o numero de soldados for menor ou igual ao mesmo, sendo que este inicia em 2.
        p->prox = malloc(sizeof(struct no)); // Alocar o ponteiro P com o ponteiro prox, com o tamanho da estrutura "no".
        p = p->prox; // P � igual ao redirecionamento de P para PROX
        p->idsoldado = i; // Redirecionar P para soldado igual ao valor de i.
    }

    p->prox = q;   // Aqui fechamos a lista circular, pois estamos direcionando o �ltimo ponteiro (p) para o primeiro (q).

    for (contagem = n; contagem > 1; --contagem) { // Decrementar a contagem(=n) enquanto a contagem for maior que 1.
       for (i = 0; i < m - 1; ++i) // Incrementar i enquanto i for menor que o valor m
          p = p->prox; // Enquanto o la�o FOR estiver ocorrendo, direcionar o ponteiro P para o pr�ximo elemento da lista.

       p->prox = p->prox->prox;  // Remover o soldado correspondente ao M-�simo n�mero em quest�o da lista circular
    }

    printf("Soldado que buscara ajuda: Soldado Numero %d\n.", p->idsoldado);  //Exibir qual soldado buscara ajuda, atrav�s do ponteiro criado.

    return 0;
}
