# ProtonJS

**ProtonJS** es un ejecutor de JavaScript que utiliza **JSCore** para interpretar código JavaScript y renderizar ventanas con una webview de manera multiplataforma.

## Características principales

- **Interpretación de JavaScript**: Ejecuta código JavaScript utilizando JSCore para garantizar un rendimiento óptimo.
- **Webview integrada**: Permite mostrar contenido interactivo en una ventana multiplataforma utilizando webviews.
- **Multiplataforma**: Diseñado para funcionar en diversos sistemas operativos (Windows, macOS, Linux).

## Instalación

1. Clona el repositorio:

   ```bash
   git clone https://github.com/joanqwerty/protonjs.git
   cd protonjs
   ```

2. Instala las dependencias necesarias (En Linux):

   ```bash
    sudo apt update
    sudo apt install libwebkit2gtk-4.0-dev
    sudo apt install libglib2.0-dev libgtk-3-dev cmake pkg-config
   ```

3. Compila el proyecto:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

## Uso

1. Ejecuta el archivo utilizando ProtonJS:

   ```bash
   ./protonJS <nombre del archivo>
   ```

## Ejemplo

El siguiente ejemplo despliega una ventana cargando un sitio web.
Desde la carpeta build ejecutar el siguiente comando:

   ```bash
      ./protonJS ../examples/website.js
   ```

## Contribución

Si deseas contribuir al desarrollo de ProtonJS:

1. Haz un fork del repositorio.
2. Crea una rama para tu función o corrección de errores:

   ```bash
   git checkout -b mi-nueva-funcion
   ```

3. Realiza tus cambios y haz un commit:

   ```bash
   git commit -m "Agrega mi nueva función"
   ```

4. Envía un pull request.

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo `LICENSE` para más detalles.

## Contacto

Si tienes preguntas, ideas o comentarios, no dudes en abrir un issue o contactar a través del repositorio oficial.
