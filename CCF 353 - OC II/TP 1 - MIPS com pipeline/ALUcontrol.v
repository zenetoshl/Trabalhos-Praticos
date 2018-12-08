module ALUcontrol (ALUOp, funct, ALUctrl);
    input wire [1:0] ALUOp;
    input wire [5:0] funct;
    output reg [3:0] ALUctrl;
    always@(ALUOp,funct)
    case(ALUOp)
    2'b00: ALUctrl <= 4'b0010; 
    2'b01: ALUctrl <= 4'b0110;
    2'b11: ALUctrl <= 4'b0110;
    default: case(funct)
                      6'b100000 : ALUctrl = 4'b0010;
                      6'b100010 : ALUctrl = 4'b0110;
                      6'b100100 : ALUctrl = 4'b0000;
                      6'b100101 : ALUctrl = 4'b0001;
                      6'b101010 : ALUctrl = 4'b0111;
        endcase
    endcase
    /*always @(ALUOp or funct) begin
    case (ALUOp)
      2'b00       : select = 4'b0010;
      2'b01       : select = 4'b0110;
      2'b10       : begin case(funct)
                      6'b100000 : select = 4'b0010;
                      6'b100010 : select = 4'b0110;
                      6'b100100 : select = 4'b0000;
                      6'b100101 : select = 4'b0001;
                      6'b101010 : select = 4'b0111;
                      default : select = 4'bxxxx;
                     endcase
                    end
      2'b11       : select = 4'bxxxx;
    endcase*/
    endmodule