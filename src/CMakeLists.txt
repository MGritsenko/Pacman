file(GLOB PACMAN_SRC
    "*.h"
    "*.cpp"
)

add_library(src STATIC ${PACMAN_SRC})