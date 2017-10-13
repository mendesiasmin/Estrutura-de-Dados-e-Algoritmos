#include <iostream>



using namespace std;


bool subsequence(int S[], int SL[], int n, int m) {

	int * a = SL;

	for(int i = 0; i <= m; i++) {

			if( *a == S[i] )
					++a;
	}

	if (a == SL+n)
		return true;
	else 
		return false;	

}	


int main () {


		int seqnormal[] = {2, 4, 2, 5, 8, 7, 10};
		int seqlinha[] = {1, 4, 1};

		bool seq = subsequence(seqnormal, seqlinha, 3, 7);

		if( seq ) {

			cout << "S' é subsequencia de S" << endl;

		} 
		else {
			cout << "S' não é subsquencia de S" << endl;

		}

		return 0;

}
			
