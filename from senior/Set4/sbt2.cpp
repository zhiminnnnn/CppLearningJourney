////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1013- Programming Technique I
// Semester 1, 2016/2017
// Skill-Based Test 2
// 6 Dec 2016
//
//  Student Name: ____________________
//  Section     : ____________________  
//
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

//----------------- Function prototypes ---------------------------------------------
double gradeToPoint(char);
void readFile(string,string[], double[], char[], double[], int &);
double sum(const double[], int);
void multiply(const double [], const double [], double [], int);
//------------------------------------------------------------------------------------

// Function   : gradeToPoint
// Purpose    : To determine the point value for a letter grade.  
//
// Parameters :
//       	  grade - the letter grade
//
// Return value:  the point value of the grade

// **** Task 1 : Complete the defintion of function "gradeToPoint" (5 marks)

double gradeToPoint(char grade)
{
	switch (grade){
		case 'A':
			return 4.0;
			break;
		case 'B':
			return 3.0;
			break;
		case 'C':
			return 2.0;
			break;
		case 'D':
			return 1.0;
			break;
		case 'E':
			return 0.0;
			break;
	}
}

// Function : readFile  
// Purpose  : To read inputs from a file consisting of the list of subjects along 
//             with their credit hours and grades earned by the student.
// Parameters:
//           fileName  :  the name of the input file
//           subjects  :  the array to hold the list of subjects read from the file
//           credits   :  the array to hold the list of credit hours
//           grades    :  the array to hold the list of grades
//           points    :  the array to hold the list of point values for corresponding grades
//           count     :  the number of subjects read
//

// **** Task 2: Complete the definition of function "readFile"    (5 marks)

void readFile(string fileName,string subjects[], double credits[], char grades[], double points[], int &count)
{
	string sn;    // subject name
	double ch;    // credit hour
	char g;       // grade earned
	double gp;    // grade point

	ifstream fin(fileName.c_str());
	count = 0;

	while ( getline(fin,sn,'\t') ){

		fin >> ch; fin.ignore();
		fin >> g; fin.ignore();

		// complete these lines such that the read data
		//  are stored into arrays accordingly.

		subjects[count] = sn;
		credits[count] = ch;
		grades[count] = g;
		points[count] = gradeToPoint(g);

		count++;
	}
	fin.close();
}

// Function  : sum
// Purpose   : To calculate the sum of elemenets of an array.
//
// Parameters:
//         	a  - the array
//          n  - the size of array 
//
//  Return value:  the sum of all the elements of the array

// **** Task 3 : Complete the defintion of function "sum"  (4 marks)

double sum(const double a[], int n)
{
	double sum=0;
	for(int i=0; i<n; i++){
		sum += a[i];
	}
	return sum;
}

// Function  : multiply
// Purpose   : to multiply the elements of arrays a and b correspondingly, and puts the result into another array, c.
//
// Parameters:
//      		a,b  - the input arrays
//              c    - the array that holds the results of the multiplication.

// **** Task 4 : Complete the defintion of function "multiply"  (2 marks)

void multiply(const double a[], const double b[], double c[], int n)
{
	for(int i=0; i<n; i++){
		c[i] = a[i] * b[i];
	}
}



int main()
{
	string inputFile;
	string s[10];  // The list (array) of subjects
	double c[10];  // The list (array) of credits
	char g[10];    // The list (array) of grades
	double p[10];  // The list (array) of points (i.e., the point value for each grade)
	int n;          // The number of subjects
	
	double cp[10]; // The list of credit points, i.e., creditHour x gradePoint
	double tc;     // Total credit hour
	double tcp;    // Total credit point
	double cgpa;
	
	cout << "Enter the input file => ";
	cin >> inputFile;
	
	// **** Task 5: Read inputs from the input file (2 marks)
	readFile(inputFile, s, c, g, p, n);
	
	// **** Task 6: Using appropriate functions defined above, calculate the total credit hours, 
	//              total credit points and CGPA. 	       (8 marks)
	multiply(c, p, cp, n);
	tc = sum(c, n);
	tcp = sum(cp, n);
	cgpa = tcp / tc;

	cout << endl << endl;
    
    // **** Task 7: Print the list of subjects along with their credit hours, grades earned and grade points.     (5 marks)

	cout << setw(30) << left << "Subject Name"
	     << setw(15) << left << "Credit Hour"
	     << setw(15) << left << "Grade Earned"
	     << setw(15) << left << "Grade Point"
	     << endl << endl;
    
    for(int i=0; i<n; i++){
    	cout << setw(30) << s[i]
    		 << setw(15) << c[i]
    		 << setw(15) << g[i]
    		 << setw(15) << p[i] << endl;
	}
	cout << endl;

    // **** Task 8: Print the number of subjects, total credit hours, total credit points and CGPA.                 (4 marks).

	cout << "Number of subject   : " << n << endl;	
	cout << "Total credit hours  : " << tc << endl;	
	cout << "Total credit points : "<< tcp << endl;
	cout << showpoint << fixed << setprecision(2);	
	cout << "CGPA                : " << cgpa << endl;	
	
	return 0;
}
