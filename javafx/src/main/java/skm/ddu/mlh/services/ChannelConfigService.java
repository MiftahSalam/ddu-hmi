package skm.ddu.mlh.services;

import skm.ddu.mlh.infra.channel.ChannelDataAccessor;
import skm.ddu.mlh.infra.channel.ChannelDataAccessorFactory;
import skm.ddu.mlh.models.ChannelConfigInRequest;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.models.ChannelConfigOutRequest;
import skm.ddu.mlh.models.ChannelDataPeriodicModel;

public class ChannelConfigService {
    private ChannelDataAccessor channelDataAccessor;
    private static ChannelConfigService instance;

    private ChannelConfigService(ChannelDataAccessor dataAccessor) {
        channelDataAccessor = dataAccessor;
    }

    private ChannelConfigService() {
        channelDataAccessor = ChannelDataAccessorFactory.build();
    }

    public static ChannelConfigService getInstance() {
        if (instance == null) {
            instance = new ChannelConfigService();
        }

        return instance;
    }

    public ChannelConfigInfoModel getChannelConfigInfo(int channelNumber) {
        return channelDataAccessor.getChannelInfo(channelNumber);
    }

    public ChannelDataPeriodicModel getChannelDataPeriod(int channelNumber) {
        return channelDataAccessor.getChannelDataPeriodFisis(channelNumber);
    }

    public void setInputConfig(int channelNumber, ChannelConfigInRequest request) {

    }

    public void setOutputConfig(int channelNumber, ChannelConfigOutRequest request) {

    }
}
