module q2(a,b,c,d,f);
	input a,b,c,d;
	output f;
	assign f = (~c&b) | (c&~d);
endmodule
