# fotomosaico
Trabalho feito para a matéria de programação 2, no curso de Ciencia da Computação, da Universidade Federal do Paraná.

Autor:
Frasão, A. A. C.

programa para gerar um fotomosaico.

Para ultilizar o programa, execute o comando make no terminal (dentro da pasta em que o código esta) e execute um desses comandos:

// entrada e saída em arquivos

> ./mosaico -i input.ppm  -o output.ppm
> ./mosaico -o output.ppm -i input.ppm

// entrada em arquivo, saída em stdout, vice-versa ou ambos

> ./mosaico -i input.ppm  > output.ppm
> ./mosaico -o output.ppm < input.ppm
> ./mosaico <  input.ppm  > output.ppm

// as opções podem estar em qualquer ordem

> ./mosaico -p /tmp/tiles -i input.ppm -o output.ppm
> ./mosaico -i input.ppm -p /tmp/tiles -o output.ppm
> ./mosaico -o output.ppm -i input.ppm -p /tmp/tiles

As pastilhas a usar para a construção do mosaico são imagens em formato PPM em um diretório separado (por default ./tiles/).
mas podem ser usadas outras pastilhas usando o comando a cima da forma correta.
