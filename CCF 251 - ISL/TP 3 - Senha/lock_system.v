
//Sistema de Fechadura
module lock_system(
    //Input
    input wire clk, input wire lock, input wire valid, input wire [3:0] pwd,

    //Output
    output reg pwd_error, output reg unlocked
);

//    //Parâmetros dos estados
    parameter   D0 = 3'b000,
                D1 = 3'b001,
                D2 = 3'b010,
              D3_1 = 3'b011,
              D3_2 = 3'b100,
              D3_3 = 3'b101,
              CLSD = 3'b110,
              OPEN = 3'b111;
    
    //Variáveis de estados e controle para verificar a senha 
    reg [2:0] state;
    reg [2:0] next_state;
    reg wr_pwd,next_wr_pwd;
	 
    //Atribuição do próximo estado
    always @(posedge clk) begin
        if (lock) begin
            state = D0;
            wr_pwd = 1'b0;
        end else begin
            state = next_state;
				wr_pwd = next_wr_pwd;
		  end
	 end

    //Cálculo do próximo estado
    always @(posedge lock or posedge valid) begin
	 
		  if (lock) begin
				next_state = D0;
				next_wr_pwd = 1'b0;
		  end 
		  else begin
			  if (valid) begin
			  
				  case (state)
				  D0: begin
						next_state = D1;
						if (pwd!=4'b0011)
							 next_wr_pwd = 1'b1;
				  end
				  D1: begin
						next_state = D2;
						if (pwd!=4'b0000)
							 next_wr_pwd = 1'b1;
				  end
				  D2: begin
						case (pwd)
						4'b0001: next_state = D3_1;
						4'b0100: next_state = D3_2;
						default: next_state = D3_3;
						endcase
						if (pwd!=4'b0001 & pwd!=4'b0100 & pwd!=4'b0101)
							 next_wr_pwd = 1'b1;
				  end
				  D3_1: begin
						if (wr_pwd | pwd!=4'b0111) next_state = CLSD;
						else next_state = OPEN;
				  end
				  D3_2: begin
						if (wr_pwd | (pwd!=4'b0010 & pwd!=4'b0110)) next_state = CLSD;
						else next_state = OPEN;
				  end
				  D3_3: begin
						if (wr_pwd | pwd!=4'b0001) next_state = CLSD;
						else next_state = OPEN;
				  end
				  CLSD:
						next_state = CLSD;
				  OPEN:
						next_state = OPEN;
				  endcase
				  
				end
		  end
			
	 end

    //Cálculo das saídas
    always @(state)
        case (state)
        D0: begin pwd_error = 1'b0; unlocked = 1'b0; end
        D1: begin pwd_error = 1'b0; unlocked = 1'b0; end
        D2: begin pwd_error = 1'b0; unlocked = 1'b0; end
        D3_1: begin pwd_error = 1'b0; unlocked = 1'b0; end
        D3_2: begin pwd_error = 1'b0; unlocked = 1'b0; end
        D3_3: begin pwd_error = 1'b0; unlocked = 1'b0; end
        CLSD: begin pwd_error = 1'b1; unlocked = 1'b0; end
        OPEN: begin pwd_error = 1'b0; unlocked = 1'b1; end
        endcase

    
endmodule