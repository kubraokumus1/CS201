#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {
    const int n = 40000000;
    const int k = 1000;
    int* input = new int[n];
    int* output = new int[k];
    for (int i = 0; i < n; ++i) {
        input[i] = rand();
    }
    double duration1;
    clock_t startTime1 = clock();

    solution1( input, n, k, output );

    duration1 = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration1 << " milliseconds." << endl;


    ////////////////////////////////////////////////////////////////////////////


    delete [] output;
    output = new int[k];

    double duration2;
    clock_t startTime2 = clock();

    solution2( input, n, k, output );

    duration2 = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration2 << " milliseconds." << endl;


    /////////////////////////////////////////////////////////////////////////////


    delete [] output;
    output = new int[k];

    double duration3;
    clock_t startTime3 = clock();

    solution3( input, n, k, output );

    duration3 = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration3 << " milliseconds." << endl;

    delete [] input;
    delete [] output;
    return 0;
}
