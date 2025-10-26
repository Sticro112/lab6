#include <array>
#include <iostream>
#include <string>
#include <receiver.h>


void Radioreceiver::input() {
        for (size_t i = 0; i < receivers.size(); ++i) {
            std::cout << "\n Enter data for receiver " << i + 1 << std::endl;

            std::cout << "Working frequency: ";
            std::cin >> receivers[i].working_frequency;

            std::cout << " Sensitivity: ";
            std::cin >> receivers[i].sensitivity;

            std::cout << " Type of modulation: ";
            std::cin >> receivers[i].modulation_type;

            if (!validate(receivers[i].working_frequency,
                          receivers[i].sensitivity,
                          receivers[i].modulation_type)) {
                error();
        
                receivers[i].working_frequency = 404.0;
                receivers[i].sensitivity = 404.0;
                receivers[i].modulation_type = "ERROR";
            }
        }
    }

    void Radioreceiver::display() {
        for (const auto& r : receivers) {
            std::cout << "Working frequency: " << r.working_frequency
                      << " Sensitivity: " << r.sensitivity
                      << " Modulation: " << r.modulation_type << std::endl;
        }
    }