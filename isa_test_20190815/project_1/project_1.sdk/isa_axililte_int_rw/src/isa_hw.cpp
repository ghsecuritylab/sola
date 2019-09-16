
#include "isa_hw.h"

double what_time_is_it_now()
{
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        return 0;
    }
    return (double)time.tv_sec*1000000.0 + (double)time.tv_usec;
}

int ISA_FPGA(int mode, int isa_addr, int wdata, int fd_isa)
{
	int rdata = 0xFFFF;
	unsigned int ap_idle;
	unsigned int ap_done;
	unsigned int temp;

//	printf("wait for ilde start\n");
	while(1)
	{
		read(fd_isa, &temp, ISA_CTRL_BUS_ADDR_AP_CTRL);
//		printf("Read IDLE = 0x%x\n", temp);
		ap_idle = ((temp >> 2) & 0x1);
		if(ap_idle)
			break;
	}
//	printf("wait for ilde end\n");

	write(fd_isa,      &mode, ISA_CTRL_BUS_ADDR_ISA_MODE);//0x01 write; 0x02 read
	write(fd_isa,  &isa_addr, ISA_CTRL_BUS_ADDR_ISA_ADDR);
	if(mode == 0x01)
		write(fd_isa, &wdata, ISA_CTRL_BUS_ADDR_WDATA);

	temp = 0x1;
	write(fd_isa,      &temp, ISA_CTRL_BUS_ADDR_AP_CTRL);//Start
//	printf("wait for done start\n");
	while(1)
	{
		read(fd_isa,   &temp, ISA_CTRL_BUS_ADDR_AP_CTRL);
		ap_done = ((temp >> 1) & 0x1);
		if(ap_done)
			break;
	}
//	printf("wait for done end\n");

	if(mode == 0x02)
		read(fd_isa, &rdata, ISA_CTRL_BUS_ADDR_RDATA);

//	if(mode == 0x01)
//    	printf("[OUT] 0x%x = 0x%x\n", isa_addr, wdata);
//	else if(mode == 0x02)
//	{
//		if(wdata == rdata)
//			printf("[IN]  0x%x = 0x%x |Read 0x%x == 0x%x\n", isa_addr, wdata, rdata, wdata);
//		else
//			printf("[IN]  0x%x = 0x%x |Read 0x%x != 0x%x\n", isa_addr, wdata, rdata, wdata);
//	}


	return rdata;

}

//int ISA_FPGA(int mode, int isa_addr, int wdata)
//{
//	int rdata = 0xFFFF;
//	unsigned int ap_idle;
//	unsigned int ap_done;
//
//	unsigned long int PhysicalAddress = ISA_BASEADDR;
//	int map_len = 0x20;
//	int fd = open("/dev/mem", O_RDWR);
//
//	unsigned char *xbase_address;
//	xbase_address = (unsigned char *)mmap(NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)PhysicalAddress);
//	if(xbase_address == MAP_FAILED)
//	{
//		perror("1:Init Mapping memory for absolute memory access failed.\n");
//		return -1;
//	}
//
//	while(1)//Wait for IDLE
//	{
//		ap_idle = ((ReadReg(xbase_address, ISA_CTRL_BUS_ADDR_AP_CTRL) >> 2) && 0x1);
//		if(ap_idle)
//			break;
//	}
//
//	WriteReg(xbase_address, ISA_CTRL_BUS_ADDR_ISA_MODE, mode);//0x01 write; 0x02 read
//	WriteReg(xbase_address, ISA_CTRL_BUS_ADDR_ISA_ADDR, isa_addr);
//	if(mode == 0x01)
//		WriteReg(xbase_address, ISA_CTRL_BUS_ADDR_WDATA, wdata);
//
//	WriteReg(xbase_address, ISA_CTRL_BUS_ADDR_AP_CTRL, 0x1);//Start
//	while(1)
//	{
//		ap_done = ((ReadReg(xbase_address, ISA_CTRL_BUS_ADDR_AP_CTRL) >> 1) && 0x1);
//		if(ap_done)
//			break;
//	}
//	if(mode == 0x02)
//		rdata = ReadReg(xbase_address, ISA_CTRL_BUS_ADDR_RDATA);
//
//	munmap((void *)xbase_address, map_len);
//	close(fd);
//
//	if(mode == 0x01)
//    	printf("[OUT] 0x%x = 0x%x\n", isa_addr, wdata);
//	else if(mode == 0x02)
//	{
//		if(wdata == rdata)
//			printf("[IN]  0x%x = 0x%x |Read 0x%x == 0x%x\n", isa_addr, wdata, rdata, wdata);
//		else
//			printf("[IN]  0x%x = 0x%x |Read 0x%x != 0x%x\n", isa_addr, wdata, rdata, wdata);
//	}
//
//
//	return rdata;
//
//}
