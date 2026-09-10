🍯 ESP32 Basic Honeypot


![ESP32 Network Status Monitor](images/esp32-network-monitor.png)

A simple cybersecurity project built with an ESP32 to demonstrate the basic concept of a Honeypot.

The ESP32 runs a fake HTTP web service that can detect and log incoming web requests. When a client accesses the honeypot, the system records the client's IP address, request information, and request count through the Serial Monitor.

---

🎯 Project Objective

The main objective of this project is to understand how a basic honeypot can be used to:

- Detect incoming HTTP requests
- Identify the client's IP address
- Monitor web access attempts
- Count incoming requests
- Generate basic security alerts
- Understand the fundamentals of network security monitoring

---

⚙️ Features

- 📡 Wi-Fi connectivity
- 🌐 ESP32 HTTP Web Server
- 🍯 Fake Honeypot Web Page
- 🚨 HTTP Request Detection
- 🌍 Client IP Address Detection
- 📊 Request Counter
- 📝 Serial Monitor Logging
- 🔐 Basic Security Alert

---

🧰 Hardware Requirements

Component| Quantity
ESP32 Dev Module| 1
USB Cable| 1
Wi-Fi Network / Mobile Hotspot| 1

No external sensors are required.

---

💻 Software & Libraries

- Arduino IDE
- ESP32 Board Package
- "WiFi.h"
- "WebServer.h"
- HTML
- CSS

---

🏗️ System Architecture

                 Wi-Fi Network
                      │
          ┌───────────┴───────────┐
          │                       │
       Client                  ESP32
     Phone / PC              Honeypot
          │                       │
          │ HTTP Request          │
          └──────────────────────►│
                                  │
                           Request Detection
                                  │
                     ┌────────────┴────────────┐
                     │                         │
                 Client IP                Request Count
                     │                         │
                     └────────────┬────────────┘
                                  │
                                  ▼
                           Serial Monitor

---

🔄 How It Works

1. ESP32 connects to the Wi-Fi network.
2. ESP32 starts an HTTP web server on port "80".
3. A client accesses the ESP32 IP address through a browser.
4. The honeypot detects the HTTP request.
5. The client's IP address is obtained.
6. The request count is increased.
7. The activity is displayed in the Serial Monitor.
8. The ESP32 returns the honeypot HTML page to the client.

---

🌐 Web Interface

The ESP32 hosts a simple security-themed web page:

🍯 ESP32 HONEYPOT

⚠️ This is a monitored device

● Status: ONLINE

The page is accessible using the ESP32's local IP address:

http://ESP32_IP_ADDRESS

Example:

http://192.168.1.100

---

🖥️ Serial Monitor Output

When a client accesses the honeypot:

================================
      HONEYPOT ACTIVITY
================================

Request #  : 1
Client IP  : 192.168.1.105
Method     : GET
Path       : /
Status     : ALERT

================================

If the client refreshes the page, the request counter increases:

Request #  : 2
Request #  : 3
Request #  : 4

---

📁 Project Structure

ESP32-Honeypot/
│
├── code
│     └── ESP32-Honeypot.ino
│     │──index.html
│     
├── demo
├── images
└── README.md

---

🚀 Installation & Setup

1. Clone the Repository

git clone https://github.com/Sasidu-Tech/ESP32-Honeypot.git

2. Open the Project

Open:

ESP32-Honeypot.ino

using Arduino IDE.

3. Configure Wi-Fi

Add your Wi-Fi credentials to the Arduino code:

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

4. Select ESP32 Board

In Arduino IDE:

Tools → Board → ESP32 → ESP32 Dev Module

5. Upload

Connect the ESP32 using USB and upload the program.

6. Open Serial Monitor

Set the baud rate according to the value used in the code, for example:

115200

7. Access the Honeypot

Find the ESP32 IP address in the Serial Monitor and open it in a browser:

http://ESP32_IP_ADDRESS

---

🧪 Testing

The project can be tested using:

- 📱 Smartphone
- 💻 Laptop
- 🖥️ Desktop PC

Connect the device to the same local network as the ESP32 and access the ESP32 IP address.

Each HTTP request should generate a log entry in the Serial Monitor.

---

📌 Project Series

This project is part of my ongoing ESP32 Cybersecurity Project Series.

01. ESP32 Wi-Fi Scanner                  ✅
02. ESP32 Network Status Monitor        ✅
03. ESP32 Unauthorized Device Detector  ✅
04. ESP32 Honeypot                       ✅
05. ESP32 Mini IDS                      🔜
06. Secure IoT Gateway                  🔜

---


🔐 Security Note

This project is designed for educational purposes and authorized lab environments.

It demonstrates basic honeypot and network-monitoring concepts. It is not intended to replace a professional intrusion detection or security monitoring system.

Only test devices and networks that you own or have explicit permission to monitor.

---

🔮 Future Improvements

Possible future versions could include:

- 📊 Web-based activity dashboard
- 💾 Request log storage
- 🚨 Advanced suspicious-request detection
- 📱 Security notifications
- 🛡️ Integration with an ESP32 Mini IDS
- 📈 Network activity statistics

---

👨‍💻 Author

Sasidu-Tech

BICT Student | Networking & Cyber Security Enthusiast

Interests

- 🌐 Computer Networking
- 🔐 Cyber Security
- 🐧 Linux
- 🐍 Python
- 📡 IoT & ESP32
- 🤖 Robotics

---

📜 License

This project is licensed under the MIT License.

Copyright © 2026 Sasidu-Tech
