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
void printTableEjecutiva(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year);
void printTableTradicional(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year);
void printTableViajeEjecutiva(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year);
void printTableViajeTradicional(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year);


int main(){
    char respuesta = '\0';
    int control;
    int opciones;
    int opcioneslista;
    int opcionesviaje;
    vector<string> vtype; 
    queue<string> userInputQueue;
    int yearchecker;
    int moverint;
	string moverstring;
	    
    //U S E R   I N P U T S
    //Carros
	int placataxi;
    int yeartaxi;
    string type;
    string motortaxi;
    string modelotaxi;
    //Conductor
    string nombre;
    string apellido;
    int dui;
    int licencia;
    int numisss;
    int telefono;
    
    
    //V E C T O R E S   G E N E R A L E S
    //Carro
    vector<int> placa;
    vector<int> year;
    vector<string> motor;
    vector<string> modelo;
    //Conductor 
    vector<string> vnombre;
    vector<string> vapellido;
    vector<int> vdui;
    vector<int> vlicencia;
    vector<int> vnumisss;
    vector<int> vtelefono;
    
    //V E C T O R E S   T R A D I C I O N A L E S
    //Carro
    vector<int> placaTradicional;
    vector<int> yearTradicional;
    vector<string> motorTradicional;
    vector<string> modeloTradicional;
    //Conductor 
    vector<string> vnombreTradicional;
    vector<string> vapellidoTradicional;
    vector<int> vduiTradicional;
    vector<int> vlicenciaTradicional;
    vector<int> vnumisssTradicional;
    vector<int> vtelefonoTradicional;
    
    //V E C T O R E S   E J E C U T I V O
    //Carro
    vector<int> placaEjecutivo;
    vector<int> yearEjecutivo;
    vector<string> motorEjecutivo;
    vector<string> modeloEjecutivo;
    //Conductor 
    vector<string> vnombreEjecutivo;
    vector<string> vapellidoEjecutivo;
    vector<int> vduiEjecutivo;
    vector<int> vlicenciaEjecutivo;
    vector<int> vnumisssEjecutivo;
    vector<int> vtelefonoEjecutivo;
    
    //V E C T O R E S   E N   V I A J E S  (Tradicional)
    //Carro
    vector<int> placaenviajeTradicional;
    vector<int> yearenviajeTradicional;
    vector<string> motorenviajeTradicional;
    vector<string> modeloenviajeTradicional;
    //Conductor
    vector<string> vnombreenviajeTradicional;
    vector<string> vapellidoenviajeTradicional;
    vector<int> vduienviajeTradicional;
    vector<int> vlicenciaenviajeTradicional;
    vector<int> vnumisssenviajeTradicional;
    vector<int> vtelefonoenviajeTradicional;
    
    //V E C T O R E S   E N   V I A J E S  (Ejecutivo)
    //Carro
    vector<int> placaenviajeEjecutivo;
    vector<int> yearenviajeEjecutivo;
    vector<string> motorenviajeEjecutivo;
    vector<string> modeloenviajeEjecutivo;
    //Conductor
    vector<string> vnombreenviajeEjecutivo;
    vector<string> vapellidoenviajeEjecutivo;
    vector<int> vduienviajeEjecutivo;
    vector<int> vlicenciaenviajeEjecutivo;
    vector<int> vnumisssenviajeEjecutivo;
    vector<int> vtelefonoenviajeEjecutivo;
    

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
				    	yearEjecutivo.push_back(yeartaxi); 
				    	//ENVIARLO A QUEUE EJECUTIVO
                    } else if(yeartaxi>=2010 && yeartaxi<2015) {
					 	 type="Tradicional";
					 	 yearchecker = 2;
					 	 yearTradicional.push_back(yeartaxi); 
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
                	placaEjecutivo.push_back(placataxi);

                	cin.ignore();
                
                
                	// MOTOR ES STRING (REPETIR)

                	cout << "motor: ";                               
                	getline(cin, motortaxi);
					motor.push_back(motortaxi);
					motorEjecutivo.push_back(motortaxi);
                
                	// MODELO ES STRING (REPETIR)

                	cout << "modelo: ";
                	getline(cin, modelotaxi);
                	modelo.push_back(modelotaxi);
                	modeloEjecutivo.push_back(modelotaxi);
                
                	//DATOS DEL CONDUCTOR
                
                	//NOMBRE ES STRING (ÚNICO)
                
                	do{
                		cout<< "Ingresando datos del conductor...\n";
                		cout<< "Ingrese el nombre: ";
                		cin>>nombre;
					}while(checkForItemString(vnombre,nombre));
					vnombre.push_back(nombre);
					vnombreEjecutivo.push_back(nombre);
				
					//APELLIDO ES STRING (ÚNICO)
				
					do{
					cout<< "Ingrese el apellido: ";
					cin>>apellido;
					}while(checkForItemString(vapellido,apellido));
					vapellido.push_back(apellido);
					vapellidoEjecutivo.push_back(apellido);
                
                	//DUI ES INT (ÚNICO)
                
                	do{
                		cout<<"Ingrese el # de DUI sin guion: ";
                		cin>>dui;
					}while(checkForItemInt(vdui,dui));
					vdui.push_back(dui);
					vduiEjecutivo.push_back(dui);
				
					//LICENCIA (ÚNICO)
				
					do{
						cout<<"Ingresa el # de licencia sin guion: ";
						cin>>licencia;
					}while(checkForItemInt(vlicencia,licencia));
					vlicencia.push_back(licencia);
					vlicenciaEjecutivo.push_back(licencia);
				
					//SEGURO SOCIAL ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de seguro social sin guiones: ";
						cin>>numisss;
					}while(checkForItemInt(vnumisss,numisss));
					vnumisss.push_back(numisss);
					vnumisssEjecutivo.push_back(numisss);
				
					//NÚMERO DE TELÉFONO ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de telefono: ";
						cin>>telefono;
					}while(checkForItemInt(vtelefono,telefono));
					vtelefono.push_back(telefono);
					vtelefonoEjecutivo.push_back(telefono);
                
                	break;
                		
                	case 2:
                	
					// PLACA ES INT (ÚNICO)
            	
                	do {
                    	cout << "Ingresando Vehículo Tradicional" << endl;     
                    	cout << "placa: ";
                    	cin >> placataxi;
                	} while (checkForItemInt(placa, placataxi));
                	placa.push_back(placataxi);
                	placaTradicional.push_back(placataxi);

                	cin.ignore();
                
                
                	// MOTOR ES STRING (REPETIR)

                	cout << "motor: ";                               
                	getline(cin, motortaxi);
					motor.push_back(motortaxi);
					motorTradicional.push_back(motortaxi);
                
                	// MODELO ES STRING (REPETIR)

                	cout << "modelo: ";
                	getline(cin, modelotaxi);
                	modelo.push_back(modelotaxi);
                	modeloTradicional.push_back(modelotaxi);
                
                	//DATOS DEL CONDUCTOR
                
                	//NOMBRE ES STRING (REPETIR)
                
                	
                	cout<< "Ingresando datos del conductor...\n";
                	cout<< "Ingrese el nombre: ";
                	cin>>nombre;
					vnombre.push_back(nombre);
					vnombreTradicional.push_back(nombre);
				
					//APELLIDO ES STRING (REPETIR)
				
					
					cout<< "Ingrese el apellido: ";
					cin>>apellido;
					vapellido.push_back(apellido);
					vapellidoTradicional.push_back(apellido);
                
                	//DUI ES INT (ÚNICO)
                
                	do{
                		cout<<"Ingrese el # de DUI sin guion: ";
                		cin>>dui;
					}while(checkForItemInt(vdui,dui));
					vdui.push_back(dui);
					vduiTradicional.push_back(dui);
				
					//LICENCIA (ÚNICO)
				
					do{
						cout<<"Ingresa el # de licencia sin guion: ";
						cin>>licencia;
					}while(checkForItemInt(vlicencia,licencia));
					vlicencia.push_back(licencia);
					vlicenciaTradicional.push_back(licencia);
				
					//SEGURO SOCIAL ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de seguro social sin guiones: ";
						cin>>numisss;
					}while(checkForItemInt(vnumisss,numisss));
					vnumisss.push_back(numisss);
					vnumisssTradicional.push_back(numisss);
				
					//NÚMERO DE TELÉFONO ES INT (ÚNICO)
				
					do{
						cout<< "Ingresa el numero de telefono: ";
						cin>>telefono;
					}while(checkForItemInt(vtelefono,telefono));
					vtelefono.push_back(telefono);
					vtelefonoTradicional.push_back(telefono);
                
                	break;
                				
				}
                
            	break;

            case 2:
                // Ver lista de vehículos y conductores
                cout << "¿Cual lista desea ver?:\n\n";
        		cout << "\t\t1. Lista de conductores totales" << endl;
        		cout << "\t\t2. Lista de conductores ejecutivos disponibles" << endl;
        		cout << "\t\t3. Lista de conductores Tradicionales disponibles" << endl;
        		cout << "\t\t4. Lista de conductores en viaje" << endl;
                
                cout << "Seleccionar (1,2,3 o 4): ";
        		cin>>opcioneslista;
        		
        		switch(opcioneslista) {
        			case 1:
        				printTable(placa, motor, modelo, year);//Imprime tabla completa
        				break;
        			case 2:
        				printTableEjecutiva(placaEjecutivo, motorEjecutivo, modeloEjecutivo, yearEjecutivo);//Imprime ejecutiva disponible
        				break;
        			case 3:
        				printTableTradicional(placaTradicional, motorTradicional, modeloTradicional, yearTradicional);//Imprime tradicional disponible
        				break;
        			case 4:  				
        				//Imprime los que estan en viaje
        				printTableViajeEjecutiva(placaenviajeEjecutivo, motorenviajeEjecutivo, modeloenviajeEjecutivo, yearenviajeEjecutivo);
        				break;
				}

                //printUserInputQueue(userInputQueue);  
                break;

            case 3:
                // COMIENZA VIAJE
                cout << "¿Qué tipo de viaje desea iniciar?:\n\n";
        		cout << "\t\t1. Ejecutivo" << endl;
        		cout << "\t\t2. Tradicional" << endl;
                
                cout << "Seleccionar (1,2,3 o 4): ";
        		cin>>opcionesviaje;
        		
        		switch(opcionesviaje) {
        			case 1:
        				//EJECUTIVO
        				
        				
        				moverint = placaEjecutivo[0]; //usa "moverint/moverstring" para copiar primer elemento
        				placaEjecutivo.erase(placaEjecutivo.begin()); //elimina el primer elemento
						placaenviajeEjecutivo.push_back(moverint); //pega el primer elemento en vector "enviaje"
						
						moverint = yearEjecutivo[0];
						yearEjecutivo.erase(yearEjecutivo.begin());
						yearenviajeEjecutivo.push_back(moverint);    
						
						moverstring = motorEjecutivo[0];
        				motorEjecutivo.erase(motorEjecutivo.begin());
						motorenviajeEjecutivo.push_back(moverstring);
						
						moverstring = modeloEjecutivo[0];
						modeloEjecutivo.erase(modeloEjecutivo.begin());
						modeloenviajeEjecutivo.push_back(moverstring);    
						
						moverstring = vnombreEjecutivo[0];
        				vnombreEjecutivo.erase(vnombreEjecutivo.begin());
						vnombreenviajeEjecutivo.push_back(moverstring);
						
						moverstring = vapellidoEjecutivo[0];
						vapellidoEjecutivo.erase(vapellidoEjecutivo.begin());
						vapellidoenviajeEjecutivo.push_back(moverstring);   
						
						moverint = vduiEjecutivo[0];
        				vduiEjecutivo.erase(vduiEjecutivo.begin());
						vduienviajeEjecutivo.push_back(moverint);
						
						moverint = vlicenciaEjecutivo[0];
						vlicenciaEjecutivo.erase(vlicenciaEjecutivo.begin());
						vlicenciaenviajeEjecutivo.push_back(moverint);    
						
						moverint = vnumisssEjecutivo[0];
        				vnumisssEjecutivo.erase(vnumisssEjecutivo.begin());
						vnumisssenviajeEjecutivo.push_back(moverint);
						
						moverint = vtelefonoEjecutivo[0];
						vtelefonoEjecutivo.erase(vtelefonoEjecutivo.begin());
						vtelefonoenviajeEjecutivo.push_back(moverint); 
						
						cout << "viaje ejecutivo iniciado :)" << endl;
        				break;
        			case 2:
        				//TRADICIONAL
        				break;
        		}
                break;

            case 4:
                // TERMINA VIAJE
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
void printTableEjecutiva(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year) {
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
void printTableTradicional(const vector<int>& placa, const vector<string>& motor, const vector<string>& modelo, const vector<int>& year) {
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

void printTableViajeEjecutiva(const vector<int>& placaenviajeEjecutivo, const vector<string>& motorenviajeEjecutivo, const vector<string>& modeloenviajeEjecutivo, 
	const vector<int>& yearenviajeEjecutivo) {
    
	InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.add("Año");
    t.endOfRow();

    for (int i = 0; i < placaenviajeEjecutivo.size(); i++) {
        t.add(to_string(i+1)); //agrega el orden
        t.add(to_string(placaenviajeEjecutivo[i])); //agrega el PLACA
        t.add(motorenviajeEjecutivo[i]); //agrega el MOTOR
        t.add(modeloenviajeEjecutivo[i]); //agrega el MODELO
        t.add(to_string(yearenviajeEjecutivo[i])); //agrega el AÑO
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}
void printTableViajeTradicional(const vector<int>& placaenviajeTradicional, const vector<string>& motorenviajeTradicional, const vector<string>& modeloenviajeTradicional, 
	const vector<int>& yearenviajeTradicional) {
    
	InfoClass t('-', '|', '+');
    t.add("Order");
    t.add("Placa");
    t.add("Motor");
    t.add("Modelo");
    t.add("Año");
    t.endOfRow();

    for (int i = 0; i < placaenviajeTradicional.size(); i++) {
        t.add(to_string(i+1)); //agrega el orden
        t.add(to_string(placaenviajeTradicional[i])); //agrega el PLACA
        t.add(motorenviajeTradicional[i]); //agrega el MOTOR
        t.add(modeloenviajeTradicional[i]); //agrega el MODELO
        t.add(to_string(yearenviajeTradicional[i])); //agrega el AÑO
        t.endOfRow();
    }

    t.setAlignment(2, InfoClass::Alignment::RIGHT);
    cout << t;
}