`timescale 1ns/1ns
`include "q3.v" 

module q3_tb();
reg [3:0]w;
wire [1:0]y;
wire z;  
integer i;

q3 ex1(w,y,z);
initial 
begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);
	for(i=0;i<15;i=i+1)
    begin
		w=i;
		#20;
    end
	$display("Test Complete");
end

endmodule

