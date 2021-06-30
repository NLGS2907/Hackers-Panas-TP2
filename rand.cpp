/*
 * main.cpp
 *
 *  Created on: Jun 29, 2021
 *      Author: Guillermina
 */

#include <iostream>
#include <random>
#include<time.h>

int main() {

	/* inicializa la generación de números aleatorios */
		srand(time(NULL));

		std::cout << "Aleatorios" << std::endl
				  << "[0..2147483647]\t[1..3]" << std::endl;

		for (int i = 0; i < 10; i++) {

			/* entero aleatorio entre 0 y 2147483647 */
			int aleatorio = rand();
			std::cout << aleatorio << "\t\t";


			/* reduce el rango a 0..2 y luego lo traslada entre 1 y 3 */
			int aleatorioEntre1y3 = (aleatorio % 3) + 1;
			std::cout << aleatorioEntre1y3 << std::endl;
		}

	return 0;
}


