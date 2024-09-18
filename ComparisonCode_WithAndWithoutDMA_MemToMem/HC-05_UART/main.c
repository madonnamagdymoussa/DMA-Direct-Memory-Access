//#include <stdio.h>
#include "HC-05.h"
#include "GPIO.h"
#include "GPIO_config.h"
#include "GPTM_config.h"
#include "GPTM.h"
#include "DMA.h"
#include "UART.h"
#include "NVIC.h"

#include <stdio.h>
#include <stdlib.h>

u8_t charater1=0xAB;
u8_t *ptr_charater1=&charater1;

u8_t SourceBuffer_DMA[1024];
u8_t DestBufferA[1];
u8_t DestBufferB[1];
u8_t DestBuffer_DMA[1024];


u32_t ListA[1]={0xAB};
u32_t ListB[1]={0xCD};
u32_t ListC[1]={0xEF};


u32_t ListD[2]={0xAAABCBDD,0XFF223344};
u32_t ListE[2]={0x34567891,0x11778899};
u32_t ListF[2]={0x66557799,0xEE77AAD3};

u32_t ListDest[6];
u32_t IndexCounter=0;

int main(void)
{

    /*****************************Global Interrupt Enable****************************/
     __asm("  CPSIE  I");

     /*****************************Output Pin used for logical Analyzer ****************************/
      GPIO_ConfigureOutputPin(&GPIO_ConfigurePin_PF1);


    /***************************** Initialize the Source Buffer with Random Number ****************************/
     for(IndexCounter=0;IndexCounter<1024;IndexCounter++){
         SourceBuffer_DMA[IndexCounter]=rand();
     }

    //*******************Code for Mem To Mem DMA *******************
    DMA_PeripheralInitialization();
    DMA_ChannelControlStructureSet(Pt_DMAChannel30_MemToMem, &SourceBuffer_DMA[1023] , &DestBuffer_DMA[1023] );
    DMA_EnableChannelAttributes(Pt_DMAChannel30_MemToMem);
    DMA_AssignChannel(DMAChannel_30, EncodingNum_0);
    DMA_EnableChannel(DMAChannel_30);
    DMA_ConfigurePeripheralInterrupt(EnableInterrupt);
    DMA_ConfigureChannelInterrupt(EnableInterrupt, DMAChannel_30);
    GPIO_WriteBitBandBits(Channel_1, PortF, OutputLow);
    GPIO_WriteBitBandBits(Channel_1, PortF, OutputHigh);
    DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_30);



    /*****************************************Copy data from Source to destination using Software **********************************************/
    /* GPIO_WriteBitBandBits(Channel_1, PortF, OutputLow);
     GPIO_WriteBitBandBits(Channel_1, PortF, OutputHigh);
     for(IndexCounter=0;IndexCounter<1024;IndexCounter++){

         DestBuffer_DMA[IndexCounter] =SourceBuffer_DMA[IndexCounter];
     }
     GPIO_WriteBitBandBits(Channel_1, PortF, OutputLow);*/


     //*******************Code for Mem To pheripheral Transmit *******************
     /* UART_Initialization(&UARTChannel1_Config, GPIO_AFSELUARTConfig_ArrPtrStruct[1]);

      DMA_PeripheralInitialization();

      DMA_EnableChannelAttributes(DMA_ChannelsConfigTX[1]);

      DMA_ConfigurePriority(SetHighPriorityChannel, DMAChannel_23);

      DMA_ConfigurePeripheralInterrupt(EnableInterrupt);

      UART_Transmit_DMA(UART_Channel1,  &SourceBuffer_DMA[0], DMAChannel_23);
      DMA_EnableChannel(DMAChannel_23);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_23);*/


      //*******************Code for Mem To pheripheral Receive *******************

      /*DMA_EnableChannelAttributes(DMA_ChannelsConfigRX[1]);

       UART_DMA_Reload_PrimaryControlStructure(UART_Channel1, &DestBufferA[0]);
       UART_DMA_Reload_AlternateControlStructure(UART_Channel1, &DestBufferB[0]);

      UART_Receive_DMA(UART_Channel1);
      DMA_EnableChannel(DMAChannel_22);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);
      DMA_ConfigureChannelInterrupt(EnableInterrupt, DMAChannel_22);*/


      //*******************Code for Memory Scatter Gather *******************
      /*DMA_PeripheralInitialization();
      DMA_EnableChannelAttributes(Pt_DMAChannel28_MemToMem);
      DMA_ConfigurePriority(SetHighPriorityChannel, DMAChannel_28);
      DMA_ConfigurePeripheralInterrupt(EnableInterrupt);
      DMA_ChannelScatterGatherSet(Pt_DMAChannel28_MemToMem);
      DMA_ConfigureChannelInterrupt(EnableInterrupt, DMAChannel_28);
      DMA_EnableChannel(DMAChannel_28);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_28);*/

      //*******************Code for Peripheral Scatter Gather *******************
      /*UART_Initialization(&UARTChannel1_Config, GPIO_AFSELUARTConfig_ArrPtrStruct[1]);
      DMA_PeripheralInitialization();
      UART_Transmit_DMA(UART_Channel1);
      DMA_EnableChannelAttributes(Pt_DMAChannel29_MemToMem);
      DMA_ConfigurePriority(SetHighPriorityChannel, DMAChannel_29);
      DMA_ChannelPeripheralScatterGatherSet(Pt_DMAChannel29_MemToMem);
      DMA_EnableChannel(DMAChannel_29);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_29);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_29);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_29);*/


    while(1){



        /* UART_DMA_Reload_PrimaryControlStructure(UART_Channel1, &DestBufferA[0]);
        DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);

        UART_DMA_Reload_AlternateControlStructure(UART_Channel1, &DestBufferB[0]);
        DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_22);*/

     }

}
