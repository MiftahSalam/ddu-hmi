package skm.ddu.mlh.infra.channel;

import skm.ddu.mlh.infra.database.DBAccess;
import skm.ddu.mlh.infra.database.DBAccessPostgresql;
import skm.ddu.mlh.models.ChannelConfigInRequest;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.models.ChannelConfigOutRequest;
import skm.ddu.mlh.shared.configs.DatabaseConfig;

public class ChannelDataAccessorDB implements ChannelDataAccessor {
    private DBAccess dbAccess;

    public ChannelDataAccessorDB(String config) {
        try {
            DatabaseConfig instance = DatabaseConfig.getInstance(config);
            dbAccess = new DBAccessPostgresql(instance);
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

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
}
