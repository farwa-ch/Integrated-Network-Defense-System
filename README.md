# Integrated-Network-Defense-System
C++ Simulation of an Integrated Intrusion Detection and Firewall System for Network Security Research

## Overview

This project implements a **lightweight network defense system** combining:

- **Intrusion Detection System (IDS)** → Detects DDoS and Port Scanning attacks  
- **Firewall Engine** → Blocks malicious traffic automatically  
- **Logging and Evaluation** → Records blocked packets and summarizes system performance

The system is implemented entirely in **C++** using object-oriented design.

---

## Features

- Threshold-based detection for DDoS and Port Scan
- Rule-based firewall for IP and port blocking
- Logging of security events in `security_log.txt`
- Evaluation summary of allowed vs blocked traffic
- Easily extensible for research purposes

---

## System Architecture
Incoming Traffic
↓
Packet Class (IP + Port)
↓
IDS Engine
↓ ↓
DDoS Check Port Scan Check
↓
If Malicious → Add IP to Firewall Block List
↓
Firewall Engine
↓
Allow / Block Decision
↓
Logging + Evaluation Summary


---

## Example Simulation



Integrated Network Defense System Started

DDoS Detected from: 192.168.1.10
Port Scan Detected from: 10.0.0.5
Firewall Blocked: 192.168.1.10:80
Firewall Blocked: 10.0.0.5:21
Allowed: 172.16.0.3:80

System Evaluation Completed.


---

## How it Works

1. Each network packet is represented as a `Packet` object.
2. IDS Engine checks packet behavior:
   - DDoS: Packet count > 5
   - Port Scan: Ports accessed > 3
3. Malicious IPs are added to Firewall blocklist.
4. Firewall Engine blocks malicious IPs and restricted ports.
5. Logs alerts and summarizes system performance.

---

## Research Contributions

- Demonstrates **integrated detection and prevention**  
- Implements **threshold-based anomaly detection**  
- Provides **clear evaluation metrics**  
- Serves as a **foundation for advanced research in cybersecurity**

---

## Future Work

- Real-time traffic integration  
- Dynamic firewall rules  
- AI-assisted anomaly detection  
- Stateful inspection  
- Multi-threaded processing

---

## Technologies

- C++ (Object-Oriented Programming)  
- File Handling  


