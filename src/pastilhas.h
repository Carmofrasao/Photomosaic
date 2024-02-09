//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#ifndef _PASTILHAS_H
#define _PASTILHAS_H

//structs para RGB P6
typedef struct rgb
{
	unsigned char r, g, b;
}rgb;

//structs para imagens P6
typedef struct t_pastilha
{
	char tipo[2];
	int c_pred_r, c_pred_g, c_pred_b;
	int larg, alt;
	int max;
	rgb **pastilha;
}t_pastilha;

//structs para RGB P3
typedef struct rgb_p3
{
	int r, g, b;
}rgb_p3;


//structs para imagens P3
typedef struct t_pastilha_p3
{
	char tipo[2];
	int c_pred_r, c_pred_g, c_pred_b;
	int larg, alt;
	int max;
	rgb_p3 **pastilha;
}t_pastilha_p3;

void inicializar_pastilhas(t_pastilha* vpasti, int num_past);
//zera valores do vetor de pastilha

t_pastilha ler_pastilha(char* imagem);
//função para ler uma pastilha e retorna-la ao vetor de pastilha

void ler_diretorio(t_pastilha* vpasti, char *argv[], int argc);
//função para ler o diretorio que contem as pastilhas

int contar_pastilhas(char *argv[], int argc);
//função que conta o numero de pastilhas dentro do diretorio

#endif
