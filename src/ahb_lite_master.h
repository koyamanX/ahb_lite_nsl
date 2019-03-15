#ifndef AHB_LITE_MASTER_H
#define AHB_LITE_MASTER_H

declare ahb_lite_master interface {

	/* transfer response */
	input HREADY;
	input HRESP;
	/* Global signals */
	input HRESETn; //reset signal
	input HCLK; //clock signal
	/* Data */
	input HRDATA[32]; //read data bus

	/* Address and control */
	output HADDR[32]; //32 bit address bus
	output HWRITE; //high(write transfer), low(read transfer)
	output HSIZE[3]; //size of transfer
	output HBURST[3]; /* for this implementation only single tranasfer is supported */
	output HPROT[4];  /* only [0] opcode fetch -> 0, data access -> 1 other field is hard wired to 0 */
	output HTRANS[2]; //transfer type, this implementation only support IDEL, NONSEQ transfer 
	output HMASTLOCK; //high on locked transfer? not supported
	/* Data */
	output HWDATA[32]; //write data bus

	/* easy-to-use interfaces */
	input address[32];
	input wdata[32];
	input byteen[3];
	input prot[4];
	output rdata[32];
	func_in read(address, byteen, prot);
	func_in write(address, byteen, prot, wdata);
	/* indicate end of transaction */
	func_out done();
	/* indicate no extended address phase */
	func_out ready();

}

#endif
