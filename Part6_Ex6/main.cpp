#include <iostream>

using namespace std;

bool mod(int a, int b);

int main()
{
    int n = 0;
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Enter un nombre: " << endl;
    cin >> n;

    for (int i = 0; i <= 9; i++)
    {
        if (mod(n, numbers[i]))
        {
            cout << n << " est divisible par " <<  numbers[i] << endl;
        }
    }

    return 0;
}

bool mod(int a, int b)
{
    return a % b == 0 ? true : false;
}
