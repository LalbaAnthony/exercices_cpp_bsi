#include <iostream>

using namespace std;

int main()
{

    int largeur = 0;
    int hauteur = 0;
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
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
