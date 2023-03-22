/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Authore Name : Sivaprakasam.v                                         //
//   Title : ARM Systic Delay LED Blinking used to RCC_PLL                 //
//   Date  : 28/02/2023                                                    //
//                                                                         // 
/////////////////////////////////////////////////////////////////////////////


#include "arm_config.h"
#define T0H 12
#define T1H 36
#define RES 11200

void rcc_config(void);
void timer11_pwm_config(void);
void port_config(void);

int main()
{
		//		unsigned int colour[]={12,12,12,12,12,12,12,12,36,36,36,36,36,36,36,36,12,12,12,12,12,12,12,12,0};
				unsigned int colour_code = 0x000001;
				unsigned int *ptr;
				rcc_config();
				port_config();
				int c;
				timer11_pwm_config();
                while(1)
                {
					for(unsigned int count=0;count<=0xff;count++)
					{
								
						for(c=24,TIM11_ARR=48;c; )
						{
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;               // clear UIF,CC1IF
							if(count & 1<<--c)
								TIM11_CCR1 = T1H;			// assign the ccr1 value
							else 
								TIM11_CCR1 = T0H;
						}
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;				// clear UIF,CC1IF
			
					TIM11_CCR1 = 0;
					TIM11_PSC = 100;
					TIM11_ARR = RES;
					while(!(TIM11_SR & 0X1));
					TIM11_PSC = 0;
					TIM11_SR &= ~0X3;				// clear UIF,CC1IF
					}

					for(unsigned int count=0;count<=0xff;count++)
					{
								
						for(c=24,TIM11_ARR=48;c; )
						{
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;               // clear UIF,CC1IF
							if(count<<8 & 1<<--c)
								TIM11_CCR1 = T1H;			// assign the ccr1 value
							else 
								TIM11_CCR1 = T0H;
						}
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;				// clear UIF,CC1IF
			
					TIM11_CCR1 = 0;
					TIM11_PSC = 100;
					TIM11_ARR = RES;
					while(!(TIM11_SR & 0X1));
					TIM11_PSC = 0;
					TIM11_SR &= ~0X3;				// clear UIF,CC1IF
					}

					for(unsigned int count=0;count<=0xff;count++)
					{
								
						for(c=24,TIM11_ARR=48;c; )
						{
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;               // clear UIF,CC1IF
							if(count<<16 & 1<<--c)
								TIM11_CCR1 = T1H;			// assign the ccr1 value
							else 
								TIM11_CCR1 = T0H;
						}
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;				// clear UIF,CC1IF
			
					TIM11_CCR1 = 0;
					TIM11_PSC = 100;
					TIM11_ARR = RES;
					while(!(TIM11_SR & 0X1));
					TIM11_PSC = 0;
					TIM11_SR &= ~0X3;				// clear UIF,CC1IF
					}

					for(unsigned int count=0;count<=0xff;count++)
					{
						unsigned int temp=count<<8 | count;
								
						for(c=24,TIM11_ARR=48;c; )
						{
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;               // clear UIF,CC1IF
							if(temp & 1<<--c)
								TIM11_CCR1 = T1H;			// assign the ccr1 value
							else 
								TIM11_CCR1 = T0H;
						}
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;				// clear UIF,CC1IF
			
					TIM11_CCR1 = 0;
					TIM11_PSC = 100;
					TIM11_ARR = RES;
					while(!(TIM11_SR & 0X1));
					TIM11_PSC = 0;
					TIM11_SR &= ~0X3;				// clear UIF,CC1IF
					}

					for(unsigned int count=0;count<=0xff;count++)
					{
						unsigned int temp=count<<16 | count;
								
						for(c=24,TIM11_ARR=48;c; )
						{
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;               // clear UIF,CC1IF
							if(temp & 1<<--c)
								TIM11_CCR1 = T1H;			// assign the ccr1 value
							else 
								TIM11_CCR1 = T0H;
						}
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;				// clear UIF,CC1IF
			
					TIM11_CCR1 = 0;
					TIM11_PSC = 100;
					TIM11_ARR = RES;
					while(!(TIM11_SR & 0X1));
					TIM11_PSC = 0;
					TIM11_SR &= ~0X3;				// clear UIF,CC1IF
					}

					for(unsigned int count=0;count<=0xff;count++)
					{
								
						unsigned int temp=count<<8| count<<16;

						for(c=24,TIM11_ARR=48;c; )
						{
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;               // clear UIF,CC1IF
							if(temp & 1<<--c)
								TIM11_CCR1 = T1H;			// assign the ccr1 value
							else 
								TIM11_CCR1 = T0H;
						}
							while(!(TIM11_SR & 0X1));
							TIM11_SR &= ~0X3;				// clear UIF,CC1IF
			
					TIM11_CCR1 = 0;
					TIM11_PSC = 100;
					TIM11_ARR = RES;
					while(!(TIM11_SR & 0X1));
					TIM11_PSC = 0;
					TIM11_SR &= ~0X3;				// clear UIF,CC1IF
					}
				}
}

void rcc_config(void)
{
                RCC_CR |= 1<<16 ; // HSE Enable

				while(!(RCC_CR & 1<<17));     // waiting for HSE ready flag

				RCC_CFGR &= ~0x7 <<10;              //PPRE1: APB1 = AHB/2
				RCC_CFGR |= 0x4 <<10;

                RCC_CFGR |= 0x01;                // System clock switch,: System clock switch status,AHB prescaler[system clock divided by nothing]
				while((RCC_CFGR & 0x3<<2) != 1<<2);  // 01: HSE oscillator used as the system clock
				
				RCC_PLLCFGR &= ~0XF37FFF;
				RCC_PLLCFGR |=  10<<24 | 1<<22 | 3<<16 | 192<<6 | 15<<0;  // for 80MHz , M=15,N=288,P=6 , PLL clock source HSE 1<<22 = 1,PLLQ = 10 to make  PLL48CK to 48MHz
				RCC_CR |= 1<<24;   // PLL ON
				while(!(RCC_CR & 1<<25)); //wait for PLL ready flag

                RCC_CFGR &= ~0x03;                // System clock switch to HSI 

				while(RCC_CR & 0x03<<2);            //wait for clock sourcr to switch to HSI
				RCC_CFGR |= 0x02;                // System clock switch to pll 
				while((RCC_CFGR & 0x3<<2) != 2<<2);                // System clock switch to pll 
				//GPIOBEN: IO port B clock enable
				RCC_AHB1ENR |= 1<<1;

				//Enable TIMER11
				RCC_APB2ENR |= 1<<18;

}

void port_config(void)
{

                GPIOB_MODER   &= ~(0xC<<16);        // clear bit
                GPIOB_MODER   |=  1<<19;            // 10: Alternate function mode
		//		GPIOB_OSPEEDR &= ~0x3<<18;          // speed register clear
				GPIOB_OSPEEDR |=  0x3<<18;            // 10: high speed
				GPIOB_PUPDR   |=  1<<19;            // 10: Pull-down

				//GPIO alternate function high register (GPIOx_AFRH)
				GPIOB_AFRH &= ~0xf0;   //clear the values
				GPIOB_AFRH |= 0x30;    // load the 0011: AF3 values
}

void timer11_pwm_config(void)
{
	//  CC1E:0: Off - OC1 is not active 
	TIM11_CCER &= ~(1<<0);

	// OC1PE:0 Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the new value is taken in account immediately. 
	TIM11_CCMR1 &= ~ (1<<3);

	// CC1S:00 channel is configured as output
	TIM11_CCMR1 &= ~ 0x3;

	// OC1M: 110: PWM mode 1 - Channel 1 is active as long as TIMx_CNT < TIMx_CCR1 else inactive
	TIM11_CCMR1 |= 0x60;

	// OC1FE: Output compare 1 fast enable
	TIM11_CCMR1 |= 1<<2;

	// CCR1[15:0]: Capture/Compare value = 8
	TIM11_CCR1 &= ~0xffff;  // clear the register
	TIM11_CCR1 |= 12;        // assign the ccr1 value

	//ARPE: Auto-reload preload enable
	TIM11_CR1 |= 1<<7;

	// ARR[15:0]: Auto-reload value = 30
	TIM11_ARR  &= ~ 0xffff;  // clear the register
	TIM11_ARR  |= 36;       // assign arr value

	// PSC[15:0]: Prescaler value = 0
	TIM11_PSC &= ~0xffff;   // clear the register
	TIM11_PSC |= 0;        // assign pse value

	//CNT[15:0]: Counter value = 0
	TIM11_CNT |= 0;

	// CC1P: Capture/Compare 1 output Polarity = 0: OC1 active high
	TIM11_CCER &= ~0x2;

	// CC1NP: Capture/Compare 1 complementary output Polarity = 0:CC1 channel configured as output: CC1NP must be kept cleared.
	TIM11_CCER &= ~0x8;

	// CC1E: Capture/Compare 1 output enable.
	TIM11_CCER |= 0x1;

	// OC1PE: Output compare 1 fast enable
	TIM11_CCMR1 |=  1<<3;

	// UG: Update generation 1
	TIM11_EGR |= 0x3;

	// CEN: Counter enable
	TIM11_CR1 |= 0x1;
}
