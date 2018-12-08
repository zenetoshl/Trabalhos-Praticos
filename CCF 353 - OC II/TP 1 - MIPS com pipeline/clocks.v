//Divisor de clock
module clk_div 
#( 
parameter WIDTH = 3, // Largura necessária para o registrador
parameter N = 6 // Para dividir por 12 (6*2)
)
(
    input wire reset,
    input wire clk,
    output wire clk_out
);
 
    reg [WIDTH-1:0] counter;
    reg [WIDTH-1:0] next_counter;
    reg clk_track;
    reg next_ctrack;
    
    always @(negedge clk) begin
        clk_track <= next_ctrack;
        counter <= next_counter;
    end

    always @(*) begin
        if (reset) begin
            next_counter <= 0;
            next_ctrack  <= 1'b0;
        end else if (counter + 1 == N) begin
            next_counter <= 0;
            next_ctrack  <= ~clk_track;
        end else begin
            next_counter <= counter + 1;
            next_ctrack  <= clk_track;
        end
    end
         
    assign clk_out = clk_track;
    
endmodule
