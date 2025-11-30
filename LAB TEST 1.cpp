#include <iostream>
#include <iomanip>
using namespace std;

double price1 = 150.00; // room type 1
double price2 = 200.00; // room type 2
double price3 = 300.00; // room type 3

int main()
{
	int roomtype, numnights;
	double price, subtotal, discount, discountnights, adddiscount, totaldiscount, finaltotal;
	char promocode;

	cout << "==========================================" << endl;
	cout << "\tFTMK GRAND HOTEL BOOKING SYSTEM" << endl;
	cout << "==========================================" << endl;
	cout << "1. Standard room - RM150.00 per night" << endl;
	cout << "2. Deluxe Room   - RM200.00 per night" << endl;
	cout << "3. Suite Room    - RM300.00 per night" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Enter room type (1-3): ";
	cin >> roomtype;
	cout << "Enter number of nights: ";
	cin >> numnights;

	if (roomtype == 1) {
		cout << "\nYou selected Standard Room." << endl;
		price = price1;
	}
	else if (roomtype == 2) {
		cout << "\nYou selected Deluxe Room." << endl;
		price = price2;
	}
	else if (roomtype == 3) {
		cout << "\nYou selected Suite Room." << endl;
		price = price3;
	}
	else {
		cout << "\nInvalid room type. Enter 1, 2 or 3." << endl;
	}

	subtotal = price * numnights;
	cout << fixed << setprecision(2);

	if (numnights <= 2) {
		discount = 0;
	}
	else if (numnights <= 5) {
		discount = 0.05;
	}
	else {
		discount = 0.10;
	}

	discountnights = subtotal * discount;

	cout << "\nDo you have a promo code? (Y for Yes / N for No): ";
	cin >> promocode;

	if (promocode == 'Y' || promocode == 'y') {
		adddiscount = 0.10;
	}
	else {
		adddiscount = 0;
	}

	totaldiscount = discountnights * adddiscount;
	finaltotal = subtotal - discount - totaldiscount;

	cout << "\n------------------ BOOKING SUMMARY ------------------" << endl;
	cout << "Price per Nights : RM" << price << endl;
	cout << "Nights Stayed    : " << numnights << endl;
	cout << "Subtotal         : RM" << subtotal << endl;
	cout << "Discount         : RM" << discountnights << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Final total      : RM" << finaltotal << endl;
	cout << "----------------------------------------------------" << endl;

	if (finaltotal > 1200) {
		cout << "VIP CUSROMER: You are eligible for free airport transfer." << endl;
	}
	else if (finaltotal < 300) {
		cout << "Enjoy yout vacation." << endl;
	}
	else {
		cout << "Thank you for booking with FTMK Grand Hotel." << endl;
	}

	cout << "=====================================================";

	return 0;
}