//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#ifndef _IMAGEM_PRINCIPAL_H
#define _IMAGEM_PRINCIPAL_H

#include"pastilhas.h"

void ler_imagem(t_pastilha ima_princi, FILE *imagem);
//função que le a imagem P6 que foi passada via linha de comando 

t_pastilha ler_imagem_principal(FILE* imagem);
//função que le as caracteristicas da imagem P6 que foi passada via linha de comando

#endif
