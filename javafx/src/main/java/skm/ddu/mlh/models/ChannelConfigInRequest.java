package skm.ddu.mlh.models;

import lombok.Getter;
import lombok.Setter;
import skm.ddu.mlh.entities.SerialConfigEntity;

@Getter
@Setter
public class ChannelConfigInRequest extends ChannelConfigCommonRequest {
    private String priority;

    public ChannelConfigInRequest(
            SerialConfigEntity serial,
            String jenisSensor,
            String sensorName,
            String nmeaValue,
            String priority) {
        super(serial, jenisSensor, sensorName, nmeaValue);

        this.priority = priority;
    }
}
