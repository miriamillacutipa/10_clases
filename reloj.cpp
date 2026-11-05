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

int main() {
	Reloj reloj(10, 30, 15, 50);
	cout << reloj.getHoras() << ":" << reloj.getMinutos() << ":" << reloj.getSegundos() << endl;
	cout << "Bateria: " << reloj.getBateria() << endl;
	return 0;
}
