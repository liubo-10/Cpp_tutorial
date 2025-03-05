#include "STM32F10x_Lib.h"


void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);

void System_Init(void)
{
	RCC_Configuration();				//���ʱ����Դѡ���Լ�PLL��ϵͳʱ�ӳ�ʼ��,��ʹ��һЩʹ�õ���ģ��ʱ��
	GPIO_Configuration();				//��ʼ��һЩ�˿ڵĹ���,��Ҳ�����һЩģ������������������û����г�ʼ��	

	NVIC_Configuration();				//��ʼ��NVIC�ж�ϵͳ,�Լ�ʹ��һЩNVIC�ж�

	//��ʼ��ϵͳʱ�Ӷ�ʱ��
	//SysTick end of count event each 1ms with input clock equal to 9MHz (HCLK/8, default)
//	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
//	SysTick_SetReload(10240);//4);			//1000��/S		64M��ʱ��
	//Enable SysTick interrupt
//	SysTick_CounterCmd(SysTick_Counter_Enable);
	
}

//=======================================================================//
// ����: void RCC_Configuration(void)
// ����: ��ʼ��ϵͳʱ��,����ʱ����Դ�Լ�PLL�����Լ������û�ʹ�õ���ģ���
//		 ��ʱ��ʹ��
// ����: ��(����ͷ�ļ��������˶���)
// ���: ��
// ��ע: ��
//=======================================================================//

void RCC_Configuration(void)
{
	ErrorStatus HSEStartUpStatus;
	// RCC system reset(for debug purpose) //
	RCC_DeInit();
//	RCC_HSICmd(ENABLE);					//ʹ���ڲ���RC����

  	//Enable HSE //
	RCC_HSEConfig(RCC_HSE_ON);

	//Wait till HSE is ready
 	HSEStartUpStatus = RCC_WaitForHSEStartUp();

	if (HSEStartUpStatus == SUCCESS)
	{
    // Enable Prefetch Buffer
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

    //Flash 2 wait state
    FLASH_SetLatency(FLASH_Latency_2);

    //HCLK = SYSCLK/2
    RCC_HCLKConfig(RCC_SYSCLK_Div1);

    //PCLK2 = HCLK
    RCC_PCLK2Config(RCC_HCLK_Div2);

    //PCLK1 = HCLK
    RCC_PCLK1Config(RCC_HCLK_Div2);

    //PLLCLK = 8MHz/2 * 16 = 64 MHz
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_8);

    //Enable PLL 
    RCC_PLLCmd(ENABLE);

    //Wait till PLL is ready
    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
    {}

    //Select PLL as system clock source
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    // Wait till PLL is used as system clock source
    while (RCC_GetSYSCLKSource() != 0x08)
    {}
	}
	// Enable peripheral clocks --------------------------------------------------
//	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	/// GPIOA, GPIOB and SPI1 clock enable 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOG | RCC_APB2Periph_GPIOE |
    //                     RCC_APB2Periph_GPIOF|RCC_APB2Periph_GPIOB, ENABLE);
	// TIM3 clock enable //
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3|RCC_APB1Periph_USART3, ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); //RCC_APB1Periph_USART3
} 

//=======================================================================//
// ����: void GPIO_Configuration(void)
// ����: ϵͳʹ�õ��Ķ˿�
// ����: ��
// ���: ��
// ��ע: �����еĶ˿�Ҫ���ֹ���ģ��ĳ�ʼ�����������г�ʼ��,���û�ע�����
//=======================================================================//
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	//��PB12����Ϊ����˿�
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure); 

/*	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//|GPIO_Pin_8;//|GPIO_Pin_0;//|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//|GPIO_Pin_8;//|GPIO_Pin_0;//|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 |
                                GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure); 
  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 |
                                GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
                                GPIO_Pin_15;
	GPIO_Init(GPIOE, &GPIO_InitStructure);	 */
}

//=======================================================================//
// ����: void NVIC_Configuration(void)
// ����: ��ʼ��NVIC�ж�ϵͳ,��ʹ��һЩ�ж�
// ����: ��
// ���: ��
// ��ע: �����еĶ˿�Ҫ���ֹ���ģ��ĳ�ʼ�����������г�ʼ��,���û�ע�����
//=======================================================================//
void NVIC_Configuration(void)
{
//	NVIC_InitTypeDef NVIC_InitStructure;

#ifdef  VECT_TAB_RAM
	// Set the Vector Table base location at 0x20000000 
	NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
#else  // VECT_TAB_FLASH  
	// Set the Vector Table base location at 0x08000000 
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
#endif

	// 1 bit for pre-emption priority, 3 bits for subpriority 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

/*	// Configure and enable SPI1 interrupt
	NVIC_InitStructure.NVIC_IRQChannel = SPI2_IRQChannel;
	//NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = NVIC_PriorityGroup_2;
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);  */
	//Enable the DMA1 Channel 3 Interrupt
/*	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	// */
/*	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel2_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	*/
/*	NVIC_InitStructure.NVIC_IRQChannel = TIM1_TRG_COM_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQChannel;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_Init(&NVIC_InitStructure);	*/
	
//	NVIC_SystemHandlerPriorityConfig(SystemHandler_SysTick, 0, 0);
}	







