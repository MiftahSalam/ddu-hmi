package skm.ddu.mlh.infra.channel;

import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import skm.ddu.mlh.models.ChannelConfigInfoModel;

public class ChannelDataAccessorDBTest {
    private static ChannelDataAccessorDB accessorDB;

    @BeforeAll
    static void setup() {
        assertDoesNotThrow(() -> {
            accessorDB = new ChannelDataAccessorDB("localhost:5432:postgres:fisikawangarut:skmddu_2014");

            assertNotNull(accessorDB);
        });
    }

    @Test
    void testGetChannelInfo() {
        assertDoesNotThrow(() -> {
            ChannelConfigInfoModel expectInfoModel = new ChannelConfigInfoModel(
                    "-",
                    "TIMEOUT",
                    "4800",
                    "8",
                    "1",
                    "NONE",
                    "127.0.0.1",
                    "14001");

            ChannelConfigInfoModel channelInfo = accessorDB.getChannelInfo(1);
            assertNotEquals("-", channelInfo.getAccessIP());

            assertEquals(expectInfoModel, channelInfo);
        });
    }

    @Test
    void testSetInputConfig() {

    }

    @Test
    void testSetOutputConfig() {

    }
}
