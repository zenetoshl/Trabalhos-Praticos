module BancoRegs (reset, regW, readReg1, readReg2, writeReg, writeData, clk, readData1, readData2);

    //Declaração das entradas e saídas do bloco
    input regW;
    input [4:0] readReg1;
    input [4:0] readReg2;
    input [4:0] writeReg;
    input [31:0] writeData;
    input clk, reset;

    output [31:0] readData1;
    output [31:0] readData2;
    //Fim da declaração das entradas e saídas;

    reg [31:0] memoriaRegs [31:0];

    //BLOCO DE INICIALIZAÇÃO DOS REGISTRADORES DA MEMÓRIA DE REGS
    always @(negedge clk) begin
        if (reset) begin
            memoriaRegs[0] = 32'b00000000000000000000000000000000;		
            memoriaRegs[1] = 32'b00000000000000000000000000000000;
            memoriaRegs[2] = 32'b00000000000000000000000000000000;
            memoriaRegs[3] = 32'b00000000000000000000000000000000;
            memoriaRegs[4] = 32'b00000000000000000000000000000000;
            memoriaRegs[5] = 32'b00000000000000000000000000000000;
            memoriaRegs[6] = 32'b00000000000000000000000000000000;
            memoriaRegs[7] = 32'b00000000000000000000000000000000;
            memoriaRegs[8] = 32'b00000000000000000000000000000000;
            memoriaRegs[9] = 32'b00000000000000000000000000000000;
            memoriaRegs[10] = 32'b00000000000000000000000000000000;
            memoriaRegs[11] = 32'b00000000000000000000000000000000;
            memoriaRegs[12] = 32'b00000000000000000000000000000000;
            memoriaRegs[13] = 32'b00000000000000000000000000000000;
            memoriaRegs[14] = 32'b00000000000000000000000000000000;
            memoriaRegs[15] = 32'b00000000000000000000000000000000;
            memoriaRegs[16] = 32'b00000000000000000000000000000000;
            memoriaRegs[17] = 32'b00000000000000000000000000000000;
            memoriaRegs[18] = 32'b00000000000000000000000000000000;
            memoriaRegs[19] = 32'b00000000000000000000000000000000;
            memoriaRegs[20] = 32'b00000000000000000000000000000000;
            memoriaRegs[21] = 32'b00000000000000000000000000000000;
            memoriaRegs[22] = 32'b00000000000000000000000000000000;
            memoriaRegs[23] = 32'b00000000000000000000000000000000;
            memoriaRegs[24] = 32'b00000000000000000000000000000000;
            memoriaRegs[25] = 32'b00000000000000000000000000000000;
            memoriaRegs[26] = 32'b00000000000000000000000000000000;
            memoriaRegs[27] = 32'b00000000000000000000000000000000;
            memoriaRegs[28] = 32'b00000000000000000000000000000000;
            memoriaRegs[29] = 32'h00000FFC; //SP
            memoriaRegs[30] = 32'b00000000000000000000000000000000;
            memoriaRegs[31] = 32'b00000000000000000000000000000000;
        end
		  if(regW == 1'b1)
            memoriaRegs[writeReg] <= writeData;
    end
    //Atribuição das saídas
        assign readData1 = memoriaRegs[readReg1];
        assign readData2 = memoriaRegs[readReg2];

endmodule




