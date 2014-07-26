#include <stdio.h>
#include <alloc.h>
#include <conio.h>

struct paddingtest
{
	char a;
	long b;
	char c;
	double d;
	char e;
};

typedef struct paddingtest * pt;
int main()
{

	pt p;
	clrscr();
	p=(pt) malloc(sizeof(struct paddingtest));
	printf("\nHello, world %u %u %u %u %u %d\n",\
	&p->a,&p->b,&p->c,&p->d,&p->e,sizeof(struct paddingtest));
	getch();
	return 0;
}
