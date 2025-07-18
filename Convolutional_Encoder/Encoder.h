//
// Created by Esosa on 03/11/2023.
//

#ifndef ENCODER_H
#define ENCODER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "ShiftReg.h"
#include "FileHandler.h"


class Encoder {
public:
    Encoder(std::string InputString) {
        int requiredRegisters = 3;
        for (int x = 0; x < requiredRegisters; x++) {
            ShiftRegisters sf;
            sf.value = 0;
            shiftregisters.push_back(sf);
        }
        InputData_ = InputString;
        polynomials.push_back("111");
        polynomials.push_back("101");
        polynomials.push_back("110");
    }

    bool Encode() {
        for (int i = 0; i < InputData_.length(); i++) {
            ShiftReg(i);

            PrepareGroup();

            CalculateXOR();
        }
        return true;
    }

private:
    // Variables
    std::vector <ShiftRegisters> shiftregisters;
    std::vector <std::string> polynomials;
    std::vector <std::vector<ShiftRegisters>> registerGroups;
    std::string InputData_;
    std::vector <int> state_;

    // Function to calculate the XORs of the given shift registers
    void CalculateXOR() {
        for (int k = 0; k < registerGroups.size(); k++) {
            int xorResult = registerGroups[k][0].value;
            for (int l = 1; l < registerGroups[k].size(); l++) {
                xorResult ^= registerGroups[k][l].value;
            }
            std::cout << xorResult;
        }
        std::cout << " ";
    }

    void PrepareGroup() {
        registerGroups.clear();
        for (int i = 0; i < polynomials.size(); i++) {
            BuildRegisterGroups(polynomials[i], i);
        }
    }
    void ShiftReg(int i) {
        int InputValue = std::stoi(InputData_.substr(i, 1));
        for (int j = shiftregisters.size() - 1; j > 0; j--) {
            shiftregisters[j].value = shiftregisters[j - 1].value;
        }
        shiftregisters[0].value = InputValue;
    }

    void BuildRegisterGroups(std::string configReg, int i){
        registerGroups.push_back(std::vector<ShiftRegisters>());
        for (int j = 0; j < shiftregisters.size(); j++) {
            if (configReg.substr(j, 1) == "1") {
                registerGroups[i].push_back(shiftregisters[j]);
            }
        }
    }
};

#endif //ENCODER_H


