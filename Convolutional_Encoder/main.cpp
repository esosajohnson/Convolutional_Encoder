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


    Encoder encoder("1011000");

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