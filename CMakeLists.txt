cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(protonJS)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directorios de los archivos fuente y Webview
set(SOURCE_DIR src)
set(THIRD_PARTY_DIR extern/webview)

# Buscar los archivos fuente en src
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

include_directories(${THIRD_PARTY_DIR})

# add_subdirectory(extern/libuv)
# target_link_libraries(uv)

# Detectar el sistema operativo y agregar las dependencias correspondientes
if(WIN32)
    set(LIBRARIES ole32 comctl32 d2d1 Shcore)
elseif(UNIX AND NOT APPLE)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK REQUIRED gtk+-3.0)
    pkg_check_modules(WEBKIT REQUIRED webkit2gtk-4.0)
    include_directories(${GTK_INCLUDE_DIRS} ${WEBKIT_INCLUDE_DIRS})
    find_library(JAVASCRIPTCORE_LIBRARY JavaScriptCore)
    link_directories(${GTK_LIBRARY_DIRS} ${WEBKIT_LIBRARY_DIRS} ${JAVASCRIPTCORE_LIBRARY})
    add_definitions(${GTK_CFLAGS_OTHER} ${WEBKIT_CFLAGS_OTHER})
    set(LIBRARIES ${GTK_LIBRARIES} ${WEBKIT_LIBRARIES})
elseif(APPLE)
    set(LIBRARIES "-framework WebKit -framework Cocoa")
endif()

# Generar el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Vincular las bibliotecas
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

