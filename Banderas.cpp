#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    array<string, 10> paises = {
        "Argentina", "Bolivia", "Brasil", "Chile", "Colombia",
        "Ecuador", "Guyana", "Paraguay", "Perú", "Surinam"
    };

    paises.resize(12);

    paises.at(10) = "Uruguay";
    paises[11] = "Venezuela";

    cout << "Paises que inician con C o P\n";
    for (const string &p : paises) {
        if (!p.empty() && (p[0] == 'C' || p[0] == 'P' || p[0] == 'c' || p[0] == 'p')) {
            cout << p << "\n";
        }
    }
    cout << "\n";

    cout << "Primer y ultimo elemento del grupo\n";
    cout << "Primer pais: " << paises.front() << "\n";
    cout << "Ultimo pais: " << paises.back() << "\n\n";

    cout << "Elementos ordenados alfabeticamente\n";
    sort(paises.begin(), paises.end());
    for (const string &p : paises) {
        cout << "- " << p << "\n";
    }

    return 0;
}
