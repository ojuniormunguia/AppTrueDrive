#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include<queue>
#include "InfoClass.h"

//Prueba

using namespace std;

bool checkForItemInt(const vector<int>& arr, int data);
bool checkForItemString(const vector<string>& arr, const string& data);
void printTable(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year);


int main(){
    char respuesta = '\0';
    int control;
    int opciones;
    vector<string> vtype;
    queue<string> userInputQueue;
    int yearchecker;
    
    //U S E R   I N P U T S
    //Carro
    int placataxi;
    int yeartaxi;
    string type;
    string motortaxi;
    string modelotaxi;
    vector<int> placa;
    vector<int> year;
    vector<string> motor;
    vector<string> modelo;
    
    //Conductor 
    string nombre;
    string apellido;
    int dui;
    int licencia;
    int numisss;
    int telefono;
    vector<string> vnombre;
    vector<string> vapellido;
    vector<int> vdui;
    vector<int> vlicencia;
    vector<int> vnumisss;
    vector<int> vtelefono;
    
    //
    

    cout << "Bienvenido a TrueDrive" << endl;

    do {
        system("cls");
        cout << "Por favor seleccione una opción:\n\n";
        cout << "\t\t1. Ingresar nuevo vehículo y conductor" << endl;
        cout << "\t\t2. Ver lista de conductores" << endl;
        cout << "\t\t3. Comenzar Viaje" << endl;
        cout << "\t\t4. Terminar Viaje" << endl;
        cout << "\t\t5. Salir del programa" << endl << endl;
        cout << "Escribir su opción: ";
        cin >> opciones;

        switch (opciones) {
            case 1: //AGREGAR CONDUCTOR
        		//* * * D A T O S   D E L   V E H I C U L O * * *
        		
        		// YEAR ES INT (REPETIR)
        	
                do{
                cout << "Año: ";
                cin >> yeartaxi;
                	
                    if(yeartaxi>=2015) {
					
				    	type="Ejecutiva";
				    	yearchecker = 1;
				    	//ENVIARLO A QUEUE EJECUTIVO
                    } else if(yeartaxi>=2010 && yeartaxi<2015) {
					 	 type="Tradicional";
					 	 yearchecker = 2;
					 	 //ENVIARLO A QUEUE TRADICIONAL
                    } else {
						cout<<"No es posible ingresar este vehiculo debido a la antiguedad...\n";
						yearchecker = 0;
						//REPETIR AÑO
					}
                } while (yearchecker==0);
				year.push_back(yeartaxi);
				
                //YEARCHEKER CATEGORIZA:
                
                //(0) ES DEMASIADO ANTIGUO
                //(1) EJECUTIVO
                //(2) TRADICIONAL
                
                switch (yearchecker) {
                case 1:
                	// PLACA ES INT (ÚNICO)
            	
                	do {
                    	cout << "Ingresando Vehículo Ejecutivo" << endl;     
                    	cout << "placa: ";
                    	cin >> placataxi;
                	} while (checkForItemInt(placa, placataxi));
                	placa.push_back(placataxi);

                	cin.ignore();
                
                
                	// MOTOR ES STRING (REPETIR)

                	cout << "motor: ";                               
                	getline(cin, motortaxi);
					motor.push_back(motortaxi);
                
                	// MODELO ES STRING (REPETIR)

                	cout << "modelo: ";
                	getline(cin, modelotaxi);
                	modelo.push_back(modelotaxi);
                
                	//DATOS DEL CONDUCTOR
                
                	//NOMBRE ES STRING (ÚNICO)
                
                	do{
                		cout<< "Ingresando datos del conductor...\n";
                		cout<< "Ingrese el nombre: ";
                		cin>>nombre;
					}while(checkForItemString(vnombre,nombre));
					vnombre.push_back(nombre);
				
					//APELLIDO ES STRING (ÚNICO)
				
					do{
					cout<< "Ingrese el apellido: ";
					cin>>apellido;
					}while(checkForItemString(vapellido,apellido));
					vapellido.push_back(apellido);
                
                	//DUI ES INT (ÚNICO)
                
                	do{
                		cout<<"Ingrese el # de DUI sin guion: ";
                		cin>>dui;
					}while(checkForItemInt(vdui,dui));
					vdui.push_back(dui);
				
					//LICENCIA (ÚNICO)
				
					do{
						cout<<"Ingresa el # de licencia sin guion: ";
						cin>>licencia;
					}while(checkForItemInt(vlicencia,licencia));
					vlicencia.push_back(licencia);
				
					//SEGURO SOCIAL ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de seguro social sin guiones: ";
						cin>>numisss;
					}while(checkForItemInt(vnumisss,numisss));
					vnumisss.push_back(numisss);
				
					//NÚMERO DE TELÉFONO ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de telefono: ";
						cin>>telefono;
					}while(checkForItemInt(vtelefono,telefono));
					vtelefono.push_back(telefono);
                
                	break;
                		
                	case 2:
                		
                		break;
                	
                		
				}
                
            	

            case 2:
                // Ver lista de vehículos y conductores
                printTable(placa, motor, modelo, year);
                //printUserInputQueue(userInputQueue);  
                break;

            case 3:
                // Code logic for ending a trip
                break;

            case 4:
                
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
        t.add(to_string(i+1)); //agrega el orden
        t.add(to_string(placa[i])); //agrega el PLACA
        t.add(motor[i]); //agrega el MOTOR
        t.add(modelo[i]); //agrega el MODELO
        t.add(to_string(year[i])); //agrega el AÑO
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}

/* void printUserInputQueue(const queue<string>& userInputQueue) {
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
} */
