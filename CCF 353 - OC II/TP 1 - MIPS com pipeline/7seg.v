// Conversor para o display de 7 segmentos

module sevenSeg(
    input wire [3:0] n,
    output wire [6:0] s
);

    assign s =
    (n[3])?(
        (n[2])?(
            (n[1])?(
                (n[0])?(
                    7'b0001110 // F
                ):(
                    7'b0000110 // E
                )
            ):(
                (n[0])?(
                    7'b0100001 // D
                ):(
                    7'b1000110 // C 
                )
            )
        ):(
            (n[1])?(
                (n[0])?(
                    7'b0000011 // B
                ):(
                    7'b0001000 // A
                )
            ):(
                (n[0])?(
                    7'b0010000 // 9
                ):(
                    7'b0000000 // 8
                )
            )
        )
    ):(
        (n[2])?(
            (n[1])?(
                (n[0])?(
                    7'b1111000 // 7
                ):(
                    7'b0000010 // 6 
                )
            ):(
                (n[0])?(
                    7'b0010010 // 5
                ):(
                    7'b0011001 // 4 
                )
            )
        ):(
            (n[1])?(
                (n[0])?(
                    7'b0110000 // 3
                ):(
                    7'b0100100 // 2 
                )
            ):(
                (n[0])?(
                    7'b1111001 // 1 
                ):(
                    7'b1000000 // 0 
                )
            )
        )
    );

endmodule
