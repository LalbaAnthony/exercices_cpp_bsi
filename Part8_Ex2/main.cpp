#include <iostream>

using namespace std;

int main() {
    // Declaration et initialisation de la variable age
    int age = 20;

    // Declaration et initialisation du pointeur a
    int* a = &age;

    // Affichage des informations sur la variable age
    cout << "age vaut : " << age << " et est stocke a l'adresse : " << &age << endl;

    // Affichage des informations sur le pointeur a
    cout << "a (le pointeur de age) vaut : " << a << " et est stocke a l'adresse : " << &a << endl;

    return 0;
}
