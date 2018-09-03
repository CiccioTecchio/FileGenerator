# FileGenerator 
Given the number of files, the maximum number of words that can be contained in a file, a dictionary written line by line as **parole.txt** and the number of lines contained in the dictionary. Generate files containing at most the number of words specified in the dictionary, the name all the generated files is written in **index.txt**.  
The used dictionaries can be found [here](https://github.com/napolux/paroleitaliane).  
## Prerequisites
The dictionary file must contain one word per line.  
## How to run
Compile **main.c** with
```bash
gcc main.c
```
Run **a.out**
```bash
./a.out <number of file to generate> <maximum number of words per file> <name of dictionary file> <number of dictionary lines>
```
