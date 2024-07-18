#include <iostream>

const int MAX_SIZE_QUESTIONS = 5;

struct Answer
{
	char answerStr[50];
};

struct Question
{
	char title[50];
	Answer answers[4];
	char rightAnswer;
	int points = 0;
};

struct Test
{
	Question questions[MAX_SIZE_QUESTIONS];
	int currentSizeQuestions = 0;
};

void addQuestion(Test& test, const Question& question)
{
	if (test.currentSizeQuestions == MAX_SIZE_QUESTIONS)
	{
		std::cout << "[ERROR] Can not add any more questions" << std::endl;
		return;
	}

	test.questions[test.currentSizeQuestions++] = question;
}

void printQuestion(const Question& question)
{
	std::cout << "Question: " << question.title << std::endl;

	char option = 'A';
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Option: " << option++ << " " << question.answers[i].answerStr << std::endl;
	}
}


int doTest(Test& test)
{
	int totalPoints = 0;
	for (int i = 0; i < test.currentSizeQuestions; i++)
	{
		printQuestion(test.questions[i]);
		char answer = ' ';
		std::cin >> answer;

		if(!(answer >= 'A' && answer <= 'D'))
		{
			std::cout<<"[ERROR] Invalid option"<<std::endl;
			return -1;
		}

		if (answer == test.questions[i].rightAnswer)
		{
			totalPoints += test.questions[i].points;
		}
	}

	return totalPoints;
}

int main()
{
	Question question = { "questionOne", {"test", "test", "test", "test"}, 'A', 10};
	Question questionTwo = { "questionTwo", {"test", "test", "test", "test"}, 'A', 10 };
	Test test;

	addQuestion(test, question);
	addQuestion(test, questionTwo);

	std::cout<<"Your total score is: " << doTest(test) << "points." << std::endl;

	return 0;
}