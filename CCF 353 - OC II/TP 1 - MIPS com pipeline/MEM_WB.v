module MEM_WB(clk, reset, bitsCtr, readD, resultadoUla, escreveReg, saidaBitsCtr, saidaReadD, saidaResUla, saidaEReg );


	input clk, reset;
	input [4:0] bitsCtr;
	input [31:0] readD, resultadoUla;
	input [4:0] escreveReg;
	output reg [31:0] saidaReadD;
	output reg [31:0] saidaResUla;
	output reg [1:0] saidaBitsCtr;
	output reg [4:0 ]saidaEReg;
	

	always @(posedge clk or posedge reset)begin
		if(reset) begin
			saidaResUla <= 0;
			saidaBitsCtr <= 0;
			saidaEReg <= 0;
		end
		else begin
			saidaResUla <= resultadoUla;
			saidaBitsCtr <= bitsCtr;
			saidaEReg <= escreveReg;
			saidaReadD <= readD;
		end
	end
	
endmodule	

