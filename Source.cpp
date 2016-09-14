/*  Taylor Jenkins
	05-03-16
	CIT 213-875
	Assignment Ch. 7
	Part I: 25pts.
	Exercize 10 (Page 451)  */

//Driver"s License Exam

/*   This program grades the written portion of a hypothetical diver"s license exam.
The exam has 20 multiple choice questions. The student must correctly answer 15/20
questions correctly to pass the exam.  */

#include <iostream>
using namespace std;


//Prototypes:
bool inputValidation(char);
int checkAnswers();
void getWrongAnswers();
void displayOutput(int);

//Constants:
const int QUESTIONS = 20;
const int PASSING = 15;

//Arrays: 
//this array is to hold the correct answers.
char answerKey[] = { 'A','D','B','B','C',
					 'B', 'A', 'B', 'C', 'D',
					 'A', 'C', 'D', 'B', 'D',
					 'C', 'C', 'A','D', 'B'};

int wrongAnswers[QUESTIONS]; //this array holds the wrong answers.
char userAnswers[QUESTIONS]; //this array holds the user's anwers.

//*****************************************/
//*This is the start of the main function.*/
//*****************************************/
int main()
{
	int rightAnswers = 0; //counts the correct answers

	//for loop used to determine iterations 
	for (int i = 0; i < QUESTIONS; i++)
	{
		//get input and validate
		do {
			cout << "Enter your answer for question #" << i + 1 << ": ";
			cin >> userAnswers[i];
		} while (!inputValidation(userAnswers[i])); // if false is returned do while loop reiterates. 
	}

	rightAnswers = checkAnswers(); //checkAnswers() will return the number of correctly answered questions.

	//if statement used to only run function getWrongAnswers if the user entered wrong answers.
	if (rightAnswers < QUESTIONS)
	{
		getWrongAnswers();
	}
	
	displayOutput(rightAnswers); //passing the number of correctly answered questions.

	return 0;
}

//****************************************************/
//This is the start of void function displayOutput.  */
// This function will display to the user if they    */
//passed the exam, the total of correctly answered   */
//questions, the total of incorrectly answered ques- */
// tions, and a list of the incorrectly answered     */
//question numbers.
//****************************************************/
void displayOutput(int count)
{
	//if statment to determine if passing score was reached.
	if (count >= PASSING)
	{
		cout << "\nYou have passed the exam!";
	}
	else
		cout << "You did not pass the exam.";

	//displays how many questions were answered correct and incorrectly.
	cout << "\nYou answered " << count << " out of " << QUESTIONS << " correctly." << endl;
	cout << "You answered " << (QUESTIONS - count) << " incorrectly." << endl;

	//output which questions were wrong
	if (count < QUESTIONS)
	{
		cout << "Incorrect Answers: " << endl;

		for (int i = 0; i < QUESTIONS - count; i++)
		{
			cout << "Q." << (wrongAnswers[i]) << "." << endl;
		}
	}
}

//****************************************************/
//This is the start of void function getWrongAnswers.*/
// This function will compare the answerKey with the */
//user's answers and store the incorrect answers in  */
//the array wrongAnswers.							 */
//****************************************************/
void getWrongAnswers()
{
	int count = 0; //index of wrongAnswers array.

	//for loop used to set the number of times for iteration.
	for (int i = 0; i < QUESTIONS; i++)
	{
		if (answerKey[i] != toupper(userAnswers[i])) 
		{
			wrongAnswers[count] = i + 1; 
			count++;
		}
	}
}

//****************************************************/
//This is the start of int function checkAnswers.	 */
// This function will compare the answerKey with the */
//user's answers and return the number of correct    */
//answers.											 */
//****************************************************/
int checkAnswers()
{
	int count = 0;

	for (int i = 0; i < QUESTIONS; i++)
	{
		if ((toupper(userAnswers[i]) == answerKey[i]))
		{
			count++;
		}
	}

	return count; //returns the number of correct answers.
}


//****************************************************/
//This is the start of bool function inputValidation */
// This function will check to make sure that the user/
//enters either an A, B, C, or D. If lowercase leters*/
//are entered the toupper will temporarily convert 	 */
//the input to uppercase letters.					 */
//****************************************************/
bool inputValidation(char answer)
{
	//A, B, C, or D are the valid inputs
	if (toupper(answer) != 'A' && toupper(answer) != 'B' && toupper(answer) != 'C' && toupper(answer) != 'D')
	{
		cout << "\nInvalid input. The answer choices are A, B, C, or D.";
		return false;
	}
	else
		return true;
}


//******************   TEST OUTPUT://   *******************************************************//
/*		Incorrect answers antered.
Enter your answer for question #1: a
Enter your answer for question #2: b
Enter your answer for question #3: c
Enter your answer for question #4: D
Enter your answer for question #5: A
Enter your answer for question #6: D
Enter your answer for question #7: A
Enter your answer for question #8: C
Enter your answer for question #9: B
Enter your answer for question #10: B
Enter your answer for question #11: B
Enter your answer for question #12: a
Enter your answer for question #13: e                        //shows entering of other character besides the vaild ones.

Invalid input. The answer choices are A, B, C, or D.Enter your answer for question #13: a
Enter your answer for question #14: D
Enter your answer for question #15: C
Enter your answer for question #16: B
Enter your answer for question #17: B
Enter your answer for question #18: A
Enter your answer for question #19: C
Enter your answer for question #20: D
You did not pass the exam.
You answered 2 out of 20 correctly.
You answered 18 incorrectly.
Incorrect Answers:
Q.2.
Q.3.
Q.4.
Q.5.
Q.6.
Q.8.
Q.9.
Q.10.
Q.11.
Q.12.
Q.13.
Q.14.
Q.15.
Q.16.
Q.17.
Q.19.
Q.20.
Q.1.
Press any key to continue . . .
*/

//			Correct answers entered.
/*
Enter your answer for question #1: A
Enter your answer for question #2: D
Enter your answer for question #3: B
Enter your answer for question #4: B
Enter your answer for question #5: C
Enter your answer for question #6: B
Enter your answer for question #7: A
Enter your answer for question #8: B
Enter your answer for question #9: C
Enter your answer for question #10: D
Enter your answer for question #11: A
Enter your answer for question #12: C
Enter your answer for question #13: D
Enter your answer for question #14: B
Enter your answer for question #15: D
Enter your answer for question #16: C
Enter your answer for question #17: C
Enter your answer for question #18: A
Enter your answer for question #19: D
Enter your answer for question #20: B

You have passed the exam!
You answered 20 out of 20 correctly.
You answered 0 incorrectly.
Press any key to continue . . .

*/

//		Correct answers in loweercase entered
/*
Enter your answer for question #1: a
Enter your answer for question #2: d
Enter your answer for question #3: b
Enter your answer for question #4: b
Enter your answer for question #5: c
Enter your answer for question #6: b
Enter your answer for question #7: a
Enter your answer for question #8: b
Enter your answer for question #9: c
Enter your answer for question #10: d
Enter your answer for question #11: a
Enter your answer for question #12: c
Enter your answer for question #13: d
Enter your answer for question #14: b
Enter your answer for question #15: d
Enter your answer for question #16: c
Enter your answer for question #17: c
Enter your answer for question #18: a
Enter your answer for question #19: d
Enter your answer for question #20: b

You have passed the exam!
You answered 20 out of 20 correctly.
You answered 0 incorrectly.
Press any key to continue . . .
*/