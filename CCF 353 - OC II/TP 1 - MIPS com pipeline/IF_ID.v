module IF_ID (clk, reset, hazard, IF_ID_Inst, IF_ID_NewPC, IF_ID_Instsaida, IF_ID_NewPCsaida);

    input clk, reset, hazard;
    input [31:0] IF_ID_Inst, IF_ID_NewPC;
    output reg [31:0] IF_ID_Instsaida, IF_ID_NewPCsaida;

    
    always @(posedge clk) begin
      if (reset) begin
        IF_ID_Instsaida <= 0;
        IF_ID_NewPCsaida <= 0;
      end
      else if (~hazard) begin
        IF_ID_Instsaida <= IF_ID_Inst;
        IF_ID_NewPCsaida <= IF_ID_NewPC;
      end
    end

endmodule