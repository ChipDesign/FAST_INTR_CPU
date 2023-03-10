module full_adder(
ain,bin,cin,sout,cout,xorout,orout,andout);

input ain,bin,cin;
output sout,cout,xorout,orout,andout;

wire axorb,aorb,aandb;

assign axorb= ain ^ bin;
assign aorb=  ain | bin;
assign aandb= ain & bin;


assign xorout= axorb;
assign orout=aorb;
assign andout=aandb;
assign sout=axorb ^ cin;
assign cout=(cin & aorb) | aandb;

endmodule
