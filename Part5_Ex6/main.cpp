#include <iostream>

using namespace std;

int main()
{

    int largeur = 0;
    int hauteur = 0;

    cout << "Saissisez la largeur:" << endl;
    cin >> largeur;
    cout << "Saissisez la hauteur:" << endl;
    cin >> hauteur;

    cout << "\n";
    for (int i = 0; i < hauteur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
