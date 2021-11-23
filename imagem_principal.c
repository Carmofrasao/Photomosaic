//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#include<stdio.h>
#include<stdlib.h>
#include"pastilhas.h"

void ler_imagem(t_pastilha ima_princi, FILE* imagem)
//função que le a imagem P6 que foi passada via linha de comando
{
	unsigned char aux = '\0';
	fread(&aux, sizeof(unsigned char), 1, imagem);
	for(int l = 0; l < ima_princi.alt; l++)
	{
		for(int c = 0; c < ima_princi.larg; c++)
		{
			fread(&ima_princi.pastilha[l][c].r, sizeof(unsigned char), 1, imagem);
			fread(&ima_princi.pastilha[l][c].g, sizeof(unsigned char), 1, imagem);
			fread(&ima_princi.pastilha[l][c].b, sizeof(unsigned char), 1, imagem);
		}
	}
}

t_pastilha ler_imagem_principal(FILE* imagem)
//função que le as caracteristicas da imagem P6 que foi passada via linha de comando
{
	fprintf(stderr, "Reading input image\n");
	t_pastilha ima_princi;
	char ch = '\0';
	
	ima_princi.tipo[0] = '\0';
	ima_princi.tipo[1] = '\0';
	
	fscanf(imagem, "%s", ima_princi.tipo);
	
	fscanf(imagem, "%c", &ch);
	
	//pulando linha do comentario
	if(ch == '#')
	{
		while((ch = fgetc(imagem)) != EOF)
		{
    		if(ch == '\n') 
    		{
    			if ((ch = fgetc(imagem)) != '#')
    				break;
    		}
		}
	}
	fseek(imagem, -sizeof(ch), SEEK_CUR);
	
	fscanf(imagem, "%d%d%d", &ima_princi.larg, &ima_princi.alt, &ima_princi.max);
	fprintf(stderr, "Input image is PPM %s, %dx%d pixels\n", ima_princi.tipo, ima_princi.larg, ima_princi.alt);
	
	//alocando memoria para a imagem
	ima_princi.pastilha = (rgb**) malloc(ima_princi.alt * sizeof(rgb*));
	if(ima_princi.pastilha == NULL)
	{
		perror ("Memoria insuficiente");
	}
	for(int i = 0; i < ima_princi.alt; i++)
	{
		ima_princi.pastilha[i] = (rgb*) malloc(ima_princi.larg * sizeof(rgb));
		if(ima_princi.pastilha[i] == NULL)
		{
			perror ("Memoria insuficiente");
		}
	}
	
	ler_imagem(ima_princi, imagem);
	
	return ima_princi;
}
