/*
 * Copyright (c) 2009-2012 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include "platform.h"
#include "xbasic_types.h"
#include "xparameters.h"

Xuint32 *baseaddr_p = (Xuint32 *)XPAR_MULTWITHTROJAN_0_S00_AXI_BASEADDR;
//void print(char *str);

int main()
{
    init_platform();

    //xil_printf("Hello World\n\r");

    *(baseaddr_p+0) = 0x00020005;
    xil_printf("Wrote: 0x%08x \n\r", *(baseaddr_p+0));
    xil_printf("Read: 0x%08x \n\r", *(baseaddr_p+1));
    int c = *(baseaddr_p+1);
    int a[2];
    int i;
    for(i=0;i<2;i++)
    {

    	if (c%2==0)
    	a[i]=0;
    	else
    		 a[i]=1;
    	c = c / 2;

    }
if(a[0]==1)
	xil_printf("Trojan Detected \n\n\r");
   // xil_printf("Read: %d \n\r", &(baseaddr_p+1));
    //xil_printf("End of test \n\n\r");
    return 0;
}
