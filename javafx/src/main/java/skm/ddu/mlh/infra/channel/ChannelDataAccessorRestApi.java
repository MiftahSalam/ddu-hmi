package skm.ddu.mlh.infra.channel;

import skm.ddu.mlh.models.ChannelConfigInRequest;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.models.ChannelConfigOutRequest;
import skm.ddu.mlh.models.ChannelDataPeriodicModel;

public class ChannelDataAccessorRestApi implements ChannelDataAccessor {

    @Override
    public ChannelConfigInfoModel getChannelInfo(int channelNumber) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'getChannelInfo'");
    }

    @Override
    public void setInputConfig(int channelNumber, ChannelConfigInRequest request) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'setInputConfig'");
    }

    @Override
    public void setOutputConfig(int channelNumber, ChannelConfigOutRequest request) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'setOutputConfig'");
    }

    @Override
    public ChannelDataPeriodicModel getChannelDataFisis(int channelNumber) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'getChannelDataFisis'");
    }

}
