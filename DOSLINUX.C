#include <stdio.h>
#include <conio.h>

int main()
{
	clrscr();
	#ifdef __MSDOS__
		printf("Correct\n ");
	#else
		printf("In Correct\n");
	#endif
	getch();
	return 0;
}