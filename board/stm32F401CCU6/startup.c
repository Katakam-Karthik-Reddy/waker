#define SRAM_START (0x20000000U)
#define SRAM_SIZE (64U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)


#include <stdint.h>
#include "utils.h"
#define ISR_VECTOR_SIZE_WORDS 101

void reset_handler(void);
void default_handler(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void PendSV_Handler(void) __attribute__((weak, alias("default_handler")));
void SysTick_Handler(void) __attribute__((weak, alias("default_handler")));
void WWDG_handler(void) __attribute__((weak, alias("default_handler")));
void EXTI16_handler(void) __attribute__((weak, alias("default_handler")));
void EXTI21_handler(void) __attribute__((weak, alias("default_handler")));
void EXTI22_handler(void) __attribute__((weak, alias("default_handler")));
void FLASH_handler(void) __attribute__((weak, alias("default_handler")));
void RCC_handler(void) __attribute__((weak, alias("default_handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void Alarm_Handler(void) __attribute__((weak, alias("default_handler")));
// continue adding device interrupt handlers

uint32_t isr_vector[ISR_VECTOR_SIZE_WORDS] __attribute__((section(".isr_vector"))) = {
    STACK_POINTER_INIT_ADDRESS,
    (uint32_t)&reset_handler,
    (uint32_t)&nmi_handler,
    (uint32_t)&hard_fault_handler,
    (uint32_t)&mem_manage_handler,
    (uint32_t)&bus_fault_handler,
    (uint32_t)&usage_fault_handler,
    0,
    0,
    0,
    0,
    (uint32_t)&svcall_handler,
    (uint32_t)&debug_monitor_handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,
    (uint32_t)&WWDG_handler,
    (uint32_t)&EXTI16_handler,
    (uint32_t)&EXTI21_handler,
    (uint32_t)&EXTI22_handler,
    (uint32_t)&FLASH_handler,
    (uint32_t)&RCC_handler,
    (uint32_t)&EXTI0_IRQHandler,
    (uint32_t)&EXTI1_IRQHandler,
    (uint32_t)&EXTI2_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)&Alarm_Handler,
};


/**
 * @brief this is just for alias 
 */
void default_handler(void)
{
  while(1){
    writef("thisf af");
  };
}


extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;
void main(void);

void reset_handler(void)
{
  // Copy .data from FLASH to SRAM
  uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *flash_data = (uint8_t*) &_etext;
  uint8_t *sram_data = (uint8_t*) &_sdata;
  
  for (uint32_t i = 0; i < data_size; i++)
  {
    sram_data[i] = flash_data[i];
  }

  // Zero-fill .bss section in SRAM
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *bss = (uint8_t*) &_sbss;

  for (uint32_t i = 0; i < bss_size; i++)
  {
    bss[i] = 0;
  }
  
  main();
}