`timescale 1ns/1ns
`include "q4.v" 

module q4_tb();
reg [2:0]x3,y3;
wire [5:0]p;

q4 ex1(x3,y3,p);
initial 
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	x3=3'b011; y3=3'b110; #20;
	x3=3'b001; y3=3'b100; #20;
	$display("Test Complete");
end

endmodule

