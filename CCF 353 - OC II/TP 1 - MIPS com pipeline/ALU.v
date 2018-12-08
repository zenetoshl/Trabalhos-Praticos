module ALU (entradaA, entradaB, ctrlULA, zero, saida);
    //Declaração das entradas e saidas
    input wire [3:0] ctrlULA;
    input wire [31:0] entradaA,entradaB;
    output reg [31:0] saida;
    output reg zero;
    //Fim das entradas e saídas
    always @(ctrlULA,entradaA,entradaB) begin
        //Analiza em qual função ela deva entrar e realizar a operação correspondente.
        case (ctrlULA)
        0: saida <= entradaA & entradaB; //AND
        1: saida <= entradaA | entradaB; //OR
        2: saida <= entradaA + entradaB; //ADD
        6: saida <= entradaA - entradaB; //SUB
        7: saida <= entradaA < entradaB ? 1 : 0; //SLT
        12: saida <= ~(entradaA | entradaB); // NOR
        default: saida <= 0;
        endcase
    end
    always @(saida) begin
		if (saida == 0)
			zero <= 1;
		else
			zero <= 0;
	end	
endmodule
