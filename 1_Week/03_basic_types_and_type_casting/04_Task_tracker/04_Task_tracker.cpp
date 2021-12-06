#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    int N = 10000;
    int sum = 0;
    auto start = chrono::steady_clock::now();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                sum += k;
            }
        }
    }
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "The time is = " << elapsed_ms.count() << endl;
    cout << sum << endl;
}