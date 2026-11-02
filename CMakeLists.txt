cmake_minimum_required(VERSION 3.20)

# setting the toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/board/arm-none-eabi-gcc.cmake" CACHE FILEPATH "Toolchain")
set(CPU_FLAGS "-mcpu=cortex-m4 -mthumb -nostdlib")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CPU_FLAGS} -Wall -Wextra -g3 -fdata-sections -ffunction-sections")

# Enable C, c++ and Assemebly
project(waker C CXX ASM) 

set(CMAKE_C_STANDARD 11)

set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${CPU_FLAGS}")

set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/board/stm32F401CCU6/stm32F401CCU6.ld")
set(CMAKE_EXE_LINKER_FLAGS "${CPU_FLAGS} -T${LINKER_SCRIPT} -Wl,--gc-sections --specs=nano.specs")

include_directories(
    "include"
)

file(GLOB_RECURSE SOURCES
    "board/stm32F401CCU6/startup.c"    
    "src/*.c"
    "subsys/*.c"
)

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${INCLUDES}
    subsys/core.c
    include/app.h
    include/i2c.h
    include/oled.h)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMAND arm-none-eabi-objcopy -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    COMMENT "generating hex and bin for flashing"
)


add_custom_target(flash
    COMMAND openocd -f "C:/Program Files/openocd/openocd/scripts/interface/stlink.cfg" -f "C:/Program Files/openocd/openocd/scripts/target/stm32f4x.cfg" -c "program ${PROJECT_NAME}.elf verify reset exit"
    DEPENDS ${PROJECT_NAME}.elf
    COMMENT "Flashing binary to STM32 target..."
)