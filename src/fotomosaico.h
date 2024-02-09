//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#ifndef _FOTOMOSAICO_H
#define _FOTOMOSAICO_H

#include"pastilhas.h"

void zerar_fotomosaico(rgb **mosaico, int larg, int alt);
//zerando a matriz para criar o fotomosaico

void imprimir_fotomosaico(rgb **mosaico, int larg, int alt, FILE *saida);
//função que imprime o fotomosaico no formato P6 na saida padrão

void cor_pred(t_pastilha ima_princi, int larg, int alt, int cpr, int lpr, int *auxr, int *auxg, int *auxb);
//função que calcula a cor predominante em cada bloco da imagem P6 da entrada padrão

void preenche_matriz(t_pastilha* vpasti, t_pastilha ima_princi, rgb **m, int num_past);
//função qu preenche a matriz que se tornara o fotomosaico no formato P6

void cria_foto(t_pastilha* vpasti, t_pastilha ima_princi, int num_past, FILE *saida);
//função que aloca memoria para a matriz do fotomosaico no formato P6, e inicia a impreção das caracteristicas do mesmo

#endif
