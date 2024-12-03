package skm.ddu.mlh.models;

import lombok.Getter;
import lombok.Setter;
import skm.ddu.mlh.entities.SerialConfigEntity;

@Setter
@Getter
public class ChannelConfigOutRequest extends ChannelConfigCommonRequest {
    private String assign;

    public ChannelConfigOutRequest(
            SerialConfigEntity serial,
            String jenisSensor,
            String sensorName,
            String nmeaValue,
            String assign) {
        super(serial, jenisSensor, sensorName, nmeaValue);

        this.assign = assign;
    }
}
