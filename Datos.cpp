#include<iostream>
#include<array>
#include<algorithm>
#include<map>

using namespace std;
int main(){
    freopen("Datos.txt", "r" , stdin);
    array<tuple<string,int,float>,10> estudiante;

    estudiante[0] = {"Juan",2000,3.4};
    estudiante[1] = {"Maria",2005,2.8};

    int pos = 2;

    for(int i = 0; i < 2; i++){
        string nombre;
        int nacido;
        float promedio;

        cin >> nombre >> nacido >> promedio;
        estudiante[pos++] = {nombre,nacido,promedio};
    }

    string nombres[] = {"Gaby", "Patty", "Diana"};
    int nacimientos[] = {2002, 2004, 2006};
    float gps[] = {3.8, 3.0, 2.9};

    for(int i = 0; i < 2; i++){
        estudiante[pos++] = {nombres[i],nacimientos[i],gps[i]};
    }

    for(int i = 0; i < 4; i++){
        string nombre;
        int nacido;
        float promedio;

        cin >> nombre >> nacido >> promedio;
        estudiante[pos++] = {nombre,nacido,promedio};
    }

    time_t ahora = time(0);
    tm *fecha = localtime(&ahora);
    int anioActual = 1900 + fecha->tm_year;

    for(auto &[x,y,z] : estudiante){
        cout << x << " " << y << " " << z << "\n";
        cout << "Edad: " << anioActual - y << "\n";

        if(z >= 3.5)
            cout << x << " Si califico para una beca\n";
        else
            continue;
    }
return 0;}
