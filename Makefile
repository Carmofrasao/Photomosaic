#makefile para o programa fotomosaico, para a materia programação 2 (CI-1002)
#feito por Anderson Aparecido do Carmo Frasão
#GRR 20204069

CFLAGS = -Wall -std=gnu99
LDLIBS = -lm

objs = main.o fotomosaico.o fotomosaico_p3.o imagem_principal.o \
		imagem_principal_p3.o pastilhas.o

all: mosaico

mosaico: $(objs)
		cc -o mosaico $(objs) $(LDLIBS)
	
main.o:	main.c fotomosaico.h fotomosaico_p3.h imagem_principal.h imagem_principal_p3.h pastilhas.h
fotomosaico.o: fotomosaico.c fotomosaico.h pastilhas.h
fotomosaico_p3.o: fotomosaico_p3.c fotomosaico_p3.h pastilhas.h
imagem_principal.o: imagem_principal.c imagem_principal.h pastilhas.h
imagem_principal_p3.o: imagem_principal_p3.c imagem_principal_p3.h pastilhas.h
pastilha.o: pastilhas.c pastilhas.h
			
clean:
	-rm -f *.o *~ 
	
purge: clean
	-rm -f mosaico
