MEMORY TEST GAME.
==================

This game is built to test the memorisation ability of the user.
The game goes thus.
1. At the start, the user is give the opportunity to choose from 4
options the possible strength that he would like to play with.
There is easy, normal and difficult with 3, 5 and 7 numbers respectively that the user has to memorise and reproduce at the give time.
2. At the state of each level, there is also a sub state if the user will like to be timed or not. If timed, a particular time will be given from the appearance of the numbers and their disappearance.
If untimed, the user has all the time too input the numbers back so that the computer can compute his/her memorization ability.

For timed memory test, a correct value is +3 while a wrong value is -1.
For untimed test,  correct value give is +2 while a wrong value given is -1.

Now in terms of the time given when playing in timed mode, if u choose:
	Easy;
U will be given a system sleep time of 3
	Normal:
U will be given a system sleep time of 6
	Difficult:
U will be given a system sleep time of 10

Then after this time, the numbers will be taken off the terminal for the user to rewrite.

To keep track of the number of questions the player has played in the difficult, normal and easy levels of the time and untimed section, variables quest_category[2] are defined where the first cell is for the timed games of the respective categories and the 2nd cells are for the untimed games in their respective categories.

e.g

<code>quest_easy[0]: number of easy timed questions answered.<br/>
quest_easy[1]: number of easy untimed question answered.
</code>

###COMPILING THE GAME:
Open the terminal and type the following command
<pre>
$		make
</pre>

###RUNNING THE GAME:
Open the sterminal and type the following command
<pre>
$ 	./memgame
</pre>

###AUTHOR:
Fongoh Martin Tayong aka _echelon<br/>
FET<br/>
[University of Buea, Cameroon](http://ubuea.cm)
fongohmartin@gmail.com<br/>
