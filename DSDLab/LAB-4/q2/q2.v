module q2(w,e,y);
    input [3:0] w;
    input e;
    output [0:15] y;
    wire [0:3]temp;
    ttf s0 (w[3:2], e, temp[0:3]);
    ttf s1 (w[1:0], temp[0], y[0:3]);
    ttf s2 (w[1:0], temp[1], y[4:7]);
    ttf s3 (w[1:0], temp[2], y[8:11]);
    ttf s4 (w[1:0], temp[3], y[12:15]);
endmodule

module ttf(w,e,y);
    input [1:0] w;
    input e;
    output reg [0:3] y;

    always @(e, w)
    begin 
    y = 4'b0000;
        if (w == 2'b00 && e == 1)
        y[0] = 1;
        else if (w == 2'b01 && e == 1)
        y[1] = 1;
        else if (w == 2'b10 && e == 1)
        y[2] = 1;
        else if (w == 2'b11 && e == 1)
        y[3] = 1;
    end
endmodule