#ifndef OLED_H
#define OLED_H

#if __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


enum controlbyte{
    SINGLE_COMMAND                      = 0x80U,
    COMMAND_STREAM                      = 0x00U,
    SINGLE_DATA                         = 0xC0U,
    DATA_STREAM                         = 0x40U,
};


enum commandsandarguments {
    // Fundamental Commands Table
    // we can set in 256(0 to 256) setups
    SET_CONTRAST_CONTROL                                        = 0x81U,
    CONTRAST_RESET_VALUE                                        = 0x7FU, // arg

    ENTIRE_DISPLAY_ON_RESUME_TO_RAM                             = 0xA4U, // Resume to RAM content display
    ENTIRE_DISPLAY_ON                                           = 0xA5U, // Entire display on, ignores RAM content
    SET_NORMAL_MODE                                             = 0xA6U, // Set to normal mode
    SET_INVERSE_MODE                                            = 0xA7U, // Set to inverse mode
    SET_DISPLAY_ON                                              = 0xAFU, // Display on
    SET_DISPLAY_OFF                                             = 0xAEU, // Display off
    
    // Scrolling Command Table
    RIGHT_CONTINUOUS_HORIZONTAL_SCROLL_SETUP                    = 0x26U, // Right Horizontal Scroll
    // the above command should follow
    // A -> 00h, B -> start page address, c -> set time interval between each scroll step in terms of frame frequency
    // D -> define end page address, e -> dummy, f -> dummy
    LEFT_CONTINUOUS_HORIZONTAL_SCROLL_SETUP                     = 0x27U, // Left Horizontal Scroll
    // the above command should follow
    // A -> 00h, B -> start page address, c -> set time interval between each scroll step in terms of frame frequency
    // D -> define end page address, e -> Vertical scrolling offset,
    VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL                        = 0x29U, // enable Vertical and Right Horizontal Scroll, check the doc for options
    VERTICAL_AND_LEFT_HORIZONTAL_SCROLL                         = 0x2AU, // enable Vertical and Left Horizontal Scroll, check the doc for options
    DEACTIVATE_SCROLL                                           = 0X2EU, // Stop scrolling
    ACTIVATE_SCROLL                                             = 0x2FU, // Start Scrolling
    SET_VERTICAL_SCROLL_AREA                                    = 0xA3U, // Set No of rows in top fixed area.
    // the above command should follow
    // A -> Set No. of rows in top fixed area, The No. of rows in top fixed area is referenced to the top of the GDDRAM 
    // B -> Set No. of rows in scroll area. This is the number of rows to be used for vertical scrolling. The scroll area starts in the first row below the top fixed area. 
    
    // Addressing Setting Command Table
    SET_LOWER_COLUMN_START_ADDRESS_FOR_PAGE_ADDRESSING_MODE     = 0x00U,     
    SET_HIGHER_COLUMN_START_ADDRESS_FOR_PAGE_ADDRESSING_MODE    = 0x10U,
    // set the memory addressing mode
    SET_MEMORY_ADDRESSING_MODE                                  = 0x20U, // command
    HORIZONTAL_ADDRESSING_MODE                                  = 0x00U, 
    VERTICAL_ADDRESSING_MODE                                    = 0x01U,
    PAGE_ADDRESSING_MODE                                        = 0x02U,
    
    // setup column start and end address
    SET_COLUMN_ADDRESS                                          = 0x21U,
    COLUMN_ADDRESS_START_RESET_VALUE                            = 0x00U, // arg
    COLUMN_ADDRESS_END_RESET_VALUE                              = 0x7FU, // arg

    // setup page start and end address
    SET_PAGE_ADDRESS                                            = 0x22U,
    PAGE_ADDRESS_START_RESET_VALUE                              = 0x00U, // arg
    PAGE_ADDRESS_END_RESET_VALUE                                = 0x03U, // arg
    SET_SEGMENT_RE_MAP_SEG127                                   = 0xA1U, // remap the start of the display to SEG127
    SET_PAGE_START_ADDRESS_FOR_PAGE_ADDRESSING_MODE             = 0xB0U, // set GDDRAM page start address
    
    // Hardware Configuration Command Table
    SET_DISPLAY_START_LINE                                      = 0x40U, // Set display RAM display start line register form 0-63, for now only 32 is enough
    SET_SEGMENT_RE_MAP_SEG0                                     = 0xA0U, // remap the start of the display to SEG0
    // Set the multiplex
    SET_MULTIPLEX_RATIO                                         = 0xA8U, // command
    MULTIPLEX_32                                                = 0x1FU, // arg -> Set the multiplexing to 32
    
    SET_COM_OUTPUT_SCAN_DIRECTION_NORMAL_MODE                   = 0xC0U, // set the scan direction as normal mode Scan from COM0 to COM[N –1]
    SET_COM_OUTPUT_SCAN_DIRECTION_REMAPPED_MODE                 = 0xC8U, // set the scan direction as remapped mode Scan from COM[N-1] to COM0
    SET_DISPLAY_OFFSET                                          = 0xD3U, // Set vertical shift by COM from 0 to 63(in next byte).
    // Set how COM is connected in physicaly to display
    SET_COM_PINS_HARDWARE_CONFIGURATION                         = 0xDAU,
    SEQUENTIAL_COM_PIN_CONFIGURATION                            = 0x02U, // arg: Sequential COM pin configuration

    // Timing & Driving Scheme Setting Command Table
    // set the divide clock and oscillator frequency 
    SET_DISPLAY_CLOCK_DIVIDE_RATIO_OSCILLATIOR_FREQUENCY        = 0xD5U,
    CLOCK_DIVIDE_RATIO_OSCILLATOR_FREQUENCY_RESET_VALUE         = 0x80U, // arg
    
    // set the period of up to 15 DCLK clock 0 
    SET_PRE_CHARGE_PERIOD                                       = 0xD9U,
    PRE_CHARGE_PERIOD_RESET_VALUE                               = 0x22U, // arg
    
    SET_V_COMH_DESELECT_LEVEL                                   = 0xDBU, // 
    NOP                                                         = 0xE3U, // command for no operation

    // charge pump command
    // enable the charge pump setting
    CHARGE_PUMP_SETTING                                         = 0x8DU,
    CHARGE_PUMP_ENABLE                                          = 0x14U,
};

#define ASCII_FONT_COLS_LENGTH 24   // 12 columns × 2 bytes

extern const uint8_t ASCII_FONT_12x14[][ASCII_FONT_COLS_LENGTH];

void setup_oled_display(void);

void send_cmd_oled(uint8_t cmd, uint8_t leng, uint8_t *args);

void send_data_oled(uint8_t *data, size_t leng);

void send_char_oled(uint8_t hour, uint8_t minutes, uint8_t seconds, uint8_t ampm, uint8_t day, uint8_t month, uint8_t year, uint8_t weekday);

void send_state_oled(uint8_t state);

void send_char_oled_alarm(uint8_t hour, uint8_t minutes, uint8_t seconds, uint8_t ampm, uint8_t day);

void print_string_to_oled(char *chars, size_t leng);

void print_char(uint8_t *frame, uint8_t value, uint32_t position);

#if __cplusplus
}
#endif
#endif