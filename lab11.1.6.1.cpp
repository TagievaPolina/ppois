#include "Header.h"
using namespace std;



int main()
{

    Fraction first(-7, 6);
    Fraction second(5, 6);
    Fraction third(1,1);
    third = first + second;
    cout <<"Slojenie " << third.toString() << '\n';
    third = first - second;
    cout << "Vichitanie " << third.toString() << '\n';
    first *= second; // пример *=
    cout << "Umnojenie s prisvoeniem" << first.toString() << '\n';
    first /= second;
    cout << "Delenie s prisvoeniem" << first.toString() << '\n';
    first++;
    cout << "Postincriment " << first.toString() << '\n';
    --first;
    cout << "Predecrement " << first.toString() << '\n';

    bool b;
    b = first > second;
    cout << "Bolshe " << b << '\n';
    b = first <= second;
    cout << "Menshe libo ravno " << b << '\n';
    cout <<"Celaya chast pervogo " << toInt(first) <<'\n';
    cout << "Double vtorogo " << toDouble(second) << '\n';
}