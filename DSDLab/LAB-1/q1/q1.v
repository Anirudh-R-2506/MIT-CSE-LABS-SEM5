module q1(a,b,c,d,f);
	input a,b,c,d;
	output f;
	not(g, c);
	assign f = (c)|(a&g&d);
endmodule

