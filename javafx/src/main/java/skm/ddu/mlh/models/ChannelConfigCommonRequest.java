package skm.ddu.mlh.models;

import lombok.AllArgsConstructor;
import lombok.Data;
import skm.ddu.mlh.entities.SerialConfigEntity;

@Data
@AllArgsConstructor
public class ChannelConfigCommonRequest {
    private SerialConfigEntity serial;
    private String jenisSensor;
    private String sensorName;
    private String nmeaValue;
}
