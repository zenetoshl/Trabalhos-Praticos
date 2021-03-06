
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module MIPScomPipeline(

	//////////// CLOCK //////////
	input 		          		CLOCK_50,
	input 		          		CLOCK2_50,
	input 		          		CLOCK3_50,

	//////////// SW //////////
	input 		    [17:0]		SW,

	//////////// SEG7 //////////
	output		     [6:0]		HEX0,
	output		     [6:0]		HEX1,
	output		     [6:0]		HEX2,
	output		     [6:0]		HEX3,
	output		     [6:0]		HEX4,
	output		     [6:0]		HEX5,
	output		     [6:0]		HEX6,
	output		     [6:0]		HEX7
);



//=======================================================
//  REG/WIRE declarations
//=======================================================
		wire newClock;
		wire reset;
		wire [31:0]ALU_Out;



//=======================================================
//  Structural coding
//=======================================================

//Divisor de clock
	
	clk_div #(25,50000000) divisorClk(reset,CLOCK_50,newClock);
	//Sinais de Controle
	assign reset = SW[0];
	
	
	Pipeline pipe(newClock, reset, ALU_Out);

//Instanciamento do 7 SEG
	 sevenSeg seteS1 (ALU_Out[31:28],HEX7);
	 sevenSeg seteS2 (ALU_Out[27:24],HEX6);
	 sevenSeg seteS3 (ALU_Out[23:20],HEX5);
	 sevenSeg seteS4 (ALU_Out[19:16],HEX4);
	 sevenSeg seteS5 (ALU_Out[15:12],HEX3);
	 sevenSeg seteS6 (ALU_Out[11:8],HEX2);
	 sevenSeg seteS7 (ALU_Out[7:4],HEX1);
	 sevenSeg seteS8 (ALU_Out[3:0],HEX0);
	 

endmodule
