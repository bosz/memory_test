/*
BY: FONGOH MARTIN-BOSZ
FET-UB
Modified: 11/03/14:
	Succeeded in the timing.
	Created a statistic analyser, but did not intergrate it.
	Changed the data type of the level variable from size_t to char so that any input can be handled in the same manner.
	Modified some output(the way the text is displayed.
	Procedure to initialise all the counter variables holding the number of questions  answered for each section.
	BUG: Default case for initial options of easy, normal and difficult does not respond as intended.
*/
#include<stdio.h>
#include<stdlib.h>
#include"functions_memory.h"

int main(void)
{
	quest_init();
	system("clear");
	item points=0;
	printf("\t\t\t\t\tThis is the memory testing game\n"
			"\t\t\t\t\t-------------------------------\n"
			"\t\t\tu are going to be asked to memorise a set of numbers and reproduce them back\n\n");
	printf("\t\t\t\t\tFirst of all select ur level");
	
	printf("\n\t1\tEasy(3#)\n\t2\tNormal(5#)\n\t3\tDifficult(7#)\n\t0\tEscape(exit)\n");
	
	scanf("%c", &level);
	while(level!='0')
	{
		switch(level)
		{
			case '1':
				points+=memory_test_level(3);
				break;
			case '2':
				points+=memory_test_level(5);
				break;
			case '3':
				points+=memory_test_level(7);
				break;
			case '0':
				statistics();
				return 0;
			default:
				printf("wrong option. New option > ");
				goto SCN;
		}
		fflush(stdin);
		printf(" |---------Accumulated points ------- : | %d |\n\n", points);
	printf(" chose a new level\n");
	printf("\n\t1\tEasy(3#)\n\t2\tNormal(5#)\n\t3\tDifficult(7#)\n\t0\tEscape(exit)\n");
SCN:scanf("%c", &level);
	}

return 0;
}
