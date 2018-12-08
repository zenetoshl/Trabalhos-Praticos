module fowarding (RsE, RtE, WriteRegM, RegWriteM, WriteRegW, RegWriteW,
                    ForwardAE, ForwardBE);
input wire RegWriteM, RegWriteW;
input wire [4:0] WriteRegW, WriteRegM, RsE, RtE;
output wire [1:0] ForwardAE;
output wire [1:0] ForwardBE;

assign ForwardAE = ((RsE != 0) && (RsE == WriteRegM) && RegWriteM)  ? 2'b10 : // EX/EX
				   (((RsE != 0) && (RsE == WriteRegW) && RegWriteW) ? 2'b01 : // MEM/EX
				   0);

assign ForwardBE = ((RtE != 0) && (RtE == WriteRegM) && RegWriteM)  ? 2'b10 : // EX/EX
				   (((RtE != 0) && (RtE == WriteRegW) && RegWriteW) ? 2'b01 : // MEM/EX
				   0);


endmodule