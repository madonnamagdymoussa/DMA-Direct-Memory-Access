//#include <stdio.h>
#include "HC-05.h"
#include "GPIO.h"
#include "GPIO_config.h"
#include "GPTM_config.h"
#include "GPTM.h"
#include "DMA.h"
#include "UART.h"
u8_t charater1=0xAB;
u8_t *ptr_charater1=&charater1;


u8_t SourceBuffer_DMA[256]={0x01,0x02,0x03,0x04};
u8_t DestBuffer_DMA[256];

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

     /*=======================Initialization=======================*/
     UART_Initialization(&UARTChannel1_Config, GPIO_AFSELUARTConfig_ArrPtrStruct[1]);

      DMA_PeripheralInitialization();

      DMA_DisableChannelAttributes(DMA_ChannelsConfigTX[1]);

      DMA_EnableChannelAttributes(DMA_ChannelsConfigTX[1]);

      DMA_ConfigurePriority(SetHighPriorityChannel, DMAChannel_9);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_9);
      /*
       * Prior to starting a transfer, a μDMA channel must be enabled by setting the appropriate bit in the
         DMA Channel Enable Set (DMAENASET) register.

         At the end of a complete μDMA transfer, the controller automatically disables the channel.
       * */
      DMA_EnableChannel(DMAChannel_9);
      UART_Transmit_DMA(UART_Channel1,  ptr_charater1, DMAChannel_9);


     //*******************Code for Mem To Mem*******************
     /*
     DMA_PeripheralInitialization();

     DMA_ChannelControlStructureSet(Pt_DMAChannel30_MemToMem, SourceBuffer_DMA , DestBuffer_DMA );
     DMA_EnableChannelAttributes(Pt_DMAChannel30_MemToMem);
     DMA_AssignChannel(DMAChannel_30, EncodingNum_0);
     DMA_EnableChannel(DMAChannel_30);
     DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_30);*/


      while(1){


     }

}
