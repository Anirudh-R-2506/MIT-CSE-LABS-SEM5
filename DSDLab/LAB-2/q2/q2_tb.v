`timescale 1ns/1ns
`include "q2.v" 

module q2_tb();
reg a,b,cin;
wire sum,cout;
integer i;

q2 ex1(a,b,cin,sum,cout);
initial 
begin

	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	for(i=0; i<12; i=i+1) begin
		{a,b,cin} = i;
		#20;
	end
	$display("Test Complete");
end

endmodule

