using Reseau = std::vector<std::vector<Routeur>>;

Reseau consoliderSignal(const Reseau& reseau) {
    Reseau nouveauReseau;

    // Itération sur les lignes du réseau par pas de 2
    for (size_t i = 0; i < reseau.size(); i += 2) {
        std::vector<Routeur> nouvelleLigne;

        // Itération sur les colonnes du réseau par pas de 2
        for (size_t j = 0; j < reseau[i].size(); j += 2) {
            int totalSignal = reseau[i][j].intensiteSignal;
            int compteur = 1;

            // Vérifier les limites et ajouter l'intensité du signal adjacent
            if (j + 1 < reseau[i].size()) {
                totalSignal += reseau[i][j + 1].intensiteSignal;
                compteur++;
            }
            if (i + 1 < reseau.size()) {
                totalSignal += reseau[i + 1][j].intensiteSignal;
                compteur++;
                if (j + 1 < reseau[i + 1].size()) {
                    totalSignal += reseau[i + 1][j + 1].intensiteSignal;
                    compteur++;
                }
            }

            // Calculer la moyenne de l'intensité du signal
            int moyenneSignal = totalSignal / compteur;
            nouvelleLigne.push_back({moyenneSignal});
        }

        // Ajouter la nouvelle ligne au nouveau réseau
        nouveauReseau.push_back(nouvelleLigne);
    }

    return nouveauReseau;
}
