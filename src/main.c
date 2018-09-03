#include <stdio.h>
#include <stdlib.h>

int numFile;
int maxWord;

void checkArgs(int argc, char* argv[]);


int main (int argc, char* argv[]){
	checkArgs(argc,argv);
	FILE *fp;
	FILE *fpw;
	FILE *fpi;

	fpw = fopen("parole.txt","r");
	fpi = fopen("index.txt","w");

	for(int i=0; i < numFile; i++ ){
		char fileName [30]; 
		sprintf(fileName,"file%d.txt",i);
		fprintf(fpi, "%s\n",fileName);		
		fp = fopen(fileName,"w");
		int numWord = rand() % maxWord + 1;
		
		for(int j=0;j<numWord;j++){
			int rowNum = rand() % 1160 +1;
			int index=0;	
			char buf[50];
			while(index < rowNum ){
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
	if(argc!=3){
		printf("Enter <number of files to generate> and <maximum number of words for each file>\n");
		exit(0);
	}else{
				numFile = atoi(argv[1]);
				maxWord = atoi(argv[2]);
			if(numFile <= 0 && maxWord <= 0){					
				printf("The number of files or the maximum number of words per file can only be positive\n");
				exit(0);
			}
	}}