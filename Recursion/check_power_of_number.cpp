#include <iostream>
using namespace std;

// Check power recursively
bool checkPower(int n, int x)
{
    if(n == 1)
    {
        return true;
    }

    if(n == 0 || n % x != 0)
    {
        return false;
    }

    return checkPower(n / x, x);
}

int main()
{
    int n, x;

    cin >> n >> x;

    if(checkPower(n, x))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
