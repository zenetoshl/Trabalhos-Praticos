module hazard1 (RsD, RtD, RtE, Memread,
				Hazard);

input wire [4:0] RsD; 
input wire [4:0] RtD;
input wire [4:0] RtE;
input wire Memread;

output wire Hazard;

assign Hazard = Memread & (RtE != 0) & ((RtE == RsD) | (RtE == RtD));
endmodule