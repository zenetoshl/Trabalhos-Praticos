module MUX (entrada1,entrada2,Seletor,Saida);

    //Declaração das entradas de 32 bits
    input wire [31:0] entrada1, entrada2;
    input wire Seletor; //sinal seletor
    output [31:0] Saida; // saida 32-bit
    assign Saida = Seletor ? entrada1 : entrada2;
endmodule