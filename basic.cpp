#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ENTRIES = 100; // Maximum number of income/expense entries

// Function Prototypes
void addIncome(string incomeNames[], double incomeAmounts[], int& incomeCount);
void addExpenses(string expenseNames[], double expenseAmounts[], int& expenseCount);
void updateIncome(string incomeNames[], double incomeAmounts[], int incomeCount);
void updateExpenses(string expenseNames[], double expenseAmounts[], int expenseCount);
void deleteIncome(string incomeNames[], double incomeAmounts[], int& incomeCount);
void deleteExpenses(string expenseNames[], double expenseAmounts[], int& expenseCount);
double setSavingsGoal();
void viewSummary(const string incomeNames[], const double incomeAmounts[], int incomeCount,
                 const string expenseNames[], const double expenseAmounts[], int expenseCount,
                 double savingsGoal);
void displayMenu();

int main() {
    string incomeNames[MAX_ENTRIES];   
    double incomeAmounts[MAX_ENTRIES]; 
    int incomeCount = 0;               
    string expenseNames[MAX_ENTRIES];   
    double expenseAmounts[MAX_ENTRIES]; 
    int expenseCount = 0;               

    double savingsGoal = 0.0;           

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addIncome(incomeNames, incomeAmounts, incomeCount);
                break;
            case 2:
                addExpenses(expenseNames, expenseAmounts, expenseCount);
                break;
            case 3:
                updateIncome(incomeNames, incomeAmounts, incomeCount);
                break;
            case 4:
                updateExpenses(expenseNames, expenseAmounts, expenseCount);
                break;
            case 5:
                deleteIncome(incomeNames, incomeAmounts, incomeCount);
                break;
            case 6:
                deleteExpenses(expenseNames, expenseAmounts, expenseCount);
                break;
            case 7:
                savingsGoal = setSavingsGoal();
                break;
            case 8:
                viewSummary(incomeNames, incomeAmounts, incomeCount, expenseNames, expenseAmounts, expenseCount, savingsGoal);
                break;
            case 9:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    cout << "\n--- Monthly Expense Planner ---" << endl;
    cout << "1. Add Income Sources" << endl;
    cout << "2. Add Expenses" << endl;
    cout << "3. Update Income Sources" << endl;
    cout << "4. Update Expenses" << endl;
    cout << "5. Delete Income Sources" << endl;
    cout << "6. Delete Expenses" << endl;
    cout << "7. Set Savings Goal" << endl;
    cout << "8. View Summary" << endl;
    cout << "9. Exit" << endl;
}

// Function to add income sources
void addIncome(string incomeNames[], double incomeAmounts[], int& incomeCount) {
    int count;
    cout << "How many income sources do you want to add? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        if (incomeCount >= MAX_ENTRIES) {
            cout << "Maximum number of income entries reached!" << endl;
            break;
        }

        cout << "Enter income source name: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, incomeNames[incomeCount]);
        cout << "Enter amount for " << incomeNames[incomeCount] << " (₱): ";
        cin >> incomeAmounts[incomeCount];
        incomeCount++;
    }
}

// Function to add expenses
void addExpenses(string expenseNames[], double expenseAmounts[], int& expenseCount) {
    int count;
    cout << "How many expense categories do you want to add? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        if (expenseCount >= MAX_ENTRIES) {
            cout << "Maximum number of expense entries reached!" << endl;
            break;
        }

        cout << "Enter expense category: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, expenseNames[expenseCount]);
        cout << "Enter amount for " << expenseNames[expenseCount] << " (₱): ";
        cin >> expenseAmounts[expenseCount];
        expenseCount++;
    }
}

// Function to update income sources
void updateIncome(string incomeNames[], double incomeAmounts[], int incomeCount) {
    if (incomeCount == 0) {
        cout << "No income sources to update!" << endl;
        return;
    }

    int index;
    cout << "Enter the index of the income source to update (0 to " << incomeCount - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < incomeCount) {
        cout << "Updating " << incomeNames[index] << " with amount " << incomeAmounts[index] << endl;
        cout << "Enter new income source name: ";
        cin.ignore();
        getline(cin, incomeNames[index]);
        cout << "Enter new amount: ";
        cin >> incomeAmounts[index];
    } else {
        cout << "Invalid index!" << endl;
    }
}

// Function to update expenses
void updateExpenses(string expenseNames[], double expenseAmounts[], int expenseCount) {
    if (expenseCount == 0) {
        cout << "No expense categories to update!" << endl;
        return;
    }

    int index;
    cout << "Enter the index of the expense category to update (0 to " << expenseCount - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < expenseCount) {
        cout << "Updating " << expenseNames[index] << " with amount " << expenseAmounts[index] << endl;
        cout << "Enter new expense category: ";
        cin.ignore();
        getline(cin, expenseNames[index]);
        cout << "Enter new amount: ";
        cin >> expenseAmounts[index];
    } else {
        cout << "Invalid index!" << endl;
    }
}

// Function to delete income sources
void deleteIncome(string incomeNames[], double incomeAmounts[], int& incomeCount) {
    if (incomeCount == 0) {
        cout << "No income sources to delete!" << endl;
        return;
    }

    int index;
    cout << "Enter the index of the income source to delete (0 to " << incomeCount - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < incomeCount) {
        for (int i = index; i < incomeCount - 1; i++) {
            incomeNames[i] = incomeNames[i + 1];
            incomeAmounts[i] = incomeAmounts[i + 1];
        }
        incomeCount--;
        cout << "Income source deleted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

// Function to delete expenses
void deleteExpenses(string expenseNames[], double expenseAmounts[], int& expenseCount) {
    if (expenseCount == 0) {
        cout << "No expense categories to delete!" << endl;
        return;
    }

    int index;
    cout << "Enter the index of the expense category to delete (0 to " << expenseCount - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < expenseCount) {
        for (int i = index; i < expenseCount - 1; i++) {
            expenseNames[i] = expenseNames[i + 1];
            expenseAmounts[i] = expenseAmounts[i + 1];
        }
        expenseCount--;
        cout << "Expense category deleted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

// Function to set the savings goal
double setSavingsGoal() {
    double goal;
    cout << "Enter your monthly savings goal: ";
    cin >> goal;
    return goal;
}

// Function to view the summary
void viewSummary(const string incomeNames[], const double incomeAmounts[], int incomeCount,
                 const string expenseNames[], const double expenseAmounts[], int expenseCount,
                 double savingsGoal) {
    double totalIncome = 0.0, totalExpenses = 0.0;

    cout << "\n--- Summary ---" << endl;

    // Display income sources and calculate total income
    cout << "Income Sources:" << endl;
    for (int i = 0; i < incomeCount; i++) {
        cout << "  " << incomeNames[i] << ": ₱" << fixed << setprecision(2) << incomeAmounts[i] << endl;
        totalIncome += incomeAmounts[i];
    }
    cout << "Total Income: ₱" << totalIncome << endl;

    // Display expenses and calculate total expenses
    cout << "\nExpense Categories:" << endl;
    for (int i = 0; i < expenseCount; i++) {
        cout << "  " << expenseNames[i] << ": ₱" << fixed << setprecision(2) << expenseAmounts[i] << endl;
        totalExpenses += expenseAmounts[i];
    }
    cout << "Total Expenses: ₱" << totalExpenses << endl;

    // Display savings goal and remaining balance
    cout << "\nSavings Goal: ₱" << fixed << setprecision(2) << savingsGoal << endl;
    double remainingBalance = totalIncome - totalExpenses - savingsGoal;
    cout << "Remaining Balance: ₱" << fixed << setprecision(2) << remainingBalance << endl;

    if (remainingBalance < 0) {
        cout << "Warning: You are over budget!" << endl;
    }
}
