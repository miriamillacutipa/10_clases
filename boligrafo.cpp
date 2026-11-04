#include <iostream>
#include <string>
using namespace std; 

class Boligrafo {
	private:
		int tinta;
		string color;
	public:
		Boligrafo();
		int getTinta();
		string getColor();
		bool setColor(string);
		bool escribir(int);
		bool recargar(int);
		void mostrarEstado();
};

Boligrafo::Boligrafo() {
	tinta=100;
	color="azul";
}

int Boligrafo::getTinta() {
	return tinta;
}

string Boligrafo::getColor(){
	return color;
}

bool Boligrafo::setColor(string nuevoColor) {
	if(nuevoColor=="azul" || nuevoColor=="rojo" || nuevoColor=="verde" || nuevoColor=="negro") {
		color=nuevoColor;
		return true;
	}
	return false;
}

bool Boligrafo::escribir(int unidades) {
	if(unidades>0 && unidades<=tinta) {
		tinta=tinta-unidades;
		return true;
	}
	return false;
	
}
bool Boligrafo::recargar(int unidades) {
    if (unidades > 0 && tinta + unidades <= 100) {
        tinta = tinta + unidades;
        return true;
    }
    return false;
    
}
void Boligrafo::mostrarEstado() {
	cout << "Color: " << color << endl;
	cout << "Tinta disponible: " << tinta << endl;
}

int main() {
	Boligrafo lapicero;
    int opcion, unidades;
    string nuevoColor;

    do {
        cout << "\nBOLIGRAFO" << endl;
        cout << "1. Escribir" << endl;
        cout << "2. Recargar" << endl;
        cout << "3. Cambiar color" << endl;
        cout << "4. Consultar estado" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Unidades de tinta a consumir: ";
                cin >> unidades;
                if (lapicero.escribir(unidades)) {
                    cout << "Tinta consumida: " << unidades << endl;
                    cout << "Tinta restante: " << lapicero.getTinta() << endl;
                } else {
                    cout << "Error: cantidad invalida o tinta insuficiente." << endl;
                }
                break;
            case 2:
                cout << "Unidades de tinta a recargar: ";
                cin >> unidades;
                if (lapicero.recargar(unidades)) {
                    cout << "Recarga exitosa. Tinta actual: " << lapicero.getTinta() << endl;
                } else {
                    cout << "Error: cantidad invalida o supera las 100 unidades." << endl;
                }
                break;
            case 3:
                cout << "Nuevo color (azul, rojo, verde, negro): ";
                cin >> nuevoColor;
                if (lapicero.setColor(nuevoColor)) {
                    cout << "Color cambiado a " << lapicero.getColor() << endl;
                } else {
                    cout << "Error: color no permitido." << endl;
                }
                break;
            case 4:
                lapicero.mostrarEstado();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida, elija un numero del 1 al 5." << endl;
        }
    } while (opcion != 5);

    return 0;
}
