// Euler_024_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Millionth Lexicon Permutations
// Solution using next_permutation
// Took 2 minutes to do, first solution took me a day

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str("0123456789");
    int count = 1;
    do
    {
        count++;
    } while (next_permutation(str.begin(), str.end()) && count < 1000000);
    cout << str;
} //end main