`ifndef __HALFADDER__
`define __HALFADDER__
module half_adder(
ain,bin,sout,cout);

input ain,bin;
output sout,cout;


assign sout=ain^bin;
assign cout=(ain&bin);

endmodule
`endif
