
/*********************************************************************
** Program name: ValidateInput.cpp
** Author: Huy Nguyen <nguyehu6@oregonstate.edu>
** Date: Apr 02, 2019 at 7:59 PM
** Description: Class implementation file for ValidateInput.
 *              ValidateInput class has static methods for input
 *              validation. Validate input by choosing corresponding
 *              static method for integer, float, double, character, string.
 *              Call static methods directly from class name and
 *              input arguments.
 *              Currently only supports integer and float validation,
 *              others will be added eventually.
*********************************************************************/


#include "ValidateInput.hpp"

using std::cout;
using std::cin;
using std::flush;
using std::endl;
using std::stringstream;
using std::string;

/********************************************************************
** Function: validateInteger: validates user input to ensure it is
 *           an integer. Rejects floats.
** Params:   None
** Returns:  int: valid user integer input
*********************************************************************/
int ValidateInput::validateInteger()
{
    //Initialize with lowest possible int
    int out_num = std::numeric_limits<int>::min();
    string input;
    bool valid;

    do
    {
        valid = true;      //Reset valid flag to true
        cout << "Enter an integer: " << flush;

        if (getline(cin, input))
        {
            //Put input into a string stream and attempt to
            // insert into an int variable
            stringstream ss(input);
            ss >> std::noskipws >> out_num;

            //If anything remains in the string stream,
            // or if input string is empty (they only pressed enter)
            // then validation failed
            if (!ss.eof() || !input.length())
            {
                valid = false;
            }
        }
        else
        {
            valid = false;          //getline failed
        }

        //Clear error flags
        cin.clear();

    } while (!valid);

    return out_num;
}


/********************************************************************
** Function: validateInteger: validates user input to ensure
 *           it is an integer within specified range. Rejects
 *           floating point numbers.
** Params:   int range_start: starting value of valid numeric range
 *           int range_end:   ending value of valid numeric range
** Returns:  int: valid user integer input
*********************************************************************/
int ValidateInput::validateInteger(int range_start, int range_end)
{
    //Initialize with lowest possible int
    int out_num = std::numeric_limits<int>::min();
    string input;
    bool valid;

    do
    {
        valid = true;       //Reset valid flag to true
        cout << "Enter a number between "
            << range_start << " and " << range_end << ": " << flush;

        if (getline(cin, input))
        {
            //Put input into a string stream and attempt to
            // insert into an int variable
            stringstream ss(input);
            ss >> std::noskipws >> out_num;

            //If anything remains in the string stream,
            // or if input string is empty (they only pressed enter)
            // then validation failed
            if (!ss.eof() || !input.length())
            {
                valid = false;
            }
        }
        else
        {
            valid = false;  //getline failed
        }

        //Clear error flags
        cin.clear();

    } while (!valid || out_num < range_start || out_num > range_end);

    return out_num;
}


/********************************************************************
** Function: validateInteger: validates user input to ensure
 *           it is an integer within list of valid choices. Rejects
 *           floating point numbers.
** Params:   const int * choices: pointer to array of valid integer choices
 *           int size: size of array
** Returns:  int: valid user integer input
*********************************************************************/
int ValidateInput::validateInteger(const int * choices, int size)
{
    //Initialize with lowest possible int
    int out_num = std::numeric_limits<int>::min();
    string input;
    bool valid;             //Check for valid input type
    bool matched;           //Check if valid selection

    do
    {
        valid = true;       //Reset valid flag to true
        matched = false;    //Reset matched flag to false
        cout << "Enter an integer: " << flush;

        if (getline(cin, input))
        {
            //Put input into a string stream and attempt to
            // insert into an int variable
            stringstream ss(input);
            ss >> std::noskipws >> out_num;

            //If anything remains in the string stream,
            // or if input string is empty (they only pressed enter)
            // then validation failed
            if (!ss.eof() || !input.length())
            {
                valid = false;
            }

            //Check if input matches with valid choices
            if (valid)
            {
                //Loop to compare valid choices with user input
                for (int i=0; i<size; i++)
                {
                    if (choices[i] == out_num)
                    {
                        matched = true;
                        i = size;   //To break out of for loop
                    }
                }

                //Loop to inform user of valid choices
                if (!matched)
                {
                    cout << "Error: The number must be one of: ";
                    for (int i=0; i<size; i++)
                    {
                        cout << choices[i];

                        //Separate by commas except for last choice
                        if (i != size-1)
                        {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            valid = false;  //getline failed
        }

        //Clear error flags
        cin.clear();

    } while (!valid || !matched);

    return out_num;
}


/********************************************************************
** Function: validateFloat: validates user input to ensure it is
 *           a float.
** Params:   None
** Returns:  double: valid user float input
*********************************************************************/
double ValidateInput::validateFloat()
{
    //Initialize with lowest possible double
    double out_num = std::numeric_limits<double>::min();
    string input;
    bool valid;

    do
    {
        valid = true;      //Reset valid flag to true
        cout << std::fixed << std::showpoint << std::setprecision(2)
             << "Enter an number: " << flush;

        if (getline(cin, input))
        {
            //Put input into a string stream and attempt to
            // insert into an int variable
            stringstream ss(input);
            ss >> std::noskipws >> out_num;

            //If anything remains in the string stream or failbit set,
            // or if input string is empty (they only pressed enter)
            // then validation failed
            if (!ss.eof() || ss.fail() || !input.length())
            {
                valid = false;
            }
        }
        else
        {
            valid = false;          //getline failed
        }

        //Clear error flags
        cin.clear();

    } while (!valid);

    return out_num;
}


/********************************************************************
** Function: validateFloat: validates user input to ensure
 *           it is a floating point number within specified range.
** Params:   double range_start: starting value of valid numeric range
 *           double range_end:   ending value of valid numeric range
** Returns:  double: valid user float input
*********************************************************************/
double ValidateInput::validateFloat(double range_start, double range_end)
{
    //Initialize with lowest possible int
    double out_num = std::numeric_limits<double>::min();
    string input;
    bool valid;

    do
    {
        valid = true;       //Reset valid flag to true
        cout << std::fixed << std::showpoint << std::setprecision(2)
             << "Enter a number between "
             << range_start << " and " << range_end << ": " << flush;

        if (getline(cin, input))
        {
            //Put input into a string stream and attempt to
            // insert into an int variable
            stringstream ss(input);
            ss >> std::noskipws >> out_num;

            //If anything remains in the string stream or failbit set,
            // or if input string is empty (they only pressed enter)
            // then validation failed
            if (!ss.eof() || ss.fail() || !input.length())
            {
                valid = false;
            }
        }
        else
        {
            valid = false;  //getline failed
        }

        //Clear error flags
        cin.clear();

    } while (!valid || out_num < range_start || out_num > range_end);

    return out_num;
}
