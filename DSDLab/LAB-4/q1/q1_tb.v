`timescale 1ns/1ns
`include "q1.v" 

module q1_tb();
reg [1:0]w;
wire [0:3]y;
reg e;

q1 ex1(w,e,y);
initial 
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	e=1;
    w = 2'b00;
    #20;

    e=1;
    w = 2'b01;
    #20;

    e=1;
    w = 2'b10;
    #20;

    e=1;
    w = 2'b11;
    #20;
    
    e=0;
    w = 4'b11;
    #20;
	$display("Test Complete");
end

endmodule

