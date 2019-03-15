#ifndef AHB_LITE_SLAVE_H
#define AHB_LITE_SLAVE_H
declare ahb_lite_slave interface {
	/* Select */
	input HSEL;
	/* Address and control */
	input HADDR[32]; //address bus
	input HWRITE;
	input HSIZE[3];
	input HBURST[3];
	input HPROT[4];
	input HTRANS[2];
	input HMASTLOCK;
	input HREADY; 
	/* Data */
	input HWDATA[32]; 
	/* Global signal */
	input HRESETn; //active low
	input HCLK; //clock, rising edge 

	/* Transfer response */
	output HREADYOUT; //high (transfer is finished), low (extended transfer)
	output HRESP; //indicate failure(high) or success(low)
	/* Data */
	output HRDATA[32]; //read data bus

	/* easy-to-use interface */
	output address[32];
	output wdata[32];
	output byteen[3];
	input rdata[32];
	func_out mem_req_read(address, byteen);
	func_out mem_req_write(address, byteen, wdata);
	func_out done();
	func_in mem_wait();
	func_in mem_ok();
}
#endif
