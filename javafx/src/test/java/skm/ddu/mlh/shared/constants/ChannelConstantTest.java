package skm.ddu.mlh.shared.constants;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

import skm.ddu.mlh.shared.constants.ChannelConstant.CH_IO_FUNCTION;

public class ChannelConstantTest {
    @Test
    public void createChannelIOMap() {
        assertEquals(GlobalConstant.CHANNEL_COUNT, ChannelConstant.CH_IO_MAP.size());
        for (int i = 0; i < GlobalConstant.CHANNEL_COUNT; i++) {
            if (i <= 16) {
                assertEquals(CH_IO_FUNCTION.OUT, ChannelConstant.CH_IO_MAP.get(i));
            } else {
                assertEquals(CH_IO_FUNCTION.IN, ChannelConstant.CH_IO_MAP.get(i));
            }
        }
    }
}
