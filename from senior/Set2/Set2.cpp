//Program 9
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#define SIZE 20 //Maximum number of players/ characters
using namespace std; 

struct player
{
	char name[SIZE]; //Player name 
	char team[SIZE]; //Player team
	int goal; //Number of goals
	int assist; //Number of assists
	int point; //Total point
};
//Function prototype
int calcPoints (player [], int); //Function to calculate 
								 //players’ point and to 
								 //determine the best player

//Complete the program start from here
								
int main(){
	player *stats;
	stats = new player [SIZE];
	
	int count = 0;
	
	ifstream infile("input.txt");
	
	if(!infile){
		cout<<"Error";
		return 0;
	}
	else{
		while(infile.getline(stats[count].name, SIZE, ',')){
			infile.getline(stats[count].team, SIZE, ',');
			infile >> stats[count].goal >> stats[count].assist;
			infile.ignore();
			count++;
		}
	}
	infile.close();
	
	int maxIn = calcPoints(stats, count);
	
	cout<<":: LIST OF PLAYERS ::"<<endl;
	for(int i=0; i<count; i++){
		cout << setw(24) << left << stats[i].name
			 << setw(24) << left << stats[i].team
			 << setw(6) << left << stats[i].goal
			 << setw(6) << left << stats[i].assist
			 << setw(6) << left << stats[i].point
			 << endl;
	}
	cout << endl << endl;
	cout << "Best player: "
		 << stats[maxIn].name
		 << " with "
		 << stats[maxIn].point
		 << " from "
		 << stats[maxIn].team;

	delete[] stats;
	return 0;
}

int calcPoints(player arr[], int count){
	for(int i=0; i<count; i++){
		arr[i].point = arr[i].goal*2 + arr[i].assist;
	}
	int maxIn = 0, max = arr[0].point;
	for(int i=0; i<count; i++){
		if(arr[i].point > max){
			max = arr[i].point;
			maxIn = i;
		}
	}
	return maxIn;
}
