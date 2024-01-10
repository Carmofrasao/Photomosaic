# Photomosaic
Work done for the programming 2 subject in the Computer Science course at the Federal University of Paraná.

Made by Anderson Frasão

Objective

To generate a photomosaic.

Execution

To use the program, run the make command in the terminal (inside the folder where the code is) and execute one of these commands:

// input and output to files

> ./mosaico -i input.ppm -o output.ppm
> ./mosaico -o output.ppm -i input.ppm

// input to file, output to stdout, vice versa or both

> ./mosaico -i input.ppm > output.ppm
> ./mosaico -o output.ppm < input.ppm
> ./mosaico < input.ppm > output.ppm

// the options can be in any order

> ./mosaico -p /tmp/tiles -i input.ppm -o output.ppm
> ./mosaico -i input.ppm -p /tmp/tiles -o output.ppm
> ./mosaico -o output.ppm -i input.ppm -p /tmp/tiles

The tiles to be used for building the mosaic are images in PPM format in a separate directory (by default ./tiles/).
But you can use other tiles using the command above in the correct way.
