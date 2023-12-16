module q3(a,b,c,d,f);
	input a,b,c,d;
	output f;
	
	assign f = (b|~c)&(~b|c|~d)&(~c|d)&(a|~b|~d);
endmodule

