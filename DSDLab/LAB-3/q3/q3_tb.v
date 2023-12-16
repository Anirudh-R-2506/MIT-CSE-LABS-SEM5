`timescale 1ns/1ns
`include "q3.v" 

module q3_tb();
reg [2:0]a,b;
wire lt,eq,gt;

q3 ex1(a,b,lt,eq,gt);
initial 
begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);
	a=3'b011;b=3'b001;#20;
	a=3'b110;b=3'b110;#20;
	a=3'b111;b=3'b100;#20;
	a=3'b010;b=3'b010;#20;
	a=3'b000;b=3'b100;#20;
	$display("Test Complete");
end

endmodule

