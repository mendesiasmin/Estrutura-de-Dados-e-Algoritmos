#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> task;

#define start_time first
#define end_time second
#define sorting_by end_time

void mergeSort(vector<task> *Tasks);
void merge(vector<task> *Tasks, int start, int middle, int end);
void scheduling(vector<task> *Tasks);

int main() {

        vector<task> *Tasks = new vector<task>();
        task aux;

        while(scanf("%d %d", &aux.start_time, &aux.end_time) != EOF) {
                  Tasks->push_back(aux);
        }

        scheduling(Tasks);

        return 0;

}

void scheduling(vector<task> *Tasks) {

    mergeSort(Tasks);

    cout << "Schedule" << endl;

    for(unsigned int i = 0; i < Tasks->size(); i++) {
        cout << i + 1 << " - Task: " << (*Tasks)[i].start_time << " to " << (*Tasks)[i].end_time << endl;
    }

}


void mergeSort(vector<task> *Tasks) {
        int max_tasks = Tasks->size() - 1;

        for(int current_size = 1; current_size < max_tasks; current_size++) {
          for(int left_start = 0; left_start < max_tasks; left_start += 2*current_size) {
            int right_end = min(left_start + 2 * current_size - 1, max_tasks);
            int middle = min(left_start + current_size - 1, right_end);

            merge(Tasks, left_start, middle, right_end);
          }
        }
}

void merge(vector<task> *Tasks, int start, int middle, int end) {

  int left_size = middle - start + 1;
  int right_size = end - middle;

  task *L = new task[left_size];
  task *R = new task[right_size];;

  for(int i = 0; i < left_size; i++) L[i] = (*Tasks)[start + i];
  for(int i = 0; i < right_size; i++) R[i] = (*Tasks)[middle + 1 + i];


  int l = 0;
  int r = 0;
  int t = start;

  while(l < left_size && r < right_size) {

    if(L[l].sorting_by <= R[r].sorting_by) {
            (*Tasks)[t] = L[l];
            l++;
    }
    else {
            (*Tasks)[t] = R[r];
            r++;
    }
    t++;
  }

  while(l < left_size) (*Tasks)[t++] = L[l++];
  while(r < right_size) (*Tasks)[t++] = R[r++];

}
