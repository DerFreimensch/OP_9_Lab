
#define _CRT_SECURE_NO_WARNINGS
#define MAXLINE 1024
#include <stdio.h>


FILE *fin;
FILE *fout;
FILE* fout1;
char line[MAXLINE];
char* ptr;
char* c;
int N = 0;
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
		fputs(line, fout1);
	}
}
int main(void) {
	fin = fopen("read.txt", "rt");
	fout = fopen("write.txt", "wt");
	fout1 = fopen("rw.txt", "w+t");
	if (fin == NULL || fout == NULL || fout1 == NULL)
		return;
	printf("%s\n", "Print N: ");
	scanf_s("%d", &N);
	edit();
	fseek(fout1, 0, SEEK_SET);
	while (!feof(fout1)) {
		ptr = fgets(line, MAXLINE, fout1);
		c = ptr;
		if (ptr == NULL)
			break;
		while (*ptr != '\0') {
			if (counter++ == N) {
				ptr = c;
				*ptr++ = '\n';
				counter = 0;
			}
			if (*ptr == ' ') {
				c = ptr;
			}
			ptr++;
		}
		fputs(line, fout);
	}
	fclose(fin);
	fclose(fout);
	fclose(fout1);
	remove("rw.txt");
	return 0;
}

