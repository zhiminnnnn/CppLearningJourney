#include <iostream>
#include <iomanip>
#include <fstream>
#define SIZE 12
using namespace std;

struct Weather{
	double rain;
	int rainDays;
	double hiTemp;
	double loTemp;
	string month;
};

double calcTotal(Weather arr[]);
void calcAvgTemp(Weather arr[], double avg[]);
int findHighest(Weather arr[]);
int findLowest(Weather arr[]);
void displayOutput(Weather arr[], double avg[]);

int main(){
	Weather array[SIZE];
	ifstream infile("data.txt");
	if(!infile){
		cout<<"Error";
		return 1;
	}
	else{
		for(int i=0; i<SIZE; i++){
			infile >> array[i].rain
				   >> array[i].rainDays
				   >> array[i].hiTemp
				   >> array[i].loTemp
				   >> array[i].month;
		}
	}
	double avg[SIZE];
	calcAvgTemp(array, avg);
	displayOutput(array, avg);
	
	return 0;
}

void displayOutput(Weather arr[], double avg[]){
	double total = calcTotal(arr);
	int maxIn = findHighest(arr);
	int minIn = findLowest(arr);
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"Total Rainfall: "<<total<<endl;
	cout<<"Average Monthly Rain: "<<total/12<<endl;
	cout<<"Highest Temperature: "
		<<arr[maxIn].hiTemp
		<<" (Month "
		<<maxIn+1
		<<": "
		<<arr[maxIn].month
		<<")"
		<<endl;
	cout<<"Lowest Temperature: "
		<<arr[minIn].loTemp
		<<" (Month "
		<<minIn+1
		<<": "
		<<arr[minIn].month
		<<")"
		<<endl<<endl;
	cout<<setw(12)<<left<<"Month"
		<<setw(12)<<left<<"Rain"
		<<setw(12)<<left<<"Rain days"
		<<setw(12)<<left<<"Hi TEMP"
		<<setw(12)<<left<<"Lo TEMP"
		<<setw(12)<<left<<"Avg TEMP"
		<<endl;
	cout<<"===================================================================="<<endl;
	for(int i=0; i<SIZE; i++){
		cout<<setw(12)<<left<<arr[i].month
			<<setw(12)<<left<<arr[i].rain
			<<setw(12)<<left<<arr[i].rainDays
			<<setw(12)<<left<<arr[i].hiTemp
			<<setw(12)<<left<<arr[i].loTemp
			<<setw(12)<<left<<avg[i]<<endl;
	}
}

double calcTotal(Weather arr[]){
	double sum=0;
	for(int i=0; i<SIZE; i++){
		sum += arr[i].rain;
	}
	return sum;
}

void calcAvgTemp(Weather arr[], double avg[]){
	for(int i=0; i<SIZE; i++){
		avg[i] = (arr[i].hiTemp + arr[i].loTemp) / 2;
	}
}

int findHighest(Weather arr[]){
	int maxIndex = 0;
	double max = arr[0].hiTemp;
	for(int i=0; i<SIZE; i++){
		if(arr[i].hiTemp > max){
			max = arr[i].hiTemp;
			maxIndex = i;
		}
	}
	return maxIndex;
}

int findLowest(Weather arr[]){
	int minIndex = 0;
	double min = arr[0].loTemp;
	for(int i=0; i<SIZE; i++){
		if(arr[i].loTemp < min){
			min = arr[i].loTemp;
			minIndex = i;
		}
	}
	return minIndex;
}
