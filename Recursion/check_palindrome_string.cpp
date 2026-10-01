#include <iostream>
using namespace std;

// Check palindrome using recursion
bool checkPalindrome(string str, int left, int right)
{
    if(left >= right)
    {
        return true;
    }

    if(str[left] != str[right])
    {
        return false;
    }

    return checkPalindrome(str, left + 1, right - 1);
}

int main()
{
    string str;

    cin >> str;

    if(checkPalindrome(str, 0, str.length() - 1))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}
