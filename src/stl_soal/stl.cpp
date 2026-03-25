#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, inputKoordinat, inputID;
    cin >> n;
    map<int, int> paket;
    vector<int> koordinat(n);

    for (int i = 0; i < n; i++){
        cin >> inputKoordinat;
        paket[inputKoordinat];
        koordinat[i] = inputKoordinat;
    }
    for (int i = 0; i < n; i++){
        cin >> paket[koordinat[i]];
    }

    int paketMaks;
    vector<int> ID_paket_terambil;
    
    for (auto const& [koor, id] : paket) {
        bool status = true;
        for (int i = 0; i < ID_paket_terambil.size(); i++){
            if (id == ID_paket_terambil[i]){
                status = false;
                break;
            }
        }
        if (status == true) {
            ID_paket_terambil.push_back(id);
        }
    }
    cout << ID_paket_terambil.size();
}