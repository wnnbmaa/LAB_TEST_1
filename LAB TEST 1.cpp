#include <iostream>
#include <iomanip>
using namespace std;

// Prototype Declaration
double getPrice(int roomType);
double calculateDiscount(int nights, double subtotal);
void computeAmounts(int nights, double pricePerNight, double &subtotal, double &discount, double &afterDiscount);
double applyPromo(char hasPromo, double afterDiscount);
void displayMessage(double finalTotal);
void displaySummary(double pricePerNight, int nights, double subtotal, double discount, double promoAmount, double finalTotal);

// Return room price per night based on room type
double getPrice(int roomType) {
	double pricePerNight = 0.0;
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
	return pricePerNight;
}

// Return discount amount (based on nights and subtotal)
double calculateDiscount(int nights, double subtotal) {
	double discountRate = 0.0;
	if (nights <= 2) {
		discountRate = 0.0;
	}
	else if (nights <= 5) {
		discountRate = 0.05; // 5%
	}
	else {
		discountRate = 0.10; // 10%
	}
	return discountRate;
}

// Compute subtotal, discount and afterDiscount via reference parameters
void computeAmounts(int nights, double pricePerNight, double &subtotal, double &discount, double &afterDiscount) {
	subtotal = pricePerNight * nights;
	discount = calculateDiscount(nights, subtotal);
	afterDiscount = subtotal - discount;
}

// Return promo discount amount (10% on afterDiscount if promo applied)
double applyPromo(char hasPromo, double afterDiscount) {
	double promoRate = 0.0;
	if (hasPromo == 'Y' || hasPromo == 'y') {
		promoRate = 0.10; // additional 10%
	}
	return promoRate;
}

// Display final message based on finalTotal
void displayMessage(double finalTotal) {
	if (finalTotal > 1200.0) {
		cout << "VIP CUSROMER: You are eligible for free airport transfer." << endl;
	}
	else if (finalTotal < 300.0) {
		cout << "Enjoy yout vacation." << endl;
	}
	else {
		cout << "Thank you for booking with FTMK Grand Hotel." << endl;
	}
}

// Print booking summary for a single booking
void displaySummary(double pricePerNight, int nights, double subtotal, double discount, double promoAmount, double finalTotal) {
	cout << fixed << setprecision(2);
	cout << "\n------------------ BOOKING SUMMARY ------------------" << endl;
	cout << "Price per Nights : RM" << pricePerNight << endl;
	cout << "Nights Stayed    : " << nights << endl;
	cout << "Subtotal         : RM" << subtotal << endl;
	cout << "Discount         : RM" << discount << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Final total      : RM" << finalTotal << endl;
	cout << "----------------------------------------------------" << endl;
}

int main()
{
	int roomType, nights;
	double subtotal, discountAmount, totalAfterFirstDiscount, promoDiscount, finalTotal = 0.0, pricePerNight;
	char hasPromo = 'y', promoChar;
	double afterDiscount = 0.0, discount, promoAmount = 0.0;

	cout << "==========================================" << endl;
	cout << "\tFTMK GRAND HOTEL BOOKING SYSTEM" << endl;
	cout << "==========================================" << endl;
	cout << "1. Standard room - RM150.00 per night" << endl;
	cout << "2. Deluxe Room   - RM200.00 per night" << endl;
	cout << "3. Suite Room    - RM300.00 per night" << endl;
	cout << "-----------------------------------------" << endl;

	double total = 0.0;
	char more = 'Y';

	while (more == 'Y' || more == 'y') {
		int roomType = 0;
		int nights = 0;

		do {
			cout << "Enter room type (1-3): ";
			if (!(cin >> roomType)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				roomType = 0;
			}
			if (roomType < 1 || roomType > 3) {
				cout << "\nInvalid room type. Enter 1, 2 or 3." << endl;
			}
		} while (roomType < 1 || roomType > 3);

		do {
			cout << "Enter number of nights: ";
			if (!(cin >> nights)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				nights = 0;
			}
			if (nights <= 0) {
				cout << "\tInvalid number. Enter a positive integer." << endl;
			}
		} while (nights <= 0);

		// Determine room name and price per night using selection
		double pricePerNight = 0.0;
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

		// Calculate subtotal
		subtotal = pricePerNight * nights;

		cout << "\n\tAdd more order? (Y/N): ";
		cin >> more;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Discount policy based on number of nights
		double discountRate = calculateDiscount(nights, subtotal);

		// Promo code (additional 10% off the total after first discount)
		cout << "\nDo you have a promo code? (Y for Yes / N for No): ";
		cin >> promoChar;
		promoDiscount = applyPromo(hasPromo, afterDiscount);
		
		computeAmounts(nights, pricePerNight, subtotal, discount, afterDiscount);
		
		displaySummary(pricePerNight, nights, subtotal, discount, promoAmount, finalTotal);

		displayMessage(finalTotal);
	}
	return 0;
}