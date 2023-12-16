`timescale 1ns/1ns
`include "q2.v" 

module q2_tb();
reg [2:0]S;
reg [7:0]W;
wire f;
integer i;

q2 ex1(S,W,f);
initial 
begin

	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	S=0;
	W=7'b1110110;
	#20

	S=1;
	W=7'b0011100;
	#20

	S=2;
	W=7'b0111001;
	#20

	S=3;
	W=7'b0100010;
	#20

	S=4;
	W=7'b0001100;
	#20

	S=5;
	W=7'b0101110;
	#20

	S=6;
	W=7'b1010011;
	#20

	S=7;
	W=7'b1001100;
	#20
	$display("Test Complete");
end

endmodule

