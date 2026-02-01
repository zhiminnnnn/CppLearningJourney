#include <iostream>
#include <iomanip>
#define MAX 20
#define COL 5
using namespace std;

void displayLine();
void getData(double **empRecord, int &ROW, int empID[]);
void calculatePayroll(double **empRecord, int ROW, int empID[]);
void printData(double **empRecord, int ROW, int empID[]);
void highestOvertime(double **empRecord, int ROW, int empID[]);

int main(){
	int ROW;
	int *empID = new int [MAX];
	double **empRecord = new double *[MAX];
	for(int i=0; i<MAX; i++){
		empRecord[i] = new double [COL];
	}
	getData(empRecord, ROW, empID);
	calculatePayroll(empRecord, ROW, empID);
	printData(empRecord, ROW, empID);
	highestOvertime(empRecord, ROW, empID);
	return 0;
}

void displayLine(){
	for (int i=0; i<105; i++){
		cout << "-";
	}
	cout << endl;
}

void getData(double **empRecord, int &ROW, int empID[]){
	cout << "How many employees? ";
	cin >> ROW;
	cout << endl;
	cout << "Payroll program" << endl;
	for(int i=0; i<ROW; i++){
		cout << "ID: ";
		cin >> empID[i];
		cout << "Hours worked: ";
		cin >> empRecord[i][0];
		cout << "Rate of Pay (RM per hour): ";
		cin >> empRecord[i][1];
	}
	cout << endl;
}

void calculatePayroll(double **empRecord, int ROW, int empID[]){
	for(int i=0; i<ROW; i++){
		if(empRecord[i][0] > 40){
			empRecord[i][2] = 40 * empRecord[i][1];
			empRecord[i][3] = (empRecord[i][0] - 40) * 1.5 * empRecord[i][1];
		}
		else{
			empRecord[i][2] =  empRecord[i][0] * empRecord[i][1];
		}
		empRecord[i][4] = empRecord[i][2] + empRecord[i][3];
	}
}

void printData(double **empRecord, int ROW, int empID[]){
	cout << "Payroll Final Report" << endl;
	displayLine();
	cout << left << setw(7) << "ID"
	<< setw(22) << "HOURS"
	<< setw(22) << "RATE (RM)"
	<< setw(22) << "REGULAR PAY (RM)"
	<< setw(22) << "OVERTIME (RM)"
	<< setw(22) << "TOTAL (RM)" << endl;
	displayLine();
	for(int i=0; i<ROW; i++){
		cout << setw(7) << empID[i];
		for(int j=0; j<COL; j++){
			cout << setw(22) << empRecord[i][j];
		}
		cout << endl;
	}
}

void highestOvertime(double **empRecord, int ROW, int empID[]){
	int maxIn = 0;
	double max = empRecord[0][3];
	for(int i=0; i<ROW; i++){
		if(empRecord[i][3] > max){
			max = empRecord[i][3];
			maxIn = i;
		}
	}
	cout << "Staff " << empID[maxIn] << " have the highest pay overtime of RM" << empRecord[maxIn][3] << endl;
}
