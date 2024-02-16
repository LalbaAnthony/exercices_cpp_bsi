#include <iostream>

using namespace std;

float average(float myArray[10])
{
    float result = 0;
    for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); i++)
    {
        result += myArray[i];
    }
    return result / (sizeof(myArray) / sizeof(myArray[0]));
}

float highest(float myArray[10])
{
    float result = 0;
    for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); i++)
    {
        if (myArray[i] > result)
            result = myArray[i];
    }
    return result;
}

float lowest(float myArray[10])
{
    float result = 20;
    for (int i = 0; i < sizeof(myArray) / sizeof(myArray[0]); i++)
    {
        if (myArray[i] < result)
            result = myArray[i];
    }
    return result;
}

int main()
{
    float grades[10] = {};
    float average_grade = 0;
    float highest_grade = 0;
    float lowest_grade = 20;

    for (int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++)
    {
        cout << "Entrez une note: ";
        cin >> grades[i];
        if (grades[i] < 0 || grades[i] > 20)
        {
            cout << "Note invalide !" << endl;
            i--;
        }
    }

    average_grade = average(grades);
    highest_grade = highest(grades);
    lowest_grade = lowest(grades);

    cout << "Moyenne: " << average_grade << endl;
    cout << "Note la plus haute: " << highest_grade << endl;
    cout << "Note la plus basse: " << lowest_grade << endl;

    return 0;
}

