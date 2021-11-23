//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 
//esse programa foi feito pra criar fotomosaicos a partir de "pastilhas" composta por imagens no formato PPM

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pastilhas.h"
#include"imagem_principal.h"
#include"imagem_principal_p3.h"
#include"fotomosaico.h"
#include"fotomosaico_p3.h"

void iniciar_processamento(t_pastilha* vpasti, int num_past, char *argv[], int argc)
//funcao para gerar o fotomosaico
{
	FILE *nome_imagem = NULL;
	FILE *nome_saida = NULL;
	//defindo o nome da imagem de entrada e a de saida
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "-i") == 0)
		{
			nome_imagem = fopen(argv[i+1], "r");
		}
		if(strcmp(argv[i], "-o") == 0)
		{
			nome_saida = fopen(argv[i+1], "w+");
		}
	}
	if(nome_imagem == NULL)
	{
		nome_imagem = stdin;
	}
	if(nome_saida == NULL)
	{
		nome_saida = stdout;
	}
	
	char tipo[2];
	tipo[0] = '\0';
	tipo[1] = '\0';
	
	fscanf(nome_imagem, "%s", tipo);
	
	//definindo a maneira de processamento da imagem (P3 ou P6)
	if(strcmp(tipo, "P6") == 0)
	{
		fseek(nome_imagem, -sizeof(tipo), SEEK_CUR);
		t_pastilha ima_princi;
		ima_princi = ler_imagem_principal(nome_imagem);
		cria_foto(vpasti, ima_princi, num_past, nome_saida);
		for(int i = 0; i < ima_princi.alt; i++)
		{
			free(ima_princi.pastilha[i]);
		}
		free(ima_princi.pastilha);
	}
	else
	{
		fseek(nome_imagem, -sizeof(tipo), SEEK_CUR);
		t_pastilha_p3 ima_princi;
		ima_princi = ler_imagem_principal_p3(nome_imagem);
		cria_foto_p3(vpasti, ima_princi, num_past, nome_saida);
		for(int i = 0; i < ima_princi.alt; i++)
		{
			free(ima_princi.pastilha[i]);
		}
		free(ima_princi.pastilha);
	}
	
	//fechando arquivos (se necessario)
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "-i") == 0)
		{
			fclose(nome_imagem);
		}
		if(strcmp(argv[i], "-o") == 0)
		{
			fclose(nome_saida);
		}
	}
}

int main(int argc, char *argv[])
{   
	int num_past = 0;
	
	num_past = contar_pastilhas(argv, argc);
	
	//alocando memoria para o vetor de pastilha 
	t_pastilha* vpasti = (t_pastilha*) malloc(num_past*(sizeof(t_pastilha)));
	
	if(vpasti == NULL)
	{
		perror ("Memoria insuficiente");
	}
	
	inicializar_pastilhas(vpasti, num_past);
	ler_diretorio(vpasti, argv, argc);
	
	fprintf(stderr, "%d tiles read\n", num_past);
	fprintf(stderr, "Tile size is %dx%d\n", vpasti[0].larg, vpasti[0].alt);
	fprintf(stderr, "Calculating tiles' average colors\n");
	
	iniciar_processamento(vpasti, num_past, argv, argc);
	
	//liberando memorias alocadas
	for(int l = 0; l < num_past; l++)
	{
		for(int i = 0; i < vpasti[1].alt; i++)
		{
			free(vpasti[l].pastilha[i]);
		}
	}
	for(int i = 0; i < num_past; i++)
		free(vpasti[i].pastilha);
	free(vpasti);
}
