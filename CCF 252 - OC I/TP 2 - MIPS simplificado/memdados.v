module dataMem(clk, reset, address, write_data, mem_write, read_data);
    input wire clk, reset, mem_write;
    input wire [31:0] address, write_data;
    output wire [31:0] read_data;

    reg	[31:0] memory [1023:0];

	assign read_data = memory[address[11:2]>>2];

    always @(negedge clk) begin
        if (reset) begin
            $readmemh("dados.bin",memory);
        end
		  else if (mem_write) begin
			memory[address[17:2]>>2] <= write_data[31:0];
        end
    end
    
endmodule