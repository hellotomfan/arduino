#include(${ArduinoCode_SOURCE_DIR}/arduino_diecimila_crosscompile.cmake)

include_directories(${ArduinoCode_SOURCE_DIR}/libu8g)

LINK_DIRECTORIES(${ArduinoCode_SOURCE_DIR}/libarduino)
LINK_DIRECTORIES(${ArduinoCode_SOURCE_DIR}/libu8g)

link_libraries(u8g)
link_libraries(arduino)

add_executable(main main.cpp)
