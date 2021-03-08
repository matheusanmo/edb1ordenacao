# cmake --version
cmake_minimum_required(VERSION 3.16.3)

# nome do projeto
project(ordenacao)

# exigir suporte C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# exibir mais warnings
add_compile_options(-Wall -Wextra)

# definir nome de executavel e arquivos que o constroem
add_executable(ordenacao src/main.cpp src/vecfacilities.cpp src/sorts.cpp src/timefacilities.cpp)

