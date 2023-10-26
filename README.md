# Greenhouse Monitoring System

## Project Structure
```
GREENHOUSE-IOT/
│
├── dht.h                    # Header file for the DHT11 sensor
├── GREENHOUSE-IOT.ino        # Main Arduino sketch for monitoring
├── http.h                   # Header file includes an server and request routes
├── ph.h                     # Header file for the pH sensor
├── wifi.h                   # Header file for Wi-Fi setup
```

## Sensor Information

### DHT Sensor (Temperature and Humidity)
The DHT sensor is used to measure temperature and humidity in the greenhouse.

- **Initialization:**
  - The `initSensor()` function initializes the DHT sensor on GPIO pin D2 (defined as `GPIO_PIN`).

- **Temperature Reading:**
  - The `getTemperature()` function retrieves the temperature value in degrees Celsius from the DHT sensor.

- **Humidity Reading:**
  - The `getHumidity()` function retrieves the relative humidity as a percentage from the DHT sensor.

### pH Sensor
The pH sensor measures the pH level of the greenhouse environment.

- **pH Reading:**
  - The `readPhValue(int gpio)` function calculates the pH value based on the analog reading from the specified GPIO pin (defined as `SENSOR_GPIO`).
  - It reads the analog value, converts it to a voltage, and calculates the pH value based on a formula.

## Wi-Fi Setup
The Wi-Fi credentials for the ESP8266 are defined in the `wifi.h` file. The system creates a soft access point (AP) with the SSID "GreenHouse-IOT" and the password "12345678."

## HTTP Server
An HTTP server is set up on the ESP8266 to handle client requests.

- **Port Configuration:**
  - The server listens on port 80 (defined as `HTTP_PORT`).

- **Request Handling:**
  - The server responds to the following endpoints:
    - `/id`: Returns the sensor's identification string.
    - `/data`: Returns data from the pH sensor, temperature, and humidity.
    - `/reset`: Restarts the ESP8266 MCU.
    - Any other requests result in a "Not Found" response.

- **Server Initialization:**
  - The `startupServer()` function initializes the server, sets up the sensor, and configures the request handlers.

- **Request Handling:**
  - The `handleClientRequest()` function continuously handles incoming client requests.

## Setup and Usage
1. Load the `GREENHOUSE-IOT.ino` sketch onto your ESP8266 microcontroller using the Arduino IDE or a compatible programming environment.

2. Ensure that you have the necessary libraries for the DHT sensor and the ESP8266.

3. Configure the Wi-Fi credentials in the `wifi.h` file.

4. Flash the ESP8266 with the sketch. It will create a soft access point and serve sensor data via HTTP endpoints.

5. Access the data using the following endpoints:
   - `/id`: Obtain the simple sensor id.
   - `/data`: Retrieve data from the pH sensor, temperature, and humidity.
   - `/reset`: Restart the ESP8266.

## Notes
- The project provides a basic demonstration of greenhouse monitoring. In practice, you would use actual sensor data for accurate greenhouse environmental monitoring.

- The system can be extended to incorporate other sensors, data logging, and visualization for more comprehensive greenhouse monitoring.
