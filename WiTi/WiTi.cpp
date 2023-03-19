#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
using std::cout;
using std::cin;
using namespace std;

int value_in_time(int W, int T, int time) {
    return W * (time - T);
}
int algorithm(int P[], int W[], int T[], int N) {
    int a = N;
    int R[pow(2,a)];
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    int sumOfC, m, C, N, P[100], W[100], T[100], * X;
    ifstream f("data.txt");
    string s;
    string data[11] = { "data.10:", "data.11:", "data.12:", "data.13:","data.14:", "data.15:", "data.16:", "data.17:",
    "data.18:", "data.19:", "data.20:"};
    for (int k = 0;k < 11;k++) {
        cout << data[k] << endl;
        while (s != data[k]) {
            f >> s;
        }
        f >> N;
        for (int i = 0;i < N;i++) {
            f >> P[i] >> W[i] >> T[i];
            cout << P[i] << " " << W[i] << " " << T[i] << endl;

        }
        cout << N << endl;
    }
    f.close();
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;
    cout << fixed << time_taken << setprecision(9) << " seconds";
    return 0;
}
