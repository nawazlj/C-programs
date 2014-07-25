#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	FILE *out;

	char another,choice;

	struct emp {
		char name[40];
		int age;
		float bs;
	};

	struct emp e;
	char empname[40];

	int recsize;

	char buffer[25];

	clrscr();

	fp=fopen("emp.dat","rb+");

	if (fp==NULL)
	{
		fp=fopen("emp.dat","wb+");
		if (fp==NULL)
		{
			printf("Cannot open the main file");
			exit(1);
		}
	}


	recsize=sizeof(e);

	while(1)
	{
		printf("\n1. Add Records");
		printf("\n2. List Records");
		printf("\n3. Modify Records");
		printf("\n4. Delete Records");
		printf("\n5. Exit");
		printf("\nEnter Your Choice");
		fflush(stdin);
		choice=getche();

		switch(choice)
		{
			case '1':
				fseek(fp,0,SEEK_END);
				another='Y';
				while(another=='y' || another=='Y')
				{
					printf("\nEnter name , age and basic Salary");
					scanf("%s%d%f",e.name,&e.age,&e.bs);
					//	fprintf(fp,"%s%d%f",e.name,e.age,e.bs);
					fwrite(&e,recsize,1,fp);
					printf("\nAdd Another Reccord(Y/N)");
					fflush(stdin);
					another=getche();
				}
				break;
			case '2':
				rewind(fp);
				//fseek(fp,0,SEEK_SET);

				while(fread(&e,recsize,1,fp)==1)
				printf("%s %d %f\n",e.name,e.age,e.bs);
				break;
			case '3':
				another='y';
				while(another=='y' || another=='Y')
				{
					printf("\nEnter the name of employee to modify");
					scanf("%s",empname);

					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if (strcmp(e.name,empname)==0)
						{
							printf("\nEnter new name, age, basic "\
							"salary");
							scanf("%s%d%f",e.name,&e.age,&e.bs);
							fseek(fp,-recsize,SEEK_CUR);
							fwrite(&e,recsize,1,fp);
							break;
						}
					}
					printf("\nModify Another record (Y/N)");
					fflush(stdin);
					another=getche();
				}
				break;
			case '4':
				another='Y';

				while(another=='y' || another=='Y')
				{
					printf("\nEnter the name of employee to delete");
					scanf("%s",empname);

					tmpnam(buffer);
					puts(buffer);
					out=fopen(buffer,"wb+");
					if (out==NULL)
					{
						printf("\nCannot open the temp file");
						exit(2);
					}

					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if (strcmp(e.name,empname)!=0)
							fwrite(&e,recsize,1,out);
					}
					fclose(fp);
					fclose(out);
					remove("EMP.DAT");
					if (rename(buffer,"EMP.DAT") == 0)
						printf("\nRenamed");
					else
						printf("\nCannot rename");

					fp=fopen("EMP.DAT","rb+");

					printf("\nDelete Another Record (Y/N)");
					fflush(stdin);
					another=getche();
				}
				break;
			case '5':
				fclose(fp);
				exit(0);
		}
	}
}
