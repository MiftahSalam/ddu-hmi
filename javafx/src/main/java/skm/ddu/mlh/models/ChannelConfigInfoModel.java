package skm.ddu.mlh.models;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class ChannelConfigInfoModel {
    private String sensorName;
    private String currentError;
    private String serialBaudrate;
    private String serialDatabits;
    private String serialStopbits;
    private String serialParity;
    private String accessIP;
    private String accessPort;
}
