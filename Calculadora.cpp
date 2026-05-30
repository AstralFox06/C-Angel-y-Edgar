#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operador;

    cout << "Ingresa el primer numero: ";
    cin >> num1;

    cout << "Ingresa un operador (+, -, *, /): ";
    cin >> operador;

    cout << "Ingresa el segundo numero: ";
    cin >> num2;

    switch (operador) {
        case '+':
            cout << "Resultado: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Resultado: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Resultado: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Resultado: " << num1 / num2 << endl;
            } else {
                cout << "Error: No se puede dividir entre cero." << endl;
            }
            break;
        default:
            cout << "Error: Operador no valido." << endl;
            break;
    }

    return 0;
}
