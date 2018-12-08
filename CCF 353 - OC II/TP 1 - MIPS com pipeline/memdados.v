module memdados(clk, reset, address, write_data, mem_write, mem_read, read_data);
    input clk, reset, mem_write, mem_read;
    input [31:0] address, write_data;
    output wire [31:0] read_data;

    reg	[31:0] memory [255:0];

    assign read_data = memory[address[31:2]];

    always @(posedge clk) begin
        if (reset) begin
            $readmemh("dados.hex",memory);
        end
		if (mem_write) begin
			memory[address[17:2]] = write_data;
        end
    end


   
    
endmodule