module progCounter(clk,reset,NewPC,PC);
    input wire        clk,reset;
    input wire [31:0] NewPC;
    output reg [31:0] PC; // passa pra reg e seja feliz

    always @(posedge clk) begin
        if (reset)
            PC <= 32'h00000000;
        else
            PC <= NewPC;
    end

endmodule
