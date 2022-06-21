#include <iostream>
#include <cstdlib>
#include <cstring>

class Cadena {
private:
    char* p;
    int tam;
public:
    Cadena(const char* palabra = "nada") {
        tam = strlen(palabra) + 1;
        p = new char[tam];
        if (p == NULL)return;
        strcpy(p, palabra);
        p[tam - 1] = '\0';
    }
    void Mostrar() {
        std::cout << p << std::endl;
    }
    ~Cadena() {
        delete p;
    }
    int getTamanio() { return tam; }
    void setP(const char* texto) {
        delete p;
        tam = strlen(texto) + 1;
        p = new char[tam];
        if (p == NULL)return;
        strcpy(p, texto);
        p[tam - 1] = '\0';
    }
    bool operator==(const Cadena& cad) {
        if (strcmp(p, cad.p) == 0)return true;
        return false;
    }
    bool operator==(const char* cad) {
        if (strcmp(p, cad) == 0)return true;
        return false;
    }
    void operator=(const char* cad) {
        delete p;
        tam = strlen(cad) + 1;
        p = new char[tam];
        if (p == NULL)return;
        strcpy(p, cad);
        p[tam - 1] = '\0';
    }
    void operator=(const std::string &pal) {
        delete p;
        tam = pal.length() + 1;
        p = new char[tam];
        if (p == NULL)return;
        strcpy(p, pal.c_str());
        p[tam - 1] = '\0';
    }
    bool buscarCaracter(char letra) {
        for (int i = 0; i < tam; i++) {
            if (p[i] == letra)return true;
        }
        return false;
    }
    int contarCaracter(char letra) {
        int cont = 0;
        for (int i = 0; i < tam; i++) {
            if (p[i] == letra)cont++;
        }
        return cont;
    }
    bool agregarCaracter(char letra) {}///agregar el caracter al final de la cadena existente
    void todoMayuscula() {}
};