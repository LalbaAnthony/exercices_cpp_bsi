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
    string words[100] = {"Bonjour", "Chat", "Maison", "Soleil", "École", "Chien", "Jardin", "Plage", "Voiture", "Livre", "Musique", "Montagne", "Fleurs", "Amour", "Téléphone", "Café", "Avion", "Arbre", "Parc", "Étoile", "Porte", "Fenêtre", "Rire", "Oiseau", "Nuit", "Rivière", "Enfant", "Crayon", "Bateau", "Table", "Ciel", "Ville", "Poulet", "Pied", "Lumière", "Cadeau", "Appartement", "Gâteau", "Route", "Télévision", "Étoile", "Rêve", "Hiver", "Été", "Visage", "Île", "Neige", "Main", "Chapeau", "Verre", "Balle", "Chaussure", "Nez", "Visage", "Dent", "Sable", "Bonheur", "Vent", "Rêve", "Forêt", "Lune", "Monde", "Papillon", "Nuage", "Terre", "Sourire", "Étoile", "Lèvres", "Ville", "Ruisseau", "Chanson", "Vin", "Ami", "Cheval", "Port", "Guitare", "Porte-monnaie", "Pomme", "Danse", "Sac", "Terre", "Piscine", "Pluie", "Chocolat", "Montre", "Vent", "Terre", "Voix", "Cœur", "Poisson", "Orange", "Jour", "Bouteille", "Poème", "Vélo", "Père", "Chapeau", "Chemin", "Rire", "Baiser"};

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
        if (solution[i] == guessed[i] || i == 0) // i == 0 pour le premier caractère
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
