#include <bits/stdc++.h>
#define cd complex<double>

using namespace std;

const complex<double> i(0, 1);
const double PI = acos(-1);

void fft(vector<cd>& seq, bool invert=false){ // sequence size should eb a power of two 
    int N = seq.size();
    if (N == 1) return;
    vector<cd> e(N/2), o(N/2);
    for (int i = 0; i<N; i++){
        if (i%2) o[i/2] = seq[i];
        else e[i/2] = seq[i];
    }
    fft(e, invert); fft(o, invert);
    double ang = 2 * PI / N * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int k = 0; k < N/2; k++){
        seq[k] = e[k] + o[k] * w;
        seq[k + N/2] = e[k] - o[k] * w;
        if (invert){
            seq[k] /=2;
            seq[k+N/2] /=2;
        }
        w*=wn;
    }
}

template <typename T> 
void printarr(vector<T>& arr){
    for(int i =0; i < arr.size();i++) cout << arr[i] << ' ';
    cout << endl;
}


int smallestpow(int lb){
    return 1<<(int)ceil(log2(lb));
}

int N, M;
vector<cd> seq1, seq2;
int main() {
    cin >> N >> M;
    int s =smallestpow(N+M);
    seq1.resize(s); seq2.resize(s);
    for (int i =0; i<N; i++){
        cd a; cin >> a; seq1[i] = a;
    }
    for (int i = 0; i < M;i++){
        cd a; cin >> a; seq2[M-1-i] = a;
    }
    fft(seq1, false);
    fft(seq2, false);
    // convolve
    vector<cd> c(s);
    for (int i= 0; i< s; i++) c[i]= seq1[i]*seq2[i];
    //inverse
    fft(c,true);
    for (int i = 0;i< N+M-1; i++) cout << (int)round(c[i].real()) << ' ';
    cout << endl;
}