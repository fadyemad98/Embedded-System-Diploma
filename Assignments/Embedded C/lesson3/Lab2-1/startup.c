#include<stdint.h>

extern int main(void);
extern unsigned int stack_top;
extern unsigned int E_text;
extern unsigned int S_data;
extern unsigned int E_data;
extern unsigned int S_bss;
extern unsigned int E_bss;

void Reset_Handler(void);
void Default_Handler(void)
{
	Reset_Handler();
}
void NMI_Handler(void)__attribute__((weak, alias("Default_Handler")));
void H_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".vectors"))) = {
(uint32_t) &stack_top,
(uint32_t) &Reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_Fault_Handler,
(uint32_t) &MM_Fault_Handler,
(uint32_t) &Bus_Fault,
(uint32_t) &Usage_Fault_Handler
};
void Reset_Handler(void)
{
	//copy data from Rom to Ram
	unsigned int Data_Size= (unsigned char*)&E_data - (unsigned char*)&S_data;
	unsigned char* P_src=(unsigned char*)&E_text;
	unsigned char* P_dst=(unsigned char*)&S_data;
	for (int i = 0; i < Data_Size; ++i)
	{
		*((unsigned char*) P_src++) = *((unsigned char*) P_dst++);
	}
	// init bss by zeros
	unsigned int Bss_Size= (unsigned char*)&E_bss - (unsigned char*)&S_bss;
	P_dst=(unsigned char*)&S_bss;
	for (int i = 0; i < Bss_Size; ++i)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}
	//jump to main
	main();
}




















