#pragma once
#include <string>
#include <vector>

using namespace std;
class GestorArchivo
{
public:
    GestorArchivo();

    // Guardar lineas de texto en un archivo
    void guardarLineas(string nombreArchivo, vector<vector<string>> lineas, char delimitador);

    // Leer todas las lineas de un archivo
    vector<vector<string>> leerLineasString(string nombreArchivo, char delimitador);

    // Verificar si un archivo existe
    bool archivoExiste(string nombreArchivo);

    // Métodos simples para archivo binario con strings e int
    void guardarTextoEnBinario(string nombreArchivo, string texto);
    string leerTextoDelBinario(string nombreArchivo);
};


