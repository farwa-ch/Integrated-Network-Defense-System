#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Packet {
public:
    string ip;
    int port;

    Packet(string ipAddress, int portNumber) {
        ip = ipAddress;
        port = portNumber;
    }
};

class Firewall {
private:
    string blockedIPs[10];
    int blockedIPCount = 0;

public:
    void addBlockedIP(string ip) {
        blockedIPs[blockedIPCount] = ip;
        blockedIPCount++;
    }

    bool isBlocked(string ip) {
        for (int i = 0; i < blockedIPCount; i++) {
            if (blockedIPs[i] == ip)
                return true;
        }
        return false;
    }
};


class IDS {
private:
    string ipList[10];
    int packetCount[10];
    int portCount[10];
    int ipCount = 0;

    Firewall* firewall;

public:
    IDS(Firewall* fw) {
        firewall = fw;
    }

    void analyze(Packet p) {
        int index = -1;

        for (int i = 0; i < ipCount; i++) {
            if (ipList[i] == p.ip) {
                index = i;
                break;
            }
        }

    
        if (index == -1) {
            ipList[ipCount] = p.ip;
            packetCount[ipCount] = 1;
            portCount[ipCount] = 1;
            index = ipCount;
            ipCount++;
        }
        else {
            packetCount[index]++;
            portCount[index]++;
        }

        if (packetCount[index] > 5) {
            cout << "DDoS Detected from: " << p.ip << endl;
            firewall->addBlockedIP(p.ip);
            packetCount[index] = 0;
        }

        if (portCount[index] > 3) {
            cout << "Port Scan Detected from: " << p.ip << endl;
            firewall->addBlockedIP(p.ip);
            portCount[index] = 0;
        }
    }
};

int main() {

    Firewall firewall;
    IDS ids(&firewall);

    cout << "Integrated Network Defense System Started\n\n";

    Packet traffic[] = {
        Packet("192.168.1.10", 80),
        Packet("192.168.1.10", 80),
        Packet("192.168.1.10", 80),
        Packet("192.168.1.10", 80),
        Packet("192.168.1.10", 80),
        Packet("192.168.1.10", 80),  

        Packet("10.0.0.5", 21),
        Packet("10.0.0.5", 22),
        Packet("10.0.0.5", 23),
        Packet("10.0.0.5", 24),     

        Packet("172.16.0.3", 80)
    };

    int total = sizeof(traffic) / sizeof(traffic[0]);

    for (int i = 0; i < total; i++) {

        ids.analyze(traffic[i]);

        if (firewall.isBlocked(traffic[i].ip)) {
            cout << "Firewall Blocked: "
                 << traffic[i].ip << ":" << traffic[i].port << endl;

            ofstream log("security_log.txt", ios::app);
            log << "Blocked: "
                << traffic[i].ip << ":" << traffic[i].port << endl;
            log.close();
        }
        else {
            cout << "Allowed: "
                 << traffic[i].ip << ":" << traffic[i].port << endl;
        }
    }

    cout << "\nSystem Evaluation Completed.\n";

    return 0;
}
