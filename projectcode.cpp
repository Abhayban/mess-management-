#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <sstream>

using namespace std;

// Template for handling different types of data
template <typename T>
void printDetail(const string &label, T value) 
{
    cout << label << ": " << value << endl;
}

// Static data and functions in Admin class
class Admin
{
public:
    static map<string, string> adminAccounts;

    static bool authenticate(const string &adminID, const string &password) 
    {
        return adminAccounts.count(adminID) && adminAccounts[adminID] == password;
    }

    static void changePassword(const string &adminID, const string &newPassword) 
    {
        if (adminAccounts.count(adminID)) 
        {
            adminAccounts[adminID] = newPassword;
            cout << "Password changed successfully!\n";
        } 
        else 
        {
            cout << "Admin ID not found!\n";
        }
    }

    static void addAdmin(const string &newAdminID, const string &newPassword) 
    {
        adminAccounts[newAdminID] = newPassword;
        cout << "New admin added successfully!\n";
    }
};

map<string, string> Admin::adminAccounts = { {"sugam", "1234"} };

// Student class demonstrating encapsulation
class Student 
{
public:
    string username;
    string contact;
    
    void registerStudent() 
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter contact: ";
        cin >> contact;
        ofstream outFile("students.txt", ios::app);
        outFile << username << "," << contact << "\n";
        outFile.close();
        cout << "Student registered successfully!\n";
    }
};

// Base class for data management
class MealData 
{
public:
    string date;
    int breakfast;
    int lunch;
    int dinner;
    int snacks;
    int extraItem;
    
    virtual void inputMealData() 
    {
        cout << "------> Enter date (DD-MM-YYYY): ";
        cin >> date;
        cout << "------> Breakfast: ";
        cin >> breakfast;
        cout << "------> Lunch: ";
        cin >> lunch;
        cout << "------> Dinner: ";
        cin >> dinner;
        cout << "------> Snacks: ";
        cin >> snacks;
        cout << "------> Enter the price of Extra Item: ";
        cin >> extraItem;
    }
};

// Derived class with method overriding
class SpecialMealData : public MealData 
{
public:
    void inputMealData() override 
    {
        cout << "(Special Data Entry)\n";
        MealData::inputMealData();
    }
};

class HostelMess 
{
public:
    void addData() 
    {
        string a;
        string pin;
        string username;
        MealData meal;
        cout << "Enter the admin ID: ";
        cin >> a;
        cout << "Enter the password: ";
        cin >> pin;

        if (Admin::authenticate(a, pin)) 
        {
            cout << "------> Enter username: ";
            cin >> username;
            meal.inputMealData();

            ofstream outFile(username + ".txt", ios::app);
            outFile << meal.date << "," << meal.breakfast << "," << meal.lunch << "," << meal.dinner << "," << meal.snacks << "," << meal.extraItem << "\n";
            outFile.close();

            cout << "Data added successfully!\n\n";
        } 
        else 
        {
            cout << "Invalid Admin ID!\n\n";
        }
    }

    void sendNotifications() 
    {
        ifstream inFile("students.txt");
        string line;
        cout << "Sending notifications...\n";
        while (getline(inFile, line)) 
        {
            size_t pos = line.find(',');
            string username = line.substr(0, pos);
            string contact = line.substr(pos + 1);
            cout << "Notification sent to " << username << " (" << contact << ")\n";
        }
        inFile.close();
    }

    void calculateMonthlyExpenses(const string& username, int month) 
    {
    ifstream inFile(username + ".txt");
    if (!inFile) 
    {
        cout << "Error opening file for " << username << "!" << endl;
        return;
    }

    string line;
    int totalBreakfast = 0;
    int totalLunch = 0;
    int totalDinner = 0;
    int totalSnacks = 0;
    int totalExtra = 0;

    while (getline(inFile, line)) 
    {
        string date;
        int breakfast;
        int lunch;
        int dinner;
        int snacks;
        int extraItem;
        string breakfastStr;
        string lunchStr;
        string dinnerStr;
        string snacksStr;
        string extraItemStr;

        istringstream iss(line);
        getline(iss, date, ','); // Read the date

        // Read the meal data as strings, then convert to integers
        if (getline(iss, breakfastStr, ',') &&
            getline(iss, lunchStr, ',') &&
            getline(iss, dinnerStr, ',') &&
            getline(iss, snacksStr, ',') &&
            getline(iss, extraItemStr, ',')) 
            {
            try 
            {
                breakfast = stoi(breakfastStr);
                lunch = stoi(lunchStr);
                dinner = stoi(dinnerStr);
                snacks = stoi(snacksStr);
                extraItem = stoi(extraItemStr);
            } 
            catch (const exception& e) 
            {
                cout << "Error converting meal data to integers: " << e.what() << endl;
                continue; // Skip this line if there's an error
            }
        } 
        else 
        {
            cout << "Error reading meal data from line: " << line << endl;
            continue; // Skip this line if there's an error
        }


        // Ensure the date is in the correct format and month is valid
        if (date.length() == 10 && isdigit(date[3]) && isdigit(date[4])) 
        {
            int entryMonth = stoi(date.substr(3, 2)); // Extract the month correctly
            if (entryMonth == month) {
                totalBreakfast += breakfast;
                totalLunch += lunch;
                totalDinner += dinner;
                totalSnacks += snacks;
                totalExtra += extraItem;
            }
        }
    }
    inFile.close();

    int totalBill = totalBreakfast * 50 + totalLunch * 60 + totalDinner * 70 + totalSnacks * 30 + totalExtra;
    cout << "Monthly expenses for " << username << " in month " << month << ":\n";
    printDetail("Total Breakfast", totalBreakfast);
    printDetail("Total Lunch", totalLunch);
    printDetail("Total Dinner", totalDinner);
    printDetail("Total Snacks", totalSnacks);
    printDetail("Total Extra Items", totalExtra);
    printDetail("Total Bill", totalBill);
}
};

void displayMenu() 
{
    cout <<"*********************************************"<<endl;
    cout << "\t MESS MANAGEMENT SYSTEM\n";
    cout <<"*********************************************"<<endl;
    cout << "1. Register Student\n";
    cout << "2. Add Admin\n";
    cout << "3. Change Admin Password\n";
    cout << "4. Add Data\n";
    cout << "5. Send Notifications\n";
    cout << "6. Calculate Monthly Expenses\n";
    cout << "7. Exit\n";
}

int main() 
{
    HostelMess hm;
    Student student;
    int choice;

    do 
    {
        displayMenu();
        cout << "------> Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                {
                    student.registerStudent();
                    break;
                }
            case 2: 
            {
            string a;
            string pin;
            cout << "Enter the admin ID: ";
            cin >> a;
            cout << "Enter the password: ";
            cin >> pin;

           if (Admin::authenticate(a, pin))
           { 
                string newAdminID, newPassword;
                cout << "Enter new admin ID: ";
                cin >> newAdminID;
                cout << "Enter new password: ";
                cin >> newPassword;
                Admin::addAdmin(newAdminID, newPassword);
                break;
           }
           else
           {
            cout<<"You are not allowed to add admin!!!"<<endl;
            break;
           }
            }
            case 3: 
            {
            string a, pin;
            cout << "Enter the admin ID: ";
            cin >> a;
            cout << "Enter the password: ";
            cin >> pin;
           if (Admin::authenticate(a, pin))
            {
                string adminID, newPassword;
                cout << "Enter admin ID: ";
                cin >> adminID;
                cout << "Enter new password: ";
                cin >> newPassword;
                Admin::changePassword(adminID, newPassword);
                
                break;
            }
            else
            {
                cout<<"You are not allowed to add admin!!!"<<endl;
                break;
            }
            }
            case 4:
                hm.addData();
                break;
            case 5:
                hm.sendNotifications();
                break;
            case 6: 
            {
                string username;
                int month;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter month (MM): ";
                cin >> month;
                hm.calculateMonthlyExpenses(username, month);
                break;
            }
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}