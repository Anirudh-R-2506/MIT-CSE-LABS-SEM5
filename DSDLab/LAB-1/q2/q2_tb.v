`timescale 1ns/1ns
`include "q2.v" 

module q2_tb();
reg a,b,c,d;
wire f;
integer i;

q2 uut(a,b,c,d,f);
initial 
begin

	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	for(i=0; i<16; i=i+1) begin
		{a,b,c,d} = i;
		#20;
	end
	$display("Test Complete");
end

endmodule

