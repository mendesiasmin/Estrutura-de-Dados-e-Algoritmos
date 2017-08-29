/*

  Universidade de Brasíla - Campus Gama 2017/02
  Estrutura de Dados e Algortimos 2 - Mauricio Serrano

    Lista 01 - Questão 04: Busca binaria com Index Primario

    Iasmin Santos Mendes, 14/0041940
    Francisco Wallacy Coutinho Braz, 15/0059329

*/


#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define MILLION


struct index {
  int index;
  int key;
};

typedef struct index Index;

bool sequential_search(vector<int> &list, vector<Index> &table, int search_value);
vector<Index> generate_index_table(vector<int> &list); 
bool valid_entry(int argc);
void create_list(vector<int> &list, int number_elements);
void print_list(vector<int> list);


int main(int argc, char *argv[]) {

  if (!valid_entry(argc)){
    return 0;
  }

  int vector_size = atoi(argv[1]);
  vector<int> list(vector_size);
  create_list(list, vector_size);
  cout << "Vector ***********************************" << endl;
  print_list(list);
  cout << "Table Index ***********************************" << endl;
  vector<Index> table_index = generate_index_table(list);
  cout << "Search ***********************************" << endl;
  sequential_search(list, table_index, atoi(argv[2]));
  return 0;
}

bool valid_entry(int argc) {

  if (argc != 3) {
    cout << "Expected: ./<program> <vector_size> <search_value>\n";
    return false;
  }

  return true;
}

void create_list(vector<int> &list, int number_elements) {

  if (number_elements <= 0) {
    cout << "FAIL: Invalid array size\n";
  } else {
    for(int i = 0; i < number_elements; i++ ) {
      list[i] = i*2;
    }
  }
}

void print_list(vector<int> list) {
  for(unsigned int i = 0; i < list.size(); i++) {
    printf("%d[%d] ", i, list[i]);
  }
  printf("\n\n");
}



vector<Index> generate_index_table(vector<int> &list) {
  int indexSize = 3;
  vector<Index> table(( list.size()/ indexSize ) );
  for(unsigned int i=0,j=3; j < list.size(); i++,j = j + 3) {
      table[i].index = j;
      table[i].key = list[j];
  }

  for(unsigned int i = 0; i<table.size(); i++) {
    printf("%d[%d - %d] ", i, table[i].index, table[i].key);
  }
  cout << endl << endl;
  return table;
 }


bool sequential_search(vector<int> &list, vector<Index> &table, int search_value) {
  cout << "Search: " << search_value << endl;

  unsigned int t = 0;
  while(search_value > table[t].key && t < table.size()){
    t++;
  }

  int l = t != 0 ? table[t-1].index : 0;
  while(search_value != list[l] && l != table[t].index){
    l++;
  }

  if (list[l] == search_value) {
    cout << "Find value in " << l << " position\n";
  } else {
    cout << "Value not found" << endl;
  }
  return true;
}
