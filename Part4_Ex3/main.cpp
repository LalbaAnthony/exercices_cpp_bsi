#include <iostream>

using namespace std;

int main()
{
    int tempVar = 0;
    int finalResult = 0;

    cout << "Donnez A:" << endl;
    cin >> tempVar;
    finalResult = tempVar;
    tempVar = 0;

    cout << "Donnez B:" << endl;
    cin >> tempVar;
    finalResult *= tempVar;
    tempVar = 0;

    cout << "Donnez C:" << endl;
    cin >> tempVar;
    finalResult += tempVar;
    tempVar = 0;

    cout << "Donnez D:" << endl;
    cin >> tempVar;
    finalResult -= tempVar;
    tempVar = 0;

    cout << "Resultat: " << finalResult <<endl;

    return 0;
}
