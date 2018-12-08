

module Pipeline (clk , reset, alu_resultexec);
	input wire clk, reset;
	output wire [31:0] alu_resultexec;
    wire [31:0] IF_ID_IR, IF_ID_NPC, npcdec, rdata1outdec, rdata2outdec, s_extendoutdec; // DECODE
    wire [31:0] add_resultexec, rdata2outexec; // EXECUTE
    wire [31:0] Read_dataoutmem, mem_ALU_result;   // MEM
    wire [8:0] CTR_bitsdec;
    wire [4:0] instrout_2016dec, instrout_1511dec, CTR_bitsexec, five_bit_muxoutexec, MEM_WB_Writereg;
    wire [1:0]  CTR_bitsmem;
    wire zeroexec, RegWrite;
    
    wire EX_MEM_PCSrc;
    wire [5:0] opcode;
    wire [31:0] MEM_WB_Writedata;
    wire [4:0] rs, rt, writeRE;
    wire [1:0] fowardEA, fowardEB; 
    wire [8:0] CTR_bits;
    wire Hazard;

    IF i_f (clk, reset, Hazard, add_resultexec, EX_MEM_PCSrc, IF_ID_IR, IF_ID_NPC);  // clock, EX_MEM_NPC, IF_ID_IR, IF_ID_NPC

    ID i_d (clk, reset, Hazard, IF_ID_IR, IF_ID_NPC, RegWrite, MEM_WB_Writereg, MEM_WB_Writedata, // Inputs
                            CTR_bitsdec, npcdec, rdata1outdec, rdata2outdec, s_extendoutdec, instrout_2016dec, instrout_1511dec, opcode, rs, rt, CTR_bits);  // Outputs

    EX execute (clk, reset, CTR_bitsdec, npcdec, rdata1outdec, rdata2outdec, s_extendoutdec, instrout_2016dec, instrout_1511dec, opcode,  fowardEA, fowardEB, MEM_WB_Writedata, // Inputs
                            CTR_bitsexec, add_resultexec, zeroexec, alu_resultexec, rdata2outexec, five_bit_muxoutexec);

    MEM memory (clk, reset, CTR_bitsexec, alu_resultexec, rdata2outexec, five_bit_muxoutexec, // Inputs
                            CTR_bitsmem, Read_dataoutmem, mem_ALU_result, MEM_WB_Writereg);                 // Outputs
                            
    WB writeback (CTR_bitsmem, Read_dataoutmem, mem_ALU_result, MEM_WB_Writedata);
 
    hazard1 hzrd(IF_ID_IR[25:21], IF_ID_IR[20:16], rt, CTR_bitsdec[3], Hazard);
    // (RsD, RtD, RtE, Memread, Hazard);
    
    fowarding fwrd(rs, rt, five_bit_muxoutexec, CTR_bitsexec[1], MEM_WB_Writereg, CTR_bitsmem[1], fowardEA, fowardEB);

    assign RegWrite = CTR_bitsmem[1];

    assign EX_MEM_PCSrc = zeroexec & CTR_bitsexec[4];
endmodule