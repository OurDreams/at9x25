/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2006, Atmel Corporation

 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "common.h"
#include "hardware.h"
#include "board.h"
#include "dbgu.h"
#include "debug.h"
#include "nandflash.h"
#include "slowclk.h"

#define JUMP_ADDR   0x21F00000
#define IMG_ADDRESS 0x00040000
#define IMG_SIZE    0x00080000


static void display_banner (void)
{
	char *version = "miniStrap";

	dbgu_print("\n\r");
	dbgu_print("\n\r");
	dbgu_print(version);
	dbgu_print("\n\r");
	dbgu_print("\n\r");
}

int main(void)
{
	struct image_info image;
	int ret;

	image.dest = (unsigned char *)JUMP_ADDR;
	image.offset = IMG_ADDRESS;
	image.length = IMG_SIZE;

	hw_init();

	display_banner();
    pio_set_gpio_output(32 + 18, 0);

    while(1);
	ret = load_nandflash(&image);
	dbgu_print("NAND: ");

	if (ret == 0){
		dbgu_print("Done to load image\n\r");
	}
	if (ret == -1) {
		dbgu_print("Failed to load image\n\r");
		while(1);
	}
	if (ret == -2) {
		dbgu_print("Success to recovery\n\r");
		while (1);
	}

	slowclk_switch_osc32();

	return JUMP_ADDR;
}
