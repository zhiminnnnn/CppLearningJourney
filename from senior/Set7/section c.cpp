#include <iostream>
#include <iomanip>
#include <fstream>
#define MAX 100
using namespace std;

ofstream out("overdue.txt");

struct Detail{
	string name;
	int acc;
	double charge;
	double pay;
};

double generateOverdue(Detail a[], int count);
void summaryProfit(Detail a[], int count, double over);

int main(){
	Detail *arr = new Detail [MAX];
	int count = 0;
	cout << "Enter number of customer: ";
	cin >> count;
	cin.ignore();
	cout << endl;
		
	for(int i=0; i<count; i++){
		cout << "Customer #" << i+1 << endl;
		cout << "Name: ";
		getline(cin, arr[i].name);
		cout << "Account number: ";
		cin >> arr[i].acc;
		cout << "To-date charges (RM): ";
		cin >> arr[i].charge;
		cout << "To-date payment (RM): ";
		cin >> arr[i].pay;
		cin.ignore();
		cout << endl;
	}
	double over = generateOverdue(arr, count);
	summaryProfit(arr, count, over);
	delete [] arr;
	return 0;
}

double generateOverdue(Detail a[], int count){
	double sum = 0;
	for(int i=0; i<count; i++){
		sum += (a[i].pay - a[i].charge);
		out << "Customer #" << i+1 << endl;
		out << "Name: " << a[i].name << endl;
		out << "Account number: " << a[i].acc << endl;
		out << "Overdue amount (RM): " << a[i].pay - a[i].charge << endl << endl;
	}
	return sum;
}

void summaryProfit(Detail a[], int count, double over){
	double totCharge = 0, totPay = 0;
	for(int i=0; i<count; i++){
		totCharge += a[i].charge;
		totPay += a[i].pay;
	}
	cout << "UTM-Mobile MONTHLY PROFIT" << endl;
	cout << "Number of customer: " << count << endl;
	cout << fixed << setprecision(2);
	cout << "Total Charges (RM): " << totCharge << endl;
	cout << "Total Paid (RM): " << totPay << endl;
	cout << "Total Overdue (RM): " << over << endl;
}
