#include <iostream>
#include <iomanip>
#include <fstream>
#define SIZE 12
using namespace std;

struct Data{
	int year;
	double per[5];
};

void readInput(Data arr[]);
void calculateAverage(Data arr[], double avg[]);
void displayAnalysis(Data arr[], string dis[]);
void displayOutput(Data arr[], string dis[], double avg[]);

int main(){
	Data array[SIZE];
	readInput(array);
	
	double avg[5];
	
	string dis[5] = {"Measles", "MMR", "DPT", "Hepatitis B", "Polio"};
	
	displayOutput(array, dis, avg);
	
	return 0;
}

void readInput(Data arr[]){
	ifstream infile("input.txt");
	if(!infile){
		cout << "Error";
	}
	else{
		for(int i=0; i<SIZE; i++){
			infile >> arr[i].year;
			for(int j=0; j<5; j++){
				infile >> arr[i].per[j];
			}
		}
	}
}

void calculateAverage(Data arr[], double avg[]){
	for(int i=0; i<5; i++){
		double sum=0;
		for(int j=0; j<SIZE; j++){
			sum += arr[j].per[i];
		}
		avg[i] = sum / SIZE;
	}
}

void displayAnalysis(Data arr[], string dis[]){
	double max = arr[0].per[0], min = arr[0].per[0];
	int maxInYear = 0, minInYear = 0, maxInDis = 0, minInDis = 0;
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<5; j++){
			if(arr[i].per[j] < min){
				min = arr[i].per[j];
				minInYear = i;
				minInDis = j;
			}
			else if(arr[i].per[j] > max){
				max = arr[i].per[j];
				maxInYear = i;
				maxInDis = j;
			}
		}
	}
	cout << "The lowest level of immunisation: "
		 << dis[minInDis]
		 << " ("
		 << min
		 <<"%) in year "
		 << arr[minInYear].year
		 <<endl;
	cout << "The highest level of immunisation: "
		 << dis[maxInDis]
		 << " ("
		 << max
		 <<"%) in year "
		 << arr[maxInYear].year
		 <<endl;
}

void displayOutput(Data arr[], string dis[], double avg[]){
	calculateAverage(arr, avg);
	cout << "The Percentage of Infants who have been Immunised against Measles, MMR, DPT, Hepatitis B, and Polio (2004-2015)" << endl;
	cout << "----------------------------------------------------------------------------------"<<endl;
	cout << setw(15) << left << "Year"
		 << setw(15) << left << "Measles"
		 << setw(15) << left << "MMR"
		 << setw(15) << left << "DPT"
		 << setw(15) << left << "Hepatitis B"
		 << setw(15) << left << "Polio" <<endl;
	cout << "----------------------------------------------------------------------------------"<<endl;
	for(int i=0; i<SIZE; i++){
		cout << setw(15) << left << arr[i].year;
		for(int j=0; j<5; j++){
			cout << fixed << showpoint << setprecision(1);
			cout << setw(15) << left << arr[i].per[j];
		}
		cout<<endl;
	}
	cout << "----------------------------------------------------------------------------------"<<endl;
	cout << setw(15) << left << "Average";
	for(int i=0; i<5; i++){
		cout << setw(15) << left << avg[i];
	}
	cout<<endl;
	cout << "----------------------------------------------------------------------------------"<<endl;
	displayAnalysis(arr, dis);
	cout << "----------------------------------------------------------------------------------"<<endl;
}
