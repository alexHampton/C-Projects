/* Creates a CDAccount class, and leaves account empty or updates the account
 * with user input.
 * Program then outputs the details of the account.
 * Finally, program asks user to check functions of program and runs
 * functions accordingly.
 *
 *
 * Author: Alex Hampton
 */



#include <iostream>
using namespace std;


/***********************************************************************
************************************************************************
*
*                 class CDAccount
*
************************************************************************
************************************************************************/



class CDAccount
{
public:
    CDAccount();
    // Creates a new CDAccount with dollar, cent, interest rate, and term set to 0.

    CDAccount(double new_balance, double new_interest_rate, int new_term);
    // Creates a new CDAccount with new_balance set to dollar and cent, 
    // new_interest_rate as the interest_rate, and new_term as the term in months.

    double get_initial_balance() const;
    // returns the balance in dollar.cent form

    double get_balance_at_maturity() const;
    // returns the balance at the end of the term of the account.

    double get_interest_rate() const;
    // reurns the interest rate in percentage form

    int get_term() const;
    // returns the term of the account in months

    void input(istream& in);
    // takes in three values from 'in'
    // sets first value to balance which then populates dollar and cent
    // sets second value to interest_rate
    // sets third value to term

    void output(ostream& out);
    // outputs the balance, interest rate, term, and balance at maturity to 'out'

    bool invalidValues();
    // returns true if dollar, cent, interest_rate, or term are negative.
    // returns false if all values are non-negative.


    int constructor_menu(istream& in, ostream& out); 
    // prints menu and accepts 1 or 2 as input.
    // 1 represents an empty constructor (all member variables set to '0')
    // 2 represents a non-empty constructor so user can input account information


    int function_tester_menu(istream& in, ostream& out); // second menu so user can test the functions
    // outputs a menu of all the functions. Accepts 1, 2, 3, or 4 as input.
    // returns input.
    // 1 represents get_initial_balance()
    // 2 represents get_balance_at_maturity()
    // 3 represents get_interest_rate()
    // 4 represents get_term()

private:
    int dollar;
    int cent;
    double interest_rate; // percent for (ex. 4.5 for 4.5%)
    int term; // months until maturity
    double percent_to_fraction() const; // returns fraction version of interest_rate
};


/***********************************************************************
************************************************************************
* 
*                 int main()
* 
************************************************************************
************************************************************************/

int main()
{
    

    // Use empty constructor to initialize account
    CDAccount newAccount;

    // Declaration of variables
    int user_choice;
    char view_functions;
    int function_choice;



    /*****************************************************************
                TEST CONSTRUCTORS
    ******************************************************************/

    // menu allows user to make empty account or set the values.
    user_choice = newAccount.constructor_menu(cin, cout);
    if (user_choice == 2) // Take user input to set the values if user_choice is 2
    {

        // loop until user values are all non-negative
        do
        {
            cout << "Enter the balance, rate, and term in months (Ex. 500.50 4.5 12): ";
            newAccount.input(cin);

        } while (newAccount.invalidValues()); // ensure values are non-negative
    }
    
    // if user_choice is not 2, leave the account empty.

    cout << "Your account has been created.\n\n";

    newAccount.output(cout);



    /*****************************************************************
                TEST FUNCTIONS
    ******************************************************************/


    cout << "Would you like to test the functions? (y/n): ";
    cin >> view_functions;

    // Continue to test functions until user no longer wants to.
    while (view_functions == 'y' || view_functions == 'Y')
    {
        // print function tester menu and accept input
        function_choice = newAccount.function_tester_menu(cin, cout);

        // test functions based on user input ( 1, 2, 3, or 4)
        switch (function_choice)
        {
        case 1:
            cout << "Initial balance: $" << newAccount.get_initial_balance() << endl << endl;
            break;
        case 2:
            cout << "Balance at maturity: $" << newAccount.get_balance_at_maturity() << endl << endl;
            break;
        case 3:
            cout << "Interest rate: " << newAccount.get_interest_rate() << "%\n\n";
            break;
        case 4:
            cout << "Term (months): " << newAccount.get_term() << endl << endl;
            break;
        default:
            cout << "Error: invalid entry\n";
        }

        cout << "Try the functions again? (y/n): ";
        cin >> view_functions;
    }

    

    system("pause");
    return 0;
}



/***********************************************************************
************************************************************************
*
*                 function definitions
*
************************************************************************
************************************************************************/

CDAccount::CDAccount() : dollar(0), cent(0), interest_rate(0), term(0)
{
    // Intentionally left blank.
}

CDAccount::CDAccount(double new_balance, double new_interest_rate, int new_term)
{
    dollar = (int)new_balance;
    cent = (int)((new_balance - dollar) * 100);
    interest_rate = new_interest_rate;
    term = new_term;
}


double CDAccount::get_initial_balance() const
{
    double balance = dollar + (cent * 0.01);
    return balance;
}

double CDAccount::get_interest_rate() const
{
    return interest_rate;
}

int CDAccount::get_term() const
{
    return term;
}

double CDAccount::get_balance_at_maturity() const
{
    double balance = get_initial_balance();
    balance = balance + ((percent_to_fraction() * term / 12) * balance);
    return balance;

}

double CDAccount::percent_to_fraction() const
{
    return interest_rate / 100;
}

void CDAccount::input(istream& in)
{
    double balance;
    in >> balance; // get initial balance from user

    // convert balance to dollars and cents since this is how balance stored
    dollar = (int)balance; // dollar is the interger part of balace
    cent = (int)((balance - dollar) * 100); // cent is the fraction part * 100

    in >> interest_rate; // get interest rate from user
    in >> term; // get term from user
}

void CDAccount::output(ostream& out)
{
    // set decimal point to show cents.
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    // output account information
    out << "Initial Balance: $" << get_initial_balance() << endl;
    out << "Interest rate: " << get_interest_rate() << "%" << endl;
    out << "Term (months): " << get_term() << endl;
    out << "Balance after maturity: $" << get_balance_at_maturity() << endl << endl;
}

int CDAccount::constructor_menu(istream& in, ostream& out)
{
    int input;

    do {
        out << "What would you like to do? (1/2)\n";
        out << "**************************************\n";
        out << "* 1. Create empty account            *\n";
        out << "* 2. Create account with balance,    *\n";
        out << "*    rate, and term of the account.  *\n";
        out << "*                                    *\n";
        out << "**************************************\n";

        in >> input;
        if (input != 1 && input != 2)
            out << "Error: please choose 1 or 2\n";
    } while (input != 1 && input != 2);
    return input;
}

int CDAccount::function_tester_menu(istream& in, ostream& out)
{
    int input;

    do {
        out << "Which function would you like to test? (1, 2, 3 or 4): \n\n";
        out << "*******************************************************\n";
        out << "**   1. get_initial_balance()                        **\n";
        out << "**   2. get_balance_at_maturity()                    **\n";
        out << "**   3. get_interest_rate()                          **\n";
        out << "**   4. get_term()                                   **\n";
        out << "*******************************************************\n";

        in >> input;
        if (input < 1 || input > 4)
            out << "Error: please choose 1, 2, 3, or 4\n";
    } while (input < 1 || input > 4);
    return input;     
}



bool CDAccount::invalidValues()
{
    if ((dollar < 0) || (cent < 0) || (interest_rate < 0) || (term < 0))
    {
        cout << "Error: balance, interest rate, and term must all be non-negative.\n";
        return true;
    }
    return false;
}






/***********************************************************************
************************************************************************
*
*                 OUTPUT 1
*
************************************************************************
************************************************************************/

/*************What would you like to do? (1/2)
**************************************
* 1. Create empty account            *
* 2. Create account with balance,    *
*    rate, and term of the account.  *
*                                    *
**************************************
1
Your account has been created.

Initial Balance: $0.00
Interest rate: 0.00%
Term (months): 0
Balance after maturity: $0.00

Would you like to test the functions? (y/n): n
Press any key to continue . . .
*/




/***********************************************************************
************************************************************************
*
*                 OUTPUT 2
*
************************************************************************
************************************************************************/



/*

What would you like to do? (1/2)
**************************************
* 1. Create empty account            *
* 2. Create account with balance,    *
*    rate, and term of the account.  *
*                                    *
**************************************
2
Enter the balance, rate, and term in months (Ex. 500.50 4.5 12): 300 2.7 8
Your account has been created.

Initial Balance: $300.00
Interest rate: 2.70%
Term (months): 8
Balance after maturity: $305.40

Would you like to test the functions? (y/n): y
Which function would you like to test? (1, 2, 3 or 4):

*******************************************************
**   1. get_initial_balance()                        **
**   2. get_balance_at_maturity()                    **
**   3. get_interest_rate()                          **
**   4. get_term()                                   **
*******************************************************
1
Initial balance: $300.00

Try the functions again? (y/n): y
Which function would you like to test? (1, 2, 3 or 4):

*******************************************************
**   1. get_initial_balance()                        **
**   2. get_balance_at_maturity()                    **
**   3. get_interest_rate()                          **
**   4. get_term()                                   **
*******************************************************
2
Balance at maturity: $305.40

Try the functions again? (y/n): y
Which function would you like to test? (1, 2, 3 or 4):

*******************************************************
**   1. get_initial_balance()                        **
**   2. get_balance_at_maturity()                    **
**   3. get_interest_rate()                          **
**   4. get_term()                                   **
*******************************************************
3
Interest rate: 2.70%

Try the functions again? (y/n): y
Which function would you like to test? (1, 2, 3 or 4):

*******************************************************
**   1. get_initial_balance()                        **
**   2. get_balance_at_maturity()                    **
**   3. get_interest_rate()                          **
**   4. get_term()                                   **
*******************************************************
4
Term (months): 8

Try the functions again? (y/n): n
Press any key to continue . . .
*/