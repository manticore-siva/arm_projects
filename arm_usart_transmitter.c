////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM Assembly USART TRANSMITTER                                //
//   Date  : 28/04/2023                                                    //
//                                                                         // 
/////////////////////////////////////////////////////////////////////////////

#include "arm_config.h"

void rcc_config(void);
void port_config(void);
void usart_config(void);
void data_tx(unsigned char data);
void usar_data(unsigned char *u_data);
int main()
{
	unsigned char *a="School of linux\n\r";

	rcc_config();
	port_config();
    usart_config();

	usar_data(a);

	while(1);

}

void rcc_config(void)
{
	//USART1 clock enable
	RCC_APB2ENR |=0x10;

	//GPIOAEN: IO port A clock enable
	RCC_AHB1ENR |= 0x1; 
}
void port_config(void)
{
	//10: Alternate function mode PIN A9 TX 
	GPIOA_MODER &= ~(3<<18);
	GPIOA_MODER |= 1<<19;

	//GPIO port output speed register
	GPIOA_OSPEEDR &= ~(3<<18);
	GPIOA_OSPEEDR |= 1<<19;   // set as 10: High speed

	// 0111: AF7 GPIO alternate function high register 
	GPIOA_AFRH |= 0x70;
	
}
void usart_config(void)
{
	//Enable UE bit,M: Word length
	USART_CR1 &= ~(3<<12);
	USART_CR1 |= 1<<13;

	//number of stop bit 
	USART_CR2 &= ~(3<<12);
	USART_CR2 |= (1<<13);


	//select baud rate
	USART_BRR |= 0x3;  // fraction value = 3
	USART_BRR |= 104<<4; // mantissa value = 104


	//enable TE bit 
	USART_CR1 |= 0x8;

	//cheak sattus 			
	while(!(USART_SR & (1<<7)));  //waiting for idle pream complition 

}
void data_tx(unsigned char data)
{

	//Data register
	USART_DR =data;   // character a

	//cheak sattus 			
	while(!(USART_SR & (1<<6)));
	USART_SR &= ~(1<<6); //clear TC bit

}
void usar_data(unsigned char *u_data)
{
	while(*u_data)
	{
		data_tx(*u_data);
		u_data++;
	}

}
