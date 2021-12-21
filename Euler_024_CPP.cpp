// Euler_024_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Millionth Lexicon Permutations
//Simple math solution

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{
    int n = 10;
    int stopper = 1000000;
    int arr[10];
    int zero_at_9 = factorial(n - 1); //zeroes for this many places
    //zero value at index 9 (0 _ _ _ _ _ _ _ _ _)

    while (n > 0) //end while loop when all 10 ints locations are accounted for
    {
        int i = 1;
        int count = 0;
        while (i < stopper)
        {
            if (i % factorial(n - 1) == 0) //+1 num at index
                count++;
            i++;
        }
        cout << "The count is: " << count << endl; //2 is first digit
        stopper = stopper - count * factorial(n - 1); //decrease stopper for loop w/ next index
        cout << "The stopper is: " << stopper << endl;
        arr[n - 1] = count;
        n = n - 1;

    } //end while

    reverse(arr, arr + size(arr)); //reverse arr to correct order
    for (int i = 0; i < size(arr); i++)
        cout << arr[i] << " ";
    cout << endl;

    // Output millionth permutation
    int finArr[10]; //empty final array to store solution
    int nums[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //set of available ints

    for (int k = 0; k < 10; k++)
    {
        finArr[k] = nums[arr[k]]; //assign value for each index 0 through 9

        for (int j = arr[k]; j < 9; j++) //"deleting" used elements from nums
            nums[j] = nums[j + 1]; // copy next element left
    }

    for (int i = 0; i < size(finArr); i++)
        cout << finArr[i] << " "; //print solution
    cout << endl;
} //end main