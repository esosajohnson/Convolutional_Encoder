//---------------------------------------
//  Author:  Esosa M. Johnson Ikponmwosa
//---------------------------------------

#include <iostream>
#include "Encoder.h"


int main() {
    std::cout << std::endl;

    std::cout << "Convolutional Encoder Analyser" << std::endl;

    std::cout << std::endl;

    std::cout << "Author: Esosa M. Johnson Ikponmwosa" << std::endl;

    FileHandler fileHandler;
    fileHandler.ReadFile();

    std::vector<std::string> stringPolynomials;
    for (const auto& vec : fileHandler.outputs) {
        std::string str;
        for (int val : vec) str += std::to_string(val);
        stringPolynomials.push_back(str);
    }

    Encoder encoder(fileHandler.input, stringPolynomials, fileHandler.startingState);


    // Encode the input string
    std::cout << "Encoded Output: ";
    encoder.Encode();
    std::cout << std::endl;

    std::string choice;
    std::cout << "Would you like to run this program again? (Y/N): ";
    std::cin >> choice;

    if (choice == "Y" || "y" || "yes" || "Yes") {
        FileHandler fileH;
        fileHandler.ReadFile();
    }

    return 0;
}