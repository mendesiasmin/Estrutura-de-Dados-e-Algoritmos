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





bool sequentialSearch(vector<int> &list, vector<Index> &table, int search_value);
vector<Index> generate_index_table(vector<int> &list); 
bool valid_entry(int argc);
void create_list(vector<int> &list, int number_elements);
void print_list(vector<int> list);


int main(int argc, char *argv[]) {
/*
  if (!valid_entry(argc)){
    return 0;
  }*/

  int vector_size = atoi(argv[1]);
  vector<int> list(vector_size);
  create_list(list, vector_size);
  print_list(list);
  generate_index_table(list);
  return 0;
}

bool valid_entry(int argc) {

  if (argc != 4) {
    cout << "Expected: ./<program> <vector_size> <search_value> <instruction>\n";
    cout << "Instruction values: (i) insertion - (r) remove\n";
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
    printf("%d ", list[i]);
  }
  printf("\n");
}



vector<Index> generate_index_table(vector<int> &list) {
  int indexSize = 3;
  vector<Index> table(( list.size()/ indexSize ) );
  for(unsigned int i=0,j=3; j < list.size(); i++,j = j + 3) {
      table[i].index = j;
      table[i].key = list[j];
  }

  for(unsigned int i = 0; i<table.size(); i++) {
    cout << table[i].index << ' ';
    cout << table[i].key << endl;
  }
  return table;
 }


bool sequentialSearch(vector<int> &list, vector<Index> &table, int search_value) {
  
  unsigned int t = 0;
  while(search_value > table[t++].key && t != table.size());

  int l = table[t-1].index;
  while(search_value != list[l++] && l != table[t].index);

  cout << "list[" << l << "] = " << list[l] << endl;
  cout << "tabl[" << t << "] = " << table[t].index << " " << table[t].key  << endl;
  return true;
}
vector<Index> generate_index_table(vector<int> &list); 
