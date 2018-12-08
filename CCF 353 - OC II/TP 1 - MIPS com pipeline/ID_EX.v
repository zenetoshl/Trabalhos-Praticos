module ID_EX(clk, reset, bitsCtr, newpc, read1, read2, extensor, instr_2, instr_1,rs,rt, 
             saidaBitsCtr, saidaNewPC, saidaRead1, saidaRead2, saidaExtensor, saidaInst_2, saidaInst_1,rsout,rtout);

  input clk, reset;
  input [8:0] bitsCtr;
  input [31:0] read1, read2, extensor, newpc;
  input [4:0] instr_2, instr_1;
  input [4:0]rs, rt;
  output reg [8:0] saidaBitsCtr;
  output reg [31:0] saidaNewPC, saidaRead1, saidaRead2, saidaExtensor;
  output reg [4:0] saidaInst_2, saidaInst_1;
  output reg [4:0]rsout, rtout;



  always @(posedge clk) begin
    if (reset) begin
      saidaBitsCtr <= 0;
      saidaNewPC <= 0;
      saidaInst_2 <= 0;
      saidaInst_1 <= 0;
      saidaRead1 <= 0;
      saidaRead2 <= 0;
      saidaExtensor <= 0;
      rsout <= 0;
      rtout <= 0;

    end
    else begin
      saidaBitsCtr <= bitsCtr;
      saidaNewPC <= newpc;
      saidaInst_2 <= instr_2;
      saidaInst_1 <= instr_1;
      saidaRead1 <= read1;
      saidaRead2 <= read2;
      saidaExtensor <= extensor;
      rsout <= rs;
      rtout <= rt;
    end
  end

endmodule