

module WB(bitsCtr, read_data, ALUmem, wb_data);
    input [1:0] bitsCtr;
    input [31:0] read_data, ALUmem;
    output wire [31:0] wb_data;
    
    MUX muxwb (read_data, ALUmem, bitsCtr[0] /*MemToReg*/, wb_data);
endmodule