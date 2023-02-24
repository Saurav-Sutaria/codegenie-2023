/*
 * Test Case - 1
 * Final Number = 2500
 * Operations = {"X + 10", "X - 5", "X * 5", "X ^ 2"}
 * Expected Output: 5
 *
 * Test Case - 2
 * Final Number = 1000
 * Operations = {"X * 5", "X / 0", "X ^ 3"}
 * Expected Output: -1
 *
 * Test Case - 3
 * Final Number: 10
 * Operations: {"X * 5", "X * 0", "X + 10"}
 * Exepcted Output : -1
 *
 * Test Case - 4
 * Final Number: 617283948
 * Operations: {"X + 5", "X - 0", "X + 1", "X / 2", "X ^ 1"}
 * Exected Output: 1234567890
 */

/*
Logic:
we will start with end in the operation array and we will apply reverse operations on
the finalNumber(given in input)
i.e if operation is '+' we will perform '-'
and when we complete the traversal we will get actual number
*/
#include <bits/stdc++.h>
using namespace std;

int guessNumber(int finalNumber, vector<string>& operations)
{
    int actualNumber = finalNumber;
    for (int i = operations.size() - 1; i >= 0; i--)
    {
        char opr = operations[i][2];
        int temp = stoi(operations[i].substr(4));
        /* exception case
        X * 0, X ^ 0, X % anynumber
        */
        if (opr == '%' || (opr == '*' && temp == 0) || (opr == '^' && temp == 0))
            return -2;

        // case handled here : x / 0
        if (opr == '/' && temp == 0)
            return -1;

        // applying operations
        if(opr == '+') actualNumber -= temp;
        else if(opr == '-') actualNumber += temp;
        else if(opr == '*') actualNumber /= temp;
        else if(opr == '/') actualNumber *= temp;
        else{
            float rt = 1.0/temp;
            actualNumber = pow(actualNumber,rt);
        }
    }
    return actualNumber;
}

int main()
{
    int finalNumber = 2500;
    vector<string> operations = {"X + 10", "X - 5", "X * 5", "X ^ 2"};

    int actualNumber = guessNumber(finalNumber, operations);
    cout << actualNumber << endl;
    return 0;
}
