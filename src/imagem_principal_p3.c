//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#include<stdio.h>
#include<stdlib.h>
#include"pastilhas.h"

void ler_imagem_p3(t_pastilha_p3 ima_princi, FILE *imagem)
//função que le a imagem P3 que foi passada via linha de comando
{
	for(int l = 0; l < ima_princi.alt; l++)
	{
		for(int c = 0; c < ima_princi.larg; c++)
		{
			fscanf(imagem, "%d%d%d", &ima_princi.pastilha[l][c].r, &ima_princi.pastilha[l][c].g, &ima_princi.pastilha[l][c].b);
		}
	}
}

t_pastilha_p3 ler_imagem_principal_p3(FILE *imagem)
//função que le as caracteristicas da imagem P3 que foi passada via linha de comando
{
	fprintf(stderr, "Reading input image\n");
	t_pastilha_p3 ima_princi;
	char ch = '\0';
	
	ima_princi.tipo[0] = '\0';
	ima_princi.tipo[1] = '\0';
	
	fscanf(imagem, "%s\n", ima_princi.tipo);
	
	fscanf(imagem, "%c", &ch);
	
	//pulando a linha do comentario
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
	
	fscanf(imagem, "%d %d\n%d\n", &ima_princi.larg, &ima_princi.alt, &ima_princi.max);
	fprintf(stderr, "Input image is PPM %s, %dx%d pixels\n", ima_princi.tipo, ima_princi.larg, ima_princi.alt);
	
	//alocando memoria para a imagem
	ima_princi.pastilha = (rgb_p3**) malloc(ima_princi.alt * sizeof(rgb_p3*));
	if(ima_princi.pastilha == NULL)
	{
		perror ("Memoria insuficiente");
	}
	for(int i = 0; i < ima_princi.alt; i++)
	{
		ima_princi.pastilha[i] = (rgb_p3*) malloc(ima_princi.larg * sizeof(rgb_p3));
		if(ima_princi.pastilha[i] == NULL)
		{
			perror ("Memoria insuficiente");
		}
	}
	
	ler_imagem_p3(ima_princi, imagem);
	
	return ima_princi;
}
