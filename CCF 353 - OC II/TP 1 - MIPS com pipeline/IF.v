

module IF(clk, reset, hazard, EX_MEM_NewPC, EX_MEM_Seletor, IF_ID_Instsaida, IF_ID_NewPCsaida);

	input clk, reset, hazard;
	input [31:0] EX_MEM_NewPC;
	input EX_MEM_Seletor;
    output [31:0] IF_ID_Instsaida, IF_ID_NewPCsaida;

    wire [31:0] IF_ID_NewPC;
	wire [6:0] addr;
	wire [31:0] add;
	wire [31:0] IF_ID_Inst;

    //PC
    reg [31:0] PC;
	
	
	
	assign addr = PC[6:0];
	

	//le a instrucao e retorna o endereço addr
	memoriaInstru IM1 (reset, clk, addr, IF_ID_Inst);

	 //soma +4 no PC, add é a saida
	PC_4 soma_4 (PC, add);
	
	//seleciona qual o novo pc:
	MUX32b mux1 ((EX_MEM_NewPC), add, EX_MEM_Seletor, IF_ID_NewPC);

	IF_ID if_id (clk, reset, hazard, IF_ID_Inst, IF_ID_NewPC, IF_ID_Instsaida, IF_ID_NewPCsaida);

// PC
always @(posedge clk) begin
        if (reset)
            PC <= 32'h00000000;
        else if (~hazard)
            PC <= IF_ID_NewPC;
    end
endmodule