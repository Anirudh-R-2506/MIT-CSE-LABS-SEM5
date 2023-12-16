`timescale 1ns/1ns
`include "q3.v" 

module q3_tb();
reg a,b,c,d;
wire f;
integer i;

q3 ex1(a,b,c,d,f);
initial 
begin

	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);
	for(i=0; i<16; i=i+1) begin
		{a,b,c,d} = i;
		#20;
	end
	$display("Test Complete");
end

endmodule

