#ifndef MESSAGE_H
#define MESSAGE_H

#include <ctime>
#include <string>
#include <vector>

using TexteMessage = std::vector<std::string>;

class Message {
public:
    // Constructeur
    Message(const std::string &expediteur, const std::string &destinataire);

    // Permet d'ajouter une ligne de texte au message
    void ajouter(const std::string &ligneTexte);

    // Convertit l'objet courant en chaîne de caractères
    std::string toString() const;

    // Affiche le contenu intégral de l'objet courant
    void afficher() const;

    // Les accesseurs viendraient s'insérer ici

private:
    const std::time_t dateCreation;// date-heure de création du message
    std::string expediteur;        // expéditeur du message
    std::string destinataire;      // destinataire du message
    TexteMessage texteMessage;     // l'ensemble des lignes constituant le message
};

#endif
