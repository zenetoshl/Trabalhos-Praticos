module MUX5b (entrada1,entrada2,Seletor,Saida);

    //Declaração das entradas de 5 bits
    input wire [4:0] entrada1, entrada2;
    input wire Seletor; //sinal seletor
    output [4:0] Saida; // saida 5-bit
    
    assign Saida = Seletor ? entrada1 : entrada2;

endmodule