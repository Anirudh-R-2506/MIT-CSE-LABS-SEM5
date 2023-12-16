`timescale 1ns/1ns
`include "q1.v" 

module q1_tb();
reg a,b,c,d;
wire f;
integer i;

q1 ex1(a,b,c,d,f);
initial 
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	for(i=0; i<16; i=i+1) begin
		{a,b,c,d} = i;
		#20;
	end
	$display("Test Complete");
end

endmodule

