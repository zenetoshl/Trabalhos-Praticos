


module ID(clk, reset, Hazard, IF_ID_Inst, IF_ID_NewPC, RegWrite, MEM_WB_Writereg, MEM_WB_Writedata, 
                CTR_bitsout, npcout, rdata1out, rdata2out, s_extendout, instrout_2, instrout_1, opcode, rsout, rtout, CTR_bits);  
  input clk, reset;
  input [31:0] IF_ID_Inst, IF_ID_NewPC, MEM_WB_Writedata;
  input [4:0] MEM_WB_Writereg;
  input RegWrite, Hazard;
  output [8:0] CTR_bitsout;
  output [31:0] npcout, rdata1out, rdata2out, s_extendout;
  output [4:0] instrout_2, instrout_1;
  output [5:0] opcode;
  output wire [4:0] rsout, rtout;
  wire [4:0] rs, rt;
  wire [15:0] imediato;
  wire [4:0] instr_2, instr_1;

  wire [31:0] read1, read2, sinalEx;
  output wire [8:0] CTR_bits;

  // dividindo a instrucao:
  assign opcode = IF_ID_Inst[31:26];
  assign rs = IF_ID_Inst[25:21];
  assign rt = IF_ID_Inst[20:16];
  assign imediato = IF_ID_Inst[15:0];
  assign instr_2 = IF_ID_Inst[20:16];
  assign instr_1 = IF_ID_Inst[15:11];
  
  
  control control1 (opcode, Hazard, CTR_bits);

  bancoReg reg1 (clk, rs, rt, RegWrite, MEM_WB_Writereg, MEM_WB_Writedata, read1, read2);

  ExtensorSinal sinal_EX (imediato, sinalEx);

  ID_EX id_ex_pipeline (clk, reset, CTR_bits, IF_ID_NewPC, read1, read2, sinalEx, instr_2, instr_1,rs,rt, // Inputs
                        CTR_bitsout, npcout, rdata1out, rdata2out, s_extendout, instrout_2, instrout_1, rsout, rtout); // Outputs

endmodule