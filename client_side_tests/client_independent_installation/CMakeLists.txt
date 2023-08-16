cmake_minimum_required(VERSION 3.25)

project(Client)

# ANCHOR: find_package
set(Nain4_DIR "$ENV{NAIN4_INSTALL}/lib/cmake/Nain4/")
find_package(Nain4 REQUIRED)
# ANCHOR_END: find_package

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

add_executable(client_exe main.cc)

if(APPLE)
    target_link_options(Nain4 PRIVATE -undefined dynamic_lookup)
endif()

if(APPLE)
    target_link_options(client_exe PRIVATE -undefined dynamic_lookup)
endif()

target_link_libraries(
client_exe
PRIVATE
Nain4
${Geant4_LIBRARIES}
)
