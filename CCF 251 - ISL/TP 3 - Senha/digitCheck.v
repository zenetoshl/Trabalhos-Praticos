//Verifica se um dígito é válido, ou seja, se está entre 0 e 9
module digitCheck(
    //Input
    input wire [3:0] dg,
    //Output
    output wire valid
);

    assign valid = ~dg[3] | ~dg[2] & ~dg[1];

endmodule