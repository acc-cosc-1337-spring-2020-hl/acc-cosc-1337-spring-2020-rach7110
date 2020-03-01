#include <iostream>
#include "vectors.h"

using std::cin;
using std::cout;

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/
int main() 
{
    int answer;

    cout << "Press '1' to execute 'Get Max From Vector' or press '2' to execute 'Get Primes'.";
    cin >> answer;

    if(answer == 1)
    {
        vector<int> numbers {1,2,3,4,5,1000};

        get_max_from_vector(numbers);
    }

    if (answer == 2)
    {
        int user_integer;

        cout << "Enter an integer: ";
        cin >> user_integer;

        // Get list of primes.
        vector<int> primes = vector_of_primes(user_integer);

        // Print prime numbers.
        for (auto prime : primes)
        {
            cout << prime;
        }
    }

	return 0;
}