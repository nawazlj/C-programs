#include <stdio.h>
#include <conio.h>
#include <alloc.h>
/* Implementation of some standard string handling function in  changed manner */

int mystrlen(char *);
char *myupper(char *);
char *mystrcat(char *,char *);
char *mysubstr(char *,int,int);
int mystrcmp(char *, char *);
void main()
{
	char *str,*str1;
	int n;
	str=(char *) malloc(40);
	clrscr();
	puts("enter two string");
	gets(str);
	gets(str1);
	n=mystrlen(str);
	printf("the length of :%s: is %d\n",str,mystrlen(str));

	printf("The substring  is :%s:\n",mysubstr(str,4,5));

	if (mystrcmp(str,str1)==0)
		printf("matched");
	else
		printf("different");
	getch();
}

int mystrlen(char *s)
{
	int i=0;
	while( s[i]!='\0')
		i++;
	return i;
}

char *myupper(char *s)
{
	int i=0;
	char *s1;
	s1=(char *) malloc(mystrlen(s)+1);
	while (s[i]!='\0')
	{
		s1[i]=s[i];

		if (s1[i]>=97 && s1[i]<=122)
			s1[i]=s1[i]-32;
		i++;
	}
	s1[i]='\0';
	return s1;
}

char *mylower(char *s)
{
	int i=0;
	char *s1;
	s1=(char *) malloc(mystrlen(s)+1);
	while (s[i]!='\0')
	{
		s1[i]=s[i];

		if (s1[i]>=65 && s1[i]<=90)
			s1[i]=s1[i]+32;
		i++;
	}
	s1[i]='\0';
	return s1;
}
char *mystrcat(char *s1,char *s2)
{
	char *s3;
	int i,j;

	s3=(char *) malloc(mystrlen(s1)+mystrlen(s2)+1);

	for (i=0;i<mystrlen(s1);i++)
		s3[i]=s1[i];
	s3[i]=' ';
	i++;
	for (j=0;j<mystrlen(s2);j++,i++)
		s3[i]=s2[j];
	s3[i]='\0';

	return s3;
}

char *mysubstr(char *s,int p,int n)
{
	int i,k;
	char *s1;

	s1=(char *) malloc(n+1);
	k=mystrlen(s)-p;
	if (n>k)
		return NULL;

	for (i=0;i<n;i++)
		s1[i]=s[p+i];
	s1[i]='\0';
	return s1;
}

int mystrcmp(char *s1,char *s2)
{
	int i,n1,n2;
	n1=mystrlen(s1);
	n2=mystrlen(s2);
	if (n1!=n2)
		return 1;
	for (i=0;i<n1;i++)
		if (s1[i]!=s2[i])
			return 1;
	return 0;
}