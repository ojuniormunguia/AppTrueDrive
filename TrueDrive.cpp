#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "InfoClass.h"

using namespace std;

bool checkForItemInt(const vector<int>& arr, int data);
bool checkForItemString(const vector<string>& arr, const string& data);
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo);

int main() {
    char respuesta = '\0';
    int opciones;
    int placataxi;
    string motortaxi;
    string modelotaxi;
    vector<int> placa;
    vector<string> motor;
    vector<string> modelo;

    cout << "Bienvenido a TrueDrive" << endl;

    do {
        system("cls");
        cout << "Por favor seleccione una opción:\n\n";
        cout << "\t\t1. Ingresar nuevo vehículo y conductor" << endl;
        cout << "\t\t2. Comenzar Viaje" << endl;
        cout << "\t\t3. Terminar Viaje" << endl;
        cout << "\t\t4. Ver lista de conductores" << endl;
        cout << "\t\t5. Salir del programa" << endl << endl;
        cout << "Escribir su opción: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                cout << "Ingresando Vehículo..." << endl;
                cout << "Ingrese placa del vehículo: ";
                                cin >> placataxi;
                placa.push_back(placataxi);

                cout << "Ingrese número de motor: ";
                cin >> motortaxi;
                motor.push_back(motortaxi);

                cout << "Ingrese modelo del vehículo: ";
                cin.ignore();
                getline(cin, modelotaxi);
                modelo.push_back(modelotaxi);
                break;

            case 2:
                printTable(placa, motor, modelo);
                break;

            case 3:
                // Code logic for ending a trip
                break;

            case 4:
                // Code logic for viewing the list of drivers
                break;

            case 5:
                cout << "Saliendo de TrueDrive..." << endl;
                break;

            default:
                cout << "No ha seleccionado una opción válida (1-5)." << endl;
                break;
        }

        cout << "Desea continuar? (Y/N): ";
        cin >> respuesta;
    } while (respuesta == 'Y' || respuesta == 'y');

    return 0;
}

bool checkForItemInt(const vector<int>& arr, int data) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) == data) {
            cout << "Data is already registered at position [" << i << "].\nPlease enter data again." << endl;
            return true;
        }
    }
    return false;
}

bool checkForItemString(const vector<string>& arr, const string& data) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) == data) {
            cout << "Data is already registered at position [" << i << "].\nPlease enter data again." << endl;
            return true;
        }
    }
    return false;
}

void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo) {
    InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.endOfRow();

    for (int i = 0; i < placa.size(); i++) {
        t.add(to_string(i));
        t.add(to_string(placa.at(i)));
        t.add(motor.at(i));
        t.add(modelo.at(i));
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}

