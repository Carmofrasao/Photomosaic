//programa feito por Anderson Aparecido do Carmo Frasão
//GRR20204069 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"pastilhas.h"

void zerar_fotomosaico(rgb **mosaico, int larg, int alt)
//função que zera o fotomosaico no formato P3 na saida padrão
{
	for(int lp = 0; lp < alt; lp++)
	{
		for(int cp = 0; cp < larg; cp++)
		{
			mosaico[lp][cp].r = '\0'; 
			mosaico[lp][cp].g = '\0'; 
			mosaico[lp][cp].b = '\0';
		}
	}
}

void imprimir_fotomosaico(rgb **mosaico, int larg, int alt, FILE *saida)
//função que imprime o fotomosaico no formato P6 na saida padrão
{
	fprintf(stderr, "Writing output file\n");
	for(int lp = 0; lp < alt; lp++)
	{
		for(int cp = 0; cp < larg; cp++)
		{
			fwrite(&mosaico[lp][cp].r, sizeof(unsigned char), 1, saida);
			fwrite(&mosaico[lp][cp].g, sizeof(unsigned char), 1, saida);
			fwrite(&mosaico[lp][cp].b, sizeof(unsigned char), 1, saida);
		}
	}
}

void cor_pred(t_pastilha ima_princi, int larg, int alt, int cpr, int lpr, int *auxr, int *auxg, int *auxb)
//função que calcula a cor predominante em cada bloco da imagem P6 da entrada padrão
{
	for(int cs = 0; cs < larg; cs++)
	{
		for(int ls = 0; ls < alt; ls++)
		{
			*auxr += ima_princi.pastilha[ls+lpr][cs+cpr].r*ima_princi.pastilha[ls+lpr][cs+cpr].r;
			*auxg += ima_princi.pastilha[ls+lpr][cs+cpr].g*ima_princi.pastilha[ls+lpr][cs+cpr].g;
			*auxb += ima_princi.pastilha[ls+lpr][cs+cpr].b*ima_princi.pastilha[ls+lpr][cs+cpr].b;
		}
	}
	int div = larg*alt;
	*auxr = sqrt(*auxr/div);
	*auxg = sqrt(*auxg/div);
	*auxb = sqrt(*auxb/div);
}

void preenche_matriz(t_pastilha* vpasti, t_pastilha ima_princi, rgb **m, int num_past)
//função qu preenche a matriz que se tornara o fotomosaico no formato P6
{
	int cont, tom, auxr, auxg, auxb;
	tom = 0;
	cont = 0;
	auxr = 0;
	auxg = 0;
	auxb = 0;
	
	for(int lpr = 0; lpr < ima_princi.alt-30; lpr += vpasti[1].alt)
	{
		for(int cpr = 0; cpr < ima_princi.larg-30; cpr += vpasti[1].larg)
		{
			cor_pred(ima_princi, vpasti[1].larg, vpasti[1].alt, cpr, lpr, &auxr, &auxg, &auxb);
			
			tom = 0;
			//percorrendo o vetor de pastilhas
			while(cont < num_past)
			{
				//if's usados para verificar qual pastilhar tem cor mais proxima do bloco da imagem principal
				if((auxr <= vpasti[cont].c_pred_r + tom) && (auxr >= vpasti[cont].c_pred_r - tom))
				{
					if((auxg <= vpasti[cont].c_pred_g + tom) && (auxg >= vpasti[cont].c_pred_g - tom))
					{
						if((auxb <= vpasti[cont].c_pred_b + tom) && (auxb >= vpasti[cont].c_pred_b - tom))
						{
							//preenchendo a matriz do fotomosaico
							for(int c = 0; c < vpasti[1].larg; c++)
							{
								for(int l = 0; l < vpasti[1].alt; l++)
								{
									m[lpr + l][cpr + c].r = vpasti[cont].pastilha[l][c].r;
									m[lpr + l][cpr + c].g = vpasti[cont].pastilha[l][c].g;
									m[lpr + l][cpr + c].b = vpasti[cont].pastilha[l][c].b;
								}
							}
							break;
						}
					}
				}
				cont++;
				if(cont >= num_past)
				{
					cont = 0;
					tom++;
				}
			}
			cont = 0;
			auxr = 0;
			auxg = 0;
			auxb = 0;
		}
	}
}

void cria_foto(t_pastilha* vpasti, t_pastilha ima_princi, int num_past, FILE *saida)
//função que aloca memoria para a matriz do fotomosaico no formato P6, e inicia a impreção das caracteristicas do mesmo
{
	rgb **m;
	
	fprintf(stderr, "Building mosaic image\n");

	//alocando memoria para a imagem
	m = malloc (ima_princi.alt * sizeof (rgb*));
	if(m == NULL)
	{
		perror ("Memoria insuficiente");
	}
	
	for(int i = 0; i < ima_princi.alt; i++)
	{
		m[i] = malloc (ima_princi.larg * sizeof (rgb));
		if(m[i] == NULL)
		{
			perror ("Memoria insuficiente");
		}
	}
	
	zerar_fotomosaico(m, ima_princi.larg, ima_princi.alt);
	preenche_matriz(vpasti, ima_princi, m, num_past);
	
	//iniciando a criacao do fotomosaico
	fprintf(saida, "%s\n", ima_princi.tipo);
	fprintf(saida, "%d %d\n", ima_princi.larg, ima_princi.alt);
	fprintf(saida, "%d\n", ima_princi.max);
	imprimir_fotomosaico(m, ima_princi.larg, ima_princi.alt, saida);
	for(int i = 0; i < ima_princi.alt; i++)
	{
		free(m[i]);
	}
	free(m);
}
