module shifter4#(parameter DATA_WIDTH=4, parameter SHIFT_WIDTH=2) (
        input [DATA_WIDTH-1:0] d_in,
        input [SHIFT_WIDTH-1:0] shift,
        input arithOrLogic, // SRA or SRL
        input leftOrRight, // shift left or right
        output [DATA_WIDTH-1:0] d_out);

    wire M10, M11, M12, M13;
    wire msbFill;  // is shift right arithmatic, fill the msb with d[DATA_WIDTH-1], otherwish fill msb with 0.
    wire [DATA_WIDTH-1: 0] shifter_d_in, shifter_d_out; // we only implement shift right in shift array, shift left is finishing by turning over the input and turning over the output of the shift array.

    assign msbFill=arithOrLogic?0:d_in[3];
    assign shifter_d_in=leftOrRight? d_in :{d_in[0],d_in[1],d_in[2],d_in[3]};


    // shift array logic begin
    assign M10=shift[0]?shifter_d_in[1]:shifter_d_in[0];
    assign M11=shift[0]?shifter_d_in[2]:shifter_d_in[1];
    assign M12=shift[0]?shifter_d_in[3]:shifter_d_in[2];
    assign M13=shift[0]?msbFill:shifter_d_in[3];


    assign shifter_d_out[0]=shift[1]?M12:M10;
    assign shifter_d_out[1]=shift[1]?M13:M11;
    assign shifter_d_out[2]=shift[1]?msbFill:M12;
    assign shifter_d_out[3]=shift[1]?msbFill:M13;
    // shift array logic end

    assign d_out=leftOrRight? shifter_d_out: {shifter_d_out[0],shifter_d_out[1],shifter_d_out[2],shifter_d_out[3]};

    /* always @(d_in) begin */
    /*     case(shift) */
    /*         2'b00: */
    /*             d_out<=0; */
    /*         default: */
    /*             d_out<=d_in; */
    /*     endcase */
    /* end */
endmodule
