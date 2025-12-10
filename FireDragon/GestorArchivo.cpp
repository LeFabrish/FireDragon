#include "GestorArchivo.h"
#include <fstream>
#include <sstream>

using namespace std;

// ===== CONSTRUCTOR =====

GestorArchivo::GestorArchivo() {
}

// ===== ESCRITURA DE ARCHIVOS =====

void GestorArchivo::guardarLineas(string nombreArchivo, vector<vector<string>> lineas, char delimitador) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < lineas.size(); i++) {
            for (int j = 0; j < lineas[i].size(); j++) {
                archivo << lineas[i][j];
                if (j < lineas[i].size() - 1) {
                    archivo << delimitador;
                }
            }
            if (i < lineas.size() - 1) {
                archivo << endl;
            }
        }
        archivo.close();
    }
}

// ===== LECTURA DE ARCHIVOS =====

vector<vector<string>> GestorArchivo::leerLineasString(string nombreArchivo, char delimitador) {
    vector<vector<string>> lineas;
    ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            vector<string> datosLinea;
            stringstream ss(linea);
            string valor;

            while (getline(ss, valor, delimitador)) {
                datosLinea.push_back(valor);
            }
            lineas.push_back(datosLinea);
        }
        archivo.close();
    }

    return lineas;
}
// ===== VALIDACION =====

bool GestorArchivo::archivoExiste(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    return archivo.good();
}

// ===== MANEJO DE ARCHIVOS BINARIOS SIMPLE =====

void GestorArchivo::guardarTextoEnBinario(string nombreArchivo, string texto) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        archivo << texto;
        archivo.close();
    }
}

string GestorArchivo::leerTextoDelBinario(string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    string contenido = "";

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        archivo.close();
    }

    return contenido;
}
