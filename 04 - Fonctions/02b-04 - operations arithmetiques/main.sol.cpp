#include <cstdlib>
#include <iostream>

using namespace std;

//------------------------------------------------------------
bool operation(double operandeGauche,
               double operandeDroite,
               char operateur,
               double &resultat);

void test(double operandeGauche,
          double operandeDroite,
          char operateur);

//------------------------------------------------------------
int main() {
    double operandeGauche, operandeDroite;
    cout << "Donnez 2 nombres reels : ";
    cin >> operandeGauche >> operandeDroite;// saisie non contrôlée ici
    test(operandeGauche, operandeDroite, '+');
    test(operandeGauche, operandeDroite, '-');
    test(operandeGauche, operandeDroite, '*');
    test(operandeGauche, operandeDroite, '/');
    test(operandeGauche, operandeDroite, '?');
    return EXIT_SUCCESS;
}

//------------------------------------------------------------
bool operation(double operandeGauche,
               double operandeDroite,
               char operateur,
               double &resultat) {

    switch (operateur) {
        case '+':
            resultat = operandeGauche + operandeDroite;
            break;
        case '-':
            resultat = operandeGauche - operandeDroite;
            break;
        case '*':
            resultat = operandeGauche * operandeDroite;
            break;
        case '/':
            resultat = operandeGauche / operandeDroite;
            break;
        default:
            return false;
    }
    return true;
}

//------------------------------------------------------------
void test(double operandeGauche,
          double operandeDroite,
          char operateur) {
    double resultat;
    if (operation(operandeGauche, operandeDroite, operateur, resultat)) {
        cout << operandeGauche << " " << operateur << " "
             << operandeDroite << " = " << resultat << endl;
    }

    else {
        cout << "L'operation " << "'" << operateur << "'" << " est illicite" << endl;
    }
}

// Donnez 2 nombres reels : 3 5
// 3 + 5 = 8
// 3 - 5 = -2
// 3 * 5 = 15
// 3 / 5 = 0.6
// L'operation '?' est illicite
