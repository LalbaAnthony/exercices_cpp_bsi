#include <iostream>

using namespace std;

int main()
{

    int largeur = 1;
    int hauteur = 1;
    char c = 'O';

    cout << "Saissisez la largeur:" << endl;
    cin >> largeur;
    cout << "Saissisez la hauteur:" << endl;
    cin >> hauteur;
    cout << "Saissisez le caractere:" << endl;
    cin >> c;

    cout << "\n";
    for (int i = 0; i < hauteur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            // if (i == 0 || i == hauteur - 1 || j == 0 || j == largeur - 1)
            //     cout << c;
            // else
            // {
            cout << " ";
            // }
        }
        cout << "\n";
    }

    return 0;
}
