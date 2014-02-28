#include(${ArduinoCode_SOURCE_DIR}/arduino_diecimila_crosscompile.cmake)

include_directories(${ArduinoCode_SOURCE_DIR}/libarduino/cores/arduino ${ArduinoCode_SOURCE_DIR}/libarduino/variants/standard)


add_library (arduino
cores/arduino/IPAddress.cpp
cores/arduino/new.cpp
cores/arduino/Tone.cpp
cores/arduino/wiring_shift.c
cores/arduino/wiring.c
cores/arduino/avr-libc/realloc.c
cores/arduino/avr-libc/malloc.c
cores/arduino/CDC.cpp
cores/arduino/HID.cpp
cores/arduino/HardwareSerial.cpp
cores/arduino/Stream.cpp
cores/arduino/wiring_digital.c
cores/arduino/main.cpp
cores/arduino/WString.cpp
cores/arduino/wiring_pulse.c
cores/arduino/WInterrupts.c
cores/arduino/USBCore.cpp
cores/arduino/wiring_analog.c
cores/arduino/Print.cpp
cores/arduino/WMath.cpp
)
