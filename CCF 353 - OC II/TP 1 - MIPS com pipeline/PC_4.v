module PC_4(entrada, saida);
    input wire [31:0] entrada;
    output wire [31:0] saida;

    assign saida = entrada + 4;

endmodule