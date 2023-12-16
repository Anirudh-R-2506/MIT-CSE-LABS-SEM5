`timescale 1ns/1ns
`include "q4.v" 

module q4_tb();
reg a,b,c,d;
wire f;
integer i;

q4 ex1(a,b,c,d,f);
initial 
begin

	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	for(i=0; i<16; i=i+1) begin
		{a,b,c,d} = i;
		#20;
	end
	$display("Test Complete");
end

endmodule

