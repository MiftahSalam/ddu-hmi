package skm.ddu.mlh.infra.channel;

import java.sql.SQLException;
import java.util.List;

import skm.ddu.mlh.infra.database.DBAccess;
import skm.ddu.mlh.infra.database.DBAccessPostgresql;
import skm.ddu.mlh.models.ChannelConfigInRequest;
import skm.ddu.mlh.models.ChannelConfigInfoModel;
import skm.ddu.mlh.models.ChannelConfigOutRequest;
import skm.ddu.mlh.models.ChannelDataPeriodicModel;
import skm.ddu.mlh.shared.configs.DatabaseConfig;
import skm.ddu.mlh.shared.constants.ChannelConstant.CH_ERROR_STATUS;

public class ChannelDataAccessorDB implements ChannelDataAccessor {
    private DBAccess dbAccess;
    private ChannelConfigInfoModel currInfoModel = new ChannelConfigInfoModel("-", "-", "-", "-", "-", "-", "-", "-");

    public ChannelDataAccessorDB(String config) {
        try {
            DatabaseConfig instance = DatabaseConfig.getInstance(config);
            dbAccess = DBAccessPostgresql.getInstance(instance);

        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    @Override
    public ChannelConfigInfoModel getChannelInfo(int channelNumber) {
        StringBuilder queryBuilder = new StringBuilder();

        queryBuilder.append("SELECT ");
        queryBuilder.append("cur_sensor_name, ");
        queryBuilder.append("cur_error_stat, ");
        queryBuilder.append("cur_ser_baud, ");
        queryBuilder.append("cur_ser_data_bits, ");
        queryBuilder.append("cur_ser_stop_bit, ");
        queryBuilder.append("cur_ser_parity, ");
        queryBuilder.append("tcp_ch_akses_ip, ");
        queryBuilder.append("tcp_ch_akses_port ");
        queryBuilder.append("FROM ddu_ch WHERE ch_id=");
        queryBuilder.append(channelNumber);

        try {
            List<List<String>> result = dbAccess.executeQueryAndReturnResult(queryBuilder.toString());
            if (result.size() == 1) {
                currInfoModel.setSensorName(result.get(0).get(0));
                currInfoModel.setCurrentError(result.get(0).get(1));
                currInfoModel.setSerialBaudrate(result.get(0).get(2));
                currInfoModel.setSerialDatabits(result.get(0).get(3));
                currInfoModel.setSerialStopbits(result.get(0).get(4));
                currInfoModel.setSerialParity(result.get(0).get(5));
                currInfoModel.setAccessIP(result.get(0).get(6));
                currInfoModel.setAccessPort(result.get(0).get(7));
            } else {
                // TODO throw error
            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        return currInfoModel;
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
    public ChannelDataPeriodicModel getChannelDataPeriodFisis(int channelNumber) {
        StringBuilder queryBuilder = new StringBuilder();
        ChannelDataPeriodicModel dataFisisModel = null;

        queryBuilder.append("SELECT ");
        queryBuilder.append("cur_data_fisis, ");
        queryBuilder.append("cur_error_stat ");
        queryBuilder.append("FROM ddu_ch WHERE ch_id=");
        queryBuilder.append(channelNumber);

        try {
            List<List<String>> result = dbAccess.executeQueryAndReturnResult(queryBuilder.toString());
            if (result.size() == 1) {
                dataFisisModel = new ChannelDataPeriodicModel(
                        result.get(0).get(0),
                        CH_ERROR_STATUS.valueOf(result.get(0).get(1)));
            } else {
                // TODO throw error
            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        return dataFisisModel;
    }
}
