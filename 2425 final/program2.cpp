#include <iostream>
#include <iomanip>
#include <fstream>
#define SIZE 1000
using namespace std;

struct Sales{
	string branch;
	int first;
	int sec;
	int third;
	int fourth;
};

void readInput(Sales arr[], int &count);
void calcAnnual(Sales arr[], int ann[], int count);
int calcTotal(int ann[], int count);
int findMaxIndex(int ann[], int count);
void displayOutput(Sales arr[], int count, int ann[], int total, int maxIndex);

int main(){
	Sales *array;
	array = new Sales [SIZE];
	
	int count = 0;
	
	readInput(array, count);
	
	int *annual;
	annual = new int[count];
	
	calcAnnual(array, annual, count);
	
	int total = calcTotal(annual, count);
	
	int maxIndex = findMaxIndex(annual, count);
	
	displayOutput(array, count, annual, total, maxIndex);
	
	return 0;
}

void readInput(Sales arr[], int &count){
	ifstream inBranch("branches.txt");
	ifstream inFirst("first.txt");
	ifstream inSec("second.txt");
	ifstream inThird("third.txt");
	ifstream inFour("fourth.txt");
	
	while(getline(inBranch, arr[count].branch)){
		inFirst >> arr[count].first;
		inSec >> arr[count].sec;
		inThird >> arr[count].third;
		inFour >> arr[count].fourth;
		count++;
	}
}

void calcAnnual(Sales arr[], int ann[], int count){
	for(int i=0; i<count; i++){
		ann[i] = arr[i].first + arr[i].sec + arr[i].third + arr[i].fourth;
	}
}

int calcTotal(int ann[], int count){
	int sum=0;
	for(int i=0; i<count; i++){
		sum += ann[i];
	}
	return sum;
}

int findMaxIndex(int ann[], int count){
	int maxIndex = 0, max = ann[0];
	for(int i=0; i<count; i++){
		if(ann[i] > max){
			max = ann[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void displayOutput(Sales arr[], int count, int ann[], int total, int maxIndex){
	cout<<setw(30)<<left<<"BRANCH"
		<<setw(15)<<left<<"QUARTER 1"
		<<setw(15)<<left<<"QUARTER 2"
		<<setw(15)<<left<<"QUARTER 3"
		<<setw(15)<<left<<"QUARTER 4"
		<<setw(15)<<left<<"ANNUAL SALE"<<endl<<endl;
	for(int i=0; i<count; i++){
		cout<<setw(30)<<left<<arr[i].branch
			<<setw(15)<<left<<arr[i].first
			<<setw(15)<<left<<arr[i].sec
			<<setw(15)<<left<<arr[i].third
			<<setw(15)<<left<<arr[i].fourth
			<<setw(15)<<left<<ann[i]
			<<endl;
	}
	cout<<endl;
	cout<<"OVERALL REPORT"<<endl;
	cout<<"=============="<<endl;
	cout<<"GRAND TOTAL SALES = "<<total<<endl;
	cout<<"HIGHEST BRANCH SALE = "<<ann[maxIndex]<<endl;
	cout<<"BRANCH NAME: "<<arr[maxIndex].branch<<endl;
}
