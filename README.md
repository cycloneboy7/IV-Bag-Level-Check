# 💉 IoT Based IV Bag Monitoring System

An IoT-based IV (Intravenous) Bag Monitoring System built using an ESP32, HX711 load cell amplifier, and a load cell to measure the remaining fluid in an IV bag. The system displays the remaining volume and percentage on a 20x4 LCD and hosts a live web dashboard that can be accessed from any device connected to the same Wi-Fi network.

This project helps reduce the need for manual IV bag checking by providing real-time monitoring through a simple web interface.

---

## ✨ Features

- 📏 Real-time IV bag level measurement
- 🌐 Built-in web dashboard (no Blynk required)
- 📱 Accessible from any phone or PC on the same Wi-Fi
- 📺 20x4 I2C LCD display
- ⚖️ HX711 + Load Cell for accurate weight measurement
- 🔄 Auto-refreshing webpage
- 💻 Serial Monitor debugging
- 💰 Completely free (no cloud subscription)

---
<!--
## 📸 Project Preview

### LCD Display

```
IOT Based IV Bag
Monitoring System

IV Bottle = 420 mL
IV Bag Percent = 83%
```

### Web Dashboard

```
-----------------------------
      IV Bag Monitoring

Remaining Volume
420 mL

Remaining
83%

Status:
🟢 NORMAL
-----------------------------
```

---

## 🛠 Components Required

| Component | Quantity |
|-----------|----------|
| ESP32 Development Board | 1 |
| HX711 Load Cell Amplifier | 1 |
| Load Cell (500g/1kg) | 1 |
| 20x4 I2C LCD | 1 |
| Jumper Wires | Several |
| Breadboard | Optional |
| USB Cable | 1 |

---

## 🔌 Circuit Connections

### HX711 → ESP32

| HX711 | ESP32 |
|--------|--------|
| VCC | 3.3V |
| GND | GND |
| DT | GPIO 23 |
| SCK | GPIO 19 |

### I2C LCD → ESP32

| LCD | ESP32 |
|-----|--------|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---
-->
## 📚 Libraries Used

Install these libraries from the Arduino Library Manager.

- WiFi
- WebServer
- LiquidCrystal_I2C
- HX711

---

## ⚙️ Installation

### 1. Clone the repository

```bash
git clone https://github.com/yourusername/iv-bag-monitor.git
```

---

### 2. Open in Arduino IDE

Open the `.ino` file.

---

### 3. Install ESP32 Board

Arduino IDE

```
Boards Manager
↓
ESP32 by Espressif Systems
```

---

### 4. Install Required Libraries

Go to

```
Sketch
↓
Include Library
↓
Manage Libraries
```

Install

- HX711
- LiquidCrystal_I2C

---

### 5. Enter Wi-Fi Credentials

Replace:

```cpp
char ssid[] = "YOUR_WIFI";
char pass[] = "YOUR_PASSWORD";
```

with your own Wi-Fi name and password.

---

### 6. Upload

Select

```
ESP32 Dev Module
```

Upload the sketch.

---

## 🌐 Accessing the Dashboard

After uploading, open the Serial Monitor.

You'll see something similar to:

```
Connecting...
WiFi Connected!

IP Address:
192.168.1.105
```

Open your browser and visit

```
http://192.168.1.105
```

The webpage updates automatically every few seconds.

---

## 📊 How It Works

1. The load cell measures the weight of the IV bag.
2. HX711 converts the analog signal into digital values.
3. ESP32 calculates:
   - Remaining weight
   - Remaining volume (mL)
   - Remaining percentage
4. Data is displayed on:
   - LCD
   - Web Dashboard
5. The webpage refreshes automatically to show the latest readings.

---

## 📂 Project Structure

```
IV-Bag-Monitor/
│
├── IV_Bag_Monitor.ino
├── README.md
└── images/
    ├── lcd.jpg
    ├── dashboard.png
    └── circuit.png
```

---

## 📐 Calculation

```
Weight (kg)
      ↓
Convert to mL

Remaining mL
      ↓
Percentage Calculation

(Current mL / Maximum Capacity) × 100
```

Example:

```
Current Weight

0.42 kg
↓
420 mL
↓
83%
```

---

## 📷 Future Improvements

- Mobile application
- Firebase cloud integration
- Telegram notifications
- Email alerts
- Battery backup
- Patient database
- Nurse monitoring dashboard
- Multiple IV bag monitoring
- Data logging
- Historical graphs

---

## 🚀 Applications

- Hospitals
- Clinics
- Home healthcare
- Nursing education
- Biomedical engineering projects
- IoT learning
- Smart healthcare systems

---

## 🤝 Contributing

Contributions are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Open a Pull Request

---
<!--
## 📄 License

This project is licensed under the MIT License.

--->
---

## 👨‍💻 Author

Developed as an IoT project using ESP32 and HX711 for smart healthcare monitoring.

If you found this project useful, consider giving it a ⭐ on GitHub!