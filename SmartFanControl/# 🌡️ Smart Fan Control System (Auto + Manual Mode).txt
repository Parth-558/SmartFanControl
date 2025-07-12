# 🌬️ Smart Fan Control System (Auto + Manual Mode)

An Arduino-based smart fan controller that adjusts fan speed based on temperature, with an optional manual override via a pushbutton. Simulates real-world HVAC logic using PWM, analog sensors, and embedded C.

---

## 📷 Project Preview

![Circuit Diagram](https://raw.githubusercontent.com/Parth-558/SmartFanControl/main/circuit.png)

---

## 🧠 Features

- 🌡️ **Auto Mode:** Adjusts fan speed based on temperature (25°C–40°C)
- 🔘 **Manual Mode:** Toggle fan ON/OFF with a button
- 💡 **LED indicator** shows fan state when in manual mode
- 💾 **Debouncing logic** using `millis()` for clean button presses
- 🔧 **Industry-level design**, like automotive or HVAC control systems

---

## 🔗 Components Used

| Component         | Quantity |
|------------------|----------|
| Arduino UNO       | 1        |
| TMP36 Temperature Sensor | 1 |
| Push Button        | 1        |
| LED (simulate fan) | 1        |
| 220 Ω Resistors    | 2        |
| Breadboard & Wires | As needed |

See full details in [`bom.csv`](./bom.csv).

---

## 📁 Files Included

- `SmartFanControl.ino` – Arduino sketch (main code)  
- `circuit.png` – Circuit diagram screenshot (Tinkercad)  
- `bom.csv` – Bill of materials  
- `report.pdf` – Optional detailed project report  
- *(optionally)* `extras/` – folder to hold `simulation_link.txt`, wiring notes, etc.

---

## 🧪 How It Works

1. **Auto Mode (Default):** Reads temperature via TMP36. Uses `map()` + `constrain()` to set PWM speed via `analogWrite()`.
2. **Manual Mode:** Button toggles between ON/OFF states, controlled via global `fanState` variable. LED reflects current state.
3. **Debouncing Logic:** Uses `millis()` and `static bool` for reliable button press detection.

---

## 🚀 Potential Applications

- Industrial ventilation systems  
- Smart room or server cooling  
- HVAC prototypes in education or internships  
- Embedded systems portfolio showcase

---

## 🛠️ Built With

- Arduino Uno  
- Embedded C / Arduino IDE  
- Tinkercad for circuit design

---

## 🤝 Author

**Parth Pawar**  
Cheering on embedded systems innovation and learning!

---

## 📚 License

Open-source for learning, academic projects, and personal growth.

