module q4(w, y, z);
    input [15:0]w;
    output reg [3:0]y;
    output reg z;
    integer k;
    
    always @*
    begin
        z=0;
        y = 4'bxxxx;
        for (k=0;k<=15;k++) begin
            if (w[k] == 1) begin
                y = k;
                z = 1;
            end
        end
    end
endmodule