

module MEM(clk, reset, bitsCtr, resultAlu, read2, entradaMUX5in, 
                                          saidaBitsCtr, saidaRead, ALUmem, Mwrite_reg);
    input clk, reset;
    input [4:0] bitsCtr, entradaMUX5in;
    input [31:0] resultAlu, read2;
    output [1:0] saidaBitsCtr;
    output [31:0] saidaRead, ALUmem;
    output [4:0] Mwrite_reg;

    wire [31:0] read_data;
    
    memdados datamem (clk, reset, resultAlu, read2,
                        bitsCtr[2] /*MemWrite*/, bitsCtr[3] /*MemRead*/, read_data);

    MEM_WB mem_wb_pipeline (clk, reset, bitsCtr, read_data, resultAlu, entradaMUX5in,
                            saidaBitsCtr, saidaRead, ALUmem, Mwrite_reg);
                            
endmodule