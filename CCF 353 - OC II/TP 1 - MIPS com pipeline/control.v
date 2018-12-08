module control (inst, hazard, bitsCtr);
    input wire [5:0] inst;
    input wire hazard;
    output reg [8:0] bitsCtr;
        // bitsCtr
        // 0 - memtoreg
        // 1 - regwrite
        // 2 - memwrite
        // 3 - memread
        // 4 - branch
        // 5 - aluScr
        // 6 - aluOP
        // 7 - aluOP
        // 8 - regDst

    always @(*)
        if(hazard)
            bitsCtr <= 9'b000000000;
        else 
        case(inst)
            6'b000000       : bitsCtr <= 9'b110000010;
            6'b100011       : bitsCtr <= 9'b000101011;
            6'b101011       : bitsCtr <= 9'b000100100;
            6'b000100       : bitsCtr <= 9'b001010000;
            default         : bitsCtr <= 9'b000000000;
        endcase


endmodule