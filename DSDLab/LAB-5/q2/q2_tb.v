`timescale 1ns/1ns
`include "q2.v" 

module q2_tb();
reg [3:0]g;
wire [3:0]b;
integer i;

q2 ex1(g,b);
initial 
begin

	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	for(i=0; i<15; i=i+1) begin
		g = i;
		#20;
	end
	$display("Test Complete");
end

endmodule

