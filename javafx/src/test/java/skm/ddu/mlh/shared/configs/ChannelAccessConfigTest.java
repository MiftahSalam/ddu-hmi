package skm.ddu.mlh.shared.configs;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.Test;

public class ChannelAccessConfigTest {
    @Test
    void testGetInstance() {
        assertNotNull(ChannelAccessConfig.getInstance());
    }
}
