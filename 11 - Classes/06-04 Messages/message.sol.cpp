#include "message.sol.h"
#include <iostream>

using namespace std;

Message::Message(const string &expediteur, const string &destinataire)
    : dateCreation(time(NULL)), expediteur(expediteur), destinataire(destinataire) {
}

void Message::ajouter(const string &ligneTexte) {
    texteMessage.push_back(ligneTexte);
}

string Message::toString() const {
    const string FORMAT = "%d.%m.%Y %X";// Exemple : 24.07.2021 16:10:25
                                        //    const string FORMAT = "%d.%m.%Y %H:%M"; // Exemple : 24.07.2021 16:10
    char buffer[256];
    strftime(buffer, sizeof(buffer), FORMAT.c_str(), localtime(&dateCreation));
    string str = "From : " + expediteur + '\n' +
                 "To   : " + destinataire + '\n' +
                 "Date : " + buffer + '\n';
    str += '\n';
    for (const string &s: texteMessage)
        str += s + '\n';
    return str;
}

void Message::afficher() const {
    cout << toString();
}
