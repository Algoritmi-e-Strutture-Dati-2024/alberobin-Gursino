#include <iostream>
template <typename T>
class AlberoBinario {
  private:
  T elementi[100];
 bool presente[100];
 int numeroNodi;
public:
 AlberoBinario() {
 numeroNodi = 0;
 for (int indice = 0; indice < 100; ++indice) {
 presente[indice] = false;
 }
 }
 bool alberoVuoto() const {
 return numeroNodi == 0;
 }
 void insRadice(const T& valore) {
 if (numeroNodi < 100) {
 elementi[0] = valore;
 presente[0] = true;
 numeroNodi = 1;
 }
 }
 T radice() const {
 return alberoVuoto() ? T() : elementi[0];
 }
 bool isFoglia(int indice) const {
 if (!presente[indice]) return false;
 int sinistro = 2 * indice + 1;
 int destro = 2 * indice + 2;
 return (sinistro >= 100 || !presente[sinistro]) && (destro >= 100 || !
presente[destro]);
 }
 int figlioSinistro(int indice) const {
 int sinistro = 2 * indice + 1;
 return (sinistro < 100 && presente[sinistro]) ? sinistro : -1;
 }
 int figlioDestro(int indice) const {
 int destro = 2 * indice + 2;
 return (destro < 100 && presente[destro]) ? destro : -1;
 }
 void insFiglioSinistro(int indice, const T& valore) {
 int sinistro = 2 * indice + 1;
 if (sinistro < 100 && presente[indice] && !presente[sinistro]) {
 elementi[sinistro] = valore;
 presente[sinistro] = true;
 ++numeroNodi;
 }
 }
 void insFiglioDestro(int indice, const T& valore) {
 int destro = 2 * indice + 2;
 if (destro < 100 && presente[indice] && !presente[destro]) {
 elementi[destro] = valore;
 presente[destro] = true;
 ++numeroNodi;
 }
 }
 void rimuovi(int indice) {
 if (indice < 100 && presente[indice]) {
 // Elimina solo se il nodo è una foglia
 if (isFoglia(indice)) {
 presente[indice] = false;
 --numeroNodi;
 } else {
 // Gestisce l'eliminazione di un nodo con figli
 int sinistro = 2 * indice + 1;
 int destro = 2 * indice + 2;
 if (sinistro < 100 && presente[sinistro]) {
 presente[sinistro] = false;
 --numeroNodi;
 }
 if (destro < 100 && presente[destro]) {
 presente[destro] = false;
 --numeroNodi;
 }
 presente[indice] = false;
 --numeroNodi;
 }
 }
 }
 void stampa() const {
 for (int indice = 0; indice < 100; ++indice) {
 if (presente[indice]) {
 std::cout << "Nodo " << indice << ": " << elementi[indice] << std::endl;
 int sinistro = figlioSinistro(indice);
 int destro = figlioDestro(indice);
 
 if (sinistro != -1 && presente[sinistro]) {
 std::cout << " Figlio sinistro: " << elementi[sinistro] << std::endl;
 } else {
 std::cout << " Figlio sinistro: /" << std::endl;
 }
 if (destro != -1 && presente[destro]) {
 std::cout << " Figlio destro: " << elementi[destro] << std::endl;
 } else {
 std::cout << " Figlio destro: /" << std::endl;
 }
 }
 }
 }
};
