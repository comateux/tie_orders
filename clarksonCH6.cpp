#include <iostream>
#include <iomanip>
using namespace std;

// / Global constants for tie cost
const double BOW_SOLID = 5.99, BOW_PAISLEY = 9.99, BOW_STRIPED = 7.99;
const double NECK_SOLID = 7.99, NECK_PAISLEY = 9.99, NECK_STRIPED = 11.99;

// Function prototypes
void getTies();
int getTieType(int);
int getPattern(int);
double calculateTieCost(double);

int main ()
{
    int numTies;
    int tieType;
    int pattern;
    double cost;
    
    // Setup numeric output formatting
    cout << fixed << showpoint << setprecision(2);

    // Ask the user how many ties they want to order
    do
    {
        getTies();
        cin >> numTies;

        // Validate the number of ties
        if (numTies <= 0)
        {
            cout << "\n**ERROR -  INVALID NUMBER OF TIES**\n";
        }
    } while (numTies <= 0);
    
    // Get tie type and pattern for each tie
    for (int tieCount = 1; tieCount <= numTies; tieCount++)
    {
        tieType = getTieType(numTies);

        pattern = getPattern(numTies);
    }

    // Calculate total cost
    cost = calcualteTieCost();

    return 0;

}

void getTies()
{
    cout << "\nEnter the number of ties: ";
}

int getTieType(int quantityTies)
{
    int tieType; // to hold tie type choice
    int tieCount;

    // Constants for the menu choices
    const int BOW_TIE = 1;
    const int NECK_TIE = 2;


    do
    {
        // Determine type of tie
        cout << "\nSelect from one of the following types of tie:";
        cout << "\n\t 1. Bow Tie";
        cout << "\n\t 2. Neck Tie";
        cout << "Please enter the tie type for tie #" << tieCount;
        cin >> tieType;
        cout << endl;

        switch (tieType)
        {
            case 1:
                tieType = BOW_TIE;
                break;
            case 2:
                tieType = NECK_TIE;
                break;
        }

        if (tieType != 1 or tieType != 2)
        {
            cout << "\n**ERROR - INVALID TIE TYPE**\n"
        }

    } while (tieType < 1 or tieType > 2);
    

    return tieType;
}

int getPattern(int quantityTies)
{
    int pattern; // to hold pattern choice
    int tieCount;

    // Constants for pattern choices
    const int solid = 1;
    const int paisley = 2;
    const int striped = 3;

    do
    {
        // Determine tie pattern
        cout << "\nSelect from one of the following tie patterns:";
        cout << "\n\t 1. Solid";
        cout << "\n\t 2. Paisley";
        cout << "\n\t 3. Striped";
        cout << "\nPlease choose the pattern for tie #" << tieCount << " :";
        cin >> pattern;

        if (pattern < 1 or pattern > 3)
        {
            cout << "\n**ERROR - INVALID PATTERN CHOICE**\n";
        }
    } while (pattern < 1 or pattern > 3);

    switch (pattern)
    {
        case 1:
            pattern = solid;
            break;
        case 2:
            pattern = paisley;
            break;
        case 3: 
            pattern = striped;
            break;
    }

    return pattern;
    
}

double calcualteTieCost(double cost)
{
    double totalCost;
    int tieType;

    // Constants for pattern choices
    const int solid = 1;
    const int paisley = 2;
    const int striped = 3;

    if (tieType == 1)
    {
        solid = BOW_SOLID;
        paisley = BOW_PAISLEY;
        striped = BOW_STRIPED;
    }
    else if (tieType == 2)
    {
        solid = NECK_SOLID;
        paisley = NECK_PAISLEY;
        striped = NECK_STRIPED;
    }
    
    totalCost += cost;

    cout << "\nThe total of all ties: $" << totalCost << endl;
}