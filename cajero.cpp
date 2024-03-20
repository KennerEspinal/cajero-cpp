#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void retirar_dinero(int monto) {
    if (monto <= 0) {
        cout << "Error: El monto no puede ser menor que 0." << endl;
        return;
    }

    if (monto > 1000000) {
        cout << "Error: El monto no puede superar un millon." << endl;
        return;
    }

    if (monto % 10000 != 0) {
        cout << "Error: El monto debe ser un multiplo de 10000." << endl;
        return;
    }

    vector<int> denominaciones = {10000, 20000, 50000, 100000};
    vector<int> billetes(4, 0);
    int contador = 0;
    while (monto > 0) {
        int entra = 0;
        for (int i = contador; i < denominaciones.size(); ++i) {
            if (monto >= denominaciones[i]) {
                billetes[i] += 1;
                monto -= denominaciones[i];
                entra = 1;
            }
        }
        if (entra == 0 && contador == denominaciones.size()) {
            contador = 0;
        } else {
            contador += 1;
        }
    }

    int y = 8; // Ajustar la posición y para que los resultados se impriman debajo del menú
    for (size_t i = 0; i < denominaciones.size(); ++i) {
        gotoxy(0, y);
        cout << "La cantidad de billetes de $" << denominaciones[i] << " es " << billetes[i] << endl;
        y++;
    }
}

int main() {

    int opcion;
    do {
        system("cls");
        cout << "+---------------------------------------+" << endl;
        cout << "|      Bienvenido a RetirBank           |" << endl;
        cout << "+---------------------------------------+" << endl;
        cout << "Seleccione una opcion de retiro:" << endl;
        cout << "1. $20,000\t\t4. $200,000" << endl;
        cout << "2. $50,000\t\t5. $400,000" << endl;
        cout << "3. $100,000\t\t6. $600,000" << endl;
        cout << "7. Monto Diferente\t\t0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                retirar_dinero(20000);
                break;
            case 2:
                retirar_dinero(50000);
                break;
            case 3:
                retirar_dinero(100000);
                break;
            case 4:
                retirar_dinero(200000);
                break;
            case 5:
                retirar_dinero(400000);
                break;
            case 6:
                retirar_dinero(600000);
                break;
            case 7:
                int monto_solicitado;
                cout << "Ingrese el valor a retirar: ";
                cin >> monto_solicitado;
                retirar_dinero(monto_solicitado);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }

        system("pause");
    } while (opcion != 0);

    return 0;
}
