#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "sys/alt_sys_init.h"
#include <stdio.h>
#include <unistd.h>

int time=20000;
int data=0x01;

static void irqhandler_btn(void * context, alt_u32 id);
static void irqhandler_switch(void * context, alt_u32 id);

void chenillard();


void chenillard()
{

	while (data != 0x80)
    {
		data= data << 1;
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,data);//data
		usleep(time);		
		
	}

	while (data != 0x01)
    {
		data= data >> 1;
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,data);//data
		usleep(time);		
		
	}
}
static void irqhandler_btn(void * context, alt_u32 id)
{
	time = 0;
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0x01);		
}

static void irqhandler_switch(void * context, alt_u32 id)
{
	int SW = 0;

	SW = IORD_ALTERA_AVALON_PIO_DATA(PIO_1_BASE);

    time = SW * 20000;

    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x0F);		
}

int main(void)
{
	// Configurer le bouton pour générer des interruptions
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_2_BASE, 0x1);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_2_BASE, 0x1);

	// Configurer les switch pour générer des interruptions
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0x0F);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x0F);
	
	alt_irq_register( PIO_2_IRQ, NULL, (void*)irqhandler_btn );
	alt_irq_register( PIO_1_IRQ, NULL, (void*)irqhandler_switch );

	while(1)
	{
		chenillard();
	}

	return 0;
	
}
