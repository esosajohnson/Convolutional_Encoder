#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "Encoder.h"

class FileHandler {
public:
    // Declare variables
    int numShiftRegisters;
    std::string input;
    std::vector<int> startingState;
    std::vector<std::vector<int>> outputs;

    void ReadFile(){
        FileH();
    }

    void FileH() {
        // Reset all previous data
        startingState.clear();
        outputs.clear();
        input.clear();
        numShiftRegisters = 0;

        // Prompts the user to enter the filename of any encoder
        std::string inputFileName;
        std::cout << "Please enter the input filename from the keyboard: " << std::endl;
        std::cin >> inputFileName;

        std::ifstream inputFileStream;
        inputFileStream.open((inputFileName));

        // Checks if the file can be opened, if the file exists in the working directory
        if (inputFileStream.good()) {
            std::cout << "Input file is good start processing..." << std::endl << std::endl;

            // Reads the first three lines of the encoder (No. of shift registers, starting state and input)
            std::string line;
            for (int i = 0; i < 3; i++) {
                std::getline(inputFileStream, line);

                std::stringstream sstream(line);
                std::string token1, token2;
                std::getline(sstream, token1, ':');
                std::getline(sstream, token2);


                if (i == 0) {
                    numShiftRegisters = std::stoi(token2);
                } else if (i == 1) {
                    // Read the starting state
                    std::stringstream sstream2(token2);
                    std::string token3;
                    while (std::getline(sstream2, token3, ',')) {
                        startingState.push_back(std::stoi(token3));
                    }
                } else {
                    for (char ch : token2) {
                        if (ch == '0' || ch == '1') {
                            input += ch;
                        }
                    }
                    ;
                }
            }

            // Read the outputs
            while (std::getline(inputFileStream, line)) {
                std::vector<int> output;

                // Split the line into tokens by colon
                std::stringstream sstream(line);
                std::string token1, token2;
                std::getline(sstream, token1, ':');
                std::getline(sstream, token2);

                // Split the token into tokens by comma
                std::stringstream sstream2(token2);
                std::string token3;
                while (std::getline(sstream2, token3, ',')) {
                    output.push_back(std::stoi(token3));
                }

                outputs.push_back(output);
            }

            // Close the input file
            inputFileStream.close();
        } else {
            std::cout << "Error opening input file, check file exists in correct directory." << std::endl;
        }

        // Print the variables
        std::cout << "File " << inputFileName << " read successfully" << std::endl;
        std::cout << "This encoder has " << numShiftRegisters << "x shift registers." << std::endl;
        std::cout << "The starting state of the shift registers is: ";
        for (size_t i = 0; i < startingState.size(); ++i) {
            std::cout << startingState[i];
            if (i != startingState.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "The input is: " << input << std::endl;
        std::cout << "The generator polynomials are:" << std::endl;
        for (int i = 0; i < outputs.size(); i++) {
            std::cout << "Output " << (char)(i + 65) << ": ";
            for (size_t j = 0; j < outputs[i].size(); ++j) {
                std::cout << outputs[i][j];
                if (j != outputs[i].size() - 1) std::cout << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << "This encoder is a rate 1/" << outputs.size()
            << " encoder (1 input to " << outputs.size() << " outputs)." << std::endl;
    }

};

#endif //FILEHANDLER_H