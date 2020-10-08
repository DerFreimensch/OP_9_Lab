
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLINE 1024
FILE *fin;
FILE *fout;
int main(void) {
	char line[MAXLINE];
	char* ptr;
	char c;
	int N= 0;
	int counter = 0;
	fin = fopen("read.txt", "rt");
	fout = fopen("write.txt", "wt");
	if (fin == NULL || fout == NULL)
		return;
	scanf("%d", &N);
	while (!feof(fin)) {
		ptr = fgets(line, MAXLINE, fin);
		c = *ptr;
		if (ptr == NULL)
			break;
		while (counter++ != N) {
			
		}
		*ptr++ = '\n';
		ptr++;
	}
	fclose(fin);
	fclose(fout);
	return 0;

}
