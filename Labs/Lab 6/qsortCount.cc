#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;

int comps = 0;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}


int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

float c(int n) {
    if (n <= 1) return 0;
    float sum = 0.0;
    for (int m=1; m <= n; m++)
        sum += n-1 + c(m-1) + c(n-m);
    return sum / n;
}

int qc(int n){
    if (n <= 1){
        return 0;
    }
    int p = randint(0,n);
    return (n - 1) + qc(p) + qc(n - 1 - p);
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		if (x[i] < x[a])
			swap(x[++m], x[i]);
        comps++;
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

#define NN 1000

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;
    printf("comps=%d\n",comps);
    printf("%d\n",qc(NN));

	delete[] x;
	return 0;
}

