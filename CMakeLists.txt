# CMakeList.txt: проект CMake для IndianRummyGame; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (IndianRummyGame "main.cpp"  "Card.h" "Deck.h" "Card.cpp" "Deck.cpp" "AI.cpp" "AI.h" "Player.cpp" "Player.h" "GameState.h"  "GameState.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
