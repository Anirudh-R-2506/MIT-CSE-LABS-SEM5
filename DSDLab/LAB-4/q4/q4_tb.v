`timescale 1ns/1ns
`include "q4.v" 

module q4_tb();
reg [15:0]w;
wire [3:0]y;
wire z;  
integer i;

q4 ex1(w,y,z);
initial 
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	for(i=0;i<16;i=i+1)
    begin
		w=i;
		#20;
    end
	$display("Test Complete");
end

endmodule

