//Conversor de BCD para 7 segmentos, com dígito inválido
module BCDto7seg(
    input wire [3:0] n,
    output wire [6:0] s
);

    wire a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;

    assign s[6] = a2 & ~n[1] | a3 & a5;
    assign s[5] = a7 | a5 | a0 | a2 & n[0];
    assign s[4] = a1 | a6 | n[0];
    assign s[3] = a1 | a0 | a6 & ~n[0] | n[2] & a5 | a2 & a9;
    assign s[2] = a1 | a0 | a7 & ~n[0];
    assign s[1] = a1 | a0 | a6 & n[0] | a4 & ~n[0];
    assign s[0] = a1 | a0 | a6 & ~n[0] | a2 & a9;

    assign a0 =  n[3] &  n[2];
    assign a1 =  n[3] &  n[1];
    assign a2 = ~n[3] & ~n[2];
    assign a3 = ~n[3] &  n[2];
    assign a4 =  n[2] &  n[1];
    assign a5 =  n[1] &  n[0];
    assign a6 =  n[2] & ~n[1];
    assign a7 = ~n[2] &  n[1];
    assign a8 = ~n[2] & ~n[1];
    assign a9 = ~n[1] &  n[0];

endmodule

//Conversor de caracteres codificadas em binário para 7 segmentos
module letters(
    input wire [2:0] c,
    output wire [6:0] s
);

    wire a0,a1,a2,a3,a4,a5,a6;

    assign s[6] = a0 | a1;
    assign s[5] = a2 | a3;
    assign s[4] = a2 & c[0];
    assign s[3] = a3 | a4;
    assign s[2] = a4 | a5 | c[0];
    assign s[1] = c[1] | c[0];
    assign s[0] = a3 | a6;

    assign a0 = ~c[2] & ~c[0];
    assign a1 =  c[1] &  c[0];
    assign a2 =  c[2] &  c[1];
    assign a3 =  c[2] &  c[0];
    assign a4 =  c[2] & ~c[1];
    assign a5 = ~c[2] &  c[1];
    assign a6 =  c[1] & ~c[0];

endmodule