#include <iostream>
#include <iomanip>
using namespace std;

class Reloj {
	private:
		int horas, minutos, segundos;
		int bateria;
	public:
		Reloj(int h, int m, int s, int b);
		bool ajustarHora(int h, int m, int s);
		
		int getHoras();
		int getMinutos();
		int getSegundos();
		int getBateria();
		
		void tic_tac();
		bool avanza(int h, int m, int s);
		bool atrasa(int h, int m, int s);
		
		bool estaParado();
		bool recargaBateria(int b);
		
		void horaFormato12h();
		void horaFormato24h();
};

Reloj::Reloj(int h, int m, int s, int b){
	if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59 || b<0 || b>100) {
		horas=0;
		minutos=0;
		segundos=0;
		bateria=0;
	} else {
		horas=h;
		minutos=m;
		segundos=s;
		bateria=b;
	}
}

bool Reloj::ajustarHora(int h, int m, int s) {
	if (h<0 || h>23 || m<0 || m>59 || s<0 || s>59) {
		return false;
	}
	horas=h;
	minutos=m;
	segundos=s;
	return true;
}

int Reloj::getHoras() {
	return horas;
}

int Reloj::getMinutos() {
	return minutos;
}

int Reloj::getSegundos() {
	return segundos;
}

int Reloj::getBateria() {
	return bateria;
}

void Reloj::tic_tac() {
	if (bateria > 0) {
		segundos++;
		if (segundos == 60) {
			segundos=0;
			minutos++;
			if (minutos == 60) {
				minutos=0;
				horas++;
				if (horas == 24) {
					horas=0;
				}
			}
		}
		bateria--;
	}
}

bool Reloj::avanza(int h, int m, int s) {
	if (h<0 || m<0 || s<0) {
		return false;
	}
	int total = horas*3600 + minutos*60 + segundos;
	int cambio = h*3600 + m*60 + s;
	total = (total + cambio) % 86400;
	horas = total / 3600;
	minutos = (total % 3600) / 60;
	segundos = total % 60;
	return true;
}

bool Reloj::atrasa(int h, int m, int s) {
	if (h<0 || m<0 || s<0) {
		return false;
	}
	int total = horas*3600 + minutos*60 + segundos;
	int cambio = h*3600 + m*60 + s;
	total = ((total - cambio) % 86400 + 86400) % 86400;
	horas = total / 3600;
	minutos = (total % 3600) / 60;
	segundos = total % 60;
	return true;
}

bool Reloj::estaParado() {
	if (bateria == 0) {
		return true;
	} else {
		return false;
	}
}

bool Reloj::recargaBateria(int b) {
	if (b > 0 && bateria + b <= 100) {
		bateria = bateria + b;
		return true;
	}
	return false;
}

void Reloj::horaFormato12h() {
	int h12 = horas % 12;
	if (h12 == 0) {
		h12 = 12;
	}
	cout << setfill('0') << setw(2) << h12 << ":" << setw(2) << minutos << ":" << setw(2) << segundos;
	if (horas < 12) {
		cout << " AM" << endl;
	} else {
		cout << " PM" << endl;
	}
}

void Reloj::horaFormato24h() {
	cout << setfill('0') << setw(2) << horas << ":" << setw(2) << minutos << ":" << setw(2) << segundos << endl;
}

int main() {
	int opcion, tipo, h, m, s, b;
	
	cout << "Ingresa hora, minutos, segundos y bateria inicial: ";
	cin >> h >> m >> s >> b;
	Reloj reloj(h, m, s, b);
	
	do {
		cout << "\nRELOJ DIGITAL" << endl;
		cout << "Elija una opcion:" << endl;
		cout << "1. Consultar la hora" << endl;
		cout << "2. Ajustar la hora" << endl;
		cout << "3. Avanzar un segundo" << endl;
		cout << "4. Adelantar o atrasar la hora" << endl;
		cout << "5. Recargar la bateria" << endl;
		cout << "6. Consultar la bateria" << endl;
		cout << "7. Salir" << endl;
		cin >> opcion;
		
		switch(opcion) {
			case 1:
				cout << "1. Formato 12 horas" << endl;
				cout << "2. Formato 24 horas" << endl;
				cin >> tipo;
				if (tipo == 1) {
					cout << "Hora: ";
					reloj.horaFormato12h();
				} else if (tipo == 2) {
					cout << "Hora: ";
					reloj.horaFormato24h();
				} else {
					cout << "Opcion invalida." << endl;
				}
				break;
			case 2:
				cout << "Ingresa hora, minutos y segundos: ";
				cin >> h >> m >> s;
				if (reloj.ajustarHora(h, m, s)) {
					cout << "Hora ajustada correctamente." << endl;
				} else {
					cout << "Error. Hora fuera de rango." << endl;
				}
				break;
			case 3:
				if (reloj.estaParado()) {
					cout << "El reloj esta parado. Recargue la bateria." << endl;
				} else {
					reloj.tic_tac();
					cout << "Se avanzo un segundo. Hora: ";
					reloj.horaFormato24h();
				}
				break;
			case 4:
				cout << "1. Adelantar" << endl;
				cout << "2. Atrasar" << endl;
				cin >> tipo;
				if (tipo == 1 || tipo == 2) {
					cout << "Ingresa horas, minutos y segundos: ";
					cin >> h >> m >> s;
					bool exito;
					if (tipo == 1) {
						exito = reloj.avanza(h, m, s);
					} else {
						exito = reloj.atrasa(h, m, s);
					}
					if (exito) {
						cout << "Nueva hora: ";
						reloj.horaFormato24h();
					} else {
						cout << "Error. No se permiten cantidades negativas." << endl;
					}
				} else {
					cout << "Opcion invalida." << endl;
				}
				break;
			case 5:
				cout << "Unidades a recargar: ";
				cin >> b;
				if (reloj.recargaBateria(b)) {
					cout << "Recarga exitosa. Bateria: " << reloj.getBateria() << endl;
				} else {
					cout << "Error. Cantidad invalida o supera las 100 unidades." << endl;
				}
				break;
			case 6:
				cout << "Bateria: " << reloj.getBateria() << " unidades" << endl;
				break;
			case 7:
				cout << "Saliendo del reloj..." << endl;
				break;
			default:
				cout << "Opcion invalida, elija un numero del 1 al 7." << endl;
		}
	} while (opcion != 7);
	
	return 0;
}
