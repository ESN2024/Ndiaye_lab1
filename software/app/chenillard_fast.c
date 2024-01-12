#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "alt_types.h"
#include "sys/alt_sys_init.h"
#include <stdio.h>
#include <unistd.h>

int vitesse[4]={1000000,500000,250000,100000};
int i=0;
void chenillard()
{
	int data=0x01;

	for(int j=1;j<=8;j++)
	{
		data= data << 1;
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_0_BASE,data);//data
		usleep(vitesse[i]);		
		
	}
	data=0x01;
}
static void irqhandler(void * context, alt_u32 id)
{
	
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x01);
	i++;
	i=i%4 ;
	alt_printf("%d\n\r",i);
		
}

int main(void)
{
	// Configurer le bouton pour générer des interruptions
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_1_BASE, 0x1);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_1_BASE, 0x1);
	
	alt_irq_register( PIO_1_IRQ, NULL, (void*)irqhandler );
	while(1)
	{
		chenillard();	
	}
	return 0;
	
}