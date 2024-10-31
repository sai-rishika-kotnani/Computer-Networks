#include <iostream>

using namespace std;

const int MAX_FRAMES = 10; 
void sender() {
    for (int frame = 0; frame < MAX_FRAMES; frame++) {
        cout << "Sender: Sending frame " << frame << endl;
        cout << "Sender: Waiting for ACK for frame " << frame << endl;
        char ack;
        cout << "Enter '1' if ACK for frame " << frame << " is received, otherwise enter '0': ";
        cin >> ack;

        if (ack == '1') {
            cout << "Sender: ACK for frame " << frame << " received.\n";
        } else {
            cout << "Sender: ACK for frame " << frame << " not received. Resending...\n";
            frame--;
        }
    }
}
void receiver() {
    for (int frame = 0; frame < MAX_FRAMES; frame++) {
        cout << "Receiver: Received frame " << frame << endl;
        cout << "Receiver: Sending ACK for frame " << frame << endl;
    }
}
int main() {
    cout << "1-Bit Stop and Wait Protocol Simulation" << endl;
    receiver(); 
    sender();  

    cout << "Transmission complete." << endl;
    return 0;
}
