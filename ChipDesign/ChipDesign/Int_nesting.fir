circuit Int_nesting :
  module Int_status :
    input clock : Clock
    input reset : Reset
    output io : { flip pri_in : UInt<5>, pri_out : UInt<5>, flip ID_in : UInt<4>, ID_out : UInt<4>, flip act : UInt<1>, flip deact : UInt<1>, flip nest : UInt<1>, flip denest : UInt<1>, status : UInt<1>}

    reg Priority : UInt<5>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 6:23]
    reg Int_ID : UInt<4>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 7:21]
    reg Status : UInt<2>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 8:21]
    io.pri_out <= Priority @[Int_nesting.scala 22:13]
    io.ID_out <= Int_ID @[Int_nesting.scala 23:12]
    io.status <= Status @[Int_nesting.scala 24:12]
    node _T = eq(Status, UInt<1>("h0")) @[Int_nesting.scala 26:14]
    when _T : @[Int_nesting.scala 27:3]
      node _T_1 = bits(io.act, 0, 0) @[Int_nesting.scala 28:17]
      when _T_1 : @[Int_nesting.scala 29:5]
        Priority <= io.pri_in @[Int_nesting.scala 30:15]
        Int_ID <= io.ID_in @[Int_nesting.scala 31:13]
        Status <= UInt<1>("h1") @[Int_nesting.scala 32:13]
    else :
      node _T_2 = eq(Status, UInt<1>("h1")) @[Int_nesting.scala 34:20]
      when _T_2 : @[Int_nesting.scala 35:3]
        node _T_3 = bits(io.deact, 0, 0) @[Int_nesting.scala 36:19]
        when _T_3 : @[Int_nesting.scala 37:5]
          Priority <= UInt<1>("h0") @[Int_nesting.scala 38:15]
          Int_ID <= UInt<1>("h0") @[Int_nesting.scala 39:13]
          Status <= UInt<1>("h0") @[Int_nesting.scala 40:13]
        else :
          node _T_4 = eq(io.nest, UInt<1>("h1")) @[Int_nesting.scala 41:23]
          when _T_4 : @[Int_nesting.scala 42:5]
            Status <= UInt<2>("h3") @[Int_nesting.scala 43:13]
          else :
            node _T_5 = bits(io.act, 0, 0) @[Int_nesting.scala 44:23]
            when _T_5 : @[Int_nesting.scala 44:31]
              Priority <= io.pri_in @[Int_nesting.scala 45:16]
              Int_ID <= io.ID_in @[Int_nesting.scala 46:14]
      else :
        node _T_6 = eq(io.denest, UInt<1>("h1")) @[Int_nesting.scala 50:19]
        when _T_6 : @[Int_nesting.scala 51:5]
          Status <= UInt<1>("h1") @[Int_nesting.scala 52:13]

  module Int_status_1 :
    input clock : Clock
    input reset : Reset
    output io : { flip pri_in : UInt<5>, pri_out : UInt<5>, flip ID_in : UInt<4>, ID_out : UInt<4>, flip act : UInt<1>, flip deact : UInt<1>, flip nest : UInt<1>, flip denest : UInt<1>, status : UInt<1>}

    reg Priority : UInt<5>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 6:23]
    reg Int_ID : UInt<4>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 7:21]
    reg Status : UInt<2>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 8:21]
    io.pri_out <= Priority @[Int_nesting.scala 22:13]
    io.ID_out <= Int_ID @[Int_nesting.scala 23:12]
    io.status <= Status @[Int_nesting.scala 24:12]
    node _T = eq(Status, UInt<1>("h0")) @[Int_nesting.scala 26:14]
    when _T : @[Int_nesting.scala 27:3]
      node _T_1 = bits(io.act, 0, 0) @[Int_nesting.scala 28:17]
      when _T_1 : @[Int_nesting.scala 29:5]
        Priority <= io.pri_in @[Int_nesting.scala 30:15]
        Int_ID <= io.ID_in @[Int_nesting.scala 31:13]
        Status <= UInt<1>("h1") @[Int_nesting.scala 32:13]
    else :
      node _T_2 = eq(Status, UInt<1>("h1")) @[Int_nesting.scala 34:20]
      when _T_2 : @[Int_nesting.scala 35:3]
        node _T_3 = bits(io.deact, 0, 0) @[Int_nesting.scala 36:19]
        when _T_3 : @[Int_nesting.scala 37:5]
          Priority <= UInt<1>("h0") @[Int_nesting.scala 38:15]
          Int_ID <= UInt<1>("h0") @[Int_nesting.scala 39:13]
          Status <= UInt<1>("h0") @[Int_nesting.scala 40:13]
        else :
          node _T_4 = eq(io.nest, UInt<1>("h1")) @[Int_nesting.scala 41:23]
          when _T_4 : @[Int_nesting.scala 42:5]
            Status <= UInt<2>("h3") @[Int_nesting.scala 43:13]
          else :
            node _T_5 = bits(io.act, 0, 0) @[Int_nesting.scala 44:23]
            when _T_5 : @[Int_nesting.scala 44:31]
              Priority <= io.pri_in @[Int_nesting.scala 45:16]
              Int_ID <= io.ID_in @[Int_nesting.scala 46:14]
      else :
        node _T_6 = eq(io.denest, UInt<1>("h1")) @[Int_nesting.scala 50:19]
        when _T_6 : @[Int_nesting.scala 51:5]
          Status <= UInt<1>("h1") @[Int_nesting.scala 52:13]

  module Int_status_2 :
    input clock : Clock
    input reset : Reset
    output io : { flip pri_in : UInt<5>, pri_out : UInt<5>, flip ID_in : UInt<4>, ID_out : UInt<4>, flip act : UInt<1>, flip deact : UInt<1>, flip nest : UInt<1>, flip denest : UInt<1>, status : UInt<1>}

    reg Priority : UInt<5>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 6:23]
    reg Int_ID : UInt<4>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 7:21]
    reg Status : UInt<2>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 8:21]
    io.pri_out <= Priority @[Int_nesting.scala 22:13]
    io.ID_out <= Int_ID @[Int_nesting.scala 23:12]
    io.status <= Status @[Int_nesting.scala 24:12]
    node _T = eq(Status, UInt<1>("h0")) @[Int_nesting.scala 26:14]
    when _T : @[Int_nesting.scala 27:3]
      node _T_1 = bits(io.act, 0, 0) @[Int_nesting.scala 28:17]
      when _T_1 : @[Int_nesting.scala 29:5]
        Priority <= io.pri_in @[Int_nesting.scala 30:15]
        Int_ID <= io.ID_in @[Int_nesting.scala 31:13]
        Status <= UInt<1>("h1") @[Int_nesting.scala 32:13]
    else :
      node _T_2 = eq(Status, UInt<1>("h1")) @[Int_nesting.scala 34:20]
      when _T_2 : @[Int_nesting.scala 35:3]
        node _T_3 = bits(io.deact, 0, 0) @[Int_nesting.scala 36:19]
        when _T_3 : @[Int_nesting.scala 37:5]
          Priority <= UInt<1>("h0") @[Int_nesting.scala 38:15]
          Int_ID <= UInt<1>("h0") @[Int_nesting.scala 39:13]
          Status <= UInt<1>("h0") @[Int_nesting.scala 40:13]
        else :
          node _T_4 = eq(io.nest, UInt<1>("h1")) @[Int_nesting.scala 41:23]
          when _T_4 : @[Int_nesting.scala 42:5]
            Status <= UInt<2>("h3") @[Int_nesting.scala 43:13]
          else :
            node _T_5 = bits(io.act, 0, 0) @[Int_nesting.scala 44:23]
            when _T_5 : @[Int_nesting.scala 44:31]
              Priority <= io.pri_in @[Int_nesting.scala 45:16]
              Int_ID <= io.ID_in @[Int_nesting.scala 46:14]
      else :
        node _T_6 = eq(io.denest, UInt<1>("h1")) @[Int_nesting.scala 50:19]
        when _T_6 : @[Int_nesting.scala 51:5]
          Status <= UInt<1>("h1") @[Int_nesting.scala 52:13]

  module Int_status_3 :
    input clock : Clock
    input reset : Reset
    output io : { flip pri_in : UInt<5>, pri_out : UInt<5>, flip ID_in : UInt<4>, ID_out : UInt<4>, flip act : UInt<1>, flip deact : UInt<1>, flip nest : UInt<1>, flip denest : UInt<1>, status : UInt<1>}

    reg Priority : UInt<5>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 6:23]
    reg Int_ID : UInt<4>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 7:21]
    reg Status : UInt<2>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 8:21]
    io.pri_out <= Priority @[Int_nesting.scala 22:13]
    io.ID_out <= Int_ID @[Int_nesting.scala 23:12]
    io.status <= Status @[Int_nesting.scala 24:12]
    node _T = eq(Status, UInt<1>("h0")) @[Int_nesting.scala 26:14]
    when _T : @[Int_nesting.scala 27:3]
      node _T_1 = bits(io.act, 0, 0) @[Int_nesting.scala 28:17]
      when _T_1 : @[Int_nesting.scala 29:5]
        Priority <= io.pri_in @[Int_nesting.scala 30:15]
        Int_ID <= io.ID_in @[Int_nesting.scala 31:13]
        Status <= UInt<1>("h1") @[Int_nesting.scala 32:13]
    else :
      node _T_2 = eq(Status, UInt<1>("h1")) @[Int_nesting.scala 34:20]
      when _T_2 : @[Int_nesting.scala 35:3]
        node _T_3 = bits(io.deact, 0, 0) @[Int_nesting.scala 36:19]
        when _T_3 : @[Int_nesting.scala 37:5]
          Priority <= UInt<1>("h0") @[Int_nesting.scala 38:15]
          Int_ID <= UInt<1>("h0") @[Int_nesting.scala 39:13]
          Status <= UInt<1>("h0") @[Int_nesting.scala 40:13]
        else :
          node _T_4 = eq(io.nest, UInt<1>("h1")) @[Int_nesting.scala 41:23]
          when _T_4 : @[Int_nesting.scala 42:5]
            Status <= UInt<2>("h3") @[Int_nesting.scala 43:13]
          else :
            node _T_5 = bits(io.act, 0, 0) @[Int_nesting.scala 44:23]
            when _T_5 : @[Int_nesting.scala 44:31]
              Priority <= io.pri_in @[Int_nesting.scala 45:16]
              Int_ID <= io.ID_in @[Int_nesting.scala 46:14]
      else :
        node _T_6 = eq(io.denest, UInt<1>("h1")) @[Int_nesting.scala 50:19]
        when _T_6 : @[Int_nesting.scala 51:5]
          Status <= UInt<1>("h1") @[Int_nesting.scala 52:13]

  module Int_nesting :
    input clock : Clock
    input reset : UInt<1>
    output io : { empty : UInt<1>, current_pri : UInt<5>, flip nest_disable : UInt<1>, nested_pri : UInt<5>, flip coming_pri : UInt<5>, is_nesting : UInt<1>, current_ID : UInt<4>, flip coming_ID : UInt<4>, nested_ID : UInt<4>, en_nest : UInt<1>, de_nest : UInt<1>, flip is_pending : UInt<1>, flip int_fin : UInt<1>}

    inst Int_status of Int_status @[Int_nesting.scala 63:23]
    Int_status.clock <= clock
    Int_status.reset <= reset
    inst Int_status_1 of Int_status_1 @[Int_nesting.scala 63:23]
    Int_status_1.clock <= clock
    Int_status_1.reset <= reset
    inst Int_status_2 of Int_status_2 @[Int_nesting.scala 63:23]
    Int_status_2.clock <= clock
    Int_status_2.reset <= reset
    inst Int_status_3 of Int_status_3 @[Int_nesting.scala 63:23]
    Int_status_3.clock <= clock
    Int_status_3.reset <= reset
    reg StatusPtr : UInt<2>, clock with :
      reset => (reset, UInt<1>("h0")) @[Int_nesting.scala 65:24]
    wire CurrentID : UInt<4> @[Int_nesting.scala 66:21]
    wire CurrentPri : UInt<5> @[Int_nesting.scala 67:22]
    wire NestedID : UInt<4> @[Int_nesting.scala 68:20]
    wire NestedPri : UInt<5> @[Int_nesting.scala 69:21]
    wire EnNest : UInt<1>
    EnNest <= UInt<1>("h0")
    wire DeNest : UInt<1>
    DeNest <= UInt<1>("h0")
    wire StatusAct : UInt<4>
    StatusAct <= UInt<1>("h0")
    wire StatusDeact : UInt<4>
    StatusDeact <= UInt<1>("h0")
    wire StatusNest : UInt<4>
    StatusNest <= UInt<1>("h0")
    wire StatusDenest : UInt<4>
    StatusDenest <= UInt<1>("h0")
    wire _WIRE : UInt<4>
    _WIRE <= UInt<1>("h0")
    wire _WIRE_1 : UInt<5>
    _WIRE_1 <= UInt<1>("h0")
    wire _WIRE_2 : UInt<4>
    _WIRE_2 <= UInt<1>("h0")
    wire _WIRE_3 : UInt<5>
    _WIRE_3 <= UInt<1>("h0")
    wire _WIRE_4 : UInt<4>
    _WIRE_4 <= UInt<1>("h0")
    wire _WIRE_5 : UInt<5>
    _WIRE_5 <= UInt<1>("h0")
    wire _WIRE_6 : UInt<4>
    _WIRE_6 <= UInt<1>("h0")
    wire _WIRE_7 : UInt<5>
    _WIRE_7 <= UInt<1>("h0")
    node _io_empty_T = eq(StatusPtr, UInt<1>("h0")) @[Int_nesting.scala 103:23]
    node _io_empty_T_1 = eq(Int_status.io.status, UInt<1>("h0")) @[Int_nesting.scala 103:51]
    node _io_empty_T_2 = and(_io_empty_T, _io_empty_T_1) @[Int_nesting.scala 103:30]
    io.empty <= _io_empty_T_2 @[Int_nesting.scala 103:11]
    io.current_ID <= CurrentID @[Int_nesting.scala 104:16]
    io.current_pri <= CurrentPri @[Int_nesting.scala 105:17]
    node _io_is_nesting_T = neq(StatusPtr, UInt<1>("h0")) @[Int_nesting.scala 106:28]
    io.is_nesting <= _io_is_nesting_T @[Int_nesting.scala 106:16]
    io.nested_ID <= NestedID @[Int_nesting.scala 107:15]
    io.nested_pri <= NestedPri @[Int_nesting.scala 108:16]
    io.en_nest <= EnNest @[Int_nesting.scala 109:13]
    io.de_nest <= DeNest @[Int_nesting.scala 110:13]
    node _T = eq(io.nest_disable, UInt<1>("h0")) @[Int_nesting.scala 112:23]
    when _T : @[Int_nesting.scala 113:3]
      node _T_1 = bits(io.is_pending, 0, 0) @[Int_nesting.scala 114:24]
      when _T_1 : @[Int_nesting.scala 115:5]
        node _T_2 = eq(StatusPtr, UInt<1>("h0")) @[Int_nesting.scala 116:22]
        node _T_3 = eq(Int_status.io.status, UInt<1>("h0")) @[Int_nesting.scala 116:50]
        node _T_4 = and(_T_2, _T_3) @[Int_nesting.scala 116:29]
        when _T_4 : @[Int_nesting.scala 117:7]
          StatusAct <= UInt<1>("h1") @[Int_nesting.scala 118:18]
          _WIRE <= io.coming_ID @[Int_nesting.scala 119:22]
          _WIRE_1 <= io.coming_pri @[Int_nesting.scala 120:23]
        else :
          node _T_5 = eq(StatusPtr, UInt<1>("h0")) @[Int_nesting.scala 121:28]
          node _T_6 = eq(Int_status.io.status, UInt<1>("h1")) @[Int_nesting.scala 121:56]
          node _T_7 = and(_T_5, _T_6) @[Int_nesting.scala 121:35]
          when _T_7 : @[Int_nesting.scala 122:7]
            node _T_8 = eq(io.int_fin, UInt<1>("h1")) @[Int_nesting.scala 123:24]
            when _T_8 : @[Int_nesting.scala 124:9]
              StatusAct <= UInt<1>("h1") @[Int_nesting.scala 125:20]
              _WIRE <= io.coming_ID @[Int_nesting.scala 126:25]
              _WIRE_1 <= io.coming_pri @[Int_nesting.scala 127:26]
            else :
              node _T_9 = bits(io.coming_pri, 4, 3) @[Int_nesting.scala 128:33]
              node _T_10 = bits(CurrentPri, 4, 3) @[Int_nesting.scala 128:68]
              node _T_11 = gt(_T_9, _T_10) @[Int_nesting.scala 128:57]
              when _T_11 : @[Int_nesting.scala 129:9]
                StatusPtr <= UInt<1>("h1") @[Int_nesting.scala 130:20]
                StatusAct <= UInt<2>("h2") @[Int_nesting.scala 131:20]
                StatusNest <= UInt<1>("h1") @[Int_nesting.scala 132:21]
                _WIRE_2 <= io.coming_ID @[Int_nesting.scala 133:24]
                _WIRE_3 <= io.coming_pri @[Int_nesting.scala 134:26]
                EnNest <= UInt<1>("h1") @[Int_nesting.scala 135:17]
          else :
            node _T_12 = eq(StatusPtr, UInt<2>("h3")) @[Int_nesting.scala 137:27]
            when _T_12 : @[Int_nesting.scala 138:7]
              node _T_13 = eq(io.int_fin, UInt<1>("h1")) @[Int_nesting.scala 139:25]
              when _T_13 : @[Int_nesting.scala 140:9]
                node _T_14 = bits(io.coming_pri, 4, 3) @[Int_nesting.scala 141:29]
                node _T_15 = bits(NestedPri, 4, 3) @[Int_nesting.scala 141:63]
                node _T_16 = gt(_T_14, _T_15) @[Int_nesting.scala 141:53]
                when _T_16 : @[Int_nesting.scala 142:11]
                  StatusAct <= UInt<4>("h8") @[Int_nesting.scala 143:22]
                  _WIRE_6 <= io.coming_ID @[Int_nesting.scala 144:26]
                  _WIRE_7 <= io.coming_pri @[Int_nesting.scala 145:27]
                else :
                  StatusDeact <= UInt<4>("h8") @[Int_nesting.scala 148:24]
                  StatusDenest <= UInt<3>("h4") @[Int_nesting.scala 149:25]
                  StatusPtr <= UInt<2>("h2") @[Int_nesting.scala 150:22]
                  DeNest <= UInt<1>("h1") @[Int_nesting.scala 151:19]
            else :
              node _T_17 = eq(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 154:27]
              when _T_17 : @[Int_nesting.scala 155:7]
                node _T_18 = eq(io.int_fin, UInt<1>("h1")) @[Int_nesting.scala 156:25]
                when _T_18 : @[Int_nesting.scala 157:9]
                  node _T_19 = bits(io.coming_pri, 4, 3) @[Int_nesting.scala 158:29]
                  node _T_20 = bits(NestedPri, 4, 3) @[Int_nesting.scala 158:68]
                  node _T_21 = gt(_T_19, _T_20) @[Int_nesting.scala 158:57]
                  when _T_21 : @[Int_nesting.scala 159:11]
                    StatusAct <= UInt<2>("h2") @[Int_nesting.scala 160:22]
                    _WIRE_2 <= io.coming_ID @[Int_nesting.scala 161:27]
                    _WIRE_3 <= io.coming_pri @[Int_nesting.scala 162:28]
                  else :
                    StatusDeact <= UInt<2>("h2") @[Int_nesting.scala 165:24]
                    StatusDenest <= UInt<1>("h1") @[Int_nesting.scala 166:25]
                    StatusPtr <= UInt<1>("h0") @[Int_nesting.scala 167:23]
                    DeNest <= UInt<1>("h1") @[Int_nesting.scala 168:20]
                else :
                  node _T_22 = bits(io.coming_pri, 4, 3) @[Int_nesting.scala 172:29]
                  node _T_23 = bits(CurrentPri, 4, 3) @[Int_nesting.scala 172:69]
                  node _T_24 = gt(_T_22, _T_23) @[Int_nesting.scala 172:57]
                  when _T_24 : @[Int_nesting.scala 173:11]
                    _WIRE_4 <= io.coming_ID @[Int_nesting.scala 174:26]
                    _WIRE_5 <= io.coming_pri @[Int_nesting.scala 175:27]
                    StatusAct <= UInt<3>("h4") @[Int_nesting.scala 176:22]
                    StatusNest <= UInt<2>("h2") @[Int_nesting.scala 177:23]
                    EnNest <= UInt<1>("h1") @[Int_nesting.scala 178:20]
                    StatusPtr <= UInt<2>("h2") @[Int_nesting.scala 179:22]
              else :
                node _T_25 = eq(io.int_fin, UInt<1>("h1")) @[Int_nesting.scala 184:25]
                when _T_25 : @[Int_nesting.scala 185:9]
                  node _T_26 = bits(io.coming_pri, 4, 3) @[Int_nesting.scala 186:29]
                  node _T_27 = bits(NestedPri, 4, 3) @[Int_nesting.scala 186:68]
                  node _T_28 = gt(_T_26, _T_27) @[Int_nesting.scala 186:57]
                  when _T_28 : @[Int_nesting.scala 187:11]
                    StatusAct <= UInt<3>("h4") @[Int_nesting.scala 188:22]
                    _WIRE_4 <= io.coming_ID @[Int_nesting.scala 189:27]
                    _WIRE_5 <= io.coming_pri @[Int_nesting.scala 190:28]
                  else :
                    StatusDeact <= UInt<3>("h4") @[Int_nesting.scala 193:25]
                    StatusPtr <= UInt<2>("h2") @[Int_nesting.scala 194:23]
                    DeNest <= UInt<1>("h1") @[Int_nesting.scala 195:20]
                else :
                  node _T_29 = bits(io.coming_pri, 4, 3) @[Int_nesting.scala 199:29]
                  node _T_30 = bits(CurrentPri, 4, 3) @[Int_nesting.scala 199:69]
                  node _T_31 = gt(_T_29, _T_30) @[Int_nesting.scala 199:57]
                  when _T_31 : @[Int_nesting.scala 200:11]
                    _WIRE_6 <= io.coming_ID @[Int_nesting.scala 201:26]
                    _WIRE_7 <= io.coming_pri @[Int_nesting.scala 202:27]
                    StatusNest <= UInt<3>("h4") @[Int_nesting.scala 203:23]
                    StatusAct <= UInt<4>("h8") @[Int_nesting.scala 204:22]
                    StatusPtr <= UInt<2>("h3") @[Int_nesting.scala 205:22]
                    EnNest <= UInt<1>("h1") @[Int_nesting.scala 206:20]
      else :
        node _T_32 = bits(io.int_fin, 0, 0) @[Int_nesting.scala 210:27]
        when _T_32 : @[Int_nesting.scala 211:5]
          node _T_33 = eq(StatusPtr, UInt<1>("h0")) @[Int_nesting.scala 212:21]
          when _T_33 : @[Int_nesting.scala 213:7]
            StatusDeact <= UInt<1>("h1") @[Int_nesting.scala 214:20]
          else :
            node _StatusDeact_T = eq(StatusPtr, UInt<2>("h3")) @[Int_nesting.scala 217:42]
            node _StatusDeact_T_1 = eq(StatusPtr, UInt<2>("h2")) @[Int_nesting.scala 217:61]
            node _StatusDeact_T_2 = cat(_StatusDeact_T, _StatusDeact_T_1) @[Cat.scala 33:92]
            node _StatusDeact_T_3 = eq(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 217:85]
            node _StatusDeact_T_4 = cat(_StatusDeact_T_3, UInt<1>("h0")) @[Cat.scala 33:92]
            node _StatusDeact_T_5 = cat(_StatusDeact_T_2, _StatusDeact_T_4) @[Cat.scala 33:92]
            StatusDeact <= _StatusDeact_T_5 @[Int_nesting.scala 217:21]
            node _StatusDenest_T = eq(StatusPtr, UInt<2>("h3")) @[Int_nesting.scala 218:53]
            node _StatusDenest_T_1 = cat(UInt<1>("h0"), _StatusDenest_T) @[Cat.scala 33:92]
            node _StatusDenest_T_2 = eq(StatusPtr, UInt<2>("h2")) @[Int_nesting.scala 218:77]
            node _StatusDenest_T_3 = eq(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 218:96]
            node _StatusDenest_T_4 = cat(_StatusDenest_T_2, _StatusDenest_T_3) @[Cat.scala 33:92]
            node _StatusDenest_T_5 = cat(_StatusDenest_T_1, _StatusDenest_T_4) @[Cat.scala 33:92]
            StatusDenest <= _StatusDenest_T_5 @[Int_nesting.scala 218:22]
            node _StatusPtr_T = sub(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 219:29]
            node _StatusPtr_T_1 = tail(_StatusPtr_T, 1) @[Int_nesting.scala 219:29]
            StatusPtr <= _StatusPtr_T_1 @[Int_nesting.scala 219:18]
    node _T_34 = bits(StatusAct, 0, 0) @[Int_nesting.scala 225:34]
    Int_status.io.act <= _T_34 @[Int_nesting.scala 225:23]
    node _T_35 = bits(StatusDeact, 0, 0) @[Int_nesting.scala 226:38]
    Int_status.io.deact <= _T_35 @[Int_nesting.scala 226:25]
    node _T_36 = bits(StatusNest, 0, 0) @[Int_nesting.scala 227:36]
    Int_status.io.nest <= _T_36 @[Int_nesting.scala 227:24]
    node _T_37 = bits(StatusDenest, 0, 0) @[Int_nesting.scala 228:40]
    Int_status.io.denest <= _T_37 @[Int_nesting.scala 228:26]
    Int_status.io.pri_in <= _WIRE_1 @[Int_nesting.scala 229:26]
    Int_status.io.ID_in <= _WIRE @[Int_nesting.scala 230:25]
    node _T_38 = bits(StatusAct, 1, 1) @[Int_nesting.scala 225:34]
    Int_status_1.io.act <= _T_38 @[Int_nesting.scala 225:23]
    node _T_39 = bits(StatusDeact, 1, 1) @[Int_nesting.scala 226:38]
    Int_status_1.io.deact <= _T_39 @[Int_nesting.scala 226:25]
    node _T_40 = bits(StatusNest, 1, 1) @[Int_nesting.scala 227:36]
    Int_status_1.io.nest <= _T_40 @[Int_nesting.scala 227:24]
    node _T_41 = bits(StatusDenest, 1, 1) @[Int_nesting.scala 228:40]
    Int_status_1.io.denest <= _T_41 @[Int_nesting.scala 228:26]
    Int_status_1.io.pri_in <= _WIRE_3 @[Int_nesting.scala 229:26]
    Int_status_1.io.ID_in <= _WIRE_2 @[Int_nesting.scala 230:25]
    node _T_42 = bits(StatusAct, 2, 2) @[Int_nesting.scala 225:34]
    Int_status_2.io.act <= _T_42 @[Int_nesting.scala 225:23]
    node _T_43 = bits(StatusDeact, 2, 2) @[Int_nesting.scala 226:38]
    Int_status_2.io.deact <= _T_43 @[Int_nesting.scala 226:25]
    node _T_44 = bits(StatusNest, 2, 2) @[Int_nesting.scala 227:36]
    Int_status_2.io.nest <= _T_44 @[Int_nesting.scala 227:24]
    node _T_45 = bits(StatusDenest, 2, 2) @[Int_nesting.scala 228:40]
    Int_status_2.io.denest <= _T_45 @[Int_nesting.scala 228:26]
    Int_status_2.io.pri_in <= _WIRE_5 @[Int_nesting.scala 229:26]
    Int_status_2.io.ID_in <= _WIRE_4 @[Int_nesting.scala 230:25]
    node _T_46 = bits(StatusAct, 3, 3) @[Int_nesting.scala 225:34]
    Int_status_3.io.act <= _T_46 @[Int_nesting.scala 225:23]
    node _T_47 = bits(StatusDeact, 3, 3) @[Int_nesting.scala 226:38]
    Int_status_3.io.deact <= _T_47 @[Int_nesting.scala 226:25]
    node _T_48 = bits(StatusNest, 3, 3) @[Int_nesting.scala 227:36]
    Int_status_3.io.nest <= _T_48 @[Int_nesting.scala 227:24]
    node _T_49 = bits(StatusDenest, 3, 3) @[Int_nesting.scala 228:40]
    Int_status_3.io.denest <= _T_49 @[Int_nesting.scala 228:26]
    Int_status_3.io.pri_in <= _WIRE_7 @[Int_nesting.scala 229:26]
    Int_status_3.io.ID_in <= _WIRE_6 @[Int_nesting.scala 230:25]
    node _CurrentID_T = eq(StatusPtr, UInt<1>("h0")) @[Int_nesting.scala 234:39]
    node _CurrentID_T_1 = bits(_CurrentID_T, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentID_T_2 = mux(_CurrentID_T_1, UInt<4>("hf"), UInt<4>("h0")) @[Bitwise.scala 77:12]
    node _CurrentID_T_3 = and(_CurrentID_T_2, Int_status.io.ID_out) @[Int_nesting.scala 234:48]
    node _CurrentID_T_4 = eq(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 235:28]
    node _CurrentID_T_5 = bits(_CurrentID_T_4, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentID_T_6 = mux(_CurrentID_T_5, UInt<4>("hf"), UInt<4>("h0")) @[Bitwise.scala 77:12]
    node _CurrentID_T_7 = and(_CurrentID_T_6, Int_status_1.io.ID_out) @[Int_nesting.scala 235:37]
    node _CurrentID_T_8 = or(_CurrentID_T_3, _CurrentID_T_7) @[Int_nesting.scala 234:73]
    node _CurrentID_T_9 = eq(StatusPtr, UInt<2>("h2")) @[Int_nesting.scala 236:28]
    node _CurrentID_T_10 = bits(_CurrentID_T_9, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentID_T_11 = mux(_CurrentID_T_10, UInt<4>("hf"), UInt<4>("h0")) @[Bitwise.scala 77:12]
    node _CurrentID_T_12 = and(_CurrentID_T_11, Int_status_2.io.ID_out) @[Int_nesting.scala 236:37]
    node _CurrentID_T_13 = or(_CurrentID_T_8, _CurrentID_T_12) @[Int_nesting.scala 235:62]
    node _CurrentID_T_14 = eq(StatusPtr, UInt<2>("h3")) @[Int_nesting.scala 237:28]
    node _CurrentID_T_15 = bits(_CurrentID_T_14, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentID_T_16 = mux(_CurrentID_T_15, UInt<4>("hf"), UInt<4>("h0")) @[Bitwise.scala 77:12]
    node _CurrentID_T_17 = and(_CurrentID_T_16, Int_status_3.io.ID_out) @[Int_nesting.scala 237:37]
    node _CurrentID_T_18 = or(_CurrentID_T_13, _CurrentID_T_17) @[Int_nesting.scala 236:62]
    CurrentID <= _CurrentID_T_18 @[Int_nesting.scala 234:13]
    node _CurrentPri_T = eq(StatusPtr, UInt<1>("h0")) @[Int_nesting.scala 238:43]
    node _CurrentPri_T_1 = bits(_CurrentPri_T, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentPri_T_2 = mux(_CurrentPri_T_1, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _CurrentPri_T_3 = and(_CurrentPri_T_2, Int_status.io.pri_out) @[Int_nesting.scala 238:52]
    node _CurrentPri_T_4 = eq(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 239:31]
    node _CurrentPri_T_5 = bits(_CurrentPri_T_4, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentPri_T_6 = mux(_CurrentPri_T_5, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _CurrentPri_T_7 = and(_CurrentPri_T_6, Int_status_1.io.pri_out) @[Int_nesting.scala 239:40]
    node _CurrentPri_T_8 = or(_CurrentPri_T_3, _CurrentPri_T_7) @[Int_nesting.scala 238:78]
    node _CurrentPri_T_9 = eq(StatusPtr, UInt<2>("h2")) @[Int_nesting.scala 240:31]
    node _CurrentPri_T_10 = bits(_CurrentPri_T_9, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentPri_T_11 = mux(_CurrentPri_T_10, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _CurrentPri_T_12 = and(_CurrentPri_T_11, Int_status_2.io.pri_out) @[Int_nesting.scala 240:40]
    node _CurrentPri_T_13 = or(_CurrentPri_T_8, _CurrentPri_T_12) @[Int_nesting.scala 239:66]
    node _CurrentPri_T_14 = eq(StatusPtr, UInt<2>("h3")) @[Int_nesting.scala 241:31]
    node _CurrentPri_T_15 = bits(_CurrentPri_T_14, 0, 0) @[Bitwise.scala 77:15]
    node _CurrentPri_T_16 = mux(_CurrentPri_T_15, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _CurrentPri_T_17 = and(_CurrentPri_T_16, Int_status_3.io.pri_out) @[Int_nesting.scala 241:40]
    node _CurrentPri_T_18 = or(_CurrentPri_T_13, _CurrentPri_T_17) @[Int_nesting.scala 240:66]
    CurrentPri <= _CurrentPri_T_18 @[Int_nesting.scala 238:14]
    node _NestedID_T = eq(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 243:28]
    node _NestedID_T_1 = bits(_NestedID_T, 0, 0) @[Bitwise.scala 77:15]
    node _NestedID_T_2 = mux(_NestedID_T_1, UInt<4>("hf"), UInt<4>("h0")) @[Bitwise.scala 77:12]
    node _NestedID_T_3 = and(_NestedID_T_2, Int_status.io.ID_out) @[Int_nesting.scala 243:37]
    node _NestedID_T_4 = or(UInt<4>("h0"), _NestedID_T_3) @[Int_nesting.scala 242:28]
    node _NestedID_T_5 = eq(StatusPtr, UInt<2>("h2")) @[Int_nesting.scala 244:28]
    node _NestedID_T_6 = bits(_NestedID_T_5, 0, 0) @[Bitwise.scala 77:15]
    node _NestedID_T_7 = mux(_NestedID_T_6, UInt<4>("hf"), UInt<4>("h0")) @[Bitwise.scala 77:12]
    node _NestedID_T_8 = and(_NestedID_T_7, Int_status_1.io.ID_out) @[Int_nesting.scala 244:37]
    node _NestedID_T_9 = or(_NestedID_T_4, _NestedID_T_8) @[Int_nesting.scala 243:62]
    node _NestedID_T_10 = eq(StatusPtr, UInt<2>("h3")) @[Int_nesting.scala 245:28]
    node _NestedID_T_11 = bits(_NestedID_T_10, 0, 0) @[Bitwise.scala 77:15]
    node _NestedID_T_12 = mux(_NestedID_T_11, UInt<4>("hf"), UInt<4>("h0")) @[Bitwise.scala 77:12]
    node _NestedID_T_13 = and(_NestedID_T_12, Int_status_2.io.ID_out) @[Int_nesting.scala 245:37]
    node _NestedID_T_14 = or(_NestedID_T_9, _NestedID_T_13) @[Int_nesting.scala 244:62]
    NestedID <= _NestedID_T_14 @[Int_nesting.scala 242:12]
    node _NestedPri_T = eq(StatusPtr, UInt<1>("h1")) @[Int_nesting.scala 247:31]
    node _NestedPri_T_1 = bits(_NestedPri_T, 0, 0) @[Bitwise.scala 77:15]
    node _NestedPri_T_2 = mux(_NestedPri_T_1, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _NestedPri_T_3 = and(_NestedPri_T_2, Int_status.io.pri_out) @[Int_nesting.scala 247:40]
    node _NestedPri_T_4 = or(UInt<5>("h0"), _NestedPri_T_3) @[Int_nesting.scala 246:31]
    node _NestedPri_T_5 = eq(StatusPtr, UInt<2>("h2")) @[Int_nesting.scala 248:31]
    node _NestedPri_T_6 = bits(_NestedPri_T_5, 0, 0) @[Bitwise.scala 77:15]
    node _NestedPri_T_7 = mux(_NestedPri_T_6, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _NestedPri_T_8 = and(_NestedPri_T_7, Int_status_1.io.pri_out) @[Int_nesting.scala 248:40]
    node _NestedPri_T_9 = or(_NestedPri_T_4, _NestedPri_T_8) @[Int_nesting.scala 247:66]
    node _NestedPri_T_10 = eq(StatusPtr, UInt<2>("h3")) @[Int_nesting.scala 249:31]
    node _NestedPri_T_11 = bits(_NestedPri_T_10, 0, 0) @[Bitwise.scala 77:15]
    node _NestedPri_T_12 = mux(_NestedPri_T_11, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _NestedPri_T_13 = and(_NestedPri_T_12, Int_status_2.io.pri_out) @[Int_nesting.scala 249:40]
    node _NestedPri_T_14 = or(_NestedPri_T_9, _NestedPri_T_13) @[Int_nesting.scala 248:66]
    NestedPri <= _NestedPri_T_14 @[Int_nesting.scala 246:13]

