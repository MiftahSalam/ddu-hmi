package skm.ddu.mlh.entities;

import lombok.Data;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_BAUDRATE;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_DATABITS;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_FLOW_CONTROL;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_PARITY;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_SERIAL_STOPBITS;

@Data
public class SerialConfigEntity {
    private String portname;
    private CH_SERIAL_BAUDRATE baudrate;
    private CH_SERIAL_DATABITS databits;
    private CH_SERIAL_STOPBITS stopbits;
    private CH_SERIAL_PARITY parity;
    private CH_SERIAL_FLOW_CONTROL flowControl;
}
