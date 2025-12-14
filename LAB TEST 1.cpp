#include <iostream>
#include <iomanip>
using namespace std;

// Prototype Declaration
double getPrice(int roomType);
double calculateDiscount(int nights, double subtotal);
void computeAmounts(int roomType, int nights, double& subtotal, double& discount, double& afterDiscount);
double applyPromo(bool hasPromo, double amountAfterFirstDiscount);
void displayMessage(double finalTotal);
void displaySummary(const string& roomName, double pricePerNight, int nights, double subtotal, double discount, double promoAmount, double finalTotal);

// Returns the room's price per night.
double getPrice(int roomType) {
    if (roomType == 1) {
        return 150.0;
    }
    else if (roomType == 2) {
        return 200.0;
    }
    else if (roomType == 3) {
        return 300.0;
    }
    return 0.0;
}

// Returns the discount amount (based on subtotal and nights).
double calculateDiscount(int nights, double subtotal) {
    double rate = 0.0;
    if (nights >= 3 && nights <= 5) {
        rate = 0.05;
    }
    else if (nights > 5) {
        rate = 0.10;
    }
    return subtotal * rate;
}

// Computes subtotal, discount and after discount per nights and returns via reference parameters.
void computeAmounts(int roomType, int nights, double& subtotal, double& discount, double& afterDiscount) {
    double price = getPrice(roomType);
    subtotal = price * nights;
    discount = calculateDiscount(nights, subtotal);
    afterDiscount = subtotal - discount;
}

// Returns the promo discount amount (10% of amountAfterFirstDiscount if promo applies).
double applyPromo(bool hasPromo, double amountAfterFirstDiscount) {
    if (hasPromo) {
        return amountAfterFirstDiscount * 0.10;
    }
    return 0.0;
}

// This function displays the appropriate final message.
void displayMessage(double finalTotal) {
    if (finalTotal > 1200.0) {
        cout << "You are eligible for free airport transfer." << endl;
        cout << "======================================================" << endl;
    }
    else if (finalTotal < 300.0) {
        cout << "Enjoy your vacation." << endl;
        cout << "======================================================" << endl;
    }
    else {
        cout << "Thank you for booking with FTMK Grand Hotel." << endl;
        cout << "======================================================" << endl;
    }
}

// This function prints the booking summary.
void displaySummary(const string& roomName, double pricePerNight, int nights, double subtotal, double discount, double promoAmount, double finalTotal) {
    cout << fixed << setprecision(2);
    cout << "\n------------------ BOOKING SUMMARY ------------------\n";
    cout << "Price per Night  : RM" << pricePerNight << "\n";
    cout << "Nights Stayed    : " << nights << "\n";
    cout << "Subtotal         : RM" << subtotal << "\n";
    cout << "Discount         : RM" << discount << "\n";
    cout << "----------------------------------------------------\n";
    cout << "Final Total      : RM" << finalTotal << "\n";
    cout << "----------------------------------------------------\n";
}

int main() {
    cout << "==========================================\n";
    cout << "\tFTMK GRAND HOTEL BOOKING SYSTEM\n";
    cout << "==========================================\n";
    cout << "1. Standard Room - RM150.00 per night\n";
    cout << "2. Deluxe Room   - RM200.00 per night\n";
    cout << "3. Suite Room    - RM300.00 per night\n";
    cout << "-----------------------------------------\n";

    double grandTotal = 0.0;
    char moreBookings = 'Y';

    while (moreBookings == 'Y' || moreBookings == 'y') {
        int roomType;
        int nights;

        cout << "Enter room type (1-3): ";
        if (!(cin >> roomType)) {
            cout << "Invalid input. Room type must be a number.\n";
            return 1;
        }
        else if (roomType < 1 || roomType > 3) {
            cout << "Error: Invalid room type. Please enter 1, 2 or 3.\n";
            // Ask whether to continue with another booking
            cout << "Do you want to try another booking? (Y/N): ";
            cin >> moreBookings;
            continue;
        }

        cout << "Enter number of nights: ";
        if (!(cin >> nights)) {
            cout << "Invalid input. Number of nights must be a number.\n";
            return 1;
        }
        else if (nights <= 0) {
            cout << "Error: Number of nights must be greater than 0.\n";
            cout << "Do you want to try another booking? (Y/N): ";
            cin >> moreBookings;
            continue;
        }

        string roomName;
        if (roomType == 1) {
            roomName = "Standard Room";
        }
        else if (roomType == 2) {
            roomName = "Deluxe Room";
        }
        else {
            roomName = "Suite Room";
        }

        cout << "\nYou selected " << roomName << ".\n";

        // Compute amounts
        double subtotal = 0.0, discount = 0.0, afterDiscount = 0.0;
        computeAmounts(roomType, nights, subtotal, discount, afterDiscount);

        // Promo prompt
        char promoChar;
        cout << "\nDo you have a promo code? (Y for Yes / N for No): ";
        cin >> promoChar;
        bool hasPromo = (promoChar == 'Y' || promoChar == 'y');

        double promoAmount = applyPromo(hasPromo, afterDiscount);
        double finalTotal = afterDiscount - promoAmount;

        // Display summary and message for this booking
        double pricePerNight = getPrice(roomType);
        displaySummary(roomName, pricePerNight, nights, subtotal, discount, promoAmount, finalTotal);
        displayMessage(finalTotal);

        // Accumulate grand total
        grandTotal = grandTotal + finalTotal;

        // Ask if user wants to add more bookings
        cout << "\nDo you want to add another booking? (Y/N) : ";
        cin >> moreBookings;
    }
    return 0;
}