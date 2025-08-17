#include <iostream>
#include <stdexcept>
#include <vector>

void removeFromVector(std::vector<int> &vec, size_t pos) {
    // TODO
}

int main() {
    std::vector<int> monVecteur = {1, 2, 3, 4, 5};

    // Suppression en dehors du vecteur
    try {
        removeFromVector(monVecteur, 6);// Supprime l'élément à la position 2

        // Affichage du vecteur après suppression
        for (int val: monVecteur) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    // Suppression sans erreur
    try {
        removeFromVector(monVecteur, 2);
        for (int val: monVecteur) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Cette erreur ne devrait pas arriver: " << e.what() << std::endl;
    }

    // Suppression sur un vecteur vide
    try {
        std::vector<int> vide;
        removeFromVector(vide, 2);
        for (int val: monVecteur) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
