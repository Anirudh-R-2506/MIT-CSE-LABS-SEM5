`timescale 1ns/1ns
`include "q1.v" 

module q1_tb();
reg [1:0]S;
reg [3:0]W;
wire f;
integer i;

q1 ex1(S,W,f);
initial 
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	S=0;
	W=4'b1110;
	#20

	S=1;
	W=4'b0011;
	#20

	S=2;
	W=4'b0111;
	#20

	S=3;
	W=4'b0000;
	#20

	S=0;
	W=4'b0001;
	#20

	S=1;
	W=4'b0101;
	#20

	S=2;
	W=4'b1010;
	#20

	S=3;
	W=4'b 1001;
	#20
	$display("Test Complete");
end

endmodule

