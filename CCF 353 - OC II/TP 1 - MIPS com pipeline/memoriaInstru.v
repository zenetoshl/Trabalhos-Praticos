module memoriaInstru(reset, clk, addr, inst);
	input reset, clk;
    input wire [6:0] addr;
    output [31:0] inst;
    reg [31:0] memoriaInstru [255:0];
    assign inst = memoriaInstru[addr[6:2]];

    always @(posedge reset)
	 begin 
        $readmemb("program.bin",memoriaInstru);
    end
endmodule