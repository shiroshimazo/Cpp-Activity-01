#include <iostream>
#include <cstdio>
using namespace std;

void createItem(int, string, int, double);
void selectData();
void retrieveData();
void updateData();
void deleteData();
void selectMethod(string);
void selectUser();

int itemID[99];
string itemName[99];
int itemQuantity[99];
double itemPrice[99];
int static dataCount = 0;

int main() {
    selectUser(); 
    return 0;
}

void createItem(int ID, string Name, int itemQty, double price) {
    itemID[dataCount] = ID;
    itemName[dataCount] = Name;
    itemQuantity[dataCount] = itemQty;
    itemPrice[dataCount] = price;
    dataCount++;
}

void selectData() {
    int tempID;
    string tempName;
    int tempQty;
    double tempPrice;
    bool insertData = true;
    
    while (insertData != false) {
        cout << "\n\tEnter item ID: ";
        cin >> tempID;
        cout << "\n\tEnter item Name: ";
        cin >> tempName;
        cout << "\n\tEnter item Quantity: ";
        cin >> tempQty;
        cout << "\n\tEnter item Price: ";
        cin >> tempPrice;

        createItem(tempID, tempName, tempQty, tempPrice);

        char condition;
        cout << "\n\tPress Y to YES if you want to insert again." << endl;
        cout << "\n\tPress N to NO if you want to stop." << endl;
        cout << "\n\tResponse: ";
        cin >> condition;

        clrscrn();

        if (condition == 'Y' || condition == 'y') {
            insertData = true;
        } else {
            retrieveData();
            insertData = false;
        }
    }

}

void retrieveData() {
    cout << "\n\tCurrent Item are.....\n" << endl;
    cout << "\n\tID\tName\tQTY\tPrice" << endl;

    for (int x = 0; x < dataCount; x++) {
        cout << "\t" <<itemID[x] << "\t" << itemName[x] << "\t" << itemQuantity[x] <<
        "\t" << itemPrice[x] << endl;
    } cout << endl;
}

void updateData() {
    int searchID;
    cout << "\nUPDATE SECTION\n" << endl;
    cout << "\tPlease Enter Item ID: ";
    cin >> searchID;

    for (int x = 0; x < dataCount; x++) {
        if (itemID[x] == searchID) {
            cout << "\n\tCurrent Data to be Update!\n" << endl;
            cout << "\n\tID\tName\tQTY\tPrice" << endl;
            cout << "\t" <<itemID[x] << "\t" << itemName[x] << "\t" << itemQuantity[x] <<
            "\t" << itemPrice[x] << "\t" << endl;

            char select = 0;
            cout << "\n\tPress 1 to Update 'Item Name'." << endl;
            cout << "\tPress 2 to Update 'Item Quantity'." << endl;
            cout << "\tPress 3 to Update 'Item Price'." << endl;
            cout << "\tResponse: ";
            cin >> select;

            clrscrn();

            string newItem;
            int newQty;
            double newPrice;

            switch (select) {
                case '1':
                       cout << "\nPlease Enter new 'Item Name': ";
                       cin >> newItem;
                       itemName[x] = newItem;
                break;
                case '2':
                       cout << "\nPlease Enter new 'Item Quantity': ";
                       cin >> newQty;
                       itemQuantity[x] = newQty;
                break;
                case '3':
                       cout << "\nPlease Enter new 'Item Price': ";
                       cin >> newPrice;
                       itemPrice[x] = newPrice;
                break;
                default:
                       cout << "\n\tInvalid Choice! Try Again!";
                       updateData();
                break;
            }
        }
        if (itemID[x] != searchID && x == dataCount-1) {
            cout << "\n\tItem ID not Found!" << endl;
        }
    }
}

void deleteData() {
    
}

void selectMethod(string typeOfUser) {
    if(typeOfUser == "admin") {
        cout << "\n\tPress 1 to Create Data." << endl;
        cout << "\tPress 2 to Retrieve Data." << endl;
        cout << "\tPress 3 to Update Data." << endl;
        cout << "\tPress 4 to Delete Data." << endl;
        cout << "\tPress 5 to Log Out Current User." << endl;
        cout << "\tResponse: ";
        char response;
        cin >> response;

        clrscrn();

        switch(response) {
            case '1':
                  selectData();
                  selectMethod("admin");
            break;
            case '2':
                  retrieveData();
                  selectMethod("admin");
            break;
            case '3':
                  updateData();
                  selectMethod("admin");
            break;
            case '4':
                  deleteData();
                  selectMethod("admin");
            break;
            case '5':
                  selectUser();
            break;
            default:
                   cout << "\n\tInvalid Choice! Try Again!";
                   selectMethod("admin");
            break;
        }
    }
}

void selectUser() {
    int attempt = 3;
    while (attempt != 0) {
        string username, password;

        cout << "\n\tENTER VALID CREDENTIALS\n" << endl;
        cout << "\tEnter username: ";
        cin >> username;
        cout << "\tEnter password: ";
        cin >> password;

        clrscrn();

        if (username == "ADMIN" && password == "ADMIN") {
            selectMethod("admin");
        } else if (username == "employee" && password == "emp123") {
            selectMethod("employee");
        } else if (username == "customer" && password == "cus123") {
            selectMethod("customer");
        } else {
            attempt --;
            cout << "\n\tUsername or Password is incorrect!" << endl;
            cout << "\n\tNumber of attempt is: " << attempt << endl;
        }
    }
}

void clrscrn() {
    system("clear");
}