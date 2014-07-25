#include <stdio.h>
int main ()
{
	int grade, aCount, bCount, cCount, dCount, fCount ;
	aCount = bCount = cCount = dCount = fCount = 0 ;
	while (  (grade = getchar( ) )  !=  EOF )
	{
		 switch ( grade )
		 {
				case 'A':  aCount++;  break ;
				case 'B':  bCount++;  break ;
				case 'C' : cCount++;  break ;
				case 'D':  dCount++; break ;
				case 'F':  fCount++;  break ;
				default :  break ;
		 }

	}
	printf("%d%d%d%d%d",aCount, bCount, cCount, dCount, fCount);
	getch();
	return 0 ;
}