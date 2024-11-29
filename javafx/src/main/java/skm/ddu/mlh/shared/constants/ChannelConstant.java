package skm.ddu.mlh.shared.constants;

import java.util.HashMap;
import java.util.Map;

import javafx.util.Pair;

public class ChannelConstant {
    private static final Pair<Integer, Integer> CH_OUT_LIMIT = new Pair<Integer, Integer>(0, 16);
    private static final Pair<Integer, Integer> CH_IN_LIMIT = new Pair<Integer, Integer>(17,
            GlobalConstant.CHANNEL_COUNT - 1);

    enum CH_IO_FUNCTION {
        IN,
        OUT
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
