#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

string toLowerCase(const string &str)
{
    string result;
    for (char c : str)
    {
        result += tolower(c);
    }
    return result;
}

string returnRandomWord()
{
    string words[100] = {"Bonjour", "Chat", "Maison", "Soleil", "�cole", "Chien", "Jardin", "Plage", "Voiture", "Livre", "Musique", "Montagne", "Fleurs", "Amour", "T�l�phone", "Caf�", "Avion", "Arbre", "Parc", "�toile", "Porte", "Fen�tre", "Rire", "Oiseau", "Nuit", "Rivi�re", "Enfant", "Crayon", "Bateau", "Table", "Ciel", "Ville", "Poulet", "Pied", "Lumi�re", "Cadeau", "Appartement", "G�teau", "Route", "T�l�vision", "�toile", "R�ve", "Hiver", "�t�", "Visage", "�le", "Neige", "Main", "Chapeau", "Verre", "Balle", "Chaussure", "Nez", "Visage", "Dent", "Sable", "Bonheur", "Vent", "R�ve", "For�t", "Lune", "Monde", "Papillon", "Nuage", "Terre", "Sourire", "�toile", "L�vres", "Ville", "Ruisseau", "Chanson", "Vin", "Ami", "Cheval", "Port", "Guitare", "Porte-monnaie", "Pomme", "Danse", "Sac", "Terre", "Piscine", "Pluie", "Chocolat", "Montre", "Vent", "Terre", "Voix", "C�ur", "Poisson", "Orange", "Jour", "Bouteille", "Po�me", "V�lo", "P�re", "Chapeau", "Chemin", "Rire", "Baiser"};

    srand(static_cast<unsigned int>(time(NULL)));
    return words[rand() % (sizeof(words) / sizeof(words[0]))];
}

string returnWordDiff(string solution, string guessed)
{
    solution = toLowerCase(solution);
    guessed = toLowerCase(guessed);

    string result = "";

    for (int i = 0; i <= solution.length() - 1; i++)
    {
        if (solution[i] == guessed[i] || i == 0) // i == 0 pour le premier caract�re
        {
            if (i == 0)
            {
                result += toupper(solution[i]);
            }
            else
            {
                result += solution[i];
            }
        }
        else
        {
            result += " _";
        }
    }

    return result;
}

int rateGuess(string solution, string guessed)
{
    solution = toLowerCase(solution);
    guessed = toLowerCase(guessed);

    int result = 0;

    for (int i = 0; i <= solution.length() - 1; i++)
    {
        if (solution[i] == guessed[i]) result ++;
    }

    return result;
}

int main()
{
    string const solution = returnRandomWord();
    string guessedWord = "";
    string bestGuess = "";
    int maxNbGuess = 10;
    int nbGuess = 0;

    // cout << "Solution:" << solution << "\n" << endl;
    cout << "Longeur du mot: "<< solution.length() << " lettres\n" << endl;

    while (guessedWord != solution)
    {
        if (nbGuess < maxNbGuess)
        {
            cout << "\n\nA remplir: " << returnWordDiff(solution, bestGuess) << endl;
            cout << "Saissisez un mot: " << endl;
            cin >> guessedWord;

            if (guessedWord.length() > solution.length())
            {
                cout << "Mot trop long !" << endl;
            }
            else if (rateGuess(solution, guessedWord) >= rateGuess(solution, bestGuess))
            {
                bestGuess = guessedWord;
                nbGuess++;
            }
        }
        else
        {
            cout << "Trop d essaies, GAME OVER !\nSolution: " << solution << endl;
            break;
        }
    }
    if (guessedWord == solution)
    {
        cout << "Felicitation ! La solution etait: '" << solution << "'\n" << endl;
    }

    return 0;
}
