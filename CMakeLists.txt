#SET(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 2.6)

Project(ArduinoCode)


SET(CMAKE_SYSTEM_NAME Generic)

SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)

SET(CSTANDARD "-std=gnu99")
SET(CDEBUG "-gstabs")
SET(CWARN "-Wall -Wstrict-prototypes")
SET(CTUNING "-fno-exceptions -ffunction-sections -fdata-sections")
SET(COPT "-Os")
SET(CINCS "-I${ArduinoCode_SOURCE_DIR}/libarduino/cores/arduino -I${ArduinoCode_SOURCE_DIR}/libarduino/variants/standard")
SET(CMCU "-mmcu=atmega328p")
SET(CDEFS "-DF_CPU=16000000L -MMD -DUSB_VID=null -DUSB_PID=null -DARDUINO=105")

SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "-Wl,--gc-sections")
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "-Wl,--gc-sections")

SET(CFLAGS "${CMCU} ${CDEBUG} ${CTUNING} ${CDEFS} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
SET(CXXFLAGS "${CMCU} ${CTUNING} ${CDEFS} ${CINCS} ${COPT}")

SET(CMAKE_C_FLAGS  ${CFLAGS})
SET(CMAKE_CXX_FLAGS ${CXXFLAGS})


add_subdirectory(libarduino)
add_subdirectory(libu8g)
add_subdirectory(main)
add_subdirectory(bird)
add_subdirectory(shield)

