
#define _CRT_SECURE_NO_WARNINGS
#define MAXLINE 1024
#include <stdio.h>


FILE *fin;
FILE *fout;
char line[MAXLINE];
char line1[MAXLINE];
char* ptr;
char* c;
int n = 0;
int counter = 0;
void edit() {
	while (!feof(fin)) {
		ptr = fgets(line, MAXLINE, fin);
		while (*ptr != '\0') {
			if (*ptr == '\n') {
				*ptr = ' ';
			}
			ptr++;
		}
		strcat(line1, line);
	}
}
int main(void) {
	fin = fopen("read.txt", "rt");
	fout = fopen("write.txt", "wt");
	if (fin == NULL || fout == NULL )
		return;
	printf("%s\n", "Print N: ");
	scanf_s("%d", &n);
	edit();
	fseek(fout, 0, SEEK_SET);
	
	while (!feof(fout)) {
		ptr = line1;
		c = ptr;
		if (ptr == NULL)
			break;
		while (*ptr != '\0') {
			if (counter++ == n) {
				ptr = c;
				*ptr++ = '\n';
				counter = 0;
			}
			if (*ptr == ' ') {
				c = ptr;
			}
			ptr++;
		}
		fputs(line1, fout);
		break;
	}
	fclose(fin);
	fclose(fout);
	
	return 0;
}

