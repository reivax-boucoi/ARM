<<<<<<< HEAD
#include "stm32f1xx.h"
// st-flash --reset write /home/user/Documents/STm32/timer/Release/timer.bin 0x8000000

void SystemClock_Config(void){
	RCC_ClkInitTypeDef clkinitstruct = {0};
	RCC_OscInitTypeDef oscinitstruct = {0};

	oscinitstruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	oscinitstruct.HSEState = RCC_HSE_ON;
	oscinitstruct.HSIState = RCC_HSI_OFF;
	oscinitstruct.PLL.PLLState = RCC_PLL_ON;
	oscinitstruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	oscinitstruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK) {
		while(1);
	}

	clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK |
			RCC_CLOCKTYPE_HCLK |
			RCC_CLOCKTYPE_PCLK1 |
			RCC_CLOCKTYPE_PCLK2);
	clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
	clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK) {
		while(1);
	}
}

int main(void){
	HAL_Init();
	SystemClock_Config();

	RCC->APB2ENR|=RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR|=RCC_APB2ENR_TIM1EN;

	TIM1->PSC=1000;
	TIM1->CCMR1|= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
	TIM1->CCMR1&= ~(TIM_CCMR1_OC1M_0);
	TIM1->CR1|=TIM_CR1_ARPE;
	TIM1->EGR|=TIM_EGR_UG;
	TIM1->CCR1=4;
	TIM1->ARR=7;

	AFIO->MAPR|=AFIO_MAPR_TIM1_REMAP_PARTIALREMAP;

	TIM1->CR1|=TIM_CR1_CEN;

	GPIOA->CRH|=GPIO_CRH_MODE8_0;
	GPIOA->CRH&=~(GPIO_CRH_MODE8_1 | GPIO_CRH_CNF8_0);

	GPIOC->CRH|=GPIO_CRH_MODE14_0 | GPIO_CRH_MODE13_0 | GPIO_CRH_CNF15_1;
	GPIOC->CRH&=~(GPIO_CRH_CNF13_0 | GPIO_CRH_CNF14_0
			| GPIO_CRH_CNF15_0 | GPIO_CRH_MODE15_0 | GPIO_CRH_MODE15_1);
	GPIOC->ODR|=GPIO_ODR_ODR15;

	GPIOC->BSRR|=GPIO_PIN_14 | GPIO_PIN_13 <<16;

	while (1) {
		if(TIM1->CNT < 32768){
			GPIOC->BSRR|=GPIO_PIN_13;
			//	GPIOA->BSRR|=GPIO_PIN_8;
		}else{
			GPIOC->BRR|=GPIO_PIN_13;
			//	GPIOA->BRR|=GPIO_PIN_8;
		}
	}
}
=======
#include "stm32f1xx.h"
// st-flash --reset write /home/user/Documents/STm32/timer/Release/timer.bin 0x8000000

void SystemClock_Config(void){
	RCC_ClkInitTypeDef clkinitstruct = {0};
	RCC_OscInitTypeDef oscinitstruct = {0};

	oscinitstruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	oscinitstruct.HSEState = RCC_HSE_ON;
	oscinitstruct.HSIState = RCC_HSI_OFF;
	oscinitstruct.PLL.PLLState = RCC_PLL_ON;
	oscinitstruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	oscinitstruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&oscinitstruct)!= HAL_OK) {
		while(1);
	}

	clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK |
			RCC_CLOCKTYPE_HCLK |
			RCC_CLOCKTYPE_PCLK1 |
			RCC_CLOCKTYPE_PCLK2);
	clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
	clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2)!= HAL_OK) {
		while(1);
	}
}

int main(void){
	HAL_Init();
	SystemClock_Config();

	RCC->APB2ENR|=RCC_APB2ENR_IOPCEN | RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR|=RCC_APB2ENR_TIM1EN;

	TIM1->PSC=1000;
	TIM1->CCMR1|= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE;
	TIM1->CCMR1&= ~(TIM_CCMR1_OC1M_0);
	TIM1->CR1|=TIM_CR1_ARPE;
	TIM1->EGR|=TIM_EGR_UG;
	TIM1->CCR1=4;
	TIM1->ARR=7;

	AFIO->MAPR|=AFIO_MAPR_TIM1_REMAP_PARTIALREMAP;

	TIM1->CR1|=TIM_CR1_CEN;

	GPIOA->CRH|=GPIO_CRH_MODE8_0;
	GPIOA->CRH&=~(GPIO_CRH_MODE8_1 | GPIO_CRH_CNF8_0);

	GPIOC->CRH|=GPIO_CRH_MODE14_0 | GPIO_CRH_MODE13_0 | GPIO_CRH_CNF15_1;
	GPIOC->CRH&=~(GPIO_CRH_CNF13_0 | GPIO_CRH_CNF14_0
			| GPIO_CRH_CNF15_0 | GPIO_CRH_MODE15_0 | GPIO_CRH_MODE15_1);
	GPIOC->ODR|=GPIO_ODR_ODR15;

	GPIOC->BSRR|=GPIO_PIN_14 | GPIO_PIN_13 <<16;

	while (1) {
		if(TIM1->CNT < 32768){
			GPIOC->BSRR|=GPIO_PIN_13;
				GPIOA->BSRR|=GPIO_PIN_8;
		}else{
			GPIOC->BRR|=GPIO_PIN_13;
				GPIOA->BRR|=GPIO_PIN_8;
		}
	}
}
>>>>>>> a632be4dd2ca83e4c444b42e08abcfeeacd5721b
