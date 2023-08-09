`ifndef __CGENMOS__
`define __CGENMOS__
module cgen_mos(
ain,bin,cin,cout);

input ain,bin,cin;
output cout;

supply1 VDD;
supply0 GND;

wire vdd=VDD;
wire gnd=GND;
wire w0,w1,w2,w3,w4,w5;



pmos p0(w0,vdd,bin);
pmos p1(w0,vdd,ain);
pmos p2(w4,w0,cin);
pmos p3(w2,vdd,bin);
pmos p4(w4,w2,ain);
pmos p5(cout,vdd,w4);

nmos n0(w1,gnd,bin);
nmos n1(w1,gnd,ain);
nmos n2(w4,w1,cin);
nmos n3(w3,gnd,bin);
nmos n4(w4,w3,ain);
nmos n5(cout,gnd,w4);

endmodule
`endif
