#include <iostream>
#include <string>
using namespace std;
string XOR(string a, string b) {
    string result = "";
    for (int i = 1; i < b.length(); i++) {	
    	if (a[i] == b[i]) {
    result += '0';
} 
else {
    result += '1';
}
    }
    return result;
}
string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);
for (int pick = divisor.length(); pick < dividend.length(); pick++) {
    if (tmp[0] == '1') {
        tmp = XOR(divisor, tmp) + dividend[pick];
    } else {
        tmp = XOR(string(pick, '0'), tmp) + dividend[pick];
    }
}
    if (tmp[0] == '1') {
        tmp = XOR(divisor, tmp);
    } else {
        tmp = XOR(string(pick, '0'), tmp);
    }
    return tmp;
}

string encodeData(string data, string divisor) {
    int data_len = data.length();
    int divisor_len = divisor.length();
    string appended_data = data + string(divisor_len - 1, '0');
    string remainder = mod2div(appended_data, divisor);
    string codeword = data + remainder;
    return codeword;
}
bool checkForErrors(string codeword, string divisor) {
    string remainder = mod2div(codeword, divisor);
    return remainder.find('1') == string::npos; 
}
int main() {
    string data, divisor;
    cout << "Enter the data string (binary): ";
    cin >> data;
    cout << "Enter the divisor (binary): ";
    cin >> divisor;
    string codeword = encodeData(data, divisor);
    cout << "Encoded data (data + redundant bits): " << codeword << endl;
    bool isError = !checkForErrors(codeword, divisor);
    if (isError) {
        cout << "Error detected in the transmitted data." << endl;
    } else {
        cout << "No error detected in the transmitted data." << endl;
    }
    return 0;
}
