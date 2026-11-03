#include <iostream>
using namespace std;

class Calculadora {
    private: 
    float primero;
    float segundo;
    bool comprobar();
    public:
    Calculadora();
    void setNumeros(float, float);
    float getPrimero();
    float getSegundo();
    float sumar();
    float restar();
    float multiplicar();
    bool dividir (float& resultado);
};

Calculadora::Calculadora() {
    primero=0.0;
    segundo=0.0;
}
void Calculadora::setNumeros(float a, float b) {
    primero=a;
    segundo=b;
}

float Calculadora::getPrimero() {
    return primero;
}

float Calculadora::getSegundo() {
    return segundo;
}

float Calculadora::sumar() {
    return primero+segundo;
}

float Calculadora::restar() { 
    return primero-segundo;
}

float Calculadora::multiplicar() { 
    return primero*segundo;
}

bool Calculadora::comprobar() {
    if(segundo==0) 
    return false;
    else
    return true;
}

bool Calculadora::dividir (float& resultado) {
    if(comprobar()) {
    	resultado =primero/segundo;
    	return true;
	}
    return false;
}


int main() {
	float a, b, resultado;
	int opcion;
    Calculadora casio;
    cout<< "Ingrese los numeros a operar: " << endl;
    cin >> a >> b;
    casio.setNumeros(a, b);
    
    do {
    	cout << "\nCALCULADORA"<< endl;
    	cout << "1. Sumar" << endl;
    	cout << "2. Restar" << endl;
    	cout << "3. Multiplicar" << endl;
    	cout << "4. Dividir" << endl;
    	cout << "5. Consultar numeros" << endl;
    	cout << "6. Salir" << endl;
    	cout << "Elija una opcion:" << endl;
    	cin >> opcion;
    	
    	switch(opcion) {
    		case 1: 
    		cout << "Resultado: " << casio.sumar() << endl;
			break;
			case 2:
			cout << "Resultado: " << casio.restar() << endl;
			break;
			case 3:
			cout << "Resultado: " << casio.multiplicar() << endl;
			break;
			case 4: 
				if(casio.dividir(resultado)) {
					cout << "Resultado: " << resultado << endl;
				} else {
					cout << "Error. Divisor invalido." << endl;
				}
				break;
			case 5:
			cout << "Numeros elegidos" << endl;
			cout << "Primer numero: " << casio.getPrimero() << endl;
			cout << "Segundo numero: " << casio.getSegundo() << endl;
			break;
			case 6:
				cout << "Saliendo de la calculadora..." << endl;
				break;
			default:
				cout << "Opcion invalida, elija un numero del 1 al 6." << endl;
	} 	
	}while (opcion!=6);

    return 0;
}
