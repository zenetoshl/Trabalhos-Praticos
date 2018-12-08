//Módulo de teste do Sistema de Fechadura
`include "lock_system.v"

module testbench();
    reg clk, lock, valid;
    reg [3:0] pwd;

    wire error,unlck;

    lock_system lock_inst(clk,lock,valid,pwd,error,unlck);

    always
        #1 clk <= ~clk;

    initial begin
        $dumpfile("lock.vcd");
		$dumpvars;
		$monitor("Aberto? %d || Erro? %d || Digito inserido: %d\n",error,unlck,pwd);
		
        clk = 0;
        lock = 1;
        valid = 0;
        pwd = 4'b0000;

        #2 lock = 0;
        #1 pwd = 4'b0011; 
        #1 valid = 1;
        #2 valid = 0;
        #1 pwd = 4'b0000; 
        #1 valid = 1;
        #2 valid = 0;
        #1 pwd = 4'b0001; 
        #1 valid = 1;
        #2 valid = 0;
        #1 pwd = 4'b0010; 
        #1 valid = 1;
        #2 valid = 0;
        #2 lock = 1;
        #2 lock = 0;

        #2 $finish;
    end



endmodule