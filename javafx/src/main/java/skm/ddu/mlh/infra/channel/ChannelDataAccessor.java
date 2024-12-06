package skm.ddu.mlh.infra.channel;

import skm.ddu.mlh.models.ChannelConfigInRequest;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.models.ChannelConfigOutRequest;
import skm.ddu.mlh.models.ChannelDataPeriodicModel;

public interface ChannelDataAccessor {
    ChannelConfigInfoModel getChannelInfo(int channelNumber);

    ChannelDataPeriodicModel getChannelDataPeriodFisis(int channelNumber);

    void setInputConfig(int channelNumber, ChannelConfigInRequest request);

    void setOutputConfig(int channelNumber, ChannelConfigOutRequest request);
}
