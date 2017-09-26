#include <iostream>
#include <assert.h>


using namespace std;




int min(int A, int B) {

	return (A < B) ? A : B;
	
}


void printArray(int arr[], int l, int r) {
	
	cout << '[';

	for( int i = l; i <=r; i++) {

		if( i != r) {

			cout << arr[i] << ' ';

		} 
		else {
			cout << arr[i];

		}

	}
	cout << ']';


}



void merge(int arr[], int l, int m, int r) {


	int i, j;

	int aux[100];

	for( i = m+1; i > l; i--) {

		aux[i-1] = arr[i-1];

	}

	for( j = m; j < r; j++) {

		aux[r+m-j] = arr[j+1];

	}

	printArray(aux,l,r); 

	cout << "  ---Changes to---  ";


	for( int k = l; k <= r; k++ ) {

		if(aux[j] < aux[i]) { 

			arr[k] = aux[j--]; 
		}
		else 
			arr[k] = aux[i++];

	}

	printArray(arr,l,r);

	cout << endl << endl << endl;

}



void iterative_merge_sort(int arr[], int l, int r) {


	cout << "Start Vector: " << endl << endl;

	printArray(arr,l,r);

	cout << endl << endl;

	for( int m = 1;  m <= r-l; m = m+m) {

		for( int i = l; i <= r-m; i+= m+m) {

			merge(arr,i,i+m-1, min(i+m+m-1,r) );

		}
	}
}



	
int main () {



	int arr[] = {67, 14, 4, 12, 92, 34, 6, 27, 2 };
	
	
		
	iterative_merge_sort(arr, 0, 8);

	cout << endl << "Final Array:" << endl << endl;

	printArray(arr,0,8);

	cout << endl << endl;
	return 0;


}



			
