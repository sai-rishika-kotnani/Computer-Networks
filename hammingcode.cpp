#include <iostream>
#include <cmath>
using namespace std;
int calculateParity(int code[], int n, int pos) {
    int count = 0;
    for (int i = pos; i <= n; i += 2 * pos) {
        int j = 0;
while (j < pos && (i + j) <= n) {
    count += code[i + j];
    j++; 
}

    }
    return count % 2;
}
void encodeHammingCode(int data[], int m) {
    int r = 0;
    for (int r = 0; pow(2, r) < (m + r + 1); r++);
    int n = m + r;
    int code[n + 1];
    for (int i = 1, j = 0; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            code[i] = 0;
        } else {
            code[i] = data[j++]; 
        }
    }
    for (int i = 0; i < r; i++) {
        int pos = (int)pow(2, i);
        code[pos] = calculateParity(code, n, pos);
    }
    cout << "Encoded data (Hamming Code): ";
    for (int i = 1; i <= n; i++) {
        cout << code[i] << " ";
    }
    cout << endl;
    cout << "Enter received data with possible error: ";
    int received[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> received[i];
    }
    int errorPos = 0;
    for (int i = 0; i < r; i++) {
        int pos = (int)pow(2, i);
        int parity = calculateParity(received, n, pos);
        errorPos += parity * pos;
    }
    if (errorPos == 0) {
        cout << "No error detected." << endl;
    } else {
        cout << "Error detected at position: " << errorPos << endl;
        received[errorPos] = (received[errorPos] == 0) ? 1 : 0;
        cout << "Corrected data: ";
        for (int i = 1; i <= n; i++) {
            cout << received[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    int m;
    cout << "Enter the number of data bits: ";
    cin >> m;

    int data[m];
    cout << "Enter the data bits: ";
    for (int i = 0; i < m; i++) {
        cin >> data[i];
    }

    encodeHammingCode(data, m);

    return 0;
}

