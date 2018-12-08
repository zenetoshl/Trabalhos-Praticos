//`include "Muxs.v"
//`include "pc-oc.v"
//`include "memoriaInstru.v"
//`include "bancoReg.v"
//`include "ULA.v"
//`include "memdados.v"
//`include "control.v"

module main();
    reg clk,reset;
    wire ALU_Zero;
    wire [4:0] regB_Write;
    wire [31:0] inst, imediato_32, Sll, pc_4, pc, SomaNPC, New_PC, ReadData1, ReadData2, ReadDataDM, WriteDataReg, ALU_in1, ALU_Out;
   //wires do control
   wire RegDst, Branch, MemRead, MemtoReg, MemWrite, ALUSrc, RegWrite;
   wire [3:0] ALUctrl;
   wire [1:0] ALUOp;
	wire [31:0] saidaBancoReg;

    //control
    control ctrl(inst[31:26] ,RegDst, Branch, MemRead, MemtoReg, ALUOp[1:0], MemWrite, ALUSrc, RegWrite);

    //ALU control
    ALUcontrol ALU_cont(ALUOp[1:0], inst[3:0], ALUctrl[3:0]);

    //PC - Program Counter
    progCounter PC_block(clk,reset,New_PC[31:0],pc[31:0]);

    //PC+4
    Soma4 soma_4(pc[31:0],pc_4[31:0]);

    //16-32bit
    SinalSaida Sinal_ex(inst[15:0],imediato_32[31:0]);

    //sll
    Sll2 shift_left(imediato_32[31:0],Sll[31:0]); // aqui faltou extender o sinal do imediato antes

    //soma sll
    Soma somador(pc_4[31:0],Sll[31:0],SomaNPC[31:0]);

    //Memória de Instruções
    MemoriaInstrucoes mem_instru(reset,pc[31:0],inst[31:0]);

    //Banco de Registradores
    BancoRegs Bank_reg(reset,/*control*/RegWrite/*control*/,inst[25:21],inst[20:16],regB_Write[4:0],WriteDataReg[31:0],clk,ReadData1[31:0],ReadData2[31:0]);

    //Unidade Lógica e Aritmética
    ALU ALU_inst(/*control*/ALUctrl[3:0]/*control*/,ReadData1[31:0],ALU_in1[31:0],ALU_Out[31:0],ALU_Zero);

    //Memória de Dados
    dataMem Mem_dados(clk,reset,ALU_Out[31:0],ReadData2[31:0],/*control*/MemWrite/*control*/,ReadDataDM[31:0]); 

    //Multiplexadores
    //Selecionar endereço de escrita no banco de registradores
    Mux5bits2In muxRegWrite(inst[20:16],inst[15:11],/*control*/RegDst/*control*/,regB_Write[4:0]);

    //Selecionar dados a serem escritos no banco de registradores
    Mux32bits2In muxRegData(ALU_Out[31:0],ReadDataDM[31:0],/*control*/MemtoReg/*control*/,WriteDataReg[31:0]);

    //Selecionar segunda entrada da ULA
    Mux32bits2In muxALUB2(ReadData2[31:0],Sll[31:0],/*control*/ALUSrc/*control*/,ALU_in1[31:0]);

    //Selecionar novo PC
    Mux32bits2In MuxPC(pc_4[31:0],SomaNPC[31:0],ALU_Zero & Branch,New_PC[31:0]);



    initial begin
        clk = 0;
        reset = 1;

        $dumpfile("simulator.vcd");
        $dumpvars;

        #2 reset = 0;
        #80 $finish;
    end

    always #1 clk = ~clk;
endmodule