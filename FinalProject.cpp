#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

// VALID CARD NUMBERS: 5105105105105100 | 5555555555554444

const int BREAKFAST_ITEMS = 10;
const int LUNCH_ITEMS = 7;
const int DINNER_ITEMS = 7;

// Defining colour codes
#define RESET   "\033[0m"        //default
#define RED     "\033[31m"      // Red 
#define GREEN   "\033[32m"      // Green 
#define YELLOW  "\033[33m"      // Yellow 
#define BLUE    "\033[34m"      // Blue 

string breakfastItems[BREAKFAST_ITEMS] = {"Chanay", "Paratha", "Omelete", "Fried Egg", "Halwa Poori", "Kunda Dahi", "Lassi", "Plain Cake", "Gulab Jaman", "Aloo Ki Bhujia"};
int breakfastPrices[BREAKFAST_ITEMS] = {120, 50, 60, 30, 120, 50, 120, 40, 60, 70};

string mondayItems[14] = {"Chicken Palak", "Yakhni Pullao", "Sauteed Vegetables", "Daal Sabat Moong", "Boiled Rice", "Kulcha", "Fish with Hot Garlic Sauce","Chicken Masala Biryani", "Khattay Baingan", "Kalay Chanay", "Garlic Fried Rice","Vegetable Crunchy Sandwich", "Boiled Rice", "Finger Fish"};
int mondayPrices[14] = {250, 150, 120, 180, 140, 40, 350, 300, 180, 130, 200, 100, 140, 300};

string tuesdayItems[14] = {"Chicken with Vegetables", "Aloo Gobi", "Chicken Qeema", "Boiled Egg", "Banana", "Chanay ki Daal", "Chicken Karahi", "White Qorma", "Chicken Tikka", "Baked Chicken", "Daal Moong", "Torai", "Boiled Rice", "Fresh Salad"};
int tuesdayPrices[14] = {180, 130, 250, 30, 20, 180, 280, 280, 300, 180, 160, 140, 140, 50};

string wednesdayItems[14] = {"Chicken Black Pepper Karahi", "Chicken Pullao", "Daal Masoor", "Chowmein", "White Rice", "Lasagne", "Burger", "Chicken Broast", "Steamed and Peppered Chicken", "Spaghetti", "Aloo Palak", "Boiled Rice", "Sarson ka Saag", "Red Lobia"};
int wednesdayPrices[14] = {280, 180, 160, 300, 160, 300, 220, 250, 220, 250, 180, 140, 140, 160};

string thursdayItems[14] = {"Chicken Pullao", "White Qorma", "Egg Fried Rice", "Chowmein", "Finger Fish", "Fresh Salad", "Daal Sabat Masoor", "Chicken Tikka", "Anday Wala Burger", "Daal Maash", "Gujarati Handi", "Boiled Egg", "White Rice", "Fresh Salad"};
int thursdayPrices[14] = {180, 260, 250, 300, 300, 50, 170, 280, 190, 180, 320, 30, 140, 50};

string fridayItems[14] = {"Karhi Phulki", "Chicken Palak", "Chicken Biryani", "Chicken Manchurian", "Garlic Naan", "Boiled Rice", "Daal Makhni", "Chicken Broast", "Grilled Chicken with Black Pepper", "Daal Sabat Masoor", "Garlic Fried Rice", "Kulcha", "Boiled Rice", "Kalay Chanay"};
int fridayPrices[14] = {170, 250, 250, 300, 40, 140, 170, 240, 260, 160, 200, 40, 140, 130};

//tuesday ka menu repeat 
string saturdayItems[14] = {"Chicken with Vegetables", "Aloo Gobi", "Chicken Qeema", "Boiled Egg", "Banana", "Chanay ki Daal", "Chicken Karahi", "White Qorma", "Chicken Tikka", "Baked Chicken", "Daal Moong", "Torai", "Boiled Rice", "Fresh Salad"};
int saturdayPrices[14] = {180, 130, 250, 30, 20, 180, 280, 280, 300, 180, 160, 140, 140, 50};
 
//wednesday ka repeat 
string sundayItems[14] = {"Chicken Black Pepper Karahi", "Chicken Pullao", "Daal Masoor", "Chowmein", "White Rice", "Lasagne", "Burger", "Chicken Broast", "Steamed and Peppered Chicken", "Spaghetti", "Aloo Palak", "Boiled Rice", "Sarson ka Saag", "Red Lobia (ew)"};

int sundayPrices[14] = {280, 180, 160, 300, 160, 300, 220, 250, 220, 250, 180, 140, 140, 160};


string userList[50][3];
int userCounter = 0;


void addToList(string userChoice, int price, int quantity) {
    *(*(userList + userCounter)) = userChoice;
    *(*(userList + userCounter) + 1) = to_string(quantity);
    *(*(userList + userCounter) + 2) = to_string(price * quantity);
    userCounter++;
}

void displayMenu(string* items, int* prices, int itemCount) {
//cout << "Menu:" << endl;
    for (int i = 0; i < itemCount; ++i) {
        cout << (i + 1) << ". " << *(items + i) << " - Rs " << *(prices + i) << endl;
    }
}

string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string dateTime = asctime(ltm); //to format the date and timet
    return dateTime;
}

void PackOrNot() {
    string parcel;
    cout << "Do you want to get your food packed? Yes or No: ";
    cin >> parcel;
    if (parcel == "yes" || parcel == "Yes" || parcel == "Y" || parcel == "y") {
        cout << " \t \t \b \b \b \b \b \bYour freshly packed food is ready." << endl;
    }
    else {
        cout << "\t \b \b \b Your freshly prepared food has been served." << endl;
    }
}

int calculateTotal(int index = 0, int total = 0) {
    if (index >= userCounter) {
        return total;
    }
    total += stoi(*(*(userList + index) + 2)); 
    return calculateTotal(index + 1, total); 
}


string getMenuChoice(string day, string mealType) {
    string* selectedDayItems = nullptr;
    int* selectedDayPrices = nullptr;
    int startIndex = 0, endIndex = 0;

    if (mealType == "Breakfast" || mealType == "breakfast" || mealType == "BREAKFAST" || mealType == "1") {
        selectedDayItems = breakfastItems;
        selectedDayPrices = breakfastPrices;
        endIndex = BREAKFAST_ITEMS - 1;
    } 
    else if (mealType == "Lunch" || mealType == "lunch" || mealType == "LUNCH" || mealType == "2") {
        if (day == "Monday" || day == "monday" || day == "MONDAY" || day == "1") {
            selectedDayItems = mondayItems; 
            selectedDayPrices = mondayPrices;
            endIndex = 6; 
    } 
        else if (day == "Tuesday" || day == "tuesday" || day == "TUESDAY" || day == "2") {
            selectedDayItems = tuesdayItems;
            selectedDayPrices = tuesdayPrices;
            endIndex = 6;
    }   
        else if (day == "Wednesday" || day == "wednesday" || day == "WEDNESDAY" || day == "3") {
            selectedDayItems = wednesdayItems;
            selectedDayPrices = wednesdayPrices;
            endIndex = 6;
    }  
        else if (day == "Thursday" || day == "thursday" || day == "THURSDAY" || day == "4") {
            selectedDayItems = thursdayItems;
            selectedDayPrices = thursdayPrices;
            endIndex = 6;
    }  
        else if (day == "Friday" || day == "friday" || day == "FRIDAY" || day == "5") {
            selectedDayItems = fridayItems;
            selectedDayPrices = fridayPrices;
            endIndex = 6;
    }  
        else if (day == "Saturday" || day == "saturday" || day == "SATURDAY" || day == "6") {
            selectedDayItems = saturdayItems;
            selectedDayPrices = saturdayPrices;
            endIndex = 6;
    }  
        else if (day == "Sunday" || day == "sunday" || day == "SUNDAY" || day == "7") {
            selectedDayItems = sundayItems;
            selectedDayPrices = sundayPrices;
            endIndex = 6;
    }  
    
    } 
    else if (mealType == "Dinner" || mealType == "dinner" || mealType == "DINNER" || mealType == "3") {

        if (day == "Monday" || day == "monday" || day == "MONDAY" || day == "1") {
            selectedDayItems = mondayItems; 
            selectedDayPrices = mondayPrices;
            startIndex = 7; endIndex = 13; 
    } 
        else if (day == "Tuesday" || day == "tuesday" || day == "TUESDAY" || day == "2") {
            selectedDayItems = tuesdayItems;
            selectedDayPrices = tuesdayPrices;
            startIndex = 7; endIndex = 13;
    }   
        else if (day == "Wednesday" || day == "wednesday" || day == "WEDNESDAY" || day == "3") {
            selectedDayItems = wednesdayItems;
            selectedDayPrices = wednesdayPrices;
            startIndex = 7; endIndex = 13;
    }  
        else if (day == "Thursday" || day == "thursday" || day == "THURSDAY" || day == "4") {
            selectedDayItems = thursdayItems;
            selectedDayPrices = thursdayPrices;
            startIndex = 7; endIndex = 13;
    }  
        else if (day == "Friday" || day == "friday" || day == "FRIDAY" || day == "5") {
            selectedDayItems = fridayItems;
            selectedDayPrices = fridayPrices;
            startIndex = 7; endIndex = 13;
    }  
        else if (day == "Saturday" || day == "saturday" || day == "SATURDAY" || day == "6") {
            selectedDayItems = saturdayItems;
            selectedDayPrices = saturdayPrices;
            startIndex = 7; endIndex = 13;
    }  
        else if (day == "Sunday" || day == "sunday" || day == "SUNDAY" || day == "7") {
            selectedDayItems = sundayItems;
            selectedDayPrices = sundayPrices;
            startIndex = 7; endIndex = 13;
    }  
        
    //    endIndex = DINNER_ITEMS - 1; 
    } 
    else {
        return "Invalid meal type input!";
    }

    if (day == "1") {
        day = "Monday";
    }
    else if (day == "2") {
        day = "Tuesday";
    }
    else if (day == "3") {
        day = "Wednesday";
    }
    else if (day == "4") {
        day = "Thursday";
    }
    else if (day == "5") {
        day = "Friday";
    }
    else if (day == "6") {
        day = "Saturday";
    }
    else if (day == "7") {
        day = "Sunday";
    }

    cout << "Menu for " << day << "'s " << mealType << ":" << endl;
    displayMenu(selectedDayItems + startIndex, selectedDayPrices + startIndex, endIndex - startIndex + 1);

    int choice = 0; int end = 0;
    cout << "Enter the number of your choice (-1 to stop adding items to cart): ";
    cin >> choice;

    if (mealType == "Breakfast" || mealType == "breakfast") 
    {
        end = BREAKFAST_ITEMS;
    }
    else
    {
        end = 7;
    }
    

    while(cin.fail() || choice < 1 || choice > end)
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter a correct number: (-1 to stop adding items to cart): ";
        cin >> choice;
    }

    while (choice >= 1 && choice <= (endIndex + 1)) {
        string userChoice = *(selectedDayItems + startIndex + choice - 1);
        int price = *(selectedDayPrices + startIndex + choice - 1);
        int quantity;
        cout << endl;
        cout << "Enter the quantity for " << userChoice << ": ";
        cin >> quantity;

        while (quantity < 0) {
            cout << "Invalid input. Please enter the quantity for " << userChoice << " again: ";
            cin >> quantity;
        }

        string portion;

        if (mealType != "Breakfast" && mealType != "breakfast")
        {
            cout << "Do you want Half or Full Portion? ";
            cin >> portion;

            if (portion == "Half" || portion == "half") {
                price = price / 2;
        }
        }

        addToList(userChoice, price, quantity);
        cout << endl;

        cout << "Enter the number of your choice (-1 to stop adding items to cart): ";
        cin >> choice;

        if (mealType == "Breakfast" || mealType == "breakfast") 
        {
            end = BREAKFAST_ITEMS;
        }

        else
        {
            end = 7;
        }

        while(cin.fail() || choice == 0 || choice > end)
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter a correct number: (-1 to stop adding items to cart): ";
            cin >> choice;
        }
    }

    if (choice != -1) {
        string userChoice = *(selectedDayItems + startIndex + choice - 1);
        return userChoice;
    } else {
        return "";
    }
}

// PAYMENT METHOD FUNCTION

int getPaymentMethod()
{
    cout << "Enter payment method (1 for cash, 2 for credit/debit card): ";
    int option; cin >> option;

    return option;
}


int calculateChange(int amountReceived, int amountDue)
{
    return (amountReceived - amountDue);
}


bool checkCardValidity(string cardNumber)
{
    if (cardNumber.length() != 16)
    {
        return false;
    }
    
    int total = 0;
    int digit = 0;

    for (int i = cardNumber.length() - 1; i >= 0; i--)
    {
        // converting each character to equivalent integer
        digit = cardNumber[i] - '0';

        // checking if every second digit from the right has a double greater than 9
        if ((i % 2) == 0)
        {
            digit *= 2;

            if (digit > 9) {digit = (digit / 10) + (digit % 10);}

        }
        total += digit;
    }

    if ((total % 10) == 0)
    {
        return 1;
    }

    return 0;
}


int main() 
{

    string day, mealType;
    int totalPrice = 0, paymentMethod = 0;

    cout << "\t \t| WELCOME TO PDC | " << endl;

    string userChoice;

    do
    {
        cout << "Enter the day of the week: ";
        cin >> day;

        cout << "Enter the meal type from Breakfast, Lunch, or Dinner: ";
        cin >> mealType;
        if( mealType == "1") {
            mealType = "Breakfast";
        }
        else if (mealType == "2") {
            mealType = "Lunch";
        }
        else if (mealType == "3") {
            mealType = "Dinner";
        }

        userChoice = getMenuChoice(day, mealType);

if (userChoice == "Invalid meal type input!") {cout << "Invalid input. Try again." << endl; system("cls");}
        
    } 
    while (userChoice == "Invalid meal type input!");


    int rotiQuantity = -1, drinkQuantity = -1;
    while (rotiQuantity < 0)
    {
        cout << endl << "Enter the number of Roti: ";
        cin >> rotiQuantity;
    }
    while (drinkQuantity < 0)
    {
        cout << endl << "Enter the number of Drinks (includes Tea, Coffee, Milk): ";
        cin >> drinkQuantity;
    }

    addToList("Roti", 20, rotiQuantity); 
    addToList("Drink", 70, drinkQuantity); 

    string myString = "\t\tPEPSI DINING CENTRE";
    cout <<  endl;

    for (int i = 0; i < myString.length(); ++i) {
        if (i % 2 == 0) {
            cout << RED << myString[i];
        } else {
            cout << BLUE << myString[i];
        }
        }

    cout << endl << RESET << "\t\b\bLAHORE UNIVERSITY OF MANAGEMENT SCIENCES" << endl;
    string time = getCurrentDateTime();
    cout << "\t\t \b\b\b\b" << time;
    cout << endl;
    cout << "\t\tYou have selected: " << endl;
    cout << GREEN << "-------------------------------------------------------" << RESET<< endl;

    cout << YELLOW << left << setw(30) << "Item" << setw(20) << "Quantity" << setw(13) << "Price" << RESET << endl;

    for (int i = 0; i < userCounter; ++i) {
        if ((*(*(userList + i) + 0) == "Roti" && *(*(userList + i) + 1) != "0") || (*(*(userList + i) + 0) == "Drink" && *(*(userList + i) + 1) != "0")) {
            if (i % 2 == 0) {
                cout << BLUE;
            } else {
                cout << RED;
            }
            cout << left << setw(30) << *(*(userList + i) + 0) << setw(20) << *(*(userList + i) + 1) << setw(13) << *(*(userList + i) + 2) << RESET << endl;
        } else {
            if (*(*(userList + i) + 1) != "0") {
                if (i % 2 == 0) {
                    cout << BLUE;
                } else {
                    cout << RED;
                }
                cout << left << setw(30) << *(*(userList + i) + 0) << setw(20) << *(*(userList + i) + 1) << setw(13) << *(*(userList + i) + 2) << RESET << endl;
            }
        }
    }
    cout << endl;

    totalPrice = calculateTotal(); 

    cout << "\t \t Total Price: " << GREEN << totalPrice << RESET << endl << endl; 
    paymentMethod = getPaymentMethod();

    switch (paymentMethod)
    {
        case 1:
            {
                int amountReceived; 
                cout << "Enter amount in cash: Rs. ";
                cin >> amountReceived;
                
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Enter correct amount in cash: Rs. ";
                    cin >> amountReceived;
                }

                while (amountReceived < totalPrice) {
                    cout << "Entered amount is less than the total price. Please enter a larger amount: Rs. ";
                    cin >> amountReceived;
                }    

                int changeDue = calculateChange(amountReceived, totalPrice);

                cout << "Change due: Rs. " << GREEN << changeDue <<  RESET << endl;

                PackOrNot();

                if (changeDue <= 20) {                                              
                    cout << endl << "Sir change nahi hai " << changeDue << " rupay ka aap bubble le lein" <<endl;
                }

                break;
            }
        
        case 2:
            {
                cout << "Enter credit/debit card number (16 digit, no spaces): ";
                string cardNumber; cin >> cardNumber;

                bool flag = true;

                do
                {
                    flag = checkCardValidity(cardNumber);
                    if (flag == false) { cout << RED << "Invalid card number!" << RESET << endl; 
                                         cout << "Please enter another card number: ";
                                         cin >> cardNumber;
                                         flag = checkCardValidity(cardNumber);}
                } 

                while (flag == false);

                if (flag == true)
                {
                    cout << GREEN << "Valid card number... amount deducted!" << RESET << endl;
                    PackOrNot();
                }
                
                break;
            }
    }

    cout << YELLOW << endl <<"\t \t Thank you for eating with us!" << endl;
    cout << "\t  Visit us now at  https://pdc.lums.edu.pk/ " << RESET << endl;
    cout << endl << endl;

    return 0;
}
