module q4(x3, y3, p);
    input [2:0] x3, y3;
    output [5:0] p;
    wire [2:0] and_out, sum_out;
    
    assign and_out[0] = x3[0] & y3[0];
    assign and_out[1] = x3[1] & y3[0];
    assign and_out[2] = x3[2] & y3[0];
    
    assign sum_out[0] = and_out[0];
    assign sum_out[1] = and_out[1] ^ and_out[0];
    assign sum_out[2] = and_out[2] ^ and_out[1];
    
    adder3 stage0(sum_out, x3, 1'b0, p[2:1], p[3], p[4:5]);
endmodule

module adder3(x, y, cin, s, cout);
    input [2:0] x, y;
    input cin;
    output [2:0] s;
    output cout;
    wire c1, c2;

    fulladder stage0(x[0], y[0], cin, s[0], c1);
    fulladder stage1(x[1], y[1], c1, s[1], c2);
    fulladder stage2(x[2], y[2], c2, s[2], cout);
endmodule

module fulladder(x1, y1, Cin, Sum, Cout);
    input x1, y1, Cin;
    output Sum, Cout;
    assign Sum = x1 ^ y1 ^ Cin;
    assign Cout = (x1 & y1) | (x1 & Cin) | (y1 & Cin);
endmodule
