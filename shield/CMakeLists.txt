include_directories(${ArduinoCode_SOURCE_DIR}/libu8g)

LINK_DIRECTORIES(${ArduinoCode_SOURCE_DIR}/libarduino)
LINK_DIRECTORIES(${ArduinoCode_SOURCE_DIR}/libu8g)

link_libraries(m)
link_libraries(u8g)
link_libraries(arduino)
link_libraries(m)

add_executable(shield shield.cpp)
