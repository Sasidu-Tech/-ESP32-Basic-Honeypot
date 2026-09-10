#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "Infinix HOT 40 Pro";
const char* password = "12345678";

//HTTPweb-server port
WebServer server(80);

const char* htmlPage = R"rawliteral(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">

    <title>ESP32 Honeypot</title>

    <style>
        body {
            margin: 0;
            font-family: Arial, sans-serif;
            background: #0f172a;
            color: white;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
        }

        .container {
            width: 90%;
            max-width: 500px;
            text-align: center;
        }

        .card {
            background: #1e293b;
            padding: 35px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0,0,0,0.4);
        }

        .icon {
            font-size: 50px;
        }

        h1 {
            margin-bottom: 10px;
        }

        .warning {
            color: #facc15;
            font-size: 18px;
            margin: 20px 0;
        }

        .status {
            display: inline-block;
            background: #166534;
            color: #bbf7d0;
            padding: 10px 20px;
            border-radius: 20px;
            font-weight: bold;
        }

        .info {
            margin-top: 25px;
            color: #94a3b8;
            font-size: 14px;
        }
    </style>
</head>

<body>

    <div class="container">

        <div class="card">

            <div class="icon">🍯</div>

            <h1>ESP32 HONEYPOT</h1>

            <div class="warning">
                ⚠️ This is a monitored device
            </div>

            <div class="status">
                ● Status: ONLINE
            </div>

            <div class="info">
                ESP32 Basic Honeypot Security System
            </div>

        </div>

    </div>

</body>
</html>
)rawliteral";

int requestCount = 0;

void handleRoot() {

    requestCount++ ;


    Serial.println();
    Serial.println("----------------------------------------------------------------------------------------");
    Serial.println("                               HONEYPOT ACTIVITY");
    Serial.println("----------------------------------------------------------------------------------------");

    Serial.print("Request # : ");
    Serial.println( requestCount);

    Serial.print("Client IP :");
    Serial.println(server.client().remoteIP());

    Serial.println("Method  : GET");
    Serial.println("Parth   : /");

    Serial.println("Status  : 🚨 ALERT");

    Serial.println("----------------------------------------------------------------------------------------");

    server.send(200, "text/html", htmlPage);
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  WiFi.mode(WIFI_STA);

  Serial.print("Connecting to Wi-Fi");

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("Wi-Fi is Connected!");

  server.on("/",handleRoot);
  server.begin();
  Serial.println();
  Serial.println("Honeypot Web Server Started!");

  Serial.println("");
  Serial.print("ESP32 IP Address : ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

  server.handleClient();

}

