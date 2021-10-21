
/*********************************************************************
*   CSE 453
*
*   Carlos N Reina
*   Adrian Whetten
*   Jordan Burdett
*   Caleb Georgeson
*   Russell Roberts
*   Stephen Ellis
*   Orion Christensen
*
*********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/*********************************************************************
*  displayMenu()
*  Called by interact()
*  Displays menu options.
*********************************************************************/
void displayMenu()
{
    std::cout << "OPTIONS:\n"
        << "   A  Option 1\n"
        << "   B  Option 2\n"
        << "   Q  Quit\n";

    return;
}

/*********************************************************************
*  displayPrompt()
*  Displays passed message.
*********************************************************************/
void displayPrompt(std::string message)
{
    std::cout << message << "\n";
    return;
}

/*********************************************************************
*  displayResult()
*  Called by interact()
*  Displays results.
*********************************************************************/
void displayResult(std::string message)
{
    std::cout << "TEST RESULT: " << message << "\n\n";
    return;
}

/*********************************************************************
*  displayError()
*  Called by interact()
*  Displays error message.
*********************************************************************/
void displayError(std::string message)
{
    std::cout << message << "\n\n";
    return;
}

/*********************************************************************
*  displayHeader()
*  Called by interact()
*  Displays app identifier.
*********************************************************************/
void displayHeader()
{
    std::cout << "\n************ CSE 453 ************\n\n";
    return;
}

/*********************************************************************
*  clearScreen()
*  Called by interact()
*  Clears the screen.
*********************************************************************/
void clearScreen()
{
    if (system("CLS")) { system("clear"); }
    return;
}

/********************************************************************
*   sanitizeString
*   Accepts a string value and searches for common SQL keywords and removes them.
*********************************************************************/
string sanatizeString(string value)
{
    string sanitizedString = "";
    stringstream stream(value);
    string parsed;
    // select * from users where or and username = 'username'
    while (getline(stream, parsed, ' '))
    {
        if (parsed == "" ||
            parsed == "OR" ||
            parsed == "AND" ||
            parsed == "SELECT" ||
            parsed == "UNION" ||
            parsed == "INSERT" ||
            parsed == "JOIN" ||
            parsed == "ALTER" ||
            parsed == "DELETE" ||
            parsed == ";")
            continue;

        // add the parsed string to our vector
        sanitizedString.append(parsed);
    }

    // remove semicolons
    for (string::iterator iter = sanitizedString.begin(); iter != sanitizedString.end(); iter++)
    {
        if (*iter == ';')
        {
            iter = sanitizedString.erase(iter);
            iter--;
        }
    }

    return sanitizedString;
}

/*********************************************************************
*   genQuery
*   Accepts a Username and Password
*   Returns sql as a string
*********************************************************************/
string genQuery(string username, string password)
{
    std::string query = "SELECT * FROM USERS WHERE username = " + username + " AND password = " + password + ";";

    return query;
}

/*********************************************************************
*   genQueryWeak
*   Accepts a Username and Password
*   Returns sql as a string
*********************************************************************/
string genQueryWeak(string username, string password)
{
    // sanatize the string
    username = sanatizeString(username);
    password = sanatizeString(password);

    std::string query = "SELECT * FROM USERS WHERE username = " + username + " AND password = " + password + ";";

    return query;
}

/*********************************************************************
*   genQueryStrong
*   Accepts a Username and Password
*   Returns sql as a string
*********************************************************************/
std::string genQueryStrong(std::string username, std::string password)
{

    vector<char> iterator;

    //Tautology - itterate through the string and find an OR statement
    /*if (username.length() = || password.length() = ) {

    }*/

    //Extra Statement - write a SQL statement with no 


    std::string query = "SELECT * FROM USERS WHERE username = " + username + "AND password = " + password + ";";

    return query;
}

/********************************************************************
* runTest
* Accepts a username and password
* Runs each genQuery function against the test case
*********************************************************************/
void runTest(string username, string password)
{
    cout << "\tUsername: " << username << endl;
    cout << "\tPassword: " << password << endl;

   // cout << "genQuery: " << genQuery(username, password) << endl;
    cout << "genQueryWeak: " << genQueryWeak(username, password) << endl;
   // cout << "genQueryStrong: " << genQueryStrong(username, password) << endl;

    cout << endl;
}

/*********************************************************************
*  testValid
*  Tests for a valid input
*********************************************************************/
void testValid()
{
    cout << "Starting tests for testValid()" << endl;

    string username, password, queryResults;

    // Jordans test case
    cout << "Jordan's test case: " << endl;
    username = "jordanburdett";
    password = "P@ss_word1$$";
    runTest(username, password);

    // orion's test case and error checking.
    cout << "Orion's test case: " << endl;
    username = "Orionchristensen";
    password = "MJU&nhy6bgt5vfr4";
    runTest(username, password);

    // Adrians Test Case
    cout << "Adrian's test case: " << endl;
    username = "adrianWhetten";
    password = "ALPHAMOONDAWG";
    runTest(username, password);

    // caleb's test case
    cout << "Caleb's test case: " << endl;
    username = "calebgeorgeson";
    password = "totally_secure_password";
    runTest(username, password);


}

/*********************************************************************
*  testTautology
*
*********************************************************************/
void testTautology()
{
    string username, password, queryResults;

    //// Calebs test case
    //cout << "Caleb's test case: " << endl;
    //username = "calebgeorgeson' OR 'lol' = 'lol'";
    //password = "totally_secure_password' OR 'a' = 'a'";
    //runTest(username, password);

    // jordans test case
    cout << "Jordan's test case: " << endl;
    username = "jordanburdett;;;;;;; AND SELECT asdf' OR 'abc' = 'abc'";
    password = "password' OR 'test' = 'test'";
    runTest(username, password);

}

/*********************************************************************
*  testUnion
*
*********************************************************************/
void testUnion()
{
    string username, password, queryResults;

    cout << "Caleb's test case: " << endl;
    username = "calebgeorgeson";
    password = "totally_secure_password' UNION SELECT name, ssn FROM employee_data";
    runTest(username, password);

}

/*********************************************************************
*  testAddState
*
*********************************************************************/
void testAddState()
{

    string username, password, queryResults;

    cout << "Caleb's test case: " << endl;
    username = "calebgeorgeson";
    password = "totally_secure_password'; DELETE FROM employee_data";
    runTest(username, password);

}

/*********************************************************************
*  testComment
*
*********************************************************************/
void testComment()
{

    string username, password, queryResults;

    cout << "Orion's test case: " << endl;
    username = "orion'; --";
    password = "";
    runTest(username, password);

    cout << "Jordan's test case: " << endl;
    username = "jordanburdett'; --";
    password = "you got hacked";
    runTest(username, password);


}

/*********************************************************************
*   interact(), until user types "Q".
*   Called by main.
*********************************************************************/
void interact()
{
    clearScreen();
    displayHeader();
    displayMenu();

    char answer[2] = "";
    std::string returnString;
    do
    {
        if (std::cin.fail()) // bad input
        {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        std::cin.getline(answer, 2);
        if (islower(answer[0])) { answer[0] = toupper(answer[0]); }
        returnString.clear();
        switch (answer[0])
        {
        case '\0': // no input
            clearScreen();
            displayHeader();
            displayError("ERROR: Invalid command");
            displayMenu();
            break;

        case 'A':
            clearScreen();
            testTautology();
            displayMenu();
            break;

        case 'B':
            clearScreen();
            displayHeader();
            displayError("ERROR: Not implemented");
            displayMenu();
            break;

        case 'Q': // Quit
            clearScreen();
            break;

        default:
            clearScreen();
            displayHeader();
            displayError("ERROR: Invalid command");
            displayMenu();
            break;
        }
    } while (answer[0] != 'Q' && answer[0] != 'q');

    return;
}



/*********************************************************************
*   Main driver of the program
*********************************************************************/
int main()
{
    interact();

    return 0;
}
