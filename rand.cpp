
#include<iostream>
#include<random>
#include<sstream> //para uso std::stringstream
#include<chrono>

int main(){

	std::default_random_engine maquina;

	//rangos posibles de random engine
	std::cout << "Min:" << maquina.min() << std::endl;
	std::cout << "Max:" << maquina.max() << std::endl;

	// si la maquina esta en el mismo estado genera los mismos numeros
	std::stringstream estado;
	estado << maquina;

	std::cout << maquina() << std::endl;
	std::cout << maquina() << std::endl;

	estado >> maquina; // reestablece al estado guardado, asi imprime mismos num

	std::cout << maquina() << std::endl;
	std::cout << maquina() << std::endl;


	// seed = unsigned int que sale de tiempo. numero unico de time actual
	// determina estado interno de engine/maquina

	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine maquina2(seed);

	for(int i = 0; i<5; i++){
		int num;
		num = maquina2() % 3 + 1;
		std::cout << num << std::endl;
	}
	return 0;
}
