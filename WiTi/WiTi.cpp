#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <bitset>
using std::cout;
using std::cin;
using namespace std;

int value_in_time(int w, int t, int time) {
    if (time <= t) {
        return 0;
    }
    else {
        return (w * (time - t));
    }
}
string value_of_number(int x) {

    string binary = std::bitset<20>(x).to_string();
    int y = 65;
    string result = "";
    string k = "";
    for (int i = binary.length()-1; i >= 0; i--) {
        if (binary[i] == '1') {
            k = (char)y;
            result += k;
        }
        y++;
    }

    return(result);
}
int get_time(int *P, string s) {

    int result = 0;
    for (int i = 0; i < s.size();i++) {
        result += P[(int)s[i] - 65];
    }

    return result;
}
int value_of_string(string s) {
    int result = 0;
    int h;
    for (int i = 0;i < s.size(); i++) {
        h = (int)s[i]-65;
        result += pow(2,h);
    }

    return result;
}
int algorithm(int *P, int *W, int *T, int N) {
    int a = pow(2,N);
    int * R;
    int c;
    R = new int[a];
    R[0]=0;
    int f = 0;
    int h;
    int x;
    string z = "";
    string act = "";
    for (int i = 1; i < a; i++) {
        h = 99999999;
        z = value_of_number(i);
        c = get_time(P, z);
        for (int j = 0; j < z.size(); j++) {
            act = z[j];
            x = (int)act[0] - 65;
            f = R[value_of_string(z) - value_of_string(act)] + value_in_time(W[x], T[x], c);
            h = min(f, h);
            
        }
      
        R[i] = h;
    }
    return R[a - 1];
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    int fmin, N, P[100], W[100], T[100];
    ifstream f("data.txt");
    string s;
    string data[11] = {"data.10:", "data.11:", "data.12:", "data.13:","data.14:", "data.15:", "data.16:", "data.17:",
    "data.18:", "data.19:", "data.20:"};
    for (int k = 0;k < 11;k++) {
        cout << data[k] << endl;
        while (s != data[k]) {
            f >> s;
        }
        f >> N;
        for (int i = 0;i < N;i++) {
            f >> P[i] >> W[i] >> T[i];
            //cout << P[i] << " " << W[i] << " " << T[i] << endl;

        }
        //cout << N << endl;

        fmin = algorithm(P, W, T, N);
        cout << "Minimalna kara problemu: " << fmin << endl;
    }
    f.close();
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;
    cout << fixed << time_taken << setprecision(9) << " seconds";
    return 0;
}
