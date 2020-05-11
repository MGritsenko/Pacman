file(GLOB PACMAN_SRC
    "*.h"
    "*.cpp"
)

add_executable(${PROJECT_NAME} ${PACMAN_SRC})