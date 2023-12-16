`timescale 1ns/1ns
`include "q2.v" 

module q2_tb();
reg [3:0]w;
wire [0:15]y;
reg e;
integer i;

q2 ex1(w,e,y);
initial 
begin

	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	for(i=0; i<8; i=i+1) begin
		w = i;
		e = 1;
		#20;
	end
	e = 0; w = 4'b1111; #20;
	$display("Test Complete");
end

endmodule

