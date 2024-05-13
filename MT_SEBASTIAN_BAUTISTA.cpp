/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

const int MAX_ESTUDIANTES = 100; // Máximo número de estudiantes
const int MAX_MATERIAS = 10; // Máximo número de materias por estudiante
const int MAX_NOTAS = 50; // Máximo número de notas por materia

// Estructura para almacenar las notas de un estudiante en una materia
struct Notas {
    int cantidad;
    int notas[MAX_NOTAS];
};

// Estructura para almacenar la información de un estudiante
struct Estudiante {
    int cantidadMaterias;
    Notas materias[MAX_MATERIAS];
    double promedioGeneral;
};

// Función para clasificar el promedio de un estudiante
string clasificarPromedio(double promedio) {
    if (promedio < 2.9)
        return "Bajo";
    else if (promedio >= 3.0 && promedio < 4.0)
        return "Medio";
    else
        return "Alto";
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES]; // Arreglo de estudiantes

    int cantidadEstudiantes;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidadEstudiantes;

    // Ingreso de datos
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << "Ingrese la cantidad de materias del estudiante " << i + 1 << ": ";
        cin >> estudiantes[i].cantidadMaterias;

        for (int j = 0; j < estudiantes[i].cantidadMaterias; ++j) {
            cout << "Ingrese la cantidad de notas para la materia " << j + 1 << " del estudiante " << i + 1 << ": ";
            cin >> estudiantes[i].materias[j].cantidad;

            cout << "Ingrese las notas para la materia " << j + 1 << " del estudiante " << i + 1 << ":" << endl;
            for (int k = 0; k < estudiantes[i].materias[j].cantidad; ++k) {
                cin >> estudiantes[i].materias[j].notas[k];
            }
        }

        // Cálculo del promedio general del estudiante
        cout << "promedios " << endl;
        double sumaPromedios = 0;
        for (int j = 0; j < estudiantes[i].cantidadMaterias; ++j) {
            double suma = 0;
            for (int k = 0; k < estudiantes[i].materias[j].cantidad; ++k) {
                suma += estudiantes[i].materias[j].notas[k];
            }
            double promedioMateria = suma / estudiantes[i].materias[j].cantidad;
            sumaPromedios += promedioMateria;
            cout<<"Estudiante "<< j+ 1 << ", Materia" << j + 1 << ":"<< promedioMateria<< endl;
        }
        estudiantes[i].promedioGeneral = sumaPromedios / estudiantes[i].cantidadMaterias;
        cout << " Promedio general del estudiante "<< i+1 << ": "<< estudiantes[i].promedioGeneral << endl;
    }

    // Clasificación de promedios y salida de resultados
    cout << "\nClasificación de promedios de los estudiantes:" << endl;
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        string clasificacion = clasificarPromedio(estudiantes[i].promedioGeneral);
        cout << "Estudiante " << i + 1 << ": " << clasificacion << endl;
    }

 // Mostrar tabla con nombres y promedios
    cout << "\nTabla de promedios de los estudiantes:" << endl;
    cout << left << setw (20) << "Nombre" << setw (15) << "Promedio" << endl;
    for (int i = 0; i < cantidadEstudiantes; ++i) {
        cout << left << setw(20) << estudiantes[i].nombre << setw(15) << fixed << setprecision(2) << estudiantes[i].promedioGeneral << endl;
    }

    return 0;
}