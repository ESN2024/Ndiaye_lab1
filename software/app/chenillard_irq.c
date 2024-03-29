#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "sys/alt_sys_init.h"
#include <stdio.h>
#include <unistd.h>

static void irqhandler(void * context, alt_u32 id)
{
	
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x0);
	alt_printf("salut\n\r");
	int data=0x01;

	for(int i=1;i<=8;i++)
	{
		data= data << 1;
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,data);//data
		usleep(500000);		
		
	}
	data=0x01;	
}

int main(void)
{
	// Configurer le bouton pour générer des interruptions
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0x1);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x1);
	
	alt_irq_register( PIO_1_IRQ, NULL, (void*)irqhandler );
	while(1)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x01);//data
		usleep(500000);	
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,0x00);//data
		usleep(500000);	
	}
	return 0;
	
}