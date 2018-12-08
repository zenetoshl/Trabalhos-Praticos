module control (inst, RegDst, Branch, MemRead, MemtoReg, ALUOp, MemWrite, ALUSrc, RegWrite);
    input wire [5:0] inst;
    output reg [1:0] ALUOp;
    output reg RegDst, Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite;

    always @(inst)
        case(inst)
        6'b000000: begin
                RegDst <=  1;
                MemRead <= 0;
                MemtoReg <= 0;
                ALUOp <= 0;
                MemWrite <= 0;
                ALUSrc <= 0;
                RegWrite <= 1;
                Branch <= 0;
                ALUOp[0] <= 0;
                ALUOp[1] <= 1;
            end
        6'b000100: begin
                RegDst <= 0;
                MemRead <= 0;
                MemtoReg <= 0;
                ALUOp <= 0;
                MemWrite <= 0;
                ALUSrc <= 0;
                RegWrite <= 0;
                Branch <= 1;
                ALUOp[0] <= 1;
                ALUOp[1] <= 0;
            end
        6'b100011:begin
                RegDst <= 0;
                MemRead <= 1;
                MemtoReg <= 1;
                ALUOp <= 0;
                MemWrite <= 0;
                ALUSrc <= 1;
                RegWrite <= 1;
                Branch <= 0;
                ALUOp[0] <= 0;
                ALUOp[1] <= 0;
            end
        6'b101011:begin
                RegDst <= 0;
                MemRead <= 0;
                MemtoReg <= 1;
                ALUOp <= 0;
                MemWrite <= 1;
                ALUSrc <= 1;
                RegWrite <= 0;
                Branch <= 0;
                ALUOp[0] <= 0;
                ALUOp[1] <= 0;
            end
        endcase


endmodule


module ALUcontrol (ALUOp, funct, ALUctrl);
    input wire [1:0] ALUOp;
    input wire [3:0] funct;
    output reg [3:0] ALUctrl;
    always@(ALUOp,funct)
    case(ALUOp)
    2'b00: ALUctrl <= 4'b0010; 
    2'b01: ALUctrl <= 4'b0110;
    2'b11: ALUctrl <= 4'b0110;
    default: case(funct)
        4'b0000: ALUctrl <= 4'b0010;
        4'b0010: ALUctrl <= 4'b0110;
        4'b0100: ALUctrl <= 4'b0000;
        4'b0101: ALUctrl <= 4'b0001;
        4'b1010: ALUctrl <= 4'b0111;
        endcase
    endcase
endmodule