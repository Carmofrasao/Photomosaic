//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#ifndef _FOTOMOSAICO_P3_H
#define _FOTOMOSAICO_P3_H

#include"pastilhas.h"

void zerar_fotomosaico_p3(rgb_p3 **mosaico, int larg, int alt);
//zerando a matriz para criar o fotomosaico

void imprimir_fotomosaico_p3(rgb_p3 **mosaico, int larg, int alt, FILE *saida);
//função que imprime o fotomosaico no formato P3 na saida padrão

void cor_pred_p3(t_pastilha_p3 ima_princi, int larg, int alt, int cpr, int lpr, int *auxr, int *auxg, int *auxb);
//função que calcula a cor predominante em cada bloco da imagem P3 da entrada padrão

void preenche_matriz_p3(t_pastilha* vpasti, t_pastilha_p3 ima_princi, rgb_p3 **m, int num_past);
//função qu preenche a matriz que se tornara o fotomosaico no formato P3

void cria_foto_p3(t_pastilha* vpasti, t_pastilha_p3 ima_princi, int num_past, FILE *saida);
//função que aloca memoria para a matriz do fotomosaico no formato P3, e inicia a impreção das caracteristicas do mesmo

#endif
