#pragma once
#include <string>
#include <iostream>

class Vehicle {
  protected:
    int id;
    std::string model;
    std::string type;

  public:
    Vehicle(int id_, const std::string& model_, const std::string& type_) : id(id_), model(model_), type(type_) {}
    virtual ~Vehicle() = default;
    virtual void print() const = 0;
};

class Car : public Vehicle {
  int max_passengers;

  public:
    Car(int id, const std::string& model, int passengers) : Vehicle(id, model, "Car"), max_passengers(passengers) {}

    void print() const override {
      std::cout << "ID: " << id << ", Model: " << model << ", Type: " << type << ", Max Passengers: " << max_passengers << std::endl;
    }
};

class Truck : public Vehicle {
  float max_load;

  public:
    Truck(int id, const std::string& model, float load) : Vehicle(id, model, "Truck"), max_load(load) {}

    void print() const override {
      std::cout << "ID: " << id << ", Model: " << model << ", Type: " << type << ", Max Load: " << max_load << " kg" << std::endl;
    }
};
