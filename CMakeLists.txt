cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)

project(Renderer)

add_subdirectory(vendor/GLAD)
add_subdirectory(vendor/GLFW)
add_subdirectory(vendor/glm)

file(GLOB_RECURSE SRC src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME}
        PUBLIC
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            vendor/glm/

        PRIVATE
            vendor/GLAD/include
            vendor/GLFW/include
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC
            glm

        PRIVATE
            glad
            glfw
        )
