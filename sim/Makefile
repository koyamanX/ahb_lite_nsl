TOP=ahb_lite_slave_sim
CC=nsl2vl
VCC=iverilog
NSLOPT=-I$(SRCDIR)
VERIOPT=
SRCDIR=../src
VFILES=ahb_lite_master.v ahb_lite_slave.v
MASTER=ahb_lite_master
SLAVE=ahb_lite_slave
CLOCK_RESET_NAME=-clock_name HCLK -reset_name HRESETn -neg_res

$(MASTER).v: $(SRCDIR)/$(MASTER).nsl $(SRCDIR)/$(MASTER).h
	$(CC) $(NSLOPT) $(CLOCK_RESET_NAME) -o $@ $<
$(SLAVE).v: $(SRCDIR)/$(SLAVE).nsl $(SRCDIR)/$(SLAVE).h
	$(CC) $(NSLOPT) $(CLOCK_RESET_NAME) -o $@ $<
$(TOP).v: $(TOP).nsl
	$(CC) $(NSLOPT) -verisim2 -target $(TOP) -o $(TOP).v $(TOP).nsl
$(TOP).vvp: $(TOP).v $(VFILES)
	$(VCC) $(VERIOPT) -o $(TOP).vvp $(TOP).v $(VFILES)
$(TOP).vcd: $(TOP).vvp
	vvp $(TOP).vvp
sim: $(TOP).vvp
	vvp $(TOP).vvp
gtkwave: $(TOP).vcd
	gtkwave $(TOP).vcd $(SIG) &
clean:
	rm -f $(TOP).vcd $(TOP).vvp $(VFILES) $(TOP).v

