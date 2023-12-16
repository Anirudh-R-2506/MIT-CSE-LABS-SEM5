`timescale 1ns/1ns
`include "q4.v" 

module q4_tb();
reg [2:0]g;
wire [2:0]b;

q4 ex1(g,b);
initial 
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	g=3'b011; #20;
	g=3'b010; #20;
	g=3'b110; #20;
	g=3'b111; #20;
	$display("Test Complete");
end

endmodule

