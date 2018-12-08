module add(entradaA,entradaB,saida);
    input wire [31:0] entradaA,entradaB; 
    output wire [31:0] saida;

    assign saida = entradaA + entradaB;

endmodule