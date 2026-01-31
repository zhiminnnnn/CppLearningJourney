//FinalQ1.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 20 //Number of students/ characters
using namespace std;
struct info
{
	float course_marks[3]; //Marks for Test1, Test2 and Test3
	float total_mark; //Total mark for all tests
	char grade; //Grade
	char name[MAX]; //Name
};
//Function to calculate total mark for all tests
void calc_totalMark (float *TM, float CW[])
{
	*TM = 0;
	for (int i = 0; i < 3; i++)
		*TM += *(CW+i); //Use pointer arithmetic to access array
}

//Function to determine the grades
char deter_grade (float TM)
{
	if (TM >= 85)
		return 'A';
	else if (TM >= 70)
		return 'B';
	else if (TM >= 55)
		return 'C';
	else if (TM >= 40)
		return 'D';
	else
		return 'E';
}

int main()
{
	int i, j;
	info *students; //Declare a pointer variable
	fstream inp;
	//Dynamic memory allocation for students array
	students = new info [MAX];
	inp.open("input.txt", ios::in); //Open an input file
	//Read data from text file
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < 3; j++)
			inp >> students[i].course_marks[j];
		inp.getline(students[i].name, MAX);
	}
	//Display output on the screen
	cout << left << setw(26) << " NAME"
		<< setw(7) << "T1"
		<< setw(7) << "T2"
		<< setw(6) << "T3"
		<< setw(8) << "TOTAL"
		<< "GRADE" << endl;
	for (i = 0; i < MAX; i++)
	{
		cout << setw(25) << students[i].name << fixed << setprecision(1);
		for (j = 0; j < 3; j++)
			cout << setw(7) << students[i].course_marks[j];
		//Call a function to calculate total marks
		calc_totalMark(&students[i].total_mark, students[i].course_marks);
		//Call a function to determine the grades
		students[i].grade = deter_grade(students[i].total_mark);
		cout << setw(10) << students[i].total_mark << students[i].grade << endl;
	}
	//Free dynamic memory for students array
	delete []students;
	inp.close(); //Close the input file
	return 0;
}
