
/*********************************************************************
* CSE 453
* 
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;
using namespace std::filesystem;

/*********************************************************************
*  displayMenu()
*  Called by interact()
*  Displays menu options.
*********************************************************************/
void displayMenu()
{
    cout << "OPTIONS:\n"
        << "   A  Option 1\n"
        << "   B  Option 2\n"
        << "   Q  Quit\n";

    return;
}

/*********************************************************************
*  displayPrompt()
*  Displays passed message.
*********************************************************************/
void displayPrompt(string message)
{
    cout << message << "\n";
    return;
}

/*********************************************************************
*  displayResult()
*  Called by interact()
*  Displays results.
*********************************************************************/
void displayResult(string message)
{
    cout << "TEST RESULT: ";
    cout << message << "\n\n";
    return;
}

/*********************************************************************
*  displayError()
*  Called by interact()
*  Displays error message.
*********************************************************************/
void displayError(string message)
{
    cout << message << "\n\n";
    return;
}

/*********************************************************************
*  displayHeader()
*  Called by interact()
*  Displays app identifier.
*********************************************************************/
void displayHeader()
{
    cout << "\n************ CSE 453 ************\n\n";
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
    string returnString;
    do
    {
        if (cin.fail()) // bad input
        {
            cin.clear();
            cin.ignore();
            continue;
        }

        cin.getline(answer, 2);
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
            displayHeader();
            displayError("ERROR: Not implemented");
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
