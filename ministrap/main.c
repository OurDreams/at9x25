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
#include <stdio.h>
#include "common.h"
#include "hardware.h"
#include "board.h"
#include "dbgu.h"
#include "nandflash.h"

#define JUMP_ADDR   0x21F00000
#define IMG_ADDRESS 0x00040000
#define IMG_SIZE    0x00080000

//pio_set_gpio_output(32 + 18, 0); //µãµÆ·¨

static void display_banner (void)
{
    printf("\r\n"
           " \\|/\n"
           "--O-- miniStrap start up...\n"
           " /|\\\n");
	printf("  Build Time: "__DATE__" "__TIME__"\n\n");
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

	ret = load_nandflash(&image);
	printf("NAND: ");

	if (ret == 0){
		printf("Done to load image\n");
	}
	if (ret == -1) {
		printf("Failed to load image\n");
		while(1);
	}
	if (ret == -2) {
		printf("Success to recovery\n");
		while (1);
	}

	return JUMP_ADDR;
}
