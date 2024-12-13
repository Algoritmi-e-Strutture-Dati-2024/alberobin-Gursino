#include <iostream>
#include "AlberoBinario.cpp"

int main() {
 AlberoBinario<int> albero;
 albero.insRadice(3);
 std::cout << "Inserisco Radice: \n";
 albero.stampa();
 albero.insFiglioSinistro(0, 12);
 albero.insFiglioDestro(0, 26);
 albero.insFiglioSinistro(1, 34);
 std::cout << "\nAlbero dopo l'inserimento dei figli:\n";
 albero.stampa();
 int nodoCorrente = 0;
 int sinistro = albero.figlioSinistro(nodoCorrente);
 int destro = albero.figlioDestro(nodoCorrente);
 std::cout << "\nNodo " << nodoCorrente << " (" << albero.radice() << ") ha:" << 
std::endl;
 std::cout << "Figlio sinistro all'indice: " << (sinistro != -1 ? sinistro : -1) << std::endl;
 std::cout << "Figlio destro all'indice: " << (destro != -1 ? destro : -1) << std::endl;
 albero.rimuovi(3);
 std::cout << "\nRimuovo il nodo 3: \n";
 albero.stampa();
 return 0;
}
