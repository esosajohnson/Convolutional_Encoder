#include <iostream>
#include "FileHandler.h"
#include "Encoder.h"

int main() {
    std::string choice;

    do {
        std::cout << "\nConvolutional Encoder Analyser\n";
        std::cout << "Author: Esosa M. Johnson Ikponmwosa\n\n";

        FileHandler fileHandler;
        fileHandler.ReadFile();

        std::vector<std::string> stringPolynomials;
        for (const auto& vec : fileHandler.outputs) {
            std::string str;
            for (int val : vec) str += std::to_string(val);
            stringPolynomials.push_back(str);
        }

        Encoder encoder(fileHandler.input, stringPolynomials, fileHandler.startingState);
        std::cout << "\nEncoded Output: ";
        encoder.Encode();
        std::cout << "\n";

        std::cout << "\nWould you like to run this program again? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice == "Y" || choice == "y" || choice == "yes" || choice == "Yes");

    return 0;
}
