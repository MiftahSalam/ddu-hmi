package skm.ddu.mlh.entities;

import lombok.Data;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_IN_PRIORITY;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_IO_FUNCTION;

@Data
public class ChannelConfigEntity {
    private SerialConfigEntity serial;
    private String sensorName;
    private CH_IO_FUNCTION mode;
    private CH_IN_PRIORITY priority;
    private String errorStatus;
    private String jenisSensor;
    private String assign;
    private String currentTCPAccessIp;
    private String currentTCPAccessPort;
}
