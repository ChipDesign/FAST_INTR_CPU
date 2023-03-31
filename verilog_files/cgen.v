module cgen(
ain,bin,cin,cout);

input ain,bin,cin;
output cout;

assign cout=ain?cin:bin;

endmodule
