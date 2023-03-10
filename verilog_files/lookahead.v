module lookahead(
ain,bin,cin,cout);

input cin;
input[3:0] ain,bin;
output[3:0] cout;

wire p0,p1,p2,p3,g0,g1,g2,g3;

assign p0=ain[0]^bin[0];
assign p1=ain[1]^bin[1];
assign p2=ain[2]^bin[2];
assign p3=ain[3]^bin[3];
assign g0=ain[0]&bin[0];
assign g1=ain[1]&bin[1];
assign g2=ain[2]&bin[2];
assign g3=ain[3]&bin[3];

assign cout[0]=g0|(cin&p0);
assign cout[1]=g1|(g0&p1)|(cin&p0&p1);
assign cout[2]=g2|(g1&p2)|(g0&p1&p2)|(cin&p0&p1&p2);
assign cout[3]=g3|(g2&p3)|(g1&p2&p3)|(g0&p1&p2&p3)|(cin&p0&p1&p2&p3);


endmodule
