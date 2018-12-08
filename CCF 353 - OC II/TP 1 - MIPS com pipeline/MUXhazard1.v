module MUXhazard1 (entradaA, entradaB, entradaC, controle, saida);
    input wire [31:0] entradaA, entradaB, entradaC;
    input wire [1:0] controle; //sinal seletor
    output [31:0] saida; // saida 32-bit
    
    assign saida = (controle == 0) ? entradaA : ((controle == 2'b01) ? entradaB : entradaC);
endmodule