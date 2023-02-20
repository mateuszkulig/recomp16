# required by capstone cmake
cmake_minimum_required(VERSION 3.15)

project(recomp16 VERSION 0.1)

# path to src folder with .c files and inc folder with .h files
set(PATH_SRC ${PROJECT_SOURCE_DIR}/src)
set(PATH_INC ${PROJECT_SOURCE_DIR}/inc)

# EXEC list with all of sources to add by "add_executable" 
list(APPEND EXEC ${PATH_SRC}/main.c)
list(APPEND EXEC ${PATH_SRC}/dissasemblerTest.c)

# include capstone git submodule directory
add_subdirectory(capstone)

# add all executables from EXEC list
add_executable(recomp16 ${EXEC})

# link capstone library
target_link_libraries(recomp16 capstone)

# includes
target_include_directories(recomp16 PUBLIC ${PATH_INC})