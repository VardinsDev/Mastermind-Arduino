# 🎨 Mastermind — Arduino Color Sequence Game

A simple color-sequence memory game built with an Arduino Uno R4 WiFi, an RGB LED, and 5 buttons. Choose a sequence of 4 colors, hit submit after each one, and watch the LED play it back.

> 🔗 [View the Wokwi Circuit](https://wokwi.com/projects/459261699090708481)

---

## How It Works

1. Press any of the 4 **color buttons** to select a color — the RGB LED lights up to confirm your choice
2. Press the **submit button** to lock that color into the sequence
3. Repeat until you've submitted 4 colors
4. The LED automatically plays back your full sequence with a brief pause between each color

---

## Hardware

| Component | Quantity |
|-----------|----------|
| Arduino Uno R4 WiFi | 1 |
| Breadboard | 1 |
| RGB LED (common cathode) | 1 |
| 220Ω resistor | 3 |
| Tactile push button | 5 |

---

## Wiring

### RGB LED

| LED Pin | Arduino Pin |
|---------|-------------|
| R | 9 (PWM) |
| G | 10 (PWM) |
| B | 11 (PWM) |
| COM (GND) | GND |

Each RGB pin connects through a **220Ω resistor** to its Arduino pin.

### Buttons

All buttons are wired with the internal pull-up resistor enabled (`INPUT_PULLUP`). Connect one leg to the Arduino pin and the other to **GND**.

| Button | Arduino Pin |
|--------|-------------|
| Red | 3 |
| Green | 4 |
| Blue | 5 |
| Yellow | 6 |
| Submit | 7 |

---

## Pin Map

```
Arduino Uno R4 WiFi
├── D3  → Red button
├── D4  → Green button
├── D5  → Blue button
├── D6  → Yellow button
├── D7  → Submit button
├── D9  → RGB Red   (via 220Ω)
├── D10 → RGB Green (via 220Ω)
├── D11 → RGB Blue  (via 220Ω)
└── GND → RGB COM + all button grounds
```

---

## Building & Uploading

This project uses [PlatformIO](https://platformio.org/).

```bash
# Build
pio run

# Upload
pio run -t upload -e uno_r4_wifi
```

Or open the project in VS Code with the PlatformIO extension and click **Upload**.

> **Linux users:** If you get a `Permission denied` on `/dev/ttyACM0`, run:
> ```bash
> sudo usermod -a -G dialout $USER
> ```
> Then log out and back in.

---

## Project Structure

```
├── src/
│   └── main.cpp
├── platformio.ini
└── README.md
```

---

## Future Ideas

- [ ] Simon Says mode — Arduino generates a random sequence for the player to repeat
- [ ] Win/lose feedback with `tone()` buzzer
- [ ] Increasing difficulty — longer sequences each round
- [ ] High score saved to EEPROM
- [ ] LCD display for score and round counter
