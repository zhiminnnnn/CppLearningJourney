#include <iostream>
#include <iomanip>
#include <fstream>
#define SIZE 10
using namespace std;

struct Sales{
	string brand;
	double perc[4];
	double avg;
};

void showLine();
void calculateAverage(Sales arr[]);
void displayOutput(Sales arr[]);
int findLowest(Sales arr[]);
int findHighest(Sales arr[]);

int main(){
	Sales array[SIZE];
	ifstream infile("InputQ2.txt");
	if(!infile){
		cout<<"Error"<<endl;
		return 0;
	}
	else{
		for(int i=0; i<SIZE; i++){
			for(int j=0; j<4; j++){
				infile >> array[i].perc[j];
			}
			infile >> array[i].brand;
		}
	}
	calculateAverage(array);
	displayOutput(array);

	return 0;
}

void showLine()
{
	for (int i = 0; i < 60; i++)
		cout << "-";
	cout << endl;
}

void calculateAverage(Sales arr[]){
	for(int i=0; i<SIZE; i++){
		double sum=0;
		for(int j=0; j<4; j++){
			sum += arr[i].perc[j];
		}
		arr[i].avg = sum/4;
	}
}

void displayOutput(Sales arr[]){
	cout<<"Percentage of Sales by Brand (2016 to 2019)"<<endl<<endl;
	showLine();
	cout<<setw(20)<<left<<" BRAND"
		<<setw(8)<<left<<"2016"
		<<setw(8)<<left<<"2017"
		<<setw(8)<<left<<"2018"
		<<setw(8)<<left<<"2019"
		<<setw(8)<<left<<"AVERAGE"
		<<endl;
	showLine();
	for(int i=0; i<SIZE; i++){
		cout<<setw(20)<<left<<arr[i].brand;
		for(int j=0; j<4; j++){
			cout<<fixed<<showpoint<<setprecision(1);
			cout<<setw(8)<<left<<arr[i].perc[j];
		}
		cout<<fixed<<showpoint<<setprecision(2);
		cout<<setw(20)<<left<<arr[i].avg;
		cout<<endl;
	}
	showLine();
	int minIndex = findLowest(arr);
	int maxIndex = findHighest(arr);
	cout<<"Lowest Average of Sales Percentage: "
		<<arr[minIndex].avg
		<<" - "
		<<arr[minIndex].brand
		<<endl;
	cout<<"Highest Average of Sales Percentage: "
		<<arr[maxIndex].avg
		<<" - "
		<<arr[maxIndex].brand
		<<endl;
	showLine();
}

int findLowest(Sales arr[]){
	double min = arr[0].avg;
	int minIndex = 0;
	for(int i=1; i<SIZE; i++){
		if(arr[i].avg < min){
			min = arr[i].avg;
			minIndex = i;
		}
	}
	return minIndex;
}

int findHighest(Sales arr[]){
	double max = arr[0].avg;
	int maxIndex = 0;
	for(int i=1; i<SIZE; i++){
		if(arr[i].avg > max){
			max = arr[i].avg;
			maxIndex = i;
		}
	}
	return maxIndex;
}
