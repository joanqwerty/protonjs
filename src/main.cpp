#include "Application.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Uso: " << argv[0] << " <nombre_del_archivo>" << std::endl;
        return 1;
    }

    std::string nombreArchivo = argv[1];
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << archivo.rdbuf();
    std::string source = buffer.str();
    
    Application app;
    app.run(source);

    return 0;
}
