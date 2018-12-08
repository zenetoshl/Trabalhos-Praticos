module Mux32bits2In (entrada1,entrada2,Seletor,Saida);

    //Declaração das entradas de 32 bits
    input wire [31:0] entrada1, entrada2;
    input wire Seletor; //sinal seletor
    output reg [31:0] Saida; // saida 32-bit

    always @(entrada1, entrada2, Seletor) begin
        case (Seletor)
        0: Saida <= entrada1;
        default: Saida <= entrada2;
    
    endcase
    end
endmodule

module Mux5bits2In (entrada1,entrada2,Seletor,Saida);

    //Declaração das entradas de 5 bits
    input wire [4:0] entrada1, entrada2;
    input wire Seletor; //sinal seletor
    output reg [4:0] Saida; // saida 5-bit
    
    always @(entrada1, entrada2, Seletor)
        case (Seletor)
        0: Saida <= entrada1;
        default:Saida <= entrada2;
    endcase

endmodule

module Sll2(entrada,saida);

    input wire [31:0] entrada;
    output wire [31:0] saida;
    
    // shift left 2 posições
    assign saida = entrada << 2;

endmodule

module SinalSaida(entrada16b,saida32b);

    input wire [15:0] entrada16b;
    output wire [31:0] saida32b;
    
    //extensão de bits
    assign saida32b = {{16{entrada16b[15]}},entrada16b}; 

endmodule

module Soma(entradaA,entradaB,saida);
    input wire [31:0] entradaA,entradaB; 
    output wire [31:0] saida;

    assign saida = entradaA + entradaB;

endmodule

module Soma4(entrada,saida);
    input wire [31:0] entrada; // aqui o nome tá errado, tira o A
    output wire [31:0] saida;

    assign saida = entrada + 4;

endmodule