#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include<queue>
#include "InfoClass.h"

using namespace std;

bool checkForItemInt(const vector<int>& arr, int data);
bool checkForItemString(const vector<string>& arr, const string& data);
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year);
void printUserInputQueue(const queue<string>& userInputQueue);

int main(){
    char respuesta = '\0';
    int opciones;
    int placataxi;
    int yeartaxi;
    string motortaxi;
    string modelotaxi;
    vector<int> placa;
    vector<int> year;
    vector<string> motor;
    vector<string> modelo;
    queue<string> userInputQueue;

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
            	
            	// PLACA ES INT
            	
                do {
                    cout << "Ingresando Vehículo..." << endl;     
                    cout << "placa: ";
                    cin >> placataxi;
                } while (checkForItemInt(placa, placataxi));
                placa.push_back(placataxi);

                cin.ignore();  // Ignore newline character
                
                // MOTOR ES STRING

                do {
                    cout << "motor: ";                               
                    getline(cin, motortaxi);
                } while (checkForItemString(motor, motortaxi));
                motor.push_back(motortaxi);
                
                // MODELO ES STRING

                do {
                    cout << "modelo: ";
                    getline(cin, modelotaxi);
                } while (checkForItemString(modelo, modelotaxi));
                modelo.push_back(modelotaxi);
                
                // YEAR ES INT
            	
                do {  
                    cout << "Año: ";
                    cin >> yeartaxi;
                } while (checkForItemInt(year, yeartaxi));
                year.push_back(yeartaxi);
                
                // Agrega todo al QUEUE ()
    			userInputQueue.push(to_string(placataxi));
    			userInputQueue.push(motortaxi);
    			userInputQueue.push(modelotaxi);
    			userInputQueue.push(to_string(yeartaxi));

                break;

            case 2:
                // Code logic for starting a trip
                printUserInputQueue(userInputQueue);
                break;

            case 3:
                // Code logic for ending a trip
                break;

            case 4:
                printTable(placa, motor, modelo, year);
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
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year) {
    InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.add("Año");
    t.endOfRow();

    for (int i = 0; i < placa.size(); i++) {
        t.add(to_string(i));
        t.add(to_string(placa[i]));
        t.add(motor[i]);
        t.add(modelo[i]);
        t.add(to_string(year[i]));
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}

void printUserInputQueue(const queue<string>& userInputQueue) {
    InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.add("Año");
    t.endOfRow();

    queue<string> tempQueue = userInputQueue; // Create a temporary queue to preserve the original queue
    int order = 1; // Start the order from 1

    while (!tempQueue.empty()) {
        t.add(to_string(order));
        t.add(tempQueue.front());
        tempQueue.pop();
        t.add(tempQueue.front());
        tempQueue.pop();
        t.add(tempQueue.front());
        tempQueue.pop();
        t.add(tempQueue.front());
        tempQueue.pop();
        t.endOfRow();
        order++;
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << "User Input Queue:\n";
    cout << t;
}

