package skm.ddu.mlh.services;

import skm.ddu.mlh.models.ChannelConfigInRequest;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.models.ChannelConfigOutRequest;

public class ChannelConfigService {
    public ChannelConfigInfoModel getChannelConfigInfo(int channelNumber) {
        return new ChannelConfigInfoModel(null, null, null, null, null, null, null, null);
    }

    public void setInputConfig(int channelNumber, ChannelConfigInRequest request) {

    }

    public void setOutputConfig(int channelNumber, ChannelConfigOutRequest request) {

    }
}
