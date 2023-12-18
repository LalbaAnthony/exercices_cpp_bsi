#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    float result = 1;

    cout << "Enter n: " << endl;
    cin >> n;

    for (int i = 2; i <= n; ++i)
    {
        result += (1/n);
    }

    cout << "n: " << n <<endl;

    return 0;
}
