module EX_MEM(clk,reset,bitsCtr, saidaAdd, zeroUla,
				saidaUla,read2,saidaMux,saidaBitsCtr,resultadoAdd,zero,resultadoUla,saidaRead2,saidaMux5b);

input clk,reset;
input[31:0] saidaAdd, saidaUla,read2;
input[4:0]bitsCtr, saidaMux;
input zeroUla;

output reg [4:0] saidaBitsCtr, saidaMux5b;
output reg [31:0] resultadoAdd, resultadoUla, saidaRead2;
output reg zero;

always @(posedge clk or posedge reset)begin
	if (reset) begin
		saidaBitsCtr <= 0;
		resultadoAdd <= 0;
		resultadoUla <= 0;
		saidaRead2 <= 0;
		saidaMux5b <= 0;
		zero <= 0;
	end
	else begin
		saidaBitsCtr <= bitsCtr;
		resultadoAdd <= saidaAdd;
		resultadoUla <= saidaUla;
		saidaRead2 <= read2;
		saidaMux5b <= saidaMux;
		zero <= zeroUla;
	end
end

endmodule





