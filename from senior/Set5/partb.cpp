#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 100

using namespace std;

struct dataAcc
{
	int numAcc[10]; //number of road accidents from 2006-2015
	string state; //states in Malaysia
	float avg; //average number of road accidents for 2006-2015
};

ofstream out("output.txt");

void displayLine();
float cal_Avg(int arr[]);
void find_HighLow(dataAcc arr[], int count);

int main(){
	dataAcc *array;
	array = new dataAcc [MAX];
	int count=0;
	
	ifstream infile("input.txt");
	
	if(!infile){
		cout <<"Error"<<endl;
		return -1;
	}
	else{
		while(infile >> array[count].numAcc[0]){
			for(int i=1; i<10; i++){
				infile >> array[count].numAcc[i];
			}
			getline(infile, array[count].state);
			count++;
		}
	}
	
	for(int i=0; i<count; i++){
		array[i].avg = cal_Avg(array[i].numAcc);
	}
	
	displayLine();
	out << left << setw(18) << " STATE";
	for(int i=0; i<10; i++){
		out << right << setw(7) << 2006 + i;
	}
	out << setw(10) << "AVERAGE" << endl;
	displayLine();
	
	for(int i=0; i<count; i++){
		out << left << setw(18) << array[i].state;
		for(int j=0; j<10; j++){
			out << right << setw(7) << array[i].numAcc[j];
		}
		out << setw(10) << array[i].avg << endl;
	}
	displayLine();
	find_HighLow(array, count);
	infile.close();
	out.close();
	delete[] array;
	return 0;
}

void displayLine(){
	for(int i=0; i<98; i++){
		out << "-";
	}
	out << endl;
}

float cal_Avg(int arr[]){
	float sum = 0;
	for(int i=0; i<10; i++){
		sum += arr[i];
	}
	return sum/10;
}

void find_HighLow(dataAcc arr[], int count){
	int max = arr[0].numAcc[0], maxInRow = 0, maxInCol = 0;
	for(int i=0; i<count; i++){
		for(int j=0; j<10; j++){
			if(arr[i].numAcc[j] > max){
				max = arr[i].numAcc[j];
				maxInRow = i;
				maxInCol = j;
			}
		}
	}
	out << "The highest number of road accidents = "
		 << max
		 << " at"
		 << arr[maxInRow].state
		 << " on "
		 << maxInCol + 2006;
}
