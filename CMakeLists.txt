cmake_minimum_required(VERSION 4.1)
project(untitled)
set(VCPKG_TARGET_TRIPLET x64-mingw-dynamic)

set(CMAKE_CXX_STANDARD 20)

# Wir definieren die Pfade manuell, da vcpkg sie nicht automatisch durchreicht
set(RAYLIB_DIR "C:/Users/alexa/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic")

# 1. Wo liegen die Header (.h)?
include_directories("${RAYLIB_DIR}/include")

# 2. Wo liegen die Bibliotheken (.a / .lib)?
link_directories("${RAYLIB_DIR}/lib")

add_executable(untitled
        main.cpp
        Player.cpp
        Player.h
        Coin.cpp
        Coin.h
        Enemy.cpp
        Enemy.h
)

# 3. Wir verlinken direkt gegen die Datei
target_link_libraries(untitled PRIVATE raylib)

# Für Windows/MinGW brauchen wir oft noch diese System-Bibliotheken
target_link_libraries(untitled PRIVATE winmm gdi32)

