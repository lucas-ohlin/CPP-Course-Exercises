#pragma once
#include <array>
#include <memory>
#include <mutex>
#include <condition_variable>

#ifndef VEHICLE_WAREHOUSE_CAPACITY
#define VEHICLE_WAREHOUSE_CAPACITY 10
#endif

class Warehouse {
  std::array<std::unique_ptr<Vehicle>, VEHICLE_WAREHOUSE_CAPACITY> buffer;
  size_t head = 0;
  size_t tail = 0;
  size_t count = 0;

  std::mutex mtx;
  std::condition_variable not_full;
  std::condition_variable not_empty;

  public:
    Warehouse() = default;
    Warehouse(const Warehouse&) = delete;
    Warehouse& operator=(const Warehouse&) = delete;

    void put(std::unique_ptr<Vehicle> vehicle) {
      std::unique_lock<std::mutex> lock(mtx);
      not_full.wait(lock, [this]() { return count < VEHICLE_WAREHOUSE_CAPACITY; });

      buffer[tail] = std::move(vehicle);
      tail = (tail + 1) % VEHICLE_WAREHOUSE_CAPACITY;
      ++count;

      not_empty.notify_one();
    }

    std::unique_ptr<Vehicle> get() {
      std::unique_lock<std::mutex> lock(mtx);
      not_empty.wait(lock, [this]() { return count > 0; });

      auto vehicle = std::move(buffer[head]);
      head = (head + 1) % VEHICLE_WAREHOUSE_CAPACITY;
      --count;

      not_full.notify_one();
      return vehicle;
    }
};
