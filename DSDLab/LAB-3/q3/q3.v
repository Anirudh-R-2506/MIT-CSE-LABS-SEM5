module q3(a,b,lt,eq,gt);
    input [2:0]a,b;
    output lt, eq, gt;
    wire x0,x1,x2,y0,y1,y2,z0,z1,z2;
    assign x0 = (a[0] ^ b[0]);
    assign x1 = (a[1] ^ b[1]);
    assign x2 = (a[2] ^ b[2]);
    assign eq = ~(x0 | x1 | x2);
    assign y0 = (a[0] & ~b[0]);
    assign y1 = (a[1] & ~b[1]);
    assign y2 = (a[2] & ~b[2]);
    assign gt = (y2&x1) | (y1) | (y0&x2);
    assign z0 = (~a[0] & b[0]);
    assign z1 = (~a[1] & b[1]);
    assign z2 = (~a[2] & b[2]);
    assign lt = (z2) | (z1&x2) | (z0&x1);
endmodule