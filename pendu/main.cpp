#include <iostream>
#include <time.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cctype>

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
    string words[100] = {"Bonjour", "Chat", "Maison", "Soleil", "Ecole", "Chien", "Jardin", "Plage", "Voiture", "Livre", "Musique", "Montagne", "Fleurs", "Amour", "Telephone", "Cafe", "Avion", "Arbre", "Parc", "Etoile", "Porte", "Fenêtre", "Rire", "Oiseau", "Nuit", "Rivière", "Enfant", "Crayon", "Bateau", "Table", "Ciel", "Ville", "Poulet", "Pied", "Lumière", "Cadeau", "Appartement", "Gâteau", "Route", "Television", "Etoile", "Rêve", "Hiver", "Ete", "Visage", "Île", "Neige", "Main", "Chapeau", "Verre", "Balle", "Chaussure", "Nez", "Visage", "Dent", "Sable", "Bonheur", "Vent", "Rêve", "Forêt", "Lune", "Monde", "Papillon", "Nuage", "Terre", "Sourire", "Etoile", "Lèvres", "Ville", "Ruisseau", "Chanson", "Vin", "Ami", "Cheval", "Port", "Guitare", "Porte-monnaie", "Pomme", "Danse", "Sac", "Terre", "Piscine", "Pluie", "Chocolat", "Montre", "Vent", "Terre", "Voix", "Cœur", "Poisson", "Orange", "Jour", "Bouteille", "Poème", "Velo", "Père", "Chapeau", "Chemin", "Rire", "Baiser"};

    srand(static_cast<unsigned int>(time(NULL)));
    return words[rand() % (sizeof(words) / sizeof(words[0]))];
}

void sortAlphabetically(vector<char> &letters)
{
    sort(letters.begin(), letters.end());
}

bool isLetterInWord (char letter, string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == letter)
        {
            return true;
        }
    }
    return false;
}

string returnWordMissingLettters(string solution, vector<char> letters, bool forceFirstLetter = true)
{
    solution = toLowerCase(solution);

    string result = "";

    for (int i = 0; i <= solution.length() - 1; i++)
    {
        if (forceFirstLetter && i == 0)
        {
            result += toupper(solution[i]);
        }
        if (find(letters.begin(), letters.end(), solution[i]) != letters.end())
        {
            result += solution[i];
        }
        else
        {
            result += "_";
        }
    }

    return result;
}

int main()
{
    string const solution = returnRandomWord();
    string guessedWord = "";
    int maxNbGuess = 10;
    int nbGuess = 0;
    vector<char> tryedLetter;
    vector<char> rightLetter;

    // cout << "Solution:" << solution << "\n" << endl;
    cout << "Nombre d'essaies max: " << maxNbGuess << endl;
    cout << "Longeur du mot: "<< solution.length() << " lettres\n" << endl;

    while (guessedWord != solution)
    {
        if (nbGuess <= maxNbGuess)
        {
            // Display word with missing letters
            cout << "\n\nA remplir: " << returnWordMissingLettters(solution, rightLetter) << endl;

            // Display tryed letters
            if (tryedLetter.size() > 0)
            {
                sortAlphabetically(tryedLetter);
                cout << "Lettres essayees: ";
                for (int i = 0; i < tryedLetter.size(); i++)
                {
                    cout << tryedLetter[i] << " ";
                }
                cout << endl;
            }

            // Get guess
            cout << "Saissisez un mot: " << endl;
            cin >> guessedWord;

            // Force to be in lowercase
            guessedWord = toLowerCase(guessedWord);

            // Chekc for solution
            if (guessedWord == solution)
            {
                break;
            }

            // Check for word length
            if (guessedWord.length() > solution.length())
            {
                cout << "Mot trop long !" << endl;
            }
            else if (guessedWord.length() < solution.length())
            {
                cout << "Mot trop court !" << endl;
            }
            else
            {
                // Add to rightLetter
                for (int i = 0; i < guessedWord.length(); i++)
                {
                    if (isLetterInWord(guessedWord[i], solution))
                    {
                        rightLetter.push_back(guessedWord[i]);
                    }
                }

                // Addd to tryedLetter
                for (int i = 0; i < guessedWord.length(); i++)
                {
                    if (find(tryedLetter.begin(), tryedLetter.end(), guessedWord[i]) == tryedLetter.end())
                    {
                        tryedLetter.push_back(guessedWord[i]);
                    }
                }

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
        cout << "Il vous a fallu " << nbGuess << " essaies pour trouver la solution." << endl;
    }

    return 0;
}
