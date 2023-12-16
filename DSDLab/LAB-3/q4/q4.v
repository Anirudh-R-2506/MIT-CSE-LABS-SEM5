module q4(g,b);
    input [2:0] g;
    output [2:0] b;
    assign b[2] = g[2];
    assign b[1] = g[2] ^ g[1];
    assign b[0] = g[0] ^ g[1] ^ g[2];
endmodule