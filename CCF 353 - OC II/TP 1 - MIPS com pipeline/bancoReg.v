module bancoReg (clk, readReg1, readReg2, regW, writeReg, writeData, readData1, readData2);

    //Declaração das entradas e saídas do bloco
    input regW;
    input [4:0] readReg1;
    input [4:0] readReg2;
    input [4:0] writeReg;
    input [31:0] writeData;
    input clk;

    output [31:0] readData1;
    output [31:0] readData2;
    //Fim da declaração das entradas e saídas;

    reg [31:0] memoriaRegs [31:0];
    reg [10:0]i;

    //BLOCO DE INICIALIZAÇÃO DOS REGISTRADORES DA MEMÓRIA DE REGS
    
    initial begin
        for (i = 0; i < 32; i = i + 1) begin
				memoriaRegs[i] = 32'b000000000000000000000000000000;
		end
    end
    
    always @(posedge clk) begin
		  if(regW)
            memoriaRegs[writeReg] <= writeData;
    end
    //Atribuição das saídas
        assign readData1 = memoriaRegs[readReg1];
        assign readData2 = memoriaRegs[readReg2];

endmodule




