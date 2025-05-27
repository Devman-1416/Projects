// Devin Combs
// Nour Al Mahdi Ballout
//brenden bourgoise
// Car Program using chrono (simple version)

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <chrono>

class Car {
private:
    int year;
    std::string make;
    std::string model;
    float speed;
    float gallons;
    bool engine;
    std::chrono::steady_clock::time_point engineStartTime;

public:
    Car(int year, std::string make, std::string model) {
        this->year = year;
        this->make = make;
        this->model = model;
        this->speed = 0;
        this->gallons = 10;
        this->engine = false;
    }

    // Accessors
    int getYear() { return this->year; }
    std::string getMake() { return this->make; }
    std::string getModel() { return this->model; }
    float getSpeed() { return this->speed; }
    float getGallons() { return this->gallons; }
    bool getEngine() { return this->engine; }

    // Mutators
    void accelerate() {
        this->speed += 5;
        this->gallons -= 0.5;
        if (this->gallons < 0) this->gallons = 0;
    }

    void brake() {
        this->speed -= 5;
        if (this->speed < 0) this->speed = 0;
        this->gallons -= 0.2;
        if (this->gallons < 0) this->gallons = 0;
    }

    void fillUp() {
        this->gallons += 5;
        if (this->gallons > 22) this->gallons = 22;
    }

    void setEngine(bool on) {
        if (on == true && this->engine == false) {
            this->engineStartTime = std::chrono::steady_clock::now();
        }
        this->engine = on;
    }

    void updateFuelConsumption() {
        if (!this->engine || this->gallons <= 0) return;

        std::chrono::steady_clock::time_point nowTime;
        nowTime = std::chrono::steady_clock::now();

        std::chrono::milliseconds timePassed;
        timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - engineStartTime);

        int seconds = timePassed.count() / 1000;
        float fuelUsed = 0.05f * seconds;

        if (fuelUsed >= 0.05f) {
            this->gallons -= fuelUsed;
            if (this->gallons < 0) this->gallons = 0;
            this->engineStartTime = std::chrono::steady_clock::now(); // reset timer
        }
    }

    void display() {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\n--------------Car----------------";
        std::cout << "\nYear : " << this->year;
        std::cout << "\nMake : " << this->make;
        std::cout << "\nModel: " << this->model;
        std::cout << "\nSpeed: " << this->speed << " mph";
        std::cout << "\nTank : " << this->gallons << " gal";
        this->engine ? std::cout << "\nEngine On" : std::cout << "\nEngine Off";
    }
};

int main() {
    Car car(2015, "Dodge", "Journey");
    int choice;
    int turn = 1;

    while (true) {
        // Update fuel if engine is running
        car.updateFuelConsumption();

        std::cout << "\n-------------------- Turn: " << turn << " ------------------\n";
        car.display();
        std::cout << "\n----------- Menu --------------\n";
        std::cout << "Start Car    (1)\n";
        std::cout << "Turn off Car (2)\n";
        std::cout << "Add Gas      (3)\n";
        std::cout << "Accelerate   (4)\n";
        std::cout << "Deccelerate  (5)\nEnter: ";

        while (!(std::cin >> choice) || (choice < 1 || choice > 5)) {
            std::cout << "\nInvalid Menu Option! Enter a 1 - 5: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            if (car.getSpeed() == 0 && car.getGallons() > 0) {
                car.setEngine(true);
                std::cout << "\nEngine Turned On\n";
            } else {
                std::cout << "\nCar must be stopped and have gas to turn on!";
            }
            break;

        case 2:
            if (car.getSpeed() == 0) {
                car.setEngine(false);
                std::cout << "\nEngine Turned Off\n";
            } else {
                std::cout << "\nCar must be stopped to shut off!";
            }
            break;

        case 3:
            if (!car.getEngine()) {
                if (car.getSpeed() == 0) {
                    car.fillUp();
                    std::cout << "\nGas Added!";
                } else {
                    std::cout << "\nCar must be stopped to add gas!";
                }
            } else {
                std::cout << "\nEngine must be off! Safety first.";
            }
            break;

        case 4:
            if (car.getEngine()) {
                if (car.getGallons() > 0) {
                    car.accelerate();
                    std::cout << "\nAccelerating!";
                }
            } else {
                std::cout << "\nEngine is Off!";
            }

            if (car.getGallons() == 0) {
                std::cout << "\nOut of Gas!";
                car.setEngine(false);
            }
            break;

        case 5:
            if (car.getSpeed() != 0) {
                car.brake();
                std::cout << "\nBraking!";
            } else {
                std::cout << "\nCar is already stopped!";
            }
            break;
        }

        if (car.getGallons() == 0) {
            std::cout << "\nOut of Gas!";
            if (car.getSpeed() != 0) {
                car.brake();
                std::cout << "\nBraking!";
            } else {
                std::cout << "\nCar is Stopped";
            }
        }

        turn++;
        std::cout << "\n\n\n";
    }

    return 0;
}

