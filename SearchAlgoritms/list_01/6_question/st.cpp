#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>


// A busca para a distribuição usada sempre termina a busca em cerca de 
// 0.002 ~ 0.008, o que mostra que a taxa de crescimento é menor sim que 
// log de n



using namespace std;


int i_search(vector<int> &table, int inf, int sup, int v) {
	


	if ( inf > sup ) 
		return -1;

	int meio = inf + ((v - table[inf]) * (sup - inf)/(table[sup]-table[inf]));
	

	

	if( v == table[meio]) 
		return meio;
	if ( inf == sup ) 
		return -1;
	if( v < table[meio])
		return i_search(table, inf, meio -1, v);
	else
		return i_search(table, meio + 1, sup, v);


}


vector<int> generate_random_vector(int size) {
	
	vector<int> table;
	
	default_random_engine generator;
	uniform_real_distribution<double> distribution(0.0, 1000000);
	
	int number;

	for(int i = 0; i < size; i++) {

		number = (int) distribution(generator);

		table.push_back(number);

	}

	sort(table.begin(), table.end());

	return table;
}

	
int main() {

	vector<int> table;
	int elements[] = {10, 25, 50, 100, 500, 1000, 10000, 100000, 1000000}; 
	int busca, index,iterator;
	iterator = 0;

	while(iterator!=8) {

		table = generate_random_vector(elements[iterator]);
		
		cout << endl << "Qual número desejar procurar?" << endl << endl;
		
		cin >> busca;

		busca = *(table.end());
		
		clock_t c_start = clock();

		index = i_search(table, 0, table.size() - 1, busca);

		clock_t c_end = clock();
		
		cout << "O primeiro vetor levou " << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << "ms\n";

		if( index>0 ) {

			cout << "Valor encontrado em :" << index << endl;

		}
		else
			cout << "Valor não encontrado" << endl;

	iterator++;
	}

	return 0;

}	
