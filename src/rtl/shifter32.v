module shifter32#(parameter DATA_WIDTH=32, parameter SHIFT_WIDTH=5) (
        input [DATA_WIDTH-1:0] d_in,
        input [SHIFT_WIDTH-1:0] shift,
        input arithOrLogic, // SRA or SRL
        input leftOrRight, // shift left or right
        output [DATA_WIDTH-1:0] d_out);


    wire M1_00, M1_01, M1_02, M1_03, M1_04, M1_05, M1_06, M1_07, M1_08, M1_09, M1_10, M1_11, M1_12, M1_13, M1_14, M1_15, M1_16, M1_17, M1_18, M1_19, M1_20, M1_21, M1_22, M1_23, M1_24, M1_25, M1_26, M1_27, M1_28, M1_29, M1_30, M1_31;
    wire M2_00, M2_01, M2_02, M2_03, M2_04, M2_05, M2_06, M2_07, M2_08, M2_09, M2_10, M2_11, M2_12, M2_13, M2_14, M2_15, M2_16, M2_17, M2_18, M2_19, M2_20, M2_21, M2_22, M2_23, M2_24, M2_25, M2_26, M2_27, M2_28, M2_29, M2_30, M2_31;
    wire M3_00, M3_01, M3_02, M3_03, M3_04, M3_05, M3_06, M3_07, M3_08, M3_09, M3_10, M3_11, M3_12, M3_13, M3_14, M3_15, M3_16, M3_17, M3_18, M3_19, M3_20, M3_21, M3_22, M3_23, M3_24, M3_25, M3_26, M3_27, M3_28, M3_29, M3_30, M3_31;
    wire M4_00, M4_01, M4_02, M4_03, M4_04, M4_05, M4_06, M4_07, M4_08, M4_09, M4_10, M4_11, M4_12, M4_13, M4_14, M4_15, M4_16, M4_17, M4_18, M4_19, M4_20, M4_21, M4_22, M4_23, M4_24, M4_25, M4_26, M4_27, M4_28, M4_29, M4_30, M4_31;
    wire msbFill;  // is shift right arithmatic, fill the msb with d[DATA_WIDTH-1], otherwish fill msb with 0.
    wire [DATA_WIDTH-1: 0] shifter_d_in, shifter_d_out; // we only implement shift right in shift array, shift left is finishing by turning over the input and turning over the output of the shift array.

    assign msbFill=arithOrLogic?0:d_in[DATA_WIDTH-1];
    assign shifter_d_in=leftOrRight? d_in :{d_in[0], d_in[1], d_in[2], d_in[3], d_in[4], d_in[5], d_in[6], d_in[7], d_in[8], d_in[9], d_in[10], d_in[11], d_in[12], d_in[13], d_in[14], d_in[15], d_in[16], d_in[17], d_in[18], d_in[19], d_in[20], d_in[21], d_in[22], d_in[23], d_in[24], d_in[25], d_in[26], d_in[27], d_in[28], d_in[29], d_in[30], d_in[31]};

    // shift array logic begin
    // --------first column of shiter array: first shift column can choose shift by 0 bit or 1 bit
    assign M1_00=shift[0]?shifter_d_in[1] :shifter_d_in[0];
    assign M1_01=shift[0]?shifter_d_in[2] :shifter_d_in[1];
    assign M1_02=shift[0]?shifter_d_in[3] :shifter_d_in[2];
    assign M1_03=shift[0]?shifter_d_in[4] :shifter_d_in[3];
    assign M1_04=shift[0]?shifter_d_in[5] :shifter_d_in[4];
    assign M1_05=shift[0]?shifter_d_in[6] :shifter_d_in[5];
    assign M1_06=shift[0]?shifter_d_in[7] :shifter_d_in[6];
    assign M1_07=shift[0]?shifter_d_in[8] :shifter_d_in[7];
    assign M1_08=shift[0]?shifter_d_in[9] :shifter_d_in[8];
    assign M1_09=shift[0]?shifter_d_in[10]:shifter_d_in[9];
    assign M1_10=shift[0]?shifter_d_in[11]:shifter_d_in[10];
    assign M1_11=shift[0]?shifter_d_in[12]:shifter_d_in[11];
    assign M1_12=shift[0]?shifter_d_in[13]:shifter_d_in[12];
    assign M1_13=shift[0]?shifter_d_in[14]:shifter_d_in[13];
    assign M1_14=shift[0]?shifter_d_in[15]:shifter_d_in[14];
    assign M1_15=shift[0]?shifter_d_in[16]:shifter_d_in[15];
    assign M1_16=shift[0]?shifter_d_in[17]:shifter_d_in[16];
    assign M1_17=shift[0]?shifter_d_in[18]:shifter_d_in[17];
    assign M1_18=shift[0]?shifter_d_in[19]:shifter_d_in[18];
    assign M1_19=shift[0]?shifter_d_in[20]:shifter_d_in[19];
    assign M1_20=shift[0]?shifter_d_in[21]:shifter_d_in[20];
    assign M1_21=shift[0]?shifter_d_in[22]:shifter_d_in[21];
    assign M1_22=shift[0]?shifter_d_in[23]:shifter_d_in[22];
    assign M1_23=shift[0]?shifter_d_in[24]:shifter_d_in[23];
    assign M1_24=shift[0]?shifter_d_in[25]:shifter_d_in[24];
    assign M1_25=shift[0]?shifter_d_in[26]:shifter_d_in[25];
    assign M1_26=shift[0]?shifter_d_in[27]:shifter_d_in[26];
    assign M1_27=shift[0]?shifter_d_in[28]:shifter_d_in[27];
    assign M1_28=shift[0]?shifter_d_in[29]:shifter_d_in[28];
    assign M1_29=shift[0]?shifter_d_in[30]:shifter_d_in[29];
    assign M1_30=shift[0]?shifter_d_in[31]:shifter_d_in[30];
    assign M1_31=shift[0]?msbFill         :shifter_d_in[31];
    // --------second column of shiter array: second shift column can choose shift by 0 bit or 2 bit
    assign M2_00=shift[1]?M1_02   :M1_00;
    assign M2_01=shift[1]?M1_03   :M1_01;
    assign M2_02=shift[1]?M1_04   :M1_02;
    assign M2_03=shift[1]?M1_05   :M1_03;
    assign M2_04=shift[1]?M1_06   :M1_04;
    assign M2_05=shift[1]?M1_07   :M1_05;
    assign M2_06=shift[1]?M1_08   :M1_06;
    assign M2_07=shift[1]?M1_09   :M1_07;
    assign M2_08=shift[1]?M1_10   :M1_08;
    assign M2_09=shift[1]?M1_11   :M1_09;
    assign M2_10=shift[1]?M1_12   :M1_10;
    assign M2_11=shift[1]?M1_13   :M1_11;
    assign M2_12=shift[1]?M1_14   :M1_12;
    assign M2_13=shift[1]?M1_15   :M1_13;
    assign M2_14=shift[1]?M1_16   :M1_14;
    assign M2_15=shift[1]?M1_17   :M1_15;
    assign M2_16=shift[1]?M1_18   :M1_16;
    assign M2_17=shift[1]?M1_19   :M1_17;
    assign M2_18=shift[1]?M1_20   :M1_18;
    assign M2_19=shift[1]?M1_21   :M1_19;
    assign M2_20=shift[1]?M1_22   :M1_20;
    assign M2_21=shift[1]?M1_23   :M1_21;
    assign M2_22=shift[1]?M1_24   :M1_22;
    assign M2_23=shift[1]?M1_25   :M1_23;
    assign M2_24=shift[1]?M1_26   :M1_24;
    assign M2_25=shift[1]?M1_27   :M1_25;
    assign M2_26=shift[1]?M1_28   :M1_26;
    assign M2_27=shift[1]?M1_29   :M1_27;
    assign M2_28=shift[1]?M1_30   :M1_28;
    assign M2_29=shift[1]?M1_31   :M1_29;
    assign M2_30=shift[1]?msbFill :M1_30;
    ;
    assign M2_31=shift[1]?msbFill :M1_31;
    ;
    // --------third column of shiter array: third shift column can choose shift by 0 bit or 4 bit
    assign M3_00=shift[2]?M2_04   :M2_00;
    assign M3_01=shift[2]?M2_05   :M2_01;
    assign M3_02=shift[2]?M2_06   :M2_02;
    assign M3_03=shift[2]?M2_07   :M2_03;
    assign M3_04=shift[2]?M2_08   :M2_04;
    assign M3_05=shift[2]?M2_09   :M2_05;
    assign M3_06=shift[2]?M2_10   :M2_06;
    assign M3_07=shift[2]?M2_11   :M2_07;
    assign M3_08=shift[2]?M2_12   :M2_08;
    assign M3_09=shift[2]?M2_13   :M2_09;
    assign M3_10=shift[2]?M2_14   :M2_10;
    assign M3_11=shift[2]?M2_15   :M2_11;
    assign M3_12=shift[2]?M2_16   :M2_12;
    assign M3_13=shift[2]?M2_17   :M2_13;
    assign M3_14=shift[2]?M2_18   :M2_14;
    assign M3_15=shift[2]?M2_19   :M2_15;
    assign M3_16=shift[2]?M2_20   :M2_16;
    assign M3_17=shift[2]?M2_21   :M2_17;
    assign M3_18=shift[2]?M2_22   :M2_18;
    assign M3_19=shift[2]?M2_23   :M2_19;
    assign M3_20=shift[2]?M2_24   :M2_20;
    assign M3_21=shift[2]?M2_25   :M2_21;
    assign M3_22=shift[2]?M2_26   :M2_22;
    assign M3_23=shift[2]?M2_27   :M2_23;
    assign M3_24=shift[2]?M2_28   :M2_24;
    assign M3_25=shift[2]?M2_29   :M2_25;
    assign M3_26=shift[2]?M2_30   :M2_26;
    assign M3_27=shift[2]?M2_31   :M2_27;
    assign M3_28=shift[2]?msbFill :M2_28;
    assign M3_29=shift[2]?msbFill :M2_29;
    assign M3_30=shift[2]?msbFill :M2_30;
    ;
    assign M3_31=shift[2]?msbFill :M2_31;
    ;
    // --------forth column of shiter array: forth shift column can choose shift by 0 bit or 8 bit
    assign M4_00=shift[3]?M3_08  :M3_00;
    assign M4_01=shift[3]?M3_09   :M3_01;
    assign M4_02=shift[3]?M3_10   :M3_02;
    assign M4_03=shift[3]?M3_11   :M3_03;
    assign M4_04=shift[3]?M3_12   :M3_04;
    assign M4_05=shift[3]?M3_13   :M3_05;
    assign M4_06=shift[3]?M3_14   :M3_06;
    assign M4_07=shift[3]?M3_15   :M3_07;
    assign M4_08=shift[3]?M3_16   :M3_08;
    assign M4_09=shift[3]?M3_17   :M3_09;
    assign M4_10=shift[3]?M3_18   :M3_10;
    assign M4_11=shift[3]?M3_19   :M3_11;
    assign M4_12=shift[3]?M3_20   :M3_12;
    assign M4_13=shift[3]?M3_21   :M3_13;
    assign M4_14=shift[3]?M3_22   :M3_14;
    assign M4_15=shift[3]?M3_23   :M3_15;
    assign M4_16=shift[3]?M3_24   :M3_16;
    assign M4_17=shift[3]?M3_25   :M3_17;
    assign M4_18=shift[3]?M3_26   :M3_18;
    assign M4_19=shift[3]?M3_27   :M3_19;
    assign M4_20=shift[3]?M3_28   :M3_20;
    assign M4_21=shift[3]?M3_29   :M3_21;
    assign M4_22=shift[3]?M3_30   :M3_22;
    assign M4_23=shift[3]?M3_31   :M3_23;
    assign M4_24=shift[3]?msbFill :M3_24;
    assign M4_25=shift[3]?msbFill :M3_25;
    assign M4_26=shift[3]?msbFill :M3_26;
    assign M4_27=shift[3]?msbFill :M3_27;
    assign M4_28=shift[3]?msbFill :M3_28;
    assign M4_29=shift[3]?msbFill :M3_29;
    assign M4_30=shift[3]?msbFill :M3_30;
    ;
    assign M4_31=shift[3]?msbFill :M3_31;
    ;
    // --------output column of shiter array: output shift column can choose shift by 0 bit or 16 bit
    assign shifter_d_out[0 ]=shift[4]?M4_16   :M4_00;
    assign shifter_d_out[1 ]=shift[4]?M4_17   :M4_01;
    assign shifter_d_out[2 ]=shift[4]?M4_18   :M4_02;
    assign shifter_d_out[3 ]=shift[4]?M4_19   :M4_03;
    assign shifter_d_out[4 ]=shift[4]?M4_20   :M4_04;
    assign shifter_d_out[5 ]=shift[4]?M4_21   :M4_05;
    assign shifter_d_out[6 ]=shift[4]?M4_22   :M4_06;
    assign shifter_d_out[7 ]=shift[4]?M4_23   :M4_07;
    assign shifter_d_out[8 ]=shift[4]?M4_24   :M4_08;
    assign shifter_d_out[9 ]=shift[4]?M4_25   :M4_09;
    assign shifter_d_out[10]=shift[4]?M4_26   :M4_10;
    assign shifter_d_out[11]=shift[4]?M4_27   :M4_11;
    assign shifter_d_out[12]=shift[4]?M4_28   :M4_12;
    assign shifter_d_out[13]=shift[4]?M4_29   :M4_13;
    assign shifter_d_out[14]=shift[4]?M4_30   :M4_14;
    assign shifter_d_out[15]=shift[4]?M4_31   :M4_15;
    assign shifter_d_out[16]=shift[4]?msbFill :M4_16;
    assign shifter_d_out[17]=shift[4]?msbFill :M4_17;
    assign shifter_d_out[18]=shift[4]?msbFill :M4_18;
    assign shifter_d_out[19]=shift[4]?msbFill :M4_19;
    assign shifter_d_out[20]=shift[4]?msbFill :M4_20;
    assign shifter_d_out[21]=shift[4]?msbFill :M4_21;
    assign shifter_d_out[22]=shift[4]?msbFill :M4_22;
    assign shifter_d_out[23]=shift[4]?msbFill :M4_23;
    assign shifter_d_out[24]=shift[4]?msbFill :M4_24;
    assign shifter_d_out[25]=shift[4]?msbFill :M4_25;
    assign shifter_d_out[26]=shift[4]?msbFill :M4_26;
    assign shifter_d_out[27]=shift[4]?msbFill :M4_27;
    assign shifter_d_out[28]=shift[4]?msbFill :M4_28;
    assign shifter_d_out[29]=shift[4]?msbFill :M4_29;
    assign shifter_d_out[30]=shift[4]?msbFill :M4_30;
    ;
    assign shifter_d_out[31]=shift[4]?msbFill :M4_31;
    ;
    // shift array logic end

    assign d_out=leftOrRight? shifter_d_out: {shifter_d_out[0], shifter_d_out[1], shifter_d_out[2], shifter_d_out[3], shifter_d_out[4], shifter_d_out[5], shifter_d_out[6], shifter_d_out[7], shifter_d_out[8], shifter_d_out[9], shifter_d_out[10], shifter_d_out[11], shifter_d_out[12], shifter_d_out[13], shifter_d_out[14], shifter_d_out[15], shifter_d_out[16], shifter_d_out[17], shifter_d_out[18], shifter_d_out[19], shifter_d_out[20], shifter_d_out[21], shifter_d_out[22], shifter_d_out[23], shifter_d_out[24], shifter_d_out[25], shifter_d_out[26], shifter_d_out[27], shifter_d_out[28], shifter_d_out[29], shifter_d_out[30], shifter_d_out[31]};
endmodule
