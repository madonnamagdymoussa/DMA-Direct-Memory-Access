//#include <stdio.h>
#include "HC-05.h"
#include "GPIO.h"
#include "GPIO_config.h"
#include "GPTM_config.h"
#include "GPTM.h"
#include "DMA.h"
#include "UART.h"
#include "NVIC.h"
u8_t charater1=0xAB;
u8_t *ptr_charater1=&charater1;

u8_t SourceBuffer_DMA[256]={0xD1,0xC2,0xB3,0xAF};
u8_t DestBufferA[1];
u8_t DestBufferB[1];
u8_t DestBuffer_DMA[3];

//u8_t DMA_DestBufferA[4]={0xAB,0xCD,0x33,0x44};

int main(void)
{

    /*****************************Global Interrupt Enable****************************/
     __asm("  CPSIE  I");


    //GPIO_WriteBitBandBits(Channel_1, PortF, OutputHigh);

      //GPTM_InitializeDelayMode(GPIO_TimerAFSELConfig_ArrPtrStruct[0], GPTM_Config_ArrPtrStruct[0]);
     // HC05_Initialization();

      /*GPIO_ConfigureOutputPin(&GPIO_ConfigurePin_PF2);
      GPIO_ConfigureOutputPin(&GPIO_ConfigurePin_PF1);
      GPIO_ConfigureOutputPin(&GPIO_ConfigurePin_PF3);

      GPTM_GenerateDelay(GPTM_Config_ArrPtrStruct[0], 10, milli_Sec);*/

     //*******************Code for Mem To pheripheral Transmit *******************
      UART_Initialization(&UARTChannel1_Config, GPIO_AFSELUARTConfig_ArrPtrStruct[1]);

      DMA_PeripheralInitialization();

      DMA_EnableChannelAttributes(DMA_ChannelsConfigTX[1]);

      DMA_ConfigurePriority(SetHighPriorityChannel, DMAChannel_23);

      //DMA_ConfigurePeripheralInterrupt(EnableInterrupt);
      //DMA_ConfigureChannelInterrupt(EnableInterrupt, DMAChannel_23);
      //DMA_ConfigureChannelInterrupt(EnableInterrupt, DMAChannel_22);

      UART_Transmit_DMA(UART_Channel1,  &SourceBuffer_DMA[0], DMAChannel_23);
      DMA_EnableChannel(DMAChannel_23);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_23);


      //*******************Code for Mem To pheripheral Receive *******************

      DMA_EnableChannelAttributes(DMA_ChannelsConfigRX[1]);

       UART_DMA_Reload_PrimaryControlStructure(UART_Channel1, &DestBufferA[0]);
       UART_DMA_Reload_AlternateControlStructure(UART_Channel1, &DestBufferB[0]);

      UART_Receive_DMA(UART_Channel1);
      DMA_EnableChannel(DMAChannel_22);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);
      //DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);


      //*******************Code for Mem To Mem*******************

     /*DMA_PeripheralInitialization();

     DMA_ChannelControlStructureSet(Pt_DMAChannel30_MemToMem, &SourceBuffer_DMA[3] , &DestBuffer_DMA[3] );
     DMA_EnableChannelAttributes(Pt_DMAChannel30_MemToMem);
     DMA_AssignChannel(DMAChannel_30, EncodingNum_0);
     DMA_EnableChannel(DMAChannel_30);
     DMA_ConfigurePeripheralInterrupt(EnableInterrupt);
     DMA_ConfigureChannelInterrupt(EnableInterrupt, DMAChannel_30);
     DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_30);*/


    while(1){

        UART_DMA_Reload_PrimaryControlStructure(UART_Channel1, &DestBufferA[0]);
        DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);

        UART_DMA_Reload_AlternateControlStructure(UART_Channel1, &DestBufferB[0]);
        DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);


        //DMA_EnableChannelAttributes(DMA_ChannelsConfigRX[1]);
        /*DMA_EnableChannelAttributes(DMA_ChannelsConfigRX[1]);

        UART_DMA_Reload_AlternateControlStructure(UART_Channel1, &DestBufferB[0]);

        UART_Receive_DMA(UART_Channel1);
        DMA_EnableChannel(DMAChannel_22);
       DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);*/

        /*u8_t Dataread=0;
        Dataread=DestBufferA[0];
        Dataread++;
        DMA_EnableChannelAttributes(DMA_ChannelsConfigRX[1]);
        UART_DMA_Reload_AlternateControlStructure(UART_Channel1, &DestBufferB[0]);

        UART_Receive_DMA(UART_Channel1);
        DMA_EnableChannel(DMAChannel_22);
        DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);*/


     }

}
