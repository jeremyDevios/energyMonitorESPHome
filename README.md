# energyMonitorESPHome


To generate a random 32-byte API encryption key in base64 for ESPHome, run this command in your terminal:

```sh
openssl rand -base64 32
```
Copy the output and use it as the value for api.encryption.key in your YAML file.


## How to
 
This code is part of an ESPHome project for energy monitoring.
 
To launch the project, use the following command:
 
```sh
esphome run energyMonitorESPHOME-esp32-2424s012.yaml
```

This command compiles the `energyMonitorESPHOME-esp32-2424s012.yaml` configuration and uploads it to your ESP32 device.

This command will compile and upload the configuration to your ESP32 device, enabling the energy monitoring features as defined in the YAML file.

## Project Overview

This project aims to visualize household energy consumption and solar energy production using two gauges. The interface is designed to be user-friendly and engaging, featuring animated robot eyes that express emotions based on energy usage:

- **High consumption:** The robot appears upset.
- **Low or negative consumption:** The robot looks extremely happy.

This visual feedback helps users quickly understand their energy usage patterns and encourages efficient energy consumption.

## Prototype

Below is a mockup of the application's interface:

![Prototype of the application](images/Mockup.jpg)