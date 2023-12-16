module q3(a,b,cin,k,sum,cout);
    input [3:0]a,b;
    input cin,k;
    output [3:0]sum;
    output cout;
    wire [3:1]c;
    wire [3:0]i;
    assign i[0] = b[0]^k;
    assign i[1] = b[1]^k;
    assign i[2] = b[2]^k;
    assign i[3] = b[3]^k;
    fulladd stage0 (a[0], i[0], cin, sum[0], c[1]);
    fulladd stage1 (a[1], i[1], c[1], sum[1], c[2]);
    fulladd stage2 (a[2], i[2], c[2], sum[2], c[3]);
    fulladd stage3 (a[3], i[3], c[3], sum[3], cout);
endmodule

module fulladd(a,b,cin,sum,cout);
    input a,b,cin;
    output sum, cout;
    assign sum = a^b^cin;
    assign cout = (a&b)|(b&cin)|(cin&a);
endmodule