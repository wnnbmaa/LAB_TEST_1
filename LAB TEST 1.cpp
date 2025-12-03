#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int roomType, nights;
	double subtotal, discountAmount, totalAfterFirstDiscount, promoDiscount, finalTotal;
	char promoChar;

	double pricePerNight = 0.0;
	double discountRate = 0.0;
	double promoRate = 0.0;

	cout << "==========================================" << endl;
	cout << "\tFTMK GRAND HOTEL BOOKING SYSTEM" << endl;
	cout << "==========================================" << endl;
	cout << "1. Standard room - RM150.00 per night" << endl;
	cout << "2. Deluxe Room   - RM200.00 per night" << endl;
	cout << "3. Suite Room    - RM300.00 per night" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Enter room type (1-3): ";
	cin >> roomType;
	cout << "Enter number of nights: ";
	cin >> nights;

	// Determine room name and price per night using selection
	if (roomType == 1) {
		cout << "\nYou selected Standard Room." << endl;
		pricePerNight = 150.0;
	}
	else if (roomType == 2) {
		cout << "\nYou selected Deluxe Room." << endl;
		pricePerNight = 200.0;
	}
	else if (roomType == 3) {
		cout << "\nYou selected Suite Room." << endl;
		pricePerNight = 300.0;
	}
	else {
		cout << "\nInvalid room type. Enter 1, 2 or 3." << endl;
	}

	// Calculate subtotal
	subtotal = pricePerNight * nights;

	// Discount policy based on number of nights
	if (nights <= 2) {
		discountRate = 0.0;
	}
	else if (nights <= 5) {
		discountRate = 0.05; // 5%
	}
	else {
		discountRate = 0.10; // 10%
	}

	discountAmount = subtotal * discountRate;
	totalAfterFirstDiscount = subtotal - discountAmount;

	// Promo code (additional 10% off the total after first discount)
	cout << "\nDo you have a promo code? (Y for Yes / N for No): ";
	cin >> promoChar;

	if (promoChar == 'Y' || promoChar == 'y') {
		promoRate = 0.10; // additional 10%
	}

	promoDiscount = totalAfterFirstDiscount * promoRate;
	finalTotal = totalAfterFirstDiscount - promoDiscount;

	// Output booking summary with currency formatting
	cout << fixed << setprecision(2);
	cout << "\n------------------ BOOKING SUMMARY ------------------" << endl;
	cout << "Price per Nights : RM" << pricePerNight << endl;
	cout << "Nights Stayed    : " << nights << endl;
	cout << "Subtotal         : RM" << subtotal << endl;
	cout << "Discount (" << (discountRate * 100.0) << "%) : RM" << discountAmount << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Final total      : RM" << finalTotal << endl;
	cout << "----------------------------------------------------" << endl;

	// Personalized messaging based on final total
	if (finalTotal > 1200.0) {
		cout << "VIP CUSROMER: You are eligible for free airport transfer." << endl;
	}
	else if (finalTotal < 300.0) {
		cout << "Enjoy yout vacation." << endl;
	}
	else {
		cout << "Thank you for booking with FTMK Grand Hotel." << endl;
	}

	cout << "=====================================================";

	return 0;
}