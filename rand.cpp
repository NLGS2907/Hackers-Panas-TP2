
#include<iostream>
#include<ctime>
#include<cstdlib> //Para uso de rand() y srand()

int main() {

     /* inicializa la generación de números aleatorios
	con srand siempre seran diferentes los numeros
	sin esto cada vez que se ejecuta salen los mismos numeros */

	srand(time(NULL));

	std::cout << "Aleatorios" << std::endl
		  << "[0..2147483647]\t[1..3]" << std::endl;

	for (int i = 0; i < 10; i++) {

	// entero aleatorio entre 0 y 2147483647
	int aleatorio = rand();
	std::cout << aleatorio << "\t\t";

	// entero aleatorio entre 0 y 2
	int aleatorio2 = rand() % 3;
	std::cout << aleatorio2 << "\t\t";


	// reduce el rango a 0..2 y luego lo traslada entre 1 y 3
	int aleatorioEntre1y3 = (aleatorio % 3) + 1;
	std::cout << aleatorioEntre1y3 << std::endl;
		
	}
	
	return 0;
}
