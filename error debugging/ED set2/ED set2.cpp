//FinalQ1.cpp
#include <iostream>
#include <string>
#define SIZE 3
using namespace std;

string *getMenu() {
	string *p_data = new string;
	cout << "Menu name: ";
	getline(cin, *p_data);
	return p_data;
}

void getPricePcs(string caption, int *p_data) {
	cout << caption;
	cin >> *p_data;
}

int cheapestMenu(string *m[], int *pr[], int *pc[]) {
	float pcs_price, pcs_price_lowest = 999;
	int idx;
	cout << "Check chicken price per-pcs: \n";
	for (int i = 0; i < SIZE; i++) {
		pcs_price = (float) *pr[i] / *pc[i];
		cout << *m[i] << " - " << pcs_price << "\n";
		if (pcs_price_lowest > pcs_price) {
			pcs_price_lowest = pcs_price;
			idx = i;
		}
	}
	cout << "\n";
	return idx;
}

// Start main function
int main() {
	string *menus [SIZE];
	int *price[SIZE];
	int *pcs [SIZE]; // pieces of chicken
	// Examples of menus, price and pcs of chicken
	// Chicken Deluxe - RM 30 - 5 pcs
	// Happy Combo - RM 51 - 8 pcs
	// Family Bucket - RM 75 - 15 pcs
	for (int i = 0; i < SIZE; i++) {
		menus[i] = getMenu();
		price[i] = new int;
		pcs[i] = new int;
		getPricePcs("Price (RM): ", price[i]);
		getPricePcs("Chicken (pcs): ", pcs[i]);
		cin.ignore(); // need this as we mix the use of getline and cin
		cout << "\n";
	}
	int idx_cheapest = cheapestMenu(menus, price, pcs);
	cout << "Cheapest menu is " << *menus[idx_cheapest]
		 << " priced at RM " << *price[idx_cheapest] << " for "
		 << *pcs[idx_cheapest] << " pieces of chicken\n\n";
	
	// delete array data from memory
	for (int i = 0; i < SIZE; i++) {
		delete menus[i];
		delete price[i];
		delete pcs[i];
	}
	return 0;
}
