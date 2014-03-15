/*
BY: FONGOH MARTIN-BOSZ
FET-UB

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<ctype.h>
#include"functions_memory.h"
item quest_easy[2], quest_normal[2], quest_difficult[2];
char *level_mode[]={"", "", "", "Easy", "",  "Normal", "", "Difficult"};

/*
The first cell of each of the arrays say easy will hold the number of easy questions that were from the timed state
and the 2nd cell will hold the number of questions from the easy section that were taken from the untime section.
*/
int i, j;

//state_time is the variable thats going to determine if the user wants a timed play or an untimed play.

/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
item memory_test_level(size_t n)
{
	item points=0;
	char timed_untimed_level;
	ask_options(n);
	fflush(stdin);
	printf(" > ");
	scanf("%c", &timed_untimed_level);
	//timed_untimed_level=(char)timed_untimed_level;
OPT:	
		fflush(stdin);
		scanf("%c", &timed_untimed_level);
		switch(timed_untimed_level)
		{
			case 't':	
			case 'T':
				points=timed_level(n);
				break;
			case 'u':
			case 'U':
				points=untimed_level(n);
				break;
			default:
				{
					printf("Option not recognised, Try again."); 
					goto OPT;
				}
		printf("u had %d points in the %s level\n", points, *(level_mode+n));

	}
	return points;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
item timed_level(size_t n)
{
	srand(time(NULL));
	item points=0;
	item *random_array=(int *)malloc(n*sizeof(int));
	item *test_array=(int *)malloc(n*sizeof(int));
	add_number_of_questions_timed(n);
	fflush(stdin);
	for(j=0; j<N; j++)
	{
					//delay(n);
		for(i=0; i<n; i++)//print the random numbers
		{
			sleep(1);
			fflush(stdout);
			*(random_array+i)=rand() % 20;
			printf("   %d   ", *(random_array+i));
		}

		fflush(stdin);
		
		delay(n);//give the user some delay time
		
		printf("\n ?>>: ");
		for(i=0; i<n; i++)
			scanf("%d", (test_array+i) );


		for(i=0; i<n; i++)
		{
			if( *(test_array+i) == *(random_array+i) )	
				points+=3;
			else
				points-=1;	
		}
		printf("\n----Wait. Generating next set----\n\n");
	}	
	printf("\n\nSub-Points for section = %d / %d\n\n", points, N*9);
	free(random_array);
	free(test_array);
	return points;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
item untimed_level(size_t n)
{
	srand(time(NULL));
	item points=0;
	item *random_array=(int *)malloc(n*sizeof(int));
	item *test_array=(int *)malloc(n*sizeof(int));

	for(j=0; j<N; j++)
	{
		printf(" >  ");
		for(i=0; i<n; i++)//generate the random numbers and print them out
		{
			sleep(1);
			fflush(stdout);		
			*(random_array+i)=rand() % 50;
			printf("   %d   ", *(random_array+i));
		}
		
		
		
		printf("\n ?>>: ");
		for(i=0; i<n; i++)//get the numbers from the user.
			scanf("%d", (test_array+i));
			add_number_of_questions_untimed(n);
		for(i=0; i<n; i++)
		{
			if( *(test_array+i) == *(random_array+i) )	
				points+=2;
			else
				points-=1;
		}
		printf("\n----Wait. Generating next set----\n\n");
	}
	printf("\n\nSub-Points for section = %d / %d\n\n", points, N*6);

	free(random_array);
	free(test_array);
	return points;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
void add_number_of_questions_timed(size_t n)
{
	switch(n)
	{
		case EASY:
			quest_easy[0]+=3;
			break;
		case NORMAL:
			quest_normal[0]+=3;
			break;
		case DIFFICULT:
			quest_difficult[0]+=3;
			break;
	}
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
void add_number_of_questions_untimed(size_t n)
{
	switch(n)
	{
		case EASY:
			quest_easy[1]+=3;
			break;
		case NORMAL:
			quest_normal[1]+=3;
			break;
		case DIFFICULT:
			quest_difficult[1]+=3;
			break;
	}
/*+EASY because sice when u are already in the next level, timed or untimed, 
  u must play EASY games as prescibed by the system*/
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



void wait_for_signal(void)
{
	char sig;
	fflush(stdin);
	printf("\nPress any key and start entering the values : ");
	scanf("%c", &sig);
	if ( sig == '\n' )
	{
		system("clear");
		return ;
	}
}


/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
void ask_options(size_t n)
{
	printf("\t\t\t\t\tThis is the %s level\n", *(level_mode+n));
	printf("\t\t\tThere are 2 sub stages in this level, time and untimed. 3 questions for this section.\n"
			"\t\tYou will be expected to memorise the %s numbers on the screen & reproduce the\n\n\n", *(level_mode+n));
	printf("\t\t\t\t\t\tOPTIONS(3 session)\n\n");
	printf("\t\tt\tTimed\t\tMARKS:Correct +2 ..... Wrong -1/inputed value"
		   "\n\n\t\tu\tUntimed\t\tMARKS:Correct +3 ..... Wrong -1/inputed_value\n");
	printf("\n\n  timed no_of_questions || untimed no_of_questions (t/u)\n\n");
}
//*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


void delay(size_t n)
{
//This function gives the user some time to read and memorise the numbers and then it 
//clears the numbers from the standard output

	fflush(stdout);
	switch(n)
	{
		case EASY:
			sleep(3);
			break;
			
		case NORMAL:
			sleep(5);
			break;
			
		case DIFFICULT:
			sleep(7);
			break;			
	}
	fflush(stdout);
	system("reset");
}


/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/

void statistics(void)
{
	printf("\t\t\t\t\tEnd of Game Statistics\n");
	printf("%20s\t%5d\n\n"
		   "%20s\t%5d\n\n"
		   "%20s\t%5d\n\n"
		   "\t\t\t\t\tTIMED_ANALYSIS\n\n"
		   "%20s\t%5d\n\n"
		   "%20s\t%5d\n\n"
		   "%20s\t%5d\n\n"
		   "\t\t\t\t\tUNTIMED_ANALYSIS\n\n"
		   "", "Easy", quest_easy[0], "Nornal", quest_normal[0], "Difficult", quest_difficult[0], "Easy", quest_easy[1], "Nornal", quest_normal[1], "Difficult", quest_difficult[1]);
		   		   
}


void quest_init(void)
{
	register int i;
	for(i=0; i<2; i++)
	{
		*(quest_easy+i)=0;
		*(quest_normal+i)=0;
		*(quest_difficult+i)=0;
	}
}
