#include <iostream>
#include <vector>
#include <algorithm>

class SensorObserver {
public:
    virtual void update() = 0;
};

// Subject (ObservableTemperature) class
class SensingDevice {
private:
    float temperature;
    float pressure;
    std::vector<SensorObserver*> observers;

public:
    float getPressure() const {
        return pressure;
    }
    void setPressure(float newPressure) {
        pressure = newPressure;
        notifyObservers();
    }

    void setTemperature(float newTemperature) {
        temperature = newTemperature;
        notifyObservers();
    }

    float getTemperature() const {
        return temperature;
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
            observer->update();
        }
    }
};

// Concrete Observer (GasController) class
class GasController : public SensorObserver {
private:
    SensingDevice* sensor;
    double pressure;
public:
    GasController(SensingDevice* pressureSensor)
    {
        sensor = pressureSensor;
        pressureSensor->addObserver(this);
    }
    void update() override {
        pressure = sensor->getPressure();
        // Adjust gas levels based on temperature value
        // Your implementation here
        std::cout << "Gas Controller: Adjusting gas levels based on pressure " << pressure << std::endl;
    }
};

// Concrete Observer (VentilationController) class
class VentilationController : public SensorObserver {
private:
    SensingDevice* sensor;
    double temperature;
public:
    VentilationController(SensingDevice* temperatureSensor)
    {
        sensor = temperatureSensor;
        temperatureSensor->addObserver(this);
    }
    void update() override {
        temperature = sensor->getTemperature();
        // Activate ventilation system based on temperature value
        // Your implementation here
        std::cout << "Ventilation Controller: Activating ventilation system for temperature " << temperature << std::endl;
    }
};

// Concrete Observer (FireSuppressionController) class
class FireSuppressionController : public SensorObserver {
private:
    SensingDevice* sensor;
    double temperature;
public:
    FireSuppressionController(SensingDevice* temperatureSensor)
    {
        sensor = temperatureSensor;
        temperatureSensor->addObserver(this);
    }
    void update() override {
        temperature = sensor->getTemperature();

        // Trigger fire suppression system based on temperature value
        // Your implementation here
        std::cout << "Fire Suppression Controller: Triggering fire suppression system for temperature " << temperature << std::endl;
    }
};


// Concrete Observer (EmergencyShutdownController) class
class EmergencyShutdownController : public SensorObserver {
private:
    SensingDevice* sensor;
    double temperature;
public:
    EmergencyShutdownController(SensingDevice* temperatureSensor)
    {
        sensor = temperatureSensor;
        temperatureSensor->addObserver(this);
    }
    void update() override {
        temperature = sensor->getTemperature();
        // Initiate emergency shutdown based on temperature value
        // Your implementation here
        std::cout << "Emergency Shutdown Controller: Initiating emergency shutdown for temperature " << temperature << std::endl;
    }
};

int main() {
    // Create the subject (SensingDevice)
    SensingDevice sensor;
    // Create the observers (controllers)
    GasController gasController(&sensor);
    VentilationController ventilationController(&sensor);
    FireSuppressionController fireSuppressionController(&sensor);
    EmergencyShutdownController emergencyShutdownController(&sensor);


    // Simulate a temperature change
    float newTemperature = 25.5f;
    sensor.setTemperature(newTemperature);
    // Simulate a pressure change
    float newPressure = 12.5f;
    sensor.setPressure(newPressure);
    // Unregister an observer (e.g., GasController)
    sensor.removeObserver(&gasController);
    // Simulate another temperature change
    newTemperature = 30.0f;
    sensor.setTemperature(newTemperature);
    return 0;
}