/*
BY: FONGOH MARTIN-BOSZ
FET-UB

*/
typedef int item;
typedef float REAL;
//typedef register int fast;

#define EASY 3
#define NORMAL 5
#define DIFFICULT 7
#define N 3//Number of question for each section: timed or untimed.

item memory_test_level(size_t);//main level to chose btn timed or untimed
item timed_level(size_t );//in timed level to answer 3 questions within a particluar time 
						  //depending on ur first choice, easy, normal, difficult
item untimed_level(size_t );//in untimed level to answer 3 questions without a particluar time 
void add_number_of_questions_timed(size_t);//keeps track of the number of timed easy, normal or difficult questions answered
void add_number_of_questions_untimed(size_t);//keeps track of the number of untimed easy, normal or difficult questions answered
void wait_for_signal(void);//signal to triger the commencement of input of the values.

void delay(size_t);//gets to delay the output for the user to memorise before clearing the screen awaiting input.
void ask_options(size_t);//gives the user the opportunity in the untimed level to start inputing his number
size_t num_of_questions;
void statistics(void);
void quest_init(void);

char level;



