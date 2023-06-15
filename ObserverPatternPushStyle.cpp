#include <iostream>
#include <vector>
#include <algorithm>

class SensorObserver {
public:
    virtual void updateTemperature(float temperature) = 0;
};

// Subject (ObservableTemperature) class
class SensingDevice {
private:
    float temperature;
    std::vector<SensorObserver*> observers;

public:
    void setTemperature(float newTemperature) {
        temperature = newTemperature;
        notifyObservers();
    }

    void addObserver(SensorObserver* observer) {
        observers.push_back(observer);
    }

    void removeObserver(SensorObserver* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers() {
        for (auto observer : observers) {
            observer->updateTemperature(temperature);
        }
    }
};

// Concrete Observer (GasController) class
class GasController : public SensorObserver {
public:
    void updateTemperature(float temperature) override {
        // Adjust gas levels based on temperature value
        // Your implementation here
        std::cout << "Gas Controller: Adjusting gas levels based on temperature " << temperature << std::endl;
    }
};

// Concrete Observer (VentilationController) class
class VentilationController : public SensorObserver {
public:
    void updateTemperature(float temperature) override {
        // Activate ventilation system based on temperature value
        // Your implementation here
        std::cout << "Ventilation Controller: Activating ventilation system for temperature " << temperature << std::endl;
    }
};

// Concrete Observer (FireSuppressionController) class
class FireSuppressionController : public SensorObserver {
public:
    void updateTemperature(float temperature) override {
        // Trigger fire suppression system based on temperature value
        // Your implementation here
        std::cout << "Fire Suppression Controller: Triggering fire suppression system for temperature " << temperature << std::endl;
    }
};

// Concrete Observer (EmergencyShutdownController) class
class EmergencyShutdownController : public SensorObserver {
public:
    void updateTemperature(float temperature) override {
        // Initiate emergency shutdown based on temperature value
        // Your implementation here
        std::cout << "Emergency Shutdown Controller: Initiating emergency shutdown for temperature " << temperature << std::endl;
    }
};

int main() {
    // Create the subject (SensingDevice)
    SensingDevice temperatureSensor;
    // Create the observers (controllers)
    GasController gasController;
    VentilationController ventilationController;
    FireSuppressionController fireSuppressionController;
    EmergencyShutdownController emergencyShutdownController;


    // Register the observers with the subject
    temperatureSensor.addObserver(&gasController);
    temperatureSensor.addObserver(&ventilationController);
    temperatureSensor.addObserver(&fireSuppressionController);
    temperatureSensor.addObserver(&emergencyShutdownController);

    // Simulate a temperature change
    float newTemperature = 25.5;
    temperatureSensor.setTemperature(newTemperature);
    // Unregister an observer (e.g., GasController)
 //   temperatureSensor.removeObserver(&gasController);
    // Simulate another temperature change
   // newTemperature = 30.0;
   // temperatureSensor.setTemperature(newTemperature);
    return 0;
}
