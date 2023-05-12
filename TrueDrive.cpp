#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<conio.h>
#include "InfoClass.h"

using namespace std;

bool checkForItemInt(vector<int> arr, int data);
bool checkForItemInt(vector<string> arr, string data);
void printTable(vector<int> placa, vector<string> motor, vector<string> modelo, vector<int>año, vector<string>nombre, vector<string>apellidos, vector<int>dui, vector<int>seguro, vector<int>telefono);

int main(){
	char respuesta='\0';
	int opciones;
	int placataxi;
	char confirmacion;
	int placataxiToReinsert;
	string driverName;
	string plateNumber;
	cout<<"Bienvenido a TrueDrive\t\n";
	vector<int> placa;
	vector<string> motor;
	vector<string> modelo;
	vector<int> año;
	vector<string> nombre;
	vector<string> apellidos;
	vector<int> dui;
	vector<int> seguro;
	vector<int> telefono;
	vector<int> nAplaca;
	vector<string> nAmotor;
	vector<string> nAmodelo;
	vector<int> nAaño;
	vector<string> nAnombre;
	vector<string> nAapellidos;
	vector<int> nAdui;
	vector<int> nAseguro;
	vector<int> nAtelefono;
	do{
		system("cls");
		cout<<"Main menu opcioness:\n\n"<<endl;
		cout<<"\t\t1. Add New Taxi to standby queue"<<endl;
		cout<<"\t\t2. Check for actual data"<<endl;
		cout<<"\t\t3. Sent Taxi to a Client"<<endl;
		cout<<"\t\t4. Check for taxis in routes"<<endl;
		cout<<"\t\t5. Reinsert a taxi to avaialable queue"<<endl;
		cout<<"\t\t6. Exit program"<<endl<<endl;
		cout<<"Please, input your opciones: ";
		cin>>opciones;
		switch(opciones){
			case 1:
				do{
					cout<<"Taxi placataxi: ";
					cin>>placataxi;
				}while(checkForItemInt(taxis, placataxi));
				taxis.push_back(placataxi);
				do{
					cout<<"Driver Name: ";
					cin.ignore();
					getline(cin,driverName);
				}while(checkForItemInt(drivers, driverName));
				drivers.push_back(driverName);
				do{
					cout<<"Plate Number: ";
					cin.ignore();
					getline(cin,plateNumber);
				}while(checkForItemInt(plates, plateNumber));
				plates.push_back(plateNumber);
			break;
			case 2:		
				printTable(taxis, drivers, plates);
			break;
			case 3:
				//code logic for sending taxis here
			break;
			case 4:
				//code logic for on route checks
			break;
			case 5:
				//code logic for reinset taxis into avaialable queue
			break;
			case 6:
				cout<<"Program has ended...";
				system("pause");
				system("exit");
			break;
			default:
				cout<<"Non correct opciones has been chosen."<<endl;
			break;
		}
  	cout<<"Desea continuar? (Y/N)?: ";
  	respuesta=getch();
	}while(respuesta=='Y' || respuesta=='y');	
}