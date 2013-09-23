/**
 ******************************************************************************
 * @file       cfg.h
 * @brief      API include file of cfg.h.
 * @details    This file including all API functions's declare of cfg.h.
 * @copyright
 *
 ******************************************************************************
 */
#ifndef CFG_H_
#define CFG_H_ 

/*-----------------------------------------------------------------------------
 Section: Macro Definitions
 ----------------------------------------------------------------------------*/
#define JUMP_ADDR       0x23F00000
#define IMG_ADDRESS     0x00040000
#define IMG_SIZE        0x00080000

#define CONFIG_DISABLE_WATCHDOG         0
#define CONFIG_USE_PMECC
#define PMECC_ERROR_CORR_BITS           2
#define PMECC_SECTOR_SIZE               512
#define CONFIG_NANDFLASH_RECOVERY
#define RECOVERY_BUTTON_NAME            "PB11"
#define CONFIG_SYS_RECOVERY_BUTTON_PIN  AT91C_PIN_PB(11)

#define DEBUG_LEVEL

#endif /* CFG_H_ */
/*------------------------------End of cfg.h---------------------------------*/
