#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include "InfoClass.h"

using namespace std;

bool checkForItemInt(const vector<int>& arr, int data);
bool checkForItemString(const vector<string>& arr, const string& data);
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo);

int main(){
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
                do {
                    cout << "Ingresando Vehículo..." << endl;
                    cout << "placa: ";
                    cin >> placataxi;
                } while (checkForItemInt(placa, placataxi));
                placa.push_back(placataxi);

                cin.ignore();  // Ignore newline character

                do {
                    cout << "motor: ";
                    getline(cin, motortaxi);
                } while (checkForItemString(motor, motortaxi));
                motor.push_back(motortaxi);

                do {
                    cout << "modelo: ";
                    getline(cin, modelotaxi);
                } while (checkForItemString(modelo, modelotaxi));
                modelo.push_back(modelotaxi);

                break;

            case 2:
                // Code logic for starting a trip
                break;

            case 3:
                // Code logic for ending a trip
                break;

            case 4:
                printTable(placa, motor, modelo);
                break;

            case 5:
                cout << "Saliendo de TrueDrive..." << endl;
                system("pause");
                system("exit");
                break;

            default:
                cout << "No ha seleccionado una opción válida (1-5)." << endl;
                break;
        }

        cout << "¿Desea continuar? (Y/N): ";
        respuesta = getch();
    } while (respuesta == 'Y' || respuesta == 'y');
}

bool checkForItemInt(const vector<int>& arr, int data) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == data) {
            cout << "Data is already registered at position [" << i << "].\nPlease enter data again.\n";
            return true;
        }
    }
    return false;
}

bool checkForItemString(const vector<string>& arr, const string& data) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == data) {
            cout << "Data is already registered at position [" << i << "].\nPlease enter data again.\n";
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
        t.add(to_string(placa[i]));
        t.add(motor[i]);
        t.add(modelo[i]);
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}
