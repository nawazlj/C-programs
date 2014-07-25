#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp,*fp1;
	char ch;

	if (argc!=3)
	{
		printf("ERROR !!! usage: %s sourceFile destFile",argv[0]);
		exit(1);
	}

	fp=fopen(argv[1],"r");
	if (fp==NULL)
	{
		printf("cannot open the file");
		exit(2);
	}

	fp1=fopen(argv[2],"w");
	if (fp1==NULL)
	{
		printf("cannot open the file");
		fclose(fp);
		exit(3);
	}

	while((ch=fgetc(fp))!=EOF)
		fputc(ch,fp1);

	fclose(fp);
	fclose(fp1);

	return 0;
}
