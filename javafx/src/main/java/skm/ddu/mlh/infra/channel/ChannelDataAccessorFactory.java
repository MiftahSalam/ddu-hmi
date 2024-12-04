package skm.ddu.mlh.infra.channel;

import skm.ddu.mlh.shared.configs.ChannelAccessConfig;

public class ChannelDataAccessorFactory {
    private static ChannelDataAccessor channelDataAccessor;

    public static ChannelDataAccessor build() {
        switch (ChannelAccessConfig.getAccessType()) {
            case DB:
                channelDataAccessor = new ChannelDataAccessorDB(ChannelAccessConfig.getAccessConfig());
                break;
            default:
                break;
        }

        return channelDataAccessor;
    }
}
