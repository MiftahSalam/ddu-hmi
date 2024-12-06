package skm.ddu.mlh.models;

import lombok.AllArgsConstructor;
import lombok.Data;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_ERROR_STATUS;

@Data
@AllArgsConstructor
public class ChannelDataPeriodicModel {
    private String dataFisis;
    private CH_ERROR_STATUS currentError;
}
