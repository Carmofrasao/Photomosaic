//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#include"pastilhas.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<dirent.h>

void inicializar_pastilhas(t_pastilha* vpasti, int num_past)
//funcao para zerar as caracteristicas da imagem
{
	for(int i = 0; i < num_past; i++)
	{
		vpasti[i].tipo[0] = '\0';
		vpasti[i].tipo[1] = '\0';
		vpasti[i].larg = 0;
		vpasti[i].alt = 0;
		vpasti[i].max = 0;
		vpasti[i].c_pred_r = 0;
		vpasti[i].c_pred_g = 0;
		vpasti[i].c_pred_b = 0;
	}
}

t_pastilha ler_pastilha(char *imagem)
//função para ler uma pastilha e retorna-la ao vetor de pastilha
{
	char ch = '\0';
	FILE *arq;
	arq = fopen(imagem, "r");
	t_pastilha pasti;
	pasti.c_pred_r = 0;
	pasti.c_pred_g = 0;
	pasti.c_pred_b = 0;
	
	if (!arq)
	{
		perror("ERRO");
		exit(1);
	}
	
	fscanf(arq, "%s\n", pasti.tipo);
	
	fscanf(arq, "%c", &ch);
	
	//pular linha de comentario
	if(ch == '#')
	{
		while((ch = fgetc(arq)) != EOF)
		{
    		if(ch == '\n') 
    		{
    			if ((ch = fgetc(arq)) != '#')
    				break;
    		}
		}
	}
	fseek(arq, -sizeof(ch), SEEK_CUR);
	
	fscanf(arq, "%d %d\n%d\n", &pasti.alt, &pasti.larg, &pasti.max);
	
	//alocando memoria para imagem
	pasti.pastilha = (rgb**) malloc(pasti.alt * sizeof(rgb*));
	if(pasti.pastilha == NULL)
	{
		perror ("Memoria insuficiente");
	}
	for(int i = 0; i < pasti.alt; i++)
	{
		pasti.pastilha[i] = (rgb*) malloc(pasti.larg * sizeof(rgb));
		if(pasti.pastilha[i] == NULL)
		{
			perror ("Memoria insuficiente");
		}
	}
	
	//zerar matriz para imagem
	for(int c = 0; c < pasti.larg; c++)
	{
		for(int l = 0; l < pasti.alt; l++)
		{
			pasti.pastilha[l][c].r = '\0'; 
			pasti.pastilha[l][c].g = '\0';
			pasti.pastilha[l][c].b = '\0';
		}
	}
	
	for(int l = 0; l < pasti.alt; l++)
	{
		for(int c = 0; c < pasti.larg; c++)
		{
			fscanf(arq, "%c%c%c", &pasti.pastilha[l][c].r, &pasti.pastilha[l][c].g, &pasti.pastilha[l][c].b);
			pasti.c_pred_r += pasti.pastilha[l][c].r*pasti.pastilha[l][c].r;
			pasti.c_pred_g += pasti.pastilha[l][c].g*pasti.pastilha[l][c].g;
			pasti.c_pred_b += pasti.pastilha[l][c].b*pasti.pastilha[l][c].b;
		}
	}
	
	//calculando cor predominante da imagem
	pasti.c_pred_r = sqrt(pasti.c_pred_r/(pasti.alt*pasti.larg));
	pasti.c_pred_g = sqrt(pasti.c_pred_g/(pasti.alt*pasti.larg));
	pasti.c_pred_b = sqrt(pasti.c_pred_b/(pasti.alt*pasti.larg));
	fclose(arq);
	return pasti;
}

void ler_diretorio(t_pastilha* vpasti, char *argv[], int argc)
//função para ler o diretorio que contem as pastilhas
{
	//definindo o nome do diretorio
	char *nome_dir = NULL;
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "-p") == 0)
			nome_dir = argv[i+1]; 
	}
	if(nome_dir == NULL)
	{
		nome_dir = "tiles";
	}
	
	fprintf(stderr, "Reading tiles from %s\n", nome_dir);
	char *nomefinal;
	int i = 0;
	DIR *d;
	struct dirent *dir;
	d = opendir(nome_dir);
	if(d)
	{
		//lendo o diretorio
		rewinddir(d);
		while((dir = readdir(d)) != NULL)
		{
			if(dir->d_type == DT_REG)
			{	
				nomefinal = (char*) malloc(sizeof(nome_dir) + sizeof(dir->d_name));
				if(nomefinal == NULL)
				{
					perror ("Memoria insuficiente");
				}
				sprintf(nomefinal, "%s/%s", nome_dir, dir->d_name);
				vpasti[i] = ler_pastilha(nomefinal);
				free(nomefinal);
				i++;
			}
		}
		closedir(d);
	}
	else
	{
  		perror ("Não foi possível abrir o diretório");
      	exit (1);
   	}
}

int contar_pastilhas(char *argv[], int argc)
//função que conta o numero de pastilhas dentro do diretorio
{
	char *nome_dir = NULL;
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "-p") == 0)
			nome_dir = argv[i+1]; 
	}
	if(nome_dir == NULL)
	{
		nome_dir = "tiles";
	}

	int num_past = 0;
	DIR *d;
	struct dirent *dir;
	d = opendir(nome_dir);
	if(d)
	{
		while((dir = readdir(d)) != NULL)
		{
			if(dir->d_type == DT_REG)
			{
				num_past++;
			}
		}
	}
	closedir(d);
	return num_past;
}
