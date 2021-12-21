// Euler_024_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string addNum(string str, int val)
{
    string valStr = to_string(val);
    if (str.find(valStr) == string::npos)
        return valStr;
}


int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}

string addVect1(string str)
{
    int mPos = str.length() - 1; //index of last digit (ones place)
    swap(str[mPos - 1], str[mPos]);
    return str;
}

string addVect2(string str, int reps)
{
    int mPos = str.length() - 1; //index of last digit (ones place)
    for(int i = 0; i < reps; i++)
    {
        swap(str[mPos - 2], str[mPos]);
        swap(str[mPos - 1], str[mPos]);
    } 
    return str;
}

string addVect3(string str, int reps)
{
    int mPos = str.length() - 1; //index of last digit (ones place)
    str[0] = str[0] + 1;
    str[1] = str[1] - 3;
    str[2] = str[2] + 1;
    str[3] = str[3] + 1;
    return str;
}


int main()
{
    int len = 5;
    int n = len-1;
    int arr[120][5]; //factorial(n) and n

    for (int i = 0; i < len; i++)
    {
        arr[0][i] = i;
        cout << arr[0][i] << " ";
    }
    cout << endl;
    
    for (int i = 1; i < factorial(len); i++) //sequence number
    {
        for (int j = 0; j < len; j++) //index number
        {
            //swapping all last two ints of index
            arr[i][j] = arr[i-1][j];



            //cout << arr[i][j] << " ";
        }
        int temp = arr[i][n];
        arr[i][n] = arr[i][n - 1];
        arr[i][n - 1] = temp;

        if (i % 24 == 0) //24
        {
            arr[i][n] = arr[i][n] + 2;
            arr[i][n - 1] = arr[i][n - 1] + 2;
            arr[i][n - 2] = arr[i][n - 2] - 1;
            arr[i][n - 3] = arr[i][n - 3] - 4;
            arr[i][n - 4] = arr[i][n - 4] + 1;

        }
        else if (i % factorial(n - 1) == 0) //6
        {
            arr[i][n] = arr[i][n] + 1;
            arr[i][n - 1] = arr[i][n - 1] + 1;
            arr[i][n - 2] = arr[i][n - 2] - 3;
            arr[i][n - 3] = arr[i][n - 3] + 1;

        }
        else if (i % 6 == 4)
        {
            int temp = arr[i][n];
            arr[i][n] = arr[i][n - 2];
            arr[i][n - 2] = temp;
        }
        else if (i % 6 == 2)
        {
            int temp = arr[i][n - 1];
            arr[i][n - 1] = arr[i][n - 2];
            arr[i][n - 2] = temp;
        }
    } 

    for (int i = 1; i < factorial(len); i++) //sequence number
    {
        for (int j = 0; j < len; j++) //index number
            cout << arr[i][j] << " ";
        cout << endl;
    }

    /*vector<int> currNum;
    while (currNum.size() < n)
    {
        currNum.push_back(i);
        i++;
        //cout << currNum[i - 1] << " ";
    }

    vector<vector<int>> v;
    vector<int> vals;
    int count = 0;
    v.push_back(currNum);
    for (int i = 1; i < factorial(n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            vals.push_back(count);
            
            
            count++;
        }
        v.push_back(vals);
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
    */


    /*
    string numStr;
    int i = 0;
    int n = 4; //number of chars in string
    while (numStr.length() < n)
    {
        numStr = numStr + addNum(numStr, i);
        i++;
        //cout << i << " " << numStr << endl;
       
    }
    //cout << numStr << endl;

    vector<string> v;
    v.push_back(numStr); //add first element
    
    for (int i = 1; i < (factorial(n)); i++)
    {
  
        if (i % factorial(3) == 0) //div by 6
        {
            v.push_back(addVect3(numStr, i / factorial(3)));
            numStr = addVect3(numStr, i / factorial(3));
        } 
        else if (i % factorial(2) == 0) //div by 2
        {
            v.push_back(addVect2(numStr, i / factorial(2)));
            numStr = addVect2(numStr, i / factorial(2));
        }
        else //if (i % factorial(2) == 1) //div by 1
        {
            v.push_back(addVect1(numStr));
            numStr = addVect1(numStr);
        }
        
        
       // cout << i << endl;
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
   */
} //end main