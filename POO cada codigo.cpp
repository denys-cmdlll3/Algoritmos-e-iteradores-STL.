
#include<iostream>
#include<array>
#include<algorithm>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;

class GrupoNumeros{
private:
    array<int,20> numeros;

public:

    void generar(){
        int idx = 0;

        for(int val = 31; idx < 5; val += 2){
            numeros[idx] = val;
            idx++;
        }

        int val_medio = 1;

        for(int i = 5; i < 20; i++){
            if(i > 14){
                numeros[i] = val_medio;
                val_medio += 2;
            }
            else{
                numeros[i] = 2 * i + 1;
            }
        }
    }

    void imprimir(){
        cout << "Todos los elementos\n";

        for(int x : numeros){
            cout << x << " ";
        }
        cout << "\n\n";
    }

    void mayores(){
        cout << "Elementos mayores de 20 y menores que 50\n";

        for(int x : numeros){
            if(x > 20 && x < 50){
                cout << x << " ";
            }
        }
        cout << "\n\n";
    }

    void ordenar(){
        sort(numeros.begin(), numeros.end());

        cout << "Elementos ordenados\n";

        for(int x : numeros){
            cout << x << " ";
        }
        cout << "\n\n";
    }

    void indicesImpares(){
        cout << "Elementos en indices impares menores de 10\n";

        for(int i = 1; i < 10; i += 2){
            cout << "Indice " << i << ": "
                 << numeros.at(i) << "\n";
        }
    }
};

class GrupoPaises{
private:
    array<string,12> paises;

public:

    GrupoPaises(){
        paises = {
            "Argentina", "Bolivia", "Brasil", "Chile",
            "Colombia", "Ecuador", "Guyana", "Paraguay",
            "Peru", "Surinam"
        };
    }

    void insertar(){
        paises.at(10) = "Uruguay";
        paises[11] = "Venezuela";
    }

    void iniciales(){
        cout << "Paises que inician con C o P\n";

        for(const string &p : paises){
            if(!p.empty() &&
              (p[0] == 'C' || p[0] == 'P' ||
               p[0] == 'c' || p[0] == 'p')){
                cout << p << "\n";
            }
        }
        cout << "\n";
    }

    void primeroUltimo(){
        cout << "Primer y ultimo elemento del grupo\n";

        cout << "Primer pais: " << paises.front() << "\n";
        cout << "Ultimo pais: " << paises.back() << "\n\n";
    }

    void ordenar(){
        sort(paises.begin(), paises.end());

        cout << "Elementos ordenados alfabeticamente\n";

        for(const string &p : paises){
            cout << "- " << p << "\n";
        }
    }
};

class Estudiante{
private:
    string nombre;
    int nacido;
    float promedio;

public:

    Estudiante(){
        nombre = "";
        nacido = 0;
        promedio = 0;
    }

    Estudiante(string n, int a, float p){
        nombre = n;
        nacido = a;
        promedio = p;
    }

    string getNombre(){
        return nombre;
    }

    int getNacimiento(){
        return nacido;
    }

    float getPromedio(){
        return promedio;
    }
};

class GrupoEstudiantes{
private:
    array<Estudiante,10> estudiante;
    int pos;

public:

    GrupoEstudiantes(){
        estudiante[0] = Estudiante("Juan",2000,3.4);
        estudiante[1] = Estudiante("Maria",2005,2.8);

        pos = 2;
    }

    void insertarTeclado(){
        cout << "Ingrese dos estudiantes:\n";

        for(int i = 0; i < 2; i++){
            string nombre;
            int nacido;
            float promedio;

            cin >> nombre >> nacido >> promedio;

            estudiante[pos++] = Estudiante(nombre,nacido,promedio);
        }
    }

    void insertarArrays(){
        string nombres[] = {"Gaby", "Patty", "Diana"};
        int nacimientos[] = {2002, 2004, 2006};
        float gps[] = {3.8, 3.0, 2.9};

        for(int i = 0; i < 2; i++){
            estudiante[pos++] = Estudiante(
                nombres[i],nacimientos[i],gps[i]
            );
        }
    }

    void leerArchivo(){
        ifstream archivo("Datos.txt");

        if(!archivo){
            cout << "No se pudo abrir el archivo\n";
            return;
        }

        for(int i = 0; i < 4; i++){
            string nombre;
            int nacido;
            float promedio;

            if(archivo >> nombre >> nacido >> promedio){
                estudiante[pos++] = Estudiante(
                    nombre,nacido,promedio
                );
            }
        }

        archivo.close();
    }

    void imprimir(){
        time_t ahora = time(0);
        tm *fecha = localtime(&ahora);
        int anioActual = 1900 + fecha->tm_year;

        cout << "\nLISTA DE ESTUDIANTES\n";

        for(int i = 0; i < pos; i++){

            cout << "\nNombre: "
                 << estudiante[i].getNombre();

            cout << "\nNacimiento: "
                 << estudiante[i].getNacimiento();

            cout << "\nPromedio: "
                 << estudiante[i].getPromedio();

            cout << "\nEdad: "
                 << anioActual - estudiante[i].getNacimiento();

            if(estudiante[i].getPromedio() >= 3.5){
                cout << "\nCalifica para una beca";
            }
            else{
                cout << "\nNo califica para una beca";
            }

            cout << "\n----------------------\n";
        }
    }
};

int main(){

    cout << "========== EJERCICIO 1 ==========\n";

    GrupoNumeros grupo1;

    grupo1.generar();
    grupo1.imprimir();
    grupo1.mayores();
    grupo1.ordenar();
    grupo1.indicesImpares();


    cout << "\n========== EJERCICIO 2 ==========\n";

    GrupoPaises grupo2;

    grupo2.insertar();
    grupo2.iniciales();
    grupo2.primeroUltimo();
    grupo2.ordenar();


    cout << "\n========== EJERCICIO 3 ==========\n";

    GrupoEstudiantes grupo3;

    grupo3.insertarTeclado();
    grupo3.insertarArrays();
    grupo3.leerArchivo();
    grupo3.imprimir();

    return 0;
}
