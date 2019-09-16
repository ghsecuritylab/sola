
#include "sobel_hw.h"

//void PR_Decoupler(int turn)
//{
//	unsigned long int PhysicalAddress = 0x43c00000;
//	int map_len = 0x60;
//	int fd = open("/dev/mem", O_RDWR);
//
//	unsigned char *xsobel_base_address;
//	xsobel_base_address = (unsigned char *)mmap(NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)PhysicalAddress);
//	if(xsobel_base_address == MAP_FAILED)
//	{
//		perror("Sobel Init Mapping memory for absolute memory access failed.\n");
//		return;
//	}
//
//    printf("status: %x\n", ReadReg(xsobel_base_address, 0));
//    printf("turn %d\n", turn);
//
//	WriteReg(xsobel_base_address, 0, turn);
//
//
//    printf("status %d\n", ReadReg(xsobel_base_address, 0));
//
//	munmap((void *)xsobel_base_address, map_len);
//	close(fd);
//}

void SOBEL_HW(int ncols, int nrows)
{
//	PR_Decoupler(0);
//	sleep(1);
	unsigned long int PhysicalAddress = SOBEL_BASEADDR;
	int map_len = 0x60;
	int fd = open("/dev/mem", O_RDWR);

	unsigned char *xsobel_base_address;
	xsobel_base_address = (unsigned char *)mmap(NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)PhysicalAddress);
	if(xsobel_base_address == MAP_FAILED)
	{
		perror("Sobel Init Mapping memory for absolute memory access failed.\n");
		return;
	}


    printf("ISR %x\n", ReadReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_ISR));

    printf("rows %d\n", nrows);
	printf("cols %d\n", ncols);

	WriteReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_ROWS_DATA, nrows);
	WriteReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_COLS_DATA , ncols);

	WriteReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_IER , 0x1);
	WriteReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_GIE , 0x1);

    printf("rows %d\n", ReadReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_ROWS_DATA));
	printf("cols %d\n", ReadReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_COLS_DATA));

	WriteReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_AP_CTRL, 0x1);//start

	printf("AP_CTRL %x\n", ReadReg(xsobel_base_address, XSOBEL_FILTER_CTRL_BUS_ADDR_AP_CTRL));

	munmap((void *)xsobel_base_address, map_len);
	close(fd);
}

void DMA_HW(int ncols, int nrows,unsigned long mm2s_addr,unsigned long s2mm_addr)
{
	unsigned long int PhysicalAddress = DMA_BASEADDR;
	int map_len = 0x80;
	int fd = open("/dev/mem", O_RDWR);

	unsigned char *dma_address;
	dma_address = (unsigned char *)mmap(NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)PhysicalAddress);
	if(dma_address == MAP_FAILED)
	{
		perror("DMA Init Mapping memory for absolute memory access failed.\n");
		return;
	}

//#define MM2S_DMACR     0x00
//#define MM2S_DMASR     0x04
//#define MM2S_SA        0x18
//#define MM2S_LENGTH    0x28  //start
//
//#define S2MM_DMACR     0x30
//#define S2MM_DMASR     0x34
//#define S2MM_DA        0x48
//#define S2MM_LENGTH    0x58 //start

	printf("MM2S_DMACR %x\n", ReadReg(dma_address, MM2S_DMACR));
	printf("S2MM_DMACR %x\n", ReadReg(dma_address, S2MM_DMACR));

	WriteReg(dma_address, MM2S_DMACR, ReadReg(dma_address, MM2S_DMACR)|0x4);	//reset

	printf("MM2S_DMACR %x\n", ReadReg(dma_address, MM2S_DMACR));
	printf("S2MM_DMACR %x\n", ReadReg(dma_address, S2MM_DMACR));

	WriteReg(dma_address, MM2S_SA, mm2s_addr);
	WriteReg(dma_address, S2MM_DA, s2mm_addr);

	printf("MM2S_SA %x\n", ReadReg(dma_address, MM2S_SA));
	printf("S2MM_DA %x\n", ReadReg(dma_address, S2MM_DA));


	WriteReg(dma_address, MM2S_DMACR, ReadReg(dma_address, MM2S_DMACR)|0x1001);
	WriteReg(dma_address, S2MM_DMACR, ReadReg(dma_address, S2MM_DMACR)|0x1001);

	printf("MM2S_DMACR %x\n", ReadReg(dma_address, MM2S_DMACR));
	printf("S2MM_DMACR %x\n", ReadReg(dma_address, S2MM_DMACR));

	//start
	WriteReg(dma_address, S2MM_LENGTH, nrows*ncols*4);
	WriteReg(dma_address, MM2S_LENGTH, nrows*ncols*4);

	printf("S2MM_LENGTH %d\n", ReadReg(dma_address, S2MM_LENGTH));
	printf("MM2S_LENGTH %d\n", ReadReg(dma_address, MM2S_LENGTH));

	unsigned int ap_done;

//	printf("MM2S_DMASR %x\n", ReadReg(dma_address, MM2S_DMASR));
//	printf("S2MM_DMASR %x\n", ReadReg(dma_address, S2MM_DMASR));

	while(1)
	{
		ap_done = ((ReadReg(dma_address, MM2S_DMASR) >> 1) && 0x1);
		if(ap_done)
		{
			 break;
		}
	}
	printf("MM2S_DMASR idle\n");
	while(1)
	{
		ap_done = ((ReadReg(dma_address, S2MM_DMASR) >> 1) && 0x1);
		if(ap_done)
		{
			 break;
		}
	}
	printf("S2MM_DMASR idle\n");

	printf("MM2S_DMASR %x\n", ReadReg(dma_address, MM2S_DMASR));
	printf("S2MM_DMASR %x\n", ReadReg(dma_address, S2MM_DMASR));

	WriteReg(dma_address, MM2S_DMASR, ReadReg(dma_address, MM2S_DMASR)|0x1000);
	WriteReg(dma_address, S2MM_DMASR, ReadReg(dma_address, S2MM_DMASR)|0x1000);

	printf("MM2S_DMASR %x\n", ReadReg(dma_address, MM2S_DMASR));
	printf("S2MM_DMASR %x\n", ReadReg(dma_address, S2MM_DMASR));

	WriteReg(dma_address, MM2S_DMASR, ReadReg(dma_address, MM2S_DMASR)|0x5000);
	WriteReg(dma_address, S2MM_DMASR, ReadReg(dma_address, S2MM_DMASR)|0x5000);

	printf("MM2S_DMASR %x\n", ReadReg(dma_address, MM2S_DMASR));
	printf("S2MM_DMASR %x\n", ReadReg(dma_address, S2MM_DMASR));

//    printf("rows %d\n", ReadReg(dma_address, XSOBEL_FILTER_CONTROL_BUS_ADDR_ROWS_DATA));
//	printf("cols %d\n", ReadReg(dma_address, XSOBEL_FILTER_CONTROL_BUS_ADDR_COLS_DATA));


	munmap((void *)dma_address, map_len);
	close(fd);
}
