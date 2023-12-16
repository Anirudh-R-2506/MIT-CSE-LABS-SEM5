`timescale 1ns/1ns
`include "q4.v" 

module q4_tb();
reg [2:0]w;
wire f;
integer i;

q4 ex1(w,f);
initial 
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	for(i=0; i<5; i=i+1) begin
		w = i;
		#20;
	end
	$display("Test Complete");
end

endmodule

