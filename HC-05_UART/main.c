//#include <stdio.h>
#include "HC-05.h"
#include "GPIO.h"
#include "GPIO_config.h"
#include "GPTM_config.h"
#include "GPTM.h"
#include "DMA.h"
#include "UART.h"
u32_t charater1=0x55555555;
u32_t *ptr_charater1=&charater1;
//extern  u32_t* const SourceAddressPointerRegisters[32];
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
      UART_Init0ialization(&UARTChannel1_Config, GPIO_AFSELUARTConfig_ArrPtrStruct[1]);

      DMA_PeripheralInitialization();

      DMA_DisableChannelAttributes(DMA_ChannelsConfigTX[1]);

      DMA_EnableChannelAttributes(DMA_ChannelsConfigTX[1]);

      DMA_ConfigurePriority(SetHighPriorityChannel, DMAChannel_9);
      DMA_ConfigureChannelSoftwareRequest(EnableSoftwareRequest , DMAChannel_9);
      UART_Transmit_DMA(UART_Channel1,  ptr_charater1, DMAChannel_9);

      /*
       * Prior to starting a transfer, a μDMA channel must be enabled by setting the appropriate bit in the
         DMA Channel Enable Set (DMAENASET) register.

         At the end of a complete μDMA transfer, the controller automatically disables the channel.
       * */
      DMA_EnableChannel(DMAChannel_9);


      while(1){


        /* HC05_ReadChar(ptr_charater1);

         if (charater1=='D'){
             GPIO_WriteBitBandBits(Channel_1, PortF, OutputHigh);
             GPIO_WriteBitBandBits(Channel_2, PortF, OutputHigh);
             GPIO_WriteBitBandBits(Channel_3, PortF, OutputHigh);

             HC05_WriteString("Command D is received\n"  );
             HC05_WriteString("Bit band feature is used\n"  );
         }

        else if(charater1 == 'C'){

         GPIO_WriteBitBandBits(Channel_1, PortF, OutputLow);
         GPIO_WriteBitBandBits(Channel_2, PortF, OutputHigh);
         GPIO_WriteBitBandBits(Channel_3, PortF, OutputHigh);

         HC05_WriteString("Command C is received\n"  );
         HC05_WriteString("Bit band feature is used\n"  );


        }

        else if(charater1 == 'E'){
        GPIO_WriteBitBandBits(Channel_1, PortF, OutputLow);
        GPIO_WriteBitBandBits(Channel_2, PortF, OutputHigh);
        GPIO_WriteBitBandBits(Channel_3, PortF, OutputLow);

        HC05_WriteString("Command E is received\n"  );
        HC05_WriteString("Bit band feature is used\n"  );


        }


        else if(charater1 == 'F'){

             GPIO_WriteBitBandBits(Channel_1, PortF, OutputHigh);
             GPIO_WriteBitBandBits(Channel_2, PortF, OutputLow);
             GPIO_WriteBitBandBits(Channel_3, PortF, OutputLow);

             HC05_WriteString("Command F is received\n"  );
             HC05_WriteString("Bit band feature is used\n"  );


        }

        else if(charater1 == 'G'){
            GPIO_WriteBitBandBits(Channel_1, PortF, OutputLow);
            GPIO_WriteBitBandBits(Channel_2, PortF, OutputLow);
            GPIO_WriteBitBandBits(Channel_3, PortF, OutputHigh);

            HC05_WriteString("Command G is received\n"  );
            HC05_WriteString("Bit band feature is used\n"  );


         }*/


     }

}
