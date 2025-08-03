#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void encodeFile(const std::string &inputFilename, const std::string &outputFilename, int shift) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Erreur lors de la création du fichier de sortie." << std::endl;
        return;
    }

    shift %= 26;
    std::string line;
    while (std::getline(inputFile, line)) {
        for (char &c: line) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                c = ((c - base + shift + 26) % 26) + base;
            }
        }
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

void decodeFile(const std::string &inputFilename, const std::string &outputFilename, int shift) {
    encodeFile(inputFilename, outputFilename, -shift);
}

int main() {
    encodeFile("src/source.txt", "src/chiffre.txt", 3);
    decodeFile("src/chiffre.txt", "src/claire.txt", 3);

    system("cat src/chiffre.txt");// afficher le contenu
    system("cat src/claire.txt"); // .. des fichiers créés

    return EXIT_SUCCESS;
}
