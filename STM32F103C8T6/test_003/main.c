#include "stm32f10x.h"


void WaitForAMoment(uint32_t moment){
	volatile int i, j;

	for (i=0; i < moment; i++) {
		j ++;
	}
}

int main(void){
	
	RCC->APB2ENR |=RCC_APB2ENR_IOPCEN;
	RCC->APB2ENR	|= RCC_APB2ENR_IOPAEN; //activate port a io clock
	//RCC->APB1ENR |= RCC_APB1ENR_TI RCC_APB1ENR_TIM6EN;
	
	/*
	upcounting mode : from 0 to TIMw_ARR value
	OVF event : update event or TIMx_EGR UGbit
	
	*/
	GPIOC->CRH |=	GPIO_CRH_MODE13_1  ; // set to slow mode
	GPIOC->CRH &=~( GPIO_CRH_CNF13_0); // set to output mode
	GPIOA->CRL |=	GPIO_CRL_MODE0_1  ; // set to slow mode
	GPIOA->CRL &=~( GPIO_CRL_CNF0_0); // set to output mode
	
	while(1){


		GPIOC->BSRR |= GPIO_BSRR_BS13; //set on
		GPIOA->BSRR |= GPIO_BSRR_BR0;
		WaitForAMoment(1500000);
		GPIOC->BSRR |= GPIO_BSRR_BR13; //set off
		GPIOA->BSRR |= GPIO_BSRR_BS0;
		WaitForAMoment(1500000);

	}
}
/*
timer 6:
interrupt name : TIM6
*/
