#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <bitset>
using std::cout;
using std::cin;
using namespace std;

int value_in_time(int w, int t, int time) {
    return w * (time - t);
}
string value_of_number(int x) {
    string binary = std::bitset<20>(x).to_string();
    int y = 65;
    string result = "";
    string k = "";
    for (int i = binary.size()-1; i >= 0; i--) {
        if (binary[i] == '1') {
            k = (char)y;
            result += k;
        }
        y++;
    }
    return(result);
}
int int_of_string(string s) {
    int result = 0;
    int h;
    for (int i = 0;i < s.size(); i++) {
        h = (int)s[i]-64;
        result += 2 ^ h;
    }
    return result;
}
int algorithm(int P[], int W[], int T[], int N) {
    int a = pow(2,N);
    int * R;
    int c;
    R = new int[a];
    R[0]=0;
    int t = 0;
    int h = 10000;
    string z = "";
    string act = "";
    for (int i = 1; i < a;i++) {
        z = value_of_number(i);
        for (int j = 0; j < z.size(); j++) {
            act = z[j];
            t = int_of_string(z) - int_of_string(act) + value_in_time();
            c = value_in_time(W[j],T[j],)
        }
    }
}

int main()
{
    /*auto start = chrono::high_resolution_clock::now();
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
    cout << fixed << time_taken << setprecision(9) << " seconds";*/
    int x;
    cin >> x;
    cout << value_of_number(x);
    return 0;
}
