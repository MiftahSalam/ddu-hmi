package skm.ddu.mlh.infra.channel;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.Test;

import skm.ddu.mlh.shared.configs.ChannelAccessConfig;

public class ChannelDataAccessorFactoryTest {
    @Test
    void testBuild() {
        ChannelAccessConfig.getInstance();
        ChannelDataAccessor channelDataAccessor = ChannelDataAccessorFactory.build();

        assertNotNull(channelDataAccessor);
        assertEquals(ChannelDataAccessorDB.class, channelDataAccessor.getClass());
        assertNotEquals(ChannelDataAccessorRestApi.class, channelDataAccessor.getClass());
    }
}
