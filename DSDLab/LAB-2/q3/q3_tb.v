`timescale 1ns/1ns
`include "q3.v" 

module q3_tb();
reg [3:0]a,b;
reg cin,k;
wire [3:0]sum;
wire cout;
integer i;

q3 ex1(a,b,cin,k,sum,cout);
initial 
begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);
	cin=0;a=3;b=2;k=0;#20;
	cin=0;a=3;b=2;k=1;#20;
	$display("Test Complete");
end

endmodule

