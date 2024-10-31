#include <iostream>

using namespace std;

class SlidingWindow {
public:
    void startTransmission(int windowSize, int totalFrames) {
        int nextFrameToSend = 0;

        while (nextFrameToSend < totalFrames) {
            for (int i = 0; i < windowSize && nextFrameToSend < totalFrames; i++) {
                cout << "Sender: Sending frame " << nextFrameToSend << endl;
                nextFrameToSend++;
            }
            cout << "Sender: Waiting for ACKs...\n";
            for (int i = 0; i < windowSize && (nextFrameToSend - i - 1) >= 0; i++) {
                int ackReceived;
                cout << "Enter ACK for frame " << (nextFrameToSend - i - 1) << " (1 = received, 0 = not received): ";
                cin >> ackReceived;
                if (ackReceived == 1) {
                    cout << "Sender: ACK for frame " << (nextFrameToSend - i - 1) << " received.\n";
                } else {
                    cout << "Sender: ACK for frame " << (nextFrameToSend - i - 1) << " not received. Resending...\n";
                    nextFrameToSend -= (i + 1); 
                    break; 
                }
            }
        }
        cout << "Transmission complete.\n";
    }
};

int main() {
    int windowSize, totalFrames;

    cout << "N-bit Sliding Window Protocol Simulation\n";
    cout << "Enter the size of the sliding window: ";
    cin >> windowSize;
    cout << "Enter the total number of frames to be sent: ";
    cin >> totalFrames;

    SlidingWindow window;
    window.startTransmission(windowSize, totalFrames);

    return 0;
}
