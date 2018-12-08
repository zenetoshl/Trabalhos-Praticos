module raiz(a,b,c,d,e,s1,s2,s3);
	input a,b,c,d,e;
	output s1,s2,s3;
	assign s1 = (b & c) | ((~c & b) & (d | e)) | (~a & ~b & ~c & d) | (~a & ~b & ~c & e);
	assign s2 = ~a & (c | b);
	assign s3 = a;
endmodule

module teste;
	reg a,b,c,d,e;
	wire s1,s2,s3;
	raiz RAIZ(a,b,c,d,e,s1,s2,s3);
	initial
	begin
	$dumpfile ("teste.vcd");
	$dumpvars;
	$monitor("s3 = %d s2 = %d s1 = %d ",s3,s2,s1);
	a=0;
	b=0;
	c=0;
	d=0;
	e=0;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1 e=0;d=0;c=1;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1 b=1;c=0;d=0;e=0;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1 e=0;d=0;c=1;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1 a=1;b=0;c=0;d=0;e=0;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1 e=0;d=0;c=1;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1 b=1;c=0;d=0;e=0;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1 e=0;d=0;c=1;
	#1 e=1;
	#1 e=0;d=1;
	#1 e=1;
	#1;
	end
endmodule
	
	
	
	