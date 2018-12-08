
module EX(clk, reset, bitsCtr, newpc, read1, read2, extensor, instr_2, instr_1, opcode, ForwardA, ForwardB, ResultW,
                 saidaBitsCtr, resultadoAdd, zero, resultadoAlu, rdata2out, saidaMux5b);

  input clk, reset;
  input [1:0] ForwardB, ForwardA;
  input [31:0] ResultW;
  input [8:0] bitsCtr;
  input [31:0] newpc, read1, read2, extensor;
  input [4:0] instr_2, instr_1;
  input [5:0] opcode;
  output [4:0] saidaBitsCtr, saidaMux5b;
  output [31:0] resultadoAdd, resultadoAlu, rdata2out;
  output zero;

  wire [31:0] saidAdd, mux32_saida, saidaAlu;
  wire [4:0] mux5_saida;
  wire [3:0] select;
  wire [31:0] saidaShift;
  wire [31:0] fowardoutA, WriteDataFW;
  wire saidaZero;


  add soma (newpc, (extensor << 2), saidAdd);                       

  ALUcontrol alucontrol (bitsCtr[7:6], extensor[5:0], select);  

  ALU alu1 (fowardoutA, mux32_saida, select, saidaZero, saidaAlu);  
  
  MUX5b mux5_1 (instr_1, instr_2, bitsCtr[8], mux5_saida);

  MUX32 Mux32_2 (extensor, WriteDataFW, bitsCtr[5], mux32_saida);

  MUXhazard1 Mux32_3inA (read1, ResultW, resultadoAlu, ForwardA, fowardoutA);

  MUXhazard1 Mux32_3inB (read2, ResultW, resultadoAlu, ForwardB, WriteDataFW);  

  EX_MEM ex_mem_pipeline (clk, reset, bitsCtr[4:0], saidAdd, saidaZero, saidaAlu, read2, mux5_saida,      
                          saidaBitsCtr, resultadoAdd, zero, resultadoAlu, rdata2out, saidaMux5b);

endmodule