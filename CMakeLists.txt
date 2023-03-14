# required by capstone cmake
cmake_minimum_required(VERSION 3.15)

project(recomp16 VERSION 0.1)

# path to src folder with .c files and inc folder with .h files
set(PATH_SRC ${PROJECT_SOURCE_DIR}/src)
set(PATH_INC ${PROJECT_SOURCE_DIR}/inc)

# EXEC list with all of sources to add by "add_executable" 
list(APPEND EXEC ${PATH_SRC}/main.c)
list(APPEND EXEC ${PATH_SRC}/dissasemblerTest.c)
list(APPEND EXEC ${PATH_SRC}/byteReader.c)
list(APPEND EXEC ${PATH_SRC}/disassembler.c)

# include capstone git submodule directory
add_subdirectory(capstone)

# add all executables from EXEC list
add_executable(recomp16 ${EXEC})

# copy opsys folder to build dir
# taken from https://stackoverflow.com/questions/3702115/creating-a-directory-in-cmake
add_custom_command(TARGET recomp16 PRE_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_SOURCE_DIR}/opsys ${CMAKE_BINARY_DIR}/opsys/)

# link capstone library
target_link_libraries(recomp16 capstone)

# includes
target_include_directories(recomp16 PUBLIC ${PATH_INC})