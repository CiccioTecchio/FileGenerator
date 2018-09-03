#include <stdio.h>
#include <stdlib.h>

int numFile;
int maxWord;
FILE *fpw;
int line;

void checkArgs(int argc, char* argv[]);


int main (int argc, char* argv[]){
	checkArgs(argc,argv);
	FILE *fp;
	FILE *fpi;


	fpi = fopen("index.txt","w");

	for(int i=0; i < numFile; i++ ){
		char fileName [30]; 
		sprintf(fileName,"file%d.txt",i);
		fprintf(fpi, "%s\n",fileName);		
		fp = fopen(fileName,"w");
		int numWord = rand() % maxWord + 1;
		
		for(int j=0;j<numWord;j++){
			int rowNum = rand() % line +1;
			int index=0;	
			char buf[50];
			while(index < rowNum){
				fscanf(fpw,"%s",buf);			
				index++;
			}
			fprintf(fp, "%s\n",buf );
			fseek(fpw, 0, SEEK_SET);
		}		
	}
	fclose(fpi);
	fclose(fpw);
	fclose(fp);
	return 0;
}

void checkArgs(int argc, char* argv[]){
	if(argc!=5){
		printf("Enter <number of files to generate> <maximum number of words for each file> <dictionary name> <line of dictionary>\n");
		exit(0);
	}else{
				numFile = atoi(argv[1]);
				maxWord = atoi(argv[2]);
				fpw = fopen(argv[3],"r");
				line = atoi(argv[4]);
			if(numFile <= 0 || maxWord <= 0 || line <= 0 || !fpw){
			printf("Make sure that:\n1)the number of files is positive;\n2)the maximum number of words per file is positive;\n3)the file exists;\n4)the number of dictionary words is positive.\n");
			exit(0);
			}
	}
}