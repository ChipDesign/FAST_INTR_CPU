`ifndef FULL_ADDER
`define FULL_ADDER
module full_adder(
ain,bin,cin,sout,cout);

input ain,bin,cin;
output sout,cout;

wire axorb;


assign axorb=ain^bin;

assign sout=axorb ^ cin;
assign cout=(cin&axorb)|(ain&bin);

endmodule
`endif
