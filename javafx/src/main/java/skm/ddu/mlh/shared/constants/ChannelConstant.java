package skm.ddu.mlh.shared.constants;

import java.util.HashMap;
import java.util.Map;

import javafx.util.Pair;

public class ChannelConstant {
    private static final Pair<Integer, Integer> CH_OUT_LIMIT = new Pair<Integer, Integer>(0, 16);
    private static final Pair<Integer, Integer> CH_IN_LIMIT = new Pair<Integer, Integer>(17,
            GlobalConstant.CHANNEL_COUNT - 1);

    public enum CH_IO_FUNCTION {
        IN,
        OUT
    }

    public enum CH_ASSIGN {
        NONE,
        JENIS,
        CHANNEL
    }

    public enum CH_IN_PRIORITY {
        NONE,
        P_1,
        P_2,
        P_3,
        P_4,
    }

    public enum CH_JENIS_NMEA {
        NONE,
        AG,
        AI,
        AP,
        DC,
        CR,
        CS,
        CT,
        CV,
        CX,
        DE,
        DF,
        EC,
        EP,
        ER,
        GL,
        GN,
        GP,
        GV,
        HC,
        HE,
        HN,
        II,
        IN,
        LA,
        LC,
        OM,
        P,
        RA,
        SD,
        SN,
        SS,
        TI,
        TR,
        VD,
        VM,
        VW,
        YX,
        ZA,
        ZC,
        ZQ,
        WI,
    }

    public enum CH_NMEA_VALUE {
        NONE,
        DBT,
        DPT,
        FPD,
        GGA,
        GLL,
        HDG,
        HDT,
        HSC,
        MWD,
        MWV,
        SN,
        TTM,
        VBW,
        VDM,
        VDR,
        VHW,
        VTG
    }

    public enum CH_SENSOR_NAME {
        NONE,
        AIS,
        ARPA,
        Echo_Sounder_1,
        Echo_Sounder_2,
        Echo_Sounder_3,
        GPS_1,
        GPS_2,
        GPS_3,
        Gyro_Compas_1,
        Gyro_Compas_2,
        Gyro_Compas_3,
        Gyro_Vertical_1,
        Gyro_Vertical_2,
        Gyro_Vertical_3,
        Meteo,
        Speedlog_1,
        Speedlog_2,
        Speedlog_3,
        Wind_Direction_1,
        Wind_Direction_2,
        Wind_Direction_3,
    }

    public enum CH_SERIAL_BAUDRATE {
        NONE,
        B_2400,
        B_4800,
        B_9600,
        B_19200,
        B_38400,
        B_56800,
        B_115200,
    }

    public enum CH_SERIAL_DATABITS {
        NONE,
        DATA_5,
        DATA_6,
        DATA_7,
        DATA_8,
    }

    public enum CH_SERIAL_PARITY {
        NONE,
        ODD,
        EVEN,
    }

    public enum CH_SERIAL_FLOW_CONTROL {
        NONE,
        OFF,
        HARDWARE,
        XON_XOFF,
    }

    public enum CH_SERIAL_STOPBITS {
        NONE,
        STOP_1,
        STOP_2,
    }

    public static final Map<Integer, CH_IO_FUNCTION> CH_IO_MAP = new HashMap<>();

    static {
        for (int i = 0; i < GlobalConstant.CHANNEL_COUNT; i++) {
            if (i >= CH_OUT_LIMIT.getKey() && i <= CH_OUT_LIMIT.getValue()) {
                CH_IO_MAP.put(i, CH_IO_FUNCTION.OUT);
            } else if (i >= CH_IN_LIMIT.getKey() && i <= CH_IN_LIMIT.getValue()) {
                CH_IO_MAP.put(i, CH_IO_FUNCTION.IN);
            }
        }
    };
}
