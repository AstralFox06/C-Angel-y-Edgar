#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;

bool juegoTerminado;
const int ancho = 20;
const int alto = 20;
int x, y, frutaX, frutaY, puntuacion;
vector<int> colaX(100), colaY(100);
int nCola;
enum Direccion { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direccion dir;

void Inicializar() {
    juegoTerminado = false;
    dir = STOP;
    x = ancho / 2;
    y = alto / 2;
    frutaX = rand() % ancho;
    frutaY = rand() % alto;
    puntuacion = 0;
    nCola = 0;
}

void Dibujar() {
    // Limpia la pantalla reposicionando el cursor para evitar parpadeo severo
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    for (int i = 0; i < ancho + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (j == 0) cout << "#";

            if (i == y && j == x) {
                cout << "O"; // Cabeza de la culebrita
            } else if (i == frutaY && j == frutaX) {
                cout << "*"; // Fruta
            } else {
                bool impreso = false;
                for (int k = 0; k < nCola; k++) {
                    if (colaX[k] == j && colaY[k] == i) {
                        cout << "o"; // Cuerpo de la culebrita
                        impreso = true;
                        break;
                    }
                }
                if (!impreso) cout << " ";
            }

            if (j == ancho - 1) cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < ancho + 2; i++) cout << "#";
    cout << endl;
    cout << "Puntuacion: " << puntuacion << endl;
}

void Entrada() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'x': juegoTerminado = true; break;
        }
    }
}

void Logica() {
    int prevX = colaX[0];
    int prevY = colaY[0];
    int prev2X, prev2Y;
    colaX[0] = x;
    colaY[0] = y;

    for (int i = 1; i < nCola; i++) {
        prev2X = colaX[i];
        prev2Y = colaY[i];
        colaX[i] = prevX;
        colaY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default: break;
    }

    // Colisión con las paredes
    if (x >= ancho || x < 0 || y >= alto || y < 0) {
        juegoTerminado = true;
    }

    // Colisión con el propio cuerpo
    for (int i = 0; i < nCola; i++) {
        if (colaX[i] == x && colaY[i] == y) {
            juegoTerminado = true;
        }
    }

    // Comer fruta
    if (x == frutaX && y == frutaY) {
        puntuacion += 10;
        frutaX = rand() % ancho;
        fruta
